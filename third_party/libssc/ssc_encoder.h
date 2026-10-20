#ifndef SSC_ENCODER_H
#define SSC_ENCODER_H

#include <stddef.h>
#include <stdint.h>

#if defined(_WIN32)
# define SSC_API __declspec(dllexport)
#elif defined(__GNUC__)
# define SSC_API __attribute__((visibility("default")))
#else
# define SSC_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SSC_FRAME_SAMPLES 864
#define SSC_MAX_FRAME_BYTES 484
#define SSC_MAX_UHQ_FRAME_BYTES 660
#define SSC_SUPPORTED_BITRATE 192000

/*
 * Supports stereo signed PCM represented in int32_t containers: 16-bit at
 * 44.1/48 kHz (192 kbit/s), 24-bit at 48 kHz (88/96/128/192 kbit/s), and
 * 24-bit at 96 kHz (152/291/328/584 kbit/s). Each call encodes exactly 864
 * interleaved frames. 24-bit values must be right-justified in [-8388608,
 * 8388607]. SSC_MAX_FRAME_BYTES retains its original meaning as the maximum
 * standard 16-bit or 48 kHz/24-bit frame. SSC_MAX_UHQ_FRAME_BYTES is the
 * maximum 96 kHz/24-bit frame.
 *
 * create() returns NULL on failure and stores a positive errno value in error
 * when error is non-NULL. Only one live encoder may exist; a second create
 * returns EBUSY. This is required by the native encoder's process-global DRC.
 *
 * encode() returns the positive encoded frame length, or a negative errno
 * value. It does not write output on validation/native failure. Output
 * capacity is checked against the exact frame length for the handle's rate,
 * depth, and requested bitrate before the native encoder state advances.
 * Callers that may use any supported mode can reserve
 * SSC_MAX_UHQ_FRAME_BYTES. Calls on one live encoder are serialized.
 *
 * destroy() destroys only the current live handle; NULL or unrelated handles
 * are ignored. A handle must not be used after destroy().
 */
SSC_API void *ssc_encoder_create(int rate, int channels, int depth, int *error);
SSC_API void ssc_encoder_destroy(void *state);
SSC_API int ssc_encode(void *state, const int32_t *pcm, int frames,
                       uint8_t *output, size_t output_capacity, int bitrate);

#ifdef __cplusplus
}
#endif
#endif
