#include "ssc_encoder.h"

#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* The translated native implementation is compiled with ssc_native_rename.h. */
extern void *ssc_native_create(int rate, int channels, int depth, int *error);
extern void ssc_native_destroy(void *state);
extern int ssc_native_encode(void *state, const int32_t *pcm, int frames,
                             uint8_t *output, int bitrate);

#define SSC_NATIVE_OUTPUT_GUARD_BYTES 4096

struct ssc_encoder_handle {
    void *native;
    int rate;
    int depth;
};

static pthread_mutex_t ssc_mutex = PTHREAD_MUTEX_INITIALIZER;
static struct ssc_encoder_handle *ssc_active;

static int supported_rate(int rate)
{
    return rate == 44100 || rate == 48000 || rate == 96000;
}

static int supported_config(int rate, int channels, int depth)
{
    if (channels != 2)
        return 0;
    if (depth == 16)
        return rate == 44100 || rate == 48000;
    return depth == 24 && (rate == 48000 || rate == 96000);
}

/* Return the exact payload size for a supported rate/depth/bitrate tuple. */
static int expected_frame_bytes(int rate, int depth, int bitrate)
{
    if (depth == 16 && (rate == 44100 || rate == 48000))
        return bitrate == SSC_SUPPORTED_BITRATE ? SSC_MAX_FRAME_BYTES : 0;

    if (depth == 24 && rate == 48000) {
        switch (bitrate) {
        case 88000: return 224;
        case 96000: return 244;
        case 128000: return 324;
        case 192000: return 484;
        default: return 0;
        }
    }
    if (depth == 24 && rate == 96000) {
        switch (bitrate) {
        case 152000: return 174;
        case 291000: return 330;
        case 328000: return 372;
        case 584000: return SSC_MAX_UHQ_FRAME_BYTES;
        default: return 0;
        }
    }
    return 0;
}

void *ssc_encoder_create(int rate, int channels, int depth, int *error)
{
    struct ssc_encoder_handle *handle;
    int native_error = 0;
    int lock_error;

    if (error)
        *error = 0;
    if (!supported_rate(rate) || !supported_config(rate, channels, depth)) {
        if (error)
            *error = EINVAL;
        return NULL;
    }

    lock_error = pthread_mutex_lock(&ssc_mutex);
    if (lock_error != 0) {
        if (error)
            *error = lock_error;
        return NULL;
    }
    if (ssc_active != NULL) {
        pthread_mutex_unlock(&ssc_mutex);
        if (error)
            *error = EBUSY;
        return NULL;
    }

    handle = calloc(1, sizeof(*handle));
    if (!handle) {
        pthread_mutex_unlock(&ssc_mutex);
        if (error)
            *error = ENOMEM;
        return NULL;
    }

    handle->rate = rate;
    handle->depth = depth;
    handle->native = ssc_native_create(rate, channels, depth, &native_error);
    if (!handle->native) {
        free(handle);
        pthread_mutex_unlock(&ssc_mutex);
        if (error)
            *error = native_error == -7 ? ENOMEM : (native_error ? EINVAL : EIO);
        return NULL;
    }
    ssc_active = handle;
    pthread_mutex_unlock(&ssc_mutex);
    return handle;
}

void ssc_encoder_destroy(void *state)
{
    struct ssc_encoder_handle *handle = state;
    if (!handle)
        return;
    if (pthread_mutex_lock(&ssc_mutex) != 0)
        return;
    if (handle == ssc_active) {
        ssc_active = NULL;
        ssc_native_destroy(handle->native);
        handle->native = NULL;
        free(handle);
    }
    pthread_mutex_unlock(&ssc_mutex);
}

int ssc_encode(void *state, const int32_t *pcm, int frames, uint8_t *output,
               size_t output_capacity, int bitrate)
{
    struct ssc_encoder_handle *handle = state;
    int32_t pcm_copy[SSC_FRAME_SAMPLES * 2];
    uint8_t native_output[SSC_NATIVE_OUTPUT_GUARD_BYTES];
    int encoded_size;
    int expected_size;
    int lock_error;

    /* Reject caller mistakes before touching stateful native encoder state. */
    if (!handle || !pcm || !output)
        return -EINVAL;
    if (frames != SSC_FRAME_SAMPLES)
        return -EINVAL;

    lock_error = pthread_mutex_lock(&ssc_mutex);
    if (lock_error != 0)
        return -lock_error;
    if (handle != ssc_active || !handle->native) {
        pthread_mutex_unlock(&ssc_mutex);
        return -EINVAL;
    }

    expected_size = expected_frame_bytes(handle->rate, handle->depth, bitrate);
    if (!expected_size) {
        pthread_mutex_unlock(&ssc_mutex);
        return -EINVAL;
    }
    /* Do this before copying/encoding so an undersized output never advances
     * the native encoder's state. The per-mode lengths are fixed by the
     * selected SSC bitrate tier. */
    if (output_capacity < (size_t)expected_size) {
        pthread_mutex_unlock(&ssc_mutex);
        return -EMSGSIZE;
    }

    /* Native code mutates its PCM argument; preserve BlueALSA's input buffer. */
    memcpy(pcm_copy, pcm, sizeof(pcm_copy));
    for (size_t i = 0; i < sizeof(pcm_copy) / sizeof(pcm_copy[0]); i++) {
        int32_t minimum = handle->depth == 16 ? INT16_MIN : -8388608;
        int32_t maximum = handle->depth == 16 ? INT16_MAX : 8388607;
        if (pcm_copy[i] < minimum || pcm_copy[i] > maximum) {
            pthread_mutex_unlock(&ssc_mutex);
            return -ERANGE;
        }
    }
    encoded_size = ssc_native_encode(handle->native, pcm_copy, frames,
                                     native_output, bitrate);
    if (encoded_size != expected_size || encoded_size > SSC_NATIVE_OUTPUT_GUARD_BYTES) {
        pthread_mutex_unlock(&ssc_mutex);
        return -EIO;
    }
    if ((size_t)encoded_size > output_capacity) {
        pthread_mutex_unlock(&ssc_mutex);
        return -EMSGSIZE;
    }
    memcpy(output, native_output, (size_t)encoded_size);
    pthread_mutex_unlock(&ssc_mutex);
    return encoded_size;
}
