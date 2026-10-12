#!/bin/sh
# Persist a bounded, filtered record of COMPAS startup checkpoints.

TRACE_PREFIX=compas-startup
TRACE_DIR=/usr/data/compas-startup
TRACE_LOG=$TRACE_DIR/startup.log

# COMPAS_STARTUP_CHECKPOINT_BEGIN
compas_startup_checkpoint() {
    [ "$#" -eq 3 ] || return 0
    case "${COMPAS_STARTUP_BOOT_ID:-}" in
        ????????-????-????-????-????????????) ;;
        *) return 0 ;;
    esac
    case "$COMPAS_STARTUP_BOOT_ID" in
        *[!0123456789abcdefABCDEF-]*) return 0 ;;
    esac
    for COMPAS_STARTUP_CHECKPOINT_FIELD in "$1" "$2" "$3"; do
        case "$COMPAS_STARTUP_CHECKPOINT_FIELD" in
            ''|*[!A-Za-z0-9_.-]*) return 0 ;;
        esac
        [ "${#COMPAS_STARTUP_CHECKPOINT_FIELD}" -le 48 ] || return 0
    done
    IFS=' ' read -r COMPAS_STARTUP_CHECKPOINT_UPTIME COMPAS_STARTUP_CHECKPOINT_IDLE </proc/uptime || return 0
    : "$COMPAS_STARTUP_CHECKPOINT_IDLE"
    case "$COMPAS_STARTUP_CHECKPOINT_UPTIME" in
        ''|*[!0-9.]*) return 0 ;;
    esac
    COMPAS_STARTUP_CHECKPOINT_RECORD="compas-startup boot=$COMPAS_STARTUP_BOOT_ID uptime=$COMPAS_STARTUP_CHECKPOINT_UPTIME phase=$1 name=$2 status=$3"
    if [ -c /dev/kmsg ] && [ -w /dev/kmsg ]; then
        printf '<6>%s\n' "$COMPAS_STARTUP_CHECKPOINT_RECORD" >/dev/kmsg 2>/dev/null || :
    elif [ -c /dev/console ] && [ -w /dev/console ]; then
        printf '%s\n' "$COMPAS_STARTUP_CHECKPOINT_RECORD" >/dev/console 2>/dev/null || :
    else
        printf '%s\n' "$COMPAS_STARTUP_CHECKPOINT_RECORD" >&2 || :
    fi
    return 0
}
# COMPAS_STARTUP_CHECKPOINT_END

trace_boot_id() {
    if [ -n "${COMPAS_STARTUP_BOOT_ID:-}" ]; then
        TRACE_BOOT_ID=$COMPAS_STARTUP_BOOT_ID
    else
        IFS= read -r TRACE_BOOT_ID </proc/sys/kernel/random/boot_id || return 1
    fi
    case "$TRACE_BOOT_ID" in
        ????????-????-????-????-????????????) ;;
        *) return 1 ;;
    esac
    case "$TRACE_BOOT_ID" in
        *[!0123456789abcdefABCDEF-]*) return 1 ;;
    esac
    COMPAS_STARTUP_BOOT_ID=$TRACE_BOOT_ID
    export COMPAS_STARTUP_BOOT_ID
    return 0
}

trace_emit() {
    trace_id=$1
    [ "$COMPAS_STARTUP_BOOT_ID" = "$trace_id" ] || return 0
    compas_startup_checkpoint "$2" "$3" "$4"
    return 0
}

trace_mount_ready() {
    awk '$2 == "/usr/data" && $3 == "ubifs" && $4 ~ /(^|,)rw(,|$)/ && $1 ~ /^\/dev\/ubi[0-9]+_[0-9]+$/ { found=1 } END { exit !found }' /proc/mounts 2>/dev/null
}

trace_target_safe() {
    trace_target=$1
    if [ -L "$trace_target" ]; then
        return 1
    fi
    if [ -e "$trace_target" ] && [ ! -f "$trace_target" ]; then
        return 1
    fi
    return 0
}

trace_prepare_storage() {
    trace_mount_ready || return 1
    if [ -L "$TRACE_DIR" ]; then
        return 1
    fi
    if [ ! -e "$TRACE_DIR" ]; then
        mkdir "$TRACE_DIR" 2>/dev/null || return 1
    fi
    [ -d "$TRACE_DIR" ] || return 1
    chmod 0700 "$TRACE_DIR" 2>/dev/null || return 1

    for trace_file in "$TRACE_LOG" "$TRACE_LOG.1" "$TRACE_LOG.2" "$TRACE_LOG.3"; do
        trace_target_safe "$trace_file" || return 1
    done

    rm -f "$TRACE_LOG.3" 2>/dev/null || return 1
    [ ! -e "$TRACE_LOG.2" ] || mv "$TRACE_LOG.2" "$TRACE_LOG.3" 2>/dev/null || return 1
    [ ! -e "$TRACE_LOG.1" ] || mv "$TRACE_LOG.1" "$TRACE_LOG.2" 2>/dev/null || return 1
    [ ! -e "$TRACE_LOG" ] || mv "$TRACE_LOG" "$TRACE_LOG.1" 2>/dev/null || return 1
    : >"$TRACE_LOG" 2>/dev/null || return 1
    chmod 0600 "$TRACE_LOG" 2>/dev/null || return 1
    return 0
}

