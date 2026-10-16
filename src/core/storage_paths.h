#ifndef STORAGE_PATHS_H
#define STORAGE_PATHS_H

/* Canonical persistent application data paths. The metadata database also
 * lives in .compas; the shared directory does not make it disposable. */
#define COMPAS_STORAGE_DIR ".compas"

#ifdef HOST_BUILD
#define INTERNAL_COMPAS_DIR "./.compas"
#define SETTINGS_FILE_PATH "./.compas/settings.txt"
#define PEQ_FILE_PATH "./.compas/peq.txt"
#define SUBSONIC_COMPAS_DIR "./.compas"
#define PLUGIN_STORAGE_ROOT "./.compas/plugins"
#define SD_COMPAS_ROOT "./.compas"
#else
#define INTERNAL_COMPAS_DIR "/usr/data/.compas"
#define SETTINGS_FILE_PATH "/usr/data/.compas/settings.txt"
#define PEQ_FILE_PATH "/usr/data/.compas/peq.txt"
#define SUBSONIC_COMPAS_DIR "/usr/data/.compas"
#define PLUGIN_STORAGE_ROOT "/usr/data/.compas/plugins"
#define SD_COMPAS_ROOT "/data/mnt/sd_0/.compas"
#endif

#endif