trace_save_snapshot() {
    trace_contents=$1
    [ -n "$trace_contents" ] || return 0
    trace_mount_ready || return 1
    [ -d "$TRACE_DIR" ] && [ ! -L "$TRACE_DIR" ] || return 1
    trace_target_safe "$TRACE_LOG" || return 1
    printf '%s\n' "$trace_contents" | dd of="$TRACE_LOG" oflag=append conv=notrunc,fsync status=none 2>/dev/null || return 1
    return 0
}

trace_worker() {
    trace_id=$1
    trace_last=
    trace_pending=
    trace_saved_count=0
    trace_storage_prepared=0
    trace_boot_end_seen=0
    trace_start=$(awk '{ split($1, t, "."); print t[1] * 100 + t[2] }' /proc/uptime 2>/dev/null)
    case "$trace_start" in ''|*[!0-9]*) return 0 ;; esac
    trace_deadline=$((trace_start + 6000))

    while :; do
        trace_now=$(awk '{ split($1, t, "."); print t[1] * 100 + t[2] }' /proc/uptime 2>/dev/null)
        case "$trace_now" in ''|*[!0-9]*) return 0 ;; esac
        [ "$trace_now" -lt "$trace_deadline" ] || break

        trace_current=$(dmesg 2>/dev/null | grep -F "$TRACE_PREFIX boot=$trace_id " | tail -n 256)
        if [ -n "$trace_current" ]; then
            case "$trace_current" in
                *"phase=boot-end"*) trace_boot_end_seen=1 ;;
            esac
            trace_remaining=$((256 - trace_saved_count))
            if [ "$trace_remaining" -gt 0 ]; then
                trace_new=$(printf '%s\n' "$trace_current" | awk -v previous="$trace_last" -v limit="$trace_remaining" '
                    { records[NR] = $0 }
                    END {
                        start = 1
                        if (previous != "") {
                            found = 0
                            for (i = 1; i <= NR; i++) {
                                if (records[i] == previous) {
                                    start = i + 1
                                    found = 1
                                }
                            }
                            if (!found)
                                start = 1
                        }
                        for (i = start; i <= NR && emitted < limit; i++) {
                            print records[i]
                            emitted++
                        }
                    }')
                if [ -n "$trace_new" ]; then
                    if [ -n "$trace_pending" ]; then
                        trace_pending="$trace_pending
$trace_new"
                    else
                        trace_pending=$trace_new
                    fi
                    trace_added=$(printf '%s\n' "$trace_new" | awk 'END { print NR }')
                    trace_saved_count=$((trace_saved_count + trace_added))
                fi
            fi
            trace_last=$(printf '%s\n' "$trace_current" | tail -n 1)
        fi

        if trace_mount_ready; then
            if [ "$trace_storage_prepared" -eq 0 ]; then
                if trace_prepare_storage; then
                    trace_storage_prepared=1
                else
                    trace_emit "$trace_id" trace persistence unavailable
                    return 0
                fi
            fi
            if [ -n "$trace_pending" ]; then
                if trace_save_snapshot "$trace_pending"; then
                    trace_pending=
                else
                    trace_emit "$trace_id" trace persistence write-failed
                    return 0
                fi
            fi
            if [ "$trace_boot_end_seen" -eq 1 ] && [ -z "$trace_pending" ]; then
                return 0
            fi
        fi
        sleep 0.2
    done
}

case "${1:-}" in
    begin)
        trace_boot_id || exit 0
        compas_startup_checkpoint boot begin start
        exit 0
        ;;
    start-writer)
        trace_boot_id || exit 0
        trace_mount_ready || exit 0
        case "$0" in
            /*) trace_script=$0 ;;
            *) trace_script=$(pwd)/$0 ;;
        esac
        if command -v setsid >/dev/null 2>&1; then
            setsid "$trace_script" worker "$TRACE_BOOT_ID" </dev/null >/dev/null 2>&1 &
        else
            (trap '' HUP; exec "$trace_script" worker "$TRACE_BOOT_ID") </dev/null >/dev/null 2>&1 &
        fi
        exit 0
        ;;
    checkpoint)
        trace_boot_id || exit 0
        [ "$#" -eq 4 ] || exit 0
        compas_startup_checkpoint "$2" "$3" "$4"
        exit 0
        ;;
    worker)
        trace_id=${2:-}
        COMPAS_STARTUP_BOOT_ID=$trace_id
        export COMPAS_STARTUP_BOOT_ID
        trace_boot_id || exit 0
        trace_worker "$trace_id"
        exit 0
        ;;
    *)
        exit 0
        ;;
esac
