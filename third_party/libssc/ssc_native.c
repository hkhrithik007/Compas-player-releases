#define _GNU_SOURCE
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ssc_image_data.h"

typedef int16_t ssc_i16_u __attribute__((aligned(1), may_alias));
typedef uint16_t ssc_u16_u __attribute__((aligned(1), may_alias));
typedef int32_t ssc_i32_u __attribute__((aligned(1), may_alias));
typedef uint32_t ssc_u32_u __attribute__((aligned(1), may_alias));
typedef int64_t ssc_i64_u __attribute__((aligned(1), may_alias));
typedef uint64_t ssc_u64_u __attribute__((aligned(1), may_alias));

typedef uint8_t undefined;
typedef uint8_t undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;
typedef uint8_t byte;
typedef uint16_t word;
typedef uint32_t dword;
typedef uint64_t qword;
typedef uint32_t uint;

typedef uint16_t ushort;
typedef void (*code)(void);

typedef uint32_t int3;
typedef uint64_t uint6;

typedef struct { uint8_t b[3]; } unkbyte3;
typedef struct { uint8_t b[5]; } unkbyte5;
typedef struct { uint8_t b[9]; } unkbyte9;
typedef struct { uint8_t b[10]; } unkbyte10;
typedef struct { uint8_t b[12]; } unkbyte12;
typedef struct { uint8_t b[14]; } unkbyte14;

#define long int64_t
#define ulong uint64_t

static uint64_t fake_tpidr[16] = {0};
#define tpidr_el0 ((uint64_t)(uintptr_t)fake_tpidr)

#define SBORROW4(a, b) (((((uint32_t)(a) ^ (uint32_t)(b)) & ((uint32_t)(a) ^ ((uint32_t)(a) - (uint32_t)(b)))) >> 31) != 0)
#define __stack_chk_fail(...) abort()

typedef union __attribute__((packed, aligned(1), may_alias)) {
    uint8_t b[16];
    uint16_t h[8];
    uint32_t s[4];
    uint64_t d[2];
    int8_t sb[16];
    int16_t sh[8];
    int32_t ss[4];
    int64_t sd[2];
    struct { int32_t _0_4_, _4_4_, _8_4_, _12_4_; };
    struct { uint64_t _0_8_, _8_8_; };
    struct { int16_t _0_2_, _2_2_, _4_2_, _6_2_, _8_2_, _10_2_, _12_2_, _14_2_; };
    struct { uint8_t _pad4_12[4]; unkbyte12 _4_12_; };
    unkbyte12 _0_12_;
    unkbyte10 _0_10_;
    unkbyte9 _0_9_;
    unkbyte5 _0_5_;
} vec128_t;

static inline unkbyte12 SUB1612(vec128_t v, int offset) {
    unkbyte12 r;
    memcpy((void *)(r.b), (const void *)(v.b + offset), 12);
    return r;
}

static inline vec128_t ZEXT816(uint64_t x) {
    vec128_t r = {0};
    r.d[0] = x;
    return r;
}

static inline vec128_t vec128_bif(vec128_t a, vec128_t b, vec128_t c) {
    vec128_t r;
    r.d[0] = a.d[0] ^ ((a.d[0] ^ b.d[0]) & ~c.d[0]);
    r.d[1] = a.d[1] ^ ((a.d[1] ^ b.d[1]) & ~c.d[1]);
    return r;
}

static inline vec128_t vec128_bit(vec128_t a, vec128_t b, vec128_t c, vec128_t d) {
    vec128_t r;
    r.d[0] = a.d[0] ^ ((b.d[0] ^ c.d[0]) & d.d[0]);
    r.d[1] = a.d[1] ^ ((b.d[1] ^ c.d[1]) & d.d[1]);
    return r;
}

#define MP_INT_ABS(x) abs((int)(x))
#define LZCOUNT(x) ((x) ? __builtin_clz(x) : 32)
#define CARRY8(a, b) ((uint64_t)(a) > UINT64_MAX - (uint64_t)(b))

#define CONCAT11(a,b) (((uint16_t)(uint8_t)(a) << 8) | (uint8_t)(b))
#define CONCAT12(a,b) (((uint32_t)(uint8_t)(a) << 16) | (uint16_t)(b))
#define CONCAT13(a,b) (((uint32_t)(uint8_t)(a) << 24) | ((uint32_t)(b) & 0xffffffU))
#define CONCAT14(a,b) (((uint64_t)(uint8_t)(a) << 32) | (uint32_t)(b))
#define CONCAT15(a,b) (((uint64_t)(uint8_t)(a) << 40) | ((uint64_t)(b) & 0xffffffffffULL))
#define CONCAT16(a,b) (((uint64_t)(uint8_t)(a) << 48) | ((uint64_t)(b) & 0xffffffffffffULL))
#define CONCAT17(a,b) (((uint64_t)(uint8_t)(a) << 56) | ((uint64_t)(b) & 0xffffffffffffffULL))
#define CONCAT22(a,b) (((uint32_t)(uint16_t)(a) << 16) | (uint16_t)(b))
#define CONCAT24(a,b) (((uint64_t)(uint16_t)(a) << 32) | (uint32_t)(b))
#define CONCAT26(a,b) (((uint64_t)(uint16_t)(a) << 48) | ((uint64_t)(b) & 0xffffffffffffULL))
#define CONCAT44(a,b) (((uint64_t)(uint32_t)(a) << 32) | (uint32_t)(b))

#define PTR_in_shared_0011bd00 ((uint8_t *)(ssc_image + 0x2402c))
#define PTR_win_square_0011bcc0 ((ssc_i32_u *)(ssc_image + 0x1ff80))
#define PTR_drc_struct_0011bca0 ((uint8_t *)(ssc_image + 0x20500))
#define PTR__pre_shared_0011bce0 ((uint8_t *)(ssc_image + 0x2052c))
#define PTR__pcmpower_0011bce8 ((uint8_t *)(ssc_image + 0x25e8c))
#define PTR_headroom_gain_0011bcd8 ((uint8_t *)(ssc_image + 0x20140))
#define PTR_Soundbooster_DRC_Fs_0011bcb8 ((uint8_t *)(ssc_image + 0x20520))
#define PTR_DRC_ChNum_0011bca8 ((uint8_t *)(ssc_image + 0x20518))
#define PTR_DRC_ModeFlag_0011bcb0 ((uint8_t *)(ssc_image + 0x2051c))
#define PTR_previous_uhq_index_0011bcd0 ((ssc_i32_u *)(ssc_image + 0x20528))
#define PTR_ssc_tf_select_table_0011bcc8 ((uint8_t *)(ssc_image + 0x2838))
#define PTR_coeffs96andbelow_0011bcf0 ((uint8_t *)(ssc_image + 0x3d00))
#define PTR_coeffs_0011bcf8 ((uint8_t *)(ssc_image + 0x3cec))
#define PTR_ssc_eMeans_tmp_0011bd08 ((int8_t *)(ssc_image + 0x5d78))
#define PTR_LOOP_0011b940 ((uint8_t *)(ssc_image + 0x1b940))
#define PTR_DAT_0011b948 ((uint8_t *)(ssc_image + 0x1b948))
#define PTR_DAT_0011b950 ((uint8_t *)(ssc_image + 0x1b950))
#define PTR_DAT_0011b948_arr ((ssc_u64_u *)(ssc_image + 0x1b948))
#define PTR_DAT_0011b950_arr ((ssc_u64_u *)(ssc_image + 0x1b950))
#define PTR_0011bd20 ((uint8_t *)(ssc_image + 0x1bd20))

#define DAT_00102740 (*(ssc_u64_u *)(ssc_image + 0x2740))
#define UNK_00102744 (*(ssc_u32_u *)(ssc_image + 0x2744))
#define UNK_00102748 (*(ssc_u64_u *)(ssc_image + 0x2748))
#define UNK_0010274c (*(ssc_u32_u *)(ssc_image + 0x274c))
#define DAT_00102750 (*(ssc_u64_u *)(ssc_image + 0x2750))
#define DAT_00102758 (*(ssc_u64_u *)(ssc_image + 0x2758))
#define UNK_00102758 (*(ssc_u64_u *)(ssc_image + 0x2758))
#define UNK_00105d58 (*(uint8_t *)(ssc_image + 0x5d58))
#define DAT_00102760 (*(uint8_t *)(ssc_image + 0x2760))
#define DAT_00102770 (*(ssc_u64_u *)(ssc_image + 0x2770))
#define UNK_00102778 (*(ssc_u64_u *)(ssc_image + 0x2778))
#define DAT_00102780 (*(ssc_u64_u *)(ssc_image + 0x2780))
#define UNK_00102788 (*(ssc_u64_u *)(ssc_image + 0x2788))
#define DAT_00102790 (*(ssc_u64_u *)(ssc_image + 0x2790))
#define DAT_001027a0 (*(ssc_u64_u *)(ssc_image + 0x27a0))
#define DAT_001027b0 (*(ssc_u32_u *)(ssc_image + 0x27b0))
#define UNK_001027b4 (*(ssc_u32_u *)(ssc_image + 0x27b4))
#define UNK_001027b8 (*(ssc_u32_u *)(ssc_image + 0x27b8))
#define UNK_001027bc (*(ssc_u32_u *)(ssc_image + 0x27bc))
#define DAT_001027c0 (*(uint8_t *)(ssc_image + 0x27c0))
#define DAT_001027d0 (*(ssc_u64_u *)(ssc_image + 0x27d0))
#define UNK_001027d4 (*(ssc_u32_u *)(ssc_image + 0x27d4))
#define UNK_001027d8 (*(ssc_u64_u *)(ssc_image + 0x27d8))
#define UNK_001027dc (*(ssc_u32_u *)(ssc_image + 0x27dc))
#define DAT_001027e0 (*(ssc_u64_u *)(ssc_image + 0x27e0))
#define DAT_001027f0 (*(ssc_u64_u *)(ssc_image + 0x27f0))
#define DAT_001027f8 (*(ssc_u64_u *)(ssc_image + 0x27f8))
#define DAT_00102800 (*(ssc_u64_u *)(ssc_image + 0x2800))
#define DAT_00102808 (*(ssc_u64_u *)(ssc_image + 0x2808))
#define DAT_00102810 (*(ssc_u64_u *)(ssc_image + 0x2810))
#define DAT_00102818 (*(ssc_u64_u *)(ssc_image + 0x2818))
#define DAT_00102820 (*(ssc_u64_u *)(ssc_image + 0x2820))
#define DAT_00102828 (*(ssc_u64_u *)(ssc_image + 0x2828))
#define DAT_00102830 (*(ssc_u64_u *)(ssc_image + 0x2830))
#define DAT_00102840 (*(uint8_t *)(ssc_image + 0x2840))
#define DAT_00102878 (*(uint8_t *)(ssc_image + 0x2878))
#define DAT_00103d14 (*(uint8_t *)(ssc_image + 0x3d14))
#define DAT_00103d18 (*(uint8_t *)(ssc_image + 0x3d18))
#define DAT_00103d46 (*(uint8_t *)(ssc_image + 0x3d46))
#define DAT_00103d74 (*(uint8_t *)(ssc_image + 0x3d74))
#define DAT_00103d7c (*(uint8_t *)(ssc_image + 0x3d7c))
#define DAT_00103d80 (*(uint8_t *)(ssc_image + 0x3d80))
#define DAT_00105d91 (*(uint8_t *)(ssc_image + 0x5d91))
#define DAT_00105dbf (*(uint8_t *)(ssc_image + 0x5dbf))
#define DAT_00105ded (*(uint8_t *)(ssc_image + 0x5ded))
#define DAT_00105df0 (*(uint8_t *)(ssc_image + 0x5df0))
#define DAT_0011b9c0 (*(uint8_t *)(ssc_image + 0x1b9c0))
#define DAT_0011ba40 (*(uint8_t *)(ssc_image + 0x1ba40))

static inline uint64_t neon_ext_u64(uint64_t a, uint64_t b, int idx, int size) {
    (void)size;
    uint8_t buf[16];
    memcpy((void *)(buf), (const void *)(&a), 8);
    memcpy((void *)(buf + 8), (const void *)(&b), 8);
    uint64_t res;
    memcpy((void *)(&res), (const void *)(buf + idx), 8);
    return res;
}
static inline vec128_t NEON_ext_v128(vec128_t a, vec128_t b, int idx, int size) {
    (void)size;
    uint8_t buf[32];
    memcpy((void *)(buf), (const void *)(a.b), 16);
    memcpy((void *)(buf + 16), (const void *)(b.b), 16);
    vec128_t res;
    memcpy((void *)(res.b), (const void *)(buf + idx), 16);
    return res;
}
#define NEON_ext(a, b, idx, sz) _Generic((a), vec128_t: NEON_ext_v128, default: neon_ext_u64)((a), (b), (idx), (sz))

static inline uint64_t NEON_rev64_u64(uint64_t v, int size) {
    if (size == 4) return (v >> 32) | (v << 32);
    return v;
}
static inline vec128_t NEON_rev64_v128(vec128_t a, int size) {
    vec128_t res;
    res.d[0] = NEON_rev64_u64(a.d[0], size);
    res.d[1] = NEON_rev64_u64(a.d[1], size);
    return res;
}
#define NEON_rev64(a, sz) _Generic((a), vec128_t: NEON_rev64_v128, default: NEON_rev64_u64)((a), (sz))

static inline uint64_t NEON_rshrn(uint64_t dummy, vec128_t src, int shift, int size) {
    (void)dummy; (void)size;
    int64_t v0 = (int64_t)src.d[0];
    int64_t v1 = (int64_t)src.d[1];
    int64_t round = 1LL << (shift - 1);
    int32_t r0 = (int32_t)((v0 + round) >> shift);
    int32_t r1 = (int32_t)((v1 + round) >> shift);
    return ((uint64_t)(uint32_t)r1 << 32) | (uint32_t)r0;
}

static inline vec128_t NEON_smax_v128(vec128_t a, vec128_t b, int size) {
    vec128_t res;
    if (size == 4) {
        for (int i = 0; i < 4; i++) res.ss[i] = (a.ss[i] > b.ss[i]) ? a.ss[i] : b.ss[i];
    } else if (size == 2) {
        for (int i = 0; i < 8; i++) res.sh[i] = (a.sh[i] > b.sh[i]) ? a.sh[i] : b.sh[i];
    } else {
        for (int i = 0; i < 16; i++) res.sb[i] = (a.sb[i] > b.sb[i]) ? a.sb[i] : b.sb[i];
    }
    return res;
}
static inline uint64_t NEON_smax_u64(uint64_t a, uint64_t b, int size) {
    (void)size;
    int32_t a0 = (int32_t)a, a1 = (int32_t)(a >> 32);
    int32_t b0 = (int32_t)b, b1 = (int32_t)(b >> 32);
    int32_t r0 = (a0 > b0) ? a0 : b0;
    int32_t r1 = (a1 > b1) ? a1 : b1;
    return ((uint64_t)(uint32_t)r1 << 32) | (uint32_t)r0;
}
#define NEON_smax(a, b, sz) _Generic((a), vec128_t: NEON_smax_v128, default: NEON_smax_u64)((a), (b), (sz))

static inline int32_t NEON_smaxv(vec128_t a, int size) {
    if (size == 4) {
        int32_t m = a.ss[0];
        for (int i = 1; i < 4; i++) if (a.ss[i] > m) m = a.ss[i];
        return m;
    } else if (size == 2) {
        int16_t m = a.sh[0];
        for (int i = 1; i < 8; i++) if (a.sh[i] > m) m = a.sh[i];
        return m;
    } else {
        int8_t m = a.sb[0];
        for (int i = 1; i < 16; i++) if (a.sb[i] > m) m = a.sb[i];
        return m;
    }
}

static inline vec128_t NEON_smin_v128(vec128_t a, vec128_t b, int size) {
    vec128_t res;
    if (size == 4) {
        for (int i = 0; i < 4; i++) res.ss[i] = (a.ss[i] < b.ss[i]) ? a.ss[i] : b.ss[i];
    } else if (size == 2) {
        for (int i = 0; i < 8; i++) res.sh[i] = (a.sh[i] < b.sh[i]) ? a.sh[i] : b.sh[i];
    } else {
        for (int i = 0; i < 16; i++) res.sb[i] = (a.sb[i] < b.sb[i]) ? a.sb[i] : b.sb[i];
    }
    return res;
}
static inline uint64_t NEON_smin_u64(uint64_t a, uint64_t b, int size) {
    if (size == 4) {
        int32_t a0 = (int32_t)a, a1 = (int32_t)(a >> 32);
        int32_t b0 = (int32_t)b, b1 = (int32_t)(b >> 32);
        int32_t r0 = (a0 < b0) ? a0 : b0;
        int32_t r1 = (a1 < b1) ? a1 : b1;
        return ((uint64_t)(uint32_t)r1 << 32) | (uint32_t)r0;
    } else if (size == 2) {
        int16_t a0 = (int16_t)a, a1 = (int16_t)(a >> 16), a2 = (int16_t)(a >> 32), a3 = (int16_t)(a >> 48);
        int16_t b0 = (int16_t)b, b1 = (int16_t)(b >> 16), b2 = (int16_t)(b >> 32), b3 = (int16_t)(b >> 48);
        int16_t r0 = (a0 < b0) ? a0 : b0;
        int16_t r1 = (a1 < b1) ? a1 : b1;
        int16_t r2 = (a2 < b2) ? a2 : b2;
        int16_t r3 = (a3 < b3) ? a3 : b3;
        return ((uint64_t)(uint16_t)r3 << 48) | ((uint64_t)(uint16_t)r2 << 32) | ((uint64_t)(uint16_t)r1 << 16) | (uint16_t)r0;
    }
    return a;
}
#define NEON_smin(a, b, sz) _Generic((a), vec128_t: NEON_smin_v128, default: NEON_smin_u64)((a), (b), (sz))

static inline int32_t sat_add32(int32_t a, int32_t b) {
    int64_t sum = (int64_t)a + b;
    if (sum > INT32_MAX) return INT32_MAX;
    if (sum < INT32_MIN) return INT32_MIN;
    return (int32_t)sum;
}
static inline int16_t sat_add16(int16_t a, int16_t b) {
    int32_t sum = (int32_t)a + b;
    if (sum > INT16_MAX) return INT16_MAX;
    if (sum < INT16_MIN) return INT16_MIN;
    return (int16_t)sum;
}
static inline int64_t sat_add64(int64_t a, int64_t b) {
    int64_t res;
    if (__builtin_add_overflow(a, b, &res)) {
        return (a > 0) ? INT64_MAX : INT64_MIN;
    }
    return res;
}
static inline vec128_t NEON_sqadd(vec128_t a, vec128_t b, int size) {
    vec128_t res;
    if (size == 8) {
        res.sd[0] = sat_add64(a.sd[0], b.sd[0]);
        res.sd[1] = sat_add64(a.sd[1], b.sd[1]);
    } else if (size == 4) {
        for (int i = 0; i < 4; i++) res.ss[i] = sat_add32(a.ss[i], b.ss[i]);
    } else if (size == 2) {
        for (int i = 0; i < 8; i++) res.sh[i] = sat_add16(a.sh[i], b.sh[i]);
    } else {
        for (int i = 0; i < 16; i++) {
            int16_t sum = (int16_t)a.sb[i] + b.sb[i];
            if (sum > INT8_MAX) res.sb[i] = INT8_MAX;
            else if (sum < INT8_MIN) res.sb[i] = INT8_MIN;
            else res.sb[i] = (int8_t)sum;
        }
    }
    return res;
}

static inline uint64_t NEON_srshr_u64(uint64_t val, int shift, int size) {
    (void)size;
    int32_t v0 = (int32_t)val;
    int32_t v1 = (int32_t)(val >> 32);
    int64_t round = 1LL << (shift - 1);
    int32_t r0 = (int32_t)(((int64_t)v0 + round) >> shift);
    int32_t r1 = (int32_t)(((int64_t)v1 + round) >> shift);
    return ((uint64_t)(uint32_t)r1 << 32) | (uint32_t)r0;
}
static inline vec128_t NEON_srshr_v128(vec128_t val, int shift, int size) {
    (void)size;
    vec128_t res;
    int64_t round = 1LL << (shift - 1);
    for (int i = 0; i < 4; i++) {
        res.ss[i] = (int32_t)(((int64_t)val.ss[i] + round) >> shift);
    }
    return res;
}
#define NEON_srshr(a, sh, sz) _Generic((a), vec128_t: NEON_srshr_v128, default: NEON_srshr_u64)((a), (sh), (sz))

static inline vec128_t NEON_sshl_v128(vec128_t a, vec128_t b, int size) {
    (void)size;
    vec128_t res;
    for (int i = 0; i < 4; i++) {
        int sh = b.ss[i];
        if (sh >= 32) res.ss[i] = 0;
        else if (sh >= 0) res.ss[i] = a.ss[i] << sh;
        else if (sh <= -32) res.ss[i] = a.ss[i] >> 31;
        else res.ss[i] = a.ss[i] >> (-sh);
    }
    return res;
}
static inline uint64_t NEON_sshl_u64(uint64_t a, uint64_t b, int size) {
    (void)size;
    int32_t a0 = (int32_t)a, a1 = (int32_t)(a >> 32);
    int32_t b0 = (int32_t)b, b1 = (int32_t)(b >> 32);
    int32_t r0 = (b0 >= 32) ? 0 : (b0 >= 0) ? (a0 << b0) : (b0 <= -32) ? (a0 >> 31) : (a0 >> (-b0));
    int32_t r1 = (b1 >= 32) ? 0 : (b1 >= 0) ? (a1 << b1) : (b1 <= -32) ? (a1 >> 31) : (a1 >> (-b1));
    return ((uint64_t)(uint32_t)r1 << 32) | (uint32_t)r0;
}
#define NEON_sshl(a, b, sz) _Generic((a), vec128_t: NEON_sshl_v128, default: NEON_sshl_u64)((a), (b), (sz))

static inline vec128_t NEON_ushl_v128(vec128_t a, vec128_t b, int size) {
    (void)size;
    vec128_t res;
    for (int i = 0; i < 4; i++) {
        int sh = b.ss[i];
        if (sh >= 32 || sh <= -32) res.s[i] = 0;
        else if (sh >= 0) res.s[i] = a.s[i] << sh;
        else res.s[i] = a.s[i] >> (-sh);
    }
    return res;
}
#define NEON_ushl(a, b, sz) NEON_ushl_v128((a), (b), sz)

__attribute__((constructor)) static void ssc_auto_init(void) {
    ssc_init_image();
}

void ssc_comb_filter_const_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, long param_4, int param_5, int param_6, int param_7);
void ssc_comb_filter_function1_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, int param_4, int param_5, ssc_u32_u *param_6);
void ssc_comb_filter_function2_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, int param_4, int param_5, ssc_i32_u *param_6);
void ssc_comb_filter_function3_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, int param_4, int param_5, int param_6, ssc_u32_u *param_7);
void ssc_comb_filter_function4_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, long param_4, int param_5, int param_6, int param_7, ssc_u32_u *param_8);
void ssc_amp2Log2_asm(long param_1, ssc_u64_u *param_2, ssc_i16_u *param_3, char *param_4);
void ssc_bitexact_cos_asm(int param_1, int param_2, ssc_i32_u *param_3, ssc_i32_u *param_4);
void ssc_encoder_destroy(void *st);
void Biquad_Narrow_int2int_stereo (ssc_u64_u *param_1,ssc_u64_u *param_2,ssc_i32_u *param_3,ssc_i64_u *param_4,int param_5);
void powercalc(ssc_u64_u *param_1,int param_2,ssc_u32_u *param_3);
int CalculateLimitGain(int param_1,int param_2,uint param_3,int param_4);
void set_DRC_limit_gain(undefined4 param_1);
void SSC_DRC_Exe(ssc_u32_u *param_1,int param_2);
void SSC_DRC_SetPar(int param_1,undefined4 param_2, ...);
void SSC_DRC_Init(uint param_1,int param_2);
void ssc_comb_filter(long param_1,long param_2,undefined8 param_3,int param_4,int param_5, uint param_6,uint param_7,uint param_8);
ulong ssc_hysteresis_decision(short param_1,long param_2,long param_3,uint param_4,uint param_5);
void CalculateBandEnergy(long param_1,long param_2,long param_3,uint param_4,int param_5,int param_6 );
void ssc_compute_band_energies(long param_1,long param_2,long param_3,uint param_4);
void CalculateBandEnergyLastBand (long param_1,long param_2,long param_3,ulong param_4,uint param_5,int param_6, int param_7);
void ssc_compute_band_energies_for_lastband (long param_1,long param_2,ssc_i32_u *param_3,uint param_4,int param_5,uint param_6);
void ssc_normalise_bands(long param_1,undefined1 (*param_2) [16],ssc_u64_u *param_3,ssc_u32_u *param_4, int param_5);
undefined1 ssc_spreading_decision(ssc_i64_u *param_1,long param_2,int param_3,uint param_4);
void ssc_haar1(ssc_i16_u *param_1,int param_2,uint param_3);
void ssc_quant_all_bands(long param_1,uint param_2,long param_3,long param_4,undefined8 param_5, long param_6,int param_7,undefined4 param_8,int param_9,uint param_10, long param_11,int param_12,int param_13,undefined8 param_14,int param_15, ssc_u32_u *param_16);
ulong FUN_00109038(long param_1,ssc_i16_u *param_2,int param_3,undefined4 param_4,int param_5, undefined4 param_6,undefined8 param_7,ulong param_8);
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong FUN_00109460(long param_1,undefined1 (*param_2) [16],uint param_3,int param_4, undefined8 param_5,int param_6,short param_7,uint param_8);
void FUN_00109ca4(long param_1,ssc_u64_u *param_2,ssc_u64_u *param_3,long param_4,int param_5, uint param_6);
void ssc_encode_pulses(long param_1,ulong param_2,int param_3,undefined8 param_4);
int ssc_encoder_get_size(int param_1,undefined4 param_2);
int ssc_encoder_init(ssc_i64_u *param_1,int param_2,int param_3,int param_4);
void * ssc_encoder_create(int param_1,int param_2,int param_3,ssc_i32_u *param_4);
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void normal_headroom(long param_1,int param_2,int param_3,long param_4,int param_5);
void uhq_headroom(long param_1,int param_2,int param_3,long param_4);
void ssc_preemphasis(ssc_i32_u *param_1,ssc_i32_u *param_2,int param_3,undefined8 param_4,int param_5);
uint getPitchIndexGain(long param_1,long param_2,ssc_i32_u *param_3,int param_4,int param_5);
uint getPitchFilterThreshold(long param_1,int param_2,int param_3);
undefined8 prefilter_gain_calculation(short param_1,short param_2,ssc_i32_u *param_3,ssc_i16_u *param_4);
ulong last_band_info_calc(int param_1,uint param_2,long param_3);
undefined8 get_header_from_bitrate(int param_1);
void set_limit_gain_from_bitrate(int param_1,int param_2);
void get_uhq_info_from_bitrate(int param_1,ssc_u32_u *param_2,ssc_u32_u *param_3);
void set_data_header(long param_1,undefined1 param_2,uint param_3,int param_4);
void set_data_frame_header (ssc_u16_u *param_1,int param_2,undefined8 param_3,uint param_4,byte param_5, int param_6);
/* WARNING: Type propagation algorithm not settling */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int ssc_encode(ssc_i64_u *param_1,const ssc_i32_u *param_2,int param_3,uint8_t *param_4_u8,int param_5);
int ssc_ec_tell_frac(long param_1);
void ssc_ec_enc_init(ssc_u64_u *param_1, undefined8 param_2, undefined4 param_3);
void ssc_ec_encode(long param_1,int param_2,int param_3,uint param_4);
void FUN_0010f88c(ssc_i64_u *param_1);
void ssc_ec_encode_bin(long param_1,int param_2,int param_3,uint param_4);
void ssc_ec_enc_bit_logp(long param_1,int param_2,uint param_3);
void ssc_ec_enc_icdf(long param_1,uint param_2,long param_3,uint param_4);
void ssc_ec_enc_uint(ssc_i64_u *param_1,uint param_2,uint param_3);
void ssc_ec_enc_bits(ssc_i64_u *param_1,int param_2,int param_3);
void ssc_ec_enc_patch_initial_bits(ssc_u64_u *param_1,int param_2,uint param_3);
void ssc_ec_enc_shrink(ssc_i64_u *param_1,uint param_2);
void ssc_ec_enc_done(ssc_i64_u *param_1);
ulong smull32_x86_scalable(int param_1,int param_2);
void ssc_fft(ssc_i32_u *param_1,ssc_u32_u *param_2,ssc_u64_u *param_3);
void ssc_ec_laplace_encode(undefined8 param_1,ssc_u32_u *param_2,uint param_3,int param_4);
void _ssc_lpc(ssc_u16_u *param_1,ssc_i32_u *param_2);
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ uint _ssc_autocorr(undefined *param_1,ssc_u32_u *param_2);
int ssc_frac_div32(int param_1,uint param_2);
int ssc_rcp(uint param_1);
int ssc_rsqrt_norm(short param_1);
ulong ssc_sqrt(ulong param_1);
uint ssc_cos_norm(uint param_1);
void ssc_mdct_forward(ssc_i32_u *param_1,long param_2,ssc_u32_u *param_3,uint param_4,uint param_5, uint param_6);
undefined * ssc_custom_mode_create(int param_1,undefined8 param_2,ssc_u32_u *param_3);
void ssc_pitch_downsample(ssc_i32_u *param_1,ssc_i32_u *param_2,ssc_i16_u *param_3,uint param_4);
undefined8 tone_detect(long param_1,ssc_u32_u *param_2,int param_3,int param_4);
void ssc_pitch_search(ssc_u16_u *param_1,ssc_u16_u *param_2,int param_3,int param_4,ssc_i32_u *param_5);
void FUN_001126bc(ssc_u64_u *param_1,int param_2,uint param_3,ssc_u64_u *param_4,uint param_5, uint param_6);
uint ssc_remove_doubling(long param_1,uint param_2,uint param_3,int param_4,ssc_u32_u *param_5, int param_6,short param_7);
int ssc_pitch_xcorr_c2(ssc_u64_u *param_1,long param_2,long param_3,int param_4,int param_5);
undefined8 ssc_pitch_xcorr_c1(long param_1,undefined1 (*param_2) [16],ssc_u64_u *param_3);
void ssc_quant_coarse_energy (long param_1,undefined8 param_2,int param_3,long param_4,long param_5,uint param_6, undefined8 param_7,ssc_i64_u *param_8,int param_9,int param_10,ssc_u32_u *param_11);
int FUN_00113734(long param_1,uint param_2,long param_3,long param_4,int param_5,int param_6,long param_7,long param_8,long param_9,int param_10,short param_11);
void ssc_quant_fine_energy (long param_1,uint param_2,long param_3,long param_4,long param_5,ssc_i64_u *param_6);
void ssc_quant_energy_finalise (long param_1,int param_2,long param_3,long param_4,long param_5,long param_6, int param_7,ssc_i64_u *param_8);
void ssc_amp2Log2(undefined8 param_1,uint param_2,long param_3,long param_4);
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ uint ssc_compute_allocation(ssc_i64_u *param_1,ssc_u32_u *param_2,undefined8 param_3,uint param_4,int param_5);
void SSC_COPY32(ulong param_1,ulong param_2,uint param_3);
void SSC_COPY16(ulong param_1,ulong param_2,uint param_3);
void SSC_COPY8(ulong param_1,ulong param_2,uint param_3);
void SSC_CLEAR(void *param_1,uint param_2);
ulong ssc_alg_quant(ssc_i16_u *param_4,uint param_5,int param_6,int param_7,uint param_8, undefined8 param_9);
int ssc_stereo_itheta(long param_1,long param_2,uint param_3);
void FUN_001167d0(ssc_u16_u *param_1,int param_2,short param_3,short param_4);

/* Function: Biquad_Narrow_int2int_stereo @ 00106d8c */
/* ==================================================================== */

void Biquad_Narrow_int2int_stereo
               (ssc_u64_u *param_1,ssc_u64_u *param_2,ssc_i32_u *param_3,ssc_i64_u *param_4,int param_5)

{
  vec128_t auVar1;
  vec128_t auVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  vec128_t auVar31;
  undefined8 uVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  vec128_t auVar42;

  lVar3 = param_4[9];
  uVar10 = (undefined1)lVar3;
  uVar11 = (undefined1)((ulong)lVar3 >> 8);
  uVar12 = (undefined1)((ulong)lVar3 >> 0x10);
  uVar13 = (undefined1)((ulong)lVar3 >> 0x18);
  uVar14 = (undefined1)((ulong)lVar3 >> 0x20);
  uVar15 = (undefined1)((ulong)lVar3 >> 0x28);
  uVar16 = (undefined1)((ulong)lVar3 >> 0x30);
  uVar17 = (undefined1)((ulong)lVar3 >> 0x38);
  iVar26 = (int)param_4[7];
  lVar3 = param_4[4];
  uVar18 = (undefined1)lVar3;
  uVar19 = (undefined1)((ulong)lVar3 >> 8);
  uVar20 = (undefined1)((ulong)lVar3 >> 0x10);
  uVar21 = (undefined1)((ulong)lVar3 >> 0x18);
  uVar22 = (undefined1)((ulong)lVar3 >> 0x20);
  uVar23 = (undefined1)((ulong)lVar3 >> 0x28);
  uVar24 = (undefined1)((ulong)lVar3 >> 0x30);
  uVar25 = (undefined1)((ulong)lVar3 >> 0x38);
  iVar28 = (int)param_4[8];
  uVar32 = CONCAT44((int)*param_4,(int)param_4[5]);
  iVar27 = (int)param_4[2];
  param_5 = param_5 + 2;
  iVar29 = (int)param_4[3];
  iVar30 = *param_3;
  iVar34 = param_3[1];
  iVar35 = param_3[2];
  iVar36 = param_3[3];
  iVar37 = param_3[4];
  iVar7 = (int)param_4[6];
  iVar9 = (int)param_4[1];
  do {
    param_5 = param_5 + -2;
    iVar38 = (int)*param_2 << 7;
    iVar39 = (int)((ulong)*param_2 >> 0x20) << 7;
    iVar40 = (int)param_2[1] << 7;
    iVar41 = (int)((ulong)param_2[1] >> 0x20) << 7;
    iVar33 = (int)((ulong)uVar32 >> 0x20);
    lVar3 = CONCAT17(uVar17,CONCAT16(uVar16,CONCAT15(uVar15,CONCAT14(uVar14,CONCAT13(uVar13,CONCAT12
                                                  (uVar12,CONCAT11(uVar11,uVar10))))))) +
            (long)iVar38 * (long)iVar30 + (long)(int)uVar32 * (long)iVar34 +
            (long)iVar7 * (long)iVar35 + (long)iVar26 * (long)iVar36;
    lVar5 = CONCAT17(uVar25,CONCAT16(uVar24,CONCAT15(uVar23,CONCAT14(uVar22,CONCAT13(uVar21,CONCAT12
                                                  (uVar20,CONCAT11(uVar19,uVar18))))))) +
            (long)iVar39 * (long)iVar30 + (long)iVar33 * (long)iVar34 + (long)iVar9 * (long)iVar35 +
            (long)iVar27 * (long)iVar36;
    iVar6 = (int)((ulong)(lVar3 + (long)iVar28 * (long)iVar37) >> 0x20);
    iVar8 = (int)((ulong)(lVar5 + (long)iVar29 * (long)iVar37) >> 0x20);
    iVar7 = iVar28 * iVar37;
    iVar9 = iVar29 * iVar37;
    iVar28 = iVar6 << 3;
    iVar29 = iVar8 << 3;
    lVar3 = (ulong)(uint)((int)lVar3 + iVar7) + (long)iVar40 * (long)iVar30 +
            (long)iVar38 * (long)iVar34 + (long)(int)uVar32 * (long)iVar35 +
            (long)iVar28 * (long)iVar36;
    lVar5 = (ulong)(uint)((int)lVar5 + iVar9) + (long)iVar41 * (long)iVar30 +
            (long)iVar39 * (long)iVar34 + (long)iVar33 * (long)iVar35 + (long)iVar29 * (long)iVar36;
    iVar7 = (int)((ulong)(lVar3 + (long)iVar26 * (long)iVar37) >> 0x20);
    iVar9 = (int)((ulong)(lVar5 + (long)iVar27 * (long)iVar37) >> 0x20);
    uVar4 = lVar3 + (long)iVar26 * (long)iVar37;
    uVar10 = (undefined1)uVar4;
    uVar11 = (undefined1)(uVar4 >> 8);
    uVar12 = (undefined1)(uVar4 >> 0x10);
    uVar13 = (undefined1)(uVar4 >> 0x18);
    lVar5 = lVar5 + (long)iVar27 * (long)iVar37;
    uVar18 = (undefined1)lVar5;
    uVar19 = (undefined1)((ulong)lVar5 >> 8);
    uVar20 = (undefined1)((ulong)lVar5 >> 0x10);
    uVar21 = (undefined1)((ulong)lVar5 >> 0x18);
    uVar14 = 0;
    uVar15 = 0;
    uVar16 = 0;
    uVar17 = 0;
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    auVar42._4_4_ = iVar39;
    auVar42._0_4_ = iVar38;
    auVar42._8_4_ = iVar40;
    auVar42._12_4_ = iVar41;
    auVar31._4_4_ = iVar39;
    auVar31._0_4_ = iVar38;
    auVar31._8_4_ = iVar40;
    auVar31._12_4_ = iVar41;
    auVar42 = NEON_ext(auVar42,auVar31,8,1);
    iVar26 = iVar7 << 3;
    iVar27 = iVar9 << 3;
    uVar32 = auVar42._0_8_;
    param_1[1] = CONCAT44(iVar9 + 8 >> 4,iVar7 + 8 >> 4);
    *param_1 = CONCAT44(iVar8 + 8 >> 4,iVar6 + 8 >> 4);
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    iVar7 = iVar38;
    iVar9 = iVar39;
  } while (2 < param_5);
  auVar1.b[8] = uVar18;
  auVar1._0_8_ = uVar4 & 0xffffffff;
  auVar1.b[9] = uVar19;
  auVar1.b[10] = uVar20;
  auVar1.b[0xb] = uVar21;
  auVar1._12_4_ = 0;
  auVar2.b[8] = uVar18;
  auVar2._0_8_ = uVar4 & 0xffffffff;
  auVar2.b[9] = uVar19;
  auVar2.b[10] = uVar20;
  auVar2.b[0xb] = uVar21;
  auVar2._12_4_ = 0;
  auVar31 = NEON_ext(auVar1,auVar2,8,1);
  param_4[6] = (long)iVar38;
  param_4[1] = (long)iVar39;
  *param_4 = (long)auVar42._4_4_;
  param_4[3] = (long)iVar29;
  param_4[2] = (long)iVar27;
  param_4[8] = (long)iVar28;
  param_4[7] = (long)iVar26;
  param_4[5] = (long)auVar42._0_4_;
  param_4[4] = (long)auVar31._0_4_;
  param_4[9] = (long)(int)uVar4;
  return;
}


/* ==================================================================== */
/* Function: powercalc @ 00106ea0 */
/* ==================================================================== */

void powercalc(ssc_u64_u *param_1,int param_2,ssc_u32_u *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;

  if (param_2 == 0) {
    lVar1 = 0;
    lVar2 = 0;
  }
  else {
    lVar1 = 0;
    lVar2 = 0;
    do {
      uVar4 = *param_1;
      param_1 = param_1 + 0x20;
      param_2 = param_2 + -0x20;
      iVar3 = (int)uVar4;
      iVar5 = (int)((ulong)uVar4 >> 0x20);
      lVar1 = lVar1 + ((ulong)((long)iVar3 * (long)iVar3) >> 0x10 & 0xfffffffffffe) * 0x10;
      lVar2 = lVar2 + ((ulong)((long)iVar5 * (long)iVar5) >> 0x10 & 0xfffffffffffe) * 0x10;
    } while (param_2 != 0);
  }
  *param_3 = (int)((ulong)(lVar1 + lVar2) >> 9);
  return;
}


/* ==================================================================== */
/* Function: CalculateLimitGain @ 00106f0c */
/* ==================================================================== */

int CalculateLimitGain(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;

  if ((int)param_3 < 0x17701) {
    iVar2 = -0x50;
    iVar1 = 0x76c0;
  }
  else {
    if (0x1f400 < param_3) {
      if (param_4 == 96000) {
        lVar3 = (long)param_2;
        iVar2 = (int)((ulong)((long)param_2 * 0xf0a4) >> 0x10);
        if (param_3 < 270000) {
          if (iVar2 <= param_1) {
            return 0x7b4c;
          }
          if ((int)((ulong)(lVar3 * 0xeb85) >> 0x10) <= param_1) {
            return 0x7a52;
          }
          if ((int)((ulong)(lVar3 * 0xe666) >> 0x10) <= param_1) {
            return 0x796c;
          }
          if ((int)((ulong)(lVar3 * 0xcccc) >> 0x10) <= param_1) {
            return 0x7890;
          }
        }
        else {
          if (iVar2 <= param_1) {
            return 0x7b4c;
          }
          if ((int)((ulong)(lVar3 * 0xeb85) >> 0x10) <= param_1) {
            return 0x7a01;
          }
          if ((int)((ulong)(lVar3 * 0xe666) >> 0x10) <= param_1) {
            return 0x78f4;
          }
          if ((int)((ulong)(lVar3 * 0xcccc) >> 0x10) <= param_1) {
            return 0x785e;
          }
        }
        return 0x75d4;
      }
      if ((int)((ulong)((long)param_2 * 0xe666) >> 0x10) <= param_1) {
        return 0x7a94;
      }
      if ((int)((ulong)((long)param_2 * 0xcccc) >> 0x10) <= param_1) {
        return 0x76b3;
      }
      iVar2 = 0x741d;
      goto LAB_00106f5c;
    }
    iVar2 = -0x2f8;
    iVar1 = 0x78b4;
  }
  if ((int)((ulong)((long)param_2 * 0xe666) >> 0x10) <= param_1) {
    return iVar1;
  }
  iVar2 = iVar2 + iVar1;
LAB_00106f5c:
  iVar1 = 0x8000;
  if (param_2 >> 2 <= param_1) {
    iVar1 = iVar2;
  }
  return iVar1;
}


/* ==================================================================== */
/* Function: set_DRC_limit_gain @ 001070b4 */
/* ==================================================================== */

void set_DRC_limit_gain(undefined4 param_1)

{
  *(ssc_u32_u *)PTR_drc_struct_0011bca0 = param_1;
  return;
}


/* ==================================================================== */
/* Function: SSC_DRC_Exe @ 001070c4 */
/* ==================================================================== */

void SSC_DRC_Exe(ssc_u32_u *param_1,int param_2)

{
  ssc_u32_u *puVar1;
  uint uVar2;
  ssc_u32_u *puVar3;
  ssc_u32_u *puVar4;
  vec128_t auVar5;
  vec128_t auVar6;
  undefined8 uVar7;
  ssc_i32_u *piVar8;
  undefined *puVar9;
  int iVar10;
  ssc_u32_u *puVar11;
  long lVar12;
  int iVar13;
  long lVar14;
  uint uVar15;
  ssc_u32_u *puVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  long lVar20;
  uint uVar21;
  long lVar22;
  vec128_t auVar23;
  long lVar24;
  uint uVar25;
  long lVar26;
  vec128_t auVar27;
  long lVar28;
  byte bVar30;
  byte bVar31;
  int iVar29;
  byte bVar32;
  byte bVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;

  puVar9 = PTR_drc_struct_0011bca0;
  iVar13 = *(ssc_i32_u *)PTR_DRC_ChNum_0011bca8 * param_2;
  iVar29 = iVar13;
  if (0 < iVar13) {
    iVar29 = 1;
  }
  iVar10 = *(ssc_i32_u *)PTR_drc_struct_0011bca0;
  if ((uint)(iVar13 - iVar29) < 7) {
    uVar21 = 0;
    uVar25 = 0;
    puVar11 = param_1;
LAB_00107188:
    iVar13 = iVar13 + 1;
    uVar15 = uVar21;
    do {
      uVar21 = *puVar11;
      iVar13 = iVar13 + -1;
      uVar2 = -uVar21;
      if (-1 < (int)uVar21) {
        uVar2 = uVar21;
      }
      uVar21 = uVar2;
      if ((int)uVar2 <= (int)uVar15) {
        uVar21 = uVar15;
      }
      if (iVar10 < (int)uVar2) {
        uVar25 = uVar25 + 1;
      }
      puVar11 = puVar11 + 1;
      uVar15 = uVar21;
    } while (1 < iVar13);
  }
  else {
    uVar18 = (ulong)(uint)(iVar13 - iVar29) + 1;
    puVar16 = param_1 + 4;
    uVar17 = uVar18 & 0x1fffffff8;
    auVar23 = ZEXT816(0);
    iVar13 = iVar13 - (int)uVar17;
    auVar27 = ZEXT816(0);
    puVar11 = param_1 + uVar17;
    iVar29 = 0;
    iVar34 = 0;
    iVar35 = 0;
    iVar36 = 0;
    iVar37 = 0;
    iVar38 = 0;
    iVar39 = 0;
    iVar40 = 0;
    uVar19 = uVar17;
    do {
      puVar1 = puVar16 + -4;
      puVar3 = puVar16 + -2;
      puVar4 = puVar16 + 2;
      uVar7 = *(ssc_u64_u *)puVar16;
      puVar16 = puVar16 + 8;
      uVar19 = uVar19 - 8;
      iVar41 = MP_INT_ABS((int)*(ssc_u64_u *)puVar1);
      iVar42 = MP_INT_ABS((int)((ulong)*(ssc_u64_u *)puVar1 >> 0x20));
      iVar43 = MP_INT_ABS((int)*(ssc_u64_u *)puVar3);
      iVar44 = MP_INT_ABS((int)((ulong)*(ssc_u64_u *)puVar3 >> 0x20));
      iVar45 = MP_INT_ABS((int)uVar7);
      iVar46 = MP_INT_ABS((int)((ulong)uVar7 >> 0x20));
      iVar47 = MP_INT_ABS((int)*(ssc_u64_u *)puVar4);
      iVar48 = MP_INT_ABS((int)((ulong)*(ssc_u64_u *)puVar4 >> 0x20));
      auVar5._4_4_ = iVar42;
      auVar5._0_4_ = iVar41;
      auVar5._8_4_ = iVar43;
      auVar5._12_4_ = iVar44;
      auVar23 = NEON_smax(auVar23,auVar5,4);
      auVar6._4_4_ = iVar46;
      auVar6._0_4_ = iVar45;
      auVar6._8_4_ = iVar47;
      auVar6._12_4_ = iVar48;
      auVar27 = NEON_smax(auVar27,auVar6,4);
      iVar29 = iVar29 + (uint)(iVar10 < iVar41);
      iVar34 = iVar34 + (uint)(iVar10 < iVar42);
      iVar35 = iVar35 + (uint)(iVar10 < iVar43);
      iVar36 = iVar36 + (uint)(iVar10 < iVar44);
      iVar37 = iVar37 + (uint)(iVar10 < iVar45);
      iVar38 = iVar38 + (uint)(iVar10 < iVar46);
      iVar39 = iVar39 + (uint)(iVar10 < iVar47);
      iVar40 = iVar40 + (uint)(iVar10 < iVar48);
    } while (uVar19 != 0);
    auVar23 = NEON_smax(auVar23,auVar27,4);
    uVar25 = iVar37 + iVar29 + iVar38 + iVar34 + iVar39 + iVar35 + iVar40 + iVar36;
    uVar21 = NEON_smaxv(auVar23,4);
    if (uVar18 != uVar17) goto LAB_00107188;
  }
  iVar13 = 0x400000;
  if (0x18 < uVar25) {
    if (uVar21 == 0) {
      iVar13 = 0x2000;
    }
    else {
      iVar13 = 0;
      if ((ulong)uVar21 != 0) {
        iVar13 = (int)(((long)iVar10 << 0x1f) / (long)(ulong)uVar21);
      }
      iVar13 = iVar13 >> 9;
    }
  }
  piVar8 = (ssc_i32_u *)(PTR_drc_struct_0011bca0 + 8);
  if (iVar13 <= *(ssc_i32_u *)(PTR_drc_struct_0011bca0 + 0xc)) {
    piVar8 = (ssc_i32_u *)(PTR_drc_struct_0011bca0 + 4);
  }
  iVar29 = *(ssc_i32_u *)(PTR_drc_struct_0011bca0 + 0x10);
  lVar14 = (long)iVar29;
  iVar10 = (int)((ulong)((long)*piVar8 * (long)*(ssc_i32_u *)(PTR_drc_struct_0011bca0 + 0xc) +
                        (long)(0x400000 - *piVar8) * (long)iVar13) >> 0x16);
  iVar13 = *(ssc_i32_u *)(PTR_drc_struct_0011bca0 + 0x14);
  if (iVar10 <= *(ssc_i32_u *)(PTR_drc_struct_0011bca0 + 0x14)) {
    iVar13 = iVar10;
  }
  *(ssc_i32_u *)(PTR_drc_struct_0011bca0 + 0xc) = iVar10;
  iVar34 = 0;
  if (param_2 != 0) {
    iVar34 = (iVar13 - iVar29) / param_2;
  }
  if ((iVar29 != 0x400000) || (iVar34 != 0)) {
    lVar12 = (long)iVar34;
    iVar29 = param_2;
    if (0 < param_2) {
      iVar29 = 1;
    }
    if (2 < (uint)(param_2 - iVar29)) {
      lVar20 = lVar12 * 4;
      uVar18 = (ulong)(uint)(param_2 - iVar29) + 1;
      uVar17 = uVar18 & 0x1fffffffc;
      param_2 = param_2 - (int)uVar17;
      bVar30 = (byte)((uint)iVar34 >> 8);
      bVar31 = (byte)((uint)iVar34 >> 0x10);
      bVar32 = (byte)((uint)iVar34 >> 0x18);
      bVar33 = (byte)(iVar34 >> 0x1f);
      auVar23._0_8_ =
           CONCAT17(bVar33 & (*(uint8_t *)(ssc_image + 0x27a7)),
                    CONCAT16(bVar33 & (*(uint8_t *)(ssc_image + 0x27a6)),
                             CONCAT15(bVar33 & (*(uint8_t *)(ssc_image + 0x27a5)),
                                      CONCAT14(bVar33 & (*(uint8_t *)(ssc_image + 0x27a4)),
                                               CONCAT13(bVar32 & (*(uint8_t *)(ssc_image + 0x27a3)),
                                                        CONCAT12(bVar31 & (*(uint8_t *)(ssc_image + 0x27a2)),
                                                                 CONCAT11(bVar30 & (*(uint8_t *)(ssc_image + 0x27a1)),
                                                                          (byte)iVar34 &
                                                                          DAT_001027a0)))))));
      auVar23.b[8] = (byte)iVar34 & (*(uint8_t *)(ssc_image + 0x27a8));
      auVar23.b[9] = bVar30 & (*(uint8_t *)(ssc_image + 0x27a9));
      auVar23.b[10] = bVar31 & (*(uint8_t *)(ssc_image + 0x27aa));
      auVar23.b[0xb] = bVar32 & (*(uint8_t *)(ssc_image + 0x27ab));
      auVar23.b[0xc] = bVar33 & (*(uint8_t *)(ssc_image + 0x27ac));
      auVar23.b[0xd] = bVar33 & (*(uint8_t *)(ssc_image + 0x27ad));
      auVar23.b[0xe] = bVar33 & (*(uint8_t *)(ssc_image + 0x27ae));
      auVar23.b[0xf] = bVar33 & (*(uint8_t *)(ssc_image + 0x27af));
      puVar16 = param_1 + uVar17 * 2;
      uVar19 = uVar17;
      lVar26 = lVar14 + auVar23._0_8_;
      lVar28 = lVar14 + auVar23._8_8_;
      lVar22 = lVar14 + lVar12 * 2;
      lVar24 = lVar14 + lVar12 * 3;
      do {
        uVar19 = uVar19 - 4;
        *param_1 = (uint)((ulong)(lVar26 * (int)*param_1) >> 0x16);
        param_1[1] = (uint)((ulong)(lVar26 * (int)param_1[1]) >> 0x16);
        param_1[2] = (uint)((ulong)(lVar28 * (int)param_1[2]) >> 0x16);
        param_1[3] = (uint)((ulong)(lVar28 * (int)param_1[3]) >> 0x16);
        param_1[4] = (uint)((ulong)(lVar22 * (int)param_1[4]) >> 0x16);
        param_1[5] = (uint)((ulong)(lVar22 * (int)param_1[5]) >> 0x16);
        param_1[6] = (uint)((ulong)(lVar24 * (int)param_1[6]) >> 0x16);
        param_1[7] = (uint)((ulong)(lVar24 * (int)param_1[7]) >> 0x16);
        param_1 = param_1 + 8;
        lVar26 = lVar26 + lVar20;
        lVar28 = lVar28 + lVar20;
        lVar22 = lVar22 + lVar20;
        lVar24 = lVar24 + lVar20;
      } while (uVar19 != 0);
      lVar14 = lVar14 + uVar17 * lVar12;
      param_1 = puVar16;
      if (uVar18 == uVar17) goto LAB_00107370;
    }
    param_2 = param_2 + 1;
    do {
      param_2 = param_2 + -1;
      uVar18 = lVar14 * (int)*param_1;
      uVar19 = lVar14 * (int)param_1[1];
      lVar14 = lVar14 + lVar12;
      *param_1 = (uint)(uVar18 >> 0x16);
      param_1[1] = (uint)(uVar19 >> 0x16);
      param_1 = param_1 + 2;
    } while (1 < param_2);
  }
LAB_00107370:
  *(ssc_i32_u *)(puVar9 + 0x10) = iVar13;
  *(ssc_i32_u *)(puVar9 + 0x14) = iVar10;
  return;
}


/* ==================================================================== */
/* Function: SSC_DRC_SetPar @ 0010737c */
/* ==================================================================== */

void SSC_DRC_SetPar(int param_1,undefined4 param_2, ...)
{
  undefined8 uVar1;
  undefined *puVar2;

  puVar2 = PTR_drc_struct_0011bca0;
  uVar1 = DAT_00102808;
  *(ssc_u32_u *)PTR_DRC_ModeFlag_0011bcb0 = (uint)(param_1 == 1);
  *(ssc_u32_u *)puVar2 = param_2;
  *(ssc_u64_u *)(puVar2 + 4) = uVar1;
  *(ssc_u32_u *)(puVar2 + 0xc) = 0x400000;
  return;
}


/* ==================================================================== */
/* Function: SSC_DRC_Init @ 001073b4 */
/* ==================================================================== */

void SSC_DRC_Init(uint param_1,int param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;

  puVar3 = PTR_DRC_ChNum_0011bca8;
  puVar2 = PTR_drc_struct_0011bca0;
  uVar1 = DAT_00102800;
  if ((int)param_1 < 0x1f41) {
    param_1 = 8000;
  }
  if (0x176 < param_1 >> 9) {
    param_1 = 0x2ee00;
  }
  uVar4 = 1;
  if (param_2 == 2) {
    uVar4 = 2;
  }
  *(ssc_u32_u *)PTR_Soundbooster_DRC_Fs_0011bcb8 = param_1;
  *(ssc_u32_u *)puVar3 = uVar4;
  *(ssc_u64_u *)(puVar2 + 0x10) = uVar1;
  return;
}


/* ==================================================================== */
/* Function: ssc_comb_filter @ 00107410 */

void ssc_comb_filter(long param_1,long param_2,undefined8 param_3,int param_4,int param_5,
                    uint param_6,uint param_7,uint param_8)

{
  int iVar1;
  ulong uVar2;

  if (((param_7 | param_6) & 0xffff) == 0) {
    if (param_2 == param_1) {
      return;
    }
LAB_00107500:
    SSC_COPY32((ulong)param_1,(ulong)param_2,param_5);
    return;
  }
  uVar2 = (ulong)param_8;
  if ((param_6 & 0xffff) == 0) {
    ssc_comb_filter_function1_asm((ssc_i32_u *)(uintptr_t)((uintptr_t)param_1),(ssc_i32_u *)(uintptr_t)((uintptr_t)param_2),param_4,param_7,uVar2,(ssc_u32_u *)PTR_win_square_0011bcc0);
  }
  else {
    if ((param_7 & 0xffff) == 0) {
      ssc_comb_filter_function2_asm((ssc_i32_u *)(uintptr_t)((uintptr_t)param_1),(ssc_i32_u *)(uintptr_t)((uintptr_t)param_2),param_3,param_6,uVar2,(ssc_i32_u *)PTR_win_square_0011bcc0);
      if (param_2 == param_1) {
        return;
      }
      param_5 = param_5 - param_8;
      param_1 = param_1 + (long)(int)param_8 * 4;
      param_2 = param_2 + (long)(int)param_8 * 4;
      goto LAB_00107500;
    }
    if ((int)param_3 == param_4) {
      ssc_comb_filter_function3_asm
                ((ssc_i32_u *)(uintptr_t)((uintptr_t)param_1),(ssc_i32_u *)(uintptr_t)((uintptr_t)param_2),param_3,param_6,param_7,uVar2,(ssc_u32_u *)PTR_win_square_0011bcc0);
    }
    else {
      ssc_comb_filter_function4_asm
                ((ssc_i32_u *)(uintptr_t)((uintptr_t)param_1),(ssc_i32_u *)(uintptr_t)((uintptr_t)param_2),param_3,param_4,param_6,param_7,uVar2,(ssc_u32_u *)PTR_win_square_0011bcc0);
    }
  }
  uVar2 = -(ulong)(param_8 >> 0x1f) & 0xfffffffc00000000 | uVar2 << 2;
  iVar1 = (int)(short)param_7;
  ssc_comb_filter_const_asm
            ((ssc_i32_u *)(uintptr_t)((uintptr_t)(param_1 + uVar2)),(ssc_i32_u *)(uintptr_t)((uintptr_t)(param_2 + uVar2)),param_4,param_5 - param_8,iVar1 * 0x4e80 >> 0x10,
             iVar1 * 0x1bc8 >> 0xf,iVar1 * 0x1098 >> 0xf);
  return;
}

/* Function: ssc_hysteresis_decision @ 0010759c */
/* ==================================================================== */

ulong ssc_hysteresis_decision(short param_1,long param_2,long param_3,uint param_4,uint param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;

  if ((int)param_4 < 1) {
    uVar3 = 0;
    if ((int)param_5 < 0) goto LAB_001075ec;
  }
  else {
    uVar2 = 0;
    do {
      uVar3 = uVar2;
      if (param_1 < *(ssc_i16_u *)(uintptr_t)((param_2 + uVar2 * 2))) break;
      uVar2 = uVar2 + 1;
      uVar3 = (ulong)param_4;
    } while (param_4 != uVar2);
    if ((int)param_5 < (int)uVar3) {
LAB_001075ec:
      uVar2 = -(ulong)(param_5 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_5 << 1;
      uVar1 = param_5;
      if ((int)*(ssc_i16_u *)(uintptr_t)((param_3 + uVar2)) + (int)*(ssc_i16_u *)(uintptr_t)((param_2 + uVar2)) <= (int)param_1) {
        uVar1 = (uint)uVar3;
      }
      uVar3 = (ulong)uVar1;
      goto joined_r0x00107608;
    }
  }
  uVar1 = (uint)uVar3;
joined_r0x00107608:
  if ((int)uVar1 < (int)param_5) {
    lVar4 = (-(ulong)(param_5 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_5 << 1) - 2;
    if ((int)param_1 <= (int)*(ssc_i16_u *)(uintptr_t)((param_2 + lVar4)) - (int)*(ssc_i16_u *)(uintptr_t)((param_3 + lVar4))) {
      param_5 = (uint)uVar3;
    }
    return (ulong)param_5;
  }
  return uVar3;
}


/* ==================================================================== */
/* Function: CalculateBandEnergy @ 00107630 */
/* ==================================================================== */

void CalculateBandEnergy(long param_1,long param_2,long param_3,uint param_4,int param_5,int param_6
                        )

{
  undefined1 (*pauVar1) [16];
  ulong uVar2;
  uint uVar3;
  vec128_t auVar4;
  vec128_t auVar5;
  undefined1 (*pauVar6) [16];
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  long lVar11;
  long lVar12;
  undefined1 (*pauVar13) [16];
  long lVar14;
  undefined1 (*pauVar15) [16];
  ulong uVar16;
  uint uVar17;
  int iVar18;
  int iVar21;
  int iVar22;
  vec128_t auVar19;
  vec128_t auVar20;
  int iVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;

  if (0 < (int)param_4) {
    uVar16 = 0;
    do {
      uVar2 = uVar16 + 1;
      auVar20 = ZEXT816(0);
      lVar12 = (long)*(ssc_i16_u *)(uintptr_t)((param_3 + uVar16 * 2));
      lVar11 = lVar12 << 3;
      pauVar13 = (undefined1 (*) [16])(uintptr_t)((param_2 + (long)param_5 * 4 + 0x10 + lVar12 * 0x20));
      lVar14 = (long)*(ssc_i16_u *)(uintptr_t)((param_3 + uVar2 * 2)) * 8;
      pauVar15 = pauVar13;
      lVar12 = lVar11;
      do {
        pauVar1 = pauVar15 + -1;
        pauVar6 = pauVar15 + -1;
        puVar7 = *pauVar15;
        puVar8 = *pauVar15;
        puVar9 = *pauVar15;
        puVar10 = *pauVar15;
        lVar12 = lVar12 + 8;
        pauVar15 = pauVar15 + 2;
        uVar24 = MP_INT_ABS((int)*(ssc_u64_u *)*pauVar1);
        uVar25 = MP_INT_ABS((int)((ulong)*(ssc_u64_u *)*pauVar1 >> 0x20));
        uVar26 = MP_INT_ABS((int)*(ssc_u64_u *)(*pauVar6 + 8));
        uVar27 = MP_INT_ABS((int)((ulong)*(ssc_u64_u *)(*pauVar6 + 8) >> 0x20));
        auVar19._4_4_ = uVar25;
        auVar19._0_4_ = uVar24;
        auVar19._8_4_ = uVar26;
        auVar19._12_4_ = uVar27;
        auVar19 = NEON_smax(auVar20,auVar19,4);
        uVar24 = MP_INT_ABS(*(ssc_u32_u *)puVar7);
        uVar25 = MP_INT_ABS(*(ssc_u32_u *)(puVar8 + 4));
        uVar26 = MP_INT_ABS(*(ssc_u32_u *)(puVar9 + 8));
        uVar27 = MP_INT_ABS(*(ssc_u32_u *)(puVar10 + 0xc));
        auVar20._4_4_ = uVar25;
        auVar20._0_4_ = uVar24;
        auVar20._8_4_ = uVar26;
        auVar20._12_4_ = uVar27;
        auVar20 = NEON_smax(auVar19,auVar20,4);
      } while (lVar12 < lVar14);
      uVar17 = NEON_smaxv(auVar20,4);
      if ((int)uVar17 < 1) {
        iVar18 = 1;
      }
      else {
        uVar3 = (int)LZCOUNT(uVar17) - 0x15;
        iVar18 = 0;
        iVar21 = 0;
        iVar22 = 0;
        iVar23 = 0;
        do {
          pauVar15 = pauVar13 + -1;
          auVar20 = *(vec128_t *)*pauVar13;
          lVar11 = lVar11 + 8;
          pauVar13 = pauVar13 + 2;
          auVar4._4_4_ = uVar3;
          auVar4._0_4_ = uVar3;
          auVar4._8_4_ = uVar3;
          auVar4._12_4_ = uVar3;
          auVar19 = NEON_sshl(*(vec128_t *)*pauVar15,auVar4,4);
          auVar5._4_4_ = uVar3;
          auVar5._0_4_ = uVar3;
          auVar5._8_4_ = uVar3;
          auVar5._12_4_ = uVar3;
          auVar20 = NEON_sshl(auVar20,auVar5,4);
          iVar18 = iVar18 + (int)auVar19._0_2_ * (int)auVar19._0_2_ +
                   (int)auVar20._0_2_ * (int)auVar20._0_2_;
          iVar21 = iVar21 + (int)auVar19._4_2_ * (int)auVar19._4_2_ +
                   (int)auVar20._4_2_ * (int)auVar20._4_2_;
          iVar22 = iVar22 + (int)auVar19._8_2_ * (int)auVar19._8_2_ +
                   (int)auVar20._8_2_ * (int)auVar20._8_2_;
          iVar23 = iVar23 + (int)auVar19._12_2_ * (int)auVar19._12_2_ +
                   (int)auVar20._12_2_ * (int)auVar20._12_2_;
        } while (lVar11 < lVar14);
        iVar18 = iVar18 + iVar21 + iVar22 + iVar23;
        if (uVar17 < 0x400) {
          iVar18 = ssc_sqrt(iVar18);
          iVar18 = iVar18 >> (uVar3 & 0x1f);
        }
        else {
          iVar18 = ssc_sqrt(iVar18);
          iVar18 = iVar18 << (ulong)(0x15U - (int)LZCOUNT(uVar17) & 0x1f);
        }
        iVar18 = iVar18 + 1;
      }
      *(ssc_i32_u *)(uintptr_t)((param_1 + (long)param_6 * 4 + uVar16 * 4)) = iVar18;
      uVar16 = uVar2;
    } while (uVar2 != param_4);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_compute_band_energies @ 0010776c */
/* ==================================================================== */

void ssc_compute_band_energies(long param_1, long param_2, long param_3, uint param_4) {
    int nbBands = (int)param_4;
    if (nbBands < 1) return;

    int nbEBands = *(ssc_i32_u *)(uintptr_t)((param_1 + 8));
    const ssc_i16_u *ebands = *(const ssc_i16_u **)(uintptr_t)((param_1 + 0x10));
    int stride = *(ssc_i32_u *)(uintptr_t)((param_1 + 0x1c));

    const ssc_i32_u *X = (const ssc_i32_u *)(uintptr_t)(param_2);
    ssc_i32_u *bandE = (ssc_i32_u *)(uintptr_t)(param_3);

    for (int ch = 0; ch < 2; ch++) {
        const ssc_i32_u *pX = X + (ch * stride * 8);
        ssc_i32_u *pE = bandE + (ch * nbEBands);

        for (int b = 0; b < nbBands; b++) {
            int start = (int)ebands[b] * 8;
            int end = (int)ebands[b + 1] * 8;
            int N = end - start;

            int32_t max_val = 0;
            for (int i = 0; i < N; i++) {
                int32_t a = abs(pX[start + i]);
                if (a > max_val) max_val = a;
            }

            if (max_val < 1) {
                pE[b] = 1;
                continue;
            }

            int clz = __builtin_clz(max_val);
            int shift = clz - 21;
            int64_t sum = 0;

            for (int i = 0; i < N; i++) {
                int32_t s = pX[start + i];
                int32_t shifted = (shift >= 0) ? (s << shift) : (s >> (-shift));
                int16_t s16 = (int16_t)shifted;
                sum += (int32_t)s16 * (int32_t)s16;
            }

            int32_t root = ssc_sqrt((int)sum);
            int32_t res;
            if (max_val <= 0x3ff) {
                res = (root >> shift) + 1;
            } else {
                res = (root << (21 - clz)) + 1;
            }
            pE[b] = res;
        }
    }
}


/* ==================================================================== */
/* Function: CalculateBandEnergyLastBand @ 001079b8 */
/* ==================================================================== */

void CalculateBandEnergyLastBand
               (long param_1,long param_2,long param_3,ulong param_4,uint param_5,int param_6,
               int param_7)

{
  ssc_u64_u *puVar1;
  undefined1 (*pauVar2) [16];
  long lVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  ssc_u64_u *puVar7;
  undefined8 uVar8;
  ssc_u64_u *puVar9;
  ssc_u32_u *puVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  ssc_i32_u *piVar14;
  long lVar15;
  ssc_u32_u *puVar16;
  ulong uVar17;
  ssc_u32_u *puVar18;
  undefined1 (*pauVar19) [16];
  ulong uVar20;
  ulong uVar21;
  ssc_u64_u *puVar22;
  ulong uVar23;
  long lVar24;
  ssc_i32_u *piVar25;
  uint uVar26;
  vec128_t auVar27;
  vec128_t auVar28;
  int iVar29;
  int iVar33;
  int iVar34;
  vec128_t auVar30;
  int iVar35;
  vec128_t auVar31;
  vec128_t auVar32;
  vec128_t auVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  vec128_t auVar41;
  vec128_t auVar42;
  vec128_t auVar43;
  vec128_t auVar44;
  vec128_t auVar45;

  if (0 < (int)param_5) {
    lVar24 = (long)param_6;
    uVar23 = 0;
    lVar3 = param_2 + lVar24 * 4;
    piVar25 = (ssc_i32_u *)(uintptr_t)((param_1 + (long)param_7 * 4));
    do {
      sVar5 = *(ssc_i16_u *)(uintptr_t)((param_3 + uVar23 * 2));
      auVar27 = ZEXT816(0);
      iVar11 = (int)param_4;
      uVar12 = sVar5 - iVar11;
      uVar26 = uVar12 + 3;
      if (-1 < (int)uVar12) {
        uVar26 = uVar12;
      }
      param_4 = param_4 & 0xffffffff;
      auVar31._0_4_ = (int)sVar5 + ((uVar26 & 0xfffffffc) - uVar12);
      if (iVar11 < auVar31._0_4_) {
        auVar27 = ZEXT816(0);
        param_4 = (ulong)iVar11;
        puVar16 = (ssc_u32_u *)(uintptr_t)((lVar3 + (long)iVar11 * 4));
        do {
          param_4 = param_4 + 4;
          auVar44._0_4_ = MP_INT_ABS(*puVar16);
          auVar44._4_4_ = MP_INT_ABS(puVar16[1]);
          auVar44._8_4_ = MP_INT_ABS(puVar16[2]);
          auVar44._12_4_ = MP_INT_ABS(puVar16[3]);
          auVar27 = NEON_smax(auVar27,auVar44,4);
          puVar16 = puVar16 + 4;
        } while ((long)param_4 < (long)auVar31._0_4_);
      }
      uVar26 = NEON_smaxv(auVar27,4);
      uVar12 = (uint)sVar5;
      if ((int)param_4 < (int)sVar5) {
        lVar15 = (long)(int)param_4;
        uVar17 = (int)uVar12 - lVar15;
        if (7 < uVar17) {
          auVar27._0_8_ = CONCAT44(uVar26,uVar26);
          auVar27._8_4_ = uVar26;
          auVar27._12_4_ = uVar26;
          lVar13 = lVar24 + lVar15;
          uVar20 = uVar17 & 0xfffffffffffffff8;
          auVar30._8_8_ = auVar27._8_8_;
          auVar30._0_8_ = auVar27._0_8_;
          lVar15 = uVar20 + lVar15;
          puVar22 = (ssc_u64_u *)(uintptr_t)((param_2 + 0x10 + lVar13 * 4));
          uVar21 = uVar20;
          do {
            puVar1 = puVar22 + -2;
            puVar16 = (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar22)) + -0xc));
            puVar9 = puVar22 + -1;
            puVar10 = (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar22)) + -4));
            puVar7 = puVar22 + 1;
            uVar8 = *puVar22;
            uVar21 = uVar21 - 8;
            puVar22 = puVar22 + 4;
            auVar45._0_4_ = MP_INT_ABS(*(ssc_u32_u *)puVar1);
            auVar45._4_4_ = MP_INT_ABS(*puVar16);
            auVar45._8_4_ = MP_INT_ABS(*(ssc_u32_u *)puVar9);
            auVar45._12_4_ = MP_INT_ABS(*puVar10);
            uVar37 = MP_INT_ABS((int)uVar8);
            uVar38 = MP_INT_ABS((int)((ulong)uVar8 >> 0x20));
            uVar39 = MP_INT_ABS((int)*puVar7);
            uVar40 = MP_INT_ABS((int)((ulong)*puVar7 >> 0x20));
            auVar27 = NEON_smax(auVar27,auVar45,4);
            auVar43._4_4_ = uVar38;
            auVar43._0_4_ = uVar37;
            auVar43._8_4_ = uVar39;
            auVar43._12_4_ = uVar40;
            auVar30 = NEON_smax(auVar30,auVar43,4);
          } while (uVar21 != 0);
          auVar27 = NEON_smax(auVar27,auVar30,4);
          uVar26 = NEON_smaxv(auVar27,4);
          if (uVar17 == uVar20) goto LAB_00107b3c;
        }
        lVar13 = (int)uVar12 - lVar15;
        puVar18 = (ssc_u32_u *)(uintptr_t)((param_2 + (lVar24 + lVar15) * 4));
        do {
          uVar4 = *puVar18;
          uVar6 = -uVar4;
          if (-1 < (int)uVar4) {
            uVar6 = uVar4;
          }
          if ((int)uVar26 <= (int)uVar6) {
            uVar26 = uVar6;
          }
          lVar13 = lVar13 + -1;
          puVar18 = puVar18 + 1;
        } while (lVar13 != 0);
      }
LAB_00107b3c:
      if ((int)uVar26 < 1) {
        iVar11 = 1;
        param_4 = (ulong)uVar12;
      }
      else {
        uVar6 = (int)LZCOUNT(uVar26) - 0x15;
        iVar29 = 0;
        iVar33 = 0;
        iVar34 = 0;
        iVar35 = 0;
        auVar28._4_4_ = uVar6;
        auVar28._0_4_ = uVar6;
        auVar28._8_4_ = uVar6;
        auVar28._12_4_ = uVar6;
        if (iVar11 < auVar31._0_4_) {
          iVar29 = 0;
          iVar33 = 0;
          iVar34 = 0;
          iVar35 = 0;
          lVar15 = (long)iVar11;
          pauVar19 = (undefined1 (*) [16])(uintptr_t)((lVar3 + (long)iVar11 * 4));
          do {
            lVar15 = lVar15 + 4;
            auVar27 = NEON_sshl(*(vec128_t *)*pauVar19,auVar28,4);
            iVar29 = iVar29 + (int)auVar27._0_2_ * (int)auVar27._0_2_;
            iVar33 = iVar33 + (int)auVar27._4_2_ * (int)auVar27._4_2_;
            iVar34 = iVar34 + (int)auVar27._8_2_ * (int)auVar27._8_2_;
            iVar35 = iVar35 + (int)auVar27._12_2_ * (int)auVar27._12_2_;
            pauVar19 = pauVar19 + 1;
          } while (lVar15 < auVar31._0_4_);
          iVar11 = (int)lVar15;
        }
        auVar31._0_4_ = iVar29 + iVar33 + iVar34 + iVar35;
        uVar4 = 0x15 - (int)LZCOUNT(uVar26);
        if (iVar11 < sVar5) {
          lVar15 = (long)iVar11;
          uVar17 = (int)uVar12 - lVar15;
          if (7 < uVar17) {
            lVar13 = lVar24 + lVar15;
            uVar20 = uVar17 & 0xfffffffffffffff8;
            lVar15 = uVar20 + lVar15;
            pauVar19 = (undefined1 (*) [16])(uintptr_t)((param_2 + 0x10 + lVar13 * 4));
            auVar31._4_12_ = SUB1612(ZEXT816(0),4);
            uVar21 = uVar20;
            auVar27 = ZEXT816(0);
            do {
              pauVar2 = pauVar19 + -1;
              auVar44 = *(vec128_t *)*pauVar19;
              uVar21 = uVar21 - 8;
              auVar42._0_4_ = -uVar4;
              auVar42._4_4_ = -uVar4;
              auVar42._8_4_ = -uVar4;
              auVar42._12_4_ = -uVar4;
              pauVar19 = pauVar19 + 2;
              auVar41._0_4_ = -(uint)(0x7ff < uVar26);
              auVar45 = NEON_ushl(*(vec128_t *)*pauVar2,auVar28,4);
              auVar43 = NEON_sshl(*(vec128_t *)*pauVar2,auVar42,4);
              auVar30 = NEON_sshl(auVar44,auVar42,4);
              auVar44 = NEON_ushl(auVar44,auVar28,4);
              auVar41._4_4_ = auVar41._0_4_;
              auVar41._8_4_ = auVar41._0_4_;
              auVar41._12_4_ = auVar41._0_4_;
              auVar43 = vec128_bif(auVar43, auVar45, auVar41);
              auVar44 = vec128_bit(auVar44, auVar44, auVar30, auVar41);
              auVar32._0_4_ = auVar31._0_4_ + (int)auVar43._0_2_ * (int)auVar43._0_2_;
              auVar32._4_4_ = auVar31._4_4_ + (int)auVar43._4_2_ * (int)auVar43._4_2_;
              auVar32._8_4_ = auVar31._8_4_ + (int)auVar43._8_2_ * (int)auVar43._8_2_;
              auVar32._12_4_ = auVar31._12_4_ + (int)auVar43._12_2_ * (int)auVar43._12_2_;
              auVar36._0_4_ = auVar27._0_4_ + (int)auVar44._0_2_ * (int)auVar44._0_2_;
              auVar36._4_4_ = auVar27._4_4_ + (int)auVar44._4_2_ * (int)auVar44._4_2_;
              auVar36._8_4_ = auVar27._8_4_ + (int)auVar44._8_2_ * (int)auVar44._8_2_;
              auVar36._12_4_ = auVar27._12_4_ + (int)auVar44._12_2_ * (int)auVar44._12_2_;
              auVar31 = auVar32;
              auVar27 = auVar36;
            } while (uVar21 != 0);
            auVar31._0_4_ =
                 auVar36._0_4_ + auVar32._0_4_ + auVar36._4_4_ + auVar32._4_4_ +
                 auVar36._8_4_ + auVar32._8_4_ + auVar36._12_4_ + auVar32._12_4_;
            if (uVar17 == uVar20) goto LAB_00107a14;
          }
          lVar13 = (int)uVar12 - lVar15;
          piVar14 = (ssc_i32_u *)(uintptr_t)((param_2 + (lVar24 + lVar15) * 4));
          do {
            sVar5 = (short)(*piVar14 >> (uVar4 & 0x1f));
            if (uVar26 < 0x800) {
              sVar5 = (short)(*piVar14 << (ulong)(uVar6 & 0x1f));
            }
            lVar13 = lVar13 + -1;
            auVar31._0_4_ = auVar31._0_4_ + (int)sVar5 * (int)sVar5;
            piVar14 = piVar14 + 1;
          } while (lVar13 != 0);
        }
LAB_00107a14:
        auVar31._0_4_ = ssc_sqrt(auVar31._0_4_);
        param_4 = (ulong)*(ssc_i16_u *)(uintptr_t)((param_3 + uVar23 * 2));
        iVar11 = auVar31._0_4_ >> (uVar6 & 0x1f);
        if (0x3ff < uVar26) {
          iVar11 = auVar31._0_4_ << (ulong)(uVar4 & 0x1f);
        }
        iVar11 = iVar11 + 1;
      }
      uVar23 = uVar23 + 1;
      *piVar25 = iVar11;
      piVar25 = piVar25 + 1;
    } while (uVar23 != param_5);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_compute_band_energies_for_lastband @ 00107cb4 */
/* ==================================================================== */

void ssc_compute_band_energies_for_lastband(long param_1, long param_2, ssc_i32_u *param_3, uint param_4, int param_5, uint param_6) {
    int nbBands = (int)param_4;
    if (nbBands < 1) return;

    int nbEBands = *(ssc_i32_u *)(uintptr_t)((param_1 + 8));
    const ssc_i16_u *ebands = *(const ssc_i16_u **)(uintptr_t)((param_1 + 0x10));
    int stride = *(ssc_i32_u *)(uintptr_t)((param_1 + 0x1c));

    const ssc_i16_u *table = (param_5 == 0) ? (const ssc_i16_u *)&DAT_001027f8 : (const ssc_i16_u *)((const char *)&DAT_00102840 + (int)param_6 * 0x10);

    int start_offset = (param_5 == 0) ? (nbEBands - 1) : (nbEBands + ~param_6);
    int init_start = (int)ebands[start_offset] * 8;

    const ssc_i32_u *X = (const ssc_i32_u *)(uintptr_t)(param_2);

    for (int ch = 0; ch < 2; ch++) {
        const ssc_i32_u *pX = X + (ch * stride * 8);
        ssc_i32_u *pE = param_3 + (ch * nbBands);
        int cur_start = init_start;

        for (int b = 0; b < nbBands; b++) {
            int end = (int)table[b];
            int N = end - cur_start;

            int32_t max_val = 0;
            for (int i = 0; i < N; i++) {
                int32_t a = abs(pX[cur_start + i]);
                if (a > max_val) max_val = a;
            }

            if (max_val < 1) {
                pE[b] = 1;
                cur_start = end;
                continue;
            }

            int clz = __builtin_clz(max_val);
            int shift = clz - 21;
            int64_t sum = 0;

            for (int i = 0; i < N; i++) {
                int32_t s = pX[cur_start + i];
                int32_t shifted = (shift >= 0) ? (s << shift) : (s >> (-shift));
                int16_t s16 = (int16_t)shifted;
                sum += (int32_t)s16 * (int32_t)s16;
            }

            int32_t root = ssc_sqrt((int)sum);
            int32_t res;
            if (max_val <= 0x3ff) {
                res = (root >> shift) + 1;
            } else {
                res = (root << (21 - clz)) + 1;
            }
            pE[b] = res;
            cur_start = end;
        }
    }
}

/* ==================================================================== */
/* Function: ssc_normalise_bands @ 001082a8 */
/* ==================================================================== */

void ssc_normalise_bands(long param_1,undefined1 (*param_2) [16],ssc_u64_u *param_3,ssc_u32_u *param_4,
                        int param_5)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  undefined1 (*pauVar4) [16];
  vec128_t auVar5;
  vec128_t auVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  ssc_u64_u *puVar10;
  undefined1 (*pauVar11) [16];
  ssc_u32_u *puVar12;
  ssc_u64_u *puVar13;
  int iVar14;
  ssc_i16_u *psVar15;
  ssc_i16_u *psVar16;
  int iVar17;
  vec128_t auVar18;
  vec128_t auVar19;
  vec128_t auVar20;
  vec128_t auVar21;

  psVar15 = *(ssc_i16_u **)(uintptr_t)((param_1 + 0x10));
  puVar10 = param_3;
  pauVar11 = param_2;
  psVar16 = psVar15;
  puVar12 = param_4;
  iVar17 = param_5;
  do {
    uVar2 = *puVar12;
    iVar14 = (int)LZCOUNT(uVar2);
    uVar1 = (int)uVar2 >> (0x12U - iVar14 & 0x1f);
    if (uVar2 >> 0xe == 0) {
      uVar1 = uVar2 << (ulong)(iVar14 - 0x12U & 0x1f);
    }
    sVar7 = ssc_rcp(-(uVar1 >> 0xf & 1) & 0xfff80000 | (uVar1 & 0xffff) << 3);
    sVar3 = *psVar16;
    psVar16 = psVar16 + 1;
    iVar9 = (int)sVar7;
    if (uVar2 >> 0xf == 0) {
      iVar14 = iVar14 + -0x11;
      iVar8 = *psVar16 * 8 + sVar3 * -8 + 8;
      puVar13 = puVar10;
      do {
        auVar21 = *(vec128_t *)*pauVar11;
        pauVar4 = pauVar11 + 1;
        pauVar11 = pauVar11 + 2;
        puVar10 = puVar13 + 2;
        iVar8 = iVar8 + -8;
        auVar19._4_4_ = iVar14;
        auVar19._0_4_ = iVar14;
        auVar19._8_4_ = iVar14;
        auVar19._12_4_ = iVar14;
        auVar19 = NEON_ushl(auVar21,auVar19,4);
        auVar21._4_4_ = iVar14;
        auVar21._0_4_ = iVar14;
        auVar21._8_4_ = iVar14;
        auVar21._12_4_ = iVar14;
        auVar21 = NEON_ushl(*(vec128_t *)*pauVar4,auVar21,4);
        *puVar13 = CONCAT26((short)((uint)(auVar19._12_2_ * iVar9) >> 0xf),
                            CONCAT24((short)((uint)(auVar19._8_2_ * iVar9) >> 0xf),
                                     CONCAT22((short)((uint)(auVar19._4_2_ * iVar9) >> 0xf),
                                              (short)((uint)(auVar19._0_2_ * iVar9) >> 0xf))));
        puVar13[1] = CONCAT26((short)((uint)(auVar21._12_2_ * iVar9) >> 0xf),
                              CONCAT24((short)((uint)(auVar21._8_2_ * iVar9) >> 0xf),
                                       CONCAT22((short)((uint)(auVar21._4_2_ * iVar9) >> 0xf),
                                                (short)((uint)(auVar21._0_2_ * iVar9) >> 0xf))));
        puVar13 = puVar10;
      } while (8 < iVar8);
    }
    else {
      iVar14 = 0x11 - iVar14;
      iVar8 = *psVar16 * 8 + sVar3 * -8 + 8;
      puVar13 = puVar10;
      do {
        auVar19 = *(vec128_t *)*pauVar11;
        pauVar4 = pauVar11 + 1;
        auVar18._0_4_ = -iVar14;
        auVar18._4_4_ = -iVar14;
        auVar18._8_4_ = -iVar14;
        auVar18._12_4_ = -iVar14;
        pauVar11 = pauVar11 + 2;
        puVar10 = puVar13 + 2;
        iVar8 = iVar8 + -8;
        auVar21 = NEON_sshl(auVar19,auVar18,4);
        auVar19 = NEON_sshl(*(vec128_t *)*pauVar4,auVar18,4);
        *puVar13 = CONCAT26((short)((uint)(auVar21._12_2_ * iVar9) >> 0xf),
                            CONCAT24((short)((uint)(auVar21._8_2_ * iVar9) >> 0xf),
                                     CONCAT22((short)((uint)(auVar21._4_2_ * iVar9) >> 0xf),
                                              (short)((uint)(auVar21._0_2_ * iVar9) >> 0xf))));
        puVar13[1] = CONCAT26((short)((uint)(auVar19._12_2_ * iVar9) >> 0xf),
                              CONCAT24((short)((uint)(auVar19._8_2_ * iVar9) >> 0xf),
                                       CONCAT22((short)((uint)(auVar19._4_2_ * iVar9) >> 0xf),
                                                (short)((uint)(auVar19._0_2_ * iVar9) >> 0xf))));
        puVar13 = puVar10;
      } while (8 < iVar8);
    }
    iVar17 = iVar17 + -1;
    puVar12 = puVar12 + 1;
  } while (iVar17 != 0);
  psVar15 = psVar15 + (((ulong)(param_5 - 1) + 1) - (long)param_5);
  param_2 = param_2 + 0xd8;
  param_3 = param_3 + 0xd8;
  puVar12 = param_4 + 0x16;
  do {
    uVar2 = *puVar12;
    iVar17 = (int)LZCOUNT(uVar2);
    uVar1 = (int)uVar2 >> (0x12U - iVar17 & 0x1f);
    if (uVar2 >> 0xe == 0) {
      uVar1 = uVar2 << (ulong)(iVar17 - 0x12U & 0x1f);
    }
    sVar7 = ssc_rcp(-(uVar1 >> 0xf & 1) & 0xfff80000 | (uVar1 & 0xffff) << 3);
    sVar3 = *psVar15;
    psVar15 = psVar15 + 1;
    iVar14 = (int)sVar7;
    if (uVar2 >> 0xf == 0) {
      iVar17 = iVar17 + -0x11;
      iVar9 = *psVar15 * 8 + sVar3 * -8 + 8;
      puVar10 = param_3;
      do {
        auVar19 = *(vec128_t *)*param_2;
        pauVar11 = param_2 + 1;
        param_2 = param_2 + 2;
        param_3 = puVar10 + 2;
        iVar9 = iVar9 + -8;
        auVar5._4_4_ = iVar17;
        auVar5._0_4_ = iVar17;
        auVar5._8_4_ = iVar17;
        auVar5._12_4_ = iVar17;
        auVar19 = NEON_ushl(auVar19,auVar5,4);
        auVar6._4_4_ = iVar17;
        auVar6._0_4_ = iVar17;
        auVar6._8_4_ = iVar17;
        auVar6._12_4_ = iVar17;
        auVar21 = NEON_ushl(*(vec128_t *)*pauVar11,auVar6,4);
        *puVar10 = CONCAT26((short)((uint)(auVar19._12_2_ * iVar14) >> 0xf),
                            CONCAT24((short)((uint)(auVar19._8_2_ * iVar14) >> 0xf),
                                     CONCAT22((short)((uint)(auVar19._4_2_ * iVar14) >> 0xf),
                                              (short)((uint)(auVar19._0_2_ * iVar14) >> 0xf))));
        puVar10[1] = CONCAT26((short)((uint)(auVar21._12_2_ * iVar14) >> 0xf),
                              CONCAT24((short)((uint)(auVar21._8_2_ * iVar14) >> 0xf),
                                       CONCAT22((short)((uint)(auVar21._4_2_ * iVar14) >> 0xf),
                                                (short)((uint)(auVar21._0_2_ * iVar14) >> 0xf))));
        puVar10 = param_3;
      } while (8 < iVar9);
    }
    else {
      iVar17 = 0x11 - iVar17;
      iVar9 = *psVar15 * 8 + sVar3 * -8 + 8;
      puVar10 = param_3;
      do {
        auVar19 = *(vec128_t *)*param_2;
        pauVar11 = param_2 + 1;
        auVar20._0_4_ = -iVar17;
        auVar20._4_4_ = -iVar17;
        auVar20._8_4_ = -iVar17;
        auVar20._12_4_ = -iVar17;
        param_2 = param_2 + 2;
        param_3 = puVar10 + 2;
        iVar9 = iVar9 + -8;
        auVar21 = NEON_sshl(auVar19,auVar20,4);
        auVar19 = NEON_sshl(*(vec128_t *)*pauVar11,auVar20,4);
        *puVar10 = CONCAT26((short)((uint)(auVar21._12_2_ * iVar14) >> 0xf),
                            CONCAT24((short)((uint)(auVar21._8_2_ * iVar14) >> 0xf),
                                     CONCAT22((short)((uint)(auVar21._4_2_ * iVar14) >> 0xf),
                                              (short)((uint)(auVar21._0_2_ * iVar14) >> 0xf))));
        puVar10[1] = CONCAT26((short)((uint)(auVar19._12_2_ * iVar14) >> 0xf),
                              CONCAT24((short)((uint)(auVar19._8_2_ * iVar14) >> 0xf),
                                       CONCAT22((short)((uint)(auVar19._4_2_ * iVar14) >> 0xf),
                                                (short)((uint)(auVar19._0_2_ * iVar14) >> 0xf))));
        puVar10 = param_3;
      } while (8 < iVar9);
    }
    param_5 = param_5 + -1;
    puVar12 = puVar12 + 1;
  } while (param_5 != 0);
  return;
}


/* ==================================================================== */
/* Function: ssc_spreading_decision @ 001085ac */
/* ==================================================================== */

undefined1 ssc_spreading_decision(ssc_i64_u *param_1,long param_2,int param_3,uint param_4)

{
  ulong uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  long lVar16;
  ulong uVar17;
  int iVar18;
  int iVar19;
  ssc_i16_u *psVar20;
  ulong uVar21;

  if ((int)param_4 < 9) {
    iVar13 = 0;
    iVar14 = 0;
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    iVar14 = 0;
    iVar13 = 0;
    lVar16 = *(ssc_i64_u *)(uintptr_t)((*param_1 + 0x10));
    uVar17 = 8;
    uVar6 = *(ssc_u16_u *)(uintptr_t)((lVar16 + 0x10));
    do {
      uVar1 = uVar17 + 1;
      uVar2 = *(ssc_u16_u *)(uintptr_t)((lVar16 + uVar1 * 2));
      iVar18 = (int)(short)uVar2 - (int)(short)uVar6;
      if (1 < iVar18) {
        uVar3 = iVar18 * 8;
        iVar18 = 0;
        iVar8 = 0;
        iVar9 = 0;
        iVar10 = 0;
        iVar19 = 0;
        iVar11 = 0;
        psVar20 = (ssc_i16_u *)(uintptr_t)((param_2 +
                           (long)(int)(-(uint)(uVar6 >> 0xf) & 0xfff80000 | (uint)uVar6 << 3) * 2));
        uVar15 = uVar3;
        if ((int)uVar3 < 2) {
          uVar15 = 1;
        }
        uVar21 = (ulong)uVar15;
        do {
          uVar15 = ((uint)((int)*psVar20 * (int)*psVar20) >> 0xf) * uVar3;
          if ((int)uVar15 < 0x80) {
            iVar19 = iVar19 + 2;
            iVar10 = iVar10 + 2;
            iVar4 = iVar11 + 2;
          }
          else if (uVar15 < 0x200) {
            iVar19 = iVar19 + 2;
            iVar4 = iVar11 + 2;
          }
          else {
            iVar4 = iVar11 + 2;
            if (0x7ff < uVar15) {
              iVar4 = iVar11;
            }
          }
          iVar11 = iVar4;
          uVar15 = ((uint)((int)psVar20[0x360] * (int)psVar20[0x360]) >> 0xf) * uVar3;
          if ((int)uVar15 < 0x80) {
            iVar8 = iVar8 + 2;
            iVar18 = iVar18 + 2;
            iVar4 = iVar9 + 2;
          }
          else if (uVar15 < 0x200) {
            iVar8 = iVar8 + 2;
            iVar4 = iVar9 + 2;
          }
          else {
            iVar4 = iVar9 + 2;
            if (0x7ff < uVar15) {
              iVar4 = iVar9;
            }
          }
          iVar9 = iVar4;
          psVar20 = psVar20 + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
        if ((long)*(ssc_i32_u *)(uintptr_t)((*param_1 + 8)) + -4 < (long)uVar17) {
          iVar4 = 0;
          if (uVar3 != 0) {
            iVar4 = ((iVar19 + iVar11) * 0x20) / (int)uVar3;
          }
          iVar5 = 0;
          if (uVar3 != 0) {
            iVar5 = ((iVar8 + iVar9) * 0x20) / (int)uVar3;
          }
          iVar13 = iVar4 + iVar13 + iVar5;
        }
        iVar14 = iVar14 + 2;
        uVar15 = (uint)((int)uVar3 <= iVar19);
        if ((int)uVar3 <= iVar11) {
          uVar15 = uVar15 + 1;
        }
        if ((int)uVar3 <= iVar10) {
          uVar15 = uVar15 + 1;
        }
        if ((int)uVar3 <= iVar9) {
          uVar15 = uVar15 + 1;
        }
        if ((int)uVar3 <= iVar8) {
          uVar15 = uVar15 + 1;
        }
        if ((int)uVar3 <= iVar18) {
          uVar15 = uVar15 + 1;
        }
        iVar12 = iVar12 + uVar15 * 0x100;
      }
      uVar17 = uVar1;
      uVar6 = uVar2;
    } while (uVar1 != param_4);
  }
  if (param_3 != 0) {
    iVar13 = (int)param_1[6] + (iVar13 >> 3) >> 1;
    *(ssc_i32_u *)(param_1 + 6) = iVar13;
    if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x34)) == 0) {
      iVar13 = iVar13 + -4;
    }
    else if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x34)) == 2) {
      iVar13 = iVar13 + 4;
    }
    uVar15 = 2;
    if (iVar13 < 0x17) {
      uVar15 = (uint)(0x12 < iVar13);
    }
    *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x34)) = uVar15;
  }
  iVar13 = iVar12;
  if ((1 < iVar14) && (iVar13 = 0, iVar14 != 0)) {
    iVar13 = iVar12 / iVar14;
  }
  uVar15 = (int)param_1[5] + iVar13;
  iVar14 = (int)uVar15 >> 1;
  uVar15 = (uVar15 & 0xfffffffe) + iVar14 + (int)param_1[4] * -0x80 + 0x1c0;
  *(ssc_i32_u *)(param_1 + 5) = iVar14;
  if ((int)uVar15 < 0x13e) {
    uVar7 = 3;
  }
  else if (uVar15 < 0x3fe) {
    uVar7 = 2;
  }
  else {
    uVar7 = uVar15 < 0x5fe;
  }
  return uVar7;
}


/* ==================================================================== */
/* Function: ssc_haar1 @ 001087fc */
/* ==================================================================== */

void ssc_haar1(ssc_i16_u *param_1,int param_2,uint param_3)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  ulong uVar4;
  ssc_i16_u *psVar5;
  ulong uVar6;
  ssc_i16_u *psVar7;
  ssc_i16_u *psVar8;

  if (0 < (int)param_3) {
    uVar1 = param_2 >> 1;
    uVar4 = 0;
    if ((int)uVar1 < 2) {
      uVar1 = 1;
    }
    psVar5 = param_1 + param_3;
    do {
      uVar6 = (ulong)uVar1;
      psVar7 = psVar5;
      psVar8 = param_1;
      if (1 < param_2) {
        do {
          uVar6 = uVar6 - 1;
          sVar2 = (short)((uint)(*psVar7 * 0xb504) >> 0x10);
          sVar3 = (short)((uint)(*psVar8 * 0xb504) >> 0x10);
          *psVar8 = sVar2 + sVar3;
          *psVar7 = sVar3 - sVar2;
          psVar7 = psVar7 + (ulong)param_3 * 2;
          psVar8 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar8)) +
                            (-(ulong)((param_3 & 0x7fffffff) >> 0x1e) & 0xfffffffe00000000 |
                            (ulong)(param_3 << 1) << 1)));
        } while (uVar6 != 0);
      }
      uVar4 = uVar4 + 1;
      param_1 = param_1 + 1;
      psVar5 = psVar5 + 1;
    } while (uVar4 != param_3);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_quant_all_bands @ 00108898 */
/* ==================================================================== */

void ssc_quant_all_bands(long param_1,uint param_2,long param_3,long param_4,undefined8 param_5,
                        long param_6,int param_7,undefined4 param_8,int param_9,uint param_10,
                        long param_11,int param_12,int param_13,undefined8 param_14,int param_15,
                        ssc_u32_u *param_16)

{
  long lVar1;
  ulong uVar2;
  ssc_u64_u *puVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  short sVar21;
  short sVar22;
  int iVar23;
  undefined8 uVar24;
  byte bVar25;
  byte bVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  ulong uVar30;
  long lVar31;
  ulong uVar32;
  long lVar33;
  int iVar34;
  long lVar35;
  ssc_u64_u *puVar36;
  ssc_i16_u *psVar37;
  uint uVar38;
  long lVar39;
  ulong uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  ulong uVar44;
  ulong uVar45;
  int iVar46;
  undefined8 uVar47;
  int iVar48;
  int iVar49;
  undefined8 uVar50;
  undefined8 uVar51;
  short sVar52;
  ushort uVar53;
  ushort uVar54;
  ushort uVar55;
  int local_cc;
  long local_c8;
  uint8_t quant_bands_buf[0x40] __attribute__((aligned(8)));
#define local_b8 ((ssc_u32_u *)(quant_bands_buf + 0x00))
#define local_b0 (*(ssc_i64_u *)(quant_bands_buf + 0x08))
#define local_a8 (*(ssc_i32_u *)(quant_bands_buf + 0x10))
#define local_a4 (*(ssc_u32_u *)(quant_bands_buf + 0x14))
#define uStack_a0 (*(ssc_u32_u *)(quant_bands_buf + 0x18))
#define local_9c (*(ssc_u32_u *)(quant_bands_buf + 0x1c))
#define local_98 (*(ssc_u64_u *)(quant_bands_buf + 0x20))
#define local_90 (*(ssc_i32_u *)(quant_bands_buf + 0x28))
#define local_88 (*(ssc_u64_u *)(quant_bands_buf + 0x30))
#define local_80 (*(ssc_u32_u *)(quant_bands_buf + 0x38))
  int local_78;
  int iStack_74;
  long local_70;

  lVar12 = tpidr_el0;
  local_70 = *(ssc_i64_u *)(uintptr_t)((lVar12 + 0x28));
  lVar39 = *(ssc_i64_u *)(uintptr_t)((param_1 + 0x10));
  local_b8[0] = 1;
  local_80 = *param_16;
  local_98 = param_14;
  uVar38 = 8;
  if (param_7 == 0) {
    uVar38 = 1;
  }
  local_a4 = param_10;
  local_b0 = param_1;
  uStack_a0 = param_8;
  local_88 = param_5;
  if (0 < (int)param_2) {
    local_cc = param_9;
    lVar1 = param_3 + 0x6c0;
    uVar10 = ~(-1 << (ulong)uVar38);
    uVar45 = 0;
    local_c8 = lVar1 + (long)*(ssc_i16_u *)(uintptr_t)((lVar39 + (long)*(ssc_i32_u *)(uintptr_t)((param_1 + 8)) * 2)) * 0x10;
    do {
      uVar2 = uVar45 + 1;
      sVar8 = *(ssc_i16_u *)(uintptr_t)((lVar39 + uVar45 * 2));
      uVar44 = (ulong)sVar8;
      iVar49 = (int)*(ssc_i16_u *)(uintptr_t)((lVar39 + uVar2 * 2));
      iVar46 = iVar49 - sVar8;
      local_a8 = (int)uVar45;
      static int _f_cnt = 0;;
      iVar27 = ssc_ec_tell_frac(param_14);
      uVar13 = local_88;
      uVar24 = local_98;
      uVar5 = local_a4;
      iVar48 = local_a8;
      lVar31 = local_b0;
      iVar6 = 0;
      if (uVar45 != 0) {
        iVar6 = iVar27;
      }
      uVar11 = param_12 - iVar27;
      uVar41 = 0;
      local_90 = uVar11 - 1;
      if ((long)uVar45 < (long)param_15) {
        lVar35 = (long)param_15 - uVar45;
        iVar34 = (int)lVar35;
        if (2 < lVar35) {
          iVar34 = 3;
        }
        iVar28 = 0;
        if (iVar34 != 0) {
          iVar28 = (param_13 - iVar6) / iVar34;
        }
        uVar41 = *(ssc_i32_u *)(uintptr_t)((param_6 + uVar45 * 4)) + iVar28;
        if ((int)uVar41 <= (int)uVar11) {
          uVar11 = uVar41;
        }
        if ((int)uVar11 < 0x4000) {
          uVar41 = uVar11 & ((int)uVar11 >> 0x1f ^ 0xffffffffU);
        }
        else {
          uVar41 = 0x3fff;
        }
      }
      lVar35 = 0;
      if (uVar45 != param_2 - 1) {
        lVar35 = local_c8;
      }
      local_9c = *(ssc_u32_u *)(uintptr_t)((param_11 + uVar45 * 4));
      uVar30 = -(uVar44 >> 0x1f & 1) & 0xfffffff000000000 | (uVar44 & 0xffffffff) << 4;
      puVar3 = (ssc_u64_u *)(uintptr_t)((param_3 + uVar30));
      lVar4 = lVar1 + uVar30;
      uVar11 = iVar46 * 8;
      uVar30 = (ulong)uVar11;
      iVar34 = 0;
      if (uVar45 != param_10 && local_cc != 0) {
        iVar34 = local_cc;
      }
      if (iVar34 == 0) {
        iVar29 = iVar46 * 0x10 + -1;
        iVar28 = *(ssc_i16_u *)(uintptr_t)((*(ssc_i64_u *)(uintptr_t)((local_b0 + 0x38)) + (long)local_a8 * 2)) + 0x18;
        uVar43 = (uVar41 - iVar28) - 0x20;
        uVar42 = 0;
        if (iVar29 != 0) {
          uVar42 = (int)(uVar41 + ((iVar28 >> 1) + -4) * iVar29) / iVar29;
        }
        if ((int)uVar42 <= (int)uVar43) {
          uVar43 = uVar42;
        }
        if (0x3f < (int)uVar43) {
          uVar43 = 0x40;
        }
        if ((int)uVar43 < 4) {
          uVar43 = 1;
        }
        else {
          uVar43 = ((int)((ssc_i16_u *)(&DAT_00102760))[uVar43 & 7] >> (0xe - (uVar43 >> 3) & 0x1f)) + 1U &
                   0xfffffffe;
        }
        uVar40 = (uVar44 & 0xffffffff) << 3;
        uVar44 = -(uVar44 >> 0x1f & 1) & 0xfffffff800000000 | uVar40;
        iVar28 = ssc_stereo_itheta((int64_t)(uintptr_t)(puVar3),lVar4,uVar30);
        iVar29 = ssc_ec_tell_frac(uVar24);
        uVar42 = uVar10;
        if ((iVar48 < (int)uVar5) && (uVar43 != 1)) {
          uVar9 = iVar28 * uVar43 + 0x2000;
          uVar5 = (int)uVar43 >> 1;
          iVar28 = (int)uVar9 >> 0xe;
          iVar46 = (uVar43 & 0xfffffffe) + uVar5 + 3;
          iVar7 = (iVar46 - uVar5) + iVar28;
          iVar23 = iVar46 + ~uVar5 + iVar28;
          if (iVar28 <= (int)uVar5) {
            iVar7 = iVar28 * 3 + 3;
            iVar23 = iVar28 * 3;
          }
          ssc_ec_encode(uVar24,iVar23,iVar7,iVar46 + uVar5);
          iVar46 = 0;
          if (uVar43 != 0) {
            iVar46 = (int)(uVar9 & 0xffffc000) / (int)uVar43;
          }
          if (iVar46 == 0) {
            FUN_00109ca4(lVar31,puVar3,(ssc_u64_u *)(uintptr_t)(lVar4),uVar13,iVar48,uVar30);
            goto LAB_00108e0c;
          }
          lVar31 = (ulong)((iVar49 * 8 - (int)uVar40) - 8) + 8;
          {
            ssc_i16_u *ch0_ptr = (ssc_i16_u *)puVar3;
            ssc_i16_u *ch1_ptr = ch0_ptr + 864;
            for (uint32_t i_rot = 0; i_rot < (uint32_t)lVar31; i_rot++) {
              int32_t L_rot = ((int32_t)ch0_ptr[i_rot] * 0xb504) >> 16;
              int32_t R_rot = ((int32_t)ch1_ptr[i_rot] * 0xb504) >> 16;
              ch0_ptr[i_rot] = (int16_t)(R_rot + L_rot);
              ch1_ptr[i_rot] = (int16_t)(R_rot - L_rot);
            }
          }
          iVar48 = ssc_ec_tell_frac(uVar24);
          if (iVar46 == 0) goto LAB_00108e20;
          if (iVar46 == 0x4000) {
            iVar49 = 0x4000;
            uVar42 = uVar10 << (ulong)uVar38 & (-1 << (ulong)uVar38 ^ 0xffffffffU);
            iVar28 = 0x7fff;
          }
          else {
            ssc_bitexact_cos_asm(iVar46,0x4000 - iVar46,(ssc_i32_u *)&iStack_74,(ssc_i32_u *)&local_78);
            uVar5 = (int)LZCOUNT(local_78) - 0x11;
            uVar43 = (int)LZCOUNT(iStack_74) - 0x11;
            iVar49 = (int)(short)(local_78 << (ulong)(uVar5 & 0x1f));
            iVar28 = (int)(short)(iStack_74 << (ulong)(uVar43 & 0x1f));
            iVar49 = (int)(short)(((short)(((iVar49 * -0xa25 + 0x4000 >> 0xf) + 0x1efc) * iVar49 +
                                           0x4000U >> 0xf) + ((short)uVar43 - (short)uVar5) * 0x800)
                                 - (short)(((iVar28 * -0xa25 + 0x4000 >> 0xf) + 0x1efc) * iVar28 +
                                           0x4000U >> 0xf)) *
                     (int)(short)((short)uVar11 * 0x80 + -0x80) + 0x4000 >> 0xf;
            iVar28 = local_78;
          }
        }
        else {
          if ((0 < iVar46) && (0x2000 < iVar28)) {
            if (uVar11 < 0x10) {
              uVar32 = 0;
            }
            else {
              uVar32 = uVar30 & 0xfffffff0;
              puVar36 = (ssc_u64_u *)(uintptr_t)((param_3 + 0x6d0 + uVar44 * 2));
              uVar40 = uVar32;
              do {
                uVar51 = puVar36[-1];
                uVar50 = puVar36[-2];
                uVar47 = puVar36[1];
                uVar14 = *puVar36;
                uVar40 = uVar40 - 0x10;
                puVar36[-1] = CONCAT26(-(short)((ulong)uVar51 >> 0x30),
                                       CONCAT24(-(short)((ulong)uVar51 >> 0x20),
                                                CONCAT22(-(short)((ulong)uVar51 >> 0x10),
                                                         -(short)uVar51)));
                puVar36[-2] = CONCAT26(-(short)((ulong)uVar50 >> 0x30),
                                       CONCAT24(-(short)((ulong)uVar50 >> 0x20),
                                                CONCAT22(-(short)((ulong)uVar50 >> 0x10),
                                                         -(short)uVar50)));
                puVar36[1] = CONCAT26(-(short)((ulong)uVar47 >> 0x30),
                                      CONCAT24(-(short)((ulong)uVar47 >> 0x20),
                                               CONCAT22(-(short)((ulong)uVar47 >> 0x10),
                                                        -(short)uVar47)));
                *puVar36 = CONCAT26(-(short)((ulong)uVar14 >> 0x30),
                                    CONCAT24(-(short)((ulong)uVar14 >> 0x20),
                                             CONCAT22(-(short)((ulong)uVar14 >> 0x10),-(short)uVar14
                                                     )));
                puVar36 = puVar36 + 4;
              } while (uVar40 != 0);
              if (uVar32 == uVar30) goto LAB_00108dd0;
            }
            lVar33 = uVar30 - uVar32;
            psVar37 = (ssc_i16_u *)(uintptr_t)((lVar1 + (uVar32 + uVar44) * 2));
            do {
              lVar33 = lVar33 + -1;
              *psVar37 = -*psVar37;
              psVar37 = psVar37 + 1;
            } while (lVar33 != 0);
          }
LAB_00108dd0:
          FUN_00109ca4(lVar31,puVar3,(ssc_u64_u *)(uintptr_t)(lVar4),uVar13,iVar48,uVar30);
          if ((0x10 < uVar41) && (0x10 < local_90)) {
            ssc_ec_enc_bit_logp(uVar24,0x2000 < iVar28,2);
          }
LAB_00108e0c:
          iVar48 = ssc_ec_tell_frac(uVar24);
          iVar46 = 0;
LAB_00108e20:
          iVar28 = 0;
          iVar49 = -0x4000;
        }
        uVar41 = uVar41 - (iVar48 - iVar29);
        iVar48 = local_90 - (iVar48 - iVar29);
        iVar49 = uVar41 - iVar49;
        if (iVar49 < 0) {
          iVar49 = iVar49 + 1;
        }
        uVar5 = uVar41;
        if (iVar49 >> 1 <= (int)uVar41) {
          uVar5 = iVar49 >> 1;
        }
        uVar5 = uVar5 & ((int)uVar5 >> 0x1f ^ 0xffffffffU);
        iVar49 = uVar41 - uVar5;
        local_90 = iVar48;
        if ((int)uVar5 < iVar49) {
          bVar26 = FUN_00109038((int64_t)(uintptr_t)(local_b8),(ssc_i16_u *)(uintptr_t)(lVar4),uVar30,iVar49,uVar38,iVar28,0,uVar42 >> (ulong)uVar38
                               );
          iVar49 = (local_90 - iVar48) + iVar49;
          iVar48 = iVar49 + -0x18;
          if (iVar46 == 0x4000 || iVar49 < 0x19) {
            iVar48 = 0;
          }
          bVar25 = FUN_00109038((int64_t)(uintptr_t)(local_b8),(ssc_i16_u *)(puVar3),uVar30,iVar48 + uVar5,uVar38,0x7fff,lVar35,uVar42);
          bVar25 = bVar25 | bVar26;
          bVar26 = bVar25;
        }
        else {
          bVar26 = FUN_00109038((int64_t)(uintptr_t)(local_b8),(ssc_i16_u *)(puVar3),uVar30,uVar5,uVar38,0x7fff,lVar35,uVar42);
          iVar48 = (local_90 - iVar48) + uVar5;
          iVar29 = iVar48 + -0x18;
          if (iVar46 == 0 || iVar48 < 0x19) {
            iVar29 = 0;
          }
          bVar25 = FUN_00109038((int64_t)(uintptr_t)(local_b8),(ssc_i16_u *)(uintptr_t)(lVar4),uVar30,iVar29 + iVar49,uVar38,iVar28,0,
                                uVar42 >> (ulong)uVar38);
          bVar25 = bVar25 | bVar26;
          bVar26 = bVar25;
        }
      }
      else {
        bVar25 = FUN_00109038((int64_t)(uintptr_t)(local_b8),(ssc_i16_u *)(puVar3),uVar30,uVar41 >> 1,uVar38,0x7fff,lVar35,uVar10);
        bVar26 = FUN_00109038((int64_t)(uintptr_t)(local_b8),(ssc_i16_u *)(uintptr_t)(lVar4),uVar30,uVar41 >> 1,uVar38,0x7fff,lVar35,uVar10);
      }
      *(byte *)(uintptr_t)((param_4 + (-(uVar45 >> 0x1e & 1) & 0xffffffff00000000 | (uVar45 & 0x7fffffff) << 1)))
           = bVar25;
      *(byte *)(uintptr_t)((param_4 + ((int)uVar45 << 1) + 1)) = bVar26;
      param_13 = (param_13 - iVar6) + iVar27 + *(ssc_i32_u *)(uintptr_t)((param_6 + uVar45 * 4));
      uVar45 = uVar2;
      local_cc = iVar34;
      local_c8 = lVar35;
    } while (uVar2 != param_2);
  }
  *param_16 = local_80;
  if (*(ssc_i64_u *)(uintptr_t)((lVar12 + 0x28)) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* ==================================================================== */
#undef local_b8
#undef local_b0
#undef local_a8
#undef local_a4
#undef uStack_a0
#undef local_9c
#undef local_98
#undef local_90
#undef local_88
#undef local_80

/* Function: FUN_00109038 @ 00109038 */
/* ==================================================================== */

ulong FUN_00109038(long param_1,ssc_i16_u *param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,undefined8 param_7,ulong param_8)

{
  bool bVar1;
  ssc_u16_u *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  long lVar9;
  ssc_i16_u *psVar10;
  long lVar11;
  ssc_i16_u *psVar12;
  long lVar13;
  ulong uVar14;
  ssc_i16_u *psVar15;
  ssc_u16_u *puVar16;
  uint uVar17;
  uint uVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  ulong uVar22;
  long lVar23;
  ulong uVar24;
  ulong uVar25;
  ssc_i16_u *psVar26;
  uint uVar27;
  undefined2 auStack_190 [144];
  long local_70;

  lVar9 = tpidr_el0;
  iVar8 = 0;
  if (param_5 != 0) {
    iVar8 = param_3 / param_5;
  }
  local_70 = *(ssc_i64_u *)(uintptr_t)((lVar9 + 0x28));
  param_8 = param_8 & 0xffffffff;
  uVar17 = *(ssc_u32_u *)(uintptr_t)((param_1 + 0x1c));
  uVar4 = uVar17 & ((int)uVar17 >> 0x1f ^ 0xffffffffU);
  if (0 < (int)uVar17) {
    uVar20 = 0;
    do {
      if (uVar20 != 0x1f) {
        iVar3 = param_3 >> (uVar20 & 0x1f);
        uVar21 = 1 << (ulong)(uVar20 & 0x1f);
        uVar18 = iVar3 >> 1;
        uVar25 = 0;
        psVar10 = param_2 + uVar21;
        if ((int)uVar18 < 2) {
          uVar18 = 1;
        }
        psVar26 = param_2;
        do {
          psVar12 = psVar26;
          psVar15 = psVar10;
          uVar19 = (ulong)uVar18;
          if (1 < iVar3) {
            do {
              uVar19 = uVar19 - 1;
              sVar6 = (short)((uint)(*psVar15 * 0xb504) >> 0x10);
              sVar7 = (short)((uint)(*psVar12 * 0xb504) >> 0x10);
              *psVar12 = sVar6 + sVar7;
              *psVar15 = sVar7 - sVar6;
              psVar12 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar12)) +
                                 (-(ulong)((uVar21 & 0x7fffffff) >> 0x1e) & 0xfffffffe00000000 |
                                 (ulong)(uVar21 << 1) << 1)));
              psVar15 = psVar15 + (ulong)uVar21 * 2;
            } while (uVar19 != 0);
          }
          uVar25 = uVar25 + 1;
          psVar10 = psVar10 + 1;
          psVar26 = psVar26 + 1;
        } while (uVar25 != uVar21);
      }
      uVar20 = uVar20 + 1;
      param_8 = (ulong)((uint)((uint8_t *)(&DAT_001027c0))[param_8 & 0xf] |
                       (uint)((uint8_t *)(&DAT_001027c0))[(int)param_8 >> 4] << 2);
    } while (uVar20 != uVar4);
  }
  uVar21 = iVar8 << (ulong)(uVar4 & 0x1f);
  uVar20 = param_5 >> (uVar4 & 0x1f);
  uVar18 = uVar21;
  uVar27 = uVar20;
  if (((uVar21 & 1) == 0) && ((int)uVar17 < 0)) {
    do {
      uVar27 = uVar20 << 1;
      uVar18 = (int)uVar21 >> 1;
      if (0 < (int)uVar20) {
        uVar25 = 0;
        uVar5 = uVar18;
        if ((int)uVar18 < 2) {
          uVar5 = 1;
        }
        psVar10 = param_2 + uVar20;
        psVar26 = param_2;
        do {
          psVar12 = psVar26;
          psVar15 = psVar10;
          uVar19 = (ulong)uVar5;
          if (1 < (int)uVar21) {
            do {
              uVar19 = uVar19 - 1;
              sVar6 = (short)((uint)(*psVar15 * 0xb504) >> 0x10);
              sVar7 = (short)((uint)(*psVar12 * 0xb504) >> 0x10);
              *psVar12 = sVar6 + sVar7;
              *psVar15 = sVar7 - sVar6;
              psVar12 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar12)) +
                                 (-(ulong)((uVar20 & 0x7fffffff) >> 0x1e) & 0xfffffffe00000000 |
                                 (ulong)uVar27 << 1)));
              psVar15 = psVar15 + (ulong)uVar20 * 2;
            } while (uVar19 != 0);
          }
          uVar25 = uVar25 + 1;
          psVar10 = psVar10 + 1;
          psVar26 = psVar26 + 1;
        } while (uVar25 != uVar20);
      }
      param_8 = (ulong)((uint)param_8 << (ulong)(uVar20 & 0x1f) | (uint)param_8);
    } while (((uVar21 >> 1 & 1) == 0) &&
            (bVar1 = (int)uVar17 < -1, uVar17 = uVar17 + 1, uVar21 = uVar18, uVar20 = uVar27, bVar1)
            );
  }
  if (1 < (int)uVar27) {
    uVar18 = (int)uVar18 >> (uVar4 & 0x1f);
    uVar25 = (ulong)uVar18;
    uVar4 = uVar27 << (ulong)(uVar4 & 0x1f);
    uVar19 = (ulong)uVar4;
    if (param_5 == 1) {
      if (0 < (int)uVar4) {
        lVar23 = (long)(int)uVar4;
        uVar22 = 0;
        uVar24 = uVar25 & 0xfffffffe;
        psVar10 = param_2;
        do {
          if (0 < (int)uVar18) {
            iVar8 = *(ssc_i32_u *)(&DAT_00102878 + uVar22 * 4 + (long)(int)uVar4 * 4);
            if (uVar18 == 1) {
              uVar14 = 0;
            }
            else {
              psVar12 = (ssc_i16_u *)(uintptr_t)((((ulong)(uintptr_t)(uintptr_t)((auStack_190)) | 2) + (long)iVar8 * (long)(int)uVar18 * 2));
              uVar14 = uVar24;
              psVar26 = psVar10;
              do {
                sVar7 = psVar26[lVar23];
                uVar14 = uVar14 - 2;
                sVar6 = *psVar26;
                psVar26 = psVar26 + lVar23 * 2;
                psVar12[-1] = sVar6;
                *psVar12 = sVar7;
                psVar12 = psVar12 + 2;
              } while (uVar14 != 0);
              uVar14 = uVar24;
              if (uVar24 == uVar25) goto LAB_001092a4;
            }
            lVar11 = lVar23 * 2 * uVar14;
            lVar13 = uVar25 - uVar14;
            puVar16 = (ssc_u16_u *)(uintptr_t)(auStack_190 + uVar14 + (long)iVar8 * (long)(int)uVar18);
            do {
              puVar2 = (ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar10)) + lVar11));
              lVar13 = lVar13 + -1;
              lVar11 = lVar11 + lVar23 * 2;
              *puVar16 = *puVar2;
              puVar16 = puVar16 + 1;
            } while (lVar13 != 0);
          }
LAB_001092a4:
          uVar22 = uVar22 + 1;
          psVar10 = psVar10 + 1;
        } while (uVar22 != uVar19);
      }
    }
    else if (0 < (int)uVar4) {
      lVar23 = 0;
      uVar22 = 0;
      uVar24 = uVar25 & 0xfffffffe;
      psVar26 = (ssc_i16_u *)(uintptr_t)(((ulong)(uintptr_t)(uintptr_t)((auStack_190)) | 2));
      psVar10 = param_2;
      do {
        if (0 < (int)uVar18) {
          psVar12 = psVar26;
          uVar14 = uVar24;
          psVar15 = psVar10;
          if (uVar18 == 1) {
            uVar14 = 0;
          }
          else {
            do {
              sVar6 = psVar15[uVar19];
              uVar14 = uVar14 - 2;
              psVar12[-1] = *psVar15;
              *psVar12 = sVar6;
              psVar12 = psVar12 + 2;
              psVar15 = psVar15 + uVar19 * 2;
            } while (uVar14 != 0);
            uVar14 = uVar24;
            if (uVar24 == uVar25) goto LAB_00109368;
          }
          lVar11 = uVar19 * 2 * uVar14;
          lVar13 = uVar25 - uVar14;
          puVar16 = (ssc_u16_u *)(uintptr_t)(auStack_190 + uVar14 + lVar23);
          do {
            puVar2 = (ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar10)) + lVar11));
            lVar13 = lVar13 + -1;
            lVar11 = lVar11 + uVar19 * 2;
            *puVar16 = *puVar2;
            puVar16 = puVar16 + 1;
          } while (lVar13 != 0);
        }
LAB_00109368:
        uVar22 = uVar22 + 1;
        psVar10 = psVar10 + 1;
        psVar26 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar26)) +
                           (-(ulong)(uVar18 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar18 << 1)));
        lVar23 = lVar23 + (int)uVar18;
      } while (uVar22 != uVar19);
    }
    if (0 < (int)(uVar4 * uVar18)) {
      memcpy((void *)(param_2),(const void *)(auStack_190),(ulong)(uVar4 * uVar18) << 1);
    }
  }
  return FUN_00109460(param_1,(undefined1 (*) [16])param_2,param_3,param_4,uVar27,3,param_6,param_8);
}


/* ==================================================================== */
/* Function: FUN_00109460 @ 00109460 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_00109460(long param_1,undefined1 (*param_2) [16],uint param_3,int param_4,
                 undefined8 param_5,int param_6,short param_7,uint param_8)

{
  ssc_i16_u *psVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  undefined1 *puVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  int iVar16;
  short sVar17;
  uint uVar18;
  uint uVar19;
  long lVar20;
  ulong uVar21;
  long lVar22;
  ssc_i16_u *psVar23;
  undefined1 (*pauVar24) [16];
  int iVar25;
  long lVar26;
  ulong uVar27;
  ulong uVar28;
  undefined1 (*pauVar29) [16];
  uint uVar30;
  undefined8 uVar31;
  int iVar32;
  int iVar33;
  int iVar35;
  int iVar36;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  int iVar56;
  int iVar57;
  int iVar58;
  int iVar59;
  int iVar61;
  int iVar62;
  int iVar64;
  vec128_t auVar65;
  vec128_t auVar66;
  vec128_t auVar67;
  vec128_t auVar68;
  uint local_74;
  int local_70;
  int iStack_6c;
  long local_68;
  undefined8 uVar34;
  undefined8 uVar37;
  undefined8 uVar60;
  undefined8 uVar63;

  lVar6 = tpidr_el0;
  local_68 = *(ssc_i64_u *)(uintptr_t)((lVar6 + 0x28));
  lVar26 = *(ssc_i64_u *)(uintptr_t)((param_1 + 8));
  uVar31 = *(ssc_u64_u *)(uintptr_t)((param_1 + 0x20));
  lVar20 = (long)*(ssc_i16_u *)(uintptr_t)((*(ssc_i64_u *)(uintptr_t)((lVar26 + 0x68)) +
                           (long)(*(ssc_i32_u *)(uintptr_t)((param_1 + 0x10)) + *(ssc_i32_u *)(uintptr_t)((lVar26 + 8)) * (param_6 + 1)) *
                           2));
  lVar22 = *(ssc_i64_u *)(uintptr_t)((lVar26 + 0x70));
  pbVar2 = (byte *)(uintptr_t)((lVar22 + lVar20));
  bVar3 = *pbVar2;
  if (((param_6 == -1) || ((int)param_3 < 3)) || (param_4 <= (int)(pbVar2[bVar3] + 0xc))) {
    uVar18 = bVar3 + 1 >> 1;
    param_4 = param_4 + -1;
    uVar14 = (uint)bVar3;
    uVar13 = uVar18;
    if (param_4 <= (int)(uint)pbVar2[uVar18]) {
      uVar13 = 0;
      uVar14 = uVar18;
    }
    uVar18 = uVar13 + uVar14 + 1 >> 1;
    if (param_4 <= (int)(uint)pbVar2[uVar18]) {
      uVar14 = uVar18;
      uVar18 = uVar13;
    }
    uVar13 = uVar18 + uVar14 + 1 >> 1;
    if (param_4 <= (int)(uint)pbVar2[uVar13]) {
      uVar14 = uVar13;
      uVar13 = uVar18;
    }
    uVar18 = uVar13 + uVar14 + 1 >> 1;
    if (param_4 <= (int)(uint)pbVar2[uVar18]) {
      uVar14 = uVar18;
      uVar18 = uVar13;
    }
    uVar13 = uVar18 + uVar14 + 1 >> 1;
    if (param_4 <= (int)(uint)pbVar2[uVar13]) {
      uVar14 = uVar13;
      uVar13 = uVar18;
    }
    uVar18 = uVar13 + uVar14 + 1 >> 1;
    if (param_4 <= (int)(uint)pbVar2[uVar18]) {
      uVar14 = uVar18;
      uVar18 = uVar13;
    }
    if (uVar18 == 0) {
      uVar13 = 0xffffffff;
    }
    else {
      uVar13 = (uint)pbVar2[uVar18];
    }
    if ((int)(param_4 - uVar13) <= (int)((uint)pbVar2[uVar14] - param_4)) {
      uVar14 = uVar18;
    }
    uVar15 = (ulong)uVar14;
    if (uVar14 == 0) {
LAB_001096b0:
      uVar15 = 0;
    }
    else {
      iVar10 = pbVar2[uVar14] + 1;
      iVar25 = *(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) - iVar10;
      *(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) = iVar25;
      if (iVar25 < 0) {
        do {
          iVar25 = iVar10 + iVar25;
          uVar5 = uVar15 - 1;
          *(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) = iVar25;
          if (uVar5 == 0) goto LAB_001096b0;
          iVar10 = *(byte *)(uintptr_t)((lVar20 + lVar22 + -1 + uVar15)) + 1;
          iVar25 = iVar25 - iVar10;
          *(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) = iVar25;
          uVar15 = uVar5;
        } while (iVar25 < 0);
        uVar14 = (uint)uVar5;
        if (uVar14 == 0) goto LAB_001096b0;
        uVar15 = uVar5 & 0xffffffff;
      }
      if (7 < uVar14) {
        uVar15 = (ulong)(((uint)uVar15 & 7 | 8) << (ulong)((int)(uVar15 >> 3) - 1U & 0x1f));
      }
      uVar15 = ssc_alg_quant((ssc_i16_u *)(param_2),param_3,uVar15,*(ssc_u32_u *)(uintptr_t)((param_1 + 0x18)),param_5,uVar31);
    }
    goto LAB_00109b84;
  }
  iVar25 = param_6 + -1;
  iVar16 = (int)param_5;
  iVar11 = (param_3 & 0xfffffffe) - 1;
  uVar14 = param_3 >> 1;
  uVar15 = (ulong)uVar14;
  psVar1 = (ssc_i16_u *)(*param_2 + uVar15 * 2);
  iVar10 = (int)*(ssc_i16_u *)(uintptr_t)((*(ssc_i64_u *)(uintptr_t)((lVar26 + 0x38)) + (long)*(ssc_i32_u *)(uintptr_t)((param_1 + 0x10)) * 2)) +
           iVar25 * 8;
  uVar13 = (param_4 - iVar10) - 0x20;
  uVar18 = 0;
  if (iVar11 != 0) {
    uVar18 = (param_4 + ((iVar10 >> 1) + -4) * iVar11) / iVar11;
  }
  uVar30 = param_8 & 1 | param_8 << 1;
  if (iVar16 != 1) {
    uVar30 = param_8;
  }
  if ((int)uVar18 <= (int)uVar13) {
    uVar13 = uVar18;
  }
  if (0x3f < (int)uVar13) {
    uVar13 = 0x40;
  }
  if ((int)uVar13 < 4) {
    uVar13 = 1;
  }
  else {
    uVar13 = ((int)((ssc_i16_u *)(&DAT_00102760))[uVar13 & 7] >> (0xe - (uVar13 >> 3) & 0x1f)) + 1U &
             0xfffffffe;
  }
  if (uVar14 - 1 < 0xf) {
    iVar10 = 1;
    iVar47 = 1;
    uVar21 = uVar15;
    psVar23 = psVar1;
    pauVar24 = param_2;
LAB_001097e0:
    do {
      uVar18 = (int)uVar21 - 1;
      uVar21 = (ulong)uVar18;
      iVar10 = iVar10 + (int)*(ssc_i16_u *)*pauVar24 * (int)*(ssc_i16_u *)*pauVar24;
      iVar47 = iVar47 + (int)*psVar23 * (int)*psVar23;
      psVar23 = psVar23 + 1;
      pauVar24 = (undefined1 (*) [16])(*pauVar24 + 2);
    } while (uVar18 != 0);
  }
  else {
    uVar5 = (ulong)(uVar14 - 1) + 1;
    uVar27 = uVar5 & 0x1fffffff0;
    uVar21 = (ulong)(uVar14 - (int)uVar27);
    psVar23 = psVar1 + uVar27;
    iVar10 = 0;
    iVar11 = 0;
    iVar32 = 0;
    iVar12 = 0;
    pauVar24 = (undefined1 (*) [16])(*param_2 + uVar27 * 2);
    iVar39 = 0;
    iVar40 = 0;
    iVar41 = 0;
    iVar42 = 0;
    iVar43 = 0;
    iVar44 = 0;
    iVar45 = 0;
    iVar46 = 0;
    iVar47 = 0;
    iVar48 = 0;
    iVar49 = 0;
    iVar50 = 0;
    iVar51 = 0;
    iVar52 = 0;
    iVar53 = 0;
    iVar54 = 0;
    iVar55 = 0;
    iVar56 = 0;
    iVar57 = 0;
    iVar58 = 0;
    uVar28 = uVar27;
    pauVar29 = param_2;
    uVar34 = DAT_00102780;
    uVar37 = UNK_00102788;
    uVar60 = DAT_00102780;
    uVar63 = UNK_00102788;
    do {
      auVar65 = *(vec128_t *)*pauVar29;
      auVar66 = *(vec128_t *)pauVar29[1];
      puVar7 = *pauVar29;
      pauVar29 = pauVar29 + 2;
      uVar28 = uVar28 - 0x10;
      auVar67 = NEON_ext(auVar65,auVar65,8,1);
      iVar33 = (int)uVar34 + (int)auVar65._0_2_ * (int)auVar65._0_2_;
      iVar35 = (int)((ulong)uVar34 >> 0x20) + (int)auVar65._2_2_ * (int)auVar65._2_2_;
      uVar34 = CONCAT44(iVar35,iVar33);
      iVar36 = (int)uVar37 + (int)auVar65._4_2_ * (int)auVar65._4_2_;
      iVar38 = (int)((ulong)uVar37 >> 0x20) + (int)auVar65._6_2_ * (int)auVar65._6_2_;
      uVar37 = CONCAT44(iVar38,iVar36);
      auVar68 = NEON_ext(auVar66,auVar66,8,1);
      iVar39 = iVar39 + (int)auVar66._0_2_ * (int)auVar66._0_2_;
      iVar40 = iVar40 + (int)auVar66._2_2_ * (int)auVar66._2_2_;
      iVar41 = iVar41 + (int)auVar66._4_2_ * (int)auVar66._4_2_;
      iVar42 = iVar42 + (int)auVar66._6_2_ * (int)auVar66._6_2_;
      auVar65 = *(vec128_t *)(puVar7 + uVar15 * 2);
      auVar66 = ((vec128_t *)(puVar7 + uVar15 * 2))[1];
      iVar10 = iVar10 + (int)auVar67._0_2_ * (int)auVar67._0_2_;
      iVar11 = iVar11 + (int)auVar67._2_2_ * (int)auVar67._2_2_;
      iVar32 = iVar32 + (int)auVar67._4_2_ * (int)auVar67._4_2_;
      iVar12 = iVar12 + (int)auVar67._6_2_ * (int)auVar67._6_2_;
      iVar43 = iVar43 + (int)auVar68._0_2_ * (int)auVar68._0_2_;
      iVar44 = iVar44 + (int)auVar68._2_2_ * (int)auVar68._2_2_;
      iVar45 = iVar45 + (int)auVar68._4_2_ * (int)auVar68._4_2_;
      iVar46 = iVar46 + (int)auVar68._6_2_ * (int)auVar68._6_2_;
      iVar59 = (int)uVar60 + (int)auVar65._0_2_ * (int)auVar65._0_2_;
      iVar61 = (int)((ulong)uVar60 >> 0x20) + (int)auVar65._2_2_ * (int)auVar65._2_2_;
      uVar60 = CONCAT44(iVar61,iVar59);
      iVar62 = (int)uVar63 + (int)auVar65._4_2_ * (int)auVar65._4_2_;
      iVar64 = (int)((ulong)uVar63 >> 0x20) + (int)auVar65._6_2_ * (int)auVar65._6_2_;
      uVar63 = CONCAT44(iVar64,iVar62);
      auVar65 = NEON_ext(auVar65,auVar65,8,1);
      iVar51 = iVar51 + (int)auVar66._0_2_ * (int)auVar66._0_2_;
      iVar52 = iVar52 + (int)auVar66._2_2_ * (int)auVar66._2_2_;
      iVar53 = iVar53 + (int)auVar66._4_2_ * (int)auVar66._4_2_;
      iVar54 = iVar54 + (int)auVar66._6_2_ * (int)auVar66._6_2_;
      auVar66 = NEON_ext(auVar66,auVar66,8,1);
      iVar47 = iVar47 + (int)auVar65._0_2_ * (int)auVar65._0_2_;
      iVar48 = iVar48 + (int)auVar65._2_2_ * (int)auVar65._2_2_;
      iVar49 = iVar49 + (int)auVar65._4_2_ * (int)auVar65._4_2_;
      iVar50 = iVar50 + (int)auVar65._6_2_ * (int)auVar65._6_2_;
      iVar55 = iVar55 + (int)auVar66._0_2_ * (int)auVar66._0_2_;
      iVar56 = iVar56 + (int)auVar66._2_2_ * (int)auVar66._2_2_;
      iVar57 = iVar57 + (int)auVar66._4_2_ * (int)auVar66._4_2_;
      iVar58 = iVar58 + (int)auVar66._6_2_ * (int)auVar66._6_2_;
    } while (uVar28 != 0);
    iVar47 = iVar51 + iVar59 + iVar55 + iVar47 + iVar52 + iVar61 + iVar56 + iVar48 +
             iVar53 + iVar62 + iVar57 + iVar49 + iVar54 + iVar64 + iVar58 + iVar50;
    iVar10 = iVar39 + iVar33 + iVar43 + iVar10 + iVar40 + iVar35 + iVar44 + iVar11 +
             iVar41 + iVar36 + iVar45 + iVar32 + iVar42 + iVar38 + iVar46 + iVar12;
    if (uVar5 != uVar27) goto LAB_001097e0;
  }
  uVar8 = ssc_sqrt(iVar47);
  uVar9 = ssc_sqrt(iVar10);
  if ((short)uVar8 < (short)uVar9) {
    iVar10 = ssc_rcp((int)((uint)uVar9 << 0x10) >> 0x10);
    uVar18 = (uint)((ulong)((long)iVar10 * (long)((int)((uint)uVar8 << 0x10) >> 1)) >> 0x1f);
    if (0x7ffe < (int)uVar18) {
      uVar18 = 0x7fff;
    }
    uVar19 = -(uVar18 >> 0xf & 1) & 0xfffe0000 | (uVar18 & 0xffff) << 1;
    sVar17 = (short)(((int)(((int)(((short)uVar18 * 0x2690 + -0x2ea68000 >> 0x10) * uVar19 +
                                  -0x148000) >> 0x10) * uVar19 + 0x7fff8000) >> 0x10) *
                     (int)(short)uVar18 + 0x4000U >> 0xf) >> 1;
  }
  else {
    iVar10 = ssc_rcp((int)((uint)uVar8 << 0x10) >> 0x10);
    uVar18 = (uint)((ulong)((long)iVar10 * (long)((int)((uint)uVar9 << 0x10) >> 1)) >> 0x1f);
    if (0x7ffe < (int)uVar18) {
      uVar18 = 0x7fff;
    }
    uVar19 = -(uVar18 >> 0xf & 1) & 0xfffe0000 | (uVar18 & 0xffff) << 1;
    sVar17 = 0x6488 - (short)((((int)(((int)(((short)uVar18 * 0x2690 + -0x2ea68000 >> 0x10) * uVar19
                                            + -0x148000) >> 0x10) * uVar19 + 0x7fff8000) >> 0x10) *
                               (int)(short)uVar18 + 0x4000) * 2 >> 0x11);
  }
  local_74 = sVar17 * 0x517d >> 0xf;
  iVar10 = ssc_ec_tell_frac(uVar31);
  if (uVar13 != 1) {
    uVar18 = local_74 * uVar13 + 0x2000;
    iVar11 = (int)uVar18 >> 0xe;
    if (iVar16 < 2) {
      iVar12 = (int)uVar13 >> 1;
      iVar32 = (uVar13 - iVar11) + 1;
      iVar39 = iVar32 * ((uVar13 - iVar11) + 2);
      if (iVar11 <= iVar12) {
        iVar32 = iVar11 + 1;
      }
      iVar39 = (iVar12 + 1) * (iVar12 + 1) - (iVar39 >> 1);
      if (iVar11 <= iVar12) {
        iVar39 = (iVar11 + 1) * iVar11 >> 1;
      }
      ssc_ec_encode(uVar31,iVar39,iVar39 + iVar32,(iVar12 + 1) * (iVar12 + 1));
    }
    else {
      ssc_ec_enc_uint((ssc_i64_u *)((void *)(uintptr_t)((uintptr_t)uVar31)),iVar11,uVar13 + 1);
    }
    local_74 = 0;
    if (uVar13 != 0) {
      local_74 = (int)(uVar18 & 0xffffc000) / (int)uVar13;
    }
  }
  uVar13 = iVar16 + 1 >> 1;
  iVar11 = ssc_ec_tell_frac(uVar31);
  uVar18 = param_4 - (iVar11 - iVar10);
  if (local_74 == 0x4000) {
    iStack_6c = 0;
    local_70 = 0x7fff;
    uVar14 = ~(-1 << (ulong)(uVar13 & 0x1f)) << (ulong)(uVar13 & 0x1f);
    uVar19 = 0x4000;
LAB_001099f8:
    uVar30 = uVar14 & uVar30;
  }
  else {
    if (local_74 == 0) {
      local_70 = 0;
      iStack_6c = 0x7fff;
      uVar14 = ~(-1 << (ulong)(uVar13 & 0x1f));
      uVar19 = 0xffffc000;
      goto LAB_001099f8;
    }
    ssc_bitexact_cos_asm(local_74,0x4000 - local_74,(ssc_i32_u *)&iStack_6c,(ssc_i32_u *)&local_70);
    uVar19 = (int)LZCOUNT(local_70) - 0x11;
    uVar4 = (int)LZCOUNT(iStack_6c) - 0x11;
    iVar32 = (int)(short)(local_70 << (ulong)(uVar19 & 0x1f));
    iVar12 = (int)(short)(iStack_6c << (ulong)(uVar4 & 0x1f));
    uVar19 = (int)(short)(((short)(((iVar32 * -0xa25 + 0x4000 >> 0xf) + 0x1efc) * iVar32 + 0x4000U
                                  >> 0xf) + ((short)uVar4 - (short)uVar19) * 0x800) -
                         (short)(((iVar12 * -0xa25 + 0x4000 >> 0xf) + 0x1efc) * iVar12 + 0x4000U >>
                                0xf)) * (int)(short)(((ushort)param_3 & 0x3fe) * 0x40 + -0x80) +
             0x4000 >> 0xf;
    if ((1 < iVar16) && ((local_74 & 0x3fff) != 0)) {
      if ((int)local_74 < 0x2001) {
        uVar19 = uVar19 + (uVar14 >> (ulong)(3U - param_6 & 0x1f));
        uVar19 = uVar19 & (int)uVar19 >> 0x1f;
      }
      else {
        uVar19 = uVar19 - ((int)uVar19 >> (5U - param_6 & 0x1f));
      }
    }
  }
  uVar14 = (int)(uVar18 - uVar19) >> 1;
  iVar32 = (int)param_7;
  uVar19 = uVar18;
  if ((int)uVar14 <= (int)uVar18) {
    uVar19 = uVar14;
  }
  iVar11 = *(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) - (iVar11 - iVar10);
  uVar19 = uVar19 & ((int)uVar19 >> 0x1f ^ 0xffffffffU);
  iVar10 = uVar18 - uVar19;
  *(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) = iVar11;
  if ((int)uVar19 < iVar10) {
    iVar12 = FUN_00109460(param_1,(undefined1 (*)[16])(psVar1),uVar15,iVar10,uVar13,iVar25,
                          (short)local_70 * iVar32 + 0x4000U >> 0xf,(int)uVar30 >> (uVar13 & 0x1f));
    iVar10 = (*(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) - iVar11) + iVar10;
    iVar11 = iVar10 + -0x18;
    if (local_74 == 0x4000 || iVar10 < 0x19) {
      iVar11 = 0;
    }
    uVar13 = FUN_00109460(param_1,param_2,uVar15,iVar11 + uVar19,uVar13,iVar25,
                          (short)iStack_6c * iVar32 + 0x4000U >> 0xf,uVar30);
    uVar15 = (ulong)(uVar13 | iVar12 << (ulong)(iVar16 >> 1 & 0x1f));
  }
  else {
    uVar14 = FUN_00109460(param_1,param_2,uVar15,uVar19,uVar13,iVar25,
                          (short)iStack_6c * iVar32 + 0x4000U >> 0xf,uVar30);
    iVar11 = (*(ssc_i32_u *)(uintptr_t)((param_1 + 0x28)) - iVar11) + uVar19;
    iVar12 = iVar11 + -0x18;
    if (local_74 == 0 || iVar11 < 0x19) {
      iVar12 = 0;
    }
    iVar10 = FUN_00109460(param_1,(undefined1 (*)[16])(psVar1),uVar15,iVar12 + iVar10,uVar13,iVar25,
                          (short)local_70 * iVar32 + 0x4000U >> 0xf,(int)uVar30 >> (uVar13 & 0x1f));
    uVar15 = (ulong)(iVar10 << (ulong)(iVar16 >> 1 & 0x1f) | uVar14);
  }
LAB_00109b84:
  return uVar15;
}


/* ==================================================================== */
/* Function: FUN_00109ca4 @ 00109ca4 */
/* ==================================================================== */

void FUN_00109ca4(long param_1,ssc_u64_u *param_2,ssc_u64_u *param_3,long param_4,int param_5,
                 uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  short sVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ssc_i16_u *psVar14;
  ulong uVar15;
  ssc_i16_u *psVar16;
  ssc_u64_u *puVar17;
  ssc_u64_u *puVar18;
  undefined8 uVar19;
  undefined8 uVar20;

  iVar3 = *(ssc_i32_u *)(uintptr_t)((param_4 + (long)param_5 * 4));
  iVar4 = *(ssc_i32_u *)(uintptr_t)((param_4 + (long)(*(ssc_i32_u *)(uintptr_t)((param_1 + 8)) + param_5) * 4));
  iVar7 = iVar3;
  if (iVar3 <= iVar4) {
    iVar7 = iVar4;
  }
  iVar6 = 0x1f - (int)LZCOUNT(iVar7);
  if (iVar7 < 1) {
    iVar6 = 0;
  }
  uVar1 = iVar4 << (ulong)(0xdU - iVar6 & 0x1f);
  if (0xd < iVar6) {
    uVar1 = iVar4 >> (iVar6 - 0xdU & 0x1f);
  }
  uVar2 = iVar3 << (ulong)(0xdU - iVar6 & 0x1f);
  if (0xd < iVar6) {
    uVar2 = iVar3 >> (iVar6 - 0xdU & 0x1f);
  }
  sVar10 = ssc_sqrt((int)(short)uVar1 * (int)(short)uVar1 + (int)(short)uVar2 * (int)(short)uVar2 +
                    1);
  if (0 < (int)param_6) {
    iVar7 = (int)(short)(sVar10 + 1);
    sVar10 = 0;
    if (iVar7 != 0) {
      sVar10 = (short)((int)(-(uVar2 >> 0xf & 1) & 0xc0000000 | (uVar2 & 0xffff) << 0xe) / iVar7);
    }
    sVar5 = 0;
    if (iVar7 != 0) {
      sVar5 = (short)((int)(-(uVar1 >> 0xf & 1) & 0xc0000000 | (uVar1 & 0xffff) << 0xe) / iVar7);
    }
    iVar7 = (int)sVar10;
    iVar3 = (int)sVar5;
    uVar11 = (ulong)param_6;
    if ((param_6 < 8) ||
       ((param_2 < (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + uVar11 * 2)) &&
        (param_3 < (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_2)) + uVar11 * 2)))))) {
      uVar13 = 0;
    }
    else {
      uVar13 = uVar11 & 0xfffffff8;
      uVar15 = uVar13;
      puVar17 = param_3;
      puVar18 = param_2;
      do {
        uVar9 = puVar17[1];
        uVar8 = *puVar17;
        uVar20 = puVar18[1];
        uVar19 = *puVar18;
        uVar15 = uVar15 - 8;
        puVar18[1] = CONCAT26((short)((uint)(iVar3 * (short)((ulong)uVar9 >> 0x30)) >> 0xe) +
                              (short)((uint)(iVar7 * (short)((ulong)uVar20 >> 0x30)) >> 0xe),
                              CONCAT24((short)((uint)(iVar3 * (short)((ulong)uVar9 >> 0x20)) >> 0xe)
                                       + (short)((uint)(iVar7 * (short)((ulong)uVar20 >> 0x20)) >>
                                                0xe),
                                       CONCAT22((short)((uint)(iVar3 * (short)((ulong)uVar9 >> 0x10)
                                                              ) >> 0xe) +
                                                (short)((uint)(iVar7 * (short)((ulong)uVar20 >> 0x10
                                                                              )) >> 0xe),
                                                (short)((uint)(iVar3 * (short)uVar9) >> 0xe) +
                                                (short)((uint)(iVar7 * (short)uVar20) >> 0xe))));
        *puVar18 = CONCAT26((short)(((uint)(iVar3 * (short)((ulong)uVar8 >> 0x30)) >> 0xe & 0xffff)
                                   + ((uint)(iVar7 * (short)((ulong)uVar19 >> 0x30)) >> 0xe)),
                            CONCAT24((short)(((uint)(iVar3 * (short)((ulong)uVar8 >> 0x20)) >> 0xe &
                                             0xffff) +
                                            ((uint)(iVar7 * (short)((ulong)uVar19 >> 0x20)) >> 0xe))
                                     ,CONCAT22((short)(((uint)(iVar3 * (short)((ulong)uVar8 >> 0x10)
                                                              ) >> 0xe & 0xffff) +
                                                      ((uint)(iVar7 * (short)((ulong)uVar19 >> 0x10)
                                                             ) >> 0xe)),
                                               (short)((uint)(iVar3 * (short)uVar8) >> 0xe) +
                                               (short)((uint)(iVar7 * (short)uVar19) >> 0xe))));
        puVar17 = puVar17 + 2;
        puVar18 = puVar18 + 2;
      } while (uVar15 != 0);
      if (uVar13 == uVar11) {
        return;
      }
    }
    lVar12 = uVar11 - uVar13;
    psVar14 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + uVar13 * 2));
    psVar16 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_2)) + uVar13 * 2));
    do {
      lVar12 = lVar12 + -1;
      *psVar16 = (short)((uint)(iVar3 * *psVar14) >> 0xe) + (short)((uint)(iVar7 * *psVar16) >> 0xe)
      ;
      psVar14 = psVar14 + 1;
      psVar16 = psVar16 + 1;
    } while (lVar12 != 0);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_encode_pulses @ 00109e38 */
/* ==================================================================== */

void ssc_encode_pulses(long param_1,ulong param_2,int param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  ssc_i32_u *piVar7;
  ssc_i32_u *piVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  if (param_2 == 4 && param_3 == 30) {;
  }

  iVar4 = (int)param_2;
  if (param_3 < iVar4) {
    uVar10 = -(param_2 >> 0x1f & 1) & 0xfffffffc00000000 | (param_2 & 0xffffffff) << 2;
    piVar7 = (ssc_i32_u *)(uintptr_t)(((PTR_DAT_0011b948_arr)[param_3] + uVar10));
    piVar8 = (ssc_i32_u *)(uintptr_t)(((PTR_DAT_0011b950_arr)[param_3] + uVar10));
  }
  else {
    piVar7 = (ssc_i32_u *)(uintptr_t)(((PTR_DAT_0011b948_arr)[iVar4] + (long)param_3 * 4));
    piVar8 = piVar7 + 1;
  }
  lVar6 = (long)iVar4;
  uVar10 = 2;
  uVar3 = *(ssc_u32_u *)(uintptr_t)((param_1 + (long)iVar4 * 4 + -4));
  uVar5 = uVar3 >> 0x1f;
  uVar9 = -uVar3;
  if (-1 < (int)uVar3) {
    uVar9 = uVar3;
  }
  do {
    iVar4 = *(ssc_i32_u *)(uintptr_t)((param_1 + -8 + lVar6 * 4));
    uVar11 = (uint)uVar10;
    uVar3 = uVar11;
    if (uVar9 <= uVar10) {
      uVar3 = uVar9;
    }
    uVar2 = uVar11;
    if (uVar10 <= uVar9) {
      uVar2 = uVar9;
    }
    iVar1 = -iVar4;
    if (-1 < iVar4) {
      iVar1 = iVar4;
    }
    uVar9 = iVar1 + uVar9;
    int _t1 = *(ssc_i32_u *)(uintptr_t)(((PTR_DAT_0011b948_arr)[(int)uVar3] + (ulong)uVar2 * 4));
    uVar5 = _t1 + uVar5;
    if (param_2 == 4 && param_3 == 30) {;
    }
    if (iVar4 < 0) {
      uVar3 = uVar11;
      if (uVar9 < uVar10) {
        uVar3 = uVar9 + 1;
      }
      if (uVar10 <= uVar9 + 1) {
        uVar11 = uVar9 + 1;
      }
      uVar5 = *(ssc_i32_u *)(uintptr_t)(((PTR_DAT_0011b948_arr)[(int)uVar3] + (ulong)uVar11 * 4)) + uVar5;
    }
    lVar6 = lVar6 + -1;
    uVar10 = uVar10 + 1;
  } while ((int)lVar6 != 1);
  ssc_ec_enc_uint((ssc_i64_u *)((void *)(uintptr_t)((uintptr_t)param_4)),uVar5,*piVar8 + *piVar7);
  return;
}


/* ==================================================================== */
/* Function: ssc_encoder_get_size @ 00109f0c */
/* ==================================================================== */

int ssc_encoder_get_size(int param_1,undefined4 param_2)

{
  long lVar1;

  lVar1 = (long)(uintptr_t)(uintptr_t)(ssc_custom_mode_create(param_2,0x360,0));
  return (*(ssc_i32_u *)(uintptr_t)((lVar1 + 8)) * 6 + *(ssc_i32_u *)(uintptr_t)((lVar1 + 4)) * 4 + 0x1000) * param_1 + 0xdc;
}


/* ==================================================================== */
/* Function: ssc_encoder_init @ 00109f54 */
/* ==================================================================== */

int ssc_encoder_init(ssc_i64_u *param_1,int param_2,int param_3,int param_4)

{
  ssc_init_image();
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;

  lVar3 = (long)(uintptr_t)(uintptr_t)(ssc_custom_mode_create(param_2,0x360,0));
  SSC_CLEAR((void *)(param_1),(*(ssc_i32_u *)(uintptr_t)((lVar3 + 8)) * 6 + *(ssc_i32_u *)(uintptr_t)((lVar3 + 4)) * 4 + 0x1000) * param_3 + 0xdc);
  lVar3 = (long)(uintptr_t)(uintptr_t)(ssc_custom_mode_create(param_2,0x360,0));
  if (param_3 < 3) {
    uVar4 = 0xfffffff9;
    if ((param_1 != (ssc_i64_u *)0x0) && (lVar3 != 0)) {
      SSC_CLEAR((void *)(param_1),(*(ssc_i32_u *)(uintptr_t)((lVar3 + 8)) * 6 + *(ssc_i32_u *)(uintptr_t)((lVar3 + 4)) * 4 + 0x1000) * param_3 +
                        0xdc);
      uVar1 = *(ssc_u32_u *)(uintptr_t)((lVar3 + 4));
      *param_1 = lVar3;
      *(ssc_u32_u *)(param_1 + 1) = uVar1;
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) = param_3;
      lVar2 = DAT_00102810;
      uVar1 = *(ssc_u32_u *)(uintptr_t)((lVar3 + 0xc));
      *(ssc_u32_u *)(param_1 + 5) = 0x100;
      param_1[4] = lVar2;
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) = uVar1;
      *(ssc_u32_u *)(param_1 + 3) = 0xffffffff;
      param_1[6] = 0;
      *(ssc_u32_u *)(param_1 + 0x10) = 0;
      *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x84)) = 0;
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) = param_3;
      *(ssc_u32_u *)(param_1 + 2) = 0;
      *(ssc_i32_u *)(param_1 + 0xc) = param_2;
      *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 100)) = param_2;
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x6c)) = param_4;
      param_1[0x19] = 0;
      param_1[0x18] = 0;
      param_1[0x1b] = 0;
      param_1[0x1a] = 0;
      param_1[0x15] = 0;
      param_1[0x14] = 0;
      param_1[0x17] = 0;
      param_1[0x16] = 0;
      param_1[0x13] = 0;
      param_1[0x12] = 0;
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x8c)) = 0x10000;
      if (param_2 == 48000) {
        *(ssc_u32_u *)(param_1 + 0xc) = 0xac44;
      }
      *(ssc_u32_u *)PTR_previous_uhq_index_0011bcd0 = 0;
      SSC_DRC_Init(param_2,param_3);
      SSC_DRC_SetPar(1,0x7b8e,0,50000,0);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


/* ==================================================================== */
/* Function: ssc_encoder_create @ 0010a0b8 */
/* ==================================================================== */

void * ssc_encoder_create(int param_1,int param_2,int param_3,ssc_i32_u *param_4)
{
  ssc_init_image();
  int iVar1;
  long lVar2;
  void *__ptr;

  lVar2 = (long)(uintptr_t)(uintptr_t)(ssc_custom_mode_create(param_1,0x360,0));
  __ptr = malloc((long)((*(ssc_i32_u *)(uintptr_t)((lVar2 + 8)) * 6 + *(ssc_i32_u *)(uintptr_t)((lVar2 + 4)) * 4 + 0x1000) * param_2 +
                       0xdc));
  if (__ptr == (void *)0x0) {
    if (param_4 != (ssc_i32_u *)0x0) {
      *param_4 = -7;
      return (void *)0x0;
    }
  }
  else {
    iVar1 = ssc_encoder_init((ssc_i64_u *)(__ptr),param_1 & 0xffffffff,param_2,param_3);
    if (param_4 != (ssc_i32_u *)0x0) {
      *param_4 = iVar1;
    }
    if (iVar1 == 0) {
      return __ptr;
    }
    free(__ptr);
  }
  return (void *)0x0;
}


/* ==================================================================== */
/* Function: ssc_patch_transient_decision @ 0010a170 */

int ssc_patch_transient_decision(ssc_i16_u *param_1, ssc_i16_u *param_2, int param_3, uint param_4) {
    int p4 = (int)param_4;
    if (p4 <= 14) return 0;

    int16_t stack_buf[64];
    int16_t v13 = param_2[13];
    int16_t v13_shift = param_2[param_3 + 13];
    int16_t max_val = (v13 > v13_shift) ? v13 : v13_shift;
    stack_buf[13] = max_val;

    int cur_val = max_val;
    for (int i = 14; i < p4; i++) {
        int16_t a = param_2[i];
        int16_t b = param_2[i + param_3];
        int16_t m = (a > b) ? a : b;
        int prev_decay = cur_val - 0x400;
        cur_val = (m > prev_decay) ? m : prev_decay;
        stack_buf[i] = (int16_t)cur_val;
    }

    for (int i = p4 - 2; i >= 13; i--) {
        int next_decay = stack_buf[i + 1] - 0x400;
        if (stack_buf[i] < next_decay) {
            stack_buf[i] = (int16_t)next_decay;
        }
    }

    int32_t sum = 0;
    for (int i = 13; i < p4 - 1; i++) {
        int32_t p1 = param_1[i];
        int32_t st = stack_buf[i];
        if (p1 < 0) p1 = 0;
        if (st < 0) st = 0;
        int32_t diff = p1 - st;
        if (diff > 0) {
            sum += diff;
        }
    }

    int count = p4 - 14;
    if (count <= 0) return 0;
    int avg = sum / count;
    int res = (avg > 0x400) ? 1 : 0;
    return res;
}

/* Function: normal_headroom @ 0010a36c */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void normal_headroom(long param_1,int param_2,int param_3,long param_4,int param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  ssc_u64_u *puVar11;
  ssc_u32_u *puVar12;
  ulong uVar13;
  ssc_u64_u *puVar14;
  ulong uVar15;
  ssc_u32_u *puVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  int iVar25;
  undefined8 uVar26;
  int iVar27;
  int iVar28;
  undefined8 uVar29;
  int iVar30;
  int iVar31;
  int iVar33;
  undefined8 uVar32;
  int iVar34;
  int iVar36;
  undefined8 uVar35;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;

  puVar10 = PTR_headroom_gain_0011bcd8;
  if (95999 < param_2) {
    sVar5 = *(ssc_i16_u *)(uintptr_t)((param_4 + 0x28));
    uVar8 = (param_3 >> 2) * 0x22;
    iVar25 = uVar8 + sVar5 * param_3;
    lVar18 = (long)*(ssc_i16_u *)(uintptr_t)((param_4 + 0x2c)) * (long)param_3;
    if ((int)lVar18 <= iVar25) {
      return;
    }
    uVar17 = (ulong)iVar25;
    lVar19 = (long)param_5;
    uVar15 = lVar18 - uVar17;
    uVar22 = uVar17;
    if ((3 < uVar15) &&
       ((int)uVar8 <= (int)(uVar8 + (int)(~uVar17 + lVar18)) && ~uVar17 + lVar18 >> 0x20 == 0)) {
      puVar1 = (undefined *)(uintptr_t)((param_1 + uVar17 * 4));
      puVar2 = (undefined *)(uintptr_t)((param_1 + lVar18 * 4));
      puVar3 = (undefined *)(uintptr_t)((param_1 + (lVar19 + uVar17) * 4));
      puVar4 = (undefined *)(uintptr_t)((param_1 + (lVar19 + lVar18) * 4));
      if ((puVar4 <= puVar1 || puVar2 <= puVar3) &&
         ((PTR_headroom_gain_0011bcd8 + ((lVar18 + (int)uVar8) - uVar17) * 4 <= puVar1 ||
           puVar2 <= PTR_headroom_gain_0011bcd8 + (long)(int)uVar8 * 4 &&
          (PTR_headroom_gain_0011bcd8 + ((lVar18 + (int)uVar8) - uVar17) * 4 <= puVar3 ||
           puVar4 <= PTR_headroom_gain_0011bcd8 + (long)(int)uVar8 * 4)))) {
        uVar20 = uVar15 & 0xfffffffffffffffc;
        uVar22 = uVar20 + uVar17;
        uVar13 = uVar20;
        puVar11 = (ssc_u64_u *)(uintptr_t)((param_1 + (lVar19 + uVar17) * 4));
        puVar14 = (ssc_u64_u *)(uintptr_t)((param_1 + uVar17 * 4));
        do {
          uVar17 = (ulong)uVar8;
          uVar9 = uVar8 >> 0x1f;
          uVar24 = puVar14[1];
          uVar23 = *puVar14;
          uVar35 = puVar11[1];
          uVar32 = *puVar11;
          uVar8 = uVar8 + 4;
          uVar13 = uVar13 - 4;
          uVar29 = *(ssc_u64_u *)(uintptr_t)(
                    ((long)(uintptr_t)(uintptr_t)(((puVar10 + (-(ulong)uVar9 & 0xfffffffc00000000 | uVar17 << 2)))) + 8));
          uVar26 = *(ssc_u64_u *)(puVar10 + (-(ulong)uVar9 & 0xfffffffc00000000 | uVar17 << 2));
          iVar25 = (int)(short)uVar26;
          iVar27 = (int)(short)((ulong)uVar26 >> 0x20);
          iVar28 = (int)(short)uVar29;
          iVar30 = (int)(short)((ulong)uVar29 >> 0x20);
          puVar14[1] = CONCAT44(((uint)((long)uVar24 >> 0x2f) & 0xfffffffe) * iVar30 +
                                ((int)(iVar30 * (uint)(ushort)(CONCAT15((char)((ulong)uVar24 >> 0x28
                                                                              ),CONCAT14((char)((
                                                  ulong)uVar24 >> 0x20),(uint)(ushort)uVar24)) >>
                                                  0x20)) >> 0xf),
                                ((int)uVar24 >> 0xf & 0xfffffffeU) * iVar28 +
                                ((int)(iVar28 * (uint)(ushort)uVar24) >> 0xf));
          *puVar14 = CONCAT44(((uint)((long)uVar23 >> 0x2f) & 0xfffffffe) * iVar27 +
                              ((int)(iVar27 * (uint)(ushort)(CONCAT15((char)((ulong)uVar23 >> 0x28),
                                                                      CONCAT14((char)((ulong)uVar23
                                                                                     >> 0x20),
                                                                               (uint)(ushort)uVar23)
                                                                     ) >> 0x20)) >> 0xf),
                              ((int)uVar23 >> 0xf & 0xfffffffeU) * iVar25 +
                              ((int)(iVar25 * (uint)(ushort)uVar23) >> 0xf));
          puVar11[1] = CONCAT44(((uint)((long)uVar35 >> 0x2f) & 0xfffffffe) * iVar30 +
                                ((int)(iVar30 * (uint)(ushort)(CONCAT15((char)((ulong)uVar35 >> 0x28
                                                                              ),CONCAT14((char)((
                                                  ulong)uVar35 >> 0x20),(uint)(ushort)uVar35)) >>
                                                  0x20)) >> 0xf),
                                ((int)uVar35 >> 0xf & 0xfffffffeU) * iVar28 +
                                ((int)(iVar28 * (uint)(ushort)uVar35) >> 0xf));
          *puVar11 = CONCAT44(((uint)((long)uVar32 >> 0x2f) & 0xfffffffe) * iVar27 +
                              ((int)(iVar27 * (uint)(ushort)(CONCAT15((char)((ulong)uVar32 >> 0x28),
                                                                      CONCAT14((char)((ulong)uVar32
                                                                                     >> 0x20),
                                                                               (uint)(ushort)uVar32)
                                                                     ) >> 0x20)) >> 0xf),
                              ((int)uVar32 >> 0xf & 0xfffffffeU) * iVar25 +
                              ((int)(iVar25 * (uint)(ushort)uVar32) >> 0xf));
          puVar11 = puVar11 + 2;
          puVar14 = puVar14 + 2;
        } while (uVar13 != 0);
        if (uVar15 == uVar20) {
          return;
        }
      }
    }
    lVar19 = param_1 + lVar19 * 4;
    do {
      lVar21 = uVar22 * 4;
      uVar8 = (int)uVar22 - param_3 * sVar5;
      uVar17 = -(ulong)(uVar8 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar8 << 2;
      uVar22 = uVar22 + 1;
      *(ssc_u32_u *)(uintptr_t)((param_1 + lVar21)) =
           ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + lVar21)) >> 0xf & 0xfffffffeU) *
           (int)*(ssc_i16_u *)(puVar10 + uVar17) +
           ((int)((int)*(ssc_i16_u *)(puVar10 + uVar17) * (*(ssc_u32_u *)(uintptr_t)((param_1 + lVar21)) & 0xffff)) >> 0xf
           );
      uVar8 = *(ssc_u32_u *)(uintptr_t)((lVar19 + lVar21));
      *(ssc_u32_u *)(uintptr_t)((lVar19 + lVar21)) =
           ((int)uVar8 >> 0xf & 0xfffffffeU) * (int)*(ssc_i16_u *)(puVar10 + uVar17) +
           ((int)((int)*(ssc_i16_u *)(puVar10 + uVar17) * (uVar8 & 0xffff)) >> 0xf);
    } while ((long)uVar22 < lVar18);
    return;
  }
  sVar5 = *(ssc_i16_u *)(uintptr_t)((param_4 + 0x22));
  sVar6 = *(ssc_i16_u *)(uintptr_t)((param_4 + 0x28));
  sVar7 = *(ssc_i16_u *)(uintptr_t)((param_4 + 0x2c));
  iVar25 = sVar5 * param_3;
  iVar27 = sVar7 * param_3;
  iVar28 = sVar6 * param_3 + -0xf;
  iVar30 = iVar25;
  if (iVar25 < iVar28) {
    lVar18 = (long)iVar25;
    lVar19 = (long)iVar28;
    lVar21 = (long)param_5;
    uVar22 = lVar19 - lVar18;
    iVar30 = iVar28;
    if (3 < uVar22) {
      puVar11 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar18 * 4));
      puVar14 = (ssc_u64_u *)(uintptr_t)((param_1 + (lVar21 + lVar18) * 4));
      if (((ssc_u64_u *)(uintptr_t)((param_1 + (lVar21 + lVar19) * 4)) <= puVar11) ||
         ((ssc_u64_u *)(uintptr_t)((param_1 + lVar19 * 4)) <= puVar14)) {
        uVar15 = uVar22 & 0xfffffffffffffffc;
        lVar18 = uVar15 + lVar18;
        iVar31 = iVar25 + (int)DAT_001027d0;
        iVar33 = iVar25 + (int)((ulong)DAT_001027d0 >> 0x20);
        iVar34 = iVar25 + (int)UNK_001027d8;
        iVar36 = iVar25 + (int)((ulong)UNK_001027d8 >> 0x20);
        uVar17 = uVar15;
        do {
          iVar37 = iVar31 - iVar25;
          iVar38 = iVar33 - iVar25;
          iVar39 = iVar34 - iVar25;
          iVar40 = iVar36 - iVar25;
          uVar29 = puVar11[1];
          uVar26 = *puVar11;
          uVar17 = uVar17 - 4;
          iVar31 = iVar31 + 4;
          iVar33 = iVar33 + 4;
          iVar34 = iVar34 + 4;
          iVar36 = iVar36 + 4;
          iVar37 = iVar37 * -0x30000 + 0x7fff0000;
          iVar38 = iVar38 * -0x30000 + 0x7fff0000;
          iVar39 = iVar39 * -0x30000 + 0x7fff0000;
          iVar40 = iVar40 * -0x30000 + 0x7fff0000;
          uVar24 = puVar14[1];
          uVar23 = *puVar14;
          iVar41 = iVar37 >> 0xf;
          iVar42 = iVar38 >> 0xf;
          iVar43 = iVar39 >> 0xf;
          iVar44 = iVar40 >> 0xf;
          iVar37 = iVar37 >> 0x10;
          iVar38 = iVar38 >> 0x10;
          iVar39 = iVar39 >> 0x10;
          iVar40 = iVar40 >> 0x10;
          puVar11[1] = CONCAT44(iVar44 * (int)((long)uVar29 >> 0x30) +
                                ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar29 >> 0x28),
                                                               CONCAT14((char)((ulong)uVar29 >> 0x20
                                                                              ),(uint)(ushort)uVar29
                                                                       )) >> 0x20) * iVar40) >> 0xf)
                                ,iVar43 * ((int)uVar29 >> 0x10) +
                                 ((int)((uint)(ushort)uVar29 * iVar39) >> 0xf));
          *puVar11 = CONCAT44(iVar42 * (int)((long)uVar26 >> 0x30) +
                              ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar26 >> 0x28),
                                                             CONCAT14((char)((ulong)uVar26 >> 0x20),
                                                                      (uint)(ushort)uVar26)) >> 0x20
                                                   ) * iVar38) >> 0xf),
                              iVar41 * ((int)uVar26 >> 0x10) +
                              ((int)((uint)(ushort)uVar26 * iVar37) >> 0xf));
          puVar14[1] = CONCAT44(iVar44 * (int)((long)uVar24 >> 0x30) +
                                ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar24 >> 0x28),
                                                               CONCAT14((char)((ulong)uVar24 >> 0x20
                                                                              ),(uint)(ushort)uVar24
                                                                       )) >> 0x20) * iVar40) >> 0xf)
                                ,iVar43 * ((int)uVar24 >> 0x10) +
                                 ((int)((uint)(ushort)uVar24 * iVar39) >> 0xf));
          *puVar14 = CONCAT44(iVar42 * (int)((long)uVar23 >> 0x30) +
                              ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar23 >> 0x28),
                                                             CONCAT14((char)((ulong)uVar23 >> 0x20),
                                                                      (uint)(ushort)uVar23)) >> 0x20
                                                   ) * iVar38) >> 0xf),
                              iVar41 * ((int)uVar23 >> 0x10) +
                              ((int)((uint)(ushort)uVar23 * iVar37) >> 0xf));
          puVar11 = puVar11 + 2;
          puVar14 = puVar14 + 2;
        } while (uVar17 != 0);
        if (uVar22 == uVar15) goto LAB_0010a4f8;
      }
    }
    iVar31 = (int)lVar18 * -0x30000 + param_3 * sVar5 * 0x30000 + 0x7fff0000;
    lVar19 = lVar19 - lVar18;
    puVar12 = (ssc_u32_u *)(uintptr_t)((param_1 + lVar18 * 4));
    puVar16 = (ssc_u32_u *)(uintptr_t)((param_1 + (lVar18 + lVar21) * 4));
    do {
      iVar33 = iVar31 >> 0x10;
      iVar34 = iVar31 >> 0xf;
      iVar31 = iVar31 + -0x30000;
      lVar19 = lVar19 + -1;
      *puVar12 = iVar34 * ((int)*puVar12 >> 0x10) + ((int)((*puVar12 & 0xffff) * iVar33) >> 0xf);
      *puVar16 = iVar34 * ((int)*puVar16 >> 0x10) + ((int)((*puVar16 & 0xffff) * iVar33) >> 0xf);
      puVar12 = puVar12 + 1;
      puVar16 = puVar16 + 1;
    } while (lVar19 != 0);
  }
LAB_0010a4f8:
  if (iVar28 < iVar27) {
    uVar8 = ((int)sVar7 - (int)sVar6) * param_3 + 0xe;
    uVar22 = (ulong)uVar8;
    lVar18 = (long)iVar28;
    if (2 < uVar8) {
      lVar19 = param_5 + lVar18;
      puVar11 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar18 * 4));
      puVar14 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar19 * 4));
      if (((ssc_u64_u *)(uintptr_t)((param_1 + (lVar19 + uVar22) * 4 + 4)) <= puVar11) ||
         ((ssc_u64_u *)(uintptr_t)((param_1 + (lVar18 + uVar22) * 4 + 4)) <= puVar14)) {
        iVar25 = (iVar30 - iVar25) * -3 + 0x7767;
        uVar15 = uVar22 + 1 & 0x1fffffffc;
        lVar18 = uVar15 + lVar18;
        iVar31 = iVar28 + (int)DAT_001027d0;
        iVar33 = iVar28 + (int)((ulong)DAT_001027d0 >> 0x20);
        iVar34 = iVar28 + (int)UNK_001027d8;
        iVar36 = iVar28 + (int)((ulong)UNK_001027d8 >> 0x20);
        uVar17 = uVar15;
        do {
          iVar37 = iVar31 - iVar28;
          iVar38 = iVar33 - iVar28;
          iVar39 = iVar34 - iVar28;
          iVar40 = iVar36 - iVar28;
          uVar29 = puVar14[1];
          uVar26 = *puVar14;
          uVar17 = uVar17 - 4;
          iVar31 = iVar31 + 4;
          iVar33 = iVar33 + 4;
          iVar34 = iVar34 + 4;
          iVar36 = iVar36 + 4;
          uVar24 = puVar11[1];
          uVar23 = *puVar11;
          iVar37 = (iVar25 + iVar37 * -5) * 0x10000;
          iVar38 = (iVar25 + iVar38 * -5) * 0x10000;
          iVar39 = (iVar25 + iVar39 * -5) * 0x10000;
          iVar40 = (iVar25 + iVar40 * -5) * 0x10000;
          iVar41 = iVar37 >> 0xf;
          iVar42 = iVar38 >> 0xf;
          iVar43 = iVar39 >> 0xf;
          iVar44 = iVar40 >> 0xf;
          iVar37 = iVar37 >> 0x10;
          iVar38 = iVar38 >> 0x10;
          iVar39 = iVar39 >> 0x10;
          iVar40 = iVar40 >> 0x10;
          puVar11[1] = CONCAT44(iVar44 * (int)((long)uVar24 >> 0x30) +
                                ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar24 >> 0x28),
                                                               CONCAT14((char)((ulong)uVar24 >> 0x20
                                                                              ),(uint)(ushort)uVar24
                                                                       )) >> 0x20) * iVar40) >> 0xf)
                                ,iVar43 * ((int)uVar24 >> 0x10) +
                                 ((int)((uint)(ushort)uVar24 * iVar39) >> 0xf));
          *puVar11 = CONCAT44(iVar42 * (int)((long)uVar23 >> 0x30) +
                              ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar23 >> 0x28),
                                                             CONCAT14((char)((ulong)uVar23 >> 0x20),
                                                                      (uint)(ushort)uVar23)) >> 0x20
                                                   ) * iVar38) >> 0xf),
                              iVar41 * ((int)uVar23 >> 0x10) +
                              ((int)((uint)(ushort)uVar23 * iVar37) >> 0xf));
          puVar14[1] = CONCAT44(iVar44 * (int)((long)uVar29 >> 0x30) +
                                ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar29 >> 0x28),
                                                               CONCAT14((char)((ulong)uVar29 >> 0x20
                                                                              ),(uint)(ushort)uVar29
                                                                       )) >> 0x20) * iVar40) >> 0xf)
                                ,iVar43 * ((int)uVar29 >> 0x10) +
                                 ((int)((uint)(ushort)uVar29 * iVar39) >> 0xf));
          *puVar14 = CONCAT44(iVar42 * (int)((long)uVar26 >> 0x30) +
                              ((int)((uint)(ushort)(CONCAT15((char)((ulong)uVar26 >> 0x28),
                                                             CONCAT14((char)((ulong)uVar26 >> 0x20),
                                                                      (uint)(ushort)uVar26)) >> 0x20
                                                   ) * iVar38) >> 0xf),
                              iVar41 * ((int)uVar26 >> 0x10) +
                              ((int)((uint)(ushort)uVar26 * iVar37) >> 0xf));
          puVar11 = puVar11 + 2;
          puVar14 = puVar14 + 2;
        } while (uVar17 != 0);
        if (uVar22 + 1 == uVar15) {
          return;
        }
      }
    }
    iVar27 = iVar27 - (int)lVar18;
    iVar25 = (iVar30 * -3 + param_3 * (sVar6 * 5 + sVar5 * 3) + (int)lVar18 * -5) * 0x10000 +
             0x771c0000;
    puVar12 = (ssc_u32_u *)(uintptr_t)((param_1 + (lVar18 + param_5) * 4));
    puVar16 = (ssc_u32_u *)(uintptr_t)((param_1 + lVar18 * 4));
    do {
      iVar28 = iVar25 >> 0x10;
      iVar30 = iVar25 >> 0xf;
      iVar25 = iVar25 + -0x50000;
      iVar27 = iVar27 + -1;
      *puVar16 = iVar30 * ((int)*puVar16 >> 0x10) + ((int)((*puVar16 & 0xffff) * iVar28) >> 0xf);
      *puVar12 = iVar30 * ((int)*puVar12 >> 0x10) + ((int)((*puVar12 & 0xffff) * iVar28) >> 0xf);
      puVar12 = puVar12 + 1;
      puVar16 = puVar16 + 1;
    } while (iVar27 != 0);
  }
  return;
}


/* ==================================================================== */
/* Function: uhq_headroom @ 0010a844 */
/* ==================================================================== */

void uhq_headroom(long param_1,int param_2,int param_3,long param_4)

{
  ssc_u32_u *puVar1;
  long lVar2;
  ssc_u64_u *puVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;

  param_3 = *(ssc_i16_u *)(uintptr_t)((param_4 + 0x24)) * param_3;
  lVar5 = (long)param_3;
  lVar4 = lVar5 + 0x19;
  lVar2 = lVar4;
  if (lVar4 < lVar5 + 1) {
    lVar2 = lVar5 + 1;
  }
  uVar6 = lVar2 - lVar5;
  if (269999 < param_2) {
    if (uVar6 < 4) {
LAB_0010ab80:
      do {
        puVar1 = (ssc_u32_u *)(uintptr_t)((param_1 + lVar5 * 4));
        lVar5 = lVar5 + 1;
        *puVar1 = ((int)*puVar1 >> 0x10) * 0xf190 + ((*puVar1 & 0xffff) * 0x78c8 >> 0xf);
        puVar1[0x360] =
             ((int)puVar1[0x360] >> 0x10) * 0xf190 + ((puVar1[0x360] & 0xffff) * 0x78c8 >> 0xf);
      } while (lVar5 < lVar4);
    }
    else {
      uVar8 = uVar6 & 0xfffffffffffffffc;
      puVar3 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar5 * 4));
      lVar5 = uVar8 + lVar5;
      uVar7 = uVar8;
      do {
        uVar10 = puVar3[1];
        uVar9 = *puVar3;
        uVar7 = uVar7 - 4;
        uVar12 = puVar3[0x1b1];
        uVar11 = puVar3[0x1b0];
        puVar3[1] = CONCAT44((int)((long)uVar10 >> 0x30) * 0xf190 +
                             ((uint)(ushort)(CONCAT15((char)((ulong)uVar10 >> 0x28),
                                                      CONCAT14((char)((ulong)uVar10 >> 0x20),
                                                               (uint)(ushort)uVar10)) >> 0x20) *
                              0x78c8 >> 0xf),
                             ((int)uVar10 >> 0x10) * 0xf190 + ((uint)(ushort)uVar10 * 0x78c8 >> 0xf)
                            );
        *puVar3 = CONCAT44((int)((long)uVar9 >> 0x30) * 0xf190 +
                           ((uint)(ushort)(CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                    CONCAT14((char)((ulong)uVar9 >> 0x20),
                                                             (uint)(ushort)uVar9)) >> 0x20) * 0x78c8
                           >> 0xf),((int)uVar9 >> 0x10) * 0xf190 +
                                   ((uint)(ushort)uVar9 * 0x78c8 >> 0xf));
        puVar3[0x1b1] =
             CONCAT44((int)((long)uVar12 >> 0x30) * 0xf190 +
                      ((uint)(ushort)(CONCAT15((char)((ulong)uVar12 >> 0x28),
                                               CONCAT14((char)((ulong)uVar12 >> 0x20),
                                                        (uint)(ushort)uVar12)) >> 0x20) * 0x78c8 >>
                      0xf),((int)uVar12 >> 0x10) * 0xf190 + ((uint)(ushort)uVar12 * 0x78c8 >> 0xf));
        puVar3[0x1b0] =
             CONCAT44((int)((long)uVar11 >> 0x30) * 0xf190 +
                      ((uint)(ushort)(CONCAT15((char)((ulong)uVar11 >> 0x28),
                                               CONCAT14((char)((ulong)uVar11 >> 0x20),
                                                        (uint)(ushort)uVar11)) >> 0x20) * 0x78c8 >>
                      0xf),((int)uVar11 >> 0x10) * 0xf190 + ((uint)(ushort)uVar11 * 0x78c8 >> 0xf));
        puVar3 = puVar3 + 2;
      } while (uVar7 != 0);
      if (uVar6 != uVar8) goto LAB_0010ab80;
    }
    if (param_3 < 0x149) {
      lVar5 = lVar4;
      if (2 < 0x148U - param_3) {
        uVar6 = (ulong)(0x148U - param_3) + 1;
        uVar8 = uVar6 & 0x1fffffffc;
        lVar5 = uVar8 + lVar4;
        puVar3 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar4 * 4));
        uVar7 = uVar8;
        do {
          uVar10 = puVar3[1];
          uVar9 = *puVar3;
          uVar7 = uVar7 - 4;
          uVar12 = puVar3[0x1b1];
          uVar11 = puVar3[0x1b0];
          puVar3[1] = CONCAT44((int)((long)uVar10 >> 0x30) * 0xf0c8 +
                               ((uint)(ushort)(CONCAT15((char)((ulong)uVar10 >> 0x28),
                                                        CONCAT14((char)((ulong)uVar10 >> 0x20),
                                                                 (uint)(ushort)uVar10)) >> 0x20) *
                                0x7864 >> 0xf),
                               ((int)uVar10 >> 0x10) * 0xf0c8 +
                               ((uint)(ushort)uVar10 * 0x7864 >> 0xf));
          *puVar3 = CONCAT44((int)((long)uVar9 >> 0x30) * 0xf0c8 +
                             ((uint)(ushort)(CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                      CONCAT14((char)((ulong)uVar9 >> 0x20),
                                                               (uint)(ushort)uVar9)) >> 0x20) *
                              0x7864 >> 0xf),
                             ((int)uVar9 >> 0x10) * 0xf0c8 + ((uint)(ushort)uVar9 * 0x7864 >> 0xf));
          puVar3[0x1b1] =
               CONCAT44((int)((long)uVar12 >> 0x30) * 0xf0c8 +
                        ((uint)(ushort)(CONCAT15((char)((ulong)uVar12 >> 0x28),
                                                 CONCAT14((char)((ulong)uVar12 >> 0x20),
                                                          (uint)(ushort)uVar12)) >> 0x20) * 0x7864
                        >> 0xf),((int)uVar12 >> 0x10) * 0xf0c8 +
                                ((uint)(ushort)uVar12 * 0x7864 >> 0xf));
          puVar3[0x1b0] =
               CONCAT44((int)((long)uVar11 >> 0x30) * 0xf0c8 +
                        ((uint)(ushort)(CONCAT15((char)((ulong)uVar11 >> 0x28),
                                                 CONCAT14((char)((ulong)uVar11 >> 0x20),
                                                          (uint)(ushort)uVar11)) >> 0x20) * 0x7864
                        >> 0xf),((int)uVar11 >> 0x10) * 0xf0c8 +
                                ((uint)(ushort)uVar11 * 0x7864 >> 0xf));
          puVar3 = puVar3 + 2;
        } while (uVar7 != 0);
        if (uVar6 == uVar8) goto LAB_0010aca4;
      }
      do {
        puVar1 = (ssc_u32_u *)(uintptr_t)((param_1 + lVar5 * 4));
        lVar5 = lVar5 + 1;
        *puVar1 = ((int)*puVar1 >> 0x10) * 0xf0c8 + ((*puVar1 & 0xffff) * 0x7864 >> 0xf);
        puVar1[0x360] =
             ((int)puVar1[0x360] >> 0x10) * 0xf0c8 + ((puVar1[0x360] & 0xffff) * 0x7864 >> 0xf);
      } while ((int)lVar5 != 0x162);
    }
LAB_0010aca4:
    puVar3 = (ssc_u64_u *)(uintptr_t)((param_1 + 0x588));
    lVar4 = 0x2c;
    do {
      uVar10 = puVar3[1];
      uVar9 = *puVar3;
      lVar4 = lVar4 + -4;
      uVar12 = puVar3[0x1b1];
      uVar11 = puVar3[0x1b0];
      puVar3[1] = CONCAT44((int)((long)uVar10 >> 0x30) * 0xf000 +
                           ((uint)(ushort)(CONCAT15((char)((ulong)uVar10 >> 0x28),
                                                    CONCAT14((char)((ulong)uVar10 >> 0x20),
                                                             (uint)(ushort)uVar10)) >> 0x20) *
                            0x7800 >> 0xf),
                           ((int)uVar10 >> 0x10) * 0xf000 + ((uint)(ushort)uVar10 * 0x7800 >> 0xf));
      *puVar3 = CONCAT44((int)((long)uVar9 >> 0x30) * 0xf000 +
                         ((uint)(ushort)(CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                  CONCAT14((char)((ulong)uVar9 >> 0x20),
                                                           (uint)(ushort)uVar9)) >> 0x20) * 0x7800
                         >> 0xf),((int)uVar9 >> 0x10) * 0xf000 +
                                 ((uint)(ushort)uVar9 * 0x7800 >> 0xf));
      puVar3[0x1b1] =
           CONCAT44((int)((long)uVar12 >> 0x30) * 0xf000 +
                    ((uint)(ushort)(CONCAT15((char)((ulong)uVar12 >> 0x28),
                                             CONCAT14((char)((ulong)uVar12 >> 0x20),
                                                      (uint)(ushort)uVar12)) >> 0x20) * 0x7800 >>
                    0xf),((int)uVar12 >> 0x10) * 0xf000 + ((uint)(ushort)uVar12 * 0x7800 >> 0xf));
      puVar3[0x1b0] =
           CONCAT44((int)((long)uVar11 >> 0x30) * 0xf000 +
                    ((uint)(ushort)(CONCAT15((char)((ulong)uVar11 >> 0x28),
                                             CONCAT14((char)((ulong)uVar11 >> 0x20),
                                                      (uint)(ushort)uVar11)) >> 0x20) * 0x7800 >>
                    0xf),((int)uVar11 >> 0x10) * 0xf000 + ((uint)(ushort)uVar11 * 0x7800 >> 0xf));
      puVar3 = puVar3 + 2;
    } while (lVar4 != 0);
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x638)) =
         ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0x638)) >> 0x10) * 0xf000 +
         ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0x638)) & 0xffff) * 0x7800 >> 0xf);
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x13b8)) =
         ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0x13b8)) >> 0x10) * 0xf000 +
         ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0x13b8)) & 0xffff) * 0x7800 >> 0xf);
    lVar4 = 0x640;
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x63c)) =
         ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0x63c)) >> 0x10) * 0xf000 +
         ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0x63c)) & 0xffff) * 0x7800 >> 0xf);
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x13bc)) =
         ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0x13bc)) >> 0x10) * 0xf000 +
         ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0x13bc)) & 0xffff) * 0x7800 >> 0xf);
    do {
      puVar3 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar4));
      lVar4 = lVar4 + 0x10;
      uVar10 = puVar3[1];
      uVar9 = *puVar3;
      uVar12 = puVar3[0x1b1];
      uVar11 = puVar3[0x1b0];
      puVar3[1] = CONCAT44((int)((long)uVar10 >> 0x30) * 0xef38 +
                           ((uint)(ushort)(CONCAT15((char)((ulong)uVar10 >> 0x28),
                                                    CONCAT14((char)((ulong)uVar10 >> 0x20),
                                                             (uint)(ushort)uVar10)) >> 0x20) *
                            0x779c >> 0xf),
                           ((int)uVar10 >> 0x10) * 0xef38 + ((uint)(ushort)uVar10 * 0x779c >> 0xf));
      *puVar3 = CONCAT44((int)((long)uVar9 >> 0x30) * 0xef38 +
                         ((uint)(ushort)(CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                  CONCAT14((char)((ulong)uVar9 >> 0x20),
                                                           (uint)(ushort)uVar9)) >> 0x20) * 0x779c
                         >> 0xf),((int)uVar9 >> 0x10) * 0xef38 +
                                 ((uint)(ushort)uVar9 * 0x779c >> 0xf));
      puVar3[0x1b1] =
           CONCAT44((int)((long)uVar12 >> 0x30) * 0xef38 +
                    ((uint)(ushort)(CONCAT15((char)((ulong)uVar12 >> 0x28),
                                             CONCAT14((char)((ulong)uVar12 >> 0x20),
                                                      (uint)(ushort)uVar12)) >> 0x20) * 0x779c >>
                    0xf),((int)uVar12 >> 0x10) * 0xef38 + ((uint)(ushort)uVar12 * 0x779c >> 0xf));
      puVar3[0x1b0] =
           CONCAT44((int)((long)uVar11 >> 0x30) * 0xef38 +
                    ((uint)(ushort)(CONCAT15((char)((ulong)uVar11 >> 0x28),
                                             CONCAT14((char)((ulong)uVar11 >> 0x20),
                                                      (uint)(ushort)uVar11)) >> 0x20) * 0x779c >>
                    0xf),((int)uVar11 >> 0x10) * 0xef38 + ((uint)(ushort)uVar11 * 0x779c >> 0xf));
    } while (lVar4 != 0xd80);
    return;
  }
  if (uVar6 < 4) {
LAB_0010a8fc:
    do {
      puVar1 = (ssc_u32_u *)(uintptr_t)((param_1 + lVar5 * 4));
      lVar5 = lVar5 + 1;
      *puVar1 = ((int)*puVar1 >> 0x10) * 0xf190 + ((*puVar1 & 0xffff) * 0x78c8 >> 0xf);
      puVar1[0x360] =
           ((int)puVar1[0x360] >> 0x10) * 0xf190 + ((puVar1[0x360] & 0xffff) * 0x78c8 >> 0xf);
    } while (lVar5 < lVar4);
  }
  else {
    uVar8 = uVar6 & 0xfffffffffffffffc;
    puVar3 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar5 * 4));
    lVar5 = uVar8 + lVar5;
    uVar7 = uVar8;
    do {
      uVar10 = puVar3[1];
      uVar9 = *puVar3;
      uVar7 = uVar7 - 4;
      uVar12 = puVar3[0x1b1];
      uVar11 = puVar3[0x1b0];
      puVar3[1] = CONCAT44((int)((long)uVar10 >> 0x30) * 0xf190 +
                           ((uint)(ushort)(CONCAT15((char)((ulong)uVar10 >> 0x28),
                                                    CONCAT14((char)((ulong)uVar10 >> 0x20),
                                                             (uint)(ushort)uVar10)) >> 0x20) *
                            0x78c8 >> 0xf),
                           ((int)uVar10 >> 0x10) * 0xf190 + ((uint)(ushort)uVar10 * 0x78c8 >> 0xf));
      *puVar3 = CONCAT44((int)((long)uVar9 >> 0x30) * 0xf190 +
                         ((uint)(ushort)(CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                  CONCAT14((char)((ulong)uVar9 >> 0x20),
                                                           (uint)(ushort)uVar9)) >> 0x20) * 0x78c8
                         >> 0xf),((int)uVar9 >> 0x10) * 0xf190 +
                                 ((uint)(ushort)uVar9 * 0x78c8 >> 0xf));
      puVar3[0x1b1] =
           CONCAT44((int)((long)uVar12 >> 0x30) * 0xf190 +
                    ((uint)(ushort)(CONCAT15((char)((ulong)uVar12 >> 0x28),
                                             CONCAT14((char)((ulong)uVar12 >> 0x20),
                                                      (uint)(ushort)uVar12)) >> 0x20) * 0x78c8 >>
                    0xf),((int)uVar12 >> 0x10) * 0xf190 + ((uint)(ushort)uVar12 * 0x78c8 >> 0xf));
      puVar3[0x1b0] =
           CONCAT44((int)((long)uVar11 >> 0x30) * 0xf190 +
                    ((uint)(ushort)(CONCAT15((char)((ulong)uVar11 >> 0x28),
                                             CONCAT14((char)((ulong)uVar11 >> 0x20),
                                                      (uint)(ushort)uVar11)) >> 0x20) * 0x78c8 >>
                    0xf),((int)uVar11 >> 0x10) * 0xf190 + ((uint)(ushort)uVar11 * 0x78c8 >> 0xf));
      puVar3 = puVar3 + 2;
    } while (uVar7 != 0);
    if (uVar6 != uVar8) goto LAB_0010a8fc;
  }
  if (param_3 < 0x145) {
    lVar5 = lVar4;
    if (2 < 0x144U - param_3) {
      uVar6 = (ulong)(0x144U - param_3) + 1;
      uVar8 = uVar6 & 0x1fffffffc;
      lVar5 = uVar8 + lVar4;
      puVar3 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar4 * 4));
      uVar7 = uVar8;
      do {
        uVar10 = puVar3[1];
        uVar9 = *puVar3;
        uVar7 = uVar7 - 4;
        uVar12 = puVar3[0x1b1];
        uVar11 = puVar3[0x1b0];
        puVar3[1] = CONCAT44((int)((long)uVar10 >> 0x30) * 0xf03c +
                             ((uint)(ushort)(CONCAT15((char)((ulong)uVar10 >> 0x28),
                                                      CONCAT14((char)((ulong)uVar10 >> 0x20),
                                                               (uint)(ushort)uVar10)) >> 0x20) *
                              0x781e >> 0xf),
                             ((int)uVar10 >> 0x10) * 0xf03c + ((uint)(ushort)uVar10 * 0x781e >> 0xf)
                            );
        *puVar3 = CONCAT44((int)((long)uVar9 >> 0x30) * 0xf03c +
                           ((uint)(ushort)(CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                    CONCAT14((char)((ulong)uVar9 >> 0x20),
                                                             (uint)(ushort)uVar9)) >> 0x20) * 0x781e
                           >> 0xf),((int)uVar9 >> 0x10) * 0xf03c +
                                   ((uint)(ushort)uVar9 * 0x781e >> 0xf));
        puVar3[0x1b1] =
             CONCAT44((int)((long)uVar12 >> 0x30) * 0xf03c +
                      ((uint)(ushort)(CONCAT15((char)((ulong)uVar12 >> 0x28),
                                               CONCAT14((char)((ulong)uVar12 >> 0x20),
                                                        (uint)(ushort)uVar12)) >> 0x20) * 0x781e >>
                      0xf),((int)uVar12 >> 0x10) * 0xf03c + ((uint)(ushort)uVar12 * 0x781e >> 0xf));
        puVar3[0x1b0] =
             CONCAT44((int)((long)uVar11 >> 0x30) * 0xf03c +
                      ((uint)(ushort)(CONCAT15((char)((ulong)uVar11 >> 0x28),
                                               CONCAT14((char)((ulong)uVar11 >> 0x20),
                                                        (uint)(ushort)uVar11)) >> 0x20) * 0x781e >>
                      0xf),((int)uVar11 >> 0x10) * 0xf03c + ((uint)(ushort)uVar11 * 0x781e >> 0xf));
        puVar3 = puVar3 + 2;
      } while (uVar7 != 0);
      if (uVar6 == uVar8) goto LAB_0010aa20;
    }
    do {
      puVar1 = (ssc_u32_u *)(uintptr_t)((param_1 + lVar5 * 4));
      lVar5 = lVar5 + 1;
      *puVar1 = ((int)*puVar1 >> 0x10) * 0xf03c + ((*puVar1 & 0xffff) * 0x781e >> 0xf);
      puVar1[0x360] =
           ((int)puVar1[0x360] >> 0x10) * 0xf03c + ((puVar1[0x360] & 0xffff) * 0x781e >> 0xf);
    } while ((int)lVar5 != 0x15e);
  }
LAB_0010aa20:
  puVar3 = (ssc_u64_u *)(uintptr_t)((param_1 + 0x578));
  lVar4 = 0x200;
  do {
    uVar10 = puVar3[1];
    uVar9 = *puVar3;
    lVar4 = lVar4 + -4;
    uVar12 = puVar3[0x1b1];
    uVar11 = puVar3[0x1b0];
    puVar3[1] = CONCAT44((int)((long)uVar10 >> 0x30) * 0xef38 +
                         ((uint)(ushort)(CONCAT15((char)((ulong)uVar10 >> 0x28),
                                                  CONCAT14((char)((ulong)uVar10 >> 0x20),
                                                           (uint)(ushort)uVar10)) >> 0x20) * 0x779c
                         >> 0xf),((int)uVar10 >> 0x10) * 0xef38 +
                                 ((uint)(ushort)uVar10 * 0x779c >> 0xf));
    *puVar3 = CONCAT44((int)((long)uVar9 >> 0x30) * 0xef38 +
                       ((uint)(ushort)(CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                CONCAT14((char)((ulong)uVar9 >> 0x20),
                                                         (uint)(ushort)uVar9)) >> 0x20) * 0x779c >>
                       0xf),((int)uVar9 >> 0x10) * 0xef38 + ((uint)(ushort)uVar9 * 0x779c >> 0xf));
    puVar3[0x1b1] =
         CONCAT44((int)((long)uVar12 >> 0x30) * 0xef38 +
                  ((uint)(ushort)(CONCAT15((char)((ulong)uVar12 >> 0x28),
                                           CONCAT14((char)((ulong)uVar12 >> 0x20),
                                                    (uint)(ushort)uVar12)) >> 0x20) * 0x779c >> 0xf)
                  ,((int)uVar12 >> 0x10) * 0xef38 + ((uint)(ushort)uVar12 * 0x779c >> 0xf));
    puVar3[0x1b0] =
         CONCAT44((int)((long)uVar11 >> 0x30) * 0xef38 +
                  ((uint)(ushort)(CONCAT15((char)((ulong)uVar11 >> 0x28),
                                           CONCAT14((char)((ulong)uVar11 >> 0x20),
                                                    (uint)(ushort)uVar11)) >> 0x20) * 0x779c >> 0xf)
                  ,((int)uVar11 >> 0x10) * 0xef38 + ((uint)(ushort)uVar11 * 0x779c >> 0xf));
    puVar3 = puVar3 + 2;
  } while (lVar4 != 0);
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0xd78)) =
       ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0xd78)) >> 0x10) * 0xef38 +
       ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0xd78)) & 0xffff) * 0x779c >> 0xf);
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0x1af8)) =
       ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0x1af8)) >> 0x10) * 0xef38 +
       ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0x1af8)) & 0xffff) * 0x779c >> 0xf);
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0xd7c)) =
       ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0xd7c)) >> 0x10) * 0xef38 +
       ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0xd7c)) & 0xffff) * 0x779c >> 0xf);
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0x1afc)) =
       ((int)*(ssc_u32_u *)(uintptr_t)((param_1 + 0x1afc)) >> 0x10) * 0xef38 +
       ((*(ssc_u32_u *)(uintptr_t)((param_1 + 0x1afc)) & 0xffff) * 0x779c >> 0xf);
  return;
}


/* ==================================================================== */
/* headroom_process removed */

/* Function: ssc_preemphasis @ 0010ade4 */
/* ==================================================================== */

void ssc_preemphasis(ssc_i32_u *param_1,ssc_i32_u *param_2,int param_3,undefined8 param_4,int param_5)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  vec128_t auVar4;
  ssc_i32_u *piVar5;
  uint uVar6;
  long lVar7;
  ssc_i32_u *piVar8;
  ssc_i32_u *piVar9;
  vec128_t auVar10;
  vec128_t auVar11;
  vec128_t auVar12;

  uVar6 = 0xc;
  if (param_5 != 0) {
    uVar6 = 4;
  }
  uVar3 = param_3 - 1;
  piVar5 = param_1;
  if ((7 < uVar3) &&
     ((param_1 + (ulong)uVar3 * 2 + 1 <= param_2 || (param_2 + (ulong)uVar3 + 1 <= param_1)))) {
    uVar1 = (ulong)uVar3 + 1;
    uVar2 = 8;
    if ((uVar1 & 7) != 0) {
      uVar2 = uVar1 & 7;
    }
    lVar7 = uVar1 - uVar2;
    piVar9 = param_2 + 4;
    param_3 = param_3 - (int)lVar7;
    param_2 = param_2 + lVar7;
    piVar5 = param_1 + lVar7 * 2;
    piVar8 = param_1 + 8;
    do {
      auVar10._0_4_ = *piVar8;
      auVar10._4_4_ = piVar8[2];
      auVar10._8_4_ = piVar8[4];
      auVar10._12_4_ = piVar8[6];
      lVar7 = lVar7 + -8;
      auVar11._4_4_ = uVar6;
      auVar11._0_4_ = uVar6;
      auVar11._8_4_ = uVar6;
      auVar11._12_4_ = uVar6;
      auVar11 = NEON_ushl(auVar10,auVar11,4);
      auVar12._4_4_ = uVar6;
      auVar12._0_4_ = uVar6;
      auVar12._8_4_ = uVar6;
      auVar12._12_4_ = uVar6;
      auVar4._4_4_ = piVar8[-6];
      auVar4._0_4_ = piVar8[-8];
      auVar4._8_4_ = piVar8[-4];
      auVar4._12_4_ = piVar8[-2];
      auVar12 = NEON_ushl(auVar4,auVar12,4);
      *(ssc_i64_u *)(piVar9 + -2) = auVar12._8_8_;
      *(ssc_i64_u *)(piVar9 + -4) = auVar12._0_8_;
      *(ssc_i64_u *)(piVar9 + 2) = auVar11._8_8_;
      *(ssc_i64_u *)piVar9 = auVar11._0_8_;
      piVar9 = piVar9 + 8;
      piVar8 = piVar8 + 0x10;
    } while (lVar7 != 0);
  }
  do {
    param_3 = param_3 + -1;
    *param_2 = *piVar5 << (ulong)uVar6;
    piVar5 = piVar5 + 2;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}


/* ==================================================================== */
/* Function: getPitchIndexGain @ 0010ae98 */
/* ==================================================================== */

uint getPitchIndexGain(long param_1,long param_2,ssc_i32_u *param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  short sVar2;
  uint uVar3;

  if (param_5 == 0) {
    uVar3 = 0;
    *param_3 = 0xf;
  }
  else {
    ssc_pitch_downsample((ssc_i32_u *)(PTR__pre_shared_0011bce0), (ssc_i32_u *)(PTR__pre_shared_0011bce0 + ((long)param_4 + 0x400) * 4), (ssc_i16_u *)(uintptr_t)((uintptr_t)param_2), param_4 + 0x400);
    ssc_pitch_search((ssc_u16_u *)(uintptr_t)(param_2 + 0x400),(ssc_u16_u *)(uintptr_t)(param_2),param_4,0x3d3,param_3);
    uVar1 = *(ssc_u16_u *)(uintptr_t)((param_1 + 0x3c));
    *param_3 = 0x400 - *param_3;
    sVar2 = ssc_remove_doubling(param_2,0x400,0xf,param_4,(ssc_u32_u *)(param_3),*(ssc_u32_u *)(uintptr_t)((param_1 + 0x38)),
                                uVar1);
    if (0x3fe < *param_3) {
      *param_3 = 0x3fe;
    }
    uVar3 = (uint)(sVar2 * 0x599a) >> 0xf;
  }
  return uVar3;
}


/* ==================================================================== */
/* Function: getPitchFilterThreshold @ 0010af64 */
/* ==================================================================== */

uint getPitchFilterThreshold(long param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;

  iVar4 = param_2 - *(ssc_i32_u *)(uintptr_t)((param_1 + 0x38));
  iVar1 = -iVar4;
  if (-1 < iVar4) {
    iVar1 = iVar4;
  }
  uVar3 = 0x3334;
  if (iVar1 * 10 <= param_2) {
    uVar3 = 0x199a;
  }
  uVar2 = uVar3 + 0xccd;
  if (0x22 < param_3) {
    uVar2 = uVar3;
  }
  uVar3 = uVar3 + 0x199a;
  if (0x18 < param_3) {
    uVar3 = uVar2;
  }
  uVar2 = uVar3 - 0xccd;
  if (*(ssc_i16_u *)(uintptr_t)((param_1 + 0x3c)) < 0x3334) {
    uVar2 = uVar3;
  }
  uVar3 = uVar3 - 0x199a;
  if (*(ssc_i16_u *)(uintptr_t)((param_1 + 0x3c)) < 0x4667) {
    uVar3 = uVar2;
  }
  if ((uVar3 & 0xffff) < 0x199b) {
    uVar3 = 0x199a;
  }
  return uVar3;
}


/* ==================================================================== */
/* Function: prefilter_gain_calculation @ 0010afd4 */
/* ==================================================================== */

undefined8 prefilter_gain_calculation(short param_1,short param_2,ssc_i32_u *param_3,ssc_i16_u *param_4)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;

  sVar2 = *param_4;
  if (param_2 <= sVar2) {
    uVar4 = (int)sVar2 - (int)param_1;
    uVar3 = -uVar4;
    if (-1 < (int)uVar4) {
      uVar3 = uVar4;
    }
    iVar5 = (int)param_1;
    if (0xccc < uVar3) {
      iVar5 = (int)sVar2;
      param_1 = sVar2;
    }
    uVar3 = (iVar5 + 0x600 >> 10) * 0x56;
    iVar5 = (int)(char)(((byte)(uVar3 >> 0xf) & 1) + (char)(uVar3 >> 8) + -1);
    if (6 < iVar5) {
      iVar5 = 7;
    }
    iVar1 = 0;
    if (0x5ff < param_1) {
      iVar1 = iVar5;
    }
    *param_3 = iVar1;
    *param_4 = (short)iVar1 * 0xc00 + 0xc00;
    return 1;
  }
  *param_3 = 0;
  *param_4 = 0;
  return 0;
}


/* ==================================================================== */
/* Function: last_band_info_calc @ 0010b05c */
/* ==================================================================== */

ulong last_band_info_calc(int param_1,uint param_2,long param_3)

{
  ulong uVar1;
  int iVar2;

  if ((int)param_2 < 1) {
    return 0;
  }
  uVar1 = (ulong)param_2;
  iVar2 = param_2 << 1;
  do {
    if (param_1 < *(ssc_i32_u *)(uintptr_t)((param_3 + (long)(iVar2 + -1) * 4)) +
                  *(ssc_i32_u *)(uintptr_t)((param_3 + (long)((int)uVar1 + -1) * 4)) >> 1) {
      return uVar1;
    }
    uVar1 = uVar1 - 1;
    iVar2 = iVar2 + -1;
  } while (uVar1 != 0);
  return 0;
}


/* ==================================================================== */
/* Function: get_header_from_bitrate @ 0010b0a4 */
/* ==================================================================== */

undefined8 get_header_from_bitrate(int param_1)

{
  if (param_1 < 0x3e800) {
    if (param_1 < 0x251c0) {
      if (param_1 == 88000) {
        return 0xf0;
      }
      if (param_1 == 96000) {
        return 0xf1;
      }
      if (param_1 == 0x1f400) {
        return 0xf2;
      }
    }
    else if (param_1 < 0x37e88) {
      if (param_1 == 0x251c0) {
        return 0xe6;
      }
    }
    else {
      if (param_1 == 0x37e88) {
        return 0xf4;
      }
      if (param_1 == 250000) {
        return 0xe5;
      }
    }
  }
  else if (param_1 < 0x50140) {
    if (param_1 == 0x3e800) {
      return 0xf6;
    }
    if (param_1 == 0x470b8) {
      return 0xe0;
    }
    if (param_1 == 0x4b320) {
      return 0xe1;
    }
  }
  else if (param_1 < 0x8e940) {
    if (param_1 == 0x50140) {
      return 0xf5;
    }
    if (param_1 == 0x6be90) {
      return 0xe2;
    }
  }
  else {
    if (param_1 == 0x8e940) {
      return 0xe3;
    }
    if (param_1 == 0xd84f0) {
      return 0xe4;
    }
  }
  return 0xf3;
}


/* ==================================================================== */
/* Function: set_limit_gain_from_bitrate @ 0010b240 */
/* ==================================================================== */

void set_limit_gain_from_bitrate(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;

  uVar2 = 0x79f800;
  if (249999 < param_1) {
    if (param_1 < 0x6be90) {
      if (param_1 == 250000) goto LAB_0010b384;
      if ((param_1 == 0x470b8) || (param_1 == 0x4b320)) goto LAB_0010b364;
    }
    else if (((param_1 == 0x6be90) || (param_1 == 0x8e940)) || (param_1 == 0xd84f0)) {
LAB_0010b364:
      set_DRC_limit_gain(0x7b4c00);
      return;
    }
    return;
  }
  if (param_1 < 0x251c0) {
    if ((param_1 == 88000) || (param_1 == 96000)) {
      uVar1 = 0x76f2;
      uVar2 = 0x76f200;
    }
    else {
      if (param_1 != 0x1f400) {
        return;
      }
      uVar1 = 0x78b4;
      uVar2 = 0x78b400;
    }
  }
  else {
    if (param_1 == 0x251c0) goto LAB_0010b384;
    if ((param_1 != 0x2ee00) && (param_1 != 0x37e88)) {
      return;
    }
    uVar1 = 0x7a94;
    uVar2 = 0x7a9400;
  }
  if (param_2 != 0x18) {
    uVar2 = uVar1;
  }
LAB_0010b384:
  set_DRC_limit_gain(uVar2);
  return;
}


/* ==================================================================== */
/* Function: get_uhq_info_from_bitrate @ 0010b390 */
/* ==================================================================== */

void get_uhq_info_from_bitrate(int param_1,ssc_u32_u *param_2,ssc_u32_u *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;

  uVar1 = 0;
  if (param_1 < 0x3e800) {
    if (param_1 < 0x251c0) {
      if (((param_1 == 88000) || (param_1 == 96000)) || (param_1 == 0x1f400)) {
LAB_0010b3e4:
        *param_3 = 0;
        return;
      }
    }
    else {
      if (0x37e87 < param_1) {
        if (param_1 == 0x37e88) goto LAB_0010b3e4;
        iVar2 = 250000;
        goto LAB_0010b4c0;
      }
      if (param_1 == 0x251c0) goto LAB_0010b4c8;
      if (param_1 == 0x2ee00) goto LAB_0010b3e4;
    }
LAB_0010b4dc:
    uVar3 = 0;
    uVar1 = 0;
  }
  else {
    uVar3 = 1;
    if (param_1 < 0x50140) {
      if (param_1 == 0x3e800) goto LAB_0010b4d0;
      if (param_1 == 0x470b8) goto LAB_0010b4c8;
      iVar2 = 0x4b320;
LAB_0010b4c0:
      if (param_1 != iVar2) goto LAB_0010b4dc;
    }
    else {
      if (param_1 < 0x8e940) {
        if (param_1 == 0x50140) goto LAB_0010b4d0;
        iVar2 = 0x6be90;
        goto LAB_0010b4c0;
      }
      if (param_1 != 0xd84f0) {
        iVar2 = 0x8e940;
        goto LAB_0010b4c0;
      }
    }
LAB_0010b4c8:
    uVar3 = 1;
    uVar1 = 1;
  }
LAB_0010b4d0:
  *param_2 = uVar3;
  *param_3 = uVar1;
  return;
}


/* ==================================================================== */
/* Function: set_data_header @ 0010b4e8 */
/* ==================================================================== */

void set_data_header(long param_1,undefined1 param_2,uint param_3,int param_4)

{
  *(undefined1 *)(uintptr_t)((param_1 + 3)) = param_2;
  if (param_4 == 1) {
    *(byte *)(uintptr_t)((param_1 + 1)) = (byte)(param_3 >> 4) & 0xf | 0xe0;
  }
  return;
}


/* ==================================================================== */
/* Function: set_data_frame_header @ 0010b504 */
/* ==================================================================== */

void set_data_frame_header
               (ssc_u16_u *param_1,int param_2,undefined8 param_3,uint param_4,byte param_5,
               int param_6)

{
  undefined1 uVar1;

  *param_1 = 0xeeff;
  *(byte *)(param_1 + 1) = param_5 & 3 | (byte)(param_4 << 4);
  if (param_2 < 0x3e800) {
    if (param_2 < 0x251c0) {
      if (param_2 == 88000) {
        uVar1 = 0xf0;
        goto LAB_0010b6b0;
      }
      if (param_2 == 96000) {
        uVar1 = 0xf1;
        goto LAB_0010b6b0;
      }
      if (param_2 == 0x1f400) {
        uVar1 = 0xf2;
        goto LAB_0010b6b0;
      }
    }
    else if (param_2 < 0x37e88) {
      if (param_2 == 0x251c0) {
        uVar1 = 0xe6;
        goto LAB_0010b6b0;
      }
    }
    else {
      if (param_2 == 0x37e88) {
        uVar1 = 0xf4;
        goto LAB_0010b6b0;
      }
      if (param_2 == 250000) {
        uVar1 = 0xe5;
        goto LAB_0010b6b0;
      }
    }
  }
  else if (param_2 < 0x50140) {
    if (param_2 == 0x3e800) {
      uVar1 = 0xf6;
      goto LAB_0010b6b0;
    }
    if (param_2 == 0x470b8) {
      uVar1 = 0xe0;
      goto LAB_0010b6b0;
    }
    if (param_2 == 0x4b320) {
      uVar1 = 0xe1;
      goto LAB_0010b6b0;
    }
  }
  else if (param_2 < 0x8e940) {
    if (param_2 == 0x50140) {
      uVar1 = 0xf5;
      goto LAB_0010b6b0;
    }
    if (param_2 == 0x6be90) {
      uVar1 = 0xe2;
      goto LAB_0010b6b0;
    }
  }
  else {
    if (param_2 == 0x8e940) {
      uVar1 = 0xe3;
      goto LAB_0010b6b0;
    }
    if (param_2 == 0xd84f0) {
      uVar1 = 0xe4;
      goto LAB_0010b6b0;
    }
  }
  uVar1 = 0xf3;
LAB_0010b6b0:
  *(undefined1 *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 3)) = uVar1;
  if (param_6 == 1) {
    *(byte *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 1)) = (byte)(param_4 >> 4) & 0xf | 0xe0;
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_encode @ 0010b6cc */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ssc_encode(ssc_i64_u *param_1,const ssc_i32_u *param_2,int param_3,uint8_t *param_4_u8,int param_5)
{
  ssc_u16_u *param_4 = (ssc_u16_u *)param_4_u8;
  ssc_u16_u *puVar1;
  undefined1 (*pauVar2) [16];
  ssc_i64_u *plVar3;
  undefined *puVar4;
  undefined *puVar5;
  unkbyte10 *pVar6;
  ssc_i16_u *psVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char cVar12;
  short sVar13;
  uint uVar14;
  undefined1 (*pauVar15) [16];
  long lVar16;
  vec128_t auVar17;
  vec128_t auVar18;
  vec128_t auVar19;
  vec128_t auVar20;
  vec128_t auVar21;
  vec128_t auVar22;
  vec128_t auVar23;
  vec128_t auVar24;
  vec128_t auVar25;
  vec128_t auVar26;
  vec128_t auVar27;
  vec128_t auVar28;
  vec128_t auVar29;
  vec128_t auVar30;
  vec128_t auVar31;
  vec128_t auVar32;
  vec128_t auVar33;
  undefined8 uVar34;
  bool bVar35;
  short sVar36;
  short sVar37;
  short sVar38;
  short sVar39;
  short sVar40;
  short sVar41;
  short sVar42;
  short sVar43;
  short sVar44;
  ssc_i32_u *piVar45;
  ssc_i32_u *piVar46;
  ssc_i32_u *piVar47;
  ssc_i32_u *piVar48;
  ssc_i32_u *piVar49;
  ssc_i32_u *piVar50;
  ssc_u16_u *puVar51;
  ssc_u16_u *puVar52;
  ssc_u16_u *puVar53;
  ssc_u16_u *puVar54;
  ssc_u16_u *puVar55;
  ssc_u16_u *puVar56;
  ssc_u16_u *puVar57;
  ssc_u16_u *puVar58;
  ssc_u16_u *puVar59;
  ssc_u16_u *puVar60;
  ssc_u16_u *puVar61;
  ssc_u16_u *puVar62;
  ssc_u16_u *puVar63;
  ssc_u16_u *puVar64;
  short sVar65;
  short sVar66;
  short sVar67;
  short sVar68;
  short sVar69;
  short sVar70;
  short sVar71;
  short sVar72;
  ssc_i16_u *psVar73;
  ssc_i16_u *psVar74;
  ssc_i16_u *psVar75;
  ssc_i16_u *psVar76;
  ssc_i16_u *psVar77;
  ssc_i16_u *psVar78;
  ssc_i16_u *psVar79;
  short sVar80;
  short sVar81;
  short sVar82;
  short sVar83;
  bool bVar84;
  undefined1 *puVar85;
  undefined1 *puVar86;
  bool bVar87;
  short sVar88;
  int iVar89;
  int iVar90;
  int iVar91;
  undefined4 uVar92;
  int iVar93;
  long lVar94;
  undefined *puVar95;
  char cVar96;
  uint uVar97;
  long lVar98;
  ulong uVar99;
  long lVar100;
  long lVar101;
  ssc_u16_u *puVar102;
  ulong uVar103;
  ssc_i16_u *psVar104;
  undefined4 uVar105;
  uint uVar106;
  uint uVar107;
  long lVar108;
  ulong uVar109;
  ssc_u32_u *puVar110;
  undefined *puVar111;
  ssc_u64_u *puVar112;
  undefined1 uVar113;
  uint uVar114;
  uint uVar115;
  ulong uVar116;
  ssc_i32_u *piVar117;
  ssc_i32_u *piVar118;
  ssc_u32_u *puVar119;
  undefined1 (*pauVar120) [16];
  ssc_i16_u *psVar121;
  int iVar122;
  ulong uVar123;
  undefined1 (*pauVar124) [16];
  long lVar125;
  ulong uVar126;
  ssc_u64_u *puVar127;
  uint uVar128;
  long lVar129;
  ssc_i32_u *piVar130;
  uint uVar131;
  long lVar132;
  ssc_u64_u *puVar133;
  long lVar134;
  ulong uVar135;
  ssc_i32_u *piVar136;
  int iVar137;
  int iVar138;
  uint uVar139;
  uint uVar140;
  uint uVar141;
  int iVar142;
  undefined8 uVar143;
  int iVar156;
  vec128_t auVar144;
  vec128_t auVar145;
  vec128_t auVar146;
  vec128_t auVar147;
  vec128_t auVar148;
  vec128_t auVar149;
  vec128_t auVar150;
  int iVar153;
  int iVar154;
  int iVar155;
  int iVar157;
  vec128_t auVar151;
  vec128_t auVar152;
  int iVar158;
  int iVar159;
  short sVar171;
  int iVar172;
  int iVar173;
  int iVar174;
  int iVar175;
  vec128_t auVar160;
  vec128_t auVar161;
  vec128_t auVar162;
  vec128_t auVar163;
  vec128_t auVar164;
  vec128_t auVar165;
  vec128_t auVar166;
  vec128_t auVar167;
  vec128_t auVar168;
  int iVar176;
  int iVar177;
  vec128_t auVar169;
  vec128_t auVar170;
  uint uVar178;
  vec128_t auVar179;
  vec128_t auVar180;
  vec128_t auVar181;
  vec128_t auVar182;
  vec128_t auVar183;
  vec128_t auVar184;
  vec128_t auVar185;
  vec128_t auVar186;
  vec128_t auVar187;
  vec128_t auVar188;
  vec128_t auVar189;
  vec128_t auVar190;
  vec128_t auVar191;
  vec128_t auVar192;
  vec128_t auVar193;
  vec128_t auVar194;
  vec128_t auVar195;
  vec128_t auVar196;
  vec128_t auVar197;
  vec128_t auVar198;
  vec128_t auVar199;
  vec128_t auVar200;
  vec128_t auVar201;
  vec128_t auVar202;
  vec128_t auVar203;
  vec128_t auVar204;
  vec128_t auVar205;
  vec128_t auVar206;
  vec128_t auVar207;
  vec128_t auVar208;
  vec128_t auVar209;
  vec128_t auVar210;
  vec128_t auVar211;
  vec128_t auVar212;
  vec128_t auVar213;
  vec128_t auVar214;
  vec128_t auVar215;
  vec128_t auVar216;
  vec128_t auVar217;
  ushort uVar218;
  ushort uVar221;
  ushort uVar222;
  ushort uVar223;
  ushort uVar224;
  ushort uVar225;
  ushort uVar226;
  ushort uVar228;
  vec128_t auVar219;
  vec128_t auVar220;
  int iVar227;
  ushort uVar229;
  int iVar230;
  int iVar231;
  ushort uVar237;
  ushort uVar238;
  int iVar239;
  int iVar240;
  ushort uVar241;
  ushort uVar242;
  int iVar243;
  int iVar244;
  ushort uVar245;
  ushort uVar246;
  ushort uVar249;
  vec128_t auVar232;
  vec128_t auVar233;
  vec128_t auVar234;
  vec128_t auVar235;
  vec128_t auVar236;
  int iVar247;
  int iVar248;
  int iVar250;
  int iVar251;
  int iVar252;
  int iVar255;
  int iVar256;
  int iVar257;
  int iVar258;
  vec128_t auVar253;
  vec128_t auVar254;
  int iVar259;
  int iVar260;
  short sVar261;
  int iVar262;
  short sVar265;
  short sVar266;
  int iVar267;
  short sVar268;
  int iVar269;
  vec128_t auVar263;
  int iVar270;
  vec128_t auVar264;
  undefined2 uVar271;
  undefined2 uVar272;
  undefined2 uVar273;
  vec128_t auVar274;
  vec128_t auVar275;
  vec128_t auVar276;
  vec128_t auVar277;
  undefined8 uVar278;
  undefined8 uVar279;
  uint8_t ssc_stack_frame[0x690] __attribute__((aligned(16)));
  memset((void *)(ssc_stack_frame), 0, sizeof(ssc_stack_frame));
#define STACK_ADDR(off) (ssc_stack_frame + (0x690 - (off)))
#define local_63c   (*(ssc_u32_u *)STACK_ADDR(0x63c))
#define local_630   (*(ssc_u32_u *)STACK_ADDR(0x630))
#define local_5f8   (*(ssc_i16_u **)STACK_ADDR(0x5f8))
#define local_5ac   (*(ssc_i32_u *)STACK_ADDR(0x5ac))
#define local_570   (*(char **)STACK_ADDR(0x570))
#define auStack_538 ((undefined1 *)STACK_ADDR(0x538))
#define local_530   (*(ssc_i32_u *)STACK_ADDR(0x530))
#define local_520   (*(ssc_i32_u *)STACK_ADDR(0x520))
#define local_518   (*(ssc_u32_u *)STACK_ADDR(0x518))
#define local_508   (*(ssc_i32_u *)STACK_ADDR(0x508))
#define local_500   (*(ssc_i32_u *)STACK_ADDR(0x500))
#define local_4fc   (*(ssc_i32_u *)STACK_ADDR(0x4fc))
#define local_4f8   (*(ssc_i32_u *)STACK_ADDR(0x4f8))
#define local_4f4   (*(ssc_i32_u *)STACK_ADDR(0x4f4))
#define local_4f0   (*(ssc_i32_u *)STACK_ADDR(0x4f0))
#define local_4ec   (*(ssc_i32_u *)STACK_ADDR(0x4ec))
#define local_4e8   (*(ssc_i32_u *)STACK_ADDR(0x4e8))
#define local_4e4   (*(ssc_i32_u *)STACK_ADDR(0x4e4))
#define local_4e0   (*(ssc_i32_u *)STACK_ADDR(0x4e0))
#define local_4dc   (*(ssc_i32_u *)STACK_ADDR(0x4dc))
#define local_4d8   (*(ssc_i32_u *)STACK_ADDR(0x4d8))
#define local_4d4   (*(ssc_i32_u *)STACK_ADDR(0x4d4))
#define local_4d0   (*(ssc_i32_u *)STACK_ADDR(0x4d0))
#define local_4cc   (*(ssc_i32_u *)STACK_ADDR(0x4cc))
#define local_4c8   (*(ssc_i32_u *)STACK_ADDR(0x4c8))
#define local_4c4   (*(ssc_i32_u *)STACK_ADDR(0x4c4))
#define local_4c0   ((ssc_u32_u *)STACK_ADDR(0x4c0))
#define auStack_4b8 ((ssc_u64_u *)STACK_ADDR(0x4b8))
#define auStack_468 ((undefined1 *)STACK_ADDR(0x468))
#define local_414   ((ssc_i16_u *)STACK_ADDR(0x414))
#define local_410   (*(ssc_u64_u *)STACK_ADDR(0x410))
#define asStack_408 ((ssc_i16_u *)STACK_ADDR(0x408))
#define uStack_400  (*(ssc_u64_u *)STACK_ADDR(0x400))
#define asStack_3f8 ((ssc_i16_u *)STACK_ADDR(0x3f8))
#define local_3b8   ((ssc_i16_u *)STACK_ADDR(0x3b8))
#define local_360   ((ssc_i32_u *)STACK_ADDR(0x360))
#define local_2b0   ((ssc_i32_u *)STACK_ADDR(0x2b0))
#define auStack_254 ((undefined1 *)STACK_ADDR(0x254))
#define local_1f8   (*(ssc_i64_u *)STACK_ADDR(0x1f8))
#define local_1f0   ((ssc_u32_u *)STACK_ADDR(0x1f0))
#define local_1a8   (*(ssc_i32_u *)STACK_ADDR(0x1a8))
#define local_1a4   (*(ssc_i32_u *)STACK_ADDR(0x1a4))
#define local_1a0   (*(ssc_i32_u *)STACK_ADDR(0x1a0))
#define local_19c   (*(ssc_i32_u *)STACK_ADDR(0x19c))
#define auStack_198 ((undefined1 *)STACK_ADDR(0x198))
#define local_140   (*(ssc_u32_u *)STACK_ADDR(0x140))
#define local_13c   (*(ssc_u32_u *)STACK_ADDR(0x13c))
#define local_138   (*(ssc_u32_u *)STACK_ADDR(0x138))
#define local_130   (*(ssc_u32_u *)STACK_ADDR(0x130))
#define local_128   ((ssc_i16_u *)STACK_ADDR(0x128))
#define uStack_120  (*(ssc_u64_u *)STACK_ADDR(0x120))
#define auStack_118 ((ssc_u64_u *)STACK_ADDR(0x118))
#define local_d0    (*(ssc_i16_u *)STACK_ADDR(0xd0))
#define local_ce    (*(ssc_i16_u *)STACK_ADDR(0xce))
#define local_cc    (*(ssc_u32_u *)STACK_ADDR(0xcc))
#define asStack_c8  ((ssc_i16_u *)STACK_ADDR(0xc8))
#define uStack_c4   (*(ssc_u64_u *)STACK_ADDR(0xc4))
#define asStack_bc  ((ssc_i16_u *)STACK_ADDR(0xbc))
#define uStack_b4   (*(ssc_u64_u *)STACK_ADDR(0xb4))
#define local_70    (*(ssc_i64_u *)STACK_ADDR(0x70))

  lVar16 = tpidr_el0;
  local_70 = *(ssc_i64_u *)(uintptr_t)((lVar16 + 0x28));
  iVar155 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc));
  local_13c = 0;
  local_130 = (uint)(0x2ee00 < param_5);
  iVar122 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x6c));
  uVar105 = *(ssc_u32_u *)(uintptr_t)((*param_1 + 8));
  *(ssc_i32_u *)(param_1 + 0xd) = param_5;
  *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) = uVar105;
  if (0x3e7ff < param_5) {
    iVar154 = 0;
    iVar93 = 1;
    if (param_5 < 0x50140) {
      if (param_5 == 0x3e800) goto LAB_0010ba50;
      if ((param_5 == 0x470b8) || (param_5 == 0x4b320)) goto LAB_0010b8f0;
    }
    else if (param_5 < 0x8e940) {
      if (param_5 == 0x50140) goto LAB_0010ba50;
      if (param_5 == 0x6be90) goto LAB_0010b8f0;
    }
    else if ((param_5 == 0x8e940) || (param_5 == 0xd84f0)) {
LAB_0010b8f0:
      uVar105 = 0x7b4c00;
      goto LAB_0010b924;
    }
    goto LAB_0010ba40;
  }
  if (param_5 < 0x251c0) {
    if ((param_5 == 88000) || (param_5 == 96000)) {
      uVar92 = 0x76f2;
      uVar105 = 0x76f200;
LAB_0010b920:
      if (iVar122 != 0x18) {
        uVar105 = uVar92;
      }
      goto LAB_0010b924;
    }
    if (param_5 != 0x1f400) goto LAB_0010ba40;
    uVar105 = 0x78b400;
    if (iVar122 != 0x18) {
      uVar105 = 0x78b4;
    }
    set_DRC_limit_gain(uVar105);
    iVar154 = 0;
    iVar93 = 0;
    uVar218 = *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x8c));
    uVar271 = *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x8e));
    *param_4 = 0xeeff;
    *(byte *)(param_4 + 1) = (byte)uVar271 & 3 | (char)uVar218 << 4;
LAB_0010bb4c:
    uVar97 = (uint)uVar218;
    uVar113 = 0xf2;
  }
  else {
    uVar105 = 0x79f800;
    if (param_5 < 0x37e88) {
      if (param_5 != 0x251c0) {
        if (param_5 != 0x2ee00) goto LAB_0010ba40;
LAB_0010b8fc:
        uVar92 = 0x7a94;
        uVar105 = 0x7a9400;
        goto LAB_0010b920;
      }
    }
    else {
      if (param_5 == 0x37e88) goto LAB_0010b8fc;
      if (param_5 != 250000) goto LAB_0010ba40;
    }
LAB_0010b924:
    set_DRC_limit_gain(uVar105);
    iVar154 = 0;
    if (param_5 < 0x470b8) {
      iVar93 = iVar154;
      if (param_5 < 0x2ee00) {
        if (param_5 == 88000) {
LAB_0010bbdc:
          iVar154 = 0;
        }
        else {
          iVar154 = 0;
          if (param_5 != 96000) {
            if (param_5 == 0x251c0) goto LAB_0010ba34;
            goto LAB_0010ba40;
          }
        }
      }
      else {
        if (param_5 == 0x2ee00) goto LAB_0010bbdc;
        iVar154 = 0;
        if (param_5 != 0x37e88) {
          if (param_5 == 250000) goto LAB_0010ba34;
          goto LAB_0010ba40;
        }
      }
    }
    else {
      if (param_5 < 0x6be90) {
        if ((param_5 == 0x470b8) || (param_5 == 0x4b320)) {
LAB_0010ba34:
          iVar93 = 1;
          iVar154 = 1;
          goto LAB_0010ba50;
        }
        if (param_5 == 0x50140) {
          iVar93 = 1;
          goto LAB_0010ba50;
        }
      }
      else if (((param_5 == 0x6be90) || (param_5 == 0xd84f0)) || (param_5 == 0x8e940))
      goto LAB_0010ba34;
LAB_0010ba40:
      iVar93 = 0;
      iVar154 = 0;
    }
LAB_0010ba50:
    uVar218 = *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x8c));
    uVar97 = (uint)uVar218;
    uVar271 = *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x8e));
    *param_4 = 0xeeff;
    *(byte *)(param_4 + 1) = (byte)uVar271 & 3 | (char)uVar218 << 4;
    if (param_5 < 0x3e800) {
      if (param_5 < 0x251c0) {
        if (param_5 == 88000) {
          uVar113 = 0xf0;
        }
        else {
          if (param_5 != 96000) {
            if (param_5 != 0x1f400) goto LAB_0010bacc;
            goto LAB_0010bb4c;
          }
          uVar113 = 0xf1;
        }
      }
      else if (param_5 < 0x37e88) {
        if (param_5 == 0x251c0) {
          uVar113 = 0xe6;
        }
        else {
LAB_0010bacc:
          uVar113 = 0xf3;
        }
      }
      else if (param_5 == 0x37e88) {
        uVar113 = 0xf4;
      }
      else {
        if (param_5 != 250000) goto LAB_0010bacc;
        uVar113 = 0xe5;
      }
    }
    else if (param_5 < 0x50140) {
      if (param_5 == 0x3e800) {
        uVar113 = 0xf6;
      }
      else if (param_5 == 0x470b8) {
        uVar113 = 0xe0;
      }
      else {
        if (param_5 != 0x4b320) goto LAB_0010bacc;
        uVar113 = 0xe1;
      }
    }
    else if (param_5 < 0x8e940) {
      if (param_5 == 0x50140) {
        uVar113 = 0xf5;
      }
      else {
        if (param_5 != 0x6be90) goto LAB_0010bacc;
        uVar113 = 0xe2;
      }
    }
    else if (param_5 == 0x8e940) {
      uVar113 = 0xe3;
    }
    else {
      if (param_5 != 0xd84f0) goto LAB_0010bacc;
      uVar113 = 0xe4;
    }
  }
  local_570 = (char *)(param_4 + 1);
  local_5f8 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x8c));
  *(undefined1 *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + 3)) = uVar113;
  if (iVar154 != 0) {
    *(byte *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + 1)) = (byte)(uVar97 >> 4) & 0xf | 0xe0;
  }
  iVar142 = (int)param_1[0xc] << 3;
  iVar91 = 0;
  if (iVar142 != 0) {
    iVar91 = ((int)param_1[0xd] * param_3) / iVar142;
  }
  iVar142 = iVar91 * 3 >> 7;
  if (iVar93 != 0) {
    iVar142 = 0;
  }
  iVar142 = (~(iVar142 + iVar91) & 1U) + iVar142 + iVar91;
  uVar97 = iVar142 - 1;
  ssc_ec_enc_init((ssc_u64_u *)(auStack_538),(undefined8)(uintptr_t)(param_4 + 2),uVar97);
  puVar4 = PTR__pcmpower_0011bce8;
  iVar91 = param_3 >> 2;
  iVar137 = param_3 >> 3;
  if (iVar93 == 0) {
    puVar111 = PTR_coeffs96andbelow_0011bcf0;
    if (96000 < param_5) {
      puVar111 = PTR_coeffs_0011bcf8;
    }
    Biquad_Narrow_int2int_stereo((ssc_u64_u *)(PTR__pcmpower_0011bce8),(ssc_u64_u *)(param_2),(ssc_i32_u *)(puVar111),param_1 + 0x12,param_3);
    powercalc((ssc_u64_u *)(puVar4),param_3,(ssc_u32_u *)(local_360));
    powercalc((ssc_u64_u *)(param_2),param_3,&local_cc);
    local_cc = local_cc - local_360[0];
    iVar90 = CalculateLimitGain(local_360[0],local_cc,param_5,*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 100)));
    iVar89 = iVar90 << 8;
    if (iVar122 != 0x18) {
      iVar89 = iVar90;
    }
  }
  else {
    Biquad_Narrow_int2int_stereo
              ((ssc_u64_u *)(PTR__pcmpower_0011bce8),(ssc_u64_u *)(param_2),(ssc_i32_u *)(PTR_coeffs96andbelow_0011bcf0),param_1 + 0x12,param_3);
    powercalc((ssc_u64_u *)(puVar4),param_3,(ssc_u32_u *)(local_360));
    powercalc((ssc_u64_u *)(param_2),param_3,&local_cc);
    iVar89 = CalculateLimitGain(local_360[0],local_cc,param_5,*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 100)));
    iVar89 = iVar89 << 8;
  }
  set_DRC_limit_gain(iVar89);
  SSC_DRC_Exe((ssc_u32_u *)(param_2),iVar137);
  SSC_DRC_Exe((ssc_u32_u *)(param_2 + iVar91),iVar137);
  SSC_DRC_Exe((ssc_u32_u *)(param_2 + (long)iVar91 * 2),iVar137);
  SSC_DRC_Exe((ssc_u32_u *)(param_2 + (long)iVar91 * 3),iVar137);
  SSC_DRC_Exe((ssc_u32_u *)(param_2 + (long)iVar91 * 4),iVar137);
  SSC_DRC_Exe((ssc_u32_u *)(param_2 + (long)iVar91 * 5),iVar137);
  SSC_DRC_Exe((ssc_u32_u *)(param_2 + (long)iVar91 * 6),iVar137);
  SSC_DRC_Exe((ssc_u32_u *)(param_2 + (long)iVar91 * 7),iVar137);
  ssc_ec_enc_shrink((ssc_i64_u *)(auStack_538),uVar97);
  iVar91 = -1;
  if ((param_2 == (const ssc_i32_u *)((ssc_i32_u *)0x0)) || (iVar142 < 3)) goto LAB_0010f670;
  if (0x4fa < uVar97) {
    uVar97 = 0x4fb;
  }
  piVar136 = (ssc_i32_u *)(uintptr_t)(*param_1);
  iVar142 = local_520 + (int)LZCOUNT(local_518);
  lVar108 = *(ssc_i64_u *)(piVar136 + 4);
  iVar91 = iVar142 + -0x20;
  uVar10 = piVar136[2];
  lVar101 = param_1[1];
  uVar9 = uVar97;
  if ((int)param_1[3] != -1) {
    iVar137 = iVar91;
    if (iVar91 < 2) {
      iVar137 = 0;
    }
    iVar89 = *piVar136 << 3;
    iVar90 = 0;
    if (iVar89 != 0) {
      iVar90 = (iVar137 + (int)param_1[3] * param_3 + *piVar136 * 4) / iVar89;
    }
    if ((int)(iVar90 - 1U) <= (int)uVar97) {
      uVar9 = iVar90 - 1U;
    }
    if ((int)uVar9 < 3) {
      uVar9 = 2;
    }
  }
  uVar128 = (param_3 - piVar136[1]) * iVar155;
  uVar178 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
  uVar116 = (ulong)uVar178;
  iVar137 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x4c));
  piVar118 = (ssc_i32_u *)(param_2);
  if ((int)uVar128 < 0x10) {
    uVar141 = 0;
    auVar145 = ZEXT816(0);
  }
  else {
    auVar145 = ZEXT816(0);
    iVar89 = 0;
    do {
      iVar89 = iVar89 + 0x10;
      auVar144._0_4_ = MP_INT_ABS(*piVar118);
      auVar144._4_4_ = MP_INT_ABS(piVar118[1]);
      auVar144._8_4_ = MP_INT_ABS(piVar118[2]);
      auVar144._12_4_ = MP_INT_ABS(piVar118[3]);
      auVar220._0_4_ = MP_INT_ABS(piVar118[4]);
      auVar220._4_4_ = MP_INT_ABS(piVar118[5]);
      auVar220._8_4_ = MP_INT_ABS(piVar118[6]);
      auVar220._12_4_ = MP_INT_ABS(piVar118[7]);
      auVar144 = NEON_smax(auVar145,auVar144,4);
      piVar117 = piVar118 + 8;
      piVar130 = piVar118 + 9;
      piVar45 = piVar118 + 10;
      piVar46 = piVar118 + 0xb;
      auVar145 = *(vec128_t *)(piVar118 + 0xc);
      piVar118 = piVar118 + 0x10;
      auVar144 = NEON_smax(auVar144,auVar220,4);
      auVar277._0_4_ = MP_INT_ABS(*piVar117);
      auVar277._4_4_ = MP_INT_ABS(*piVar130);
      auVar277._8_4_ = MP_INT_ABS(*piVar45);
      auVar277._12_4_ = MP_INT_ABS(*piVar46);
      auVar235._0_4_ = MP_INT_ABS(auVar145._0_4_);
      auVar235._4_4_ = MP_INT_ABS(auVar145._4_4_);
      auVar235._8_4_ = MP_INT_ABS(auVar145._8_4_);
      auVar235._12_4_ = MP_INT_ABS(auVar145._12_4_);
      auVar145 = NEON_smax(auVar144,auVar277,4);
      auVar145 = NEON_smax(auVar145,auVar235,4);
    } while (iVar89 < (int)(uVar128 - 0xf));
    uVar141 = uVar128 & 0xfffffff0;
  }
  auVar144 = NEON_ext(auVar145,auVar145,8,1);
  uVar143 = NEON_smax(auVar144._0_8_,auVar145._0_8_,4);
  iVar90 = (int)((ulong)uVar143 >> 0x20);
  iVar89 = (int)uVar143;
  if ((int)uVar143 <= iVar90) {
    iVar89 = iVar90;
  }
  if ((int)uVar141 < (int)uVar128) {
    if (6 < uVar128 + ~uVar141) {
      uVar99 = (ulong)(uVar128 + ~uVar141) + 1;
      auVar145._0_8_ = CONCAT44(iVar89,iVar89);
      auVar145._8_4_ = iVar89;
      auVar145._12_4_ = iVar89;
      uVar103 = uVar99 & 0x1fffffff8;
      auVar264._8_8_ = auVar145._8_8_;
      auVar264._0_8_ = auVar145._0_8_;
      uVar141 = uVar141 + (int)uVar103;
      piVar117 = piVar118 + 4;
      uVar109 = uVar103;
      do {
        piVar130 = piVar117 + -4;
        piVar45 = piVar117 + -3;
        piVar46 = piVar117 + -2;
        piVar47 = piVar117 + -1;
        iVar89 = *piVar117;
        piVar48 = piVar117 + 1;
        piVar49 = piVar117 + 2;
        piVar50 = piVar117 + 3;
        piVar117 = piVar117 + 8;
        uVar109 = uVar109 - 8;
        auVar274._0_4_ = MP_INT_ABS(*piVar130);
        auVar274._4_4_ = MP_INT_ABS(*piVar45);
        auVar274._8_4_ = MP_INT_ABS(*piVar46);
        auVar274._12_4_ = MP_INT_ABS(*piVar47);
        auVar276._0_4_ = MP_INT_ABS(iVar89);
        auVar276._4_4_ = MP_INT_ABS(*piVar48);
        auVar276._8_4_ = MP_INT_ABS(*piVar49);
        auVar276._12_4_ = MP_INT_ABS(*piVar50);
        auVar145 = NEON_smax(auVar145,auVar274,4);
        auVar264 = NEON_smax(auVar264,auVar276,4);
      } while (uVar109 != 0);
      auVar145 = NEON_smax(auVar145,auVar264,4);
      iVar89 = NEON_smaxv(auVar145,4);
      piVar118 = piVar118 + uVar103;
      if (uVar99 == uVar103) goto LAB_0010bff4;
    }
    iVar90 = uVar128 - uVar141;
    do {
      iVar173 = *piVar118;
      iVar159 = -iVar173;
      if (-1 < iVar173) {
        iVar159 = iVar173;
      }
      if (iVar89 <= iVar159) {
        iVar89 = iVar159;
      }
      iVar90 = iVar90 + -1;
      piVar118 = piVar118 + 1;
    } while (iVar90 != 0);
  }
LAB_0010bff4:
  if (iVar137 <= iVar89) {
    piVar118 = (ssc_i32_u *)(param_2);
    if ((int)uVar128 < 0x10) {
      uVar141 = 0;
      auVar145 = ZEXT816(0);
    }
    else {
      auVar145 = ZEXT816(0);
      iVar137 = 0;
      do {
        iVar137 = iVar137 + 0x10;
        auVar160._0_4_ = MP_INT_ABS(*piVar118);
        auVar160._4_4_ = MP_INT_ABS(piVar118[1]);
        auVar160._8_4_ = MP_INT_ABS(piVar118[2]);
        auVar160._12_4_ = MP_INT_ABS(piVar118[3]);
        auVar179._0_4_ = MP_INT_ABS(piVar118[4]);
        auVar179._4_4_ = MP_INT_ABS(piVar118[5]);
        auVar179._8_4_ = MP_INT_ABS(piVar118[6]);
        auVar179._12_4_ = MP_INT_ABS(piVar118[7]);
        auVar144 = NEON_smax(auVar145,auVar160,4);
        piVar117 = piVar118 + 8;
        piVar130 = piVar118 + 9;
        piVar45 = piVar118 + 10;
        piVar46 = piVar118 + 0xb;
        auVar145 = *(vec128_t *)(piVar118 + 0xc);
        piVar118 = piVar118 + 0x10;
        auVar144 = NEON_smax(auVar144,auVar179,4);
        auVar161._0_4_ = MP_INT_ABS(*piVar117);
        auVar161._4_4_ = MP_INT_ABS(*piVar130);
        auVar161._8_4_ = MP_INT_ABS(*piVar45);
        auVar161._12_4_ = MP_INT_ABS(*piVar46);
        auVar180._0_4_ = MP_INT_ABS(auVar145._0_4_);
        auVar180._4_4_ = MP_INT_ABS(auVar145._4_4_);
        auVar180._8_4_ = MP_INT_ABS(auVar145._8_4_);
        auVar180._12_4_ = MP_INT_ABS(auVar145._12_4_);
        auVar145 = NEON_smax(auVar144,auVar161,4);
        auVar145 = NEON_smax(auVar145,auVar180,4);
      } while (iVar137 < (int)(uVar128 - 0xf));
      uVar141 = uVar128 & 0xfffffff0;
    }
    auVar144 = NEON_ext(auVar145,auVar145,8,1);
    uVar143 = NEON_smax(auVar144._0_8_,auVar145._0_8_,4);
    iVar89 = (int)((ulong)uVar143 >> 0x20);
    iVar137 = (int)uVar143;
    if ((int)uVar143 <= iVar89) {
      iVar137 = iVar89;
    }
    if ((int)uVar141 < (int)uVar128) {
      if (6 < uVar128 + ~uVar141) {
        uVar99 = (ulong)(uVar128 + ~uVar141) + 1;
        auVar146._0_8_ = CONCAT44(iVar137,iVar137);
        auVar146._8_4_ = iVar137;
        auVar146._12_4_ = iVar137;
        uVar103 = uVar99 & 0x1fffffff8;
        piVar117 = piVar118 + 4;
        auVar162._8_8_ = auVar146._8_8_;
        auVar162._0_8_ = auVar146._0_8_;
        uVar141 = uVar141 + (int)uVar103;
        piVar118 = piVar118 + uVar103;
        uVar109 = uVar103;
        do {
          piVar130 = piVar117 + -4;
          piVar45 = piVar117 + -3;
          piVar46 = piVar117 + -2;
          piVar47 = piVar117 + -1;
          iVar137 = *piVar117;
          piVar48 = piVar117 + 1;
          piVar49 = piVar117 + 2;
          piVar50 = piVar117 + 3;
          piVar117 = piVar117 + 8;
          uVar109 = uVar109 - 8;
          auVar181._0_4_ = MP_INT_ABS(*piVar130);
          auVar181._4_4_ = MP_INT_ABS(*piVar45);
          auVar181._8_4_ = MP_INT_ABS(*piVar46);
          auVar181._12_4_ = MP_INT_ABS(*piVar47);
          auVar200._0_4_ = MP_INT_ABS(iVar137);
          auVar200._4_4_ = MP_INT_ABS(*piVar48);
          auVar200._8_4_ = MP_INT_ABS(*piVar49);
          auVar200._12_4_ = MP_INT_ABS(*piVar50);
          auVar146 = NEON_smax(auVar146,auVar181,4);
          auVar162 = NEON_smax(auVar162,auVar200,4);
        } while (uVar109 != 0);
        auVar145 = NEON_smax(auVar146,auVar162,4);
        iVar137 = NEON_smaxv(auVar145,4);
        if (uVar99 == uVar103) goto LAB_0010c108;
      }
      iVar89 = uVar128 - uVar141;
      do {
        iVar159 = *piVar118;
        iVar90 = -iVar159;
        if (-1 < iVar159) {
          iVar90 = iVar159;
        }
        if (iVar137 <= iVar90) {
          iVar137 = iVar90;
        }
        iVar89 = iVar89 + -1;
        piVar118 = piVar118 + 1;
      } while (iVar89 != 0);
    }
  }
LAB_0010c108:
  uVar141 = piVar136[1] * iVar155;
  piVar118 = (ssc_i32_u *)(param_2 + (int)uVar128);
  if ((int)uVar141 < 0x10) {
    auVar145 = ZEXT816(0);
    uVar128 = 0;
  }
  else {
    auVar145 = ZEXT816(0);
    iVar89 = 0;
    do {
      iVar89 = iVar89 + 0x10;
      auVar163._0_4_ = MP_INT_ABS(*piVar118);
      auVar163._4_4_ = MP_INT_ABS(piVar118[1]);
      auVar163._8_4_ = MP_INT_ABS(piVar118[2]);
      auVar163._12_4_ = MP_INT_ABS(piVar118[3]);
      auVar182._0_4_ = MP_INT_ABS(piVar118[4]);
      auVar182._4_4_ = MP_INT_ABS(piVar118[5]);
      auVar182._8_4_ = MP_INT_ABS(piVar118[6]);
      auVar182._12_4_ = MP_INT_ABS(piVar118[7]);
      auVar144 = NEON_smax(auVar145,auVar163,4);
      piVar117 = piVar118 + 8;
      piVar130 = piVar118 + 9;
      piVar45 = piVar118 + 10;
      piVar46 = piVar118 + 0xb;
      auVar145 = *(vec128_t *)(piVar118 + 0xc);
      piVar118 = piVar118 + 0x10;
      auVar144 = NEON_smax(auVar144,auVar182,4);
      auVar164._0_4_ = MP_INT_ABS(*piVar117);
      auVar164._4_4_ = MP_INT_ABS(*piVar130);
      auVar164._8_4_ = MP_INT_ABS(*piVar45);
      auVar164._12_4_ = MP_INT_ABS(*piVar46);
      auVar183._0_4_ = MP_INT_ABS(auVar145._0_4_);
      auVar183._4_4_ = MP_INT_ABS(auVar145._4_4_);
      auVar183._8_4_ = MP_INT_ABS(auVar145._8_4_);
      auVar183._12_4_ = MP_INT_ABS(auVar145._12_4_);
      auVar145 = NEON_smax(auVar144,auVar164,4);
      auVar145 = NEON_smax(auVar145,auVar183,4);
    } while (iVar89 < (int)(uVar141 - 0xf));
    uVar128 = uVar141 & 0xfffffff0;
  }
  auVar144 = NEON_ext(auVar145,auVar145,8,1);
  uVar14 = uVar10 * iVar155;
  iVar90 = uVar9 * 8;
  uVar143 = NEON_smax(auVar144._0_8_,auVar145._0_8_,4);
  iVar159 = (int)((ulong)uVar143 >> 0x20);
  iVar89 = (int)uVar143;
  if ((int)uVar143 <= iVar159) {
    iVar89 = iVar159;
  }
  if ((int)uVar128 < (int)uVar141) {
    if (6 < uVar141 + ~uVar128) {
      uVar99 = (ulong)(uVar141 + ~uVar128) + 1;
      auVar147._0_8_ = CONCAT44(iVar89,iVar89);
      auVar147._8_4_ = iVar89;
      auVar147._12_4_ = iVar89;
      uVar103 = uVar99 & 0x1fffffff8;
      auVar165._8_8_ = auVar147._8_8_;
      auVar165._0_8_ = auVar147._0_8_;
      uVar128 = uVar128 + (int)uVar103;
      piVar117 = piVar118 + 4;
      uVar109 = uVar103;
      do {
        piVar130 = piVar117 + -4;
        piVar45 = piVar117 + -3;
        piVar46 = piVar117 + -2;
        piVar47 = piVar117 + -1;
        iVar89 = *piVar117;
        piVar48 = piVar117 + 1;
        piVar49 = piVar117 + 2;
        piVar50 = piVar117 + 3;
        piVar117 = piVar117 + 8;
        uVar109 = uVar109 - 8;
        auVar184._0_4_ = MP_INT_ABS(*piVar130);
        auVar184._4_4_ = MP_INT_ABS(*piVar45);
        auVar184._8_4_ = MP_INT_ABS(*piVar46);
        auVar184._12_4_ = MP_INT_ABS(*piVar47);
        auVar201._0_4_ = MP_INT_ABS(iVar89);
        auVar201._4_4_ = MP_INT_ABS(*piVar48);
        auVar201._8_4_ = MP_INT_ABS(*piVar49);
        auVar201._12_4_ = MP_INT_ABS(*piVar50);
        auVar147 = NEON_smax(auVar147,auVar184,4);
        auVar165 = NEON_smax(auVar165,auVar201,4);
      } while (uVar109 != 0);
      auVar145 = NEON_smax(auVar147,auVar165,4);
      iVar89 = NEON_smaxv(auVar145,4);
      piVar118 = piVar118 + uVar103;
      if (uVar99 == uVar103) goto LAB_0010c240;
    }
    iVar159 = uVar141 - uVar128;
    do {
      iVar11 = *piVar118;
      iVar173 = -iVar11;
      if (-1 < iVar11) {
        iVar173 = iVar11;
      }
      if (iVar89 <= iVar173) {
        iVar89 = iVar173;
      }
      iVar159 = iVar159 + -1;
      piVar118 = piVar118 + 1;
    } while (iVar159 != 0);
  }
LAB_0010c240:
  iVar159 = ((int)lVar101 + 0x400) * iVar155;
  plVar3 = param_1 + 0x1c;
  if (iVar137 <= iVar89) {
    iVar137 = iVar89;
  }
  *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x4c)) = iVar89;
  if (iVar91 == 1) {
    ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),iVar137 == 0,0xf);
    if (iVar137 == 0) {
      local_520 = (iVar90 - (int)LZCOUNT(local_518)) + 0x20;
      iVar91 = iVar90;
    }
    else {
      iVar91 = 1;
    }
    bVar35 = iVar137 != 0;
  }
  else {
    bVar35 = true;
  }
  puVar4 = PTR_in_shared_0011bd00;
  lVar98 = (long)(int)uVar10;
  lVar129 = (long)(int)param_1[1];
  lVar101 = (long)(uintptr_t)(uintptr_t)((plVar3)) + (long)((int)lVar101 * iVar155) * 4;
  uVar99 = (ulong)(int)uVar14;
  piVar118 = (ssc_i32_u *)(PTR_in_shared_0011bd00 + lVar129 * 4);
  iVar142 = uVar97 - (iVar142 + -0x1c >> 3);
  lVar100 = (long)(int)uVar178;
  uVar97 = 4;
  if (iVar93 == 0 && iVar122 != 0x18) {
    uVar97 = 0xc;
  }
  uVar128 = param_3 - 1;
  uVar109 = (ulong)uVar128;
  piVar117 = (ssc_i32_u *)(param_2);
  iVar122 = param_3;
  if ((7 < uVar128) &&
     ((param_2 + (ulong)uVar128 * 2 + 1 <= (const ssc_i32_u *)(piVar118) ||
      (PTR_in_shared_0011bd00 + (lVar129 + uVar109) * 4 + 4 <= (uint8_t *)(param_2))))) {
    uVar103 = uVar109 + 1;
    uVar123 = 8;
    if ((uVar103 & 7) != 0) {
      uVar123 = uVar103 & 7;
    }
    lVar132 = uVar103 - uVar123;
    iVar137 = (int)lVar132;
    puVar133 = (ssc_u64_u *)(PTR_in_shared_0011bd00 + lVar129 * 4 + 0x10);
    piVar118 = piVar118 + lVar132;
    lVar129 = lVar132 * 2;
    auVar148._4_4_ = uVar97;
    auVar148._0_4_ = uVar97;
    auVar148._8_4_ = uVar97;
    auVar148._12_4_ = uVar97;
    piVar130 = (ssc_i32_u *)(param_2 + 8);
    do {
      auVar166._0_4_ = *piVar130;
      auVar166._4_4_ = piVar130[2];
      auVar166._8_4_ = piVar130[4];
      auVar166._12_4_ = piVar130[6];
      lVar132 = lVar132 + -8;
      auVar202._0_4_ = piVar130[-8];
      auVar202._4_4_ = piVar130[-6];
      auVar202._8_4_ = piVar130[-4];
      auVar202._12_4_ = piVar130[-2];
      auVar145 = NEON_ushl(auVar166,auVar148,4);
      auVar144 = NEON_ushl(auVar202,auVar148,4);
      puVar133[-1] = auVar144._8_8_;
      puVar133[-2] = auVar144._0_8_;
      puVar133[1] = auVar145._8_8_;
      *puVar133 = auVar145._0_8_;
      puVar133 = puVar133 + 4;
      piVar117 = (ssc_i32_u *)(param_2 + lVar129);
      piVar130 = piVar130 + 0x10;
      iVar122 = param_3 - iVar137;
    } while (lVar132 != 0);
  }
  lVar132 = (long)iVar159;
  lVar129 = (long)(uintptr_t)(uintptr_t)((plVar3)) + (long)iVar159 * 4;
  do {
    iVar122 = iVar122 + -1;
    *piVar118 = *piVar117 << (ulong)uVar97;
    piVar118 = piVar118 + 1;
    piVar117 = piVar117 + 2;
  } while (iVar122 != 0);
  lVar94 = (long)param_3;
  lVar125 = lVar94 + ((int)param_1[1] << 1);
  piVar118 = (ssc_i32_u *)(param_2 + 1);
  piVar117 = (ssc_i32_u *)(puVar4 + lVar125 * 4);
  iVar122 = param_3;
  if ((7 < uVar128) &&
     ((param_2 + (ulong)uVar128 * 2 + 2 <= (const ssc_i32_u *)(piVar117) ||
      (puVar4 + (lVar125 + uVar109) * 4 + 4 <= (undefined *)(piVar118))))) {
    uVar109 = uVar109 + 1;
    uVar103 = 8;
    if ((uVar109 & 7) != 0) {
      uVar103 = uVar109 & 7;
    }
    lVar134 = uVar109 - uVar103;
    iVar137 = (int)lVar134;
    puVar133 = (ssc_u64_u *)(puVar4 + lVar125 * 4 + 0x10);
    piVar117 = piVar117 + lVar134;
    piVar118 = piVar118 + lVar134 * 2;
    auVar149._4_4_ = uVar97;
    auVar149._0_4_ = uVar97;
    auVar149._8_4_ = uVar97;
    auVar149._12_4_ = uVar97;
    piVar130 = (ssc_i32_u *)(param_2 + 9);
    do {
      auVar167._0_4_ = *piVar130;
      auVar167._4_4_ = piVar130[2];
      auVar167._8_4_ = piVar130[4];
      auVar167._12_4_ = piVar130[6];
      lVar134 = lVar134 + -8;
      auVar203._0_4_ = piVar130[-8];
      auVar203._4_4_ = piVar130[-6];
      auVar203._8_4_ = piVar130[-4];
      auVar203._12_4_ = piVar130[-2];
      auVar145 = NEON_ushl(auVar167,auVar149,4);
      auVar144 = NEON_ushl(auVar203,auVar149,4);
      puVar133[-1] = auVar144._8_8_;
      puVar133[-2] = auVar144._0_8_;
      puVar133[1] = auVar145._8_8_;
      *puVar133 = auVar145._0_8_;
      puVar133 = puVar133 + 4;
      piVar130 = piVar130 + 0x10;
      iVar122 = param_3 - iVar137;
    } while (lVar134 != 0);
  }
  do {
    iVar122 = iVar122 + -1;
    *piVar117 = *piVar118 << (ulong)uVar97;
    puVar4 = PTR__pre_shared_0011bce0;
    piVar118 = piVar118 + 2;
    piVar117 = piVar117 + 1;
  } while (iVar122 != 0);
  puVar5 = PTR__pre_shared_0011bce0 + (lVar94 + 0x400U) * 4;
  SSC_COPY32((uint64_t)(uintptr_t)(PTR__pre_shared_0011bce0),lVar101,0x400);
  puVar95 = PTR_in_shared_0011bd00;
  SSC_COPY32((uint64_t)(uintptr_t)(puVar4 + 0x1000),(uint64_t)(uintptr_t)(PTR_in_shared_0011bd00 + (long)(int)param_1[1] * 4),param_3);
  lVar125 = lVar101 + 0x1000;
  SSC_COPY32((uint64_t)(uintptr_t)(puVar5),lVar125,0x400);
  puVar111 = puVar5 + 0x1000;
  SSC_COPY32((uint64_t)(uintptr_t)(puVar111),(uint64_t)(uintptr_t)(puVar95 + (long)(int)param_1[1] * 4 + (long)((int)param_1[1] + param_3) * 4),
             param_3);
  if (iVar142 < 0x19 || !bVar35) {
    sVar88 = 0;
    local_360[0] = 0xf;
  }
  else {
    ssc_pitch_downsample((ssc_i32_u *)(PTR__pre_shared_0011bce0),(ssc_i32_u *)(puVar5),(ssc_i16_u *)(puVar95),lVar94 + 0x400U & 0xffffffff);
    ssc_pitch_search((ssc_u16_u *)(puVar95 + 0x400),(ssc_u16_u *)(puVar95),param_3,0x3d3,local_360);
    local_360[0] = 0x400 - local_360[0];
    sVar88 = ssc_remove_doubling((int64_t)(uintptr_t)(puVar95),0x400,0xf,param_3,(ssc_u32_u *)(local_360),(int)param_1[7],
                                 *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x3c)));
    if (0x3fe < local_360[0]) {
      local_360[0] = 0x3fe;
    }
    sVar88 = (short)((uint)(sVar88 * 0x599a) >> 0xf);
    puVar95 = PTR_in_shared_0011bd00;
  }
  iVar137 = (int)param_1[7];
  iVar89 = local_360[0] - iVar137;
  iVar122 = -iVar89;
  if (-1 < iVar89) {
    iVar122 = iVar89;
  }
  sVar171 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x3c));
  uVar218 = 0x3334;
  if (iVar122 * 10 <= local_360[0]) {
    uVar218 = 0x199a;
  }
  uVar221 = uVar218 + 0xccd;
  if (0x22 < iVar142) {
    uVar221 = uVar218;
  }
  uVar218 = uVar218 + 0x199a;
  if (0x18 < iVar142) {
    uVar218 = uVar221;
  }
  uVar221 = uVar218 - 0xccd;
  if (sVar171 < 0x3334) {
    uVar221 = uVar218;
  }
  iVar122 = (int)sVar171;
  uVar218 = uVar218 + 0xe666;
  if (iVar122 < 0x4667) {
    uVar218 = uVar221;
  }
  if (uVar218 < 0x199b) {
    uVar218 = 0x199a;
  }
  iVar89 = (int)sVar88;
  iVar159 = (int)(short)uVar218;
  if (sVar88 < iVar159) {
    local_5ac = 0;
    iVar122 = 0;
  }
  else {
    uVar128 = iVar89 - iVar122;
    uVar97 = -uVar128;
    if (-1 < (int)uVar128) {
      uVar97 = uVar128;
    }
    if (0xccc < uVar97) {
      iVar122 = iVar89;
    }
    if (0xccc < uVar97) {
      sVar171 = sVar88;
    }
    uVar97 = (iVar122 + 0x600 >> 10) * 0x56;
    iVar122 = (int)(char)(((byte)(uVar97 >> 0xf) & 1) + (char)(uVar97 >> 8) + -1);
    if (6 < iVar122) {
      iVar122 = 7;
    }
    local_5ac = 0;
    if (0x5ff < sVar171) {
      local_5ac = iVar122;
    }
    iVar122 = local_5ac * 0xc00 + 0xc00;
  }
  if (iVar137 < 0x10) {
    iVar137 = 0xf;
  }
  *(ssc_i32_u *)(param_1 + 7) = iVar137;
  SSC_COPY32((uint64_t)(uintptr_t)(puVar95),(uint64_t)(uintptr_t)(plVar3),(int)param_1[1]);
  puVar4 = puVar4 + 0x1000;
  ssc_comb_filter((int64_t)(uintptr_t)(puVar95 + (long)(int)param_1[1] * 4),(int64_t)(uintptr_t)(puVar4),(int)param_1[7],local_360[0],param_3,
                  -(uint)*(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x3c)),-iVar122,(int)param_1[1]);
  lVar134 = lVar94 * 4;
  SSC_COPY32((uint64_t)(uintptr_t)(plVar3),(uint64_t)(uintptr_t)(puVar95 + lVar134),(int)param_1[1]);
  SSC_COPY32(lVar101,lVar101 + lVar134,0x400 - param_3);
  SSC_COPY32(lVar125 + lVar94 * -4,(uint64_t)(uintptr_t)(puVar4),param_3);
  SSC_COPY32((ulong)(uintptr_t)(uintptr_t)(((puVar95 + (long)((int)param_1[1] + param_3) * 4))),
             (ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + (long)(int)param_1[1] * 4 + 0xe0), (int)param_1[1]);
  ssc_comb_filter((int64_t)(uintptr_t)(puVar95 + (long)(int)param_1[1] * 4 + (long)((int)param_1[1] + param_3) * 4),
                  (int64_t)(uintptr_t)(puVar111),(int)param_1[7],local_360[0],param_3,
                  -(uint)*(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x3c)),-iVar122,(int)param_1[1]);
  SSC_COPY32((ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + (long)(int)param_1[1] * 4 + 0xe0),
             (ulong)(uintptr_t)(uintptr_t)(((puVar95 + lVar134 + (long)((int)param_1[1] + param_3) * 4))), (int)param_1[1]);
  SSC_COPY32(lVar125,lVar125 + lVar134,0x400 - param_3);
  SSC_COPY32(lVar101 + lVar94 * -4 + 0x2000,(uint64_t)(uintptr_t)(puVar111),param_3);
  iVar137 = local_360[0];
  if (iVar89 < iVar159) {
    if (iVar91 + 0x10 <= iVar90) {
      ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),0,1);
    }
  }
  else {
    ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),1,1);
    iVar91 = iVar137 + 1;
    iVar173 = (int)LZCOUNT(iVar91);
    uVar97 = 0x1b - iVar173;
    ssc_ec_enc_uint((ssc_i64_u *)(auStack_538),uVar97,6);
    ssc_ec_enc_bits((ssc_i64_u *)(auStack_538),(-0x10 << (ulong)(uVar97 & 0x1f)) + iVar91,0x1f - iVar173);
    ssc_ec_enc_bits((ssc_i64_u *)(auStack_538),local_5ac,3);
  }
  uVar105 = local_518;
  iVar11 = local_520;
  puVar5 = PTR_in_shared_0011bd00;
  puVar111 = PTR__pre_shared_0011bce0;
  iVar91 = piVar136[7];
  piVar118 = piVar136 + 0x10;
  iVar173 = piVar136[1];
  puVar4 = PTR__pre_shared_0011bce0 + 0x1e60;
  ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(PTR_in_shared_0011bd00),(ssc_u32_u *)(puVar4),iVar173,0,1);
  ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar5 + (long)(iVar91 * 8 + iVar173) * 4),
                   (ssc_u32_u *)(puVar4 + (long)(iVar91 * 8) * 4),iVar173,0,1);
  if ((param_5 < 0x2ee00) &&
     (lVar101 = (long)*(ssc_i16_u *)(uintptr_t)((lVar108 + (long)(int)(uVar178 - 1) * 2)), lVar101 < 0x6c)) {
    lVar125 = lVar101 * 8;
    iVar91 = (int)lVar125;
    if (iVar91 < 0x360) {
      iVar91 = 0x35f;
    }
    uVar109 = (ulong)(iVar91 + 1) + lVar101 * -8;
    if (3 < uVar109) {
      uVar123 = uVar109 & 0xfffffffffffffffc;
      lVar125 = uVar123 + lVar125;
      puVar133 = (ssc_u64_u *)(puVar111 + lVar101 * 0x20 + 0x1e60);
      uVar103 = uVar123;
      do {
        puVar133[1] = 0;
        *puVar133 = 0;
        uVar103 = uVar103 - 4;
        puVar133[0x1b1] = 0;
        puVar133[0x1b0] = 0;
        puVar133 = puVar133 + 2;
      } while (uVar103 != 0);
      if (uVar109 == uVar123) goto LAB_0010c9e0;
    }
    puVar119 = (ssc_u32_u *)(puVar111 + lVar125 * 4 + 0x1e60);
    lVar125 = (ulong)(iVar91 + 1) - lVar125;
    do {
      *puVar119 = 0;
      lVar125 = lVar125 + -1;
      puVar119[0x360] = 0;
      puVar119 = puVar119 + 1;
    } while (lVar125 != 0);
  }
LAB_0010c9e0:
  if (iVar93 == 0) {
    normal_headroom((int64_t)(uintptr_t)(puVar111 + 0x1e60),param_5,8,lVar108,param_3);
  }
  else {
    uhq_headroom((int64_t)(uintptr_t)(puVar111 + 0x1e60),param_5,8,lVar108);
  }
  ssc_compute_band_energies((int64_t)(uintptr_t)(piVar136),(int64_t)(uintptr_t)(puVar111 + 0x1e60),(int64_t)(uintptr_t)(local_360),uVar178);
  ssc_amp2Log2((undefined8)(uintptr_t)(piVar136),uVar178,(int64_t)(uintptr_t)(local_360),(int64_t)(uintptr_t)(local_3b8));
  if (0 < (int)uVar14) {
    memcpy((void *)(&local_410),(const void *)(local_3b8),(ulong)uVar14 << 1);
  }
  if ((iVar90 < local_520 + (int)LZCOUNT(local_518) + -0x1d) ||
     (iVar91 = ssc_patch_transient_decision
                         (local_3b8,(ssc_i16_u *)(uintptr_t)(lVar129),lVar98,
                          *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - *(ssc_i32_u *)PTR_previous_uhq_index_0011bcd0),
     puVar4 = PTR_in_shared_0011bd00, iVar91 == 0)) {
    local_63c = 0;
    uVar97 = 0;
    local_630 = 0;
    bVar84 = true;
  }
  else {
    iVar91 = piVar136[1];
    iVar173 = piVar136[7];
    lVar101 = (long)iVar173;
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(PTR_in_shared_0011bd00),(ssc_u32_u *)(puVar111 + 0x1e60),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 4),(ssc_u32_u *)(puVar111 + 0x1e64),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 8),(ssc_u32_u *)(puVar111 + 0x1e68),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0xc),(ssc_u32_u *)(puVar111 + 0x1e6c),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x10),(ssc_u32_u *)(puVar111 + 0x1e70),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x14),(ssc_u32_u *)(puVar111 + 0x1e74),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x18),(ssc_u32_u *)(puVar111 + 0x1e78),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x1c),(ssc_u32_u *)(puVar111 + 0x1e7c),iVar91,3,8);
    puVar111 = puVar111 + 0x1e60 + lVar101 * 0x20;
    puVar4 = puVar4 + (long)(iVar91 + iVar173 * 8) * 4;
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4),(ssc_u32_u *)(puVar111),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 4),(ssc_u32_u *)(puVar111 + 4),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 8),(ssc_u32_u *)(puVar111 + 8),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0xc),(ssc_u32_u *)(puVar111 + 0xc),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x10),(ssc_u32_u *)(puVar111 + 0x10),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x14),(ssc_u32_u *)(puVar111 + 0x14),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x18),(ssc_u32_u *)(puVar111 + 0x18),iVar91,3,8);
    ssc_mdct_forward(piVar118,(int64_t)(uintptr_t)(puVar4 + lVar101 * 0x1c),(ssc_u32_u *)(puVar111 + 0x1c),iVar91,3,8);
    if (((param_5 < 0x2ee00) && (iVar93 == 0)) &&
       (lVar101 = (long)*(ssc_i16_u *)(uintptr_t)((lVar108 + (long)(int)(uVar178 - 1) * 2)), lVar101 < 0x6c)) {
      lVar125 = lVar101 * 8;
      iVar91 = (int)lVar125;
      if (iVar91 < 0x360) {
        iVar91 = 0x35f;
      }
      uVar109 = (ulong)(iVar91 + 1) + lVar101 * -8;
      if (3 < uVar109) {
        uVar123 = uVar109 & 0xfffffffffffffffc;
        lVar125 = uVar123 + lVar125;
        puVar133 = (ssc_u64_u *)(PTR__pre_shared_0011bce0 + lVar101 * 0x20 + 0x1e60);
        uVar103 = uVar123;
        do {
          puVar133[1] = 0;
          *puVar133 = 0;
          uVar103 = uVar103 - 4;
          puVar133[0x1b1] = 0;
          puVar133[0x1b0] = 0;
          puVar133 = puVar133 + 2;
        } while (uVar103 != 0);
        if (uVar109 == uVar123) goto LAB_0010cdcc;
      }
      lVar101 = (ulong)(iVar91 + 1) - lVar125;
      puVar119 = (ssc_u32_u *)(PTR__pre_shared_0011bce0 + lVar125 * 4 + 0x1e60);
      do {
        *puVar119 = 0;
        lVar101 = lVar101 + -1;
        puVar119[0x360] = 0;
        puVar119 = puVar119 + 1;
      } while (lVar101 != 0);
    }
LAB_0010cdcc:
    puVar111 = PTR__pre_shared_0011bce0;
    if (iVar93 == 0) {
      normal_headroom((int64_t)(uintptr_t)(PTR__pre_shared_0011bce0 + 0x1e60),param_5,8,lVar108,param_3);
    }
    else {
      uhq_headroom((int64_t)(uintptr_t)(PTR__pre_shared_0011bce0 + 0x1e60),param_5,8,lVar108);
    }
    ssc_compute_band_energies((int64_t)(uintptr_t)(piVar136),(int64_t)(uintptr_t)(puVar111 + 0x1e60),(int64_t)(uintptr_t)(local_360),uVar116);
    ssc_amp2Log2((undefined8)(uintptr_t)(piVar136),uVar178,(int64_t)(uintptr_t)(local_360),(int64_t)(uintptr_t)(local_3b8));
    uVar97 = uVar10 * 2;
    for (int i = 0; i < (int)uVar97; i++) {
      ((ssc_i16_u *)&local_410)[i] += 0x600;
    }
LAB_0010cec8:
    uVar97 = 1;
    bVar84 = false;
    local_630 = 8;
    local_63c = 0xccd;
  }
  if (local_520 + (int)LZCOUNT(local_518) + -0x1d <= iVar90) {
    ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),uVar97,3);
  }
  if (iVar93 == 0) {
    ssc_compute_band_energies_for_lastband((int64_t)(uintptr_t)(piVar136),(int64_t)(uintptr_t)(puVar111 + 0x1e60),&local_500,4,0,0);
    if (local_4e4 + local_4f4 < 0x7532) {
      if (local_4e8 + local_4f8 < 0x7532) {
        cVar96 = (0x7531 < local_4ec + local_4fc) << 2;
      }
      else {
        cVar96 = '\b';
      }
    }
    else {
      cVar96 = '\f';
    }
    uVar128 = 0;
    *local_570 = cVar96 + *local_570;
  }
  else {
    bVar87 = *(char *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + 3)) == -0x1a;
    uVar128 = (uint)bVar87 << 2;
    if ((!bVar87) && (iVar154 != 0)) {
      uVar128 = 0;
      cVar96 = '\b';
      do {
        ssc_compute_band_energies_for_lastband
                  ((int64_t)(uintptr_t)(piVar136),(int64_t)(uintptr_t)(puVar111 + 0x1e60),&local_500,8,iVar93,uVar128);
        if (0x2ee1 < local_4c4 + local_4e4) goto LAB_0010d0e0;
        if (0x2ee1 < local_4c8 + local_4e8) {
          cVar96 = '\a';
          goto LAB_0010d0e0;
        }
        if (0x2ee1 < local_4cc + local_4ec) {
          cVar96 = '\x06';
          goto LAB_0010d0e0;
        }
        if (0x2ee1 < local_4d0 + local_4f0) {
          cVar96 = '\x05';
          goto LAB_0010d0e0;
        }
        if (0x2ee1 < local_4d4 + local_4f4) {
          cVar96 = '\x04';
          goto LAB_0010d0e0;
        }
        if (0x2ee1 < local_4d8 + local_4f8) {
          cVar96 = '\x03';
          goto LAB_0010d0e0;
        }
        if (0x2ee1 < local_4dc + local_4fc) {
          cVar96 = '\x02';
          goto LAB_0010d0e0;
        }
        if (0x2ee1 < local_4e0 + local_500) {
          cVar96 = '\x01';
          goto LAB_0010d0e0;
        }
        uVar128 = uVar128 + 1;
      } while (uVar128 != 4);
      cVar96 = '\0';
      uVar128 = 3;
LAB_0010d0e0:
      bVar8 = 0;
      if (cVar96 != '\0') {
        bVar8 = cVar96 * ' ' - 0x20;
      }
      *(char *)(param_4 + 1) = *(char *)(param_4 + 1) + (char)uVar128 * '\x04';
      *(byte *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + 3)) = bVar8 | *(byte *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + 3)) & 0x1f;
    }
  }
  ssc_normalise_bands((int64_t)(uintptr_t)(piVar136),(undefined1 (*)[16])(puVar111 + 0x1e60),(ssc_u64_u *)(puVar111 + 0x1e60),(ssc_u32_u *)(local_360),*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - uVar128);
  puVar4 = PTR_in_shared_0011bd00;
  if ((iVar93 == 0) && (iVar155 * 0xf <= (int)uVar9)) {
    if (uVar9 < 0x28) {
      iVar154 = 0x18;
    }
    else if (uVar9 < 0x3c) {
      iVar154 = 0xc;
    }
    else {
      iVar154 = 8;
      if (99 < uVar9) {
        iVar154 = 6;
      }
    }
    iVar91 = 3;
    if (uVar97 == 0) {
      iVar91 = 0;
    }
    if ((int)uVar178 < 1) {
LAB_0010d898:
      uVar141 = 0;
      local_4c0[lVar100 + -1] = uVar97;
    }
    else {
      uVar141 = (0x2000 - local_63c) * 0x51f >> 0xe;
      uVar109 = 0;
      do {
        uVar103 = uVar109 + 1;
        lVar101 = *(ssc_i64_u *)(piVar136 + 4);
        sVar88 = *(ssc_i16_u *)(uintptr_t)((lVar101 + uVar109 * 2));
        iVar175 = (int)*(ssc_i16_u *)(uintptr_t)((lVar101 + uVar103 * 2));
        iVar173 = iVar175 - sVar88;
        uVar131 = iVar173 * 8;
        if (0 < iVar173) {
          memcpy((void *)((ssc_i16_u *)(puVar4 + 0x108)), (const void *)(((ssc_i16_u *)(puVar111 + 0x1e60)) + sVar88 * 8), (size_t)uVar131 * sizeof(short));
        }
        int sum_raw = 0;
        ssc_i16_u *p_raw = (ssc_i16_u *)(puVar4 + 0x108);
        for (int i = 0; i < (int)uVar131; i++) {
          int v = p_raw[i];
          sum_raw += (v < 0) ? -v : v;
        }
        uVar139 = sum_raw;
        iVar138 = uVar139 + ((uVar139 & 0x7fff) * uVar141 * iVar91 >> 0xf) +
                  ((int)(uVar139 << 1) >> 0x10) * uVar141 * iVar91;
        if (uVar109 < 4) {;
          for (int i = 0; i < 8; i++);;
        }
        if (bVar84 || iVar173 == 1) {
          iVar153 = 0;
          iVar175 = iVar138;
        }
        else {
          if (0 < iVar173) {
            memcpy((void *)((ssc_i16_u *)(puVar4 + 0x348)), (const void *)((ssc_i16_u *)(puVar4 + 0x108)), (size_t)uVar131 * sizeof(short));
          }
          psVar121 = (ssc_i16_u *)(puVar4 + 0x348);
          ssc_haar1(psVar121, iVar173, 8);
          int sum_haar8 = 0;
          for (int i = 0; i < (int)uVar131; i++) {
            int v = psVar121[i];
            sum_haar8 += (v < 0) ? -v : v;
          }
          uVar139 = sum_haar8;
          iVar153 = uVar139 + ((uVar139 & 0x7fff) * uVar141 * 4 >> 0xf) +
                    ((int)(uVar139 << 1) >> 0x10) * uVar141 * 4;
          iVar175 = iVar153;
          if (iVar138 <= iVar153) {
            iVar175 = iVar138;
          }
          iVar153 = -(uint)(iVar153 < iVar138);
        }
        uVar139 = 3;
        if (uVar97 == 0 && iVar173 != 1) {
          uVar139 = 4;
        }
        uVar106 = 0;
        do {
          psVar121 = (ssc_i16_u *)(puVar4 + 0x108);
          ssc_haar1(psVar121, (int)uVar131 >> (uVar106 & 0x1f), 1 << (ulong)(uVar106 & 0x1f));
          int sum_haar = 0;
          for (int i = 0; i < (int)uVar131; i++) {
            int v = psVar121[i];
            sum_haar += (v < 0) ? -v : v;
          }
          uVar140 = sum_haar;
          iVar138 = 2 - uVar106;
          if (uVar97 == 0) {
            iVar138 = uVar106 + 1;
          }
          iVar138 = (int)(uVar141 * 0x10000 * iVar138) >> 0x10;
          iVar138 = uVar140 + ((int)((uVar140 & 0x7fff) * iVar138) >> 0xf) +
                    ((int)(uVar140 << 1) >> 0x10) * iVar138;
          if (uVar109 == 2) {;
          }
          uVar140 = uVar106 + 1;
          if (iVar138 < iVar175) {
            iVar153 = uVar106 + 1;
            iVar175 = iVar138;
          }
          uVar106 = uVar140;
        } while (uVar140 != uVar139);
        if (uVar109 == 2) {;
        }
        iVar175 = iVar153 * -2;
        if (uVar97 != 0) {
          iVar175 = iVar153 * 2;
        }
        *(ssc_i32_u *)(puVar4 + uVar109 * 4) = iVar175;
        if ((iVar173 == 1) && (iVar175 == 0 || iVar175 == -6)) {
          *(ssc_i32_u *)(puVar4 + uVar109 * 4) = iVar175 + -1;
        }
        {
          static int f0 = 0;
          if (f0 < 22) {;
            f0++;
          }
        }
        puVar111 = PTR__pre_shared_0011bce0;
        uVar109 = uVar103;
      } while (uVar103 != uVar116);
      iVar91 = iVar154;
      if (!bVar84) {
        iVar91 = 0;
      }
      if ((int)uVar178 < 2) goto LAB_0010d898;
      uVar109 = (ulong)uVar97 * 4;
      iVar173 = 0;
      lVar125 = uVar116 - 1;
      lVar101 = lVar125;
      iVar175 = iVar91;
      piVar118 = (ssc_i32_u *)puVar4;
      do {
        piVar118 = piVar118 + 1;
        iVar138 = iVar173;
        if (iVar175 + iVar154 <= iVar173) {
          iVar138 = iVar175 + iVar154;
        }
        iVar153 = iVar173 + iVar154;
        if (iVar175 <= iVar173 + iVar154) {
          iVar153 = iVar175;
        }
        iVar175 = *piVar118 + (char)PTR_ssc_tf_select_table_0011bcc8[uVar109] * -2;
        iVar173 = -iVar175;
        if (-1 < iVar175) {
          iVar173 = iVar175;
        }
        iVar156 = *piVar118 + (char)PTR_ssc_tf_select_table_0011bcc8[uVar109 | 1] * -2;
        iVar173 = iVar173 + iVar138;
        iVar175 = -iVar156;
        if (-1 < iVar156) {
          iVar175 = iVar156;
        }
        iVar175 = iVar175 + iVar153;
        lVar101 = lVar101 + -1;
      } while (lVar101 != 0);
      iVar138 = 0;
      lVar101 = lVar125;
      piVar118 = (ssc_i32_u *)puVar4;
      do {
        piVar118 = piVar118 + 1;
        iVar153 = iVar138;
        if (iVar91 + iVar154 <= iVar138) {
          iVar153 = iVar91 + iVar154;
        }
        iVar156 = iVar138 + iVar154;
        if (iVar91 <= iVar138 + iVar154) {
          iVar156 = iVar91;
        }
        iVar91 = *piVar118 + (char)PTR_ssc_tf_select_table_0011bcc8[uVar109 | 2] * -2;
        iVar138 = -iVar91;
        if (-1 < iVar91) {
          iVar138 = iVar91;
        }
        iVar157 = *piVar118 + (char)PTR_ssc_tf_select_table_0011bcc8[uVar109 | 3] * -2;
        iVar138 = iVar138 + iVar153;
        iVar91 = -iVar157;
        if (-1 < iVar157) {
          iVar91 = iVar157;
        }
        iVar91 = iVar91 + iVar156;
        lVar101 = lVar101 + -1;
      } while (lVar101 != 0);
      iVar153 = 0;
      if (iVar175 <= iVar173) {
        iVar173 = iVar175;
      }
      if (iVar91 <= iVar138) {
        iVar138 = iVar91;
      }
      uVar141 = uVar97 & iVar138 < iVar173;
      uVar131 = 2;
      if (uVar141 == 0) {
        uVar131 = 0;
      }
      uVar116 = (ulong)(uVar131 | (uint)uVar109);
      iVar91 = 0;
      if (uVar97 == 0) {
        iVar91 = iVar154;
      }
      cVar96 = PTR_ssc_tf_select_table_0011bcc8[uVar116];
      cVar12 = PTR_ssc_tf_select_table_0011bcc8[uVar116 | 1];
      puVar110 = (ssc_u32_u *)(puVar4 + 0x5c);
      do {
        iVar173 = iVar91 + iVar154;
        iVar175 = iVar153 + iVar154;
        iVar138 = iVar153;
        if (iVar173 <= iVar153) {
          iVar138 = iVar173;
        }
        iVar156 = iVar175;
        if (iVar91 <= iVar175) {
          iVar156 = iVar91;
        }
        iVar157 = puVar110[-0x16] + cVar96 * -2;
        *puVar110 = (uint)(iVar173 <= iVar153);
        iVar153 = -iVar157;
        if (-1 < iVar157) {
          iVar153 = iVar157;
        }
        iVar173 = puVar110[-0x16] + cVar12 * -2;
        iVar157 = -iVar173;
        if (-1 < iVar173) {
          iVar157 = iVar173;
        }
        puVar110[0x16] = (uint)(iVar91 <= iVar175);
        iVar153 = iVar153 + iVar138;
        iVar91 = iVar157 + iVar156;
        lVar125 = lVar125 + -1;
        puVar110 = puVar110 + 1;
      } while (lVar125 != 0);
      local_4c0[lVar100 + -1] = (uint)(iVar91 <= iVar153);
      lVar101 = (ulong)(uVar178 - 2) << 2;
      do {
        puVar5 = puVar4 + 0xb0;
        if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((local_4c0)) + lVar101 + 4)) != 1) {
          puVar5 = puVar4 + 0x58;
        }
        lVar125 = lVar101 + -4;
        *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((local_4c0)) + lVar101)) = *(ssc_u32_u *)(puVar5 + lVar101 + 4);
        lVar101 = lVar125;
      } while (lVar125 != -4);
    }
    uVar131 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
    uVar116 = (ulong)uVar131;
    local_4c0[0] = uVar97;
    local_4c0[1] = uVar97;
    if ((int)uVar178 < (int)uVar131) {
      lVar101 = (int)uVar131 - lVar100;
      puVar110 = local_4c0 + lVar100;
      do {
        lVar101 = lVar101 + -1;
        *puVar110 = local_4c0[lVar100 + -1];
        puVar110 = puVar110 + 1;
      } while (lVar101 != 0);
    }
  }
  else {
    uVar141 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
    uVar116 = (ulong)uVar141;
    if (0 < (int)uVar141) {
      for (int i = 0; i < (int)uVar141; i++) {
        local_4c0[i] = uVar97;
      }
    }
LAB_0010d1ec:
    uVar141 = 0;
  }
  ssc_quant_coarse_energy
            ((int64_t)(uintptr_t)(piVar136),uVar116,uVar178 - uVar128,(int64_t)(uintptr_t)(local_3b8),lVar129,iVar90,(undefined8)(uintptr_t)(auStack_468),(ssc_i64_u *)(auStack_538),
             iVar142,(int)param_1[2],(ssc_u32_u *)(uintptr_t)((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24));
  { static int f = 0; if (f++ == 0); }
  {
    static int f_tf = 0;
    if (f_tf++ == 0) {
      for (int i = 0; i < (int)*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)); i++) {;
      }
    }
  }
  uVar115 = local_4c0[0];
  uVar131 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
  uVar116 = (ulong)uVar131;
  if (iVar93 == 0) {
    iVar91 = local_520 + (int)LZCOUNT(local_518) + -0x20;
    iVar154 = 4;
    iVar93 = iVar154;
    if (!bVar84) {
      iVar93 = 2;
    }
    uVar106 = local_530 * 8;
    uVar139 = iVar91 + iVar93 + 1;
    if (bVar84) {
      iVar154 = 5;
    }
    uVar140 = uVar106 - (uVar139 <= uVar106);;;
    if (uVar140 < (uint)(iVar91 + iVar93)) {
      uVar115 = 0;
      local_4c0[0] = 0;
    }
    else {
      ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),local_4c0[0],iVar93);
      iVar91 = local_520 + (int)LZCOUNT(local_518) + -0x20;
    }
    puVar110 = local_4c0;
    uVar107 = uVar115;
    puVar4 = PTR_ssc_tf_select_table_0011bcc8;
    puVar111 = PTR__pre_shared_0011bce0;
    while( true ) {
      uVar131 = uVar131 - 1;
      puVar110 = puVar110 + 1;


      if (uVar131 == 0) break;
      if (uVar140 < (uint)(iVar91 + iVar154)) {
        *puVar110 = uVar115;
      }
      else {
        ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),*puVar110 ^ uVar115,iVar154);
        uVar115 = *puVar110;
        iVar91 = local_520 + (int)LZCOUNT(local_518) + -0x20;
        uVar107 = uVar115 | uVar107;
        puVar4 = PTR_ssc_tf_select_table_0011bcc8;
        puVar111 = PTR__pre_shared_0011bce0;
      }
    }
    uVar109 = (ulong)uVar97 * 4;;;
    if (uVar106 < uVar139) {
      uVar131 = 0;
    }
    else if (puVar4[(long)(int)uVar107 + uVar109] == puVar4[(uVar109 | 2) + (long)(int)uVar107]) {
      uVar131 = 0;
    }
    else {
      ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),uVar141,1);
      uVar131 = 2;
      if (uVar141 == 0) {
        uVar131 = 0;
      }
    }
    do {
      puVar110 = puVar110 + -1;
      uVar141 = (int)uVar116 - 1;
      uVar116 = (ulong)uVar141;
      *puVar110 = (int)(char)puVar4[(long)(int)*puVar110 + (ulong)(uVar131 | (uint)uVar109)];
    } while (uVar141 != 0);
  }
  else if (0 < (int)uVar131) {
    memset((void *)(local_4c0),0,uVar116 << 2);
  };;
  if (local_520 + (int)LZCOUNT(local_518) + -0x1c <= iVar90) {
    if (uVar97 == 0 && iVar155 * 10 <= iVar142) {
      uVar92 = ssc_spreading_decision(param_1,(int64_t)(uintptr_t)(puVar111 + 0x1e60),iVar159 <= iVar89,uVar178 - uVar128);
    }
    else {
      uVar92 = 2;
    }
    *(ssc_u32_u *)(param_1 + 4) = uVar92;
    ssc_ec_enc_icdf((int64_t)(uintptr_t)(auStack_538),uVar92,(int64_t)(uintptr_t)(&DAT_00103d14),5);
  }
  puVar133 = *(ssc_u64_u **)(piVar136 + 0xe);
  uVar178 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - uVar128;
  uVar116 = (ulong)uVar178;
  if (0 < (int)uVar10) {
    memset((void *)(local_1f0),0,(ulong)uVar10 << 2);
  }
  if (0 < (int)uVar178) {
    if (uVar178 < 0x10) {
      uVar103 = 0;
    }
    else {
      auVar145 = ZEXT816(0xe600e600e600e600);
      uVar103 = uVar116 & 0xfffffff0;
      auVar189._4_4_ = UNK_00102744;
      auVar189._0_4_ = DAT_00102740;
      auVar189._8_4_ = UNK_00102748;
      auVar189._12_4_ = UNK_0010274c;
      auVar232._4_4_ = UNK_001027d4;
      auVar232._0_4_ = DAT_001027d0;
      auVar232._8_4_ = UNK_001027d8;
      auVar232._12_4_ = UNK_001027dc;
      puVar112 = (ssc_u64_u *)PTR_ssc_eMeans_tmp_0011bd08;
      psVar121 = local_128;
      uVar109 = uVar103;
      puVar127 = puVar133;
      auVar169 = *(vec128_t *)(ssc_image + 0x2790);
      iVar155 = DAT_001027b0;
      iVar154 = UNK_001027b4;
      iVar93 = UNK_001027b8;
      iVar142 = UNK_001027bc;
      do {
        uVar34 = puVar112[1];
        uVar143 = *puVar112;
        uVar279 = puVar127[1];
        uVar278 = *puVar127;
        sVar65 = *(ssc_i16_u *)(puVar127 + 2);
        sVar66 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar127)) + 0x12));
        sVar67 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar127)) + 0x14));
        sVar68 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar127)) + 0x16));
        sVar69 = *(ssc_i16_u *)(puVar127 + 3);
        sVar70 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar127)) + 0x1a));
        sVar71 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar127)) + 0x1c));
        sVar72 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar127)) + 0x1e));
        uVar109 = uVar109 - 0x10;
        sVar39 = auVar169._0_2_ + 5;
        iVar91 = auVar169._4_4_;
        sVar40 = auVar169._4_2_ + 5;
        iVar89 = auVar169._8_4_;
        sVar37 = auVar169._8_2_ + 5;
        iVar159 = auVar169._12_4_;
        sVar171 = auVar169._12_2_ + 5;
        sVar41 = (short)iVar155 + 5;
        sVar42 = (short)iVar154 + 5;
        sVar36 = (short)iVar93 + 5;
        sVar88 = (short)iVar142 + 5;
        sVar43 = auVar232._0_2_ + 5;
        iVar153 = auVar232._4_4_;
        sVar44 = auVar232._4_2_ + 5;
        iVar156 = auVar232._8_4_;
        sVar38 = auVar232._8_2_ + 5;
        iVar157 = auVar232._12_4_;
        sVar13 = auVar232._12_2_ + 5;
        sVar80 = auVar189._0_2_ + 5;
        iVar173 = auVar189._4_4_;
        sVar81 = auVar189._4_2_ + 5;
        iVar175 = auVar189._8_4_;
        sVar82 = auVar189._8_2_ + 5;
        iVar138 = auVar189._12_4_;
        sVar83 = auVar189._12_2_ + 5;
        sVar261 = auVar145._0_2_;
        sVar265 = auVar145._2_2_;
        sVar266 = auVar145._4_2_;
        sVar268 = auVar145._6_2_;
        auVar232._0_4_ = auVar232._0_4_ + 0x10;
        auVar232._4_4_ = iVar153 + 0x10;
        auVar232._8_4_ = iVar156 + 0x10;
        auVar232._12_4_ = iVar157 + 0x10;
        auVar189._0_4_ = auVar189._0_4_ + 0x10;
        auVar189._4_4_ = iVar173 + 0x10;
        auVar189._8_4_ = iVar175 + 0x10;
        auVar189._12_4_ = iVar138 + 0x10;
        auVar169._0_4_ = auVar169._0_4_ + 0x10;
        auVar169._4_4_ = iVar91 + 0x10;
        auVar169._8_4_ = iVar89 + 0x10;
        auVar169._12_4_ = iVar159 + 0x10;
        iVar155 = iVar155 + 0x10;
        iVar154 = iVar154 + 0x10;
        iVar93 = iVar93 + 0x10;
        iVar142 = iVar142 + 0x10;
        *(ssc_u64_u *)(psVar121 + 4) =
             CONCAT26(((short)((ulong)uVar279 >> 0x30) - (short)(char)((ulong)uVar143 >> 0x38)) *
                      0x40 + sVar83 * sVar83 * 6 + sVar268,
                      CONCAT24(((short)((ulong)uVar279 >> 0x20) -
                               (short)(char)((ulong)uVar143 >> 0x30)) * 0x40 + sVar82 * sVar82 * 6 +
                               sVar266,CONCAT22(((short)((ulong)uVar279 >> 0x10) -
                                                (short)(char)((ulong)uVar143 >> 0x28)) * 0x40 +
                                                sVar81 * sVar81 * 6 + sVar265,
                                                ((short)uVar279 -
                                                (short)(char)((ulong)uVar143 >> 0x20)) * 0x40 +
                                                sVar80 * sVar80 * 6 + sVar261)));
        *(ssc_u64_u *)psVar121 =
             CONCAT26(((short)((ulong)uVar278 >> 0x30) - (short)(char)((ulong)uVar143 >> 0x18)) *
                      0x40 + sVar13 * sVar13 * 6 + sVar268,
                      CONCAT24(((short)((ulong)uVar278 >> 0x20) -
                               (short)(char)((ulong)uVar143 >> 0x10)) * 0x40 + sVar38 * sVar38 * 6 +
                               sVar266,CONCAT22(((short)((ulong)uVar278 >> 0x10) -
                                                (short)(char)((ulong)uVar143 >> 8)) * 0x40 +
                                                sVar44 * sVar44 * 6 + sVar265,
                                                ((short)uVar278 - (short)(char)uVar143) * 0x40 +
                                                sVar43 * sVar43 * 6 + sVar261)));
        *(ssc_u64_u *)(psVar121 + 0xc) =
             CONCAT26((sVar72 - (char)((ulong)uVar34 >> 0x38)) * 0x40 + sVar88 * sVar88 * 6 +
                      sVar268,CONCAT24((sVar71 - (char)((ulong)uVar34 >> 0x30)) * 0x40 +
                                       sVar36 * sVar36 * 6 + sVar266,
                                       CONCAT22((sVar70 - (char)((ulong)uVar34 >> 0x28)) * 0x40 +
                                                sVar42 * sVar42 * 6 + sVar265,
                                                (sVar69 - (char)((ulong)uVar34 >> 0x20)) * 0x40 +
                                                sVar41 * sVar41 * 6 + sVar261)));
        *(ssc_u64_u *)(psVar121 + 8) =
             CONCAT26((sVar68 - (char)((ulong)uVar34 >> 0x18)) * 0x40 + sVar171 * sVar171 * 6 +
                      sVar268,CONCAT24((sVar67 - (char)((ulong)uVar34 >> 0x10)) * 0x40 +
                                       sVar37 * sVar37 * 6 + sVar266,
                                       CONCAT22((sVar66 - (char)((ulong)uVar34 >> 8)) * 0x40 +
                                                sVar40 * sVar40 * 6 + sVar265,
                                                (sVar65 - (char)uVar34) * 0x40 + sVar39 * sVar39 * 6
                                                + sVar261)));
        puVar112 = puVar112 + 2;
        psVar121 = psVar121 + 0x10;
        puVar127 = puVar127 + 4;
      } while (uVar109 != 0);
      if (uVar103 == uVar116) goto LAB_0010dce8;
    }
    iVar155 = (int)uVar103 * 0x10000 + 0x50000;
    do {
      uVar109 = uVar103 + 1;
      iVar154 = iVar155 * ((int)uVar103 + 5);
      iVar155 = iVar155 + 0x10000;
      local_128[uVar103] =
           (short)((uint)iVar154 >> 0x10) * 6 +
           (*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar133)) + uVar103 * 2)) -
           (short)(char)PTR_ssc_eMeans_tmp_0011bd08[uVar103]) * 0x40 + -0x1a00;
      uVar103 = uVar109;
    } while (uVar116 != uVar109);
  }
LAB_0010dce8:
  iVar155 = (int)(short)(ushort)local_410;
  if (uVar9 < 0x33) {
    sVar88 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar98 * 2));
  }
  else {
    uVar141 = (uint)(ushort)local_410;
    uVar109 = 0;
    local_cc = (local_cc & 0xffff0000U) | (uint16_t)(local_410);
    if (1 < (int)uVar178) {
      uVar103 = 1;
      uVar131 = uVar141;
      do {
        lVar101 = uVar103 * 2;
        sVar88 = (short)uVar131;
        uVar141 = (int)(short)uVar141 + 0x600;
        uVar218 = *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar101));
        uVar131 = (uint)uVar218;
        uVar115 = (uint)uVar103;
        if ((int)(short)uVar218 <= sVar88 + 0x200) {
          uVar115 = (uint)uVar109;
        }
        uVar109 = (ulong)uVar115;
        if ((int)(short)uVar218 <= (int)uVar141) {
          uVar141 = (int)(short)uVar218;
        }
        uVar103 = uVar103 + 1;
        *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar101)) = (short)uVar141;
      } while (uVar116 != uVar103);
      uVar141 = uVar115 - 1;
      if (0 < (int)uVar115) {
        uVar103 = uVar109;
        if (uVar141 != 0) {
          uVar123 = uVar109 - 1;
          if (((((uint)uVar123 <= uVar141) && (uVar123 >> 0x20 == 0)) &&
              (uVar135 = (long)(uintptr_t)(uintptr_t)((&local_cc)) + (ulong)uVar141 * 2, uVar135 + uVar123 * -2 <= uVar135))
             && ((!CARRY8(uVar123,uVar123) &&
                 (uVar135 = (long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar109 * 2, uVar135 + uVar123 * -2 <= uVar135)))) {
            if (((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar109 * 2 + 2 <=
                 (long)(uintptr_t)(uintptr_t)((&local_cc)) + (((ulong)uVar141 + 1) - uVar109) * 2) ||
               ((long)(uintptr_t)(uintptr_t)((&local_cc)) + ((ulong)uVar141 + 1) * 2 <= ((ulong)(uintptr_t)(uintptr_t)((&local_cc)) | 2))) {
              uVar103 = uVar109 + 0xffffffff;
              psVar121 = &local_ce + uVar109;
              uVar123 = uVar109 & 0xfffffffe;
              do {
                uVar135 = uVar103 & 0xffffffff;
                psVar104 = psVar121 + 1;
                psVar7 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar135 * 2));
                uVar123 = uVar123 - 2;
                uVar103 = uVar103 - 2;
                sVar88 = *psVar121;
                psVar121 = psVar121 + -2;
                uVar143 = NEON_smin(CONCAT44(sVar88 + 0x800,*psVar104 + 0x800),
                                    CONCAT44((int)local_414[uVar135 + 1],
                                             (int)*(ssc_i16_u *)(uintptr_t)(((uintptr_t)&local_410 + uVar135 * 2))),4);
                uVar143 = NEON_smin(uVar143,CONCAT44((int)(&local_ce)[uVar135],(int)*psVar7),4);
                uVar143 = NEON_rev64(uVar143,4);
                (&local_ce)[uVar135] = (short)uVar143;
                *psVar7 = (short)((ulong)uVar143 >> 0x20);
              } while (uVar123 != 0);
              uVar103 = uVar109 & 1;
              if ((uVar109 & 0xfffffffe) == uVar109) goto LAB_0010de24;
            }
          }
        }
        do {
          lVar101 = (uVar103 - 1 & 0xffffffff) * 2;
          iVar154 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar103 * 2)) + 0x800;
          if (*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar101)) <= iVar154) {
            iVar154 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar101));
          }
          iVar93 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar101));
          if (iVar154 <= *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar101))) {
            iVar93 = iVar154;
          }
          bVar87 = uVar103 != 0;
          uVar103 = uVar103 - 1;
          *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar101)) = (short)iVar93;
        } while (bVar87 && uVar103 != 0);
      }
    }
LAB_0010de24:
    uVar141 = (uint)uVar109;
    if (0 < (int)uVar178) {
      if (uVar178 < 0x10) {
        uVar123 = 0;
      }
      else {
        uVar123 = uVar116 & 0xfffffff0;
        pauVar120 = (undefined1 (*) [16])asStack_bc;
        pauVar124 = (undefined1 (*) [16])auStack_118;
        uVar103 = uVar123;
        do {
          uVar103 = uVar103 - 0x10;
          pauVar2 = pauVar124 + -1;
          auVar145 = *(vec128_t *)*pauVar124;
          pauVar124 = pauVar124 + 2;
          auVar144 = NEON_smax(*(vec128_t *)pauVar120[-1],*(vec128_t *)*pauVar2,2);
          auVar145 = NEON_smax(*(vec128_t *)*pauVar120,auVar145,2);
          *(ssc_i64_u *)(pauVar120[-1] + 8) = auVar144._8_8_;
          *(ssc_i64_u *)pauVar120[-1] = auVar144._0_8_;
          *(ssc_i64_u *)(*pauVar120 + 8) = auVar145._8_8_;
          *(ssc_i64_u *)*pauVar120 = auVar145._0_8_;
          pauVar120 = pauVar120 + 2;
        } while (uVar103 != 0);
        if (uVar123 == uVar116) goto LAB_0010dec4;
      }
      lVar101 = uVar116 - uVar123;
      psVar121 = local_128 + uVar123;
      psVar104 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar123 * 2));
      do {
        sVar88 = *psVar104;
        if (*psVar104 <= *psVar121) {
          sVar88 = *psVar121;
        }
        lVar101 = lVar101 + -1;
        *psVar104 = sVar88;
        psVar121 = psVar121 + 1;
        psVar104 = psVar104 + 1;
      } while (lVar101 != 0);
    }
LAB_0010dec4:
    lVar101 = lVar98 * 2;
    sVar88 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar101));
    *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar101)) = sVar88;
    if (1 < (int)uVar178) {
      lVar100 = 0;
      uVar131 = (uint)*(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar101));
      do {
        lVar125 = lVar100 * 2;
        psVar121 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar125 + lVar101));
        lVar100 = lVar100 + 1;
        uVar131 = (int)(short)uVar131 + 0x600;
        sVar171 = psVar121[1];
        uVar141 = (uint)lVar100;
        if ((int)sVar171 <= *psVar121 + 0x200) {
          uVar141 = (uint)uVar109;
        }
        uVar109 = (ulong)uVar141;
        if ((int)sVar171 <= (int)uVar131) {
          uVar131 = (int)sVar171;
        }
        *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar125 + lVar101 + 2)) = (short)uVar131;
      } while (uVar116 - 1 != lVar100);
    }
    if (0 < (int)uVar141) {
      uVar109 = (ulong)uVar141;
      if (uVar141 != 1) {
        uVar103 = uVar109 - 1;
        iVar154 = uVar141 + uVar10;
        if ((((iVar154 - (int)uVar103 <= iVar154 && uVar103 >> 0x20 == 0) &&
              (ssc_i16_u *)(uintptr_t)((long)(uintptr_t)(uintptr_t)(((&local_ce + lVar98 + uVar109))) + uVar103 * -2) <= &local_ce + lVar98 + uVar109)
            && (!CARRY8(uVar103,uVar103))) &&
           (uVar123 = (long)(uintptr_t)(uintptr_t)((&local_cc)) + (long)iVar154 * 2, uVar123 + uVar103 * -2 <= uVar123)) {
          lVar101 = (long)(int)(uVar141 + uVar10) + 1;
          lVar100 = lVar98 + uVar109;
          if (((ulong)((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar101 * 2) <= (ulong)((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar98 * 2)) ||
             ((ulong)((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar100 * 2) <= (long)(uintptr_t)(uintptr_t)((&local_cc)) + (lVar101 - uVar109) * 2))
          {
            psVar121 = local_414 + lVar100;
            psVar104 = &local_d0 + lVar100;
            uVar103 = uVar109 & 0xfffffffe;
            do {
              lVar101 = (long)iVar154;
              psVar7 = psVar121 + 1;
              iVar154 = iVar154 + -2;
              uVar103 = uVar103 - 2;
              sVar171 = *psVar121;
              psVar121 = psVar121 + -2;
              uVar143 = NEON_smin(CONCAT44((&local_ce)[lVar101] + 0x800,
                                           *(ssc_i16_u *)(uintptr_t)(((uintptr_t)&local_cc + lVar101 * 2)) + 0x800),
                                  CONCAT44((int)sVar171,(int)*psVar7),4);
              uVar143 = NEON_smin(uVar143,CONCAT44((int)*psVar104,(int)psVar104[1]),4);
              uVar143 = NEON_rev64(uVar143,4);
              *psVar104 = (short)uVar143;
              psVar104[1] = (short)((ulong)uVar143 >> 0x20);
              psVar104 = psVar104 + -2;
            } while (uVar103 != 0);
            bVar87 = (uVar109 & 0xfffffffe) == uVar109;
            uVar109 = uVar109 & 1;
            if (bVar87) goto LAB_0010df90;
          }
        }
      }
      do {
        iVar154 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + (long)(int)(uVar10 + (int)uVar109) * 2)) + 0x800;
        if (local_414[lVar98 + uVar109 + 1] <= iVar154) {
          iVar154 = (int)local_414[lVar98 + uVar109 + 1];
        }
        iVar93 = (int)(&local_ce)[lVar98 + uVar109];
        if (iVar154 <= (&local_ce)[lVar98 + uVar109]) {
          iVar93 = iVar154;
        }
        bVar87 = uVar109 != 0;
        uVar103 = uVar109 - 1;
        (&local_ce)[lVar98 + uVar109] = (short)iVar93;
        uVar109 = uVar103;
      } while (bVar87 && uVar103 != 0);
    }
LAB_0010df90:
    if (0 < (int)uVar178) {
      if (uVar178 < 0x10) {
        uVar103 = 0;
LAB_0010e128:
        lVar101 = uVar116 - uVar103;
        psVar121 = local_128 + uVar103;
        psVar104 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + (uVar103 + lVar98) * 2));
        do {
          sVar171 = *psVar104;
          if (*psVar104 <= *psVar121) {
            sVar171 = *psVar121;
          }
          lVar101 = lVar101 + -1;
          *psVar104 = sVar171;
          psVar121 = psVar121 + 1;
          psVar104 = psVar104 + 1;
        } while (lVar101 != 0);
      }
      else {
        uVar103 = uVar116 & 0xfffffff0;
        pauVar120 = (undefined1 (*) [16])(asStack_bc + lVar98);
        pauVar124 = (undefined1 (*) [16])auStack_118;
        uVar109 = uVar103;
        do {
          uVar109 = uVar109 - 0x10;
          pauVar2 = pauVar124 + -1;
          auVar145 = *(vec128_t *)*pauVar124;
          pauVar124 = pauVar124 + 2;
          auVar144 = NEON_smax(*(vec128_t *)pauVar120[-1],*(vec128_t *)*pauVar2,2);
          auVar145 = NEON_smax(*(vec128_t *)*pauVar120,auVar145,2);
          *(ssc_i64_u *)(pauVar120[-1] + 8) = auVar144._8_8_;
          *(ssc_i64_u *)pauVar120[-1] = auVar144._0_8_;
          *(ssc_i64_u *)(*pauVar120 + 8) = auVar145._8_8_;
          *(ssc_i64_u *)*pauVar120 = auVar145._0_8_;
          pauVar120 = pauVar120 + 2;
        } while (uVar109 != 0);
        if (uVar103 != uVar116) goto LAB_0010e128;
      }
      if (uVar178 < 8) {
LAB_0010e194:
        uVar109 = 0;
LAB_0010e198:
        lVar101 = uVar116 - uVar109;
        puVar119 = &local_cc;
        psVar121 = local_3b8;
        lVar125 = (uVar109 + lVar98) * 2;
        lVar100 = uVar109 * 2;
        do {
          sVar171 = psVar121[uVar109 + lVar98];
          iVar93 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar100)) + -0x1000;
          iVar154 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar125));
          if (*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar125)) <= iVar93) {
            iVar154 = iVar93;
          }
          *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar125)) = (short)iVar154;
          iVar93 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar100));
          if ((int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar100)) <= iVar154 + -0x1000) {
            iVar93 = iVar154 + -0x1000;
          }
          sVar13 = psVar121[uVar109];
          psVar121 = psVar121 + 1;
          lVar101 = lVar101 + -1;
          *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar100)) = (short)iVar93;
          uVar141 = (int)sVar171 - (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar125));
          *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + lVar100)) =
               (short)((sVar13 - iVar93 & (sVar13 - iVar93 >> 0x1f ^ 0xffffffffU)) +
                       (uVar141 & ((int)uVar141 >> 0x1f ^ 0xffffffffU)) >> 1);
          puVar119 = (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar119)) + 2));
        } while (lVar101 != 0);
      }
      else {
        if (((ulong)((long)(uintptr_t)(uintptr_t)((&local_cc)) + lVar98 * 2) < (long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar116 * 2) &&
           (&local_cc < (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + (lVar98 + uVar116) * 2))))
        goto LAB_0010e194;
        uVar109 = uVar116 & 0xfffffff8;
        psVar121 = local_3b8;
        auVar145 = ZEXT816(0);
        psVar104 = (ssc_i16_u *)&local_cc;
        uVar103 = uVar109;
        do {
          psVar7 = psVar104 + lVar98;
          uVar103 = uVar103 - 8;
          sVar171 = *psVar121;
          psVar73 = psVar121 + 1;
          psVar74 = psVar121 + 2;
          psVar75 = psVar121 + 3;
          psVar76 = psVar121 + 4;
          psVar77 = psVar121 + 5;
          psVar78 = psVar121 + 6;
          psVar79 = psVar121 + 7;
          auVar219._0_4_ = *psVar104 + -0x1000;
          auVar219._4_4_ = psVar104[1] + -0x1000;
          auVar219._8_4_ = psVar104[2] + -0x1000;
          auVar219._12_4_ = psVar104[3] + -0x1000;
          auVar233._0_4_ = (int)*psVar7;
          auVar233._4_4_ = (int)psVar7[1];
          auVar233._8_4_ = (int)psVar7[2];
          auVar233._12_4_ = (int)psVar7[3];
          auVar253._0_4_ = psVar104[4] + -0x1000;
          auVar253._4_4_ = psVar104[5] + -0x1000;
          auVar253._8_4_ = psVar104[6] + -0x1000;
          auVar253._12_4_ = psVar104[7] + -0x1000;
          auVar190._0_4_ = (int)psVar7[4];
          auVar190._4_4_ = (int)psVar7[5];
          auVar190._8_4_ = (int)psVar7[6];
          auVar190._12_4_ = (int)psVar7[7];
          auVar220 = NEON_smax(auVar219,auVar233,4);
          auVar234._0_4_ = (int)psVar104[4];
          auVar234._4_4_ = (int)psVar104[5];
          auVar234._8_4_ = (int)psVar104[6];
          auVar234._12_4_ = (int)psVar104[7];
          auVar144 = NEON_smax(auVar253,auVar190,4);
          psVar7 = psVar121 + lVar98;
          auVar207._0_4_ = (int)*psVar104;
          auVar207._4_4_ = (int)psVar104[1];
          auVar207._8_4_ = (int)psVar104[2];
          auVar207._12_4_ = (int)psVar104[3];
          psVar121 = psVar121 + 8;
          iVar154 = auVar220._4_4_ + -0x1000;
          iVar93 = auVar220._8_4_ + -0x1000;
          iVar142 = auVar220._12_4_ + -0x1000;
          auVar275._0_4_ = auVar144._0_4_ + -0x1000;
          auVar275._4_4_ = auVar144._4_4_ + -0x1000;
          auVar275._8_4_ = auVar144._8_4_ + -0x1000;
          auVar275._12_4_ = auVar144._12_4_ + -0x1000;
          auVar33._4_2_ = (short)iVar154;
          auVar33._0_4_ = auVar220._0_4_ + -0x1000;
          auVar33._6_2_ = (short)((uint)iVar154 >> 0x10);
          auVar33._8_2_ = (short)iVar93;
          auVar33._10_2_ = (short)((uint)iVar93 >> 0x10);
          auVar33._12_2_ = (short)iVar142;
          auVar33._14_2_ = (short)((uint)iVar142 >> 0x10);
          auVar277 = NEON_smax(auVar33,auVar207,4);
          auVar235 = NEON_smax(auVar275,auVar234,4);
          auVar208._0_4_ = (int)sVar171 - auVar277._0_4_;
          auVar208._4_4_ = (int)*psVar73 - auVar277._4_4_;
          auVar208._8_4_ = (int)*psVar74 - auVar277._8_4_;
          auVar208._12_4_ = (int)*psVar75 - auVar277._12_4_;
          auVar263._0_4_ = (int)*psVar7 - (int)auVar220._0_2_;
          auVar263._4_4_ = (int)psVar7[1] - (int)auVar220._4_2_;
          auVar263._8_4_ = (int)psVar7[2] - (int)auVar220._8_2_;
          auVar263._12_4_ = (int)psVar7[3] - (int)auVar220._12_2_;
          auVar236._0_4_ = (int)*psVar76 - auVar235._0_4_;
          auVar236._4_4_ = (int)*psVar77 - auVar235._4_4_;
          auVar236._8_4_ = (int)*psVar78 - auVar235._8_4_;
          auVar236._12_4_ = (int)*psVar79 - auVar235._12_4_;
          auVar254._0_4_ = (int)psVar7[4] - (int)auVar144._0_2_;
          auVar254._4_4_ = (int)psVar7[5] - (int)auVar144._4_2_;
          auVar254._8_4_ = (int)psVar7[6] - (int)auVar144._8_2_;
          auVar254._12_4_ = (int)psVar7[7] - (int)auVar144._12_2_;
          auVar277 = NEON_smax(auVar208,auVar145,4);
          auVar274 = NEON_smax(auVar263,auVar145,4);
          auVar235 = NEON_smax(auVar236,auVar145,4);
          auVar264 = NEON_smax(auVar254,auVar145,4);
          auVar191._0_8_ =
               CONCAT26(auVar220._12_2_,
                        CONCAT24(auVar220._8_2_,CONCAT22(auVar220._4_2_,auVar220._0_2_)));
          auVar191._8_2_ = auVar144._0_2_;
          auVar191._10_2_ = auVar144._4_2_;
          auVar191._12_2_ = auVar144._8_2_;
          auVar191._14_2_ = auVar144._12_2_;
          *(ssc_i64_u *)(psVar104 + lVar98 + 4) = auVar191._8_8_;
          *(ssc_u64_u *)(psVar104 + lVar98) = auVar191._0_8_;
          *(ssc_u64_u *)(psVar104 + 4) =
               CONCAT26((short)((uint)(auVar235._12_4_ + auVar264._12_4_) >> 1),
                        CONCAT24((short)((uint)(auVar235._8_4_ + auVar264._8_4_) >> 1),
                                 CONCAT22((short)((uint)(auVar235._4_4_ + auVar264._4_4_) >> 1),
                                          (short)((uint)(auVar235._0_4_ + auVar264._0_4_) >> 1))));
          *(ssc_u64_u *)psVar104 =
               CONCAT26((short)((uint)(auVar277._12_4_ + auVar274._12_4_) >> 1),
                        CONCAT24((short)((uint)(auVar277._8_4_ + auVar274._8_4_) >> 1),
                                 CONCAT22((short)((uint)(auVar277._4_4_ + auVar274._4_4_) >> 1),
                                          (short)((uint)(auVar277._0_4_ + auVar274._0_4_) >> 1))));
          psVar104 = psVar104 + 8;
        } while (uVar103 != 0);
        if (uVar109 != uVar116) goto LAB_0010e198;
      }
      if (bVar84) {
        if (uVar178 < 0x10) {
          uVar103 = 0;
        }
        else {
          uVar103 = uVar116 & 0xfffffff0;
          psVar121 = asStack_bc;
          uVar109 = uVar103;
          do {
            uVar109 = uVar109 - 0x10;
            auVar170._0_8_ =
                 CONCAT26(psVar121[3] >> 1,
                          CONCAT24(psVar121[2] >> 1,CONCAT22(psVar121[1] >> 1,*psVar121 >> 1)));
            auVar170._8_2_ = psVar121[4] >> 1;
            auVar170._10_2_ = psVar121[5] >> 1;
            auVar170._12_2_ = psVar121[6] >> 1;
            auVar170._14_2_ = psVar121[7] >> 1;
            psVar121[-4] = psVar121[-4] >> 1;
            psVar121[-3] = psVar121[-3] >> 1;
            psVar121[-2] = psVar121[-2] >> 1;
            psVar121[-1] = psVar121[-1] >> 1;
            psVar121[-8] = psVar121[-8] >> 1;
            psVar121[-7] = psVar121[-7] >> 1;
            psVar121[-6] = psVar121[-6] >> 1;
            psVar121[-5] = psVar121[-5] >> 1;
            *(ssc_i64_u *)(psVar121 + 4) = auVar170._8_8_;
            *(ssc_u64_u *)psVar121 = auVar170._0_8_;
            psVar121 = psVar121 + 0x10;
          } while (uVar109 != 0);
          if (uVar103 == uVar116) goto LAB_0010e350;
        }
        lVar101 = uVar116 - uVar103;
        psVar121 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar103 * 2));
        do {
          lVar101 = lVar101 + -1;
          *psVar121 = (short)((ulong)(long)*psVar121 >> 1);
          psVar121 = psVar121 + 1;
        } while (lVar101 != 0);
      }
LAB_0010e350:
      uVar109 = 0;
      iVar154 = 0;
      do {
        if (uVar109 < 8) {
          iVar93 = (uint)*(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar109 * 2)) << 1;
        }
        else {
          iVar93 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar109 * 2)) >> (0xb < uVar109);
        }
        if (0xfff < (short)iVar93) {
          iVar93 = 0x1000;
        }
        psVar121 = (ssc_i16_u *)(uintptr_t)((lVar108 + uVar109 * 2));
        *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_cc)) + uVar109 * 2)) = (short)iVar93;
        iVar142 = (int)psVar121[1] - (int)*psVar121;
        uVar131 = (iVar93 << 0x10) >> 0x17;
        uVar178 = (iVar142 * 0x10 * (int)(short)iVar93) / 6 >> 10;
        uVar141 = uVar178;
        if (3 < iVar142) {
          uVar141 = uVar131;
        }
        iVar93 = uVar178 * 0x30;
        if (3 < iVar142) {
          iVar93 = iVar142 * 0x10 * uVar131;
        }
        if ((int)(uVar9 >> 2) < iVar93 + iVar154 >> 6) {
          local_1f0[uVar109 & 0xffffffff] = uVar9 * 0x10 - iVar154;
          goto LAB_0010e574;
        }
        uVar103 = uVar109 + 1;
        local_1f0[uVar109] = uVar141;
        uVar109 = uVar103;
        iVar154 = iVar93 + iVar154;
      } while (uVar116 != uVar103);
    }
  }
  iVar154 = (int)sVar88;
  sVar88 = *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar98 * 2 + 2));
  uVar141 = iVar155 - ((ssc_i16_u *)&local_410)[1];
  uVar178 = iVar155 - 0x1964U;
  if ((int)(iVar154 - 0x1964U) <= (int)(iVar155 - 0x1964U)) {
    uVar178 = iVar154 - 0x1964U;
  }
  uVar131 = iVar154 - sVar88;
  if ((int)uVar131 <= (int)uVar141) {
    uVar141 = uVar131;
  }
  if ((0 < (int)uVar178) && (0 < (int)uVar141)) {
    if (uVar141 < 0x5dd) {
      uVar141 = 0x5dc;
    }
    uVar178 = (uVar141 + 0xfa24 >> 7 & 0x1ff) + (uVar178 >> 3 & 0x1fff) / 0x19;
    if (9 < uVar178) {
      uVar178 = 10;
    }
    if ((int)local_1f0[0] < (int)uVar178) {
      local_1f0[0] = uVar178;
    }
  }
  iVar155 = ((ssc_i16_u *)&local_410)[1] - iVar155;
  uVar178 = (int)((ssc_i16_u *)&local_410)[1] - 0x17d4;
  uVar141 = (int)sVar88 - 0x17d4;
  iVar93 = (int)((ssc_i16_u *)&local_410)[1] - (int)((ssc_i16_u *)&local_410)[2];
  iVar142 = (int)sVar88 - (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((&local_410)) + lVar98 * 2 + 4));
  iVar154 = sVar88 - iVar154;
  if ((int)uVar141 <= (int)uVar178) {
    uVar178 = uVar141;
  }
  if (iVar142 <= iVar93) {
    iVar93 = iVar142;
  }
  if (iVar154 <= iVar155) {
    iVar155 = iVar154;
  }
  if (((0 < (int)uVar178) && (0 < iVar93)) && (0 < iVar155)) {
    iVar155 = (iVar93 + -0x6a4) / 0xa0 + (uVar178 >> 3 & 0x1fff) / 0x19;
    if (9 < iVar155) {
      iVar155 = 10;
    }
    if ((int)local_1f0[1] < iVar155) {
      local_1f0[1] = iVar155;
    }
  }
LAB_0010e574:
  for (int i = 0; i < 22; i++) {;
  }

  local_1f8 = *(ssc_i64_u *)(piVar136 + 0x1e);
  iVar154 = uVar9 * 0x40;
  iVar93 = ssc_ec_tell_frac((int64_t)(uintptr_t)(auStack_538));
  iVar155 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
  if ((int)uVar128 < iVar155) {
    iVar142 = 0;
    iVar91 = 6;
    lVar101 = 0;
    do {
      lVar100 = lVar101 + 1;
      iVar89 = iVar154 - iVar142;
      uVar178 = ((uint)*(ssc_u16_u *)(uintptr_t)((lVar108 + lVar100 * 2)) - (uint)*(ssc_u16_u *)(uintptr_t)((lVar108 + lVar101 * 2))
                ) * 0x10;
      if ((short)uVar178 < 0x31) {
        uVar178 = 0x30;
      }
      if (iVar93 + iVar91 * 8 < iVar89) {
        if (*(ssc_i32_u *)(uintptr_t)((local_1f8 + lVar101 * 4)) < 1) {
          iVar159 = 0;
          uVar141 = 0;
        }
        else {
          uVar141 = 0;
          iVar159 = 0;
          uVar178 = uVar178 & 0xfff0;
          iVar155 = iVar91;
          do {
            uVar131 = local_1f0[lVar101];
            ssc_ec_enc_bit_logp((int64_t)(uintptr_t)(auStack_538),iVar159 < (int)uVar131,iVar155);
            iVar93 = ssc_ec_tell_frac((int64_t)(uintptr_t)(auStack_538));
            if ((int)uVar131 <= iVar159) goto LAB_0010e6a8;
            iVar89 = iVar89 - uVar178;
            if (iVar89 <= iVar93 + 8) {
              if (iVar91 < 4) {
                iVar91 = 3;
              }
              iVar91 = iVar91 + -1;
              iVar155 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
              iVar142 = iVar142 + uVar178 + uVar141;
              uVar141 = uVar178 + uVar141;
              goto LAB_0010e5c4;
            }
            uVar141 = uVar141 + uVar178;
            iVar159 = iVar159 + 1;
            iVar155 = 1;
          } while ((int)uVar141 < *(ssc_i32_u *)(uintptr_t)((local_1f8 + lVar101 * 4)));
          iVar159 = 1;
LAB_0010e6a8:
          iVar142 = iVar142 + uVar141;
        }
        iVar89 = iVar91;
        if (iVar91 < 4) {
          iVar89 = 3;
        }
        iVar155 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
        if (iVar159 != 0) {
          iVar91 = iVar89 + -1;
        }
      }
      else {
        uVar141 = 0;
      }
LAB_0010e5c4:
      local_1f0[lVar101] = uVar141;
      lVar101 = lVar100;
    } while (lVar100 < (int)(iVar155 - uVar128));
  }
  else {
    iVar142 = 0;
  }
  puVar4 = PTR__pre_shared_0011bce0;
  if ((local_1a8 < 0x3e9) || (local_1a4 != 0)) {
    if ((local_1a4 < 0x3e9) || (local_1a0 != 0)) {
      if (((1000 < local_1a0) && (local_19c == 0)) &&
         ((7000 < *(ssc_i16_u *)(uintptr_t)((lVar129 + 0x2a)) ||
          (*(ssc_i16_u *)(uintptr_t)((lVar129 + 0x28)) >> 1 < *(ssc_i16_u *)(uintptr_t)((lVar129 + 0x2a)))))) {
        local_19c = local_1a0;
      }
    }
    else if ((7000 < *(ssc_i16_u *)(uintptr_t)((lVar129 + 0x28))) ||
            (*(ssc_i16_u *)(uintptr_t)((lVar129 + 0x26)) >> 1 < *(ssc_i16_u *)(uintptr_t)((lVar129 + 0x28)))) {
      local_1a0 = local_1a4;
    }
  }
  else if ((7000 < *(ssc_i16_u *)(uintptr_t)((lVar129 + 0x26))) ||
          (*(ssc_i16_u *)(uintptr_t)((lVar129 + 0x24)) >> 1 < *(ssc_i16_u *)(uintptr_t)((lVar129 + 0x26)))) {
    local_1a4 = local_1a8;
  }
  psVar104 = *(ssc_i16_u **)(piVar136 + 4);
  lVar101 = 0;
  lVar108 = lVar94 * 2;
  uVar178 = 1;
  uVar141 = 1;
  psVar121 = (ssc_i16_u *)(PTR__pre_shared_0011bce0 + 0x1e60);
  sVar88 = *psVar104;
  do {
    lVar101 = lVar101 + 1;
    iVar159 = 0;
    iVar173 = 0;
    iVar175 = 0;
    iVar138 = 0;
    iVar155 = 0;
    iVar91 = 0;
    iVar89 = 0;
    iVar153 = 0;
    iVar156 = 0;
    iVar157 = 0;
    lVar100 = (ulong)((psVar104[lVar101] * 8 + sVar88 * -8) - 8) + 8;
    auVar209 = ZEXT816(0);
    psVar7 = psVar121 + lVar100;
    do {
      sVar88 = *psVar121;
      sVar171 = psVar121[1];
      sVar13 = psVar121[2];
      sVar36 = psVar121[3];
      sVar37 = psVar121[4];
      sVar38 = psVar121[5];
      sVar39 = psVar121[6];
      sVar40 = psVar121[7];
      lVar100 = lVar100 + -8;
      psVar73 = psVar121 + lVar94;
      sVar41 = *psVar73;
      sVar42 = psVar73[1];
      sVar43 = psVar73[2];
      sVar44 = psVar73[3];
      sVar65 = psVar73[4];
      sVar66 = psVar73[5];
      sVar67 = psVar73[6];
      sVar68 = psVar73[7];
      psVar121 = psVar121 + 8;
      iVar230 = MP_INT_ABS((int)sVar88);
      iVar239 = MP_INT_ABS((int)sVar171);
      iVar243 = MP_INT_ABS((int)sVar13);
      iVar247 = MP_INT_ABS((int)sVar36);
      iVar250 = MP_INT_ABS((int)sVar37);
      iVar255 = MP_INT_ABS((int)sVar38);
      iVar257 = MP_INT_ABS((int)sVar39);
      iVar259 = MP_INT_ABS((int)sVar40);
      iVar158 = MP_INT_ABS((int)sVar41);
      iVar172 = MP_INT_ABS((int)sVar42);
      iVar174 = MP_INT_ABS((int)sVar43);
      iVar176 = MP_INT_ABS((int)sVar44);
      iVar262 = MP_INT_ABS((int)sVar65);
      iVar267 = MP_INT_ABS((int)sVar66);
      iVar269 = MP_INT_ABS((int)sVar67);
      iVar270 = MP_INT_ABS((int)sVar68);
      iVar177 = auVar209._4_4_;
      iVar227 = auVar209._8_4_;
      iVar252 = auVar209._12_4_;
      iVar231 = MP_INT_ABS((int)sVar41 + (int)sVar88);
      iVar240 = MP_INT_ABS((int)sVar42 + (int)sVar171);
      iVar244 = MP_INT_ABS((int)sVar43 + (int)sVar13);
      iVar248 = MP_INT_ABS((int)sVar44 + (int)sVar36);
      iVar251 = MP_INT_ABS((int)sVar65 + (int)sVar37);
      iVar256 = MP_INT_ABS((int)sVar66 + (int)sVar38);
      iVar258 = MP_INT_ABS((int)sVar67 + (int)sVar39);
      iVar260 = MP_INT_ABS((int)sVar68 + (int)sVar40);
      auVar209._0_4_ = iVar250 + auVar209._0_4_ + iVar262;
      auVar209._4_4_ = iVar255 + iVar177 + iVar267;
      auVar209._8_4_ = iVar257 + iVar227 + iVar269;
      auVar209._12_4_ = iVar259 + iVar252 + iVar270;
      uVar178 = iVar230 + uVar178 + iVar158;
      iVar153 = iVar239 + iVar153 + iVar172;
      iVar156 = iVar243 + iVar156 + iVar174;
      iVar157 = iVar247 + iVar157 + iVar176;
      iVar159 = iVar159 + (uint)(ushort)((sVar37 - sVar65) +
                                        (sVar65 - sVar37) * 2 * (ushort)(sVar37 < sVar65)) + iVar251
      ;
      iVar173 = iVar173 + (uint)(ushort)((sVar38 - sVar66) +
                                        (sVar66 - sVar38) * 2 * (ushort)(sVar38 < sVar66)) + iVar256
      ;
      iVar175 = iVar175 + (uint)(ushort)((sVar39 - sVar67) +
                                        (sVar67 - sVar39) * 2 * (ushort)(sVar39 < sVar67)) + iVar258
      ;
      iVar138 = iVar138 + (uint)(ushort)((sVar40 - sVar68) +
                                        (sVar68 - sVar40) * 2 * (ushort)(sVar40 < sVar68)) + iVar260
      ;
      uVar141 = uVar141 + (ushort)((sVar88 - sVar41) +
                                  (sVar41 - sVar88) * 2 * (ushort)(sVar88 < sVar41)) + iVar231;
      iVar155 = iVar155 + (uint)(ushort)((sVar171 - sVar42) +
                                        (sVar42 - sVar171) * 2 * (ushort)(sVar171 < sVar42)) +
                iVar240;
      iVar91 = iVar91 + (uint)(ushort)((sVar13 - sVar43) +
                                      (sVar43 - sVar13) * 2 * (ushort)(sVar13 < sVar43)) + iVar244;
      iVar89 = iVar89 + (uint)(ushort)((sVar36 - sVar44) +
                                      (sVar44 - sVar36) * 2 * (ushort)(sVar36 < sVar44)) + iVar248;
    } while (lVar100 != 0);
    uVar178 = uVar178 + auVar209._0_4_ + iVar153 + auVar209._4_4_ +
              iVar156 + auVar209._8_4_ + iVar157 + auVar209._12_4_;
    uVar141 = uVar141 + iVar159 + iVar155 + iVar173 + iVar91 + iVar175 + iVar89 + iVar138;
    psVar121 = psVar7;
    sVar88 = psVar104[lVar101];
  } while (lVar101 != 0xd);
  uVar141 = ((int)uVar141 >> 0x10) * 0xb504 + ((uVar141 & 0xffff) * 0x5a82 >> 0xf);
  uVar131 = (int)((uint)(ushort)psVar104[0xd] << 0x14) >> 0x10 | 0xd;
  iVar155 = (int)(short)(psVar104[0xd] << 4);
  local_13c = (uint)((int)(((int)uVar178 >> 0xf & 0xfffffffeU) * iVar155 +
                          ((int)((uVar178 & 0xffff) * iVar155) >> 0xf)) <
                    (int)(uVar131 * ((int)uVar141 >> 0xf & 0xfffffffeU) +
                         ((int)(uVar131 * (uVar141 & 0xffff)) >> 0xf)));
  uVar178 = ssc_hysteresis_decision
                      (0x1fe,(int64_t)(uintptr_t)(&DAT_00103d18),(int64_t)(uintptr_t)(&DAT_00103d46),0x16 - uVar128,(int)param_1[10]);
  uVar178 = uVar178 & ((int)uVar178 >> 0x1f ^ 0xffffffffU);
  uVar131 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - uVar128;
  uVar141 = uVar131;
  if ((int)uVar178 <= (int)uVar131) {
    uVar141 = uVar178;
  }
  *(ssc_u32_u *)(param_1 + 10) = uVar141;
  if (iVar154 - iVar142 < iVar93 + 0x30) {
    local_140 = 5;
  }
  else {
    psVar121 = *(ssc_i16_u **)(piVar136 + 4);
    iVar93 = (int)psVar121[1];
    iVar155 = (iVar93 - *psVar121) * 8;
    uVar178 = (iVar93 * 8 + *psVar121 * -8) - 8;
    if (uVar178 == 0) {
      pauVar120 = (undefined1 (*) [16])(puVar4 + 0x1e60);
      iVar142 = 0;
LAB_0010ea80:
      do {
        puVar85 = *pauVar120;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar120;
        pauVar120 = (undefined1 (*) [16])(*pauVar120 + 2);
        iVar142 = iVar142 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar142 = 0;
      iVar91 = 0;
      iVar89 = 0;
      iVar159 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar173 = 0;
      iVar175 = 0;
      iVar138 = 0;
      iVar153 = 0;
      pauVar120 = (undefined1 (*) [16])(puVar4 + uVar103 * 2 + 0x1e60);
      pauVar124 = (undefined1 (*) [16])(puVar4 + 0x1e70);
      uVar109 = uVar103;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pVar6 = (unkbyte10 *)(*pauVar124 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)pauVar124[-1];
        auVar220 = *(vec128_t *)*pauVar124;
        pauVar124 = pauVar124 + 2;
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)((char *)pVar6 - 16);
        uVar143 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((pVar6)) + 8));
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)pVar6;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar142 = iVar142 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar91 = iVar91 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar89 = iVar89 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar159 = iVar159 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar17._10_2_ = uVar271;
        auVar17._0_10_ = *pVar6;
        auVar17._12_2_ = uVar272;
        auVar17._14_2_ = uVar273;
        auVar18._10_2_ = uVar271;
        auVar18._0_10_ = *pVar6;
        auVar18._12_2_ = uVar272;
        auVar18._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar17,auVar18,8,1);
        auVar192._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar192._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar192._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar192._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar173 = iVar173 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar175 = iVar175 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar138 = iVar138 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar153 = iVar153 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar210._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar210._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar210._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar210._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        auVar145 = auVar192;
        auVar144 = auVar210;
      } while (uVar109 != 0);
      iVar142 = auVar192._0_4_ + iVar142 + auVar210._0_4_ + iVar173 +
                auVar192._4_4_ + iVar91 + auVar210._4_4_ + iVar175 +
                auVar192._8_4_ + iVar89 + auVar210._8_4_ + iVar138 +
                auVar192._12_4_ + iVar159 + auVar210._12_4_ + iVar153;
      if (uVar116 != uVar103) goto LAB_0010ea80;
    }
    iVar91 = (int)psVar121[2];
    iVar155 = (iVar91 - psVar121[1]) * 8;
    uVar178 = (iVar91 * 8 + iVar93 * -8) - 8;
    if (uVar178 == 0) {
      iVar93 = 0;
LAB_0010eb30:
      do {
        puVar85 = *pauVar120;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar120;
        pauVar120 = (undefined1 (*) [16])(*pauVar120 + 2);
        iVar93 = iVar93 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
        pauVar124 = pauVar120;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar93 = 0;
      iVar89 = 0;
      iVar159 = 0;
      iVar173 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar175 = 0;
      iVar138 = 0;
      iVar153 = 0;
      iVar156 = 0;
      pauVar124 = (undefined1 (*) [16])(*pauVar120 + uVar103 * 2);
      uVar109 = uVar103;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pauVar2 = (undefined1 (*) [16])(*pauVar120 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)*pauVar120;
        auVar220 = *(vec128_t *)pauVar120[1];
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)*pauVar2;
        pauVar15 = pauVar2 + 1;
        uVar143 = *(ssc_u64_u *)(pauVar2[1] + 8);
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)*pauVar15;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar93 = iVar93 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar89 = iVar89 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar159 = iVar159 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar173 = iVar173 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar19._10_2_ = uVar271;
        auVar19._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar19._12_2_ = uVar272;
        auVar19._14_2_ = uVar273;
        auVar20._10_2_ = uVar271;
        auVar20._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar20._12_2_ = uVar272;
        auVar20._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar19,auVar20,8,1);
        auVar193._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar193._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar193._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar193._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar175 = iVar175 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar138 = iVar138 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar153 = iVar153 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar156 = iVar156 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar211._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar211._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar211._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar211._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        pauVar120 = pauVar120 + 2;
        auVar145 = auVar193;
        auVar144 = auVar211;
      } while (uVar109 != 0);
      iVar93 = auVar193._0_4_ + iVar93 + auVar211._0_4_ + iVar175 +
               auVar193._4_4_ + iVar89 + auVar211._4_4_ + iVar138 +
               auVar193._8_4_ + iVar159 + auVar211._8_4_ + iVar153 +
               auVar193._12_4_ + iVar173 + auVar211._12_4_ + iVar156;
      pauVar120 = pauVar124;
      if (uVar116 != uVar103) goto LAB_0010eb30;
    }
    iVar89 = (int)psVar121[3];
    iVar155 = (iVar89 - psVar121[2]) * 8;
    uVar178 = (iVar89 * 8 + iVar91 * -8) - 8;
    if (uVar178 == 0) {
      iVar91 = 0;
LAB_0010ebe0:
      do {
        puVar85 = *pauVar124;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar124;
        pauVar124 = (undefined1 (*) [16])(*pauVar124 + 2);
        iVar91 = iVar91 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
        pauVar120 = pauVar124;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar91 = 0;
      iVar159 = 0;
      iVar173 = 0;
      iVar175 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar138 = 0;
      iVar153 = 0;
      iVar156 = 0;
      iVar157 = 0;
      pauVar120 = (undefined1 (*) [16])(*pauVar124 + uVar103 * 2);
      uVar109 = uVar103;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pauVar2 = (undefined1 (*) [16])(*pauVar124 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)*pauVar124;
        auVar220 = *(vec128_t *)pauVar124[1];
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)*pauVar2;
        pauVar15 = pauVar2 + 1;
        uVar143 = *(ssc_u64_u *)(pauVar2[1] + 8);
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)*pauVar15;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar91 = iVar91 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar159 = iVar159 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar173 = iVar173 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar175 = iVar175 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar21._10_2_ = uVar271;
        auVar21._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar21._12_2_ = uVar272;
        auVar21._14_2_ = uVar273;
        auVar22._10_2_ = uVar271;
        auVar22._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar22._12_2_ = uVar272;
        auVar22._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar21,auVar22,8,1);
        auVar194._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar194._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar194._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar194._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar138 = iVar138 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar153 = iVar153 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar156 = iVar156 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar157 = iVar157 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar212._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar212._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar212._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar212._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        pauVar124 = pauVar124 + 2;
        auVar145 = auVar194;
        auVar144 = auVar212;
      } while (uVar109 != 0);
      iVar91 = auVar194._0_4_ + iVar91 + auVar212._0_4_ + iVar138 +
               auVar194._4_4_ + iVar159 + auVar212._4_4_ + iVar153 +
               auVar194._8_4_ + iVar173 + auVar212._8_4_ + iVar156 +
               auVar194._12_4_ + iVar175 + auVar212._12_4_ + iVar157;
      pauVar124 = pauVar120;
      if (uVar116 != uVar103) goto LAB_0010ebe0;
    }
    iVar159 = (int)psVar121[4];
    iVar155 = (iVar159 - psVar121[3]) * 8;
    uVar178 = (iVar159 * 8 + iVar89 * -8) - 8;
    if (uVar178 == 0) {
      iVar89 = 0;
LAB_0010ec90:
      do {
        puVar85 = *pauVar120;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar120;
        pauVar120 = (undefined1 (*) [16])(*pauVar120 + 2);
        iVar89 = iVar89 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
        pauVar124 = pauVar120;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar89 = 0;
      iVar173 = 0;
      iVar175 = 0;
      iVar138 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar153 = 0;
      iVar156 = 0;
      iVar157 = 0;
      iVar158 = 0;
      pauVar124 = (undefined1 (*) [16])(*pauVar120 + uVar103 * 2);
      uVar109 = uVar103;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pauVar2 = (undefined1 (*) [16])(*pauVar120 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)*pauVar120;
        auVar220 = *(vec128_t *)pauVar120[1];
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)*pauVar2;
        pauVar15 = pauVar2 + 1;
        uVar143 = *(ssc_u64_u *)(pauVar2[1] + 8);
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)*pauVar15;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar89 = iVar89 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar173 = iVar173 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar175 = iVar175 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar138 = iVar138 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar23._10_2_ = uVar271;
        auVar23._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar23._12_2_ = uVar272;
        auVar23._14_2_ = uVar273;
        auVar24._10_2_ = uVar271;
        auVar24._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar24._12_2_ = uVar272;
        auVar24._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar23,auVar24,8,1);
        auVar195._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar195._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar195._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar195._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar153 = iVar153 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar156 = iVar156 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar157 = iVar157 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar158 = iVar158 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar213._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar213._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar213._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar213._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        pauVar120 = pauVar120 + 2;
        auVar145 = auVar195;
        auVar144 = auVar213;
      } while (uVar109 != 0);
      iVar89 = auVar195._0_4_ + iVar89 + auVar213._0_4_ + iVar153 +
               auVar195._4_4_ + iVar173 + auVar213._4_4_ + iVar156 +
               auVar195._8_4_ + iVar175 + auVar213._8_4_ + iVar157 +
               auVar195._12_4_ + iVar138 + auVar213._12_4_ + iVar158;
      pauVar120 = pauVar124;
      if (uVar116 != uVar103) goto LAB_0010ec90;
    }
    iVar173 = (int)psVar121[5];
    iVar155 = (iVar173 - psVar121[4]) * 8;
    uVar178 = (iVar173 * 8 + iVar159 * -8) - 8;
    if (uVar178 == 0) {
      iVar159 = 0;
LAB_0010ed40:
      do {
        puVar85 = *pauVar124;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar124;
        pauVar124 = (undefined1 (*) [16])(*pauVar124 + 2);
        iVar159 = iVar159 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
        pauVar120 = pauVar124;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar159 = 0;
      iVar175 = 0;
      iVar138 = 0;
      iVar153 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar156 = 0;
      iVar157 = 0;
      iVar158 = 0;
      iVar172 = 0;
      pauVar120 = (undefined1 (*) [16])(*pauVar124 + uVar103 * 2);
      uVar109 = uVar103;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pauVar2 = (undefined1 (*) [16])(*pauVar124 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)*pauVar124;
        auVar220 = *(vec128_t *)pauVar124[1];
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)*pauVar2;
        pauVar15 = pauVar2 + 1;
        uVar143 = *(ssc_u64_u *)(pauVar2[1] + 8);
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)*pauVar15;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar159 = iVar159 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar175 = iVar175 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar138 = iVar138 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar153 = iVar153 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar25._10_2_ = uVar271;
        auVar25._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar25._12_2_ = uVar272;
        auVar25._14_2_ = uVar273;
        auVar26._10_2_ = uVar271;
        auVar26._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar26._12_2_ = uVar272;
        auVar26._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar25,auVar26,8,1);
        auVar196._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar196._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar196._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar196._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar156 = iVar156 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar157 = iVar157 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar158 = iVar158 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar172 = iVar172 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar214._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar214._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar214._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar214._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        pauVar124 = pauVar124 + 2;
        auVar145 = auVar196;
        auVar144 = auVar214;
      } while (uVar109 != 0);
      iVar159 = auVar196._0_4_ + iVar159 + auVar214._0_4_ + iVar156 +
                auVar196._4_4_ + iVar175 + auVar214._4_4_ + iVar157 +
                auVar196._8_4_ + iVar138 + auVar214._8_4_ + iVar158 +
                auVar196._12_4_ + iVar153 + auVar214._12_4_ + iVar172;
      pauVar124 = pauVar120;
      if (uVar116 != uVar103) goto LAB_0010ed40;
    }
    iVar175 = (int)psVar121[6];
    iVar155 = (iVar175 - psVar121[5]) * 8;
    uVar178 = (iVar175 * 8 + iVar173 * -8) - 8;
    if (uVar178 == 0) {
      iVar173 = 0;
LAB_0010edf8:
      do {
        puVar85 = *pauVar120;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar120;
        pauVar120 = (undefined1 (*) [16])(*pauVar120 + 2);
        iVar173 = iVar173 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
        pauVar124 = pauVar120;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar173 = 0;
      iVar138 = 0;
      iVar153 = 0;
      iVar156 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar157 = 0;
      iVar158 = 0;
      iVar172 = 0;
      iVar174 = 0;
      pauVar124 = (undefined1 (*) [16])(*pauVar120 + uVar103 * 2);
      uVar109 = uVar103;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pauVar2 = (undefined1 (*) [16])(*pauVar120 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)*pauVar120;
        auVar220 = *(vec128_t *)pauVar120[1];
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)*pauVar2;
        pauVar15 = pauVar2 + 1;
        uVar143 = *(ssc_u64_u *)(pauVar2[1] + 8);
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)*pauVar15;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar173 = iVar173 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar138 = iVar138 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar153 = iVar153 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar156 = iVar156 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar27._10_2_ = uVar271;
        auVar27._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar27._12_2_ = uVar272;
        auVar27._14_2_ = uVar273;
        auVar28._10_2_ = uVar271;
        auVar28._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar28._12_2_ = uVar272;
        auVar28._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar27,auVar28,8,1);
        auVar197._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar197._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar197._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar197._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar157 = iVar157 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar158 = iVar158 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar172 = iVar172 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar174 = iVar174 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar215._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar215._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar215._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar215._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        pauVar120 = pauVar120 + 2;
        auVar145 = auVar197;
        auVar144 = auVar215;
      } while (uVar109 != 0);
      iVar173 = auVar197._0_4_ + iVar173 + auVar215._0_4_ + iVar157 +
                auVar197._4_4_ + iVar138 + auVar215._4_4_ + iVar158 +
                auVar197._8_4_ + iVar153 + auVar215._8_4_ + iVar172 +
                auVar197._12_4_ + iVar156 + auVar215._12_4_ + iVar174;
      pauVar120 = pauVar124;
      if (uVar116 != uVar103) goto LAB_0010edf8;
    }
    iVar138 = (int)psVar121[7];
    iVar155 = (iVar138 - psVar121[6]) * 8;
    uVar178 = (iVar138 * 8 + iVar175 * -8) - 8;
    if (uVar178 == 0) {
      iVar175 = 0;
LAB_0010eeb0:
      do {
        puVar85 = *pauVar124;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar124;
        pauVar124 = (undefined1 (*) [16])(*pauVar124 + 2);
        iVar175 = iVar175 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
        pauVar120 = pauVar124;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar175 = 0;
      iVar153 = 0;
      iVar156 = 0;
      iVar157 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar158 = 0;
      iVar172 = 0;
      iVar174 = 0;
      iVar176 = 0;
      pauVar120 = (undefined1 (*) [16])(*pauVar124 + uVar103 * 2);
      uVar109 = uVar103;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pauVar2 = (undefined1 (*) [16])(*pauVar124 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)*pauVar124;
        auVar220 = *(vec128_t *)pauVar124[1];
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)*pauVar2;
        pauVar15 = pauVar2 + 1;
        uVar143 = *(ssc_u64_u *)(pauVar2[1] + 8);
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)*pauVar15;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar175 = iVar175 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar153 = iVar153 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar156 = iVar156 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar157 = iVar157 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar29._10_2_ = uVar271;
        auVar29._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar29._12_2_ = uVar272;
        auVar29._14_2_ = uVar273;
        auVar30._10_2_ = uVar271;
        auVar30._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar30._12_2_ = uVar272;
        auVar30._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar29,auVar30,8,1);
        auVar198._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar198._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar198._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar198._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar158 = iVar158 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar172 = iVar172 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar174 = iVar174 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar176 = iVar176 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar216._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar216._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar216._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar216._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        pauVar124 = pauVar124 + 2;
        auVar145 = auVar198;
        auVar144 = auVar216;
      } while (uVar109 != 0);
      iVar175 = auVar198._0_4_ + iVar175 + auVar216._0_4_ + iVar158 +
                auVar198._4_4_ + iVar153 + auVar216._4_4_ + iVar172 +
                auVar198._8_4_ + iVar156 + auVar216._8_4_ + iVar174 +
                auVar198._12_4_ + iVar157 + auVar216._12_4_ + iVar176;
      pauVar124 = pauVar120;
      if (uVar116 != uVar103) goto LAB_0010eeb0;
    }
    iVar155 = ((int)psVar121[8] - (int)psVar121[7]) * 8;
    uVar178 = (psVar121[8] * 8 + iVar138 * -8) - 8;
    if (uVar178 == 0) {
      iVar138 = 0;
LAB_0010ef68:
      do {
        puVar85 = *pauVar120;
        iVar155 = iVar155 + -1;
        puVar86 = *pauVar120;
        pauVar120 = (undefined1 (*) [16])(*pauVar120 + 2);
        iVar138 = iVar138 + (int)*(ssc_i16_u *)(puVar85 + lVar94 * 2) * (int)*(ssc_i16_u *)puVar86;
      } while (iVar155 != 0);
    }
    else {
      uVar116 = (ulong)uVar178 + 8;
      uVar103 = uVar116 & 0x1fffffff0;
      iVar138 = 0;
      iVar153 = 0;
      iVar156 = 0;
      iVar157 = 0;
      iVar155 = iVar155 - (int)uVar103;
      iVar158 = 0;
      iVar172 = 0;
      iVar174 = 0;
      iVar176 = 0;
      uVar109 = uVar103;
      pauVar124 = pauVar120;
      auVar145 = ZEXT816(0);
      auVar144 = ZEXT816(0);
      do {
        pauVar2 = (undefined1 (*) [16])(*pauVar124 + lVar108);
        uVar109 = uVar109 - 0x10;
        auVar277 = *(vec128_t *)*pauVar124;
        auVar220 = *(vec128_t *)pauVar124[1];
        auVar264 = NEON_ext(auVar277,auVar277,8,1);
        auVar235 = *(vec128_t *)*pauVar2;
        pauVar15 = pauVar2 + 1;
        uVar143 = *(ssc_u64_u *)(pauVar2[1] + 8);
        uVar271 = (undefined2)((ulong)uVar143 >> 0x10);
        uVar272 = (undefined2)((ulong)uVar143 >> 0x20);
        uVar273 = (undefined2)((ulong)uVar143 >> 0x30);
        uVar143 = *(ssc_u64_u *)*pauVar15;
        auVar274 = NEON_ext(auVar220,auVar220,8,1);
        auVar276 = NEON_ext(auVar235,auVar235,8,1);
        iVar138 = iVar138 + (int)auVar235._0_2_ * (int)auVar277._0_2_;
        iVar153 = iVar153 + (int)auVar235._2_2_ * (int)auVar277._2_2_;
        iVar156 = iVar156 + (int)auVar235._4_2_ * (int)auVar277._4_2_;
        iVar157 = iVar157 + (int)auVar235._6_2_ * (int)auVar277._6_2_;
        auVar31._10_2_ = uVar271;
        auVar31._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar31._12_2_ = uVar272;
        auVar31._14_2_ = uVar273;
        auVar32._10_2_ = uVar271;
        auVar32._0_10_ = *(unkbyte10 *)*pauVar15;
        auVar32._12_2_ = uVar272;
        auVar32._14_2_ = uVar273;
        auVar277 = NEON_ext(auVar31,auVar32,8,1);
        auVar199._0_4_ = auVar145._0_4_ + (int)(short)uVar143 * (int)auVar220._0_2_;
        auVar199._4_4_ = auVar145._4_4_ + (int)(short)((ulong)uVar143 >> 0x10) * (int)auVar220._2_2_
        ;
        auVar199._8_4_ = auVar145._8_4_ + (int)(short)((ulong)uVar143 >> 0x20) * (int)auVar220._4_2_
        ;
        auVar199._12_4_ =
             auVar145._12_4_ + (int)(short)((ulong)uVar143 >> 0x30) * (int)auVar220._6_2_;
        iVar158 = iVar158 + (int)auVar276._0_2_ * (int)auVar264._0_2_;
        iVar172 = iVar172 + (int)auVar276._2_2_ * (int)auVar264._2_2_;
        iVar174 = iVar174 + (int)auVar276._4_2_ * (int)auVar264._4_2_;
        iVar176 = iVar176 + (int)auVar276._6_2_ * (int)auVar264._6_2_;
        auVar217._0_4_ = auVar144._0_4_ + (int)auVar277._0_2_ * (int)auVar274._0_2_;
        auVar217._4_4_ = auVar144._4_4_ + (int)auVar277._2_2_ * (int)auVar274._2_2_;
        auVar217._8_4_ = auVar144._8_4_ + (int)auVar277._4_2_ * (int)auVar274._4_2_;
        auVar217._12_4_ = auVar144._12_4_ + (int)auVar277._6_2_ * (int)auVar274._6_2_;
        pauVar124 = pauVar124 + 2;
        auVar145 = auVar199;
        auVar144 = auVar217;
      } while (uVar109 != 0);
      iVar138 = auVar199._0_4_ + iVar138 + auVar217._0_4_ + iVar158 +
                auVar199._4_4_ + iVar153 + auVar217._4_4_ + iVar172 +
                auVar199._8_4_ + iVar156 + auVar217._8_4_ + iVar174 +
                auVar199._12_4_ + iVar157 + auVar217._12_4_ + iVar176;
      pauVar120 = (undefined1 (*) [16])(*pauVar120 + uVar103 * 2);
      if (uVar116 != uVar103) goto LAB_0010ef68;
    }
    uVar141 = ((iVar93 >> 0x12) + (iVar142 >> 0x12) + (iVar91 >> 0x12) + (iVar89 >> 0x12) +
               (iVar159 >> 0x12) + (iVar173 >> 0x12) + (iVar175 >> 0x12) + (iVar138 >> 0x12)) *
              0x10000 >> 0x13;
    uVar178 = -uVar141;
    if (-1 < (int)uVar141) {
      uVar178 = uVar141;
    }
    if (0x3ff < (uVar178 & 0xffff)) {
      uVar178 = 0x400;
    }
    uVar141 = (uVar178 & 0xffff) * (uVar178 & 0xffff);
    uVar115 = 0x100419 - uVar141;
    iVar155 = (int)LZCOUNT(uVar115);
    uVar178 = uVar115 >> (ulong)(0x10U - iVar155 & 0x1f);
    if (0xf0419 < uVar141) {
      uVar178 = uVar115 << (ulong)(iVar155 - 0x10U & 0x1f);
    }
    iVar93 = uVar178 * 0x10000 + 0x40000000;
    iVar142 = iVar93 >> 0x10;
    iVar93 = iVar93 >> 0xf;
    uVar178 = uVar131 - 1;
    uVar116 = (ulong)uVar178;
    iVar155 = (((int)(((int)((((uint)((((iVar142 * -0x579 >> 0xf) + 0x9f1) * iVar93 + -0x14610000 >>
                                      0x10) * iVar142) >> 0xf) + 0x3d82 & 0xffff) * iVar93 +
                            -0x1a890000) >> 4 & 0xffff0000U) + iVar155 * -0x4000000 + 0x48000000) >>
               2) + -0x5ff8000 >> 0x10) * 0x6000 >> 0xf;
    if ((int)uVar131 < 2) {
      iVar93 = 0;
    }
    else {
      if (uVar178 < 8) {
        uVar103 = 0;
        iVar93 = 0;
      }
      else {
        uVar103 = uVar116 & 0xfffffff8;
        iVar93 = 2 - uVar131;
        iVar156 = 0;
        iVar157 = 0;
        iVar158 = 0;
        iVar172 = 0;
        iVar174 = 0;
        iVar176 = 0;
        iVar177 = 0;
        iVar227 = 0;
        psVar121 = local_3b8;
        uVar109 = uVar103;
        iVar142 = DAT_00102740;
        iVar91 = UNK_00102744;
        iVar89 = UNK_00102748;
        iVar159 = UNK_0010274c;
        iVar173 = DAT_001027d0;
        iVar175 = UNK_001027d4;
        iVar138 = UNK_001027d8;
        iVar153 = UNK_001027dc;
        do {
          iVar252 = iVar142 * 2;
          iVar230 = iVar91 * 2;
          iVar231 = iVar89 * 2;
          iVar239 = iVar159 * 2;
          uVar34 = *(ssc_u64_u *)(psVar121 + piVar136[2] + 4);
          uVar143 = *(ssc_u64_u *)(psVar121 + piVar136[2]);
          iVar240 = iVar173 * 2;
          iVar243 = iVar175 * 2;
          iVar244 = iVar138 * 2;
          iVar247 = iVar153 * 2;
          uVar109 = uVar109 - 8;
          iVar173 = iVar173 + 8;
          iVar175 = iVar175 + 8;
          iVar138 = iVar138 + 8;
          iVar153 = iVar153 + 8;
          iVar142 = iVar142 + 8;
          iVar91 = iVar91 + 8;
          iVar89 = iVar89 + 8;
          iVar159 = iVar159 + 8;
          iVar174 = iVar174 + ((int)(short)uVar34 + (int)psVar121[4]) * (iVar93 + iVar252);
          iVar176 = iVar176 + ((int)(short)((ulong)uVar34 >> 0x10) + (int)psVar121[5]) *
                              (iVar93 + iVar230);
          iVar177 = iVar177 + ((int)(short)((ulong)uVar34 >> 0x20) + (int)psVar121[6]) *
                              (iVar93 + iVar231);
          iVar227 = iVar227 + ((int)(short)((ulong)uVar34 >> 0x30) + (int)psVar121[7]) *
                              (iVar93 + iVar239);
          iVar156 = iVar156 + ((int)(short)uVar143 + (int)*psVar121) * (iVar93 + iVar240);
          iVar157 = iVar157 + ((int)(short)((ulong)uVar143 >> 0x10) + (int)psVar121[1]) *
                              (iVar93 + iVar243);
          iVar158 = iVar158 + ((int)(short)((ulong)uVar143 >> 0x20) + (int)psVar121[2]) *
                              (iVar93 + iVar244);
          iVar172 = iVar172 + ((int)(short)((ulong)uVar143 >> 0x30) + (int)psVar121[3]) *
                              (iVar93 + iVar247);
          psVar121 = psVar121 + 8;
        } while (uVar109 != 0);
        iVar93 = iVar156 + iVar174 + iVar157 + iVar176 + iVar158 + iVar177 + iVar172 + iVar227;
        if (uVar103 == uVar116) goto LAB_0010f144;
      }
      iVar142 = (uVar128 + (int)uVar103 * 2) - *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
      lVar101 = uVar116 - uVar103;
      psVar121 = local_3b8 + uVar103 + (long)piVar136[2];
      psVar104 = local_3b8 + uVar103;
      do {
        iVar142 = iVar142 + 2;
        lVar101 = lVar101 + -1;
        iVar93 = iVar93 + ((int)*psVar121 + (int)*psVar104) * iVar142;
        psVar121 = psVar121 + 1;
        psVar104 = psVar104 + 1;
      } while (lVar101 != 0);
    }
LAB_0010f144:
    iVar142 = 0;
    if (uVar178 * 2 != 0) {
      iVar142 = iVar93 / (int)(uVar178 * 2);
    }
    lVar101 = (long)(iVar142 + 0x400 >> 2) * -0x2aaaaaab;
    sVar88 = -0x200;
    if (iVar142 < 0x2c18) {
      sVar88 = (short)((ulong)lVar101 >> 0x20) - (short)(lVar101 >> 0x3f);
    }
    sVar171 = 0x200;
    if (-0x3415 < iVar142) {
      sVar171 = sVar88;
    }
    if (iVar155 < -0x3ff) {
      iVar155 = -0x400;
    }
    iVar155 = (short)((((short)iVar155 + sVar171) - (short)(local_63c >> 5)) + 0x500) + 0x80;
    local_140 = iVar155 >> 8 & (iVar155 >> 0x1f ^ 0xffffffffU);
    if (9 < local_140) {
      local_140 = 10;
    };
    ssc_ec_enc_icdf((int64_t)(uintptr_t)(auStack_538),local_140,(int64_t)(uintptr_t)(&DAT_00103d74),7);
    ssc_ec_tell_frac((int64_t)(uintptr_t)(auStack_538));
  }
  uVar141 = ssc_ec_tell_frac((int64_t)(uintptr_t)(auStack_538));
  uVar178 = uVar97 & 0x27 < (int)(iVar154 + ~uVar141);
  iVar155 = 8;
  if (uVar178 == 0) {
    iVar155 = 0;
  }
  local_2b0[0] = (iVar154 + ~uVar141) - iVar155;
  iVar91 = ssc_compute_allocation
                     (param_1,(ssc_u32_u *)(local_2b0),(undefined8)(uintptr_t)(auStack_538),*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - uVar128,
                      *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) + ~uVar128);
  iVar142 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c));
  iVar93 = iVar91;
  if (iVar142 != 0) {
    iVar93 = iVar142 + -1;
    if (iVar142 + -1 <= iVar91) {
      iVar93 = iVar91;
    }
    if (iVar142 + 1 < iVar93) {
      iVar93 = iVar142 + 1;
    }
  }
  *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) = iVar93;
  { static int f = 0; if (f++ < 2); }
  ssc_quant_fine_energy
            ((int64_t)(uintptr_t)(piVar136),*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - uVar128,lVar129,(int64_t)(uintptr_t)(auStack_468),
             (uintptr_t)(uintptr_t)((local_2b0 + 1)),(ssc_i64_u *)(auStack_538));
  { static int f = 0; if (f++ < 2); }
  ssc_quant_all_bands((int64_t)(uintptr_t)(piVar136),*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - uVar128,(int64_t)(uintptr_t)(puVar4 + 0x1e60),(int64_t)(uintptr_t)(&local_cc),
                      (undefined8)(uintptr_t)(local_360),(int64_t)(uintptr_t)(auStack_254),local_630,(int)param_1[4],local_13c,(int)param_1[10],
                      (int64_t)(uintptr_t)(local_4c0),iVar154 - iVar155,local_138,(undefined8)(uintptr_t)(auStack_538),iVar91,
                      (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)));
  if (uVar178 != 0) {
    ssc_ec_enc_bits((ssc_i64_u *)(auStack_538),(int)param_1[8] < 2,1);
  }
  ssc_quant_energy_finalise
            ((int64_t)(uintptr_t)(piVar136),*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) - uVar128,lVar129,(int64_t)(uintptr_t)(auStack_468),
             (uintptr_t)(uintptr_t)((local_2b0 + 1)),(int64_t)(uintptr_t)(auStack_198),
             (iVar90 - (local_520 + (int)LZCOUNT(local_518))) + 0x20,(ssc_i64_u *)(auStack_538));
  puVar4 = (undefined *)(PTR_previous_uhq_index_0011bcd0);
  if ((!bVar35) && (0 < (int)uVar14)) {
    if (uVar14 < 0x10) {
      uVar109 = 0;
    }
    else {
      uVar109 = uVar99 & 0xfffffff0;
      auVar151._8_2_ = 0x9000;
      auVar151._0_8_ = 0x9000900090009000;
      auVar151._10_2_ = 0x9000;
      auVar151._12_2_ = 0x9000;
      auVar151._14_2_ = 0x9000;
      puVar133 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar132 * 4 + 0xf0));
      uVar116 = uVar109;
      do {
        puVar133[-1] = auVar151._8_8_;
        puVar133[-2] = 0x9000900090009000;
        puVar133[1] = auVar151._8_8_;
        *puVar133 = 0x9000900090009000;
        puVar133 = puVar133 + 4;
        uVar116 = uVar116 - 0x10;
      } while (uVar116 != 0);
      if (uVar109 == uVar14) goto LAB_0010f3f8;
    }
    lVar101 = uVar14 - uVar109;
    puVar102 = (ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar132 * 4 + uVar109 * 2 + 0xe0));
    do {
      lVar101 = lVar101 + -1;
      *puVar102 = 0x9000;
      puVar102 = puVar102 + 1;
    } while (lVar101 != 0);
  }
LAB_0010f3f8:
  if (uVar128 != 0) {
    lVar101 = (long)(int)(uVar10 - uVar128);
    lVar108 = lVar98;
    if (lVar98 < lVar101 + 1) {
      lVar108 = lVar101 + 1;
    }
    uVar116 = lVar108 - lVar101;
    if (0xf < uVar116) {
      lVar100 = lVar132 * 4;
      lVar108 = lVar98;
      if (lVar98 < lVar101 + 1) {
        lVar108 = lVar101 + 1;
      }
      lVar129 = lVar100 + lVar101 * 2;
      lVar125 = lVar100 + (lVar98 + lVar101) * 2;
      if (((ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar100 + (lVar108 + lVar98) * 2 + 0xe0) <=
           (ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar129 + 0xe0)) ||
         ((ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar100 + lVar108 * 2 + 0xe0) <=
          (ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar125 + 0xe0))) {
        uVar103 = uVar116 & 0xfffffffffffffff0;
        puVar133 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar125 + 0xf0));
        auVar152._8_2_ = 0x9000;
        auVar152._0_8_ = 0x9000900090009000;
        auVar152._10_2_ = 0x9000;
        auVar152._12_2_ = 0x9000;
        auVar152._14_2_ = 0x9000;
        lVar101 = uVar103 + lVar101;
        puVar112 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar129 + 0xf0));
        uVar109 = uVar103;
        do {
          uVar143 = auVar152._8_8_;
          puVar112[-1] = uVar143;
          puVar112[-2] = 0x9000900090009000;
          puVar112[1] = uVar143;
          *puVar112 = 0x9000900090009000;
          uVar109 = uVar109 - 0x10;
          puVar133[-1] = uVar143;
          puVar133[-2] = 0x9000900090009000;
          puVar133[1] = uVar143;
          *puVar133 = 0x9000900090009000;
          puVar133 = puVar133 + 4;
          puVar112 = puVar112 + 4;
        } while (uVar109 != 0);
        if (uVar116 == uVar103) goto LAB_0010f4d8;
      }
    }
    lVar100 = lVar132 * 4 + 0xe0;
    lVar108 = (lVar101 + lVar98) * 2;
    do {
      *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar101 * 2 + lVar100)) = 0x9000;
      lVar101 = lVar101 + 1;
      *(ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar108 + lVar100)) = 0x9000;
      lVar108 = lVar108 + 2;
    } while (lVar101 < lVar98);
  }
LAB_0010f4d8:
  uVar10 = uVar10 * 2;
  uVar116 = (ulong)uVar10;
  *(ssc_u32_u *)puVar4 = uVar128;
  *(ssc_i32_u *)(param_1 + 7) = iVar137;
  *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x3c)) = (short)iVar122;
  if (uVar97 == 0) {
    if (0 < (int)uVar10) {
      if (uVar10 < 0x10) {
LAB_0010f5e0:
        uVar109 = 0;
      }
      else {
        lVar108 = lVar132 * 4;
        lVar101 = lVar108 + uVar99 * 2;
        if (((ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar101 + 0xe0) < (long)(uintptr_t)(uintptr_t)((param_1)) + lVar108 + uVar116 * 2 + 0xe0)
           && ((ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar108 + 0xe0) <
               (long)(uintptr_t)(uintptr_t)((param_1)) + lVar101 + uVar116 * 2 + 0xe0)) goto LAB_0010f5e0;
        uVar109 = uVar116 & 0xfffffff0;
        lVar101 = (long)(uintptr_t)(uintptr_t)((param_1)) + lVar132 * 4;
        uVar103 = uVar109;
        do {
          auVar145 = *(vec128_t *)(uintptr_t)((lVar101 + 0xe0));
          uVar143 = *(ssc_u64_u *)(uintptr_t)((lVar101 + 0xf0));
          uVar34 = *(ssc_u64_u *)(uintptr_t)((lVar101 + 0xf8));
          lVar108 = lVar101 + uVar99 * 2;
          uVar103 = uVar103 - 0x10;
          lVar101 = lVar101 + 0x20;
          *(ssc_i64_u *)(uintptr_t)((lVar108 + 0xe8)) = auVar145._8_8_;
          *(ssc_i64_u *)(uintptr_t)((lVar108 + 0xe0)) = auVar145._0_8_;
          *(ssc_u64_u *)(uintptr_t)((lVar108 + 0xf8)) = uVar34;
          *(ssc_u64_u *)(uintptr_t)((lVar108 + 0xf0)) = uVar143;
        } while (uVar103 != 0);
        if (uVar109 == uVar116) goto LAB_0010f60c;
      }
      lVar101 = uVar116 - uVar109;
      puVar102 = (ssc_u16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar132 * 4 + uVar109 * 2 + 0xe0));
      do {
        lVar101 = lVar101 + -1;
        puVar102[uVar99] = *puVar102;
        puVar102 = puVar102 + 1;
      } while (lVar101 != 0);
    }
LAB_0010f60c:
    if (iVar90 < iVar11 + (int)LZCOUNT(uVar105) + -0x1d) goto LAB_0010f61c;
    *(ssc_u32_u *)(param_1 + 8) = 0;
  }
  else {
    if (0 < (int)uVar10) {
      if (uVar10 < 0x10) {
LAB_0010f54c:
        uVar109 = 0;
      }
      else {
        lVar108 = lVar132 * 4;
        lVar101 = lVar108 + uVar99 * 2;
        if (((ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar101 + 0xe0) < (long)(uintptr_t)(uintptr_t)((param_1)) + lVar108 + uVar116 * 2 + 0xe0)
           && ((ulong)((long)(uintptr_t)(uintptr_t)((param_1)) + lVar108 + 0xe0) <
               (long)(uintptr_t)(uintptr_t)((param_1)) + lVar101 + uVar116 * 2 + 0xe0)) goto LAB_0010f54c;
        uVar109 = uVar116 & 0xfffffff0;
        pauVar120 = (undefined1 (*) [16])(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar132 * 4 + 0xf0));
        uVar103 = uVar109;
        do {
          pauVar2 = (undefined1 (*) [16])(*pauVar120 + uVar99 * 2);
          uVar103 = uVar103 - 0x10;
          pauVar124 = pauVar120 + -1;
          auVar145 = *(vec128_t *)*pauVar120;
          pauVar120 = pauVar120 + 2;
          auVar144 = NEON_smin(*(vec128_t *)pauVar2[-1],*(vec128_t *)*pauVar124,2);
          auVar145 = NEON_smin(*(vec128_t *)*pauVar2,auVar145,2);
          *(ssc_i64_u *)(pauVar2[-1] + 8) = auVar144._8_8_;
          *(ssc_i64_u *)pauVar2[-1] = auVar144._0_8_;
          *(ssc_i64_u *)(*pauVar2 + 8) = auVar145._8_8_;
          *(ssc_i64_u *)*pauVar2 = auVar145._0_8_;
        } while (uVar103 != 0);
        if (uVar109 == uVar116) goto LAB_0010f61c;
      }
      lVar101 = uVar116 - uVar109;
      psVar121 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar132 * 4 + uVar109 * 2 + 0xe0));
      do {
        sVar88 = psVar121[uVar99];
        if (*psVar121 <= psVar121[uVar99]) {
          sVar88 = *psVar121;
        }
        lVar101 = lVar101 + -1;
        psVar121[uVar99] = sVar88;
        psVar121 = psVar121 + 1;
      } while (lVar101 != 0);
    }
LAB_0010f61c:
    *(ssc_i32_u *)(param_1 + 8) = (int)param_1[8] + 1;
  }
  *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) = local_518;
  ssc_ec_enc_done((ssc_i64_u *)(auStack_538));
  sVar88 = 0;
  if (*local_5f8 != 0xff) {
    sVar88 = *local_5f8 + 1;
  }
  iVar91 = uVar9 + 4;
  *local_5f8 = sVar88;
  if (local_508 != 0) {
    iVar91 = -3;
  }
LAB_0010f670:
  return iVar91;
}
#undef STACK_ADDR
#undef local_63c
#undef local_630
#undef local_5f8
#undef local_5ac
#undef local_570
#undef auStack_538
#undef local_530
#undef local_520
#undef local_518
#undef local_508
#undef local_500
#undef local_4fc
#undef local_4f8
#undef local_4f4
#undef local_4f0
#undef local_4ec
#undef local_4e8
#undef local_4e4
#undef local_4e0
#undef local_4dc
#undef local_4d8
#undef local_4d4
#undef local_4d0
#undef local_4cc
#undef local_4c8
#undef local_4c4
#undef local_4c0
#undef auStack_4b8
#undef auStack_468
#undef local_414
#undef local_410
#undef asStack_408
#undef uStack_400
#undef asStack_3f8
#undef local_3b8
#undef local_360
#undef local_2b0
#undef auStack_254
#undef local_1f8
#undef local_1f0
#undef local_1a8
#undef local_1a4
#undef local_1a0
#undef local_19c
#undef auStack_198
#undef local_140
#undef local_13c
#undef local_138
#undef local_130
#undef local_128
#undef uStack_120
#undef auStack_118
#undef local_d0
#undef local_ce
#undef local_cc
#undef asStack_c8
#undef uStack_c4
#undef asStack_bc
#undef uStack_b4
#undef local_70



/* ==================================================================== */
/* Function: ssc_ec_tell_frac @ 0010f7c0 */
/* ==================================================================== */

int ssc_ec_tell_frac(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;

  iVar4 = (int)LZCOUNT(*(ssc_u32_u *)(uintptr_t)(param_1 + 0x20));
  uVar1 = *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) >> (ulong)(0x10U - iVar4 & 0x1f);
  uVar1 = uVar1 * uVar1;
  uVar2 = (uVar1 >> 0xf) >> (ulong)(uVar1 >> 0x1f);
  uVar2 = uVar2 * uVar2;
  uVar3 = (uVar2 >> 0xf) >> (ulong)(uVar2 >> 0x1f);
  return (iVar4 * 2 + ((int)uVar1 >> 0x1f)) * 4 + *(ssc_i32_u *)(uintptr_t)((param_1 + 0x18)) * 8 +
         ((int)uVar2 >> 0x1f & 0xfffffffeU) + ((int)(uVar3 * uVar3) >> 0x1f) + -0x100;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_init @ 0010f824 */
void ssc_ec_enc_init(ssc_u64_u *param_1, undefined8 param_2, undefined4 param_3)
{
  char *p = (char *)param_1;
  *(ssc_u64_u *)p = param_2;
  *(ssc_u32_u *)(p + 8) = param_3;
  memcpy((void *)(p + 12), (const void *)(ssc_image + 0x2750), 16);
  memcpy((void *)(p + 28), (const void *)(ssc_image + 0x2770), 16);
  *(ssc_u32_u *)(p + 44) = 0xffffffff;
  *(ssc_u32_u *)(p + 48) = 0;
}


/* Function: ssc_ec_encode @ 0010f850 */
/* ==================================================================== */

void ssc_ec_encode(long param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint cur_offs = *(ssc_u32_u *)(uintptr_t)(((long)param_1 + 0x1c));
  if (cur_offs >= 208 && cur_offs <= 216) {
  }

  uVar1 = *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20));
  uVar2 = 0;
  if (param_4 != 0) {
    uVar2 = uVar1 / param_4;
  }
  if (param_2 != 0) {
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) = uVar2 * (param_3 - param_2);
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x24)) = uVar1 + uVar2 * (param_2 - param_4) + *(ssc_i32_u *)(uintptr_t)((param_1 + 0x24));
    FUN_0010f88c((ssc_i64_u *)(uintptr_t)(param_1));
    return;
  }
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) = uVar1 + uVar2 * (param_3 - param_4);
  FUN_0010f88c((ssc_i64_u *)(uintptr_t)(param_1));
  return;
}


/* ==================================================================== */
/* Function: FUN_0010f88c @ 0010f88c */
/* ==================================================================== */

void FUN_0010f88c(ssc_i64_u *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;

  uVar3 = *(ssc_u32_u *)(param_1 + 4);
  if (uVar3 < 0x8001) {
    uVar2 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24));
    do {
      if (uVar2 >> 0xf == 0xff) {
        *(ssc_i32_u *)(param_1 + 5) = (int)param_1[5] + 1;
      }
      else {
        cVar1 = (char)(uVar2 >> 0x17);
        if (-1 < *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c))) {
          uVar3 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c));
          if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + uVar3 < *(ssc_u32_u *)(param_1 + 1)) {
            uVar5 = 0;
            *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) = uVar3 + 1;
            {
              uint8_t _b = (char)*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) + cVar1;
              *(char *)(uintptr_t)((*param_1 + (ulong)uVar3)) = _b;
              if (uVar3 <= 25 || (uVar3 >= 208 && uVar3 <= 220)) {
              }
            }
          }
          else {
            uVar5 = 0xffffffff;
          }
          *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar5;
        }
        iVar4 = (int)param_1[5];
        if (iVar4 != 0) {
          do {
            uVar3 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c));
            if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + uVar3 < *(ssc_u32_u *)(param_1 + 1)) {
              uVar5 = 0;
              *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) = uVar3 + 1;
              *(char *)(uintptr_t)((*param_1 + (ulong)uVar3)) = cVar1 + -1;
              iVar4 = (int)param_1[5];
            }
            else {
              uVar5 = 0xffffffff;
            }
            iVar4 = iVar4 + -1;
            *(ssc_i32_u *)(param_1 + 5) = iVar4;
            *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar5;
          } while (iVar4 != 0);
        }
        uVar5 = uVar2 >> 0xf;
        uVar3 = *(ssc_u32_u *)(param_1 + 4);
        uVar2 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24));
        *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) = uVar5 & 0xff;
      }
      uVar2 = (uVar2 & 0x7fff) << 8;
      uVar3 = uVar3 << 8;
      *(ssc_u32_u *)(param_1 + 4) = uVar3;
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24)) = uVar2;
      *(ssc_i32_u *)(param_1 + 3) = (int)param_1[3] + 8;
    } while (uVar3 < 0x8001);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_encode_bin @ 0010f994 */
/* ==================================================================== */

void ssc_ec_encode_bin(long param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;

  uVar1 = *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20));
  iVar2 = -1 << (ulong)(param_4 & 0x1f);
  uVar3 = uVar1 >> (ulong)(param_4 & 0x1f);
  if (param_2 != 0) {
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) = uVar3 * (param_3 - param_2);
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x24)) = uVar1 + uVar3 * (iVar2 + param_2) + *(ssc_i32_u *)(uintptr_t)((param_1 + 0x24));
    FUN_0010f88c((ssc_i64_u *)(uintptr_t)(param_1));
    return;
  }
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) = uVar1 + uVar3 * (iVar2 + param_3);
  FUN_0010f88c((ssc_i64_u *)(uintptr_t)(param_1));
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_bit_logp @ 0010f9d8 */
/* ==================================================================== */

void ssc_ec_enc_bit_logp(long param_1,int param_2,uint param_3)

{
  static int count = 0;
  if (count < 120) {;;
  }
  uint uVar1;
  uint uVar2;

  uVar1 = *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) >> (ulong)(param_3 & 0x1f);
  uVar2 = *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) - uVar1;
  if (param_2 != 0) {
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x24)) = *(ssc_i32_u *)(uintptr_t)((param_1 + 0x24)) + uVar2;
    uVar2 = uVar1;
  }
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) = uVar2;
  FUN_0010f88c((ssc_i64_u *)(uintptr_t)(param_1));
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_icdf @ 0010fa00 */
/* ==================================================================== */

void ssc_ec_enc_icdf(long param_1,uint param_2,long param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;

  uVar1 = *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20));
  uVar2 = uVar1 >> (ulong)(param_4 & 0x1f);
  if (0 < (int)param_2) {
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x24)) =
         (*(ssc_i32_u *)(uintptr_t)((param_1 + 0x24)) + uVar1) - uVar2 * *(byte *)(uintptr_t)((param_3 + (ulong)(param_2 - 1)));
    *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) =
         ((uint)*(byte *)(uintptr_t)((param_3 + (ulong)(param_2 - 1))) -
         (uint)*(byte *)(uintptr_t)((param_3 + (ulong)param_2))) * uVar2;
    FUN_0010f88c((ssc_i64_u *)(uintptr_t)(param_1));
    return;
  }
  *(ssc_u32_u *)(uintptr_t)((param_1 + 0x20)) = uVar1 - uVar2 * *(byte *)(uintptr_t)((param_3 + (int)param_2));
  FUN_0010f88c((ssc_i64_u *)(uintptr_t)(param_1));
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_uint @ 0010fa4c */
/* ==================================================================== */

void ssc_ec_enc_uint(ssc_i64_u *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint cur_offs = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c));
  if (cur_offs >= 208 && cur_offs <= 216) {
  }

  uVar7 = param_3 - 1;
  if (uVar7 < 0x100) {
    uVar5 = *(ssc_u32_u *)(param_1 + 4);
    uVar7 = 0;
    if (param_3 != 0) {
      uVar7 = uVar5 / param_3;
    }
    if (param_2 == 0) {
      uVar7 = (uVar7 - uVar7 * param_3) + uVar5;
    }
    else {
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24)) =
           uVar5 + uVar7 * (param_2 - param_3) + *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24));
    }
    *(ssc_u32_u *)(param_1 + 4) = uVar7;
    FUN_0010f88c(param_1);
    return;
  }
  uVar3 = 0x18 - (int)LZCOUNT(uVar7);
  uVar8 = *(ssc_u32_u *)(param_1 + 4);
  uVar7 = uVar7 >> (ulong)(uVar3 & 0x1f);
  uVar6 = param_2 >> (ulong)(uVar3 & 0x1f);
  uVar5 = uVar7 + 1;
  uVar4 = 0;
  if (uVar5 != 0) {
    uVar4 = uVar8 / uVar5;
  }
  if (uVar6 == 0) {
    uVar4 = uVar8 - uVar7 * uVar4;
  }
  else {
    *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24)) =
         uVar8 + uVar4 * (uVar6 - uVar5) + *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24));
  }
  *(ssc_u32_u *)(param_1 + 4) = uVar4;
  FUN_0010f88c(param_1);
  uVar5 = *(ssc_u32_u *)(param_1 + 2);
  uVar8 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
  uVar7 = uVar8 + uVar3;
  uVar6 = uVar8;
  if (0x20 < uVar7) {
    do {
      if ((uint)(*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c))) <
          *(ssc_u32_u *)(param_1 + 1)) {
        iVar2 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + 1;
        uVar7 = 0;
        *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) = iVar2;
        *(char *)(uintptr_t)((*param_1 + (ulong)(*(ssc_u32_u *)(param_1 + 1) - iVar2))) = (char)uVar5;
      }
      else {
        uVar7 = 0xffffffff;
      }
      uVar8 = uVar6 - 8;
      uVar5 = uVar5 >> 8;
      *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar7;
      bVar1 = 0xf < (int)uVar6;
      uVar6 = uVar8;
    } while (bVar1);
    uVar7 = uVar3 + uVar8;
  }
  *(ssc_u32_u *)(param_1 + 2) =
       (param_2 & (-1 << (ulong)(uVar3 & 0x1f) ^ 0xffffffffU)) << (ulong)(uVar8 & 0x1f) | uVar5;
  *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) = uVar7;
  *(ssc_u32_u *)(param_1 + 3) = (int)param_1[3] + uVar3;
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_bits @ 0010fba4 */
/* ==================================================================== */

void ssc_ec_enc_bits(ssc_i64_u *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;

  uVar3 = *(ssc_u32_u *)(param_1 + 2);
  uVar6 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
  uVar5 = uVar6 + param_3;
  uVar4 = uVar6;
  if (0x20 < uVar5) {
    do {
      if ((uint)(*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c))) <
          *(ssc_u32_u *)(param_1 + 1)) {
        iVar2 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + 1;
        uVar5 = 0;
        *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) = iVar2;
        *(char *)(uintptr_t)((*param_1 + (ulong)(*(ssc_u32_u *)(param_1 + 1) - iVar2))) = (char)uVar3;
      }
      else {
        uVar5 = 0xffffffff;
      }
      uVar6 = uVar4 - 8;
      uVar3 = uVar3 >> 8;
      *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar5;
      bVar1 = 0xf < (int)uVar4;
      uVar4 = uVar6;
    } while (bVar1);
    uVar5 = param_3 + uVar6;
  }
  *(ssc_u32_u *)(param_1 + 2) = param_2 << (ulong)(uVar6 & 0x1f) | uVar3;
  *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14)) = uVar5;
  *(ssc_i32_u *)(param_1 + 3) = (int)param_1[3] + param_3;
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_patch_initial_bits @ 0010fc30 */
/* ==================================================================== */

void ssc_ec_enc_patch_initial_bits(ssc_u64_u *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;

  uVar2 = 8 - param_3;
  uVar1 = ~(-1 << (ulong)(param_3 & 0x1f)) << (ulong)(uVar2 & 0x1f);
  if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) != 0) {
    *(byte *)(uintptr_t)(*param_1) =
         *(byte *)(uintptr_t)(*param_1) & ((byte)uVar1 ^ 0xff) | (byte)(param_2 << (ulong)(uVar2 & 0x1f));
    return;
  }
  if (-1 < (int)*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c))) {
    *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) =
         *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) & (uVar1 ^ 0xffffffff) | param_2 << (ulong)(uVar2 & 0x1f);
    return;
  }
  if (0x800000U >> (ulong)(param_3 & 0x1f) < *(ssc_u32_u *)(param_1 + 4)) {
    *(ssc_u32_u *)(param_1 + 6) = 0xffffffff;
    return;
  }
  *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24)) =
       *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24)) & (uVar1 << 0xf ^ 0xffffffff) |
       param_2 << (ulong)(0x17 - param_3 & 0x1f);
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_shrink @ 0010fcc8 */
/* ==================================================================== */

void ssc_ec_enc_shrink(ssc_i64_u *param_1,uint param_2)

{
  SSC_COPY8((*param_1 + (ulong)param_2) - (ulong)*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)),
            (*param_1 + (ulong)*(ssc_u32_u *)(param_1 + 1)) - (ulong)*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)), *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)));
  *(ssc_u32_u *)(param_1 + 1) = param_2;
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_enc_done @ 0010fd08 */
/* ==================================================================== */

void ssc_ec_enc_done(ssc_i64_u *param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;

  iVar5 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x24));
  iVar4 = (int)LZCOUNT((int)param_1[4]);
  uVar7 = iVar4 - 8;
  uVar8 = 0x7fffff >> (ulong)(uVar7 & 0x1f);
  uVar3 = uVar8 + iVar5 & -0x800000 >> (uVar7 & 0x1f);
  if ((uint)(iVar5 + (int)param_1[4]) <= (uVar3 | uVar8)) {
    uVar7 = iVar4 - 7;
    uVar3 = (uVar8 >> 1) + iVar5 & (uVar8 >> 1 ^ 0xffffffff);
  }
  uVar8 = uVar7;
  if (0 < (int)uVar7) {
    do {
      if (uVar3 >> 0xf == 0xff) {
        *(ssc_i32_u *)(param_1 + 5) = (int)param_1[5] + 1;
      }
      else {
        cVar2 = (char)(uVar3 >> 0x17);
        if (-1 < *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c))) {
          uVar7 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c));
          if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + uVar7 < *(ssc_u32_u *)(param_1 + 1)) {
            uVar6 = 0;
            *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) = uVar7 + 1;
            *(char *)(uintptr_t)((*param_1 + (ulong)uVar7)) = (char)*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) + cVar2;
          }
          else {
            uVar6 = 0xffffffff;
          }
          *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar6;
        }
        iVar5 = (int)param_1[5];
        if (iVar5 != 0) {
          do {
            uVar7 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c));
            if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + uVar7 < *(ssc_u32_u *)(param_1 + 1)) {
              uVar6 = 0;
              *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) = uVar7 + 1;
              *(char *)(uintptr_t)((*param_1 + (ulong)uVar7)) = cVar2 + -1;
              iVar5 = (int)param_1[5];
            }
            else {
              uVar6 = 0xffffffff;
            }
            iVar5 = iVar5 + -1;
            *(ssc_i32_u *)(param_1 + 5) = iVar5;
            *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar6;
          } while (iVar5 != 0);
        }
        *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) = uVar3 >> 0xf & 0xff;
      }
      uVar3 = (uVar3 & 0x7fff) << 8;
      uVar7 = uVar8 - 8;
      bVar1 = 7 < (int)uVar8;
      uVar8 = uVar7;
    } while (uVar7 != 0 && bVar1);
  }
  if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) < 0) {
    iVar5 = (int)param_1[5];
    if (iVar5 != 0) goto LAB_0010fed4;
  }
  else {
    uVar3 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c));
    if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + uVar3 < *(ssc_u32_u *)(param_1 + 1)) {
      uVar8 = 0;
      *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) = uVar3 + 1;
      *(char *)(uintptr_t)((*param_1 + (ulong)uVar3)) = (char)*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c));
    }
    else {
      uVar8 = 0xffffffff;
    }
    iVar5 = (int)param_1[5];
    *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar8;
    while (iVar5 != 0) {
LAB_0010fed4:
      uVar3 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c));
      if (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + uVar3 < *(ssc_u32_u *)(param_1 + 1)) {
        uVar8 = 0;
        *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) = uVar3 + 1;
        *(undefined1 *)(uintptr_t)((*param_1 + (ulong)uVar3)) = 0xff;
        iVar5 = (int)param_1[5];
      }
      else {
        uVar8 = 0xffffffff;
      }
      iVar5 = iVar5 + -1;
      *(ssc_i32_u *)(param_1 + 5) = iVar5;
      *(ssc_u32_u *)(param_1 + 6) = *(ssc_u32_u *)(param_1 + 6) | uVar8;
    }
    *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c)) = 0;
  }
  uVar3 = *(ssc_u32_u *)(param_1 + 2);
  iVar5 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x14));
  iVar4 = iVar5;
  if (iVar5 < 8) {
    uVar8 = *(ssc_u32_u *)(param_1 + 6);
  }
  else {
    do {
      if ((uint)(*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c))) <
          *(ssc_u32_u *)(param_1 + 1)) {
        iVar5 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) + 1;
        uVar8 = 0;
        *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc)) = iVar5;
        *(char *)(uintptr_t)((*param_1 + (ulong)(*(ssc_u32_u *)(param_1 + 1) - iVar5))) = (char)uVar3;
      }
      else {
        uVar8 = 0xffffffff;
      }
      iVar5 = iVar4 + -8;
      uVar3 = uVar3 >> 8;
      uVar8 = *(ssc_u32_u *)(param_1 + 6) | uVar8;
      *(ssc_u32_u *)(param_1 + 6) = uVar8;
      bVar1 = 0xf < iVar4;
      iVar4 = iVar5;
    } while (bVar1);
  }
  if (uVar8 == 0) {
    bVar9 = (byte)uVar3;
    SSC_CLEAR((void *)(uintptr_t)((uintptr_t)*param_1) + (ulong)*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)),
              (int)param_1[1] - (*(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) + *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc))));
    if (0 < iVar5) {
      uVar3 = *(ssc_u32_u *)(param_1 + 1);
      uVar8 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0xc));
      if (uVar8 < uVar3) {
        if ((uVar3 <= *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x1c)) + uVar8) && ((int)-uVar7 < iVar5)) {
          bVar9 = bVar9 & ((byte)(-1 << (ulong)(-uVar7 & 0x1f)) ^ 0xff);
          *(ssc_u32_u *)(param_1 + 6) = 0xffffffff;
        }
        *(byte *)(uintptr_t)((*param_1 + (ulong)(uVar3 + ~uVar8))) =
             *(byte *)(uintptr_t)((*param_1 + (ulong)(uVar3 + ~uVar8))) | bVar9;
      }
      else {
        *(ssc_u32_u *)(param_1 + 6) = 0xffffffff;
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Function: smull32_x86_scalable @ 0010fff8 */
/* ==================================================================== */

ulong smull32_x86_scalable(int param_1,int param_2)

{
  return (ulong)((long)param_2 * (long)param_1) >> 0x20;
}


/* ==================================================================== */
/* Function: ssc_fft @ 00110004 */
/* ==================================================================== */

void ssc_fft(ssc_i32_u *param_1,ssc_u32_u *param_2,ssc_u64_u *param_3)

{
  ssc_u32_u *puVar1;
  vec128_t auVar2;
  vec128_t auVar3;
  vec128_t auVar4;
  vec128_t auVar5;
  vec128_t auVar6;
  vec128_t auVar7;
  vec128_t auVar8;
  vec128_t auVar9;
  vec128_t auVar10;
  vec128_t auVar11;
  vec128_t auVar12;
  vec128_t auVar13;
  vec128_t auVar14;
  vec128_t auVar15;
  vec128_t auVar16;
  vec128_t auVar17;
  vec128_t auVar18;
  vec128_t auVar19;
  vec128_t auVar20;
  vec128_t auVar21;
  vec128_t auVar22;
  vec128_t auVar23;
  vec128_t auVar24;
  vec128_t auVar25;
  vec128_t auVar26;
  vec128_t auVar27;
  vec128_t auVar28;
  vec128_t auVar29;
  vec128_t auVar30;
  vec128_t auVar31;
  vec128_t auVar32;
  vec128_t auVar33;
  vec128_t auVar34;
  vec128_t auVar35;
  vec128_t auVar36;
  vec128_t auVar37;
  vec128_t auVar38;
  vec128_t auVar39;
  vec128_t auVar40;
  vec128_t auVar41;
  vec128_t auVar42;
  vec128_t auVar43;
  vec128_t auVar44;
  vec128_t auVar45;
  vec128_t auVar46;
  vec128_t auVar47;
  vec128_t auVar48;
  vec128_t auVar49;
  vec128_t auVar50;
  ssc_i32_u *piVar51;
  ssc_i32_u *piVar52;
  ssc_i32_u *piVar53;
  ssc_i16_u *psVar54;
  long lVar55;
  long lVar56;
  long lVar57;
  ssc_i32_u *piVar58;
  ssc_i32_u *piVar59;
  ssc_u64_u *puVar60;
  ssc_u64_u *puVar61;
  long lVar62;
  ssc_i32_u *piVar63;
  int iVar64;
  int iVar65;
  int iVar66;
  int iVar67;
  int iVar68;
  int iVar69;
  undefined8 uVar70;
  vec128_t auVar72;
  undefined8 uVar71;
  vec128_t auVar73;
  vec128_t auVar74;
  vec128_t auVar75;
  vec128_t auVar76;
  vec128_t auVar77;
  vec128_t auVar78;
  vec128_t auVar79;
  vec128_t auVar80;
  vec128_t auVar81;
  vec128_t auVar82;
  vec128_t auVar83;
  vec128_t auVar84;
  vec128_t auVar85;
  vec128_t auVar86;
  vec128_t auVar87;
  vec128_t auVar88;
  vec128_t auVar89;
  int iVar91;
  vec128_t auVar90;
  undefined8 uVar92;
  vec128_t auVar94;
  vec128_t auVar95;
  undefined8 uVar93;
  vec128_t auVar96;
  vec128_t auVar97;
  vec128_t auVar98;
  vec128_t auVar99;
  vec128_t auVar100;
  vec128_t auVar101;
  vec128_t auVar102;
  vec128_t auVar103;
  vec128_t auVar104;
  int iVar105;
  undefined8 uVar106;
  vec128_t auVar108;
  int iVar130;
  vec128_t auVar109;
  vec128_t auVar110;
  undefined8 uVar107;
  vec128_t auVar111;
  vec128_t auVar112;
  vec128_t auVar113;
  vec128_t auVar114;
  vec128_t auVar115;
  vec128_t auVar116;
  vec128_t auVar117;
  vec128_t auVar118;
  vec128_t auVar119;
  vec128_t auVar120;
  vec128_t auVar121;
  vec128_t auVar122;
  vec128_t auVar123;
  vec128_t auVar124;
  vec128_t auVar125;
  vec128_t auVar126;
  vec128_t auVar127;
  vec128_t auVar128;
  vec128_t auVar129;
  int iVar131;
  int iVar132;
  int iVar133;
  int iVar134;
  int iVar135;
  int iVar136;
  int iVar137;

  iVar64 = *param_1;
  iVar67 = param_1[1];
  psVar54 = *(ssc_i16_u **)(param_1 + 2);
  do {
    iVar64 = iVar64 + -1;
    puVar1 = (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + (long)*psVar54 * 4));
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    param_2 = param_2 + (*param_1 << 1);
    puVar1[2] = *param_2;
    puVar1[3] = param_2[1];
    param_2 = param_2 + 1 + (*param_1 << 1);
    puVar1[4] = param_2[-1];
    puVar1[5] = *param_2;
    param_2 = param_2 + (1 - (long)(*param_1 << 2));
    psVar54 = psVar54 + 1;
  } while (iVar64 != 0);
  lVar55 = 0;
  iVar64 = (int)DAT_00102830;
  iVar66 = (int)((ulong)DAT_00102830 >> 0x20);
  if (iVar67 == 0) {
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55));
      lVar55 = lVar55 + 0x18;
      lVar56 = (long)(int)puVar60[1] * 0x2aaaaaab;
      auVar104._0_8_ = (long)(int)puVar60[2] * 0x2aaaaaab;
      auVar104._8_8_ = (long)(int)((ulong)puVar60[2] >> 0x20) * 0x2aaaaaab;
      auVar117._0_8_ = (long)(int)*puVar60 * 0x2aaaaaab;
      auVar117._8_8_ = (long)(int)((ulong)*puVar60 >> 0x20) * 0x2aaaaaab;
      auVar86._8_8_ = (long)(int)((ulong)puVar60[1] >> 0x20) * 0x2aaaaaab;
      auVar86._0_8_ = lVar56;
      uVar71 = NEON_rshrn(lVar56,auVar86,0x1f,8);
      iVar65 = (int)((ulong)uVar71 >> 0x20);
      uVar70 = NEON_rshrn(auVar104._0_8_,auVar104,0x1f,8);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      iVar67 = (int)uVar70 + (int)uVar71;
      iVar68 = iVar105 + iVar65;
      auVar125._0_8_ = (long)((int)uVar71 - (int)uVar70) * -0x6ed9eba1;
      auVar125._8_8_ = (long)(iVar65 - iVar105) * -0x6ed9eba1;
      uVar71 = NEON_rshrn(uVar70,auVar125,0x1f,8);
      uVar70 = NEON_rshrn(auVar125._0_8_,auVar117,0x1f,8);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      iVar130 = (int)uVar70 - (iVar67 >> 1);
      iVar136 = iVar105 - (iVar68 >> 1);
      uVar71 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
      iVar65 = (int)((ulong)uVar71 >> 0x20);
      *puVar60 = CONCAT44(iVar68 + iVar105,iVar67 + (int)uVar70);
      puVar60[1] = CONCAT44(iVar136 - iVar65,iVar130 - (int)uVar71);
      puVar60[2] = CONCAT44(iVar65 + iVar136,(int)uVar71 + iVar130);
      uVar71 = DAT_00102818;
    } while ((int)lVar55 != 0xd80);
    lVar55 = 0;
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55));
      lVar57 = *(ssc_i64_u *)(param_1 + 4);
      lVar55 = lVar55 + 0x48;
      auVar80._0_8_ = (long)(int)puVar60[3] * 0x2aaaaaab;
      auVar80._8_8_ = (long)(int)((ulong)puVar60[3] >> 0x20) * 0x2aaaaaab;
      auVar100._0_8_ = (long)(int)puVar60[6] * 0x2aaaaaab;
      auVar100._8_8_ = (long)(int)((ulong)puVar60[6] >> 0x20) * 0x2aaaaaab;
      auVar118._0_8_ = (long)(int)puVar60[7] * 0x2aaaaaab;
      auVar118._8_8_ = (long)(int)((ulong)puVar60[7] >> 0x20) * 0x2aaaaaab;
      uVar70 = NEON_rshrn(auVar80._0_8_,auVar80,0x1f,8);
      uVar92 = NEON_rshrn(auVar100._0_8_,auVar100,0x1f,8);
      uVar106 = NEON_rshrn(auVar118._0_8_,auVar118,0x1f,8);
      iVar65 = (int)((ulong)uVar70 >> 0x20);
      iVar105 = (int)((ulong)uVar92 >> 0x20);
      iVar67 = (int)uVar92 + (int)uVar70;
      iVar68 = iVar105 + iVar65;
      lVar56 = (long)((int)uVar70 - (int)uVar92) * -0x6ed9eba1;
      auVar41._8_8_ = (long)(iVar65 - iVar105) * -0x6ed9eba1;
      auVar41._0_8_ = lVar56;
      uVar92 = NEON_rshrn(uVar92,auVar41,0x1f,8);
      auVar46._8_8_ = (long)(int)((ulong)*puVar60 >> 0x20) * 0x2aaaaaab;
      auVar46._0_8_ = (long)(int)*puVar60 * 0x2aaaaaab;
      uVar70 = NEON_rshrn(lVar56,auVar46,0x1f,8);
      iVar65 = (int)((ulong)uVar70 >> 0x20);
      iVar136 = (int)uVar70 - (iVar67 >> 1);
      iVar137 = iVar65 - (iVar68 >> 1);
      uVar93 = NEON_rev64(CONCAT44((int)((ulong)uVar92 >> 0x20) * iVar66,(int)uVar92 * iVar64),4);
      auVar47._8_8_ = (long)(int)((ulong)puVar60[4] >> 0x20) * 0x2aaaaaab;
      auVar47._0_8_ = (long)(int)puVar60[4] * 0x2aaaaaab;
      uVar92 = NEON_rshrn(uVar70,auVar47,0x1f,8);
      iVar130 = (int)((ulong)uVar92 >> 0x20);
      *puVar60 = CONCAT44(iVar68 + iVar65,iVar67 + (int)uVar70);
      iVar67 = (int)((ulong)uVar93 >> 0x20);
      iVar65 = (int)uVar71;
      iVar68 = (int)((ulong)uVar71 >> 0x20);
      puVar60[3] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar93);
      iVar105 = (int)((ulong)uVar106 >> 0x20);
      puVar60[6] = CONCAT44(iVar67 + iVar137,(int)uVar93 + iVar136);
      uVar70 = NEON_rev64(CONCAT44(iVar130 * iVar68,(int)uVar92 * iVar65),4);
      iVar67 = *(ssc_i32_u *)(uintptr_t)((lVar57 + 0x300));
      uVar93 = NEON_rev64(CONCAT44(iVar105 * iVar68,(int)uVar106 * iVar65),4);
      lVar56 = (long)(int)puVar60[8] * 0x2aaaaaab;
      auVar81._0_8_ =
           (long)(int)uVar70 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x184)) +
           (long)(int)uVar92 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x180));
      auVar81._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x184)) +
           (long)iVar130 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x180));
      auVar101._0_8_ =
           (long)(int)uVar93 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) + (long)(int)uVar106 * (long)iVar67;
      auVar101._8_8_ =
           (long)(int)((ulong)uVar93 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) +
           (long)iVar105 * (long)iVar67;
      uVar92 = NEON_rshrn(auVar81._0_8_,auVar81,0x1f,8);
      auVar48._8_8_ = (long)(int)((ulong)puVar60[8] >> 0x20) * 0x2aaaaaab;
      auVar48._0_8_ = lVar56;
      uVar70 = NEON_rshrn(lVar56,auVar48,0x1f,8);
      iVar131 = (int)((ulong)uVar70 >> 0x20);
      uVar93 = NEON_rshrn(auVar101._0_8_,auVar101,0x1f,8);
      iVar105 = (int)((ulong)uVar92 >> 0x20);
      iVar136 = (int)((ulong)uVar93 >> 0x20);
      iVar67 = (int)uVar93 + (int)uVar92;
      iVar130 = iVar136 + iVar105;
      auVar119._0_8_ = (long)((int)uVar92 - (int)uVar93) * -0x6ed9eba1;
      auVar119._8_8_ = (long)(iVar105 - iVar136) * -0x6ed9eba1;
      uVar92 = NEON_rshrn(uVar93,auVar119,0x1f,8);
      auVar42._8_8_ = (long)(int)((ulong)puVar60[1] >> 0x20) * 0x2aaaaaab;
      auVar42._0_8_ = (long)(int)puVar60[1] * 0x2aaaaaab;
      uVar106 = NEON_rshrn(auVar119._0_8_,auVar42,0x1f,8);
      iVar105 = (int)((ulong)uVar106 >> 0x20);
      iVar136 = (int)uVar106 - (iVar67 >> 1);
      iVar137 = iVar105 - (iVar130 >> 1);
      auVar50._8_8_ = (long)(int)((ulong)puVar60[5] >> 0x20) * 0x2aaaaaab;
      auVar50._0_8_ = (long)(int)puVar60[5] * 0x2aaaaaab;
      uVar107 = NEON_rshrn(uVar106,auVar50,0x1f,8);
      uVar93 = NEON_rev64(CONCAT44((int)((ulong)uVar92 >> 0x20) * iVar66,(int)uVar92 * iVar64),4);
      puVar60[1] = CONCAT44(iVar130 + iVar105,iVar67 + (int)uVar106);
      iVar105 = (int)((ulong)uVar107 >> 0x20);
      iVar67 = (int)((ulong)uVar93 >> 0x20);
      uVar92 = NEON_rev64(CONCAT44(iVar105 * iVar68,(int)uVar107 * iVar65),4);
      puVar60[4] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar93);
      puVar60[7] = CONCAT44(iVar67 + iVar137,(int)uVar93 + iVar136);
      uVar93 = NEON_rev64(CONCAT44(iVar131 * iVar68,(int)uVar70 * iVar65),4);
      iVar67 = *(ssc_i32_u *)(uintptr_t)((lVar57 + 0x300));
      auVar82._0_8_ =
           (long)(int)uVar92 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) + (long)(int)uVar107 * (long)iVar67;
      auVar82._8_8_ =
           (long)(int)((ulong)uVar92 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) +
           (long)iVar105 * (long)iVar67;
      auVar102._0_8_ =
           (long)(int)uVar93 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x604)) +
           (long)(int)uVar70 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x600));
      auVar102._8_8_ =
           (long)(int)((ulong)uVar93 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x604)) +
           (long)iVar131 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x600));
      uVar70 = NEON_rshrn(auVar82._0_8_,auVar82,0x1f,8);
      uVar92 = NEON_rshrn(auVar102._0_8_,auVar102,0x1f,8);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      iVar136 = (int)((ulong)uVar92 >> 0x20);
      iVar67 = (int)uVar92 + (int)uVar70;
      iVar130 = iVar136 + iVar105;
      auVar120._0_8_ = (long)((int)uVar70 - (int)uVar92) * -0x6ed9eba1;
      auVar120._8_8_ = (long)(iVar105 - iVar136) * -0x6ed9eba1;
      uVar70 = NEON_rshrn(uVar92,auVar120,0x1f,8);
      auVar29._8_8_ = (long)(int)((ulong)puVar60[2] >> 0x20) * 0x2aaaaaab;
      auVar29._0_8_ = (long)(int)puVar60[2] * 0x2aaaaaab;
      uVar92 = NEON_rshrn(auVar120._0_8_,auVar29,0x1f,8);
      iVar105 = (int)((ulong)uVar92 >> 0x20);
      iVar136 = (int)uVar92 - (iVar67 >> 1);
      iVar137 = iVar105 - (iVar130 >> 1);
      uVar70 = NEON_rev64(CONCAT44((int)((ulong)uVar70 >> 0x20) * iVar66,(int)uVar70 * iVar64),4);
      puVar60[2] = CONCAT44(iVar130 + iVar105,iVar67 + (int)uVar92);
      iVar67 = (int)((ulong)uVar70 >> 0x20);
      uVar92 = CONCAT44(iVar67 + iVar137,(int)uVar70 + iVar136);
      puVar60[5] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar70);
      puVar60[8] = uVar92;
    } while ((int)lVar55 != 0xdc8);
    iVar67 = 0;
    puVar60 = param_3;
    do {
      lVar55 = 0;
      piVar63 = *(ssc_i32_u **)(param_1 + 4);
      auVar83._0_8_ = (long)(int)puVar60[0x12] * 0x2aaaaaab;
      auVar83._8_8_ = (long)(int)((ulong)puVar60[0x12] >> 0x20) * 0x2aaaaaab;
      auVar6._8_8_ = (long)(int)((ulong)puVar60[9] >> 0x20) * 0x2aaaaaab;
      auVar6._0_8_ = (long)(int)puVar60[9] * 0x2aaaaaab;
      uVar70 = NEON_rshrn(uVar92,auVar6,0x1f,8);
      uVar71 = NEON_rshrn(auVar83._0_8_,auVar83,0x1f,8);
      iVar130 = (int)((ulong)uVar71 >> 0x20);
      iVar137 = (int)((ulong)uVar70 >> 0x20);
      iVar105 = (int)uVar71 + (int)uVar70;
      iVar136 = iVar130 + iVar137;
      auVar121._0_8_ = (long)((int)uVar70 - (int)uVar71) * -0x6ed9eba1;
      auVar121._8_8_ = (long)(iVar137 - iVar130) * -0x6ed9eba1;
      uVar71 = NEON_rshrn(uVar70,auVar121,0x1f,8);
      auVar30._8_8_ = (long)(int)((ulong)*puVar60 >> 0x20) * 0x2aaaaaab;
      auVar30._0_8_ = (long)(int)*puVar60 * 0x2aaaaaab;
      uVar70 = NEON_rshrn(auVar121._0_8_,auVar30,0x1f,8);
      iVar130 = (int)((ulong)uVar70 >> 0x20);
      iVar137 = (int)uVar70 - (iVar105 >> 1);
      iVar131 = iVar130 - (iVar136 >> 1);
      uVar71 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
      *puVar60 = CONCAT44(iVar136 + iVar130,iVar105 + (int)uVar70);
      iVar105 = (int)((ulong)uVar71 >> 0x20);
      puVar60[9] = CONCAT44(iVar131 - iVar105,iVar137 - (int)uVar71);
      puVar60[0x12] = CONCAT44(iVar105 + iVar131,(int)uVar71 + iVar137);
      puVar61 = puVar60 + 0x13;
      piVar58 = piVar63;
      do {
        piVar59 = (ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((piVar63)) + lVar55 + 0x80));
        lVar55 = lVar55 + 0x80;
        iVar105 = piVar58[0x40];
        auVar84._0_8_ = (long)(int)puVar61[-9] * 0x2aaaaaab;
        auVar84._8_8_ = (long)(int)((ulong)puVar61[-9] >> 0x20) * 0x2aaaaaab;
        auVar103._0_8_ = (long)(int)*puVar61 * 0x2aaaaaab;
        auVar103._8_8_ = (long)(int)((ulong)*puVar61 >> 0x20) * 0x2aaaaaab;
        iVar130 = *piVar59;
        iVar136 = piVar59[1];
        uVar70 = NEON_rshrn(auVar84._0_8_,auVar84,0x1f,8);
        uVar92 = NEON_rshrn(auVar103._0_8_,auVar103,0x1f,8);
        iVar137 = (int)((ulong)uVar70 >> 0x20);
        iVar131 = (int)((ulong)uVar92 >> 0x20);
        uVar93 = NEON_rev64(CONCAT44(iVar137 * iVar68,(int)uVar70 * iVar65),4);
        uVar71 = NEON_rev64(CONCAT44(iVar131 * iVar68,(int)uVar92 * iVar65),4);
        auVar122._0_8_ = (long)(int)uVar93 * (long)iVar136 + (long)(int)uVar70 * (long)iVar130;
        auVar122._8_8_ =
             (long)(int)((ulong)uVar93 >> 0x20) * (long)iVar136 + (long)iVar137 * (long)iVar130;
        uVar70 = NEON_rshrn(uVar70,auVar122,0x1f,8);
        auVar31._8_8_ =
             (long)(int)((ulong)uVar71 >> 0x20) * (long)piVar58[0x41] +
             (long)iVar131 * (long)iVar105;
        auVar31._0_8_ = (long)(int)uVar71 * (long)piVar58[0x41] + (long)(int)uVar92 * (long)iVar105;
        uVar71 = NEON_rshrn(uVar92,auVar31,0x1f,8);
        iVar130 = (int)((ulong)uVar70 >> 0x20);
        iVar137 = (int)((ulong)uVar71 >> 0x20);
        iVar105 = (int)uVar71 + (int)uVar70;
        iVar136 = iVar137 + iVar130;
        auVar123._0_8_ = (long)((int)uVar70 - (int)uVar71) * -0x6ed9eba1;
        auVar123._8_8_ = (long)(iVar130 - iVar137) * -0x6ed9eba1;
        uVar71 = NEON_rshrn(uVar71,auVar123,0x1f,8);
        auVar32._8_8_ = (long)(int)((ulong)puVar61[-0x12] >> 0x20) * 0x2aaaaaab;
        auVar32._0_8_ = (long)(int)puVar61[-0x12] * 0x2aaaaaab;
        uVar70 = NEON_rshrn(auVar123._0_8_,auVar32,0x1f,8);
        iVar130 = (int)((ulong)uVar70 >> 0x20);
        iVar137 = (int)uVar70 - (iVar105 >> 1);
        iVar131 = iVar130 - (iVar136 >> 1);
        uVar71 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
        puVar61[-0x12] = CONCAT44(iVar136 + iVar130,iVar105 + (int)uVar70);
        iVar105 = (int)((ulong)uVar71 >> 0x20);
        uVar92 = CONCAT44(iVar105 + iVar131,(int)uVar71 + iVar137);
        puVar61[-9] = CONCAT44(iVar131 - iVar105,iVar137 - (int)uVar71);
        puVar60 = puVar61 + 1;
        *puVar61 = uVar92;
        puVar61 = puVar60;
        piVar58 = piVar58 + 0x40;
      } while ((int)lVar55 != 0x400);
      iVar67 = iVar67 + 1;
    } while (iVar67 != 0x10);
    piVar58 = *(ssc_i32_u **)(param_1 + 4);
    lVar55 = 0;
    piVar59 = piVar58;
    piVar63 = piVar58;
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55));
      iVar67 = *piVar58;
      piVar51 = piVar58 + 1;
      piVar58 = piVar58 + 8;
      lVar55 = lVar55 + 8;
      iVar105 = *piVar63;
      piVar52 = piVar63 + 1;
      piVar63 = piVar63 + 0x18;
      iVar91 = (int)puVar60[0x36];
      iVar132 = (int)((ulong)puVar60[0x36] >> 0x20);
      iVar136 = (int)puVar60[0x1b];
      iVar137 = (int)((ulong)puVar60[0x1b] >> 0x20);
      iVar130 = *piVar59;
      piVar53 = piVar59 + 1;
      iVar131 = (int)puVar60[0x51];
      iVar69 = (int)((ulong)puVar60[0x51] >> 0x20);
      piVar59 = piVar59 + 0x10;
      uVar70 = NEON_rev64(CONCAT44(iVar137 * iVar68,iVar136 * iVar65),4);
      uVar71 = NEON_rev64(CONCAT44(iVar69 * iVar68,iVar131 * iVar65),4);
      uVar92 = NEON_rev64(CONCAT44(iVar132 * iVar68,iVar91 * iVar65),4);
      auVar124._0_8_ = (long)(int)uVar70 * (long)*piVar51 + (long)iVar136 * (long)iVar67;
      auVar124._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)*piVar51 + (long)iVar137 * (long)iVar67;
      auVar7._8_8_ = 0x100000000;
      auVar7._0_8_ = 0x100000000;
      auVar104 = NEON_sqadd(auVar124,auVar7,8);
      auVar8._8_8_ = 0x100000000;
      auVar8._0_8_ = 0x100000000;
      auVar33._8_8_ =
           (long)(int)((ulong)uVar71 >> 0x20) * (long)*piVar52 + (long)iVar69 * (long)iVar105;
      auVar33._0_8_ = (long)(int)uVar71 * (long)*piVar52 + (long)iVar131 * (long)iVar105;
      auVar125 = NEON_sqadd(auVar33,auVar8,8);
      auVar85._0_8_ = (long)(int)uVar92 * (long)*piVar53 + (long)iVar91 * (long)iVar130;
      auVar85._8_8_ =
           (long)(int)((ulong)uVar92 >> 0x20) * (long)*piVar53 + (long)iVar132 * (long)iVar130;
      auVar9._8_8_ = 0x100000000;
      auVar9._0_8_ = 0x100000000;
      auVar86 = NEON_sqadd(auVar85,auVar9,8);
      iVar130 = auVar104._4_4_ >> 1;
      iVar131 = auVar104._12_4_ >> 1;
      iVar132 = (int)*puVar60 + 2 >> 2;
      iVar134 = (int)((ulong)*puVar60 >> 0x20) + 2 >> 2;
      iVar69 = auVar125._4_4_ >> 1;
      iVar91 = auVar125._12_4_ >> 1;
      iVar136 = iVar69 + iVar130;
      iVar137 = iVar91 + iVar131;
      iVar67 = auVar86._4_4_ >> 1;
      iVar105 = auVar86._12_4_ >> 1;
      iVar133 = iVar132 - iVar67;
      iVar135 = iVar134 - iVar105;
      iVar67 = iVar67 + iVar132;
      iVar105 = iVar105 + iVar134;
      uVar71 = NEON_rev64(CONCAT44((iVar131 - iVar91) * iVar66,(iVar130 - iVar69) * iVar64),4);
      iVar130 = (int)((ulong)uVar71 >> 0x20);
      *puVar60 = CONCAT44(iVar137 + iVar105,iVar136 + iVar67);
      puVar60[0x36] = CONCAT44(iVar105 - iVar137,iVar67 - iVar136);
      puVar60[0x1b] = CONCAT44(iVar130 + iVar135,(int)uVar71 + iVar133);
      puVar60[0x51] = CONCAT44(iVar135 - iVar130,iVar133 - (int)uVar71);
    } while ((int)lVar55 != 0xd8);
    piVar58 = *(ssc_i32_u **)(param_1 + 4);
    lVar55 = 0;
    piVar59 = piVar58;
    piVar63 = piVar58;
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55 + 0x360));
      iVar67 = *piVar58;
      piVar51 = piVar58 + 1;
      piVar58 = piVar58 + 8;
      lVar55 = lVar55 + 8;
      iVar105 = *piVar63;
      piVar52 = piVar63 + 1;
      piVar63 = piVar63 + 0x18;
      iVar91 = (int)puVar60[0x36];
      iVar132 = (int)((ulong)puVar60[0x36] >> 0x20);
      iVar136 = (int)puVar60[0x1b];
      iVar137 = (int)((ulong)puVar60[0x1b] >> 0x20);
      iVar130 = *piVar59;
      piVar53 = piVar59 + 1;
      iVar131 = (int)puVar60[0x51];
      iVar69 = (int)((ulong)puVar60[0x51] >> 0x20);
      piVar59 = piVar59 + 0x10;
      uVar70 = NEON_rev64(CONCAT44(iVar137 * iVar68,iVar136 * iVar65),4);
      uVar71 = NEON_rev64(CONCAT44(iVar69 * iVar68,iVar131 * iVar65),4);
      uVar92 = NEON_rev64(CONCAT44(iVar132 * iVar68,iVar91 * iVar65),4);
      auVar126._0_8_ = (long)(int)uVar70 * (long)*piVar51 + (long)iVar136 * (long)iVar67;
      auVar126._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)*piVar51 + (long)iVar137 * (long)iVar67;
      auVar10._8_8_ = 0x100000000;
      auVar10._0_8_ = 0x100000000;
      auVar104 = NEON_sqadd(auVar126,auVar10,8);
      auVar11._8_8_ = 0x100000000;
      auVar11._0_8_ = 0x100000000;
      auVar34._8_8_ =
           (long)(int)((ulong)uVar71 >> 0x20) * (long)*piVar52 + (long)iVar69 * (long)iVar105;
      auVar34._0_8_ = (long)(int)uVar71 * (long)*piVar52 + (long)iVar131 * (long)iVar105;
      auVar125 = NEON_sqadd(auVar34,auVar11,8);
      auVar87._0_8_ = (long)(int)uVar92 * (long)*piVar53 + (long)iVar91 * (long)iVar130;
      auVar87._8_8_ =
           (long)(int)((ulong)uVar92 >> 0x20) * (long)*piVar53 + (long)iVar132 * (long)iVar130;
      auVar12._8_8_ = 0x100000000;
      auVar12._0_8_ = 0x100000000;
      auVar86 = NEON_sqadd(auVar87,auVar12,8);
      iVar130 = auVar104._4_4_ >> 1;
      iVar131 = auVar104._12_4_ >> 1;
      iVar132 = (int)*puVar60 + 2 >> 2;
      iVar134 = (int)((ulong)*puVar60 >> 0x20) + 2 >> 2;
      iVar69 = auVar125._4_4_ >> 1;
      iVar91 = auVar125._12_4_ >> 1;
      iVar136 = iVar69 + iVar130;
      iVar137 = iVar91 + iVar131;
      iVar67 = auVar86._4_4_ >> 1;
      iVar105 = auVar86._12_4_ >> 1;
      iVar133 = iVar132 - iVar67;
      iVar135 = iVar134 - iVar105;
      iVar67 = iVar67 + iVar132;
      iVar105 = iVar105 + iVar134;
      uVar71 = NEON_rev64(CONCAT44((iVar131 - iVar91) * iVar66,(iVar130 - iVar69) * iVar64),4);
      iVar130 = (int)((ulong)uVar71 >> 0x20);
      *puVar60 = CONCAT44(iVar137 + iVar105,iVar136 + iVar67);
      puVar60[0x36] = CONCAT44(iVar105 - iVar137,iVar67 - iVar136);
      puVar60[0x1b] = CONCAT44(iVar130 + iVar135,(int)uVar71 + iVar133);
      puVar60[0x51] = CONCAT44(iVar135 - iVar130,iVar133 - (int)uVar71);
    } while ((int)lVar55 != 0xd8);
    piVar58 = *(ssc_i32_u **)(param_1 + 4);
    lVar55 = 0;
    piVar59 = piVar58;
    piVar63 = piVar58;
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55 + 0x6c0));
      iVar67 = *piVar58;
      piVar51 = piVar58 + 1;
      piVar58 = piVar58 + 8;
      lVar55 = lVar55 + 8;
      iVar105 = *piVar63;
      piVar52 = piVar63 + 1;
      piVar63 = piVar63 + 0x18;
      iVar91 = (int)puVar60[0x36];
      iVar132 = (int)((ulong)puVar60[0x36] >> 0x20);
      iVar136 = (int)puVar60[0x1b];
      iVar137 = (int)((ulong)puVar60[0x1b] >> 0x20);
      iVar130 = *piVar59;
      piVar53 = piVar59 + 1;
      iVar131 = (int)puVar60[0x51];
      iVar69 = (int)((ulong)puVar60[0x51] >> 0x20);
      piVar59 = piVar59 + 0x10;
      uVar70 = NEON_rev64(CONCAT44(iVar137 * iVar68,iVar136 * iVar65),4);
      uVar71 = NEON_rev64(CONCAT44(iVar69 * iVar68,iVar131 * iVar65),4);
      uVar92 = NEON_rev64(CONCAT44(iVar132 * iVar68,iVar91 * iVar65),4);
      auVar127._0_8_ = (long)(int)uVar70 * (long)*piVar51 + (long)iVar136 * (long)iVar67;
      auVar127._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)*piVar51 + (long)iVar137 * (long)iVar67;
      auVar13._8_8_ = 0x100000000;
      auVar13._0_8_ = 0x100000000;
      auVar104 = NEON_sqadd(auVar127,auVar13,8);
      auVar14._8_8_ = 0x100000000;
      auVar14._0_8_ = 0x100000000;
      auVar35._8_8_ =
           (long)(int)((ulong)uVar71 >> 0x20) * (long)*piVar52 + (long)iVar69 * (long)iVar105;
      auVar35._0_8_ = (long)(int)uVar71 * (long)*piVar52 + (long)iVar131 * (long)iVar105;
      auVar125 = NEON_sqadd(auVar35,auVar14,8);
      auVar88._0_8_ = (long)(int)uVar92 * (long)*piVar53 + (long)iVar91 * (long)iVar130;
      auVar88._8_8_ =
           (long)(int)((ulong)uVar92 >> 0x20) * (long)*piVar53 + (long)iVar132 * (long)iVar130;
      auVar15._8_8_ = 0x100000000;
      auVar15._0_8_ = 0x100000000;
      auVar86 = NEON_sqadd(auVar88,auVar15,8);
      iVar130 = auVar104._4_4_ >> 1;
      iVar131 = auVar104._12_4_ >> 1;
      iVar132 = (int)*puVar60 + 2 >> 2;
      iVar134 = (int)((ulong)*puVar60 >> 0x20) + 2 >> 2;
      iVar69 = auVar125._4_4_ >> 1;
      iVar91 = auVar125._12_4_ >> 1;
      iVar136 = iVar69 + iVar130;
      iVar137 = iVar91 + iVar131;
      iVar67 = auVar86._4_4_ >> 1;
      iVar105 = auVar86._12_4_ >> 1;
      iVar133 = iVar132 - iVar67;
      iVar135 = iVar134 - iVar105;
      iVar67 = iVar67 + iVar132;
      iVar105 = iVar105 + iVar134;
      uVar71 = NEON_rev64(CONCAT44((iVar131 - iVar91) * iVar66,(iVar130 - iVar69) * iVar64),4);
      iVar130 = (int)((ulong)uVar71 >> 0x20);
      *puVar60 = CONCAT44(iVar137 + iVar105,iVar136 + iVar67);
      puVar60[0x36] = CONCAT44(iVar105 - iVar137,iVar67 - iVar136);
      puVar60[0x1b] = CONCAT44(iVar130 + iVar135,(int)uVar71 + iVar133);
      puVar60[0x51] = CONCAT44(iVar135 - iVar130,iVar133 - (int)uVar71);
    } while ((int)lVar55 != 0xd8);
    piVar58 = *(ssc_i32_u **)(param_1 + 4);
    lVar55 = 0;
    piVar59 = piVar58;
    piVar63 = piVar58;
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55 + 0xa20));
      iVar67 = *piVar58;
      piVar51 = piVar58 + 1;
      piVar58 = piVar58 + 8;
      lVar55 = lVar55 + 8;
      iVar105 = *piVar63;
      piVar52 = piVar63 + 1;
      piVar63 = piVar63 + 0x18;
      iVar91 = (int)puVar60[0x36];
      iVar132 = (int)((ulong)puVar60[0x36] >> 0x20);
      iVar136 = (int)puVar60[0x1b];
      iVar137 = (int)((ulong)puVar60[0x1b] >> 0x20);
      iVar130 = *piVar59;
      piVar53 = piVar59 + 1;
      iVar131 = (int)puVar60[0x51];
      iVar69 = (int)((ulong)puVar60[0x51] >> 0x20);
      piVar59 = piVar59 + 0x10;
      uVar70 = NEON_rev64(CONCAT44(iVar137 * iVar68,iVar136 * iVar65),4);
      uVar71 = NEON_rev64(CONCAT44(iVar69 * iVar68,iVar131 * iVar65),4);
      uVar92 = NEON_rev64(CONCAT44(iVar132 * iVar68,iVar91 * iVar65),4);
      auVar128._0_8_ = (long)(int)uVar70 * (long)*piVar51 + (long)iVar136 * (long)iVar67;
      auVar128._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)*piVar51 + (long)iVar137 * (long)iVar67;
      auVar16._8_8_ = 0x100000000;
      auVar16._0_8_ = 0x100000000;
      auVar104 = NEON_sqadd(auVar128,auVar16,8);
      auVar17._8_8_ = 0x100000000;
      auVar17._0_8_ = 0x100000000;
      auVar36._8_8_ =
           (long)(int)((ulong)uVar71 >> 0x20) * (long)*piVar52 + (long)iVar69 * (long)iVar105;
      auVar36._0_8_ = (long)(int)uVar71 * (long)*piVar52 + (long)iVar131 * (long)iVar105;
      auVar125 = NEON_sqadd(auVar36,auVar17,8);
      auVar89._0_8_ = (long)(int)uVar92 * (long)*piVar53 + (long)iVar91 * (long)iVar130;
      auVar89._8_8_ =
           (long)(int)((ulong)uVar92 >> 0x20) * (long)*piVar53 + (long)iVar132 * (long)iVar130;
      auVar18._8_8_ = 0x100000000;
      auVar18._0_8_ = 0x100000000;
      auVar86 = NEON_sqadd(auVar89,auVar18,8);
      iVar130 = auVar104._4_4_ >> 1;
      iVar131 = auVar104._12_4_ >> 1;
      iVar132 = (int)*puVar60 + 2 >> 2;
      iVar134 = (int)((ulong)*puVar60 >> 0x20) + 2 >> 2;
      iVar69 = auVar125._4_4_ >> 1;
      iVar91 = auVar125._12_4_ >> 1;
      iVar136 = iVar69 + iVar130;
      iVar137 = iVar91 + iVar131;
      iVar67 = auVar86._4_4_ >> 1;
      iVar105 = auVar86._12_4_ >> 1;
      iVar133 = iVar132 - iVar67;
      iVar135 = iVar134 - iVar105;
      iVar67 = iVar67 + iVar132;
      iVar105 = iVar105 + iVar134;
      uVar71 = NEON_rev64(CONCAT44((iVar131 - iVar91) * iVar66,(iVar130 - iVar69) * iVar64),4);
      iVar130 = (int)((ulong)uVar71 >> 0x20);
      *puVar60 = CONCAT44(iVar137 + iVar105,iVar136 + iVar67);
      puVar60[0x36] = CONCAT44(iVar105 - iVar137,iVar67 - iVar136);
      puVar60[0x1b] = CONCAT44(iVar130 + iVar135,(int)uVar71 + iVar133);
      puVar60[0x51] = CONCAT44(iVar135 - iVar130,iVar133 - (int)uVar71);
    } while ((int)lVar55 != 0xd8);
    lVar56 = 0;
    lVar57 = 0;
    lVar55 = 0;
    lVar62 = *(ssc_i64_u *)(param_1 + 4);
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55));
      piVar58 = (ssc_i32_u *)(uintptr_t)((lVar62 + lVar55));
      piVar63 = (ssc_i32_u *)(uintptr_t)((lVar62 + lVar56));
      lVar55 = lVar55 + 8;
      lVar56 = lVar56 + 0x18;
      iVar67 = *piVar58;
      iVar105 = piVar58[1];
      piVar58 = (ssc_i32_u *)(uintptr_t)((lVar62 + lVar57));
      iVar69 = (int)puVar60[0x6c];
      iVar91 = (int)((ulong)puVar60[0x6c] >> 0x20);
      lVar57 = lVar57 + 0x10;
      iVar132 = (int)puVar60[0x144];
      iVar133 = (int)((ulong)puVar60[0x144] >> 0x20);
      iVar136 = *piVar63;
      iVar130 = piVar63[1];
      iVar134 = (int)puVar60[0xd8];
      iVar135 = (int)((ulong)puVar60[0xd8] >> 0x20);
      uVar70 = NEON_rev64(CONCAT44(iVar91 * iVar68,iVar69 * iVar65),4);
      iVar137 = *piVar58;
      iVar131 = piVar58[1];
      uVar71 = NEON_rev64(CONCAT44(iVar133 * iVar68,iVar132 * iVar65),4);
      uVar92 = NEON_rev64(CONCAT44(iVar135 * iVar68,iVar134 * iVar65),4);
      auVar129._0_8_ = (long)(int)uVar70 * (long)iVar105 + (long)iVar69 * (long)iVar67;
      auVar129._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)iVar105 + (long)iVar91 * (long)iVar67;
      auVar19._8_8_ = 0x100000000;
      auVar19._0_8_ = 0x100000000;
      auVar104 = NEON_sqadd(auVar129,auVar19,8);
      auVar20._8_8_ = 0x100000000;
      auVar20._0_8_ = 0x100000000;
      auVar37._8_8_ =
           (long)(int)((ulong)uVar71 >> 0x20) * (long)iVar130 + (long)iVar133 * (long)iVar136;
      auVar37._0_8_ = (long)(int)uVar71 * (long)iVar130 + (long)iVar132 * (long)iVar136;
      auVar125 = NEON_sqadd(auVar37,auVar20,8);
      auVar90._0_8_ = (long)(int)uVar92 * (long)iVar131 + (long)iVar134 * (long)iVar137;
      auVar90._8_8_ =
           (long)(int)((ulong)uVar92 >> 0x20) * (long)iVar131 + (long)iVar135 * (long)iVar137;
      auVar21._8_8_ = 0x100000000;
      auVar21._0_8_ = 0x100000000;
      auVar86 = NEON_sqadd(auVar90,auVar21,8);
      iVar130 = auVar104._4_4_ >> 1;
      iVar131 = auVar104._12_4_ >> 1;
      iVar132 = (int)*puVar60 + 2 >> 2;
      iVar134 = (int)((ulong)*puVar60 >> 0x20) + 2 >> 2;
      iVar69 = auVar125._4_4_ >> 1;
      iVar91 = auVar125._12_4_ >> 1;
      iVar136 = iVar69 + iVar130;
      iVar137 = iVar91 + iVar131;
      iVar67 = auVar86._4_4_ >> 1;
      iVar105 = auVar86._12_4_ >> 1;
      iVar133 = iVar132 - iVar67;
      iVar135 = iVar134 - iVar105;
      iVar67 = iVar67 + iVar132;
      iVar105 = iVar105 + iVar134;
      uVar71 = NEON_rev64(CONCAT44((iVar131 - iVar91) * iVar66,(iVar130 - iVar69) * iVar64),4);
      iVar130 = (int)((ulong)uVar71 >> 0x20);
      *puVar60 = CONCAT44(iVar137 + iVar105,iVar136 + iVar67);
      puVar60[0xd8] = CONCAT44(iVar105 - iVar137,iVar67 - iVar136);
      puVar60[0x6c] = CONCAT44(iVar130 + iVar135,(int)uVar71 + iVar133);
      puVar60[0x144] = CONCAT44(iVar135 - iVar130,iVar133 - (int)uVar71);
    } while ((int)lVar55 != 0x360);
  }
  else {
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55));
      lVar55 = lVar55 + 0x18;
      lVar56 = (long)(int)puVar60[1] * 0x2aaaaaab;
      auVar72._0_8_ = (long)(int)puVar60[2] * 0x2aaaaaab;
      auVar72._8_8_ = (long)(int)((ulong)puVar60[2] >> 0x20) * 0x2aaaaaab;
      auVar108._0_8_ = (long)(int)*puVar60 * 0x2aaaaaab;
      auVar108._8_8_ = (long)(int)((ulong)*puVar60 >> 0x20) * 0x2aaaaaab;
      auVar3._8_8_ = (long)(int)((ulong)puVar60[1] >> 0x20) * 0x2aaaaaab;
      auVar3._0_8_ = lVar56;
      uVar71 = NEON_rshrn(lVar56,auVar3,0x1f,8);
      iVar65 = (int)((ulong)uVar71 >> 0x20);
      uVar70 = NEON_rshrn(auVar72._0_8_,auVar72,0x1f,8);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      iVar67 = (int)uVar70 + (int)uVar71;
      iVar68 = iVar105 + iVar65;
      auVar94._0_8_ = (long)((int)uVar71 - (int)uVar70) * -0x6ed9eba1;
      auVar94._8_8_ = (long)(iVar65 - iVar105) * -0x6ed9eba1;
      uVar71 = NEON_rshrn(uVar70,auVar94,0x1f,8);
      uVar70 = NEON_rshrn(auVar94._0_8_,auVar108,0x1f,8);
      iVar65 = (int)((ulong)uVar70 >> 0x20);
      iVar105 = (int)uVar70 - (iVar67 >> 1);
      iVar130 = iVar65 - (iVar68 >> 1);
      uVar71 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
      *puVar60 = CONCAT44(iVar68 + iVar65,iVar67 + (int)uVar70);
      iVar67 = (int)((ulong)uVar71 >> 0x20);
      puVar60[1] = CONCAT44(iVar130 - iVar67,iVar105 - (int)uVar71);
      puVar60[2] = CONCAT44(iVar67 + iVar130,(int)uVar71 + iVar105);
      uVar71 = DAT_00102818;
    } while ((int)lVar55 != 0x1b0);
    lVar55 = 0;
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55));
      lVar57 = *(ssc_i64_u *)(param_1 + 4);
      lVar55 = lVar55 + 0x48;
      auVar73._0_8_ = (long)(int)puVar60[3] * 0x2aaaaaab;
      auVar73._8_8_ = (long)(int)((ulong)puVar60[3] >> 0x20) * 0x2aaaaaab;
      auVar95._0_8_ = (long)(int)puVar60[6] * 0x2aaaaaab;
      auVar95._8_8_ = (long)(int)((ulong)puVar60[6] >> 0x20) * 0x2aaaaaab;
      auVar109._0_8_ = (long)(int)puVar60[7] * 0x2aaaaaab;
      auVar109._8_8_ = (long)(int)((ulong)puVar60[7] >> 0x20) * 0x2aaaaaab;
      uVar70 = NEON_rshrn(auVar73._0_8_,auVar73,0x1f,8);
      uVar92 = NEON_rshrn(auVar95._0_8_,auVar95,0x1f,8);
      uVar106 = NEON_rshrn(auVar109._0_8_,auVar109,0x1f,8);
      iVar65 = (int)((ulong)uVar70 >> 0x20);
      iVar105 = (int)((ulong)uVar92 >> 0x20);
      iVar67 = (int)uVar92 + (int)uVar70;
      iVar68 = iVar105 + iVar65;
      lVar56 = (long)((int)uVar70 - (int)uVar92) * -0x6ed9eba1;
      auVar38._8_8_ = (long)(iVar65 - iVar105) * -0x6ed9eba1;
      auVar38._0_8_ = lVar56;
      uVar92 = NEON_rshrn(uVar92,auVar38,0x1f,8);
      auVar43._8_8_ = (long)(int)((ulong)*puVar60 >> 0x20) * 0x2aaaaaab;
      auVar43._0_8_ = (long)(int)*puVar60 * 0x2aaaaaab;
      uVar70 = NEON_rshrn(lVar56,auVar43,0x1f,8);
      iVar65 = (int)((ulong)uVar70 >> 0x20);
      iVar136 = (int)uVar70 - (iVar67 >> 1);
      iVar137 = iVar65 - (iVar68 >> 1);
      uVar93 = NEON_rev64(CONCAT44((int)((ulong)uVar92 >> 0x20) * iVar66,(int)uVar92 * iVar64),4);
      auVar44._8_8_ = (long)(int)((ulong)puVar60[4] >> 0x20) * 0x2aaaaaab;
      auVar44._0_8_ = (long)(int)puVar60[4] * 0x2aaaaaab;
      uVar92 = NEON_rshrn(uVar70,auVar44,0x1f,8);
      iVar130 = (int)((ulong)uVar92 >> 0x20);
      *puVar60 = CONCAT44(iVar68 + iVar65,iVar67 + (int)uVar70);
      iVar67 = (int)((ulong)uVar93 >> 0x20);
      iVar65 = (int)uVar71;
      iVar68 = (int)((ulong)uVar71 >> 0x20);
      puVar60[3] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar93);
      iVar105 = (int)((ulong)uVar106 >> 0x20);
      puVar60[6] = CONCAT44(iVar67 + iVar137,(int)uVar93 + iVar136);
      uVar70 = NEON_rev64(CONCAT44(iVar130 * iVar68,(int)uVar92 * iVar65),4);
      iVar67 = *(ssc_i32_u *)(uintptr_t)((lVar57 + 0x300));
      uVar93 = NEON_rev64(CONCAT44(iVar105 * iVar68,(int)uVar106 * iVar65),4);
      lVar56 = (long)(int)puVar60[8] * 0x2aaaaaab;
      auVar74._0_8_ =
           (long)(int)uVar70 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x184)) +
           (long)(int)uVar92 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x180));
      auVar74._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x184)) +
           (long)iVar130 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x180));
      auVar96._0_8_ =
           (long)(int)uVar93 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) + (long)(int)uVar106 * (long)iVar67;
      auVar96._8_8_ =
           (long)(int)((ulong)uVar93 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) +
           (long)iVar105 * (long)iVar67;
      uVar92 = NEON_rshrn(auVar74._0_8_,auVar74,0x1f,8);
      auVar45._8_8_ = (long)(int)((ulong)puVar60[8] >> 0x20) * 0x2aaaaaab;
      auVar45._0_8_ = lVar56;
      uVar70 = NEON_rshrn(lVar56,auVar45,0x1f,8);
      iVar131 = (int)((ulong)uVar70 >> 0x20);
      uVar93 = NEON_rshrn(auVar96._0_8_,auVar96,0x1f,8);
      iVar105 = (int)((ulong)uVar92 >> 0x20);
      iVar136 = (int)((ulong)uVar93 >> 0x20);
      iVar67 = (int)uVar93 + (int)uVar92;
      iVar130 = iVar136 + iVar105;
      auVar110._0_8_ = (long)((int)uVar92 - (int)uVar93) * -0x6ed9eba1;
      auVar110._8_8_ = (long)(iVar105 - iVar136) * -0x6ed9eba1;
      uVar92 = NEON_rshrn(uVar93,auVar110,0x1f,8);
      auVar39._8_8_ = (long)(int)((ulong)puVar60[1] >> 0x20) * 0x2aaaaaab;
      auVar39._0_8_ = (long)(int)puVar60[1] * 0x2aaaaaab;
      uVar106 = NEON_rshrn(auVar110._0_8_,auVar39,0x1f,8);
      iVar105 = (int)((ulong)uVar106 >> 0x20);
      iVar136 = (int)uVar106 - (iVar67 >> 1);
      iVar137 = iVar105 - (iVar130 >> 1);
      auVar49._8_8_ = (long)(int)((ulong)puVar60[5] >> 0x20) * 0x2aaaaaab;
      auVar49._0_8_ = (long)(int)puVar60[5] * 0x2aaaaaab;
      uVar107 = NEON_rshrn(uVar106,auVar49,0x1f,8);
      uVar93 = NEON_rev64(CONCAT44((int)((ulong)uVar92 >> 0x20) * iVar66,(int)uVar92 * iVar64),4);
      puVar60[1] = CONCAT44(iVar130 + iVar105,iVar67 + (int)uVar106);
      iVar105 = (int)((ulong)uVar107 >> 0x20);
      iVar67 = (int)((ulong)uVar93 >> 0x20);
      uVar92 = NEON_rev64(CONCAT44(iVar105 * iVar68,(int)uVar107 * iVar65),4);
      puVar60[4] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar93);
      puVar60[7] = CONCAT44(iVar67 + iVar137,(int)uVar93 + iVar136);
      uVar93 = NEON_rev64(CONCAT44(iVar131 * iVar68,(int)uVar70 * iVar65),4);
      iVar67 = *(ssc_i32_u *)(uintptr_t)((lVar57 + 0x300));
      auVar75._0_8_ =
           (long)(int)uVar92 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) + (long)(int)uVar107 * (long)iVar67;
      auVar75._8_8_ =
           (long)(int)((ulong)uVar92 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x304)) +
           (long)iVar105 * (long)iVar67;
      auVar97._0_8_ =
           (long)(int)uVar93 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x604)) +
           (long)(int)uVar70 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x600));
      auVar97._8_8_ =
           (long)(int)((ulong)uVar93 >> 0x20) * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x604)) +
           (long)iVar131 * (long)*(ssc_i32_u *)(uintptr_t)((lVar57 + 0x600));
      uVar70 = NEON_rshrn(auVar75._0_8_,auVar75,0x1f,8);
      uVar92 = NEON_rshrn(auVar97._0_8_,auVar97,0x1f,8);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      iVar136 = (int)((ulong)uVar92 >> 0x20);
      iVar67 = (int)uVar92 + (int)uVar70;
      iVar130 = iVar136 + iVar105;
      auVar111._0_8_ = (long)((int)uVar70 - (int)uVar92) * -0x6ed9eba1;
      auVar111._8_8_ = (long)(iVar105 - iVar136) * -0x6ed9eba1;
      uVar70 = NEON_rshrn(uVar92,auVar111,0x1f,8);
      auVar22._8_8_ = (long)(int)((ulong)puVar60[2] >> 0x20) * 0x2aaaaaab;
      auVar22._0_8_ = (long)(int)puVar60[2] * 0x2aaaaaab;
      uVar92 = NEON_rshrn(auVar111._0_8_,auVar22,0x1f,8);
      iVar105 = (int)((ulong)uVar92 >> 0x20);
      iVar136 = (int)uVar92 - (iVar67 >> 1);
      iVar137 = iVar105 - (iVar130 >> 1);
      uVar70 = NEON_rev64(CONCAT44((int)((ulong)uVar70 >> 0x20) * iVar66,(int)uVar70 * iVar64),4);
      puVar60[2] = CONCAT44(iVar130 + iVar105,iVar67 + (int)uVar92);
      iVar67 = (int)((ulong)uVar70 >> 0x20);
      uVar92 = CONCAT44(iVar67 + iVar137,(int)uVar70 + iVar136);
      puVar60[5] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar70);
      puVar60[8] = uVar92;
    } while ((int)lVar55 != 0x1f8);
    iVar67 = 8;
    piVar58 = *(ssc_i32_u **)(param_1 + 4);
    auVar76._0_8_ = (long)(int)param_3[0x12] * 0x2aaaaaab;
    auVar76._8_8_ = (long)(int)((ulong)param_3[0x12] >> 0x20) * 0x2aaaaaab;
    auVar4._8_8_ = (long)(int)((ulong)param_3[9] >> 0x20) * 0x2aaaaaab;
    auVar4._0_8_ = (long)(int)param_3[9] * 0x2aaaaaab;
    uVar70 = NEON_rshrn(uVar92,auVar4,0x1f,8);
    uVar71 = NEON_rshrn(auVar76._0_8_,auVar76,0x1f,8);
    iVar130 = (int)((ulong)uVar71 >> 0x20);
    iVar137 = (int)((ulong)uVar70 >> 0x20);
    iVar105 = (int)uVar71 + (int)uVar70;
    iVar136 = iVar130 + iVar137;
    auVar112._0_8_ = (long)((int)uVar70 - (int)uVar71) * -0x6ed9eba1;
    auVar112._8_8_ = (long)(iVar137 - iVar130) * -0x6ed9eba1;
    uVar71 = NEON_rshrn(uVar70,auVar112,0x1f,8);
    auVar23._8_8_ = (long)(int)((ulong)*param_3 >> 0x20) * 0x2aaaaaab;
    auVar23._0_8_ = (long)(int)*param_3 * 0x2aaaaaab;
    uVar70 = NEON_rshrn(auVar112._0_8_,auVar23,0x1f,8);
    iVar130 = (int)((ulong)uVar70 >> 0x20);
    iVar137 = (int)uVar70 - (iVar105 >> 1);
    iVar131 = iVar130 - (iVar136 >> 1);
    uVar71 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
    *param_3 = CONCAT44(iVar136 + iVar130,iVar105 + (int)uVar70);
    iVar105 = (int)((ulong)uVar71 >> 0x20);
    param_3[9] = CONCAT44(iVar131 - iVar105,iVar137 - (int)uVar71);
    param_3[0x12] = CONCAT44(iVar105 + iVar131,(int)uVar71 + iVar137);
    puVar60 = param_3;
    piVar63 = piVar58;
    do {
      puVar61 = puVar60;
      puVar60 = puVar61 + 1;
      iVar67 = iVar67 + -1;
      iVar105 = piVar63[0x20];
      auVar98._0_8_ = (long)(int)puVar61[10] * 0x2aaaaaab;
      auVar98._8_8_ = (long)(int)((ulong)puVar61[10] >> 0x20) * 0x2aaaaaab;
      auVar113._0_8_ = (long)(int)puVar61[0x13] * 0x2aaaaaab;
      auVar113._8_8_ = (long)(int)((ulong)puVar61[0x13] >> 0x20) * 0x2aaaaaab;
      iVar130 = piVar58[0x40];
      auVar77._0_8_ = (long)(int)*puVar60 * 0x2aaaaaab;
      auVar77._8_8_ = (long)(int)((ulong)*puVar60 >> 0x20) * 0x2aaaaaab;
      uVar93 = NEON_rshrn(auVar98._0_8_,auVar98,0x1f,8);
      uVar106 = NEON_rshrn(auVar113._0_8_,auVar113,0x1f,8);
      uVar92 = NEON_rshrn(auVar77._0_8_,auVar77,0x1f,8);
      iVar136 = (int)((ulong)uVar93 >> 0x20);
      iVar137 = (int)((ulong)uVar106 >> 0x20);
      uVar71 = NEON_rev64(CONCAT44(iVar136 * iVar68,(int)uVar93 * iVar65),4);
      uVar70 = NEON_rev64(CONCAT44(iVar137 * iVar68,(int)uVar106 * iVar65),4);
      auVar24._8_8_ =
           (long)(int)((ulong)uVar71 >> 0x20) * (long)piVar63[0x21] + (long)iVar136 * (long)iVar105;
      auVar24._0_8_ = (long)(int)uVar71 * (long)piVar63[0x21] + (long)(int)uVar93 * (long)iVar105;
      uVar71 = NEON_rshrn(uVar93,auVar24,0x1f,8);
      auVar40._8_8_ =
           (long)(int)((ulong)uVar70 >> 0x20) * (long)piVar58[0x41] + (long)iVar137 * (long)iVar130;
      auVar40._0_8_ = (long)(int)uVar70 * (long)piVar58[0x41] + (long)(int)uVar106 * (long)iVar130;
      uVar70 = NEON_rshrn(uVar106,auVar40,0x1f,8);
      iVar105 = (int)((ulong)uVar71 >> 0x20);
      iVar137 = (int)((ulong)uVar70 >> 0x20);
      iVar130 = (int)uVar70 + (int)uVar71;
      iVar136 = iVar137 + iVar105;
      auVar25._8_8_ = (long)(iVar105 - iVar137) * -0x6ed9eba1;
      auVar25._0_8_ = (long)((int)uVar71 - (int)uVar70) * -0x6ed9eba1;
      uVar71 = NEON_rshrn(uVar70,auVar25,0x1f,8);
      iVar137 = (int)uVar92 - (iVar130 >> 1);
      iVar105 = (int)((ulong)uVar92 >> 0x20);
      iVar131 = iVar105 - (iVar136 >> 1);
      uVar70 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
      *puVar60 = CONCAT44(iVar136 + iVar105,iVar130 + (int)uVar92);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      uVar71 = CONCAT44(iVar131 - iVar105,iVar137 - (int)uVar70);
      puVar61[10] = uVar71;
      puVar61[0x13] = CONCAT44(iVar105 + iVar131,(int)uVar70 + iVar137);
      piVar58 = piVar58 + 0x40;
      piVar63 = piVar63 + 0x20;
    } while (iVar67 != 0);
    piVar58 = *(ssc_i32_u **)(param_1 + 4);
    auVar78._0_8_ = (long)(int)puVar61[0x26] * 0x2aaaaaab;
    auVar78._8_8_ = (long)(int)((ulong)puVar61[0x26] >> 0x20) * 0x2aaaaaab;
    auVar5._8_8_ = (long)(int)((ulong)puVar61[0x1d] >> 0x20) * 0x2aaaaaab;
    auVar5._0_8_ = (long)(int)puVar61[0x1d] * 0x2aaaaaab;
    uVar70 = NEON_rshrn(uVar71,auVar5,0x1f,8);
    uVar71 = NEON_rshrn(auVar78._0_8_,auVar78,0x1f,8);
    lVar55 = 0xa0;
    iVar105 = (int)((ulong)uVar71 >> 0x20);
    iVar136 = (int)((ulong)uVar70 >> 0x20);
    iVar67 = (int)uVar71 + (int)uVar70;
    iVar130 = iVar105 + iVar136;
    auVar114._0_8_ = (long)((int)uVar70 - (int)uVar71) * -0x6ed9eba1;
    auVar114._8_8_ = (long)(iVar136 - iVar105) * -0x6ed9eba1;
    uVar71 = NEON_rshrn(uVar70,auVar114,0x1f,8);
    auVar26._8_8_ = (long)(int)((ulong)puVar61[0x14] >> 0x20) * 0x2aaaaaab;
    auVar26._0_8_ = (long)(int)puVar61[0x14] * 0x2aaaaaab;
    uVar70 = NEON_rshrn(auVar114._0_8_,auVar26,0x1f,8);
    iVar105 = (int)((ulong)uVar70 >> 0x20);
    iVar136 = (int)uVar70 - (iVar67 >> 1);
    iVar137 = iVar105 - (iVar130 >> 1);
    uVar71 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
    puVar61[0x14] = CONCAT44(iVar130 + iVar105,iVar67 + (int)uVar70);
    iVar67 = (int)((ulong)uVar71 >> 0x20);
    puVar61[0x1d] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar71);
    puVar61[0x26] = CONCAT44(iVar67 + iVar137,(int)uVar71 + iVar136);
    piVar63 = piVar58;
    do {
      puVar61 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar60)) + lVar55));
      iVar67 = piVar63[0x20];
      lVar55 = lVar55 + 8;
      iVar105 = piVar58[0x40];
      auVar79._0_8_ = (long)(int)puVar61[9] * 0x2aaaaaab;
      auVar79._8_8_ = (long)(int)((ulong)puVar61[9] >> 0x20) * 0x2aaaaaab;
      auVar99._0_8_ = (long)(int)puVar61[0x12] * 0x2aaaaaab;
      auVar99._8_8_ = (long)(int)((ulong)puVar61[0x12] >> 0x20) * 0x2aaaaaab;
      uVar70 = NEON_rshrn(auVar79._0_8_,auVar79,0x1f,8);
      uVar92 = NEON_rshrn(auVar99._0_8_,auVar99,0x1f,8);
      iVar130 = (int)((ulong)uVar70 >> 0x20);
      iVar136 = (int)((ulong)uVar92 >> 0x20);
      uVar93 = NEON_rev64(CONCAT44(iVar130 * iVar68,(int)uVar70 * iVar65),4);
      uVar71 = NEON_rev64(CONCAT44(iVar136 * iVar68,(int)uVar92 * iVar65),4);
      auVar115._0_8_ = (long)(int)uVar93 * (long)piVar63[0x21] + (long)(int)uVar70 * (long)iVar67;
      auVar115._8_8_ =
           (long)(int)((ulong)uVar93 >> 0x20) * (long)piVar63[0x21] + (long)iVar130 * (long)iVar67;
      uVar70 = NEON_rshrn(uVar70,auVar115,0x1f,8);
      auVar27._8_8_ =
           (long)(int)((ulong)uVar71 >> 0x20) * (long)piVar58[0x41] + (long)iVar136 * (long)iVar105;
      auVar27._0_8_ = (long)(int)uVar71 * (long)piVar58[0x41] + (long)(int)uVar92 * (long)iVar105;
      uVar71 = NEON_rshrn(uVar92,auVar27,0x1f,8);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      iVar136 = (int)((ulong)uVar71 >> 0x20);
      iVar67 = (int)uVar71 + (int)uVar70;
      iVar130 = iVar136 + iVar105;
      auVar116._0_8_ = (long)((int)uVar70 - (int)uVar71) * -0x6ed9eba1;
      auVar116._8_8_ = (long)(iVar105 - iVar136) * -0x6ed9eba1;
      uVar71 = NEON_rshrn(uVar71,auVar116,0x1f,8);
      auVar28._8_8_ = (long)(int)((ulong)*puVar61 >> 0x20) * 0x2aaaaaab;
      auVar28._0_8_ = (long)(int)*puVar61 * 0x2aaaaaab;
      uVar70 = NEON_rshrn(auVar116._0_8_,auVar28,0x1f,8);
      iVar105 = (int)((ulong)uVar70 >> 0x20);
      iVar136 = (int)uVar70 - (iVar67 >> 1);
      iVar137 = iVar105 - (iVar130 >> 1);
      uVar71 = NEON_rev64(CONCAT44((int)((ulong)uVar71 >> 0x20) * iVar66,(int)uVar71 * iVar64),4);
      *puVar61 = CONCAT44(iVar130 + iVar105,iVar67 + (int)uVar70);
      iVar67 = (int)((ulong)uVar71 >> 0x20);
      puVar61[9] = CONCAT44(iVar137 - iVar67,iVar136 - (int)uVar71);
      puVar61[0x12] = CONCAT44(iVar67 + iVar137,(int)uVar71 + iVar136);
      piVar58 = piVar58 + 0x40;
      piVar63 = piVar63 + 0x20;
    } while ((int)lVar55 != 0xe0);
    lVar55 = 0;
    piVar58 = *(ssc_i32_u **)(param_1 + 4);
    do {
      puVar60 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + lVar55));
      iVar64 = *piVar58;
      piVar63 = piVar58 + 1;
      piVar58 = piVar58 + 0x10;
      lVar55 = lVar55 + 8;
      uVar70 = puVar60[0x1b];
      iVar67 = (int)((ulong)uVar70 >> 0x20);
      uVar71 = NEON_rev64(CONCAT44(iVar67 * iVar68,(int)uVar70 * iVar65),4);
      auVar2._8_8_ = (long)(int)((ulong)uVar71 >> 0x20) * (long)*piVar63 +
                     (long)iVar67 * (long)iVar64;
      auVar2._0_8_ = (long)(int)uVar71 * (long)*piVar63 + (long)(int)uVar70 * (long)iVar64;
      uVar70 = NEON_rshrn(uVar70,auVar2,0x1f,8);
      iVar67 = (int)*puVar60;
      iVar66 = (int)((ulong)*puVar60 >> 0x20);
      iVar64 = (int)((ulong)uVar70 >> 0x20);
      uVar71 = NEON_srshr(CONCAT44(iVar66 - iVar64,iVar67 - (int)uVar70),1,4);
      uVar70 = NEON_srshr(CONCAT44(iVar64 + iVar66,(int)uVar70 + iVar67),1,4);
      puVar60[0x1b] = uVar71;
      *puVar60 = uVar70;
    } while ((int)lVar55 != 0xd8);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_ec_laplace_encode @ 00110d50 */
/* ==================================================================== */

void ssc_ec_laplace_encode(undefined8 param_1,ssc_u32_u *param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;

  uVar3 = *param_2;
  iVar5 = 0;
  if (uVar3 != 0) {
    uVar8 = (0x4000 - param_4) * (0x7fe0 - param_3);
    uVar1 = -uVar3;
    if (-1 < (int)uVar3) {
      uVar1 = uVar3;
    }
    iVar6 = 1;
    uVar7 = uVar8 >> 0xf;
    uVar4 = param_3;
    if ((0x7fff < uVar8) && (1 < (int)uVar1)) {
      iVar6 = 1;
      do {
        iVar6 = iVar6 + 1;
        uVar8 = uVar7 * 2 * param_4;
        uVar4 = uVar4 + uVar7 * 2 + 2;
        uVar7 = uVar8 >> 0xf;
        if (uVar8 < 0x8000) break;
      } while (iVar6 < (int)uVar1);
    }
    if (uVar8 >> 0xf == 0) {
      uVar8 = (int)uVar3 >> 0x1f;
      iVar5 = ((int)((uVar3 >> 0x1f | 0x8000) - uVar4) >> 1) + -1;
      iVar2 = uVar1 - iVar6;
      if (iVar5 <= (int)(uVar1 - iVar6)) {
        iVar2 = iVar5;
      }
      iVar5 = uVar4 + uVar8 + iVar2 * 2 + 1;
      param_3 = (uint)(iVar5 != 0x8000);
      *param_2 = iVar6 + uVar8 + iVar2 ^ uVar8;
    }
    else {
      param_3 = uVar7 + 1;
      iVar5 = 0;
      if (-1 < (int)uVar3) {
        iVar5 = uVar7 + 1;
      }
      iVar5 = iVar5 + uVar4;
    }
  }
  ssc_ec_encode_bin(param_1,iVar5,param_3 + iVar5,0xf);
  return;
}


/* ==================================================================== */
/* Function: _ssc_lpc @ 00110e30 */
/* ==================================================================== */

void _ssc_lpc(ssc_u16_u *param_1,ssc_i32_u *param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;

  iVar5 = *param_2;
  if (iVar5 == 0) {
    iVar8 = 0;
LAB_00110efc:
    iVar7 = 0;
    iVar3 = 0;
  }
  else {
    iVar3 = ssc_frac_div32(param_2[1] & 0xfffffff8,iVar5);
    iVar3 = -iVar3;
    iVar1 = iVar5 >> 10;
    iVar8 = iVar3 >> 3;
    iVar5 = iVar5 - (int)(((ulong)((long)iVar3 * (long)iVar3) >> 0x1f) * (long)iVar5 >> 0x1f);
    if (iVar5 < iVar1) goto LAB_00110efc;
    iVar3 = ssc_frac_div32(((uint)((ulong)((long)param_2[1] * (long)iVar8) >> 0x1c) & 0xfffffff8) +
                           param_2[2] & 0xfffffff8,iVar5);
    iVar3 = -iVar3;
    iVar7 = iVar3 >> 3;
    iVar8 = iVar8 + (int)((ulong)((long)iVar3 * (long)iVar8) >> 0x1f);
    iVar5 = iVar5 - (int)(((ulong)((long)iVar3 * (long)iVar3) >> 0x1f) * (long)iVar5 >> 0x1f);
    if (iVar5 < iVar1) {
      iVar3 = 0;
      uVar6 = 0;
      goto LAB_00110f08;
    }
    iVar4 = ssc_frac_div32(param_2[3] +
                           ((int)((ulong)((long)param_2[1] * (long)iVar7) >> 0x1f) +
                           (int)((ulong)((long)param_2[2] * (long)iVar8) >> 0x1f)) * 8 & 0xfffffff8,
                           iVar5);
    iVar4 = -iVar4;
    iVar3 = iVar4 >> 3;
    lVar2 = (long)iVar8;
    iVar8 = iVar8 + (int)((ulong)((long)iVar4 * (long)iVar7) >> 0x1f);
    iVar7 = iVar7 + (int)((ulong)(iVar4 * lVar2) >> 0x1f);
    iVar5 = iVar5 - (int)(((ulong)((long)iVar4 * (long)iVar4) >> 0x1f) * (long)iVar5 >> 0x1f);
    if (iVar1 <= iVar5)
    {
      iVar5 = ssc_frac_div32(param_2[4] +
                             ((int)((ulong)((long)param_2[2] * (long)iVar7) >> 0x1f) +
                              (int)((ulong)((long)param_2[3] * (long)iVar8) >> 0x1f) +
                             (int)((ulong)((long)param_2[1] * (long)iVar3) >> 0x1f)) * 8 &
                             0xfffffff8, iVar5);
      iVar5 = -iVar5;
      lVar2 = (long)iVar8;
      iVar8 = iVar8 + (int)((ulong)((long)iVar5 * (long)iVar3) >> 0x1f);
      iVar3 = iVar3 + (int)((ulong)(iVar5 * lVar2) >> 0x1f);
      iVar7 = iVar7 + (int)((ulong)((long)iVar5 * (long)iVar7) >> 0x1f);
      uVar6 = (undefined2)((uint)((iVar5 >> 3) + 0x8000) >> 0x10);
      goto LAB_00110f08;
    }
  }
  uVar6 = 0;
LAB_00110f08:
  param_1[3] = uVar6;
  *param_1 = (short)((uint)(iVar8 + 0x8000) >> 0x10);
  param_1[1] = (short)((uint)(iVar7 + 0x8000) >> 0x10);
  param_1[2] = (short)((uint)(iVar3 + 0x8000) >> 0x10);
  return;
}


/* ==================================================================== */
/* Function: _ssc_autocorr @ 00111044 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _ssc_autocorr(undefined *param_1,ssc_u32_u *param_2)

{
  uint uVar1;
  ssc_i16_u *psVar2;
  ssc_u64_u *puVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  vec128_t auVar9;
  vec128_t auVar10;
  undefined *puVar11;
  uint uVar12;
  long lVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar29;
  int iVar30;
  int iVar31;
  vec128_t auVar26;
  vec128_t auVar27;
  vec128_t auVar28;
  vec128_t auVar32;
  vec128_t auVar33;
  vec128_t auVar34;
  vec128_t auVar35;
  vec128_t auVar36;
  vec128_t auVar37;
  vec128_t auVar38;

  puVar11 = PTR_in_shared_0011bd00;
  iVar18 = 0;
  iVar19 = 0;
  iVar20 = 0;
  iVar21 = 0;
  iVar22 = 0;
  iVar23 = 0;
  iVar24 = 0;
  iVar25 = 0;
  lVar13 = 0;
  auVar33 = ZEXT816(0);
  auVar27 = *(vec128_t *)(ssc_image + 0x27e0);
  do {
    psVar2 = (ssc_i16_u *)(param_1 + lVar13);
    lVar13 = lVar13 + 0x40;
    iVar29 = auVar27._4_4_;
    iVar30 = auVar27._8_4_;
    iVar31 = auVar27._12_4_;
    auVar27._0_4_ =
         auVar27._0_4_ + ((uint)((int)*psVar2 * (int)*psVar2) >> 9) +
         ((uint)((int)psVar2[1] * (int)psVar2[1]) >> 9);
    auVar27._4_4_ =
         iVar29 + ((uint)((int)psVar2[2] * (int)psVar2[2]) >> 9) +
         ((uint)((int)psVar2[3] * (int)psVar2[3]) >> 9);
    auVar27._8_4_ =
         iVar30 + ((uint)((int)psVar2[4] * (int)psVar2[4]) >> 9) +
         ((uint)((int)psVar2[5] * (int)psVar2[5]) >> 9);
    auVar27._12_4_ =
         iVar31 + ((uint)((int)psVar2[6] * (int)psVar2[6]) >> 9) +
         ((uint)((int)psVar2[7] * (int)psVar2[7]) >> 9);
    iVar18 = iVar18 + ((uint)((int)psVar2[8] * (int)psVar2[8]) >> 9) +
             ((uint)((int)psVar2[9] * (int)psVar2[9]) >> 9);
    iVar19 = iVar19 + ((uint)((int)psVar2[10] * (int)psVar2[10]) >> 9) +
             ((uint)((int)psVar2[0xb] * (int)psVar2[0xb]) >> 9);
    iVar20 = iVar20 + ((uint)((int)psVar2[0xc] * (int)psVar2[0xc]) >> 9) +
             ((uint)((int)psVar2[0xd] * (int)psVar2[0xd]) >> 9);
    iVar21 = iVar21 + ((uint)((int)psVar2[0xe] * (int)psVar2[0xe]) >> 9) +
             ((uint)((int)psVar2[0xf] * (int)psVar2[0xf]) >> 9);
    iVar29 = auVar33._4_4_;
    iVar30 = auVar33._8_4_;
    iVar31 = auVar33._12_4_;
    auVar33._0_4_ =
         auVar33._0_4_ + ((uint)((int)psVar2[0x18] * (int)psVar2[0x18]) >> 9) +
         ((uint)((int)psVar2[0x19] * (int)psVar2[0x19]) >> 9);
    auVar33._4_4_ =
         iVar29 + ((uint)((int)psVar2[0x1a] * (int)psVar2[0x1a]) >> 9) +
         ((uint)((int)psVar2[0x1b] * (int)psVar2[0x1b]) >> 9);
    auVar33._8_4_ =
         iVar30 + ((uint)((int)psVar2[0x1c] * (int)psVar2[0x1c]) >> 9) +
         ((uint)((int)psVar2[0x1d] * (int)psVar2[0x1d]) >> 9);
    auVar33._12_4_ =
         iVar31 + ((uint)((int)psVar2[0x1e] * (int)psVar2[0x1e]) >> 9) +
         ((uint)((int)psVar2[0x1f] * (int)psVar2[0x1f]) >> 9);
    iVar22 = iVar22 + ((uint)((int)psVar2[0x10] * (int)psVar2[0x10]) >> 9) +
             ((uint)((int)psVar2[0x11] * (int)psVar2[0x11]) >> 9);
    iVar23 = iVar23 + ((uint)((int)psVar2[0x12] * (int)psVar2[0x12]) >> 9) +
             ((uint)((int)psVar2[0x13] * (int)psVar2[0x13]) >> 9);
    iVar24 = iVar24 + ((uint)((int)psVar2[0x14] * (int)psVar2[0x14]) >> 9) +
             ((uint)((int)psVar2[0x15] * (int)psVar2[0x15]) >> 9);
    iVar25 = iVar25 + ((uint)((int)psVar2[0x16] * (int)psVar2[0x16]) >> 9) +
             ((uint)((int)psVar2[0x17] * (int)psVar2[0x17]) >> 9);
  } while (lVar13 != 0x740);
  uVar17 = iVar22 + auVar27._0_4_ + auVar33._0_4_ + iVar18 +
           iVar23 + auVar27._4_4_ + auVar33._4_4_ + iVar19 +
           iVar24 + auVar27._8_4_ + auVar33._8_4_ + iVar20 +
           iVar25 + auVar27._12_4_ + auVar33._12_4_ + iVar21 +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x740) * (int)*(ssc_i16_u *)(param_1 + 0x740)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x742) * (int)*(ssc_i16_u *)(param_1 + 0x742)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x744) * (int)*(ssc_i16_u *)(param_1 + 0x744)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x746) * (int)*(ssc_i16_u *)(param_1 + 0x746)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x748) * (int)*(ssc_i16_u *)(param_1 + 0x748)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x74a) * (int)*(ssc_i16_u *)(param_1 + 0x74a)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x74c) * (int)*(ssc_i16_u *)(param_1 + 0x74c)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x74e) * (int)*(ssc_i16_u *)(param_1 + 0x74e)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x750) * (int)*(ssc_i16_u *)(param_1 + 0x750)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x752) * (int)*(ssc_i16_u *)(param_1 + 0x752)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x754) * (int)*(ssc_i16_u *)(param_1 + 0x754)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x756) * (int)*(ssc_i16_u *)(param_1 + 0x756)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x758) * (int)*(ssc_i16_u *)(param_1 + 0x758)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x75a) * (int)*(ssc_i16_u *)(param_1 + 0x75a)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x75c) * (int)*(ssc_i16_u *)(param_1 + 0x75c)) >> 9) +
           ((uint)((int)*(ssc_i16_u *)(param_1 + 0x75e) * (int)*(ssc_i16_u *)(param_1 + 0x75e)) >> 9);
  if (uVar17 < 0x400000) {
    uVar17 = 0;
  }
  else {
    uVar17 = 0xb - (int)LZCOUNT(uVar17);
    uVar15 = (int)uVar17 >> 1;
    iVar18 = (1 << (ulong)(uVar15 & 0x1f)) >> 1;
    if ((PTR_in_shared_0011bd00 < param_1 + 0x760) && (param_1 < PTR_in_shared_0011bd00 + 0x760)) {
      lVar13 = 0;
      do {
        *(ssc_i16_u *)(puVar11 + lVar13) =
             (short)(iVar18 + *(ssc_i16_u *)(param_1 + lVar13) >> (uVar15 & 0x1f));
        lVar13 = lVar13 + 2;
      } while (lVar13 != 0x760);
    }
    else {
      lVar13 = 0;
      iVar19 = -uVar15;
      iVar20 = -uVar15;
      iVar21 = -uVar15;
      iVar22 = -uVar15;
      do {
        psVar2 = (ssc_i16_u *)(param_1 + lVar13);
        puVar3 = (ssc_u64_u *)(puVar11 + lVar13);
        lVar13 = lVar13 + 0x20;
        auVar35._0_4_ = iVar18 + psVar2[4];
        auVar35._4_4_ = iVar18 + psVar2[5];
        auVar35._8_4_ = iVar18 + psVar2[6];
        auVar35._12_4_ = iVar18 + psVar2[7];
        auVar26._0_4_ = iVar18 + *psVar2;
        auVar26._4_4_ = iVar18 + psVar2[1];
        auVar26._8_4_ = iVar18 + psVar2[2];
        auVar26._12_4_ = iVar18 + psVar2[3];
        auVar37._0_4_ = iVar18 + psVar2[0xc];
        auVar37._4_4_ = iVar18 + psVar2[0xd];
        auVar37._8_4_ = iVar18 + psVar2[0xe];
        auVar37._12_4_ = iVar18 + psVar2[0xf];
        auVar32._0_4_ = iVar18 + psVar2[8];
        auVar32._4_4_ = iVar18 + psVar2[9];
        auVar32._8_4_ = iVar18 + psVar2[10];
        auVar32._12_4_ = iVar18 + psVar2[0xb];
        auVar36._4_4_ = iVar20;
        auVar36._0_4_ = iVar19;
        auVar36._8_4_ = iVar21;
        auVar36._12_4_ = iVar22;
        auVar36 = NEON_sshl(auVar35,auVar36,4);
        auVar38._4_4_ = iVar20;
        auVar38._0_4_ = iVar19;
        auVar38._8_4_ = iVar21;
        auVar38._12_4_ = iVar22;
        auVar27 = NEON_sshl(auVar26,auVar38,4);
        auVar9._4_4_ = iVar20;
        auVar9._0_4_ = iVar19;
        auVar9._8_4_ = iVar21;
        auVar9._12_4_ = iVar22;
        auVar38 = NEON_sshl(auVar37,auVar9,4);
        auVar10._4_4_ = iVar20;
        auVar10._0_4_ = iVar19;
        auVar10._8_4_ = iVar21;
        auVar10._12_4_ = iVar22;
        auVar33 = NEON_sshl(auVar32,auVar10,4);
        auVar28._0_8_ =
             CONCAT26(auVar27._12_2_,CONCAT24(auVar27._8_2_,CONCAT22(auVar27._4_2_,auVar27._0_2_)));
        auVar28._8_2_ = auVar36._0_2_;
        auVar28._10_2_ = auVar36._4_2_;
        auVar28._12_2_ = auVar36._8_2_;
        auVar28._14_2_ = auVar36._12_2_;
        auVar34._0_8_ =
             CONCAT26(auVar33._12_2_,CONCAT24(auVar33._8_2_,CONCAT22(auVar33._4_2_,auVar33._0_2_)));
        auVar34._8_2_ = auVar38._0_2_;
        auVar34._10_2_ = auVar38._4_2_;
        auVar34._12_2_ = auVar38._8_2_;
        auVar34._14_2_ = auVar38._12_2_;
        puVar3[1] = auVar28._8_8_;
        *puVar3 = auVar28._0_8_;
        puVar3[3] = auVar34._8_8_;
        puVar3[2] = auVar34._0_8_;
      } while (lVar13 != 0x760);
    }
    uVar17 = uVar17 & 0xfffffffe;
    param_1 = PTR_in_shared_0011bd00;
  }
  ssc_pitch_xcorr_c1((int64_t)(uintptr_t)(param_1),(undefined1 (*)[16])(param_1),(ssc_u64_u *)(param_2));
  sVar4 = *(ssc_i16_u *)(param_1 + 0x758);
  sVar5 = *(ssc_i16_u *)(param_1 + 0x75a);
  sVar6 = *(ssc_i16_u *)(param_1 + 0x75c);
  sVar7 = *(ssc_i16_u *)(param_1 + 0x75e);
  iVar18 = (int)sVar4;
  iVar19 = (int)sVar6;
  iVar20 = (int)sVar7;
  uVar15 = (int)sVar4 * (int)sVar4 + (int)sVar5 * (int)sVar5 + iVar19 * iVar19 + *param_2 +
           iVar20 * iVar20;
  uVar1 = (int)sVar7 * (int)sVar6 + (sVar6 + iVar18) * (int)sVar5 + param_2[1];
  uVar12 = param_2[3] + iVar20 * iVar18;
  uVar14 = iVar19 * iVar18 + (int)sVar7 * (int)sVar5 + param_2[2];
  *param_2 = uVar15;
  param_2[1] = uVar1;
  param_2[2] = uVar14;
  param_2[3] = uVar12;
  if ((int)uVar17 < 1) {
    uVar15 = uVar15 + 1;
    *param_2 = uVar15;
  }
  if ((int)uVar15 < 0x10000000) {
    uVar8 = (int)LZCOUNT(uVar15) - 3;
    uVar16 = -uVar8;
    uVar14 = uVar14 << (ulong)(uVar8 & 0x1f);
    uVar12 = uVar12 << (ulong)(uVar8 & 0x1f);
    *param_2 = uVar15 << (ulong)(uVar8 & 0x1f);
    param_2[1] = uVar1 << (ulong)(uVar8 & 0x1f);
    uVar15 = param_2[4] << (ulong)(uVar8 & 0x1f);
  }
  else {
    if (uVar15 >> 0x1d == 0) {
      return uVar17;
    }
    uVar16 = 1;
    if (uVar15 >> 0x1e != 0) {
      uVar16 = 2;
    }
    uVar14 = (int)uVar14 >> uVar16;
    uVar12 = (int)uVar12 >> uVar16;
    *param_2 = uVar15 >> (ulong)uVar16;
    param_2[1] = (int)uVar1 >> uVar16;
    uVar15 = (int)param_2[4] >> uVar16;
  }
  param_2[2] = uVar14;
  param_2[3] = uVar12;
  param_2[4] = uVar15;
  return uVar17 + uVar16;
}


/* ==================================================================== */
/* Function: ssc_frac_div32 @ 00111370 */
/* ==================================================================== */

int ssc_frac_div32(int param_1,uint param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  bool bVar9;
  int iVar10;

  uVar5 = (int)LZCOUNT(param_2) - 2;
  uVar6 = 2 - (int)LZCOUNT(param_2);
  bVar9 = param_2 >> 0x1e == 0;
  iVar3 = (int)param_2 >> (uVar6 & 0x1f);
  if (bVar9) {
    iVar3 = param_2 << (ulong)(uVar5 & 0x1f);
  }
  iVar1 = iVar3 + 0x8000 >> 0x10;
  uVar6 = param_1 >> (uVar6 & 0x1f);
  if (bVar9) {
    uVar6 = param_1 << (ulong)(uVar5 & 0x1f);
  }
  iVar10 = (int)LZCOUNT(iVar1);
  sVar2 = (short)(iVar1 >> (0x10U - iVar10 & 0x1f));
  if (-0x8001 < iVar3) {
    sVar2 = (short)(iVar1 << (ulong)(iVar10 - 0x10U & 0x1f));
  }
  uVar5 = (int)sVar2 ^ 0xffff8000;
  iVar4 = uVar5 * -0x7878 + 0x78780000;
  iVar1 = iVar4 >> 0x10;
  uVar7 = iVar1 - ((uint)((short)(((ushort)((uint)iVar4 >> 0x10) ^ 0x8000) +
                                 (short)(iVar1 * uVar5 >> 0xf)) * iVar1) >> 0xf);
  uVar8 = (ushort)uVar7;
  iVar4 = (int)(short)(uVar8 - (short)((int)(short)((uVar8 ^ 0x8000) +
                                                   (short)((int)(short)uVar8 * uVar5 >> 0xf)) *
                                       (-(uVar7 >> 0xf & 1) & 0xfffe0000 | (uVar7 & 0xffff) << 1) +
                                       0x10000 >> 0x10));
  iVar1 = iVar4 << (ulong)(iVar10 - 0xfU & 0x1f);
  if (iVar3 < -0x8000) {
    iVar1 = iVar4 >> (0xfU - iVar10 & 0x1f);
  }
  iVar10 = iVar1 * 0x2000 + 0x8000 >> 0x10;
  iVar1 = ((int)uVar6 >> 0xf & 0xfffffffeU) * iVar10 + ((int)(iVar10 * (uVar6 & 0xffff)) >> 0xf);
  uVar5 = ((int)(uVar6 + 2) >> 2) - (int)((ulong)((long)iVar1 * (long)iVar3) >> 0x1f);
  iVar1 = iVar1 + (((int)((uVar5 & 0xffff) * iVar10) >> 0xf) + iVar10 * ((int)uVar5 >> 0x10) * 2) *
                  4;
  iVar3 = -0x7fffffff;
  if (-0x20000000 < iVar1) {
    iVar3 = iVar1 * 4;
  }
  iVar10 = 0x7fffffff;
  if (iVar1 < 0x20000000) {
    iVar10 = iVar3;
  }
  return iVar10;
}


/* ==================================================================== */
/* Function: ssc_rcp @ 001114bc */
/* ==================================================================== */

int ssc_rcp(uint param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;

  iVar7 = (int)LZCOUNT(param_1);
  sVar2 = (short)((int)param_1 >> (0x10U - iVar7 & 0x1f));
  if (param_1 >> 0x10 == 0) {
    sVar2 = (short)(param_1 << (ulong)(iVar7 - 0x10U & 0x1f));
  }
  uVar3 = (int)sVar2 ^ 0xffff8000;
  iVar4 = uVar3 * -0x7878 + 0x78780000;
  iVar1 = iVar4 >> 0x10;
  uVar5 = iVar1 - ((uint)((short)(((ushort)((uint)iVar4 >> 0x10) ^ 0x8000) +
                                 (short)(iVar1 * uVar3 >> 0xf)) * iVar1) >> 0xf);
  uVar6 = (ushort)uVar5;
  iVar4 = (int)(short)(uVar6 - (short)((-(uVar5 >> 0xf & 1) & 0xfffe0000 | (uVar5 & 0xffff) << 1) *
                                       (int)(short)((uVar6 ^ 0x8000) +
                                                   (short)((int)(short)uVar6 * uVar3 >> 0xf)) +
                                       0x10000 >> 0x10));
  iVar1 = iVar4 << (ulong)(iVar7 - 0xfU & 0x1f);
  if (0x1ffff < param_1) {
    iVar1 = iVar4 >> (0xfU - iVar7 & 0x1f);
  }
  return iVar1;
}


/* ==================================================================== */
/* Function: ssc_rsqrt_norm @ 00111558 */
/* ==================================================================== */

int ssc_rsqrt_norm(short param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;

  uVar2 = (int)param_1 ^ 0xffff8000;
  iVar1 = (int)(uVar2 * (((int)(uVar2 * 0x1a39) >> 0xf) + -0x34b2) * 2 + 0x5c050000) >> 0x10;
  iVar3 = iVar1 * iVar1 * 2;
  iVar3 = (int)(short)(((short)((uint)iVar3 >> 0x10) + (short)((iVar3 >> 0x10) * uVar2 >> 0xf)) * 2
                      ^ 0x8000);
  return iVar1 + ((uint)(((iVar3 * 0x6000 + -0x40000000 >> 0x10) * iVar3 >> 0xf) * iVar1) >> 0xf);
}


/* ==================================================================== */
/* Function: ssc_sqrt @ 001115c0 */
/* ==================================================================== */

ulong ssc_sqrt(ulong param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;

  uVar5 = (uint)param_1;
  if (uVar5 != 0) {
    if (0x3fffffff < (int)uVar5) {
      return 0x7fff;
    }
    uVar1 = (uint)LZCOUNT(uVar5) & 0x1e;
    uVar4 = (uint)LZCOUNT(uVar5) >> 1;
    sVar3 = (short)((int)uVar5 >> (0x10 - uVar1 & 0x1f));
    if (uVar5 >> 0x10 == 0) {
      sVar3 = (short)(uVar5 << (ulong)(uVar1 - 0x10 & 0x1f));
    }
    uVar1 = (int)sVar3 ^ 0xffff8000;
    iVar2 = (int)(uVar1 * 2 *
                  ((((int)(uVar1 * 2 * ((uVar1 * -0x298 >> 0xf) + 0x6a3 & 0xffff) + -0xbc30000) >>
                    0x10) * uVar1 >> 0xf) + 0x2d29 & 0xffff) + 0x5a870000) >> 0x10;
    uVar1 = iVar2 >> (uVar4 - 1 & 0x1f);
    if (uVar5 >> 0x1c != 0) {
      uVar1 = iVar2 << (ulong)(1 - uVar4 & 0x1f);
    }
    param_1 = (ulong)uVar1;
  }
  return param_1;
}


/* ==================================================================== */
/* Function: ssc_cos_norm @ 00111670 */
/* ==================================================================== */

uint ssc_cos_norm(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;

  param_1 = param_1 & 0x1ffff;
  uVar3 = 0x20000 - param_1;
  if (param_1 < 0x10001) {
    uVar3 = param_1;
  }
  if ((uVar3 & 0x7fff) != 0) {
    if (uVar3 >> 0xf == 0) {
      uVar3 = uVar3 * uVar3 * 2 + 0x8000 >> 0x10;
      iVar1 = (uVar3 ^ 0x7fff) +
              ((int)(((int)(uVar3 * (((int)(uVar3 * -0x272 + 0x4000) >> 0xf) + 0x2055) * 2 +
                           -0x1de28000) >> 0x10) * uVar3 + 0x4000) >> 0xf);
      uVar3 = 0x7fff;
      if (iVar1 < 0x7fff) {
        uVar3 = iVar1 + 1;
      }
      return uVar3;
    }
    iVar1 = ((int)(uVar3 * -0x10000) >> 0xf) * ((int)(uVar3 * -0x10000) >> 0x10) + 0x8000 >> 0x10;
    uVar3 = (((iVar1 * ((iVar1 * -0x272 + 0x4000 >> 0xf) + 0x2055) * 2 + -0x1de28000 >> 0x10) *
              iVar1 + 0x4000 >> 0xf) - iVar1) + 0x7fff;
    uVar4 = 0xffff8001;
    if ((int)uVar3 < 0x7fff) {
      uVar4 = ~uVar3;
    }
    return uVar4;
  }
  uVar4 = 0xffff8001;
  if ((uVar3 & 0x1ffff) == 0) {
    uVar4 = 0x7fff;
  }
  uVar2 = 0;
  if ((uVar3 & 0xffff) == 0) {
    uVar2 = uVar4;
  }
  return uVar2;
}


/* ==================================================================== */
/* Function: ssc_mdct_forward @ 0011176c */
/* ==================================================================== */

void ssc_mdct_forward(ssc_i32_u *param_1,long param_2,ssc_u32_u *param_3,uint param_4,uint param_5,
                     uint param_6)

{
  ssc_i32_u *piVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  vec128_t auVar5;
  vec128_t auVar6;
  vec128_t auVar7;
  vec128_t auVar8;
  int iVar9;
  undefined8 uVar10;
  undefined *puVar11;
  ssc_i32_u *piVar12;
  undefined *puVar13;
  long lVar14;
  ssc_u32_u *puVar15;
  long lVar16;
  ssc_i32_u *piVar17;
  ssc_i32_u *piVar18;
  ssc_u64_u *puVar19;
  ulong uVar20;
  long lVar21;
  ssc_i32_u *piVar22;
  int iVar23;
  ssc_i32_u *piVar24;
  int iVar25;
  long lVar26;
  undefined8 uVar27;
  int iVar29;
  undefined8 uVar28;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  undefined8 uVar34;

  puVar11 = PTR__pre_shared_0011bce0;
  uVar2 = *param_1 >> (param_5 & 0x1f);
  lVar16 = param_2 + (long)((int)uVar2 >> 1) * 4;
  iVar3 = 0xee4bb;
  iVar9 = 0x7fffff22;
  if (param_5 != 0) {
    iVar3 = 0x7725c6;
    iVar9 = 0x7fffc88c;
  }
  iVar29 = (int)(param_4 + 3) >> 2;
  iVar25 = (int)uVar2 >> 2;
  lVar21 = lVar16 + -4;
  puVar15 = (ssc_u32_u *)(void *)&DAT_00103d80;
  if ((int)param_4 < 1) {
    iVar23 = 0;
    uVar20 = -(ulong)((uint)((int)param_4 >> 1) >> 0x1f) & 0xfffffffc00000000 |
             (ulong)(uint)((int)param_4 >> 1) << 2;
    piVar17 = (ssc_i32_u *)(uintptr_t)((param_2 + uVar20));
    piVar22 = (ssc_i32_u *)(uintptr_t)((lVar21 + uVar20));
    piVar18 = (ssc_i32_u *)PTR__pre_shared_0011bce0;
  }
  else {
    iVar23 = iVar29;
    if (iVar29 < 2) {
      iVar23 = 1;
    }
    lVar4 = (long)((ulong)param_4 << 0x20) >> 0x21;
    puVar13 = &DAT_00103d7c;
    lVar14 = param_2 + -4;
    piVar17 = (ssc_i32_u *)PTR__pre_shared_0011bce0;
    iVar31 = iVar23;
    do {
      lVar26 = lVar4 * 4;
      iVar31 = iVar31 + -1;
      piVar18 = (ssc_i32_u *)(uintptr_t)((lVar21 + lVar26));
      lVar21 = lVar21 + -8;
      iVar33 = puVar15[lVar4];
      puVar15 = puVar15 + 2;
      piVar22 = (ssc_i32_u *)(uintptr_t)((lVar16 + lVar26));
      lVar16 = lVar16 + 8;
      iVar30 = *(ssc_i32_u *)(puVar13 + lVar26);
      puVar13 = puVar13 + -8;
      *piVar17 = (int)((long)iVar33 * (long)*piVar18 + (long)iVar30 * (long)*piVar22 + 0x40000000U
                      >> 0x1f);
      piVar22 = (ssc_i32_u *)(uintptr_t)((lVar14 + lVar26));
      lVar14 = lVar14 + -8;
      piVar12 = (ssc_i32_u *)(uintptr_t)((param_2 + lVar26));
      param_2 = param_2 + 8;
      piVar18 = piVar17 + 2;
      piVar17[1] = (int)(((long)*piVar12 * (long)iVar33 - (long)*piVar22 * (long)iVar30) +
                         0x40000000U >> 0x1f);
      piVar17 = piVar18;
    } while (iVar31 != 0);
    piVar17 = (ssc_i32_u *)(uintptr_t)((param_2 + lVar26));
    piVar22 = (ssc_i32_u *)(uintptr_t)((lVar21 + lVar26));
  }
  lVar16 = (long)((ulong)uVar2 << 0x20) >> 0x21;
  iVar31 = iVar23;
  for (; iVar23 < iVar25 - iVar29; iVar23 = iVar23 + 1) {
    *piVar18 = *piVar22;
    piVar18[1] = *piVar17;
    piVar17 = piVar17 + 2;
    piVar18 = piVar18 + 2;
    piVar22 = piVar22 + -2;
    iVar31 = iVar25 - iVar29;
  }
  if (iVar31 < iVar25) {
    iVar31 = iVar25 - iVar31;
    piVar12 = (ssc_i32_u *)(&DAT_00103d80);
    piVar24 = (ssc_i32_u *)(&DAT_00103d7c + (long)(int)param_4 * 4);
    do {
      iVar31 = iVar31 + -1;
      iVar29 = *piVar12;
      iVar23 = *piVar24;
      *piVar18 = (int)(((long)iVar23 * (long)*piVar22 - (long)iVar29 * (long)piVar17[-lVar16]) +
                       0x40000000U >> 0x1f);
      piVar1 = piVar22 + lVar16;
      piVar22 = piVar22 + -2;
      iVar33 = *piVar17;
      piVar17 = piVar17 + 2;
      piVar18[1] = (int)((long)*piVar1 * (long)iVar29 + (long)iVar33 * (long)iVar23 + 0x40000000U >>
                        0x1f);
      piVar18 = piVar18 + 2;
      piVar12 = piVar12 + 2;
      piVar24 = piVar24 + -2;
    } while (iVar31 != 0);
  }
  uVar28 = DAT_00102830;
  uVar10 = DAT_00102818;
  iVar29 = iVar25 << (ulong)(param_5 & 0x1f);
  lVar16 = (long)(1 << (ulong)(param_5 & 0x1f));
  if (3 < (int)uVar2) {
    piVar17 = *(ssc_i32_u **)(param_1 + 6);
    iVar23 = iVar25;
    if (iVar25 < 2) {
      iVar23 = 1;
    }
    piVar18 = piVar17 + iVar29;
    puVar19 = (ssc_u64_u *)PTR__pre_shared_0011bce0;
    do {
      uVar27 = *puVar19;
      iVar23 = iVar23 + -1;
      iVar31 = *piVar17;
      piVar17 = piVar17 + lVar16;
      iVar33 = *piVar18;
      piVar18 = piVar18 + -lVar16;
      uVar34 = NEON_rev64(uVar27,4);
      iVar30 = (int)uVar27 * (int)uVar10;
      iVar32 = (int)((ulong)uVar27 >> 0x20) * (int)((ulong)uVar10 >> 0x20);
      auVar8._8_8_ = (long)(int)((ulong)uVar34 >> 0x20) * (long)iVar33 + (long)iVar32 * (long)iVar31
      ;
      auVar8._0_8_ = (long)(int)uVar34 * (long)iVar33 + (long)iVar30 * (long)iVar31;
      uVar27 = NEON_rshrn(CONCAT44(iVar32,iVar30),auVar8,0x1f,8);
      uVar34 = NEON_rev64(uVar27,4);
      iVar31 = (int)uVar27 * (int)uVar28;
      iVar33 = (int)((ulong)uVar27 >> 0x20) * (int)((ulong)uVar28 >> 0x20);
      auVar6._8_8_ = (long)(int)((ulong)uVar34 >> 0x20) * (long)iVar3 + (long)iVar33 * (long)iVar9;
      auVar6._0_8_ = (long)(int)uVar34 * (long)iVar3 + (long)iVar31 * (long)iVar9;
      uVar27 = NEON_rshrn(CONCAT44(iVar33,iVar31),auVar6,0x1f,8);
      *puVar19 = uVar27;
      puVar19 = puVar19 + 1;
    } while (iVar23 != 0);
  }
  puVar19 = (ssc_u64_u *)(puVar11 + 0xd80);
  ssc_fft((ssc_i32_u *)(uintptr_t)(*(ssc_u64_u *)(param_1 + (long)((int)param_5 >> 1) * 2 + 2)),(ssc_u32_u *)(puVar11),puVar19);
  uVar10 = DAT_00102818;
  piVar18 = *(ssc_i32_u **)(param_1 + 6);
  uVar20 = -(ulong)((param_6 & 0x7fffffff) >> 0x1e) & 0xfffffffc00000000 |
           (ulong)(param_6 << 1) << 2;
  piVar17 = piVar18 + iVar29;
  puVar15 = param_3 + (int)((((int)uVar2 >> 1) + -1) * param_6);
  do {
    uVar27 = *puVar19;
    iVar29 = *piVar18;
    piVar18 = piVar18 + lVar16;
    iVar23 = *piVar17;
    piVar17 = piVar17 + -lVar16;
    uVar28 = NEON_rev64(uVar27,4);
    iVar31 = (int)uVar10;
    iVar30 = (int)uVar27 * iVar31;
    iVar33 = (int)((ulong)uVar10 >> 0x20);
    iVar32 = (int)((ulong)uVar27 >> 0x20) * iVar33;
    iVar25 = iVar25 + -1;
    auVar7._8_8_ = (long)(int)((ulong)uVar28 >> 0x20) * (long)iVar23 + (long)iVar32 * (long)iVar29;
    auVar7._0_8_ = (long)(int)uVar28 * (long)iVar23 + (long)iVar30 * (long)iVar29;
    uVar27 = NEON_rshrn(CONCAT44(iVar32,iVar30),auVar7,0x1f,8);
    iVar29 = (int)((ulong)uVar27 >> 0x20);
    uVar28 = NEON_rev64(CONCAT44(iVar29 * iVar33,(int)uVar27 * iVar31),4);
    auVar5._8_8_ = (long)(int)((ulong)uVar28 >> 0x20) * (long)iVar3 + (long)iVar29 * (long)iVar9;
    auVar5._0_8_ = (long)(int)uVar28 * (long)iVar3 + (long)(int)uVar27 * (long)iVar9;
    uVar28 = NEON_rshrn(uVar27,auVar5,0x1f,8);
    *param_3 = (int)uVar28;
    param_3 = (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_3)) + uVar20));
    *puVar15 = (int)((ulong)uVar28 >> 0x20);
    puVar15 = (ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar15)) - uVar20));
    puVar19 = puVar19 + 1;
  } while (iVar25 != 0);
  return;
}


/* ==================================================================== */
/* Function: ssc_custom_mode_create @ 00111ac8 */
/* ==================================================================== */

undefined * ssc_custom_mode_create(int param_1,undefined8 param_2,ssc_u32_u *param_3)

{
  undefined *puVar1;

  if (param_3 != (ssc_u32_u *)0x0) {
    *param_3 = 0;
  }
  puVar1 = &DAT_0011b9c0;
  if ((param_1 != 0xac44) && (param_1 != 48000)) {
    if (param_1 == 96000) {
      return &DAT_0011ba40;
    }
    if (param_3 == (ssc_u32_u *)0x0) {
      return (undefined *)0x0;
    }
    puVar1 = (undefined *)0x0;
    *param_3 = 0xffffffff;
  }
  return puVar1;
}


/* ==================================================================== */
/* Function: ssc_pitch_downsample @ 00111b2c */
/* ==================================================================== */

void ssc_pitch_downsample(ssc_i32_u *param_1,ssc_i32_u *param_2,ssc_i16_u *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  ssc_i16_u *psVar7;
  long lVar8;
  vec128_t auVar9;
  vec128_t auVar10;
  vec128_t auVar11;
  ssc_i32_u *piVar12;
  ssc_i32_u *piVar13;
  ssc_i32_u *piVar14;
  ssc_i32_u *piVar15;
  ssc_i32_u *piVar16;
  ssc_i32_u *piVar17;
  ssc_i32_u *piVar18;
  bool bVar19;
  ssc_i16_u *psVar20;
  uint uVar21;
  long lVar22;
  ssc_i32_u *piVar23;
  ulong uVar24;
  long lVar25;
  ssc_i32_u *piVar26;
  ulong uVar27;
  int iVar28;
  ulong uVar29;
  int iVar30;
  undefined8 uVar31;
  vec128_t auVar32;
  vec128_t auVar33;
  int iVar35;
  vec128_t auVar34;
  vec128_t auVar36;
  vec128_t auVar37;
  vec128_t auVar38;
  short sVar39;
  vec128_t auVar40;
  vec128_t auVar41;
  vec128_t auVar42;
  short sVar46;
  short sVar47;
  short sVar48;
  vec128_t auVar43;
  vec128_t auVar44;
  vec128_t auVar45;
  vec128_t auVar49;
  vec128_t auVar50;
  undefined8 uVar51;
  undefined8 uVar52;
  undefined8 uVar53;
  undefined8 uVar54;
  undefined8 uVar55;
  short sVar57;
  short sVar58;
  undefined8 uVar56;
  short sVar59;
  short sVar60;
  short sVar61;
  short sVar62;
  short sVar64;
  short sVar65;
  undefined8 uVar63;
  short sVar66;
  undefined8 uVar67;
  undefined8 uVar68;
  undefined8 uVar69;
  short lpc_data[4];
  union { undefined8 d[3]; int i[6]; } ac_data;
  long local_28;

  lVar8 = tpidr_el0;
  local_28 = *(ssc_i64_u *)(uintptr_t)((lVar8 + 0x28));
  uVar21 = 0;
  auVar33 = ZEXT816(0);
  uVar2 = param_4 * 2;
  ac_data.d[0] = 0;
  ac_data.d[1] = 0;
  ac_data.i[4] = 0;
  piVar23 = param_1;
  if (0xf < (int)uVar2) {
    do {
      uVar21 = uVar21 + 0x10;
      auVar32._0_4_ = MP_INT_ABS(*piVar23);
      auVar32._4_4_ = MP_INT_ABS(piVar23[1]);
      auVar32._8_4_ = MP_INT_ABS(piVar23[2]);
      auVar32._12_4_ = MP_INT_ABS(piVar23[3]);
      auVar50._0_4_ = MP_INT_ABS(piVar23[4]);
      auVar50._4_4_ = MP_INT_ABS(piVar23[5]);
      auVar50._8_4_ = MP_INT_ABS(piVar23[6]);
      auVar50._12_4_ = MP_INT_ABS(piVar23[7]);
      auVar32 = NEON_smax(auVar33,auVar32,4);
      piVar26 = piVar23 + 8;
      piVar12 = piVar23 + 9;
      piVar13 = piVar23 + 10;
      piVar14 = piVar23 + 0xb;
      auVar33 = *(vec128_t *)(piVar23 + 0xc);
      piVar23 = piVar23 + 0x10;
      auVar32 = NEON_smax(auVar32,auVar50,4);
      auVar45._0_4_ = MP_INT_ABS(*piVar26);
      auVar45._4_4_ = MP_INT_ABS(*piVar12);
      auVar45._8_4_ = MP_INT_ABS(*piVar13);
      auVar45._12_4_ = MP_INT_ABS(*piVar14);
      auVar40._0_4_ = MP_INT_ABS(auVar33._0_4_);
      auVar40._4_4_ = MP_INT_ABS(auVar33._4_4_);
      auVar40._8_4_ = MP_INT_ABS(auVar33._8_4_);
      auVar40._12_4_ = MP_INT_ABS(auVar33._12_4_);
      auVar33 = NEON_smax(auVar32,auVar45,4);
      auVar33 = NEON_smax(auVar33,auVar40,4);
    } while ((int)uVar21 < (int)(uVar2 - 0xf));
    uVar21 = uVar2 & 0xfffffff0;
  }
  auVar32 = NEON_ext(auVar33,auVar33,8,1);
  uVar31 = NEON_smax(auVar32._0_8_,auVar33._0_8_,4);
  iVar35 = (int)((ulong)uVar31 >> 0x20);
  iVar30 = (int)uVar31;
  if ((int)uVar31 <= iVar35) {
    iVar30 = iVar35;
  }
  if ((int)uVar21 < (int)uVar2) {
    uVar2 = (uVar2 - uVar21) - 2;
    if (5 < uVar2) {
      uVar24 = (ulong)uVar2 + 2;
      auVar33._0_8_ = CONCAT44(iVar30,iVar30);
      auVar33._8_4_ = iVar30;
      auVar33._12_4_ = iVar30;
      uVar29 = uVar24 & 0x1fffffff8;
      auVar36._8_8_ = auVar33._8_8_;
      auVar36._0_8_ = auVar33._0_8_;
      uVar21 = uVar21 + (int)uVar29;
      piVar26 = piVar23 + 4;
      uVar27 = uVar29;
      do {
        piVar12 = piVar26 + -4;
        piVar13 = piVar26 + -3;
        piVar14 = piVar26 + -2;
        piVar15 = piVar26 + -1;
        iVar30 = *piVar26;
        piVar16 = piVar26 + 1;
        piVar17 = piVar26 + 2;
        piVar18 = piVar26 + 3;
        piVar26 = piVar26 + 8;
        uVar27 = uVar27 - 8;
        auVar41._0_4_ = MP_INT_ABS(*piVar12);
        auVar41._4_4_ = MP_INT_ABS(*piVar13);
        auVar41._8_4_ = MP_INT_ABS(*piVar14);
        auVar41._12_4_ = MP_INT_ABS(*piVar15);
        auVar43._0_4_ = MP_INT_ABS(iVar30);
        auVar43._4_4_ = MP_INT_ABS(*piVar16);
        auVar43._8_4_ = MP_INT_ABS(*piVar17);
        auVar43._12_4_ = MP_INT_ABS(*piVar18);
        auVar33 = NEON_smax(auVar33,auVar41,4);
        auVar36 = NEON_smax(auVar36,auVar43,4);
      } while (uVar27 != 0);
      auVar33 = NEON_smax(auVar33,auVar36,4);
      iVar30 = NEON_smaxv(auVar33,4);
      piVar23 = piVar23 + uVar29;
      if (uVar24 == uVar29) goto LAB_00111c60;
    }
    iVar35 = uVar21 + param_4 * -2;
    do {
      iVar1 = *piVar23;
      iVar28 = -iVar1;
      if (-1 < iVar1) {
        iVar28 = iVar1;
      }
      if (iVar30 <= iVar28) {
        iVar30 = iVar28;
      }
      bVar19 = iVar35 != -1;
      iVar35 = iVar35 + 1;
      piVar23 = piVar23 + 1;
    } while (bVar19);
  }
LAB_00111c60:
  if (iVar30 < 2) {
    iVar30 = 1;
  }
  uVar21 = 0x15 - (int)LZCOUNT(iVar30);
  uVar21 = (uVar21 & ((int)uVar21 >> 0x1f ^ 0xffffffffU)) + 1;
  *param_3 = (short)((*param_1 + (param_1[1] >> 1) >> 1) >> (uVar21 & 0x1f)) +
             (short)((*param_2 + (param_2[1] >> 1) >> 1) >> (uVar21 & 0x1f));
  if (3 < (int)param_4) {
    uVar24 = (ulong)(param_4 >> 1) - 1;
    if (uVar24 < 9) {
      lVar25 = 1;
    }
    else {
      uVar27 = 8;
      if ((uVar24 & 7) != 0) {
        uVar27 = uVar24 & 7;
      }
      lVar22 = uVar24 - uVar27;
      auVar34._0_4_ = -uVar21;
      auVar34._4_4_ = -uVar21;
      auVar34._8_4_ = -uVar21;
      auVar34._12_4_ = -uVar21;
      lVar25 = lVar22 + 1;
      piVar23 = param_2 + 2;
      piVar26 = param_1 + 2;
      psVar20 = param_3 + 1;
      do {
        lVar22 = lVar22 + -8;
        auVar37._0_4_ = *piVar26 + (piVar26[1] + piVar26[-1] >> 1) >> 1;
        auVar37._4_4_ = piVar26[2] + (piVar26[3] + piVar26[1] >> 1) >> 1;
        auVar37._8_4_ = piVar26[4] + (piVar26[5] + piVar26[3] >> 1) >> 1;
        auVar37._12_4_ = piVar26[6] + (piVar26[7] + piVar26[5] >> 1) >> 1;
        auVar33 = NEON_sshl(auVar37,auVar34,4);
        auVar42._0_4_ = piVar26[8] + (piVar26[9] + piVar26[7] >> 1) >> 1;
        auVar42._4_4_ = piVar26[10] + (piVar26[0xb] + piVar26[9] >> 1) >> 1;
        auVar42._8_4_ = piVar26[0xc] + (piVar26[0xd] + piVar26[0xb] >> 1) >> 1;
        auVar42._12_4_ = piVar26[0xe] + (piVar26[0xf] + piVar26[0xd] >> 1) >> 1;
        auVar32 = NEON_sshl(auVar42,auVar34,4);
        auVar49._0_4_ = *piVar23 + (piVar23[1] + piVar23[-1] >> 1) >> 1;
        auVar49._4_4_ = piVar23[2] + (piVar23[3] + piVar23[1] >> 1) >> 1;
        auVar49._8_4_ = piVar23[4] + (piVar23[5] + piVar23[3] >> 1) >> 1;
        auVar49._12_4_ = piVar23[6] + (piVar23[7] + piVar23[5] >> 1) >> 1;
        auVar50 = NEON_sshl(auVar49,auVar34,4);
        auVar44._0_4_ = piVar23[8] + (piVar23[9] + piVar23[7] >> 1) >> 1;
        auVar44._4_4_ = piVar23[10] + (piVar23[0xb] + piVar23[9] >> 1) >> 1;
        auVar44._8_4_ = piVar23[0xc] + (piVar23[0xd] + piVar23[0xb] >> 1) >> 1;
        auVar44._12_4_ = piVar23[0xe] + (piVar23[0xf] + piVar23[0xd] >> 1) >> 1;
        auVar45 = NEON_sshl(auVar44,auVar34,4);
        auVar38._0_8_ =
             CONCAT26((short)(auVar50._12_4_ + auVar33._12_4_),
                      CONCAT24(auVar50._8_2_ + auVar33._8_2_,
                               CONCAT22(auVar50._4_2_ + auVar33._4_2_,auVar50._0_2_ + auVar33._0_2_)
                              ));
        auVar38._8_2_ = auVar45._0_2_ + auVar32._0_2_;
        auVar38._10_2_ = auVar45._4_2_ + auVar32._4_2_;
        auVar38._12_2_ = auVar45._8_2_ + auVar32._8_2_;
        auVar38._14_2_ = auVar45._12_2_ + auVar32._12_2_;
        *(ssc_i64_u *)(psVar20 + 4) = auVar38._8_8_;
        *(ssc_u64_u *)psVar20 = auVar38._0_8_;
        piVar23 = piVar23 + 0x10;
        piVar26 = piVar26 + 0x10;
        psVar20 = psVar20 + 8;
      } while (lVar22 != 0);
    }
    lVar22 = (ulong)(param_4 >> 1) - lVar25;
    param_1 = param_1 + lVar25 * 2;
    param_2 = param_2 + lVar25 * 2;
    psVar20 = param_3 + lVar25;
    do {
      piVar12 = param_1 + -1;
      iVar30 = *param_1;
      piVar13 = param_2 + -1;
      iVar35 = *param_2;
      piVar23 = param_2 + 1;
      lVar22 = lVar22 + -1;
      piVar26 = param_1 + 1;
      param_1 = param_1 + 2;
      param_2 = param_2 + 2;
      *psVar20 = (short)((iVar35 + (*piVar23 + *piVar13 >> 1) >> 1) >> (uVar21 & 0x1f)) +
                 (short)((iVar30 + (*piVar26 + *piVar12 >> 1) >> 1) >> (uVar21 & 0x1f));
      psVar20 = psVar20 + 1;
    } while (lVar22 != 0);
  }
  _ssc_autocorr((undefined *)(param_3),(ssc_u32_u *)(&ac_data.d[0]));
  uVar31 = NEON_sshl(ac_data.d[0],DAT_00102828,4);
  ac_data.d[0] = CONCAT44((int)((ulong)ac_data.d[0] >> 0x20) - (int)((ulong)uVar31 >> 0x20),
                      (int)ac_data.d[0] + (int)uVar31);
  ac_data.i[4] = ac_data.i[4] - (ac_data.i[4] >> 10);
  ac_data.d[1] = CONCAT44((((int32_t)(ac_data.d[1] >> 32)) + ((int)((int32_t)(ac_data.d[1] >> 32)) >> 0x10) * -0x24) -
                      ((((int32_t)(ac_data.d[1] >> 32)) & 0xffff) + (((int32_t)(ac_data.d[1] >> 32)) & 0xffff) * 8 >> 0xe),
                      (int)ac_data.d[1] - ((int)ac_data.d[1] >> 0xc));
  _ssc_lpc((ssc_u16_u *)(&lpc_data[0]),(ssc_i32_u *)(&ac_data.d[0]));
  sVar39 = param_3[1];
  sVar3 = (short)((uint)(lpc_data[0] * 0x7332) >> 0xf) + 0xccd;
  sVar4 = (short)((uint)(lpc_data[1] * 0x67ac) >> 0xf) +
          (short)((uint)((lpc_data[0] * 0xe664 >> 0x10) * 0x6666) >> 0xf);
  sVar46 = *param_3;
  iVar30 = (int)sVar3;
  sVar47 = param_3[2];
  sVar5 = (short)((uint)(lpc_data[2] * 0x5d4d) >> 0xf) +
          (short)((uint)((lpc_data[1] * 0xcf58 >> 0x10) * 0x6666) >> 0xf);
  iVar35 = (int)sVar4;
  sVar6 = (short)((uint)(lpc_data[3] * 0x53f8) >> 0xf) +
          (short)((uint)((lpc_data[2] * 0xba9a >> 0x10) * 0x6666) >> 0xf);
  iVar28 = (int)sVar46;
  uVar55 = CONCAT26(param_3[3] +
                    (short)(sVar47 * iVar30 + sVar39 * iVar35 + sVar5 * iVar28 + 0x800U >> 0xc),
                    CONCAT24(sVar47 + (short)(sVar39 * iVar30 + iVar35 * iVar28 + 0x800U >> 0xc),
                             CONCAT22(sVar39 + (short)(sVar46 * iVar30 + 0x800U >> 0xc),sVar46)));
  lVar25 = (ulong)(ushort)(param_3[4] +
                          (short)((int)sVar5 * (int)sVar39 + sVar47 * iVar35 + param_3[3] * iVar30 +
                                  sVar6 * iVar28 + 0x800U >> 0xc)) << 0x30;
  psVar20 = param_3 + 0xc;
  uVar24 = 0xfffffffffffffffd;
  sVar39 = (short)((uint)((lpc_data[3] * 0xa7f0 >> 0x10) * 0x6666) >> 0xf);
  uVar51 = *(ssc_u64_u *)(param_3 + 4);
  uVar52 = *(ssc_u64_u *)(param_3 + 8);
  uVar31 = *(ssc_u64_u *)param_3;
  do {
    uVar54 = uVar52;
    *(ssc_u64_u *)(psVar20 + -0xc) = uVar55;
    uVar24 = uVar24 + 8;
    uVar55 = NEON_ext(uVar31,uVar51,6,1);
    uVar52 = NEON_ext(uVar51,uVar54,6,1);
    uVar63 = NEON_ext(uVar51,uVar54,2,1);
    uVar53 = *(ssc_u64_u *)psVar20;
    psVar7 = psVar20 + 4;
    sVar64 = (short)((ulong)uVar63 >> 0x10);
    sVar65 = (short)((ulong)uVar63 >> 0x20);
    sVar66 = (short)((ulong)uVar63 >> 0x30);
    sVar60 = (short)((ulong)uVar51 >> 0x10);
    sVar61 = (short)((ulong)uVar51 >> 0x20);
    sVar62 = (short)((ulong)uVar51 >> 0x30);
    uVar56 = NEON_ext(uVar54,uVar53,2,1);
    sVar46 = (short)((ulong)uVar54 >> 0x10);
    sVar47 = (short)((ulong)uVar54 >> 0x20);
    sVar48 = (short)((ulong)uVar54 >> 0x30);
    uVar67 = NEON_ext(uVar31,uVar51,4,1);
    sVar57 = (short)((ulong)uVar56 >> 0x10);
    sVar58 = (short)((ulong)uVar56 >> 0x20);
    sVar59 = (short)((ulong)uVar56 >> 0x30);
    uVar68 = NEON_ext(uVar31,uVar51,2,1);
    uVar69 = NEON_ext(uVar51,uVar54,4,1);
    iVar30 = (int)sVar4 * (int)(short)((ulong)uVar52 >> 0x10) + (int)sVar3 * (int)sVar46 +
             sVar57 * 0x1000 + (int)sVar5 * (int)(short)((ulong)uVar69 >> 0x10) +
             (int)sVar6 * (int)sVar64 + (int)sVar39 * (int)sVar60;
    auVar11._4_4_ =
         (int)sVar4 * (int)(short)((ulong)uVar55 >> 0x10) + (int)sVar3 * (int)sVar60 +
         sVar64 * 0x1000 + (int)sVar5 * (int)(short)((ulong)uVar67 >> 0x10) +
         (int)sVar6 * (int)(short)((ulong)uVar68 >> 0x10) +
         (int)sVar39 * (int)(short)((ulong)uVar31 >> 0x10);
    auVar11._0_4_ =
         (int)sVar4 * (int)(short)uVar55 + (int)sVar3 * (int)(short)uVar51 + (short)uVar63 * 0x1000
         + (int)sVar5 * (int)(short)uVar67 + (int)sVar6 * (int)(short)uVar68 +
         (int)sVar39 * (int)(short)uVar31;
    auVar11._8_4_ =
         (int)sVar4 * (int)(short)((ulong)uVar55 >> 0x20) + (int)sVar3 * (int)sVar61 +
         sVar65 * 0x1000 + (int)sVar5 * (int)(short)((ulong)uVar67 >> 0x20) +
         (int)sVar6 * (int)(short)((ulong)uVar68 >> 0x20) +
         (int)sVar39 * (int)(short)((ulong)uVar31 >> 0x20);
    auVar11._12_4_ =
         (int)sVar4 * (int)(short)((ulong)uVar55 >> 0x30) + (int)sVar3 * (int)sVar62 +
         sVar66 * 0x1000 + (int)sVar5 * (int)(short)((ulong)uVar67 >> 0x30) +
         (int)sVar6 * (int)(short)((ulong)uVar68 >> 0x30) +
         (int)sVar39 * (int)(short)((ulong)uVar31 >> 0x30);
    auVar33 = NEON_srshr(auVar11,0xc,4);
    auVar10._4_2_ = (short)iVar30;
    auVar10._0_4_ =
         (int)sVar4 * (int)(short)uVar52 + (int)sVar3 * (int)(short)uVar54 + (short)uVar56 * 0x1000
         + (int)sVar5 * (int)(short)uVar69 + (int)sVar6 * (int)(short)uVar63 +
         (int)sVar39 * (int)(short)uVar51;
    auVar10._6_2_ = (short)((uint)iVar30 >> 0x10);
    auVar10._8_4_ =
         (int)sVar4 * (int)(short)((ulong)uVar52 >> 0x20) + (int)sVar3 * (int)sVar47 +
         sVar58 * 0x1000 + (int)sVar5 * (int)(short)((ulong)uVar69 >> 0x20) +
         (int)sVar6 * (int)sVar65 + (int)sVar39 * (int)sVar61;
    auVar10._12_4_ =
         (int)sVar4 * (int)(short)((ulong)uVar52 >> 0x30) + (int)sVar3 * (int)sVar48 +
         sVar59 * 0x1000 + (int)sVar5 * (int)(short)((ulong)uVar69 >> 0x30) +
         (int)sVar6 * (int)sVar66 + (int)sVar39 * (int)sVar62;
    auVar32 = NEON_srshr(auVar10,0xc,4);
    uVar51 = CONCAT26(auVar33._12_2_,CONCAT24(auVar33._8_2_,CONCAT22(auVar33._4_2_,auVar33._0_2_)));
    uVar31 = NEON_ext(lVar25,uVar51,6,1);
    lVar25 = CONCAT26(auVar32._12_2_,CONCAT24(auVar32._8_2_,CONCAT22(auVar32._4_2_,auVar32._0_2_)));
    uVar55 = NEON_ext(uVar51,lVar25,6,1);
    *(ssc_u64_u *)(psVar20 + -8) = uVar31;
    psVar20 = psVar20 + 8;
    uVar51 = uVar53;
    uVar52 = *(ssc_u64_u *)psVar7;
    uVar31 = uVar54;
  } while (uVar24 < 0x3a5);
  uVar31 = NEON_ext(uVar53,*(ssc_u64_u *)psVar7,2,1);
  uVar52 = NEON_ext(uVar54,uVar53,4,1);
  *(ssc_u64_u *)(param_3 + 0x3a8) = uVar55;
  uVar51 = NEON_ext(uVar54,uVar53,6,1);
  iVar30 = (short)((ulong)uVar31 >> 0x10) * 0x1000 +
           (int)sVar3 * (int)(short)((ulong)uVar53 >> 0x10) +
           (int)sVar4 * (int)(short)((ulong)uVar51 >> 0x10) +
           (int)sVar5 * (int)(short)((ulong)uVar52 >> 0x10) + (int)sVar6 * (int)sVar57 +
           (int)sVar39 * (int)sVar46;
  auVar9._4_2_ = (short)iVar30;
  auVar9._0_4_ = (short)uVar31 * 0x1000 + (int)sVar3 * (int)(short)uVar53 +
                 (int)sVar4 * (int)(short)uVar51 + (int)sVar5 * (int)(short)uVar52 +
                 (int)sVar6 * (int)(short)uVar56 + (int)sVar39 * (int)(short)uVar54;
  auVar9._6_2_ = (short)((uint)iVar30 >> 0x10);
  auVar9._8_4_ = (short)((ulong)uVar31 >> 0x20) * 0x1000 +
                 (int)sVar3 * (int)(short)((ulong)uVar53 >> 0x20) +
                 (int)sVar4 * (int)(short)((ulong)uVar51 >> 0x20) +
                 (int)sVar5 * (int)(short)((ulong)uVar52 >> 0x20) + (int)sVar6 * (int)sVar58 +
                 (int)sVar39 * (int)sVar47;
  auVar9._12_4_ =
       (short)((ulong)uVar31 >> 0x30) * 0x1000 + (int)sVar3 * (int)(short)((ulong)uVar53 >> 0x30) +
       (int)sVar4 * (int)(short)((ulong)uVar51 >> 0x30) +
       (int)sVar5 * (int)(short)((ulong)uVar52 >> 0x30) + (int)sVar6 * (int)sVar59 +
       (int)sVar39 * (int)sVar48;
  auVar33 = NEON_srshr(auVar9,0xc,4);
  uVar31 = NEON_ext(lVar25,CONCAT26(auVar33._12_2_,
                                    CONCAT24(auVar33._8_2_,CONCAT22(auVar33._4_2_,auVar33._0_2_))),6
                    ,1);
  *(ssc_u64_u *)(param_3 + 0x3ac) = uVar31;
  if (*(ssc_i64_u *)(uintptr_t)((lVar8 + 0x28)) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* ==================================================================== */
/* Function: tone_detect @ 00112088 */
/* ==================================================================== */

undefined8 tone_detect(long param_1,ssc_u32_u *param_2,int param_3,int param_4)

{
  ssc_i32_u *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  long lVar11;

  uVar9 = *param_2;
  iVar8 = (int)((ulong)((long)param_3 * 0x7730) >> 0xf);
  if ((*(ssc_i32_u *)(uintptr_t)((param_1 + (long)(int)uVar9 * 4)) < iVar8) ||
     (uVar6 = param_2[1], *(ssc_i32_u *)(uintptr_t)((param_1 + (long)(int)uVar6 * 4)) < iVar8)) {
    return 0;
  }
  uVar2 = uVar6;
  if ((int)uVar9 <= (int)uVar6) {
    uVar2 = uVar9;
    uVar9 = uVar6;
  }
  uVar6 = -uVar2;
  lVar11 = param_1 + (long)(int)uVar9 * 4;
  if (*(ssc_i32_u *)(uintptr_t)((lVar11 + 4)) <= *(ssc_i32_u *)(uintptr_t)((lVar11 + -4))) {
    uVar6 = ~uVar2;
  }
  uVar6 = uVar6 + uVar9;
  if (4 < (int)uVar6) {
    lVar10 = (ulong)uVar2 << 0x20;
    lVar11 = lVar10 + 0x300000000;
    uVar7 = 2;
    do {
      lVar10 = lVar10 + 0x100000000;
      iVar5 = *(ssc_i32_u *)(uintptr_t)((param_1 + (long)(int)uVar2 * 4 + uVar7 * 4));
      if (iVar8 < iVar5) {
        iVar3 = *(ssc_i32_u *)(uintptr_t)((param_1 + (lVar11 >> 0x1e)));
        uVar6 = (uint)uVar7;
        if (iVar3 < iVar5) {
          uVar6 = uVar6 - (iVar3 < *(ssc_i32_u *)(uintptr_t)((param_1 + (lVar10 >> 0x1e))));
        }
        if ((int)uVar6 < 5) {
          return 0;
        }
        if (param_4 >> 1 < (int)uVar6) {
          return 0;
        }
        break;
      }
      uVar7 = uVar7 + 1;
      lVar11 = lVar11 + 0x100000000;
    } while (uVar6 != uVar7);
    if (param_4 >> 1 < (int)uVar6) {
      return 0;
    }
    uVar2 = uVar6;
    for (iVar5 = uVar6 + uVar9; iVar5 < param_4 + -1; iVar5 = uVar2 + iVar5) {
      piVar1 = (ssc_i32_u *)(uintptr_t)((param_1 + (long)iVar5 * 4));
      iVar3 = *piVar1;
      iVar4 = piVar1[1];
      uVar2 = uVar6;
      if (iVar3 <= iVar4) {
        uVar2 = uVar6 + 1;
        iVar3 = iVar4;
      }
      if (iVar3 < iVar8) {
        return 0;
      }
    }
    uVar2 = iVar5 - uVar2;
    uVar9 = uVar9 - uVar6;
    do {
      if ((int)uVar9 < 1) {
        uVar6 = uVar2 - uVar6;
        if ((int)uVar6 < 1) {
          return 0;
        }
        if (param_4 <= (int)uVar2) {
          return 0;
        }
        if (*(ssc_i32_u *)(uintptr_t)((param_1 + (ulong)uVar6 * 4)) <= *(ssc_i32_u *)(uintptr_t)((param_1 + (ulong)(uVar6 - 1) * 4))) {
          uVar6 = uVar6 - 1;
        }
        *param_2 = uVar2;
        param_2[1] = uVar6;
        return 1;
      }
      iVar3 = *(ssc_i32_u *)(uintptr_t)((param_1 + (ulong)uVar9 * 4));
      iVar4 = *(ssc_i32_u *)(uintptr_t)((param_1 + (ulong)(uVar9 - 1) * 4));
      iVar5 = iVar3;
      if (iVar3 <= iVar4) {
        iVar5 = iVar4;
      }
      uVar9 = (uVar9 - uVar6) - (uint)(iVar3 <= iVar4);
    } while (iVar8 <= iVar5);
  }
  return 0;
}


/* ==================================================================== */
/* Function: ssc_pitch_search @ 00112234 */
/* ==================================================================== */

void ssc_pitch_search(ssc_u16_u *param_1,ssc_u16_u *param_2,int param_3,int param_4,ssc_i32_u *param_5)

{
  undefined1 (*pauVar1) [16];
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  vec128_t auVar12;
  undefined *puVar13;
  ssc_u16_u *puVar14;
  undefined4 uVar17;
  undefined1 (*pauVar18) [16];
  ssc_i16_u *psVar19;
  ulong uVar20;
  int iVar21;
  uint uVar22;
  ulong uVar23;
  ulong uVar24;
  ssc_u16_u *puVar25;
  long lVar26;
  long lVar27;
  ulong uVar28;
  ssc_u64_u *puVar29;
  long lVar30;
  ssc_u16_u *puVar31;
  ssc_u16_u *puVar32;
  undefined1 (*pauVar33) [16];
  undefined1 (*pauVar34) [16];
  ssc_i16_u *psVar35;
  undefined2 uVar36;
  undefined2 uVar38;
  int iVar37;
  undefined2 uVar39;
  undefined2 uVar41;
  int iVar40;
  undefined2 uVar42;
  undefined2 uVar44;
  int iVar43;
  undefined2 uVar45;
  undefined2 uVar47;
  int iVar46;
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  undefined2 uVar52;
  undefined2 uVar54;
  int iVar53;
  undefined2 uVar55;
  undefined2 uVar57;
  int iVar56;
  int iVar58;
  int iVar59;
  int iVar60;
  int iVar61;
  int iVar62;
  int iVar63;
  vec128_t auVar64;
  vec128_t auVar65;
  vec128_t auVar66;
  vec128_t auVar67;
  undefined8 local_70;
  long local_68;
  ssc_u16_u *puVar15;
  ssc_u16_u *puVar16;

  puVar13 = PTR_in_shared_0011bd00;
  lVar7 = tpidr_el0;
  local_68 = *(ssc_i64_u *)(uintptr_t)((lVar7 + 0x28));
  uVar3 = param_3 >> 2;
  local_70 = 0;
  if (param_3 < 4) {
    uVar22 = 0;
  }
  else {
    uVar22 = uVar3;
    if ((int)uVar3 < 2) {
      uVar22 = 1;
    }
    uVar23 = (ulong)uVar22;
    if (uVar22 < 9) {
      lVar26 = 0;
    }
    else {
      lVar26 = 0;
      if ((param_1 + uVar23 * 2 + -1 <= (ssc_u16_u *)(PTR_in_shared_0011bd00 + 0x774) ||
           PTR_in_shared_0011bd00 + uVar23 * 2 + 0x924 <= (uint8_t *)(param_1)) &&
         (param_2 + uVar23 * 2 + -1 <= (ssc_u16_u *)(PTR_in_shared_0011bd00 + 0x774) ||
          PTR_in_shared_0011bd00 + uVar23 * 2 + 0x924 <= (uint8_t *)(param_2))) {
        uVar24 = 8;
        if ((uVar22 & 7) != 0) {
          uVar24 = uVar23 & 7;
        }
        puVar29 = (ssc_u64_u *)(PTR_in_shared_0011bd00 + 0x774);
        lVar26 = uVar23 - uVar24;
        lVar27 = lVar26;
        puVar25 = param_1;
        puVar31 = param_2;
        do {
          uVar36 = *puVar25;
          uVar38 = puVar25[2];
          uVar39 = puVar25[4];
          uVar41 = puVar25[6];
          puVar14 = puVar25 + 8;
          puVar32 = puVar25 + 10;
          puVar15 = puVar25 + 0xc;
          puVar16 = puVar25 + 0xe;
          puVar25 = puVar25 + 0x10;
          puVar29[1] = CONCAT26(*puVar16,CONCAT24(*puVar15,CONCAT22(*puVar32,*puVar14)));
          *puVar29 = CONCAT26(uVar41,CONCAT24(uVar39,CONCAT22(uVar38,uVar36)));
          lVar27 = lVar27 + -8;
          uVar36 = *puVar31;
          uVar38 = puVar31[2];
          uVar39 = puVar31[4];
          uVar41 = puVar31[6];
          puVar32 = puVar31 + 8;
          puVar16 = puVar31 + 10;
          puVar15 = puVar31 + 0xc;
          puVar14 = puVar31 + 0xe;
          puVar31 = puVar31 + 0x10;
          puVar29[0x37] = CONCAT26(*puVar14,CONCAT24(*puVar15,CONCAT22(*puVar16,*puVar32)));
          puVar29[0x36] = CONCAT26(uVar41,CONCAT24(uVar39,CONCAT22(uVar38,uVar36)));
          puVar29 = puVar29 + 2;
        } while (lVar27 != 0);
      }
    }
    lVar27 = uVar23 - lVar26;
    puVar25 = (ssc_u16_u *)(puVar13 + lVar26 * 2 + 0x774);
    puVar31 = param_1 + lVar26 * 2;
    puVar32 = param_2 + lVar26 * 2;
    do {
      lVar27 = lVar27 + -1;
      *puVar25 = *puVar31;
      puVar25[0xd8] = *puVar32;
      puVar25 = puVar25 + 1;
      puVar31 = puVar31 + 2;
      puVar32 = puVar32 + 2;
    } while (lVar27 != 0);
  }
  uVar4 = param_4 + param_3 >> 2;
  uVar23 = (ulong)uVar4;
  if ((int)uVar22 < (int)uVar4) {
    uVar24 = (ulong)uVar22;
    uVar28 = uVar23 - uVar24;
    if (0x10 < uVar28) {
      lVar26 = uVar24 * 2;
      if ((param_2 + uVar23 * 2 + -1 <= (ssc_u16_u *)(puVar13 + uVar24 * 2 + 0x924)) ||
         (puVar13 + uVar23 * 2 + 0x924 <= (undefined *)(param_2 + lVar26))) {
        uVar20 = 0x10;
        if ((uVar28 & 0xf) != 0) {
          uVar20 = uVar28 & 0xf;
        }
        lVar27 = uVar24 * 2;
        lVar30 = uVar20 + uVar24;
        uVar24 = (uVar28 - uVar20) + uVar24;
        lVar30 = lVar30 - uVar23;
        puVar29 = (ssc_u64_u *)(puVar13 + lVar27 + 0x934);
        puVar25 = param_2 + lVar26 + 0x10;
        do {
          uVar36 = *puVar25;
          uVar38 = puVar25[2];
          uVar39 = puVar25[4];
          uVar41 = puVar25[6];
          uVar42 = puVar25[8];
          uVar44 = puVar25[10];
          uVar45 = puVar25[0xc];
          uVar47 = puVar25[0xe];
          lVar30 = lVar30 + 0x10;
          uVar52 = puVar25[-0x10];
          uVar54 = puVar25[-0xe];
          uVar55 = puVar25[-0xc];
          uVar57 = puVar25[-10];
          puVar29[-1] = CONCAT26(puVar25[-2],CONCAT24(puVar25[-4],CONCAT22(puVar25[-6],puVar25[-8]))
                                );
          puVar29[-2] = CONCAT26(uVar57,CONCAT24(uVar55,CONCAT22(uVar54,uVar52)));
          puVar29[1] = CONCAT26(uVar47,CONCAT24(uVar45,CONCAT22(uVar44,uVar42)));
          *puVar29 = CONCAT26(uVar41,CONCAT24(uVar39,CONCAT22(uVar38,uVar36)));
          puVar29 = puVar29 + 4;
          puVar25 = puVar25 + 0x20;
        } while (lVar30 != 0);
      }
    }
    lVar26 = uVar23 - uVar24;
    puVar25 = param_2 + uVar24 * 2;
    puVar31 = (ssc_u16_u *)(puVar13 + uVar24 * 2 + 0x924);
    do {
      lVar26 = lVar26 + -1;
      *puVar31 = *puVar25;
      puVar25 = puVar25 + 2;
      puVar31 = puVar31 + 1;
    } while (lVar26 != 0);
  }
  iVar21 = param_4 >> 2;
  uVar17 = ssc_pitch_xcorr_c2((ssc_u64_u *)(puVar13 + 0x774),(int64_t)(uintptr_t)(puVar13 + 0x924),(int64_t)(uintptr_t)(puVar13 + 0xcec),uVar3,iVar21);
  FUN_001126bc((ssc_u64_u *)(puVar13 + 0x924),uVar3,iVar21,(ssc_u64_u *)&local_70,0,uVar17);
  tone_detect((int64_t)(uintptr_t)(puVar13 + 0xcec),(ssc_u32_u *)(&local_70),uVar17,iVar21);
  uVar3 = param_4 >> 1;
  uVar22 = param_3 >> 1;
  if (param_4 < 2) {
    iVar21 = 1;
  }
  else {
    uVar23 = 0;
    uVar4 = uVar22;
    if ((int)uVar22 < 2) {
      uVar4 = 1;
    }
    uVar24 = (ulong)uVar4;
    uVar6 = uVar3;
    if ((int)uVar3 < 2) {
      uVar6 = 1;
    }
    uVar28 = uVar24 & 0x7ffffff0;
    pauVar33 = (undefined1 (*) [16])(param_2 + 8);
    iVar21 = 1;
    do {
      uVar2 = (int)local_70 * -2 + (int)uVar23;
      uVar5 = -uVar2;
      if (-1 < (int)uVar2) {
        uVar5 = uVar2;
      }
      *(ssc_u32_u *)(puVar13 + uVar23 * 4 + 0xcec) = 0;
      if (uVar5 < 3) {
LAB_00112514:
        if (param_3 < 2) {
          iVar37 = 0;
          iVar40 = iVar37;
        }
        else {
          if (uVar4 < 0x10) {
            iVar37 = 0;
            uVar20 = 0;
LAB_001125a4:
            lVar26 = uVar24 - uVar20;
            psVar19 = (ssc_i16_u *)(param_1 + uVar20);
            psVar35 = (ssc_i16_u *)(param_2 + uVar20 + uVar23);
            do {
              lVar26 = lVar26 + -1;
              iVar37 = iVar37 + (int)*psVar35 * (int)*psVar19;
              psVar19 = psVar19 + 1;
              psVar35 = psVar35 + 1;
            } while (lVar26 != 0);
          }
          else {
            iVar37 = 0;
            iVar40 = 0;
            iVar43 = 0;
            iVar46 = 0;
            iVar48 = 0;
            iVar49 = 0;
            iVar50 = 0;
            iVar51 = 0;
            iVar53 = 0;
            iVar56 = 0;
            iVar58 = 0;
            iVar59 = 0;
            iVar60 = 0;
            iVar61 = 0;
            iVar62 = 0;
            iVar63 = 0;
            pauVar18 = (undefined1 (*) [16])(param_1 + 8);
            uVar20 = uVar28;
            pauVar34 = pauVar33;
            do {
              pauVar1 = pauVar18 + -1;
              uVar8 = *(ssc_u64_u *)*pauVar1;
              uVar9 = *(ssc_u64_u *)*pauVar18;
              auVar66 = *(vec128_t *)*pauVar18;
              auVar65 = *(vec128_t *)*pauVar18;
              pauVar18 = pauVar18 + 2;
              uVar20 = uVar20 - 0x10;
              auVar64 = NEON_ext(*(vec128_t *)*pauVar1,*(vec128_t *)*pauVar1,8,1);
              pauVar1 = pauVar34 + -1;
              uVar10 = *(ssc_u64_u *)*pauVar1;
              uVar11 = *(ssc_u64_u *)*pauVar34;
              auVar12 = *(vec128_t *)*pauVar34;
              auVar67 = *(vec128_t *)*pauVar34;
              auVar65 = NEON_ext(auVar65,auVar66,8,1);
              pauVar34 = pauVar34 + 2;
              auVar66 = NEON_ext(*(vec128_t *)*pauVar1,*(vec128_t *)*pauVar1,8,1);
              iVar37 = iVar37 + (int)(short)uVar10 * (int)(short)uVar8;
              iVar40 = iVar40 + (int)(short)((ulong)uVar10 >> 0x10) *
                                (int)(short)((ulong)uVar8 >> 0x10);
              iVar43 = iVar43 + (int)(short)((ulong)uVar10 >> 0x20) *
                                (int)(short)((ulong)uVar8 >> 0x20);
              iVar46 = iVar46 + (int)(short)((ulong)uVar10 >> 0x30) *
                                (int)(short)((ulong)uVar8 >> 0x30);
              auVar67 = NEON_ext(auVar67,auVar12,8,1);
              iVar53 = iVar53 + (int)(short)uVar11 * (int)(short)uVar9;
              iVar56 = iVar56 + (int)(short)((ulong)uVar11 >> 0x10) *
                                (int)(short)((ulong)uVar9 >> 0x10);
              iVar58 = iVar58 + (int)(short)((ulong)uVar11 >> 0x20) *
                                (int)(short)((ulong)uVar9 >> 0x20);
              iVar59 = iVar59 + (int)(short)((ulong)uVar11 >> 0x30) *
                                (int)(short)((ulong)uVar9 >> 0x30);
              iVar48 = iVar48 + (int)auVar66._0_2_ * (int)auVar64._0_2_;
              iVar49 = iVar49 + (int)auVar66._2_2_ * (int)auVar64._2_2_;
              iVar50 = iVar50 + (int)auVar66._4_2_ * (int)auVar64._4_2_;
              iVar51 = iVar51 + (int)auVar66._6_2_ * (int)auVar64._6_2_;
              iVar60 = iVar60 + (int)auVar67._0_2_ * (int)auVar65._0_2_;
              iVar61 = iVar61 + (int)auVar67._2_2_ * (int)auVar65._2_2_;
              iVar62 = iVar62 + (int)auVar67._4_2_ * (int)auVar65._4_2_;
              iVar63 = iVar63 + (int)auVar67._6_2_ * (int)auVar65._6_2_;
            } while (uVar20 != 0);
            iVar37 = iVar53 + iVar37 + iVar60 + iVar48 + iVar56 + iVar40 + iVar61 + iVar49 +
                     iVar58 + iVar43 + iVar62 + iVar50 + iVar59 + iVar46 + iVar63 + iVar51;
            uVar20 = uVar28;
            if (uVar28 != uVar24) goto LAB_001125a4;
          }
          iVar40 = iVar37;
          if (iVar37 < 0) {
            iVar40 = -1;
          }
        }
        if (iVar21 <= iVar37) {
          iVar21 = iVar37;
        }
        *(ssc_i32_u *)(puVar13 + uVar23 * 4 + 0xcec) = iVar40;
      }
      else {
        uVar2 = ((int32_t)(local_70 >> 32)) * -2 + (int)uVar23;
        uVar5 = -uVar2;
        if (-1 < (int)uVar2) {
          uVar5 = uVar2;
        }
        if (uVar5 < 3) goto LAB_00112514;
      }
      uVar23 = uVar23 + 1;
      pauVar33 = (undefined1 (*) [16])((uint8_t *)pauVar33 + 2);
    } while (uVar23 != uVar6);
  }
  FUN_001126bc((ssc_u64_u *)(param_2),uVar22,uVar3,(ssc_u64_u *)&local_70,1,iVar21);
  uVar22 = 0;
  if ((0 < (int)local_70) && ((int)local_70 < (int)(uVar3 - 1))) {
    iVar37 = *(ssc_i32_u *)(puVar13 + (ulong)((int)local_70 - 1) * 4 + 0xcec);
    iVar21 = *(ssc_i32_u *)(puVar13 + (local_70 & 0xffffffff) * 4 + 0xcf0);
    uVar3 = *(ssc_i32_u *)(puVar13 + (local_70 & 0xffffffff) * 4 + 0xcec) - iVar37;
    if ((int)(((int)uVar3 >> 0x10) * 0xb334 + ((uVar3 & 0xffff) * 0x599a >> 0xf)) < iVar21 - iVar37)
    {
      uVar22 = 0xffffffff;
    }
    else {
      uVar3 = *(ssc_i32_u *)(puVar13 + (local_70 & 0xffffffff) * 4 + 0xcec) - iVar21;
      uVar22 = (uint)((int)(((int)uVar3 >> 0x10) * 0xb334 + ((uVar3 & 0xffff) * 0x599a >> 0xf)) <
                     iVar37 - iVar21);
    }
  }
  *param_5 = uVar22 + (int)local_70 * 2;
  if (*(ssc_i64_u *)(uintptr_t)((lVar7 + 0x28)) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* ==================================================================== */
/* Function: FUN_001126bc @ 001126bc */
/* ==================================================================== */

void FUN_001126bc(ssc_u64_u *param_1,int param_2,uint param_3,ssc_u64_u *param_4,uint param_5,
                 uint param_6)

{
  ssc_i16_u *psVar1;
  ulong uVar2;
  uint uVar3;
  vec128_t auVar4;
  ssc_i16_u *psVar5;
  ssc_i16_u *psVar6;
  ssc_i16_u *psVar7;
  ssc_i16_u *psVar8;
  ssc_i16_u *psVar9;
  ssc_i16_u *psVar10;
  ssc_i16_u *psVar11;
  ssc_i16_u *psVar12;
  ssc_i16_u *psVar13;
  ssc_i16_u *psVar14;
  ssc_i16_u *psVar15;
  ssc_i16_u *psVar16;
  ssc_i16_u *psVar17;
  ssc_i16_u *psVar18;
  undefined *puVar19;
  uint uVar20;
  long lVar21;
  uint uVar22;
  ssc_i16_u *psVar23;
  uint uVar24;
  undefined4 uVar25;
  ssc_u64_u *puVar26;
  undefined4 uVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  uint uVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  uint uVar36;
  int iVar38;
  int iVar39;
  vec128_t auVar37;
  int iVar40;
  short sVar44;
  short sVar45;
  undefined8 uVar41;
  short sVar46;
  vec128_t auVar42;
  vec128_t auVar43;
  int iVar47;
  undefined8 uVar48;
  int iVar50;
  int iVar51;
  vec128_t auVar49;
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  int iVar56;
  vec128_t auVar57;
  vec128_t auVar58;
  vec128_t auVar59;
  vec128_t auVar60;
  vec128_t auVar61;

  *param_4 = DAT_001027f0;
  puVar19 = PTR_in_shared_0011bd00;
  if (param_2 < 1) {
    iVar32 = 0;
    iVar33 = 0;
    iVar34 = 0;
    iVar35 = 0;
    uVar24 = 0;
  }
  else {
    iVar39 = -param_5;
    iVar38 = 0;
    iVar32 = 0;
    iVar33 = 0;
    iVar34 = 0;
    iVar35 = 0;
    auVar37._4_4_ = iVar39;
    auVar37._0_4_ = iVar39;
    auVar37._8_4_ = iVar39;
    auVar37._12_4_ = iVar39;
    puVar26 = param_1;
    do {
      uVar41 = *puVar26;
      uVar48 = puVar26[1];
      iVar38 = iVar38 + 8;
      sVar44 = (short)((ulong)uVar41 >> 0x10);
      sVar45 = (short)((ulong)uVar41 >> 0x20);
      sVar46 = (short)((ulong)uVar41 >> 0x30);
      auVar42._0_4_ = (int)(short)uVar41 * (int)(short)uVar41;
      auVar42._4_4_ = (int)sVar44 * (int)sVar44;
      auVar42._8_4_ = (int)sVar45 * (int)sVar45;
      auVar42._12_4_ = (int)sVar46 * (int)sVar46;
      sVar44 = (short)((ulong)uVar48 >> 0x10);
      sVar45 = (short)((ulong)uVar48 >> 0x20);
      sVar46 = (short)((ulong)uVar48 >> 0x30);
      auVar49._0_4_ = (int)(short)uVar48 * (int)(short)uVar48;
      auVar49._4_4_ = (int)sVar44 * (int)sVar44;
      auVar49._8_4_ = (int)sVar45 * (int)sVar45;
      auVar49._12_4_ = (int)sVar46 * (int)sVar46;
      auVar42 = NEON_sshl(auVar42,auVar37,4);
      auVar49 = NEON_sshl(auVar49,auVar37,4);
      iVar32 = auVar42._0_4_ + iVar32 + auVar49._0_4_;
      iVar33 = auVar42._4_4_ + iVar33 + auVar49._4_4_;
      iVar34 = auVar42._8_4_ + iVar34 + auVar49._8_4_;
      iVar35 = auVar42._12_4_ + iVar35 + auVar49._12_4_;
      puVar26 = puVar26 + 2;
    } while (iVar38 < param_2);
    uVar24 = param_2 + 7U & 0xfffffff8;
  }
  auVar61._4_4_ = iVar33;
  auVar61._0_4_ = iVar32;
  auVar61._8_4_ = iVar34;
  auVar61._12_4_ = iVar35;
  auVar4._4_4_ = iVar33;
  auVar4._0_4_ = iVar32;
  auVar4._8_4_ = iVar34;
  auVar4._12_4_ = iVar35;
  auVar37 = NEON_ext(auVar61,auVar4,8,1);
  uVar36 = auVar37._0_4_ + auVar37._4_4_ + iVar32 + iVar33 + 1;
  if ((int)uVar24 < param_2) {
    uVar29 = (ulong)uVar24;
    if (0xe < ~uVar24 + param_2) {
      uVar2 = (ulong)(~uVar24 + param_2) + 1;
      uVar28 = uVar2 & 0x1fffffff0;
      iVar32 = 0;
      iVar33 = 0;
      iVar34 = 0;
      iVar35 = 0;
      auVar43._0_4_ = -param_5;
      auVar43._4_4_ = -param_5;
      auVar43._8_4_ = -param_5;
      auVar43._12_4_ = -param_5;
      iVar38 = 0;
      iVar39 = 0;
      iVar40 = 0;
      psVar23 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + uVar29 * 2 + 0x10));
      iVar47 = 0;
      iVar50 = 0;
      iVar51 = 0;
      iVar52 = 0;
      iVar53 = 0;
      iVar54 = 0;
      iVar55 = 0;
      iVar56 = 0;
      uVar30 = uVar28;
      do {
        psVar1 = psVar23 + -8;
        psVar5 = psVar23 + -7;
        psVar6 = psVar23 + -6;
        psVar7 = psVar23 + -5;
        psVar8 = psVar23 + -4;
        psVar9 = psVar23 + -3;
        psVar10 = psVar23 + -2;
        psVar11 = psVar23 + -1;
        sVar44 = *psVar23;
        psVar12 = psVar23 + 1;
        psVar13 = psVar23 + 2;
        psVar14 = psVar23 + 3;
        psVar15 = psVar23 + 4;
        psVar16 = psVar23 + 5;
        psVar17 = psVar23 + 6;
        psVar18 = psVar23 + 7;
        uVar30 = uVar30 - 0x10;
        psVar23 = psVar23 + 0x10;
        auVar59._0_4_ = (int)*psVar8 * (int)*psVar8;
        auVar59._4_4_ = (int)*psVar9 * (int)*psVar9;
        auVar59._8_4_ = (int)*psVar10 * (int)*psVar10;
        auVar59._12_4_ = (int)*psVar11 * (int)*psVar11;
        auVar57._0_4_ = (int)*psVar1 * (int)*psVar1;
        auVar57._4_4_ = (int)*psVar5 * (int)*psVar5;
        auVar57._8_4_ = (int)*psVar6 * (int)*psVar6;
        auVar57._12_4_ = (int)*psVar7 * (int)*psVar7;
        auVar60._0_4_ = (int)*psVar15 * (int)*psVar15;
        auVar60._4_4_ = (int)*psVar16 * (int)*psVar16;
        auVar60._8_4_ = (int)*psVar17 * (int)*psVar17;
        auVar60._12_4_ = (int)*psVar18 * (int)*psVar18;
        auVar58._0_4_ = (int)sVar44 * (int)sVar44;
        auVar58._4_4_ = (int)*psVar12 * (int)*psVar12;
        auVar58._8_4_ = (int)*psVar13 * (int)*psVar13;
        auVar58._12_4_ = (int)*psVar14 * (int)*psVar14;
        auVar49 = NEON_ushl(auVar59,auVar43,4);
        auVar37 = NEON_ushl(auVar57,auVar43,4);
        auVar61 = NEON_ushl(auVar60,auVar43,4);
        auVar42 = NEON_ushl(auVar58,auVar43,4);
        iVar32 = auVar49._0_4_ + iVar32;
        iVar33 = auVar49._4_4_ + iVar33;
        iVar34 = auVar49._8_4_ + iVar34;
        iVar35 = auVar49._12_4_ + iVar35;
        uVar36 = auVar37._0_4_ + uVar36;
        iVar38 = auVar37._4_4_ + iVar38;
        iVar39 = auVar37._8_4_ + iVar39;
        iVar40 = auVar37._12_4_ + iVar40;
        iVar53 = auVar61._0_4_ + iVar53;
        iVar54 = auVar61._4_4_ + iVar54;
        iVar55 = auVar61._8_4_ + iVar55;
        iVar56 = auVar61._12_4_ + iVar56;
        iVar47 = auVar42._0_4_ + iVar47;
        iVar50 = auVar42._4_4_ + iVar50;
        iVar51 = auVar42._8_4_ + iVar51;
        iVar52 = auVar42._12_4_ + iVar52;
      } while (uVar30 != 0);
      uVar36 = iVar47 + uVar36 + iVar53 + iVar32 + iVar50 + iVar38 + iVar54 + iVar33 +
               iVar51 + iVar39 + iVar55 + iVar34 + iVar52 + iVar40 + iVar56 + iVar35;
      uVar29 = uVar28 + uVar29;
      if (uVar2 == uVar28) goto LAB_00112814;
    }
    do {
      uVar2 = uVar29 + 1;
      iVar32 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + uVar29 * 2));
      uVar36 = ((uint)(iVar32 * iVar32) >> (ulong)(param_5 & 0x1f)) + uVar36;
      uVar29 = uVar2;
    } while ((int)uVar2 < param_2);
  }
LAB_00112814:
  if (0 < (int)param_3) {
    uVar27 = 0;
    uVar29 = 0;
    uVar22 = 0;
    uVar31 = 0;
    uVar24 = 0xffff;
    uVar20 = 0xffff;
    do {
      uVar3 = *(ssc_u32_u *)(puVar19 + uVar29 * 4 + 0xcec);
      if (0 < (int)uVar3) {
        sVar44 = (short)(uVar3 >> (ulong)(0x11U - (int)LZCOUNT(param_6) & 0x1f));
        if (param_6 >> 0xf == 0) {
          sVar44 = (short)(uVar3 << (ulong)((int)LZCOUNT(param_6) - 0x11U & 0x1f));
        }
        uVar3 = (int)sVar44 * (int)sVar44;
        iVar32 = (int)(uVar3 * 2) >> 0x10;
        if (((int)((uVar36 & 0xffff) * (int)(short)uVar24) >> 0xf) +
            (int)(short)uVar24 * ((int)uVar36 >> 0x10) * 2 <
            (int)(((int)uVar22 >> 0xf & 0xfffffffeU) * iVar32 +
                 ((int)(iVar32 * (uVar22 & 0xffff)) >> 0xf))) {
          uVar25 = (undefined4)uVar29;
          if (((int)((uVar36 & 0xffff) * (int)(short)uVar20) >> 0xf) +
              (int)(short)uVar20 * ((int)uVar36 >> 0x10) * 2 <
              (int)(((int)uVar31 >> 0xf & 0xfffffffeU) * iVar32 +
                   ((int)(iVar32 * (uVar31 & 0xffff)) >> 0xf))) {
            *(ssc_u32_u *)param_4 = uVar25;
            *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + 4)) = uVar27;
            uVar27 = uVar25;
            uVar22 = uVar31;
            uVar24 = uVar20;
            uVar20 = uVar3 >> 0xf;
            uVar31 = uVar36;
          }
          else {
            uVar24 = uVar3 >> 0xf;
            *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + 4)) = uVar25;
            uVar22 = uVar36;
          }
        }
      }
      lVar21 = uVar29 * 2;
      uVar29 = uVar29 + 1;
      iVar33 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar21 + (long)param_2 * 2));
      iVar32 = (int)*(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + lVar21));
      uVar36 = (((uint)(iVar33 * iVar33) >> (ulong)(param_5 & 0x1f)) -
               ((uint)(iVar32 * iVar32) >> (ulong)(param_5 & 0x1f))) + uVar36;
      if ((int)uVar36 < 2) {
        uVar36 = 1;
      }
    } while (param_3 != uVar29);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_remove_doubling @ 00112990 */
/* ==================================================================== */

uint ssc_remove_doubling(long param_1,uint param_2,uint param_3,int param_4,ssc_u32_u *param_5,
                        int param_6,short param_7)

{
  ssc_i16_u *psVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  bool bVar10;
  bool bVar11;
  short sVar12;
  short sVar13;
  uint extraout_var;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ssc_u64_u *puVar17;
  ulong uVar18;
  ssc_i16_u *psVar19;
  ssc_u64_u *puVar20;
  ssc_i32_u *piVar21;
  long lVar22;
  long lVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  short sVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  short sVar39;
  short sVar40;
  undefined8 uVar37;
  short sVar41;
  undefined8 uVar38;
  undefined8 uVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  undefined8 uVar47;
  long local_f0;
  uint local_e8;
  uint local_e4;

  iVar27 = (int)param_2 >> 1;
  iVar32 = 0;
  iVar34 = 0;
  iVar35 = 0;
  iVar36 = 0;
  iVar33 = param_4 >> 1;
  lVar23 = (long)((ulong)param_2 << 0x20) >> 0x21;
  uVar15 = (int)*param_5 >> 1;
  if (iVar27 <= (int)*param_5 >> 1) {
    uVar15 = iVar27 - 1;
  }
  puVar20 = (ssc_u64_u *)(uintptr_t)((param_1 + (long)iVar27 * 2));
  iVar25 = 0;
  iVar28 = 0;
  iVar30 = 0;
  iVar31 = 0;
  *param_5 = uVar15;
  puVar9 = PTR_in_shared_0011bd00;
  if (1 < param_4) {
    iVar25 = 0;
    iVar28 = 0;
    iVar30 = 0;
    iVar31 = 0;
    iVar43 = 0;
    iVar32 = 0;
    iVar34 = 0;
    iVar35 = 0;
    iVar36 = 0;
    puVar17 = puVar20;
    do {
      uVar42 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar17)) + (long)(int)uVar15 * -2));
      iVar43 = iVar43 + 4;
      uVar37 = *puVar17;
      puVar17 = puVar17 + 1;
      sVar12 = (short)uVar37;
      sVar13 = (short)((ulong)uVar37 >> 0x10);
      sVar29 = (short)((ulong)uVar37 >> 0x20);
      sVar39 = (short)((ulong)uVar37 >> 0x30);
      iVar25 = iVar25 + (int)sVar12 * (int)sVar12;
      iVar28 = iVar28 + (int)sVar13 * (int)sVar13;
      iVar30 = iVar30 + (int)sVar29 * (int)sVar29;
      iVar31 = iVar31 + (int)sVar39 * (int)sVar39;
      iVar32 = iVar32 + (int)sVar12 * (int)(short)uVar42;
      iVar34 = iVar34 + (int)sVar13 * (int)(short)((ulong)uVar42 >> 0x10);
      iVar35 = iVar35 + (int)sVar29 * (int)(short)((ulong)uVar42 >> 0x20);
      iVar36 = iVar36 + (int)sVar39 * (int)(short)((ulong)uVar42 >> 0x30);
    } while (iVar43 < iVar33);
  }
  iVar25 = iVar25 + iVar28 + iVar30 + iVar31;
  local_e4 = iVar32 + iVar34 + iVar35 + iVar36;
  *(ssc_i32_u *)(PTR_in_shared_0011bd00 + 0x774) = iVar25;
  if ((int)param_2 < 10) {
    uVar18 = 1;
    iVar32 = iVar25;
  }
  else {
    piVar21 = (ssc_i32_u *)(puVar9 + 0x784);
    puVar17 = (ssc_u64_u *)(uintptr_t)((param_1 + lVar23 * 2));
    uVar18 = 1;
    iVar32 = iVar25;
    do {
      puVar17 = puVar17 + -1;
      uVar37 = *puVar17;
      uVar18 = uVar18 + 4;
      uVar42 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar17)) + (long)iVar33 * 2));
      sVar12 = (short)((ulong)uVar37 >> 0x10);
      sVar13 = (short)((ulong)uVar37 >> 0x20);
      sVar29 = (short)((ulong)uVar37 >> 0x30);
      sVar39 = (short)((ulong)uVar42 >> 0x10);
      sVar40 = (short)((ulong)uVar42 >> 0x20);
      sVar41 = (short)((ulong)uVar42 >> 0x30);
      iVar34 = ((int)sVar29 * (int)sVar29 - (int)sVar41 * (int)sVar41) + iVar32;
      iVar35 = iVar34 + ((int)sVar13 * (int)sVar13 - (int)sVar40 * (int)sVar40);
      iVar36 = iVar35 + ((int)sVar12 * (int)sVar12 - (int)sVar39 * (int)sVar39);
      iVar32 = iVar36 + ((int)(short)uVar37 * (int)(short)uVar37 -
                        (int)(short)uVar42 * (int)(short)uVar42);
      piVar21[-3] = iVar34;
      piVar21[-2] = iVar35;
      piVar21[-1] = iVar36;
      *piVar21 = iVar32;
      piVar21 = piVar21 + 4;
    } while ((long)uVar18 < (long)(iVar27 + -3));
  }
  if ((int)uVar18 <= iVar27) {
    lVar22 = (ulong)(iVar27 + 1) - (uVar18 & 0xffffffff);
    psVar19 = (ssc_i16_u *)(uintptr_t)((param_1 + (lVar23 - (uVar18 & 0xffffffff)) * 2));
    piVar21 = (ssc_i32_u *)(puVar9 + (uVar18 & 0xffffffff) * 4 + 0x774);
    do {
      sVar12 = *psVar19;
      lVar22 = lVar22 + -1;
      psVar1 = psVar19 + iVar33;
      psVar19 = psVar19 + -1;
      iVar32 = (iVar32 + (int)sVar12 * (int)sVar12) - (int)*psVar1 * (int)*psVar1;
      *piVar21 = iVar32;
      piVar21 = piVar21 + 1;
    } while (lVar22 != 0);
  }
  local_f0 = (long)*(ssc_i32_u *)(puVar9 + (long)(int)uVar15 * 4 + 0x774);
  iVar35 = (int)((ulong)(local_f0 * iVar25) >> 0x20);
  iVar32 = iVar35 + 1;
  uVar7 = 0x11 - (int)LZCOUNT(iVar32);
  iVar34 = iVar32 >> (uVar7 & 0x1e);
  if ((int)(uVar7 & 0xfffffffe) < 1) {
    iVar34 = iVar32 << (ulong)(-(uVar7 & 0xfffffffe) & 0x1f);
  }
  sVar12 = ssc_rsqrt_norm(iVar34);
  sVar13 = ssc_rsqrt_norm(iVar34);
  uVar7 = local_e4 & 0xffff;
  uVar2 = (int)local_e4 >> 0xf & 0xfffffffe;
  iVar36 = uVar2 * (int)sVar12 + ((int)(uVar7 * (int)sVar13) >> 0xf);
  if (iVar35 == -1) {
    if (iVar36 < 0x8000) {
      sVar12 = ssc_rsqrt_norm(iVar34);
      sVar13 = ssc_rsqrt_norm(iVar34);
      local_e8 = uVar2 * (int)sVar12 + ((int)(uVar7 * (int)sVar13) >> 0xf);
      goto LAB_00112c58;
    }
  }
  else {
    uVar14 = (0x1f - (int)LZCOUNT(iVar32) >> 1) + 1;
    if (iVar36 >> (uVar14 & 0x1f) < 0x8000) {
      sVar12 = ssc_rsqrt_norm(iVar34);
      sVar13 = ssc_rsqrt_norm(iVar34);
      local_e8 = (int)(uVar2 * (int)sVar12 + ((int)(uVar7 * (int)sVar13) >> 0xf)) >> (uVar14 & 0x1f)
      ;
      goto LAB_00112c58;
    }
  }
  local_e8 = 0x7fff;
LAB_00112c58:
  iVar34 = (int)(short)local_e8;
  lVar23 = 2;
  iVar32 = 2;
  uVar7 = uVar15;
  do {
    iVar36 = (int)lVar23;
    iVar35 = iVar36 << 1;
    uVar2 = 0;
    if (iVar35 != 0) {
      uVar2 = (int)(uVar15 * 2 + iVar36) / iVar35;
    }
    if ((int)uVar2 < (int)param_3 >> 1) break;
    if (lVar23 == 2) {
      uVar14 = uVar15;
      if ((int)(uVar2 + uVar15) <= iVar27) {
        uVar14 = uVar2 + uVar15;
      }
    }
    else {
      uVar14 = 0;
      if (iVar35 != 0) {
        uVar14 = (int)(iVar36 + uVar15 * 2 * (int)*(ssc_i16_u *)(&UNK_00105d58 + lVar23 * 2)) / iVar35;
      }
    }
    iVar43 = 0;
    iVar44 = 0;
    iVar45 = 0;
    iVar46 = 0;
    iVar35 = 0;
    iVar28 = 0;
    iVar30 = 0;
    iVar31 = 0;
    if (1 < param_4) {
      iVar16 = 0;
      iVar35 = 0;
      iVar28 = 0;
      iVar30 = 0;
      iVar31 = 0;
      iVar43 = 0;
      iVar44 = 0;
      iVar45 = 0;
      iVar46 = 0;
      puVar17 = puVar20;
      do {
        uVar42 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar17)) + (long)(int)uVar2 * -2));
        iVar16 = iVar16 + 4;
        uVar38 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar17)) + (long)(int)uVar14 * -2));
        uVar37 = *puVar17;
        puVar17 = puVar17 + 1;
        sVar12 = (short)((ulong)uVar37 >> 0x10);
        sVar13 = (short)((ulong)uVar37 >> 0x20);
        sVar29 = (short)((ulong)uVar37 >> 0x30);
        iVar35 = iVar35 + (int)(short)uVar37 * (int)(short)uVar42;
        iVar28 = iVar28 + (int)sVar12 * (int)(short)((ulong)uVar42 >> 0x10);
        iVar30 = iVar30 + (int)sVar13 * (int)(short)((ulong)uVar42 >> 0x20);
        iVar31 = iVar31 + (int)sVar29 * (int)(short)((ulong)uVar42 >> 0x30);
        iVar43 = iVar43 + (int)(short)uVar37 * (int)(short)uVar38;
        iVar44 = iVar44 + (int)sVar12 * (int)(short)((ulong)uVar38 >> 0x10);
        iVar45 = iVar45 + (int)sVar13 * (int)(short)((ulong)uVar38 >> 0x20);
        iVar46 = iVar46 + (int)sVar29 * (int)(short)((ulong)uVar38 >> 0x30);
      } while (iVar16 < iVar33);
    }
    iVar5 = *(ssc_i32_u *)(puVar9 + (long)(int)uVar2 * 4 + 0x774);
    iVar6 = *(ssc_i32_u *)(puVar9 + (long)(int)uVar14 * 4 + 0x774);
    iVar24 = (int)((ulong)(((long)iVar6 + (long)iVar5) * (long)iVar25) >> 0x1f);
    iVar16 = iVar24 + 1;
    uVar14 = 0x11 - (int)LZCOUNT(iVar16);
    iVar4 = iVar16 >> (uVar14 & 0x1e);
    if ((int)(uVar14 & 0xfffffffe) < 1) {
      iVar4 = iVar16 << (ulong)(-(uVar14 & 0xfffffffe) & 0x1f);
    }
    sVar12 = ssc_rsqrt_norm(iVar4);
    sVar13 = ssc_rsqrt_norm(iVar4);
    uVar26 = iVar43 + iVar44 + iVar45 + iVar46 + iVar28 + iVar35 + iVar30 + iVar31;
    uVar14 = uVar26 & 0xffff;
    uVar3 = (int)uVar26 >> 0xf & 0xfffffffe;
    iVar35 = uVar3 * (int)sVar12 + ((int)(uVar14 * (int)sVar13) >> 0xf);
    if (iVar24 == -1) {
      if (iVar35 < 0x8000) {
        sVar12 = ssc_rsqrt_norm(iVar4);
        sVar13 = ssc_rsqrt_norm(iVar4);
        uVar14 = uVar3 * (int)sVar12 + ((int)(uVar14 * (int)sVar13) >> 0xf);
      }
      else {
LAB_00112eb0:
        uVar14 = 0x7fff;
      }
    }
    else {
      uVar8 = (0x1f - (int)LZCOUNT(iVar16) >> 1) + 1;
      if (0x7fff < iVar35 >> (uVar8 & 0x1f)) goto LAB_00112eb0;
      sVar12 = ssc_rsqrt_norm(iVar4);
      sVar13 = ssc_rsqrt_norm(iVar4);
      uVar14 = (int)(uVar3 * (int)sVar12 + ((int)(uVar14 * (int)sVar13) >> 0xf)) >> (uVar8 & 0x1f);
    }
    uVar8 = uVar2 - (param_6 >> 1);
    uVar3 = -uVar8;
    if (-1 < (int)uVar8) {
      uVar3 = uVar8;
    }
    sVar12 = param_7;
    if (1 < uVar3) {
      if (uVar3 == 2) {
        sVar12 = param_7 >> 1;
        if ((int)uVar15 <= iVar32 * iVar36 * 5) {
          sVar12 = 0;
        }
      }
      else {
        sVar12 = 0;
      }
    }
    iVar35 = (int)sVar12;
    if ((int)uVar2 < ((int)param_3 >> 1) * 3) {
      iVar36 = (iVar34 * 0x6ccd >> 0xf) - iVar35;
      iVar28 = 0x3333;
      bVar10 = SBORROW4(iVar36,0x3333);
      iVar35 = iVar36 + -0x3333;
      bVar11 = iVar36 == 0x3333;
LAB_00112f74:
      if (bVar11 || iVar35 < 0 != bVar10) {
        iVar36 = iVar28;
      }
    }
    else {
      iVar36 = (iVar34 * 0x599a >> 0xf) - iVar35;
      if (iVar36 < 0x2667) {
        iVar36 = 0x2666;
      }
      if ((int)uVar2 < (int)(param_3 & 0xfffffffe)) {
        iVar36 = (iVar34 * 0x7333 >> 0xf) - iVar35;
        iVar28 = 0x4000;
        bVar10 = SBORROW4(iVar36,0x4000);
        iVar35 = iVar36 + -0x4000;
        bVar11 = iVar36 == 0x4000;
        goto LAB_00112f74;
      }
    }
    if (iVar36 * 0x10000 < (int)(uVar14 * 0x10000)) {
      local_f0 = (long)iVar6 + (long)iVar5;
      local_e8 = uVar14;
      local_e4 = uVar26;
      uVar7 = uVar2;
    }
    lVar23 = lVar23 + 1;
    iVar32 = iVar32 + 1;
  } while (lVar23 != 0x10);
  local_e4 = local_e4 & ((int)local_e4 >> 0x1f ^ 0xffffffffU);
  if ((int)local_e4 < (int)local_f0) {
    extraout_var = (uint)ssc_frac_div32(local_e4,(int)local_f0 + 1) >> 16;
    uVar15 = extraout_var & 0xffff;
  }
  else {
    uVar15 = 0x7fff;
  }
  iVar27 = 0;
  iVar32 = 0;
  iVar34 = 0;
  iVar35 = 0;
  iVar31 = 0;
  iVar43 = 0;
  iVar44 = 0;
  iVar45 = 0;
  iVar36 = 0;
  iVar25 = 0;
  iVar28 = 0;
  iVar30 = 0;
  if (1 < param_4) {
    iVar46 = 0;
    iVar36 = 0;
    iVar25 = 0;
    iVar28 = 0;
    iVar30 = 0;
    iVar31 = 0;
    iVar43 = 0;
    iVar44 = 0;
    iVar45 = 0;
    iVar27 = 0;
    iVar32 = 0;
    iVar34 = 0;
    iVar35 = 0;
    do {
      puVar17 = (ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar20)) + (long)(int)uVar7 * -2));
      iVar46 = iVar46 + 4;
      uVar37 = *puVar20;
      uVar42 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar17)) + 2));
      uVar38 = *puVar17;
      uVar47 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((puVar17)) + -2));
      sVar12 = (short)uVar37;
      sVar13 = (short)((ulong)uVar37 >> 0x10);
      sVar29 = (short)((ulong)uVar37 >> 0x20);
      sVar39 = (short)((ulong)uVar37 >> 0x30);
      iVar36 = iVar36 + (int)sVar12 * (int)(short)uVar42;
      iVar25 = iVar25 + (int)sVar13 * (int)(short)((ulong)uVar42 >> 0x10);
      iVar28 = iVar28 + (int)sVar29 * (int)(short)((ulong)uVar42 >> 0x20);
      iVar30 = iVar30 + (int)sVar39 * (int)(short)((ulong)uVar42 >> 0x30);
      iVar31 = iVar31 + (int)sVar12 * (int)(short)uVar38;
      iVar43 = iVar43 + (int)sVar13 * (int)(short)((ulong)uVar38 >> 0x10);
      iVar44 = iVar44 + (int)sVar29 * (int)(short)((ulong)uVar38 >> 0x20);
      iVar45 = iVar45 + (int)sVar39 * (int)(short)((ulong)uVar38 >> 0x30);
      iVar27 = iVar27 + (int)sVar12 * (int)(short)uVar47;
      iVar32 = iVar32 + (int)sVar13 * (int)(short)((ulong)uVar47 >> 0x10);
      iVar34 = iVar34 + (int)sVar29 * (int)(short)((ulong)uVar47 >> 0x20);
      iVar35 = iVar35 + (int)sVar39 * (int)(short)((ulong)uVar47 >> 0x30);
      puVar20 = puVar20 + 1;
    } while (iVar46 < iVar33);
  }
  iVar33 = iVar36 + iVar25 + iVar28 + iVar30;
  iVar36 = iVar31 + iVar43 + iVar44 + iVar45;
  iVar27 = iVar27 + iVar32 + iVar34 + iVar35;
  uVar2 = iVar36 - iVar33;
  if ((int)(((int)uVar2 >> 0x10) * 0xb334 + ((uVar2 & 0xffff) * 0x599a >> 0xf)) < iVar27 - iVar33) {
    iVar27 = 1;
  }
  else {
    uVar2 = iVar36 - iVar27;
    iVar27 = -(uint)((int)(((int)uVar2 >> 0x10) * 0xb334 + ((uVar2 & 0xffff) * 0x599a >> 0xf)) <
                    iVar33 - iVar27);
  }
  if ((short)uVar15 <= (short)local_e8) {
    local_e8 = uVar15;
  }
  uVar15 = iVar27 + uVar7 * 2;
  if ((int)param_3 <= (int)uVar15) {
    param_3 = uVar15;
  }
  *param_5 = param_3;
  return local_e8;
}


/* ==================================================================== */
/* Function: ssc_pitch_xcorr_c2 @ 001130dc */
/* ==================================================================== */

int ssc_pitch_xcorr_c2(ssc_u64_u *param_1,long param_2,long param_3,int param_4,int param_5)

{
  ssc_u64_u *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  ulong uVar6;
  undefined1 (*pauVar7) [16];
  ulong uVar8;
  undefined1 (*pauVar9) [16];
  ssc_u64_u *puVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  short sVar31;
  short sVar32;
  short sVar33;
  short sVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  short sVar37;
  short sVar39;
  short sVar40;
  undefined8 uVar38;
  short sVar41;
  undefined8 uVar42;
  vec128_t auVar43;
  vec128_t auVar44;
  vec128_t auVar45;

  if (param_5 < 4) {
    return 1;
  }
  iVar2 = param_4 >> 3;
  uVar6 = 0;
  if (iVar2 < 2) {
    iVar2 = 1;
  }
  pauVar7 = (undefined1 (*) [16])(uintptr_t)((param_2 + 0x10));
  iVar5 = 1;
  do {
    iVar15 = 0;
    iVar16 = 0;
    iVar19 = 0;
    iVar20 = 0;
    iVar27 = 0;
    iVar28 = 0;
    iVar23 = 0;
    iVar24 = 0;
    iVar25 = iVar23;
    iVar26 = iVar24;
    iVar29 = iVar27;
    iVar30 = iVar28;
    iVar21 = iVar19;
    iVar22 = iVar20;
    iVar17 = iVar15;
    iVar18 = iVar16;
    if (7 < param_4) {
      puVar1 = (ssc_u64_u *)(uintptr_t)((param_2 + uVar6 * 2));
      iVar23 = 0;
      iVar24 = 0;
      iVar25 = 0;
      iVar26 = 0;
      iVar27 = 0;
      iVar28 = 0;
      iVar29 = 0;
      iVar30 = 0;
      iVar19 = 0;
      iVar20 = 0;
      iVar21 = 0;
      iVar22 = 0;
      uVar35 = *puVar1;
      sVar31 = (short)uVar35;
      sVar32 = (short)((ulong)uVar35 >> 0x10);
      sVar33 = (short)((ulong)uVar35 >> 0x20);
      sVar34 = (short)((ulong)uVar35 >> 0x30);
      iVar15 = 0;
      iVar16 = 0;
      iVar17 = 0;
      iVar18 = 0;
      pauVar9 = pauVar7;
      puVar10 = param_1;
      uVar35 = puVar1[1];
      iVar3 = iVar2;
      do {
        puVar4 = *pauVar9;
        uVar36 = *(ssc_u64_u *)*pauVar9;
        uVar42 = puVar10[1];
        uVar38 = *puVar10;
        iVar3 = iVar3 + -1;
        auVar43._2_2_ = sVar32;
        auVar43._0_2_ = sVar31;
        auVar43._4_2_ = sVar33;
        auVar43._6_2_ = sVar34;
        auVar43._8_8_ = uVar35;
        auVar43 = NEON_ext(auVar43,*(vec128_t *)*pauVar9,2,1);
        auVar44._2_2_ = sVar32;
        auVar44._0_2_ = sVar31;
        auVar44._4_2_ = sVar33;
        auVar44._6_2_ = sVar34;
        auVar44._8_8_ = uVar35;
        auVar44 = NEON_ext(auVar44,*(vec128_t *)*pauVar9,4,1);
        auVar45._2_2_ = sVar32;
        auVar45._0_2_ = sVar31;
        auVar45._4_2_ = sVar33;
        auVar45._6_2_ = sVar34;
        auVar45._8_8_ = uVar35;
        auVar45 = NEON_ext(auVar45,*(vec128_t *)*pauVar9,6,1);
        sVar37 = (short)uVar38;
        sVar39 = (short)((ulong)uVar38 >> 0x10);
        sVar40 = (short)((ulong)uVar38 >> 0x20);
        sVar41 = (short)((ulong)uVar38 >> 0x30);
        sVar11 = (short)uVar42;
        sVar12 = (short)((ulong)uVar42 >> 0x10);
        sVar13 = (short)((ulong)uVar42 >> 0x20);
        sVar14 = (short)((ulong)uVar42 >> 0x30);
        iVar23 = iVar23 + (int)sVar37 * (int)sVar31 + (int)sVar11 * (int)(short)uVar35;
        iVar24 = iVar24 + (int)sVar39 * (int)sVar32 +
                 (int)sVar12 * (int)(short)((ulong)uVar35 >> 0x10);
        iVar25 = iVar25 + (int)sVar40 * (int)sVar33 +
                 (int)sVar13 * (int)(short)((ulong)uVar35 >> 0x20);
        iVar26 = iVar26 + (int)sVar41 * (int)sVar34 +
                 (int)sVar14 * (int)(short)((ulong)uVar35 >> 0x30);
        iVar27 = iVar27 + (int)sVar37 * (int)auVar43._0_2_ + (int)sVar11 * (int)auVar43._8_2_;
        iVar28 = iVar28 + (int)sVar39 * (int)auVar43._2_2_ + (int)sVar12 * (int)auVar43._10_2_;
        iVar29 = iVar29 + (int)sVar40 * (int)auVar43._4_2_ + (int)sVar13 * (int)auVar43._12_2_;
        iVar30 = iVar30 + (int)sVar41 * (int)auVar43._6_2_ + (int)sVar14 * (int)auVar43._14_2_;
        iVar19 = iVar19 + (int)sVar37 * (int)auVar44._0_2_ + (int)sVar11 * (int)auVar44._8_2_;
        iVar20 = iVar20 + (int)sVar39 * (int)auVar44._2_2_ + (int)sVar12 * (int)auVar44._10_2_;
        iVar21 = iVar21 + (int)sVar40 * (int)auVar44._4_2_ + (int)sVar13 * (int)auVar44._12_2_;
        iVar22 = iVar22 + (int)sVar41 * (int)auVar44._6_2_ + (int)sVar14 * (int)auVar44._14_2_;
        iVar15 = iVar15 + (int)sVar37 * (int)auVar45._0_2_ + (int)sVar11 * (int)auVar45._8_2_;
        iVar16 = iVar16 + (int)sVar39 * (int)auVar45._2_2_ + (int)sVar12 * (int)auVar45._10_2_;
        iVar17 = iVar17 + (int)sVar40 * (int)auVar45._4_2_ + (int)sVar13 * (int)auVar45._12_2_;
        iVar18 = iVar18 + (int)sVar41 * (int)auVar45._6_2_ + (int)sVar14 * (int)auVar45._14_2_;
        sVar31 = (short)uVar36;
        sVar32 = (short)((ulong)uVar36 >> 0x10);
        sVar33 = (short)((ulong)uVar36 >> 0x20);
        sVar34 = (short)((ulong)uVar36 >> 0x30);
        pauVar9 = pauVar9 + 1;
        puVar10 = puVar10 + 2;
        uVar35 = *(ssc_u64_u *)(puVar4 + 8);
      } while (iVar3 != 0);
    }
    iVar23 = iVar23 + iVar24 + iVar25 + iVar26;
    uVar8 = uVar6 * 4;
    iVar28 = iVar27 + iVar28 + iVar29 + iVar30;
    iVar27 = iVar19 + iVar20 + iVar21 + iVar22;
    uVar6 = uVar6 + 4;
    iVar24 = iVar15 + iVar16 + iVar17 + iVar18;
    *(ssc_i32_u *)(uintptr_t)((param_3 + uVar8)) = iVar23;
    *(ssc_i32_u *)(uintptr_t)((param_3 + (uVar8 | 4))) = iVar28;
    pauVar7 = (undefined1 (*) [16])(*pauVar7 + 8);
    if (iVar23 <= iVar28) {
      iVar23 = iVar28;
    }
    iVar28 = iVar27;
    if (iVar27 <= iVar24) {
      iVar28 = iVar24;
    }
    if (iVar23 <= iVar28) {
      iVar23 = iVar28;
    }
    if (iVar5 <= iVar23) {
      iVar5 = iVar23;
    }
    *(ssc_i32_u *)(uintptr_t)((param_3 + (uVar8 | 8))) = iVar27;
    *(ssc_i32_u *)(uintptr_t)((param_3 + (uVar8 | 0xc))) = iVar24;
  } while (uVar6 < param_5 - 3);
  return iVar5;
}


/* ==================================================================== */
/* Function: ssc_pitch_xcorr_c1 @ 00113204 */
/* ==================================================================== */

undefined8 ssc_pitch_xcorr_c1(long param_1,undefined1 (*param_2) [16],ssc_u64_u *param_3)

{
  undefined1 (*pauVar1) [16];
  vec128_t auVar2;
  long lVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar22;
  int iVar23;
  int iVar24;
  vec128_t auVar21;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  undefined8 uVar29;
  vec128_t auVar30;
  short sVar31;
  short sVar35;
  short sVar36;
  undefined8 uVar32;
  short sVar37;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined4 uVar38;
  undefined8 uVar39;
  vec128_t auVar40;
  vec128_t auVar41;
  vec128_t auVar42;

  iVar8 = 0;
  iVar9 = 0;
  iVar10 = 0;
  iVar11 = 0;
  lVar3 = 0;
  iVar16 = 0;
  iVar17 = 0;
  iVar18 = 0;
  iVar19 = 0;
  iVar20 = 0;
  iVar22 = 0;
  iVar23 = 0;
  iVar24 = 0;
  iVar25 = 0;
  iVar26 = 0;
  iVar27 = 0;
  iVar28 = 0;
  iVar12 = 0;
  iVar13 = 0;
  iVar14 = 0;
  iVar15 = 0;
  auVar30 = *(vec128_t *)*param_2;
  do {
    uVar29 = ((ssc_u64_u *)(uintptr_t)((param_1 + lVar3)))[1];
    uVar32 = *(ssc_u64_u *)(uintptr_t)((param_1 + lVar3));
    pauVar1 = (undefined1 (*) [16])(param_2[1] + lVar3);
    uVar38 = (undefined4)((ulong)*(ssc_u64_u *)(*pauVar1 + 8) >> 0x20);
    lVar3 = lVar3 + 0x10;
    sVar31 = (short)uVar32;
    sVar35 = (short)((ulong)uVar32 >> 0x10);
    sVar36 = (short)((ulong)uVar32 >> 0x20);
    sVar37 = (short)((ulong)uVar32 >> 0x30);
    auVar40._12_4_ = uVar38;
    auVar40._0_12_ = *(unkbyte12 *)*pauVar1;
    auVar40 = NEON_ext(auVar30,auVar40,2,1);
    auVar41._12_4_ = uVar38;
    auVar41._0_12_ = *(unkbyte12 *)*pauVar1;
    auVar41 = NEON_ext(auVar30,auVar41,4,1);
    auVar42._12_4_ = uVar38;
    auVar42._0_12_ = *(unkbyte12 *)*pauVar1;
    auVar42 = NEON_ext(auVar30,auVar42,6,1);
    sVar4 = (short)uVar29;
    sVar5 = (short)((ulong)uVar29 >> 0x10);
    sVar6 = (short)((ulong)uVar29 >> 0x20);
    sVar7 = (short)((ulong)uVar29 >> 0x30);
    iVar8 = iVar8 + (int)sVar31 * (int)auVar30._0_2_ + (int)sVar4 * (int)auVar30._8_2_;
    iVar9 = iVar9 + (int)sVar35 * (int)auVar30._2_2_ + (int)sVar5 * (int)auVar30._10_2_;
    iVar10 = iVar10 + (int)sVar36 * (int)auVar30._4_2_ + (int)sVar6 * (int)auVar30._12_2_;
    iVar11 = iVar11 + (int)sVar37 * (int)auVar30._6_2_ + (int)sVar7 * (int)auVar30._14_2_;
    auVar2._12_4_ = uVar38;
    auVar2._0_12_ = *(unkbyte12 *)*pauVar1;
    auVar30 = NEON_ext(auVar30,auVar2,8,1);
    iVar16 = iVar16 + (int)sVar31 * (int)auVar40._0_2_ + (int)sVar4 * (int)auVar40._8_2_;
    iVar17 = iVar17 + (int)sVar35 * (int)auVar40._2_2_ + (int)sVar5 * (int)auVar40._10_2_;
    iVar18 = iVar18 + (int)sVar36 * (int)auVar40._4_2_ + (int)sVar6 * (int)auVar40._12_2_;
    iVar19 = iVar19 + (int)sVar37 * (int)auVar40._6_2_ + (int)sVar7 * (int)auVar40._14_2_;
    iVar20 = iVar20 + (int)sVar31 * (int)auVar41._0_2_ + (int)sVar4 * (int)auVar41._8_2_;
    iVar22 = iVar22 + (int)sVar35 * (int)auVar41._2_2_ + (int)sVar5 * (int)auVar41._10_2_;
    iVar23 = iVar23 + (int)sVar36 * (int)auVar41._4_2_ + (int)sVar6 * (int)auVar41._12_2_;
    iVar24 = iVar24 + (int)sVar37 * (int)auVar41._6_2_ + (int)sVar7 * (int)auVar41._14_2_;
    iVar25 = iVar25 + (int)sVar31 * (int)auVar42._0_2_ + (int)sVar4 * (int)auVar42._8_2_;
    iVar26 = iVar26 + (int)sVar35 * (int)auVar42._2_2_ + (int)sVar5 * (int)auVar42._10_2_;
    iVar27 = iVar27 + (int)sVar36 * (int)auVar42._4_2_ + (int)sVar6 * (int)auVar42._12_2_;
    iVar28 = iVar28 + (int)sVar37 * (int)auVar42._6_2_ + (int)sVar7 * (int)auVar42._14_2_;
    iVar12 = iVar12 + (int)sVar31 * (int)auVar30._0_2_ + (int)sVar4 * (int)auVar30._8_2_;
    iVar13 = iVar13 + (int)sVar35 * (int)auVar30._2_2_ + (int)sVar5 * (int)auVar30._10_2_;
    iVar14 = iVar14 + (int)sVar36 * (int)auVar30._4_2_ + (int)sVar6 * (int)auVar30._12_2_;
    iVar15 = iVar15 + (int)sVar37 * (int)auVar30._6_2_ + (int)sVar7 * (int)auVar30._14_2_;
    auVar30 = *(vec128_t *)*pauVar1;
  } while ((int)lVar3 != 0x750);
  uVar29 = *(ssc_u64_u *)(uintptr_t)((param_1 + 0x750));
  uVar33 = *(ssc_u64_u *)param_2[0x75];
  uVar32 = *(ssc_u64_u *)(param_2[0x75] + 2);
  uVar39 = *(ssc_u64_u *)(param_2[0x75] + 4);
  sVar4 = (short)uVar29;
  sVar5 = (short)((ulong)uVar29 >> 0x10);
  sVar6 = (short)((ulong)uVar29 >> 0x20);
  sVar7 = (short)((ulong)uVar29 >> 0x30);
  uVar34 = *(ssc_u64_u *)(param_2[0x75] + 6);
  uVar29 = *(ssc_u64_u *)(param_2[0x75] + 8);
  iVar22 = iVar22 + (int)sVar5 * (int)(short)((ulong)uVar39 >> 0x10);
  iVar23 = iVar23 + (int)sVar6 * (int)(short)((ulong)uVar39 >> 0x20);
  iVar24 = iVar24 + (int)sVar7 * (int)(short)((ulong)uVar39 >> 0x30);
  iVar26 = iVar26 + (int)sVar5 * (int)(short)((ulong)uVar34 >> 0x10);
  iVar27 = iVar27 + (int)sVar6 * (int)(short)((ulong)uVar34 >> 0x20);
  iVar28 = iVar28 + (int)sVar7 * (int)(short)((ulong)uVar34 >> 0x30);
  auVar21._0_4_ = iVar20 + (int)sVar4 * (int)(short)uVar39 + iVar22 + iVar23 + iVar24;
  auVar21._4_4_ = iVar22 * 2 + iVar23 + iVar24;
  auVar21._8_4_ = iVar23 * 2 + iVar22 + iVar24;
  auVar21._12_4_ = iVar24 * 2 + iVar22 + iVar23;
  auVar30._4_4_ = iVar25 + (int)sVar4 * (int)(short)uVar34 + iVar26 + iVar27 + iVar28;
  auVar30._0_4_ = auVar21._0_4_;
  auVar30._8_4_ = auVar21._4_4_;
  auVar30._12_4_ = iVar26 * 2 + iVar27 + iVar28;
  auVar30 = NEON_ext(auVar21,auVar30,8,1);
  param_3[1] = auVar30._8_8_;
  *param_3 = CONCAT44(iVar16 + (int)sVar4 * (int)(short)uVar32 +
                      iVar17 + (int)sVar5 * (int)(short)((ulong)uVar32 >> 0x10) +
                      iVar18 + (int)sVar6 * (int)(short)((ulong)uVar32 >> 0x20) +
                      iVar19 + (int)sVar7 * (int)(short)((ulong)uVar32 >> 0x30),
                      iVar8 + (int)sVar4 * (int)(short)uVar33 +
                      iVar9 + (int)sVar5 * (int)(short)((ulong)uVar33 >> 0x10) +
                      iVar10 + (int)sVar6 * (int)(short)((ulong)uVar33 >> 0x20) +
                      iVar11 + (int)sVar7 * (int)(short)((ulong)uVar33 >> 0x30));
  *(ssc_i32_u *)(param_3 + 2) =
       iVar12 + (int)sVar4 * (int)(short)uVar29 +
       iVar13 + (int)sVar5 * (int)(short)((ulong)uVar29 >> 0x10) +
       iVar14 + (int)sVar6 * (int)(short)((ulong)uVar29 >> 0x20) +
       iVar15 + (int)sVar7 * (int)(short)((ulong)uVar29 >> 0x30);
  return 0;
}


/* ==================================================================== */
/* Function: ssc_quant_coarse_energy @ 00113340 */
/* ==================================================================== */

void ssc_quant_coarse_energy
               (long param_1,undefined8 param_2,int param_3,long param_4,long param_5,uint param_6,
               undefined8 param_7,ssc_i64_u *param_8,int param_9,int param_10,ssc_u32_u *param_11)

{
  bool bVar1;
  void *__src;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  vec128_t auVar7;
  vec128_t auVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ssc_i16_u *psVar11;
  ssc_i16_u *psVar12;
  ssc_i16_u *psVar13;
  ssc_i16_u *psVar14;
  ssc_i16_u *psVar15;
  ssc_i16_u *psVar16;
  ssc_i16_u *psVar17;
  ssc_i16_u *psVar18;
  ssc_i16_u *psVar19;
  ssc_i16_u *psVar20;
  ssc_i16_u *psVar21;
  ssc_i16_u *psVar22;
  ssc_i16_u *psVar23;
  ssc_i16_u *psVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  ulong uVar28;
  long lVar29;
  ulong uVar30;
  ssc_i16_u *psVar31;
  ssc_u64_u *puVar32;
  ssc_i16_u *psVar33;
  ulong uVar34;
  ssc_i64_u *plVar35;
  long lVar36;
  uint uVar37;
  long lVar38;
  int iVar39;
  long lVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  int iVar52;
  short sVar53;
  short sVar54;
  short sVar55;
  short sVar56;
  short sVar57;
  short sVar58;
  short sVar59;
  short sVar60;
  short sVar61;
  short sVar62;
  short sVar63;
  short sVar64;
  short sVar65;
  short sVar66;
  short sVar67;
  short sVar68;
  vec128_t auVar69;
  vec128_t auVar70;
  undefined1 auStack_228 [152];
  long local_190;
  long lStack_188;
  long local_180;
  long local_170;
  long lStack_168;
  long local_160;
  long local_150;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined8 uStack_13c;
  undefined1 auStack_130 [92];
  undefined1 auStack_d4 [92];
  long local_78;

  uVar37 = param_3 * 2;
  uVar28 = (ulong)uVar37;
  lVar4 = tpidr_el0;
  local_78 = *(ssc_i64_u *)(uintptr_t)((lVar4 + 0x28));
  if ((int)uVar37 < 1) {
    uVar37 = 0;
  }
  else {
    if (uVar37 < 0x10) {
      uVar30 = 0;
      uVar37 = 0;
LAB_00113440:
      lVar29 = uVar28 - uVar30;
      psVar31 = (ssc_i16_u *)(uintptr_t)((param_5 + uVar30 * 2));
      psVar33 = (ssc_i16_u *)(uintptr_t)((param_4 + uVar30 * 2));
      do {
        lVar29 = lVar29 + -1;
        iVar25 = ((int)*psVar33 >> 3) - ((int)*psVar31 >> 3);
        uVar37 = uVar37 + iVar25 * iVar25;
        psVar31 = psVar31 + 1;
        psVar33 = psVar33 + 1;
      } while (lVar29 != 0);
    }
    else {
      uVar30 = uVar28 & 0xfffffff0;
      puVar32 = (ssc_u64_u *)(uintptr_t)((param_4 + 0x10));
      iVar25 = 0;
      iVar27 = 0;
      iVar39 = 0;
      iVar26 = 0;
      psVar31 = (ssc_i16_u *)(uintptr_t)((param_5 + 0x10));
      iVar41 = 0;
      iVar42 = 0;
      iVar43 = 0;
      iVar44 = 0;
      iVar45 = 0;
      iVar46 = 0;
      iVar47 = 0;
      iVar48 = 0;
      iVar49 = 0;
      iVar50 = 0;
      iVar51 = 0;
      iVar52 = 0;
      uVar34 = uVar30;
      do {
        uVar6 = puVar32[-1];
        uVar5 = puVar32[-2];
        uVar10 = puVar32[1];
        uVar9 = *puVar32;
        puVar32 = puVar32 + 4;
        uVar34 = uVar34 - 0x10;
        psVar33 = psVar31 + -8;
        psVar11 = psVar31 + -7;
        psVar12 = psVar31 + -6;
        psVar13 = psVar31 + -5;
        psVar14 = psVar31 + -4;
        psVar15 = psVar31 + -3;
        psVar16 = psVar31 + -2;
        psVar17 = psVar31 + -1;
        sVar61 = *psVar31;
        psVar18 = psVar31 + 1;
        psVar19 = psVar31 + 2;
        psVar20 = psVar31 + 3;
        psVar21 = psVar31 + 4;
        psVar22 = psVar31 + 5;
        psVar23 = psVar31 + 6;
        psVar24 = psVar31 + 7;
        psVar31 = psVar31 + 0x10;
        sVar53 = ((short)uVar5 >> 3) - (*psVar33 >> 3);
        sVar54 = ((short)((ulong)uVar5 >> 0x10) >> 3) - (*psVar11 >> 3);
        sVar55 = ((short)((ulong)uVar5 >> 0x20) >> 3) - (*psVar12 >> 3);
        sVar56 = (short)((long)uVar5 >> 0x33) - (*psVar13 >> 3);
        sVar57 = ((short)uVar6 >> 3) - (*psVar14 >> 3);
        sVar58 = ((short)((ulong)uVar6 >> 0x10) >> 3) - (*psVar15 >> 3);
        sVar59 = ((short)((ulong)uVar6 >> 0x20) >> 3) - (*psVar16 >> 3);
        sVar60 = (short)((long)uVar6 >> 0x33) - (*psVar17 >> 3);
        sVar61 = ((short)uVar9 >> 3) - (sVar61 >> 3);
        sVar62 = ((short)((ulong)uVar9 >> 0x10) >> 3) - (*psVar18 >> 3);
        sVar63 = ((short)((ulong)uVar9 >> 0x20) >> 3) - (*psVar19 >> 3);
        sVar64 = (short)((long)uVar9 >> 0x33) - (*psVar20 >> 3);
        sVar65 = ((short)uVar10 >> 3) - (*psVar21 >> 3);
        sVar66 = ((short)((ulong)uVar10 >> 0x10) >> 3) - (*psVar22 >> 3);
        sVar67 = ((short)((ulong)uVar10 >> 0x20) >> 3) - (*psVar23 >> 3);
        sVar68 = (short)((long)uVar10 >> 0x33) - (*psVar24 >> 3);
        auVar69._2_2_ = sVar54;
        auVar69._0_2_ = sVar53;
        auVar69._4_2_ = sVar55;
        auVar69._6_2_ = sVar56;
        auVar69._8_2_ = sVar57;
        auVar69._10_2_ = sVar58;
        auVar69._12_2_ = sVar59;
        auVar69._14_2_ = sVar60;
        auVar70._2_2_ = sVar54;
        auVar70._0_2_ = sVar53;
        auVar70._4_2_ = sVar55;
        auVar70._6_2_ = sVar56;
        auVar70._8_2_ = sVar57;
        auVar70._10_2_ = sVar58;
        auVar70._12_2_ = sVar59;
        auVar70._14_2_ = sVar60;
        auVar69 = NEON_ext(auVar69,auVar70,8,1);
        iVar25 = iVar25 + (int)sVar53 * (int)sVar53;
        iVar27 = iVar27 + (int)sVar54 * (int)sVar54;
        iVar39 = iVar39 + (int)sVar55 * (int)sVar55;
        iVar26 = iVar26 + (int)sVar56 * (int)sVar56;
        auVar7._2_2_ = sVar62;
        auVar7._0_2_ = sVar61;
        auVar7._4_2_ = sVar63;
        auVar7._6_2_ = sVar64;
        auVar7._8_2_ = sVar65;
        auVar7._10_2_ = sVar66;
        auVar7._12_2_ = sVar67;
        auVar7._14_2_ = sVar68;
        auVar8._2_2_ = sVar62;
        auVar8._0_2_ = sVar61;
        auVar8._4_2_ = sVar63;
        auVar8._6_2_ = sVar64;
        auVar8._8_2_ = sVar65;
        auVar8._10_2_ = sVar66;
        auVar8._12_2_ = sVar67;
        auVar8._14_2_ = sVar68;
        auVar70 = NEON_ext(auVar7,auVar8,8,1);
        iVar45 = iVar45 + (int)sVar61 * (int)sVar61;
        iVar46 = iVar46 + (int)sVar62 * (int)sVar62;
        iVar47 = iVar47 + (int)sVar63 * (int)sVar63;
        iVar48 = iVar48 + (int)sVar64 * (int)sVar64;
        iVar41 = iVar41 + (int)auVar69._0_2_ * (int)auVar69._0_2_;
        iVar42 = iVar42 + (int)auVar69._2_2_ * (int)auVar69._2_2_;
        iVar43 = iVar43 + (int)auVar69._4_2_ * (int)auVar69._4_2_;
        iVar44 = iVar44 + (int)auVar69._6_2_ * (int)auVar69._6_2_;
        iVar49 = iVar49 + (int)auVar70._0_2_ * (int)auVar70._0_2_;
        iVar50 = iVar50 + (int)auVar70._2_2_ * (int)auVar70._2_2_;
        iVar51 = iVar51 + (int)auVar70._4_2_ * (int)auVar70._4_2_;
        iVar52 = iVar52 + (int)auVar70._6_2_ * (int)auVar70._6_2_;
      } while (uVar34 != 0);
      uVar37 = iVar45 + iVar25 + iVar49 + iVar41 + iVar46 + iVar27 + iVar50 + iVar42 +
               iVar47 + iVar39 + iVar51 + iVar43 + iVar48 + iVar26 + iVar52 + iVar44;
      if (uVar30 != uVar28) goto LAB_00113440;
    }
    if (uVar37 >> 0x11 < 0x19) {
      uVar37 = uVar37 >> 0xe;
    }
    else {
      uVar37 = 200;
    }
  }
  local_150 = *param_8;
  param_9 = param_9 * 0x80;
  plVar35 = param_8 + 4;
  if (0x3fff < param_9) {
    param_9 = 0x4000;
  }
  uStack_148 = (undefined4)param_8[1];
  uVar2 = *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0x1c));
  uStack_13c = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0x14));
  uStack_144 = (undefined4)*(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0xc));
  uStack_140 = (undefined4)((ulong)*(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0xc)) >> 0x20);
  iVar25 = (int)param_8[3] + (int)LZCOUNT((int)*plVar35);
  local_160 = param_8[6];
  lStack_168 = param_8[5];
  local_170 = *plVar35;
  iVar27 = iVar25 + -0x20;
  uVar3 = iVar25 - 0x1d;
  SSC_COPY16((uint64_t)(uintptr_t)(auStack_d4),param_5,*(ssc_i32_u *)(uintptr_t)((param_1 + 8)) << 1);
  bVar1 = param_6 > uVar3 || uVar3 == param_6;
  if (param_6 <= uVar3 && uVar3 != param_6) {
    iVar25 = 0;
LAB_00113578:
    iVar26 = ssc_ec_tell_frac((int64_t)(uintptr_t)(param_8));
    lVar29 = param_8[3];
    iVar39 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0x1c));
    lVar36 = *param_8;
    lVar40 = param_8[2];
    lVar38 = param_8[1];
    local_180 = param_8[6];
    lStack_188 = param_8[5];
    local_190 = *plVar35;
    __src = (void *)(uintptr_t)((lVar36 + (ulong)uVar2));
    uVar3 = iVar39 - uVar2;
    if (uVar3 < 0x96) {
      if (uVar3 != 0) {
        memcpy((void *)(auStack_228),(const void *)(__src),(ulong)(iVar39 + ~uVar2) + 1);
      }
    }
    else {
      bVar1 = false;
    }
    *(ssc_u32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0x1c)) = uVar2;
    param_8[1] = CONCAT44(uStack_144,uStack_148);
    *param_8 = local_150;
    *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0x14)) = uStack_13c;
    *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0xc)) = CONCAT44(uStack_140,uStack_144);
    param_8[5] = lStack_168;
    *plVar35 = local_170;
    param_8[6] = local_160;
    iVar27 = FUN_00113734(param_1,param_3,param_4,param_5,param_6,iVar27,(int64_t)(uintptr_t)(&DAT_00105dbf),param_7,
                          (int64_t)(uintptr_t)(param_8),0,(short)param_9);
    if ((!bVar1) ||
       ((iVar27 <= iVar25 &&
        ((iVar25 != iVar27 || (iVar25 = ssc_ec_tell_frac((int64_t)(uintptr_t)(param_8)), iVar25 <= iVar26)))))) {
      uVar37 = uVar37 + ((int)*param_11 >> 2);
      goto LAB_001136f4;
    }
    *param_8 = lVar36;
    *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_8)) + 0x1c)) = iVar39;
    param_8[2] = lVar40;
    param_8[1] = lVar38;
    *(ssc_i32_u *)(param_8 + 3) = (int)lVar29;
    param_8[5] = lStack_188;
    *plVar35 = local_190;
    param_8[6] = local_180;
    if (uVar3 - 1 < 0x95) {
      memcpy(__src,(const void *)(auStack_228),(ulong)uVar3);
    }
    SSC_COPY16(param_5,(uint64_t)(uintptr_t)(auStack_d4),*(ssc_i32_u *)(uintptr_t)((param_1 + 8)) << 1);
    iVar25 = *(ssc_i32_u *)(uintptr_t)((param_1 + 8));
  }
  else {
    iVar25 = FUN_00113734(param_1,param_3,param_4,(int64_t)(uintptr_t)(auStack_d4),param_6,iVar27,(int64_t)(uintptr_t)(&DAT_00105d91),
                          (int64_t)(uintptr_t)(auStack_130),(int64_t)(uintptr_t)(param_8),1,(short)param_9);
    if ((param_10 == 0) || (param_6 < uVar3)) goto LAB_00113578;
    SSC_COPY16(param_5,(uint64_t)(uintptr_t)(auStack_d4),*(ssc_i32_u *)(uintptr_t)((param_1 + 8)) << 1);
    iVar25 = *(ssc_i32_u *)(uintptr_t)((param_1 + 8));
  }
  SSC_COPY16(param_7,(uint64_t)(uintptr_t)(auStack_130),iVar25 << 1);
LAB_001136f4:
  *param_11 = uVar37;
  if (*(ssc_i64_u *)(uintptr_t)((lVar4 + 0x28)) != local_78) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* ==================================================================== */
/* Function: FUN_00113734 @ 00113734 */
/* ==================================================================== */

int FUN_00113734(long param_1,uint param_2,long param_3,long param_4,int param_5,int param_6,long param_7,long param_8,long param_9,int param_10,short param_11)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  long lVar16;
  int iVar17;
  long lVar18;
  ulong uVar19;
  int iVar20;
  int iVar21;
  uint local_6c;
  long local_68;

  lVar9 = tpidr_el0;
  local_68 = *(ssc_i64_u *)(uintptr_t)((lVar9 + 0x28));
  if (param_6 + 3 <= param_5) {
    ssc_ec_enc_bit_logp(param_9,param_10,3);
  }
  iVar15 = -0x199a;
  if (param_10 != 0) {
    iVar15 = -0x1333;
  }
  if ((int)param_2 < 1) {
    iVar11 = 0;
  }
  else {
    iVar5 = (uint)(param_10 == 0) * 0x4000;
    uVar19 = 0;
    iVar20 = 0;
    iVar17 = 0;
    iVar11 = 0;
    iVar21 = param_5 + param_2 * -6 + 0x20;
    do {
      lVar18 = uVar19 * 2;
      sVar4 = *(ssc_i16_u *)(uintptr_t)((param_4 + lVar18));
      iVar12 = (int)sVar4;
      if (sVar4 < -0x23ff) {
        iVar12 = -0x2400;
      }
      iVar12 = iVar17 + (iVar5 * iVar12 >> 8);
      iVar13 = (int)*(ssc_i16_u *)(uintptr_t)((param_3 + lVar18));
      iVar6 = iVar13 * 0x80 - iVar12;
      local_6c = iVar6 + 0x10000 >> 0x11;
      if (iVar6 < -0x10000) {
        iVar14 = (int)sVar4 - (int)param_11;
        if (iVar14 < -0x6fff) {
          iVar14 = -0x7000;
        }
        iVar7 = (short)iVar14 - iVar13;
        if (iVar7 != 0 && iVar13 <= (short)iVar14) {
          local_6c = local_6c + (iVar7 >> 10);
          local_6c = local_6c & (int)local_6c >> 0x1f;
        }
      }
      uVar10 = local_6c;
      iVar13 = *(ssc_i32_u *)(uintptr_t)((param_9 + 0x18)) + (int)LZCOUNT(*(ssc_u32_u *)(uintptr_t)(param_9 + 0x20));
      iVar14 = (param_5 + 0x20) - iVar13;
      if (((uVar19 != 0) && (iVar13 = iVar21 - iVar13, iVar13 < 0x1e)) && (iVar13 < 0x18)) {
        if (0 < (int)local_6c) {
          local_6c = 1;
        }
        if ((iVar13 < 0x10) && ((int)local_6c < 0)) {
          local_6c = 0xffffffff;
        }
      }
      if (iVar14 < 0xf) {
        if (iVar14 < 2) {
          if (iVar14 == 1) {
            local_6c = local_6c & (int)local_6c >> 0x1f;
            ssc_ec_enc_bit_logp(param_9,-local_6c,1);
          }
          else {
            local_6c = 0xffffffff;
          }
        }
        else {
          if (0 < (int)local_6c) {
            local_6c = 1;
          }
          if ((int)local_6c < 0) {
            local_6c = 0xffffffff;
          }
          ssc_ec_enc_icdf(param_9,local_6c << 1 ^ (int)local_6c >> 0x1f,(int64_t)(uintptr_t)(&DAT_00105ded),2);
        }
      }
      else {
        uVar3 = uVar19;
        if (0x13 < uVar19) {
          uVar3 = 0x14;
        }
        ssc_ec_laplace_encode
                  (param_9,(ssc_u32_u *)&local_6c,(ulong)*(byte *)(uintptr_t)((param_7 + (uVar3 << 1 & 0x1fffffffe))) << 7,
                   (ulong)*(byte *)(uintptr_t)((param_7 + (uVar3 << 1 & 0xfffffffe) + 1)) << 6);
      }
      uVar2 = local_6c;
      if ((int)local_6c < -0x7fffff) {
        uVar2 = 0xff800000;
      }
      if (0x7ffffe < (int)uVar2) {
        uVar2 = 0x7fffff;
      }
      iVar14 = uVar10 - uVar2;
      iVar12 = uVar2 * 0x20000 + iVar12;
      iVar13 = -iVar14;
      if (-1 < iVar14) {
        iVar13 = iVar14;
      }
      lVar16 = (uVar19 + (long)*(ssc_i32_u *)(uintptr_t)((param_1 + 8))) * 2;
      if (iVar12 < -0x37ffff) {
        iVar12 = -0x380000;
      }
      *(ssc_i16_u *)(uintptr_t)((param_8 + lVar18)) = (short)(iVar6 + 0x40U >> 7) + (short)local_6c * -0x400;
      *(ssc_i16_u *)(uintptr_t)((param_4 + lVar18)) = (short)(iVar12 + 0x40U >> 7);
      sVar4 = *(ssc_i16_u *)(uintptr_t)((param_4 + lVar16));
      iVar12 = (int)sVar4;
      if (sVar4 < -0x23ff) {
        iVar12 = -0x2400;
      }
      iVar14 = (int)*(ssc_i16_u *)(uintptr_t)((param_3 + lVar16));
      iVar12 = iVar20 + (iVar5 * iVar12 >> 8);
      iVar6 = iVar14 * 0x80 - iVar12;
      local_6c = iVar6 + 0x10000 >> 0x11;
      if (iVar6 < -0x10000) {
        iVar7 = (int)sVar4 - (int)param_11;
        if (iVar7 < -0x6fff) {
          iVar7 = -0x7000;
        }
        iVar8 = (short)iVar7 - iVar14;
        if (iVar8 != 0 && iVar14 <= (short)iVar7) {
          local_6c = local_6c + (iVar8 >> 10);
          local_6c = local_6c & (int)local_6c >> 0x1f;
        }
      }
      uVar10 = local_6c;
      iVar14 = *(ssc_i32_u *)(uintptr_t)((param_9 + 0x18)) + (int)LZCOUNT(*(ssc_u32_u *)(uintptr_t)(param_9 + 0x20));
      iVar7 = (param_5 + 0x20) - iVar14;
      if (((uVar19 != 0) && (iVar14 = iVar21 - iVar14, iVar14 < 0x1e)) && (iVar14 < 0x18)) {
        if (0 < (int)local_6c) {
          local_6c = 1;
        }
        if ((iVar14 < 0x10) && ((int)local_6c < 0)) {
          local_6c = 0xffffffff;
        }
      }
      if (iVar7 < 0xf) {
        if (iVar7 < 2) {
          if (iVar7 == 1) {
            local_6c = local_6c & (int)local_6c >> 0x1f;
            ssc_ec_enc_bit_logp(param_9,-local_6c,1);
          }
          else {
            local_6c = 0xffffffff;
          }
        }
        else {
          if (0 < (int)local_6c) {
            local_6c = 1;
          }
          if ((int)local_6c < 0) {
            local_6c = 0xffffffff;
          }
          ssc_ec_enc_icdf(param_9,local_6c << 1 ^ (int)local_6c >> 0x1f,(int64_t)(uintptr_t)(&DAT_00105ded),2);
        }
      }
      else {
        uVar3 = uVar19;
        if (0x13 < uVar19) {
          uVar3 = 0x14;
        }
        ssc_ec_laplace_encode
                  (param_9,(ssc_u32_u *)&local_6c,(ulong)*(byte *)(uintptr_t)((param_7 + (uVar3 << 1 & 0x1fffffffe))) << 7,
                   (ulong)*(byte *)(uintptr_t)((param_7 + (uVar3 << 1 & 0xfffffffe) + 1)) << 6);
      }
      uVar1 = local_6c;
      if ((int)local_6c < -0x7fffff) {
        uVar1 = 0xff800000;
      }
      lVar18 = (uVar19 + (long)*(ssc_i32_u *)(uintptr_t)((param_1 + 8))) * 2;
      uVar19 = uVar19 + 1;
      iVar17 = uVar2 * 0x20000 + iVar17 + iVar15 * (short)(uVar2 << 2);
      if (0x7ffffe < (int)uVar1) {
        uVar1 = 0x7fffff;
      }
      *(ssc_i16_u *)(uintptr_t)((param_8 + lVar18)) = (short)(iVar6 + 0x40U >> 7) + (short)local_6c * -0x400;
      iVar14 = uVar10 - uVar1;
      iVar6 = -iVar14;
      if (-1 < iVar14) {
        iVar6 = iVar14;
      }
      iVar11 = iVar13 + iVar11 + iVar6;
      iVar12 = uVar1 * 0x20000 + iVar12;
      if (iVar12 < -0x37ffff) {
        iVar12 = -0x380000;
      }
      iVar20 = uVar1 * 0x20000 + iVar20 + iVar15 * (short)(uVar1 << 2);
      iVar21 = iVar21 + 6;
      *(ssc_i16_u *)(uintptr_t)((param_4 + lVar18)) = (short)(iVar12 + 0x40U >> 7);
      local_6c = uVar1;
    } while (param_2 != uVar19);
  }
  return iVar11;
}


/* ==================================================================== */
/* Function: ssc_quant_fine_energy @ 00113c9c */
/* ==================================================================== */

void ssc_quant_fine_energy
               (long param_1,uint param_2,long param_3,long param_4,long param_5,ssc_i64_u *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  ulong uVar6;
  long lVar7;

  if (0 < (int)param_2) {
    uVar6 = 0;
    do {
      uVar2 = *(ssc_u32_u *)(uintptr_t)((param_5 + uVar6 * 4));
      if (0 < (int)uVar2) {
        lVar7 = uVar6 * 2;
        iVar1 = (0x10000 << (ulong)(uVar2 & 0x1f)) >> 0x10;
        uVar2 = *(ssc_i16_u *)(uintptr_t)((param_4 + lVar7)) + 0x200 >> (10 - uVar2 & 0x1f);
        if (iVar1 <= (int)uVar2) {
          uVar2 = iVar1 - 1U;
        }
        uVar2 = uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU);
        ssc_ec_enc_bits(param_6,uVar2,*(ssc_i32_u *)(uintptr_t)((param_5 + uVar6 * 4)));
        uVar3 = *(ssc_u32_u *)(uintptr_t)((param_5 + uVar6 * 4));
        iVar4 = *(ssc_i32_u *)(uintptr_t)((param_1 + 8));
        sVar5 = (short)((uVar2 << 10 | 0x200) >> (ulong)(uVar3 & 0x1f)) + -0x200;
        *(ssc_i16_u *)(uintptr_t)((param_3 + lVar7)) = sVar5 + *(ssc_i16_u *)(uintptr_t)((param_3 + lVar7));
        *(ssc_i16_u *)(uintptr_t)((param_4 + lVar7)) = *(ssc_i16_u *)(uintptr_t)((param_4 + lVar7)) - sVar5;
        uVar2 = *(ssc_i16_u *)(uintptr_t)((param_4 + (uVar6 + (long)iVar4) * 2)) + 0x200 >> (10 - uVar3 & 0x1f);
        if (iVar1 <= (int)uVar2) {
          uVar2 = iVar1 - 1U;
        }
        uVar2 = uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU);
        ssc_ec_enc_bits(param_6,uVar2,*(ssc_i32_u *)(uintptr_t)((param_5 + uVar6 * 4)));
        lVar7 = (uVar6 + (long)*(ssc_i32_u *)(uintptr_t)((param_1 + 8))) * 2;
        sVar5 = (short)((uVar2 << 10 | 0x200) >> (ulong)(*(ssc_u32_u *)(uintptr_t)((param_5 + uVar6 * 4)) & 0x1f)) +
                -0x200;
        *(ssc_i16_u *)(uintptr_t)((param_3 + lVar7)) = sVar5 + *(ssc_i16_u *)(uintptr_t)((param_3 + lVar7));
        *(ssc_i16_u *)(uintptr_t)((param_4 + lVar7)) = *(ssc_i16_u *)(uintptr_t)((param_4 + lVar7)) - sVar5;
      }
      uVar6 = uVar6 + 1;
    } while (param_2 != uVar6);
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_quant_energy_finalise @ 00113e14 */
/* ==================================================================== */

void ssc_quant_energy_finalise
               (long param_1,int param_2,long param_3,long param_4,long param_5,long param_6,
               int param_7,ssc_i64_u *param_8)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;

  if ((0 < param_2) && (1 < param_7)) {
    lVar4 = 0;
    do {
      if ((*(ssc_i32_u *)(uintptr_t)((param_5 + lVar4 * 4)) < 8) && (*(ssc_i32_u *)(uintptr_t)((param_6 + lVar4 * 4)) == 0)) {
        lVar3 = lVar4 * 2;
        uVar2 = ~(uint)*(ssc_u16_u *)(uintptr_t)((param_4 + lVar3)) >> 0xf & 1;
        ssc_ec_enc_bits(param_8,uVar2,1);
        iVar1 = *(ssc_i32_u *)(uintptr_t)((param_1 + 8));
        *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) =
             *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) +
             (short)((int)(uVar2 * 0x400 + -0x200) >> (*(ssc_i32_u *)(uintptr_t)((param_5 + lVar4 * 4)) + 1U & 0x1f));
        uVar2 = ~(uint)*(ssc_u16_u *)(uintptr_t)((param_4 + (lVar4 + iVar1) * 2)) >> 0xf & 1;
        ssc_ec_enc_bits(param_8,uVar2,1);
        param_7 = param_7 + -2;
        lVar3 = (lVar4 + *(ssc_i32_u *)(uintptr_t)((param_1 + 8))) * 2;
        *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) =
             *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) +
             (short)((int)(uVar2 * 0x400 + -0x200) >> (*(ssc_i32_u *)(uintptr_t)((param_5 + lVar4 * 4)) + 1U & 0x1f));
      }
      lVar4 = lVar4 + 1;
    } while ((lVar4 < param_2) && (1 < param_7));
  }
  if ((0 < param_2) && (1 < param_7)) {
    lVar4 = 0;
    do {
      if ((*(ssc_i32_u *)(uintptr_t)((param_5 + lVar4 * 4)) < 8) && (*(ssc_i32_u *)(uintptr_t)((param_6 + lVar4 * 4)) == 1)) {
        lVar3 = lVar4 * 2;
        uVar2 = ~(uint)*(ssc_u16_u *)(uintptr_t)((param_4 + lVar3)) >> 0xf & 1;
        ssc_ec_enc_bits(param_8,uVar2,1);
        iVar1 = *(ssc_i32_u *)(uintptr_t)((param_1 + 8));
        *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) =
             *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) +
             (short)((int)(uVar2 * 0x400 + -0x200) >> (*(ssc_i32_u *)(uintptr_t)((param_5 + lVar4 * 4)) + 1U & 0x1f));
        uVar2 = ~(uint)*(ssc_u16_u *)(uintptr_t)((param_4 + (lVar4 + iVar1) * 2)) >> 0xf & 1;
        ssc_ec_enc_bits(param_8,uVar2,1);
        param_7 = param_7 + -2;
        lVar3 = (lVar4 + *(ssc_i32_u *)(uintptr_t)((param_1 + 8))) * 2;
        *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) =
             *(ssc_i16_u *)(uintptr_t)((param_3 + lVar3)) +
             (short)((int)(uVar2 * 0x400 + -0x200) >> (*(ssc_i32_u *)(uintptr_t)((param_5 + lVar4 * 4)) + 1U & 0x1f));
      }
      lVar4 = lVar4 + 1;
    } while ((lVar4 < param_2) && (1 < param_7));
  }
  return;
}


/* ==================================================================== */
/* Function: ssc_amp2Log2 @ 00114040 */
/* ==================================================================== */

void ssc_amp2Log2(undefined8 param_1,uint param_2,long param_3,long param_4)

{
  ssc_i32_u *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  int iVar10;
  uint uVar11;
  char cVar12;
  int iVar13;
  ssc_i32_u *piVar14;
  ssc_u64_u *puVar15;
  ssc_u64_u *puVar16;
  uint6 uVar17;
  vec128_t auVar18;
  vec128_t auVar19;
  vec128_t auVar20;
  vec128_t auVar21;
  vec128_t auVar22;
  vec128_t auVar23;
  vec128_t auVar24;
  uint6 uVar25;
  undefined8 uVar26;
  uint uVar27;
  undefined8 uVar28;
  vec128_t auVar29;
  vec128_t auVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  uint6 uVar33;
  int iVar34;
  int iVar35;
  ssc_i32_u *piVar36;
  ssc_i32_u *piVar37;
  ssc_i32_u *piVar38;
  ssc_i32_u *piVar39;
  ssc_i32_u *piVar40;
  ssc_i32_u *piVar41;
  char cVar42;
  char cVar43;
  char cVar44;
  char cVar45;
  char cVar46;
  char cVar47;
  char cVar48;
  char cVar49;
  char cVar50;
  char cVar51;
  char cVar52;
  char cVar53;
  char cVar54;
  char cVar55;
  char cVar56;
  ssc_i32_u *piVar57;
  ssc_i32_u *piVar58;
  ssc_i32_u *piVar59;
  undefined *puVar60;
  long lVar61;
  long lVar62;
  ulong uVar63;
  long lVar64;
  ulong uVar65;
  long lVar66;
  long lVar67;
  ssc_u64_u *puVar68;
  ssc_u32_u *puVar69;
  char *pcVar70;
  long lVar71;
  ssc_i16_u *psVar72;
  long lVar73;
  ssc_i16_u *psVar74;
  ulong uVar75;
  ssc_i32_u *piVar76;
  ssc_u64_u *puVar77;
  undefined4 uVar78;
  short sVar79;
  short sVar80;
  vec128_t auVar81;
  vec128_t auVar82;
  vec128_t auVar83;
  uint uVar84;
  vec128_t auVar86;
  vec128_t auVar87;
  vec128_t auVar88;
  int iVar94;
  int iVar95;
  vec128_t auVar89;
  int iVar96;
  vec128_t auVar90;
  vec128_t auVar91;
  vec128_t auVar92;
  vec128_t auVar93;
  char cVar97;
  undefined1 uVar98;
  undefined1 uVar99;
  undefined1 uVar100;
  undefined1 uVar101;
  char cVar102;
  undefined1 uVar103;
  undefined1 uVar104;
  undefined1 uVar105;
  undefined1 uVar106;
  char cVar107;
  undefined1 uVar108;
  undefined1 uVar109;
  undefined1 uVar110;
  undefined1 uVar111;
  char cVar112;
  undefined1 uVar113;
  undefined1 uVar114;
  vec128_t auVar115;
  vec128_t auVar116;
  vec128_t auVar117;
  vec128_t auVar118;
  undefined2 uVar119;
  undefined2 uVar120;
  undefined2 uVar121;
  undefined2 uVar122;
  short sVar123;
  undefined2 uVar124;
  vec128_t auVar125;
  vec128_t auVar126;
  vec128_t auVar127;
  vec128_t auVar128;
  vec128_t auVar129;
  int iVar132;
  uint uVar133;
  vec128_t auVar130;
  vec128_t auVar131;
  uint uVar134;
  int iVar138;
  int iVar139;
  uint uVar140;
  int iVar141;
  vec128_t auVar136;
  vec128_t auVar137;
  int iVar142;
  int iVar143;
  int iVar146;
  int iVar147;
  vec128_t auVar144;
  vec128_t auVar145;
  int iVar148;
  int iVar149;
  int iVar151;
  int iVar152;
  vec128_t auVar150;
  int iVar153;
  int iVar154;
  int iVar155;
  int iVar158;
  int iVar159;
  vec128_t auVar156;
  vec128_t auVar157;
  int iVar160;
  int iVar161;
  int iVar162;
  int iVar163;
  int iVar164;
  int iVar165;
  int iVar166;
  int iVar167;
  int iVar168;
  int iVar169;
  int iVar171;
  int iVar172;
  vec128_t auVar170;
  int iVar173;
  short sVar174;
  int iVar175;
  int iVar179;
  ulong uVar176;
  int iVar180;
  vec128_t auVar177;
  vec128_t auVar178;
  int iVar181;
  int iVar182;
  int iVar183;
  int iVar184;
  int iVar185;
  int iVar186;
  int iVar187;
  undefined4 uVar188;
  int iVar191;
  int iVar192;
  int iVar193;
  vec128_t auVar189;
  int iVar194;
  vec128_t auVar190;
  int iVar195;
  int iVar196;
  int iVar197;
  uint uVar198;
  int iVar203;
  int iVar204;
  short sVar205;
  int iVar206;
  int iVar207;
  uint uVar208;
  short sVar209;
  vec128_t auVar200;
  int iVar210;
  vec128_t auVar201;
  vec128_t auVar202;
  int iVar211;
  int iVar212;
  uint uVar213;
  int iVar218;
  int iVar219;
  vec128_t auVar215;
  vec128_t auVar216;
  vec128_t auVar217;
  int iVar220;
  int iVar221;
  int iVar225;
  int iVar226;
  uint uVar227;
  vec128_t auVar222;
  vec128_t auVar223;
  vec128_t auVar224;
  int iVar228;
  int iVar233;
  int iVar235;
  vec128_t auVar230;
  int iVar229;
  int iVar234;
  int iVar236;
  int iVar237;
  int iVar238;
  vec128_t auVar231;
  vec128_t auVar232;
  int iVar239;
  int iVar241;
  int iVar242;
  uint uVar243;
  vec128_t auVar240;
  int iVar244;
  int iVar245;
  int iVar247;
  int iVar248;
  int iVar249;
  uint uVar250;
  vec128_t auVar246;
  int iVar251;
  vec128_t auVar252;
  vec128_t auVar253;
  vec128_t auVar254;
  int iStack_10c;
  int iStack_104;
  vec128_t auVar85;
  vec128_t auVar135;
  vec128_t auVar199;
  vec128_t auVar214;

  puVar60 = (undefined *)(PTR_ssc_eMeans_tmp_0011bd08);
  uVar11 = param_2;
  if ((int)param_2 < 0) {
    uVar11 = param_2 + 1;
  }
  iVar13 = (int)param_2 % 2;
  ssc_amp2Log2_asm(uVar11 & 0xfffffffe,(ssc_u64_u *)(uintptr_t)((uintptr_t)param_3),(ssc_i16_u *)(uintptr_t)((uintptr_t)param_4),(char *)PTR_ssc_eMeans_tmp_0011bd08);
  if (iVar13 < 1) {
    return;
  }
  lVar61 = (long)(int)param_2;
  lVar73 = (long)iVar13;
  lVar71 = lVar61 - lVar73;
  lVar66 = lVar61;
  if (lVar61 < lVar71 + 1) {
    lVar66 = lVar71 + 1;
  }
  lVar62 = lVar61 + -iVar13;
  uVar63 = (lVar66 + lVar73) - lVar61;
  if (3 < uVar63) {
    puVar2 = (undefined *)(uintptr_t)((param_4 + lVar62 * 2));
    lVar67 = lVar61 - iVar13;
    lVar64 = lVar61 * 2 - (long)iVar13;
    puVar3 = (undefined *)(uintptr_t)((param_3 + lVar62 * 4));
    puVar4 = (undefined *)(uintptr_t)((param_4 + lVar64 * 2));
    lVar66 = lVar61;
    if (lVar61 < lVar67 + 1) {
      lVar66 = lVar67 + 1;
    }
    puVar5 = (undefined *)(uintptr_t)((param_3 + lVar64 * 4));
    puVar6 = (undefined *)(uintptr_t)((param_4 + lVar66 * 2));
    puVar7 = (undefined *)(uintptr_t)((param_3 + lVar66 * 4));
    puVar8 = (undefined *)(uintptr_t)((param_4 + (lVar66 + lVar61) * 2));
    puVar9 = (undefined *)(uintptr_t)((param_3 + (lVar66 + lVar61) * 4));
    if ((((puVar8 <= puVar2 || puVar6 <= puVar4) && (puVar7 <= puVar2 || puVar6 <= puVar3)) &&
        (puVar60 + lVar66 <= puVar2 || puVar6 <= puVar60 + lVar62)) &&
       (((puVar9 <= puVar2 || puVar6 <= puVar5 && (puVar7 <= puVar4 || puVar8 <= puVar3)) &&
        ((puVar60 + lVar66 <= puVar4 || puVar8 <= puVar60 + lVar62 &&
         (puVar9 <= puVar4 || puVar8 <= puVar5)))))) {
      if (uVar63 < 0x10) {
        uVar65 = 0;
      }
      else {
        lVar73 = lVar61 * 2 - lVar73;
        uVar65 = uVar63 & 0xfffffffffffffff0;
        puVar68 = (ssc_u64_u *)(uintptr_t)((param_3 + lVar71 * 4));
        piVar76 = (ssc_i32_u *)(uintptr_t)((param_3 + lVar73 * 4));
        pcVar70 = (char *)(puVar60 + lVar71);
        psVar72 = (ssc_i16_u *)(uintptr_t)((param_4 + lVar71 * 2));
        psVar74 = (ssc_i16_u *)(uintptr_t)((param_4 + lVar73 * 2));
        uVar75 = uVar65;
        do {
          uVar75 = uVar75 - 0x10;
          auVar81._0_4_ = (int)puVar68[4] << 2;
          auVar81._4_4_ = (int)((ulong)puVar68[4] >> 0x20) << 2;
          auVar81._8_4_ = (int)puVar68[5] << 2;
          auVar81._12_4_ = (int)((ulong)puVar68[5] >> 0x20) << 2;
          puVar16 = puVar68 + 1;
          uVar26 = *puVar68;
          puVar77 = puVar68 + 2;
          puVar15 = puVar68 + 3;
          auVar86._0_4_ = (int)puVar68[6] << 2;
          auVar86._4_4_ = (int)((ulong)puVar68[6] >> 0x20) << 2;
          auVar86._8_4_ = (int)puVar68[7] << 2;
          auVar86._12_4_ = (int)((ulong)puVar68[7] >> 0x20) << 2;
          puVar68 = puVar68 + 8;
          iVar10 = LZCOUNT(auVar81._0_4_);
          iVar34 = LZCOUNT(auVar81._4_4_);
          iVar35 = LZCOUNT(auVar81._8_4_);
          iVar179 = LZCOUNT(auVar81._12_4_);
          auVar117._0_4_ = (int)uVar26 << 2;
          auVar117._4_4_ = (int)((ulong)uVar26 >> 0x20) << 2;
          auVar117._8_4_ = (int)*puVar16 << 2;
          auVar117._12_4_ = (int)((ulong)*puVar16 >> 0x20) << 2;
          iVar161 = LZCOUNT(auVar86._0_4_);
          iVar162 = LZCOUNT(auVar86._4_4_);
          iVar163 = LZCOUNT(auVar86._8_4_);
          iVar164 = LZCOUNT(auVar86._12_4_);
          uVar11 = (int)*puVar77 << 2;
          uVar84 = (int)((ulong)*puVar77 >> 0x20) << 2;
          uVar119 = (undefined2)uVar84;
          uVar120 = (undefined2)(uVar84 >> 0x10);
          uVar27 = (int)*puVar15 << 2;
          uVar121 = (undefined2)(uVar27 >> 0x10);
          uVar243 = (int)((ulong)*puVar15 >> 0x20) << 2;
          uVar122 = (undefined2)uVar243;
          uVar124 = (undefined2)(uVar243 >> 0x10);
          auVar125._0_4_ = iVar10 + -0x10;
          auVar125._4_4_ = iVar34 + -0x10;
          auVar125._8_4_ = iVar35 + -0x10;
          auVar125._12_4_ = iVar179 + -0x10;
          iVar183 = LZCOUNT(auVar117._0_4_);
          iVar94 = LZCOUNT(auVar117._4_4_);
          iVar95 = LZCOUNT(auVar117._8_4_);
          iVar96 = LZCOUNT(auVar117._12_4_);
          auVar252._0_4_ = iVar161 + -0x10;
          auVar252._4_4_ = iVar162 + -0x10;
          auVar252._8_4_ = iVar163 + -0x10;
          auVar252._12_4_ = iVar164 + -0x10;
          iVar165 = LZCOUNT(uVar11);
          iVar166 = LZCOUNT(uVar84);
          iVar167 = LZCOUNT(uVar27);
          iVar168 = LZCOUNT(uVar243);
          auVar136._0_4_ = iVar161 + -0x10;
          auVar136._4_4_ = iVar162 + -0x10;
          auVar136._8_4_ = iVar163 + -0x10;
          auVar136._12_4_ = iVar164 + -0x10;
          auVar144._0_4_ = iVar10 + -0x10;
          auVar144._4_4_ = iVar34 + -0x10;
          auVar144._8_4_ = iVar35 + -0x10;
          auVar144._12_4_ = iVar179 + -0x10;
          auVar130._0_4_ = iVar183 + -0x10;
          auVar130._4_4_ = iVar94 + -0x10;
          auVar130._8_4_ = iVar95 + -0x10;
          auVar130._12_4_ = iVar96 + -0x10;
          auVar127._0_4_ = iVar165 + -0x10;
          auVar127._4_4_ = iVar166 + -0x10;
          auVar127._8_4_ = iVar167 + -0x10;
          auVar127._12_4_ = iVar168 + -0x10;
          auVar150._0_4_ = iVar165 + -0x10;
          auVar150._4_4_ = iVar166 + -0x10;
          auVar150._8_4_ = iVar167 + -0x10;
          auVar150._12_4_ = iVar168 + -0x10;
          auVar156._0_4_ = iVar183 + -0x10;
          auVar156._4_4_ = iVar94 + -0x10;
          auVar156._8_4_ = iVar95 + -0x10;
          auVar156._12_4_ = iVar96 + -0x10;
          auVar222._0_4_ = -(uint)(0xffff < auVar86._0_4_);
          auVar222._4_4_ = -(uint)(0xffff < auVar86._4_4_);
          auVar222._8_4_ = -(uint)(0xffff < auVar86._8_4_);
          auVar222._12_4_ = -(uint)(0xffff < auVar86._12_4_);
          auVar230._0_4_ = -(uint)(0xffff < auVar81._0_4_);
          auVar230._4_4_ = -(uint)(0xffff < auVar81._4_4_);
          auVar230._8_4_ = -(uint)(0xffff < auVar81._8_4_);
          auVar230._12_4_ = -(uint)(0xffff < auVar81._12_4_);
          auVar253 = NEON_sshl(auVar86,auVar252,4);
          auVar217 = NEON_sshl(auVar81,auVar125,4);
          auVar137 = NEON_ushl(auVar86,auVar136,4);
          auVar145 = NEON_ushl(auVar81,auVar144,4);
          auVar240._0_4_ = -(uint)(0xffff < uVar11);
          auVar240._4_4_ = -(uint)(0xffff < uVar84);
          auVar240._8_4_ = -(uint)(0xffff < uVar27);
          auVar240._12_4_ = -(uint)(0xffff < uVar243);
          auVar246._0_4_ = -(uint)(0xffff < auVar117._0_4_);
          auVar246._4_4_ = -(uint)(0xffff < auVar117._4_4_);
          auVar246._8_4_ = -(uint)(0xffff < auVar117._8_4_);
          auVar246._12_4_ = -(uint)(0xffff < auVar117._12_4_);
          auVar224._4_2_ = uVar119;
          auVar224._0_4_ = uVar11;
          auVar224._6_2_ = uVar120;
          auVar224._8_2_ = (short)uVar27;
          auVar224._10_2_ = uVar121;
          auVar224._12_2_ = uVar122;
          auVar224._14_2_ = uVar124;
          auVar232 = NEON_sshl(auVar224,auVar127,4);
          auVar202 = NEON_sshl(auVar117,auVar130,4);
          auVar157._4_2_ = uVar119;
          auVar157._0_4_ = uVar11;
          auVar157._6_2_ = uVar120;
          auVar157._8_2_ = (short)uVar27;
          auVar157._10_2_ = uVar121;
          auVar157._12_2_ = uVar122;
          auVar157._14_2_ = uVar124;
          auVar224 = NEON_ushl(auVar157,auVar150,4);
          auVar157 = NEON_ushl(auVar117,auVar156,4);
          auVar137 = vec128_bit(auVar137, auVar137, auVar253, auVar222);
          auVar145 = vec128_bit(auVar145, auVar145, auVar217, auVar230);
          auVar224 = vec128_bit(auVar224, auVar224, auVar232, auVar240);
          auVar157 = vec128_bit(auVar157, auVar157, auVar202, auVar246);
          iVar221 = auVar137._0_4_ * 0x10000 + 0x40000000;
          iVar225 = auVar137._4_4_ * 0x10000 + 0x40000000;
          iVar175 = auVar137._8_4_ * 0x10000 + 0x40000000;
          iVar180 = auVar137._12_4_ * 0x10000 + 0x40000000;
          iVar228 = auVar145._0_4_ * 0x10000 + 0x40000000;
          iVar233 = auVar145._4_4_ * 0x10000 + 0x40000000;
          iVar235 = auVar145._8_4_ * 0x10000 + 0x40000000;
          iVar237 = auVar145._12_4_ * 0x10000 + 0x40000000;
          iVar239 = auVar224._0_4_ * 0x10000 + 0x40000000;
          iVar241 = auVar224._4_4_ * 0x10000 + 0x40000000;
          iVar242 = auVar224._8_4_ * 0x10000 + 0x40000000;
          iVar244 = auVar224._12_4_ * 0x10000 + 0x40000000;
          iVar245 = auVar157._0_4_ * 0x10000 + 0x40000000;
          iVar247 = auVar157._4_4_ * 0x10000 + 0x40000000;
          iVar249 = auVar157._8_4_ * 0x10000 + 0x40000000;
          iVar251 = auVar157._12_4_ * 0x10000 + 0x40000000;
          iVar181 = iVar221 >> 0x10;
          iVar185 = iVar225 >> 0x10;
          iVar187 = iVar175 >> 0x10;
          iVar191 = iVar180 >> 0x10;
          iVar195 = iVar228 >> 0x10;
          iVar193 = iVar233 >> 0x10;
          iVar197 = iVar235 >> 0x10;
          iVar204 = iVar237 >> 0x10;
          iVar207 = iVar239 >> 0x10;
          iVar211 = iVar241 >> 0x10;
          iVar212 = iVar242 >> 0x10;
          iVar218 = iVar244 >> 0x10;
          iVar219 = iVar245 >> 0x10;
          iVar220 = iVar247 >> 0x10;
          iVar226 = iVar249 >> 0x10;
          iVar153 = iVar251 >> 0x10;
          iVar228 = iVar228 >> 0xf;
          iVar233 = iVar233 >> 0xf;
          iVar235 = iVar235 >> 0xf;
          iVar237 = iVar237 >> 0xf;
          iVar221 = iVar221 >> 0xf;
          iVar225 = iVar225 >> 0xf;
          iVar175 = iVar175 >> 0xf;
          iVar180 = iVar180 >> 0xf;
          iVar239 = iVar239 >> 0xf;
          iVar241 = iVar241 >> 0xf;
          iVar242 = iVar242 >> 0xf;
          iVar244 = iVar244 >> 0xf;
          iVar245 = iVar245 >> 0xf;
          iVar247 = iVar247 >> 0xf;
          iVar249 = iVar249 >> 0xf;
          iVar251 = iVar251 >> 0xf;
          iVar248 = ((uint)((((iVar193 * -0x579 >> 0xf) + 0x9f1) * iVar233 + -0x14610000 >> 0x10) *
                           iVar193) >> 0xf) + 0x3d82;
          uVar250 = ((uint)((((iVar197 * -0x579 >> 0xf) + 0x9f1) * iVar235 + -0x14610000 >> 0x10) *
                           iVar197) >> 0xf) + 0x3d82;
          iVar204 = ((uint)((((iVar204 * -0x579 >> 0xf) + 0x9f1) * iVar237 + -0x14610000 >> 0x10) *
                           iVar204) >> 0xf) + 0x3d82;
          iVar138 = ((uint)((((iVar211 * -0x579 >> 0xf) + 0x9f1) * iVar241 + -0x14610000 >> 0x10) *
                           iVar211) >> 0xf) + 0x3d82;
          uVar140 = ((uint)((((iVar212 * -0x579 >> 0xf) + 0x9f1) * iVar242 + -0x14610000 >> 0x10) *
                           iVar212) >> 0xf) + 0x3d82;
          iVar197 = ((uint)((((iVar218 * -0x579 >> 0xf) + 0x9f1) * iVar244 + -0x14610000 >> 0x10) *
                           iVar218) >> 0xf) + 0x3d82;
          iVar132 = ((uint)((((iVar220 * -0x579 >> 0xf) + 0x9f1) * iVar247 + -0x14610000 >> 0x10) *
                           iVar220) >> 0xf) + 0x3d82;
          uVar133 = ((uint)((((iVar226 * -0x579 >> 0xf) + 0x9f1) * iVar249 + -0x14610000 >> 0x10) *
                           iVar226) >> 0xf) + 0x3d82;
          iVar193 = ((uint)((((iVar153 * -0x579 >> 0xf) + 0x9f1) * iVar251 + -0x14610000 >> 0x10) *
                           iVar153) >> 0xf) + 0x3d82;
          uVar84 = (uint)(ushort)((short)((uint)((((iVar195 * -0x579 >> 0xf) + 0x9f1) * iVar228 +
                                                  -0x14610000 >> 0x10) * iVar195) >> 0xf) + 0x3d82);

          auVar116.b[0xc] = (char)iVar204;
          auVar116.b[0xd] = (char)((uint)iVar204 >> 8);
          iVar185 = ((uint)((((iVar185 * -0x579 >> 0xf) + 0x9f1) * iVar225 + -0x14610000 >> 0x10) *
                           iVar185) >> 0xf) + 0x3d82;
          uVar243 = ((uint)((((iVar187 * -0x579 >> 0xf) + 0x9f1) * iVar175 + -0x14610000 >> 0x10) *
                           iVar187) >> 0xf) + 0x3d82;
          iVar187 = ((uint)((((iVar191 * -0x579 >> 0xf) + 0x9f1) * iVar180 + -0x14610000 >> 0x10) *
                           iVar191) >> 0xf) + 0x3d82;
          uVar134 = (uint)(ushort)((short)((uint)((((iVar207 * -0x579 >> 0xf) + 0x9f1) * iVar239 +
                                                   -0x14610000 >> 0x10) * iVar207) >> 0xf) + 0x3d82)
          ;

          auVar135.b[0xc] = (undefined1)iVar197;
          auVar135.b[0xd] = (undefined1)((uint)iVar197 >> 8);
          iVar229 = uVar84 * iVar228 + -0x1a890000;
          iVar234 = (uint)(ushort)(CONCAT15((char)((uint)iVar248 >> 8),
                                            CONCAT14((char)iVar248,uVar84)) >> 0x20) * iVar233 +
                    -0x1a890000;
          iVar236 = (uVar250 & 0xffff) * iVar235 + -0x1a890000;
          iVar238 = (uint)auVar116._12_2_ * iVar237 + -0x1a890000;
          piVar1 = piVar76 + 8;
          piVar57 = piVar76 + 9;
          piVar58 = piVar76 + 10;
          piVar59 = piVar76 + 0xb;
          uVar84 = (uint)(ushort)((short)((uint)((((iVar181 * -0x579 >> 0xf) + 0x9f1) * iVar221 +
                                                  -0x14610000 >> 0x10) * iVar181) >> 0xf) + 0x3d82);

          auVar89.b[0xc] = (char)iVar187;
          auVar89.b[0xd] = (char)((uint)iVar187 >> 8);
          uVar250 = (uint)(ushort)((short)((uint)((((iVar219 * -0x579 >> 0xf) + 0x9f1) * iVar245 +
                                                   -0x14610000 >> 0x10) * iVar219) >> 0xf) + 0x3d82)
          ;

          auVar129.b[0xc] = (undefined1)iVar193;
          auVar129.b[0xd] = (undefined1)((uint)iVar193 >> 8);
          auVar126._0_4_ = piVar76[0xc] << 2;
          auVar126._4_4_ = piVar76[0xd] << 2;
          auVar126._8_4_ = piVar76[0xe] << 2;
          auVar126._12_4_ = piVar76[0xf] << 2;
          iVar197 = uVar84 * iVar221 + -0x1a890000;
          iVar187 = (uint)(ushort)(CONCAT15((char)((uint)iVar185 >> 8),
                                            CONCAT14((char)iVar185,uVar84)) >> 0x20) * iVar225 +
                    -0x1a890000;
          iVar182 = (uVar243 & 0xffff) * iVar175 + -0x1a890000;
          iVar184 = (uint)auVar89._12_2_ * iVar180 + -0x1a890000;
          iVar221 = *piVar76;
          piVar39 = piVar76 + 1;
          piVar40 = piVar76 + 2;
          piVar41 = piVar76 + 3;
          piVar14 = piVar76 + 4;
          piVar36 = piVar76 + 5;
          piVar37 = piVar76 + 6;
          piVar38 = piVar76 + 7;
          piVar76 = piVar76 + 0x10;
          iVar155 = LZCOUNT(auVar126._0_4_);
          iVar158 = LZCOUNT(auVar126._4_4_);
          iVar159 = LZCOUNT(auVar126._8_4_);
          iVar160 = LZCOUNT(auVar126._12_4_);
          auVar254._0_4_ = *piVar1 << 2;
          auVar254._4_4_ = *piVar57 << 2;
          auVar254._8_4_ = *piVar58 << 2;
          auVar254._12_4_ = *piVar59 << 2;
          auVar128._0_4_ = iVar221 << 2;
          auVar128._4_4_ = *piVar39 << 2;
          auVar128._8_4_ = *piVar40 << 2;
          auVar128._12_4_ = *piVar41 << 2;
          auVar131._0_4_ = *piVar14 << 2;
          auVar131._4_4_ = *piVar36 << 2;
          auVar131._8_4_ = *piVar37 << 2;
          auVar131._12_4_ = *piVar38 << 2;
          auVar90._0_4_ = iVar155 + -0x10;
          auVar90._4_4_ = iVar158 + -0x10;
          auVar90._8_4_ = iVar159 + -0x10;
          auVar90._12_4_ = iVar160 + -0x10;
          auVar200._0_4_ = iVar155 + -0x10;
          auVar200._4_4_ = iVar158 + -0x10;
          auVar200._8_4_ = iVar159 + -0x10;
          auVar200._12_4_ = iVar160 + -0x10;
          auVar87._0_4_ = -(uint)(0xffff < auVar126._0_4_);
          auVar87._4_4_ = -(uint)(0xffff < auVar126._4_4_);
          auVar87._8_4_ = -(uint)(0xffff < auVar126._8_4_);
          auVar87._12_4_ = -(uint)(0xffff < auVar126._12_4_);
          iVar149 = LZCOUNT(auVar131._0_4_);
          iVar151 = LZCOUNT(auVar131._4_4_);
          iVar152 = LZCOUNT(auVar131._8_4_);
          iVar154 = LZCOUNT(auVar131._12_4_);
          auVar217 = NEON_sshl(auVar126,auVar90,4);
          auVar232 = NEON_ushl(auVar126,auVar200,4);
          iVar248 = LZCOUNT(auVar128._0_4_);
          iVar139 = LZCOUNT(auVar128._4_4_);
          iVar141 = LZCOUNT(auVar128._8_4_);
          iVar142 = LZCOUNT(auVar128._12_4_);
          iVar143 = LZCOUNT(auVar254._0_4_);
          iVar146 = LZCOUNT(auVar254._4_4_);
          iVar147 = LZCOUNT(auVar254._8_4_);
          iVar148 = LZCOUNT(auVar254._12_4_);
          auVar82._0_4_ = iVar149 + -0x10;
          auVar82._4_4_ = iVar151 + -0x10;
          auVar82._8_4_ = iVar152 + -0x10;
          auVar82._12_4_ = iVar154 + -0x10;
          auVar189._0_4_ = iVar149 + -0x10;
          auVar189._4_4_ = iVar151 + -0x10;
          auVar189._8_4_ = iVar152 + -0x10;
          auVar189._12_4_ = iVar154 + -0x10;
          auVar232 = vec128_bit(auVar232, auVar232, auVar217, auVar87);
          auVar170._0_4_ = iVar143 + -0x10;
          auVar170._4_4_ = iVar146 + -0x10;
          auVar170._8_4_ = iVar147 + -0x10;
          auVar170._12_4_ = iVar148 + -0x10;
          auVar215._0_4_ = iVar248 + -0x10;
          auVar215._4_4_ = iVar139 + -0x10;
          auVar215._8_4_ = iVar141 + -0x10;
          auVar215._12_4_ = iVar142 + -0x10;
          auVar217 = NEON_sshl(auVar131,auVar82,4);
          auVar177._0_4_ = iVar143 + -0x10;
          auVar177._4_4_ = iVar146 + -0x10;
          auVar177._8_4_ = iVar147 + -0x10;
          auVar177._12_4_ = iVar148 + -0x10;
          auVar91._0_4_ = iVar248 + -0x10;
          auVar91._4_4_ = iVar139 + -0x10;
          auVar91._8_4_ = iVar141 + -0x10;
          auVar91._12_4_ = iVar142 + -0x10;
          auVar137 = NEON_ushl(auVar131,auVar189,4);
          auVar118._0_4_ = -(uint)(0xffff < auVar254._0_4_);
          auVar118._4_4_ = -(uint)(0xffff < auVar254._4_4_);
          auVar118._8_4_ = -(uint)(0xffff < auVar254._8_4_);
          auVar118._12_4_ = -(uint)(0xffff < auVar254._12_4_);
          auVar157 = NEON_sshl(auVar254,auVar170,4);
          auVar145 = NEON_sshl(auVar128,auVar215,4);
          auVar224 = NEON_ushl(auVar254,auVar177,4);
          auVar202 = NEON_ushl(auVar128,auVar91,4);
          auVar18._4_4_ = -(uint)(0xffff < auVar131._4_4_);
          auVar18._0_4_ = -(uint)(0xffff < auVar131._0_4_);
          auVar18._8_4_ = -(uint)(0xffff < auVar131._8_4_);
          auVar18._12_4_ = -(uint)(0xffff < auVar131._12_4_);
          auVar217 = vec128_bif(auVar217, auVar137, auVar18);
          iVar218 = auVar232._0_4_ * 0x10000 + 0x40000000;
          iVar219 = auVar232._4_4_ * 0x10000 + 0x40000000;
          iVar226 = auVar232._8_4_ * 0x10000 + 0x40000000;
          iVar153 = auVar232._12_4_ * 0x10000 + 0x40000000;
          auVar224 = vec128_bit(auVar224, auVar224, auVar157, auVar118);
          auVar137._4_2_ = (short)-(uint)(0xffff < auVar128._4_4_);
          auVar137._0_4_ = -(uint)(0xffff < auVar128._0_4_);
          auVar137._6_2_ = (short)(-(uint)(0xffff < auVar128._4_4_) >> 0x10);
          auVar137._8_2_ = (short)-(uint)(0xffff < auVar128._8_4_);
          auVar137._10_2_ = (short)(-(uint)(0xffff < auVar128._8_4_) >> 0x10);
          auVar137._12_2_ = (short)-(uint)(0xffff < auVar128._12_4_);
          auVar137._14_2_ = (short)(-(uint)(0xffff < auVar128._12_4_) >> 0x10);
          auVar202 = vec128_bit(auVar202, auVar202, auVar145, auVar137);
          sVar205 = (short)((uint)iVar218 >> 0x10);
          sVar79 = (short)((uint)iVar219 >> 0x10);
          sVar80 = (short)((uint)iVar226 >> 0x10);
          sVar123 = (short)((uint)iVar153 >> 0x10);
          iVar204 = auVar217._0_4_ * 0x10000 + 0x40000000;
          iVar207 = auVar217._4_4_ * 0x10000 + 0x40000000;
          iVar211 = auVar217._8_4_ * 0x10000 + 0x40000000;
          iVar212 = auVar217._12_4_ * 0x10000 + 0x40000000;
          iVar228 = auVar224._0_4_ * 0x10000 + 0x40000000;
          iVar233 = auVar224._4_4_ * 0x10000 + 0x40000000;
          iVar235 = auVar224._8_4_ * 0x10000 + 0x40000000;
          iVar237 = auVar224._12_4_ * 0x10000 + 0x40000000;
          iVar185 = auVar202._0_4_ * 0x10000 + 0x40000000;
          iVar191 = auVar202._4_4_ * 0x10000 + 0x40000000;
          iVar193 = auVar202._8_4_ * 0x10000 + 0x40000000;
          iVar195 = auVar202._12_4_ * 0x10000 + 0x40000000;
          iVar196 = iVar204 >> 0x10;
          iVar203 = iVar207 >> 0x10;
          iVar206 = iVar211 >> 0x10;
          iVar210 = iVar212 >> 0x10;
          iVar218 = iVar218 >> 0xf;
          iVar219 = iVar219 >> 0xf;
          iVar226 = iVar226 >> 0xf;
          iVar153 = iVar153 >> 0xf;
          iVar186 = iVar228 >> 0x10;
          iVar181 = iVar233 >> 0x10;
          iVar192 = iVar235 >> 0x10;
          iVar194 = iVar237 >> 0x10;
          iVar169 = iVar185 >> 0x10;
          iVar171 = iVar191 >> 0x10;
          iVar172 = iVar193 >> 0x10;
          iVar173 = iVar195 >> 0x10;
          iVar204 = iVar204 >> 0xf;
          iVar207 = iVar207 >> 0xf;
          iVar211 = iVar211 >> 0xf;
          iVar212 = iVar212 >> 0xf;
          iVar228 = iVar228 >> 0xf;
          iVar233 = iVar233 >> 0xf;
          iVar235 = iVar235 >> 0xf;
          iVar237 = iVar237 >> 0xf;
          iVar185 = iVar185 >> 0xf;
          iVar191 = iVar191 >> 0xf;
          iVar193 = iVar193 >> 0xf;
          iVar195 = iVar195 >> 0xf;
          iVar221 = ((iVar196 * -0x579 >> 0xf) + 0x9f1) * iVar204 + -0x14610000;
          iVar225 = ((iVar203 * -0x579 >> 0xf) + 0x9f1) * iVar207 + -0x14610000;
          iVar175 = ((iVar206 * -0x579 >> 0xf) + 0x9f1) * iVar211 + -0x14610000;
          iVar180 = ((iVar210 * -0x579 >> 0xf) + 0x9f1) * iVar212 + -0x14610000;
          cVar97 = (char)(iVar221 >> 0x1f);
          cVar102 = (char)(iVar225 >> 0x1f);
          cVar107 = (char)(iVar175 >> 0x1f);
          cVar112 = (char)(iVar180 >> 0x1f);
          iVar220 = ((uint)((((iVar181 * -0x579 >> 0xf) + 0x9f1) * iVar233 + -0x14610000 >> 0x10) *
                           iVar181) >> 0xf) + 0x3d82;
          uVar243 = ((uint)((((iVar192 * -0x579 >> 0xf) + 0x9f1) * iVar235 + -0x14610000 >> 0x10) *
                           iVar192) >> 0xf) + 0x3d82;
          iVar181 = ((uint)((((iVar194 * -0x579 >> 0xf) + 0x9f1) * iVar237 + -0x14610000 >> 0x10) *
                           iVar194) >> 0xf) + 0x3d82;
          iStack_10c = (int)(CONCAT26(uVar120,CONCAT24(uVar119,uVar11)) >> 0x20);
          iStack_104 = (int)(CONCAT26(uVar124,CONCAT24(uVar122,uVar27)) >> 0x20);
          uVar84 = (uint)(ushort)((short)((uint)((((iVar186 * -0x579 >> 0xf) + 0x9f1) * iVar228 +
                                                  -0x14610000 >> 0x10) * iVar186) >> 0xf) + 0x3d82);

          auVar85.b[0xc] = (undefined1)iVar181;
          auVar85.b[0xd] = (undefined1)((uint)iVar181 >> 8);
          iVar169 = (uint)(ushort)((short)((uint)((short)((uint)(((iVar169 * -0x579 >> 0xf) + 0x9f1)
                                                                 * iVar185 + -0x14610000) >> 0x10) *
                                                 iVar169) >> 0xf) + 0x3d82) * iVar185 + -0x1a890000;
          iVar171 = (uint)(ushort)((short)((uint)((short)((uint)(((iVar171 * -0x579 >> 0xf) + 0x9f1)
                                                                 * iVar191 + -0x14610000) >> 0x10) *
                                                 iVar171) >> 0xf) + 0x3d82) * iVar191 + -0x1a890000;
          iVar172 = (uint)(ushort)((short)((uint)((short)((uint)(((iVar172 * -0x579 >> 0xf) + 0x9f1)
                                                                 * iVar193 + -0x14610000) >> 0x10) *
                                                 iVar172) >> 0xf) + 0x3d82) * iVar193 + -0x1a890000;
          iVar173 = (uint)(ushort)((short)((uint)((short)((uint)(((iVar173 * -0x579 >> 0xf) + 0x9f1)
                                                                 * iVar195 + -0x14610000) >> 0x10) *
                                                 iVar173) >> 0xf) + 0x3d82) * iVar195 + -0x1a890000;
          auVar83._2_2_ = -(ushort)(auVar117._4_4_ == 0);
          auVar83._0_2_ = -(ushort)(auVar117._0_4_ == 0);
          auVar83._4_2_ = -(ushort)(auVar117._8_4_ == 0);
          auVar83._6_2_ = -(ushort)(auVar117._12_4_ == 0);
          auVar83._8_2_ = -(ushort)(uVar11 == 0);
          auVar83._10_2_ = -(ushort)(iStack_10c == 0);
          auVar83._12_2_ = -(ushort)(uVar27 == 0);
          auVar83._14_2_ = -(ushort)(iStack_104 == 0);
          sVar174 = (short)((int)(uVar134 * iVar239 + -0x1a890000) >> 0x14) +
                    (short)((uint)(iVar165 * -0x4000000 + 0x48000000) >> 0x10);
          iVar191 = (uint)(ushort)((int)((uint)(ushort)(CONCAT15((char)((uint)iVar138 >> 8),
                                                                 CONCAT14((char)iVar138,uVar134)) >>
                                                       0x20) * iVar241 + -0x1a890000) >> 0x14) +
                    (iVar166 * -0x4000000 + 0x48000000U >> 0x10);
          iVar193 = (uint)(ushort)((int)((uVar140 & 0xffff) * iVar242 + -0x1a890000) >> 0x14) +
                    (iVar167 * -0x4000000 + 0x48000000U >> 0x10);
          iVar195 = (uint)(ushort)((int)((uint)auVar135._12_2_ * iVar244 + -0x1a890000) >> 0x14) +
                    (iVar168 * -0x4000000 + 0x48000000U >> 0x10);
          auVar22._8_2_ = 0x8001;
          auVar22._0_8_ = 0x8001800180018001;
          auVar22._10_2_ = 0x8001;
          auVar21._8_2_ = 0x8001;
          auVar21._0_8_ = 0x8001800180018001;
          auVar21._10_2_ = 0x8001;
          auVar20._8_2_ = 0x8001;
          auVar20._0_8_ = 0x8001800180018001;
          auVar20._10_2_ = 0x8001;
          auVar19._8_2_ = 0x8001;
          auVar19._0_8_ = 0x8001800180018001;
          auVar19._10_2_ = 0x8001;
          sVar209 = (short)((int)(uVar250 * iVar245 + -0x1a890000) >> 0x14) +
                    (short)((uint)(iVar183 * -0x4000000 + 0x48000000) >> 0x10);
          iVar181 = (uint)(ushort)((int)((uint)(ushort)(CONCAT15((char)((uint)iVar132 >> 8),
                                                                 CONCAT14((char)iVar132,uVar250)) >>
                                                       0x20) * iVar247 + -0x1a890000) >> 0x14) +
                    (iVar94 * -0x4000000 + 0x48000000U >> 0x10);
          iVar183 = (uint)(ushort)((int)((uVar133 & 0xffff) * iVar249 + -0x1a890000) >> 0x14) +
                    (iVar95 * -0x4000000 + 0x48000000U >> 0x10);
          iVar185 = (uint)(ushort)((int)((uint)auVar129._12_2_ * iVar251 + -0x1a890000) >> 0x14) +
                    (iVar96 * -0x4000000 + 0x48000000U >> 0x10);
          iVar187 = (uint)CONCAT11((char)(iVar187 >> 0x1c),(char)(iVar187 >> 0x14)) +
                    (iVar162 * -0x4000000 + 0x48000000U >> 0x10);
          iVar34 = (uint)CONCAT11((char)(iVar234 >> 0x1c),(char)(iVar234 >> 0x14)) +
                   (iVar34 * -0x4000000 + 0x48000000U >> 0x10);
          auVar92._2_2_ = -(ushort)(auVar81._4_4_ == 0);
          auVar92._0_2_ = -(ushort)(auVar81._0_4_ == 0);
          auVar92._4_2_ = -(ushort)(auVar81._8_4_ == 0);
          auVar92._6_2_ = -(ushort)(auVar81._12_4_ == 0);
          auVar92._8_2_ = -(ushort)(auVar86._0_4_ == 0);
          auVar92._10_2_ = -(ushort)(auVar86._4_4_ == 0);
          auVar92._12_2_ = -(ushort)(auVar86._8_4_ == 0);
          auVar92._14_2_ = -(ushort)(auVar86._12_4_ == 0);
          uVar98 = (undefined1)iVar181;
          uVar99 = (undefined1)((uint)iVar181 >> 8);
          uVar100 = (undefined1)iVar183;
          uVar101 = (undefined1)((uint)iVar183 >> 8);
          uVar103 = (undefined1)iVar185;
          uVar104 = (undefined1)((uint)iVar185 >> 8);
          uVar105 = (undefined1)sVar174;
          uVar106 = (undefined1)((ushort)sVar174 >> 8);
          uVar108 = (undefined1)iVar191;
          uVar109 = (undefined1)((uint)iVar191 >> 8);
          uVar110 = (undefined1)iVar193;
          uVar111 = (undefined1)((uint)iVar193 >> 8);
          uVar113 = (undefined1)iVar195;
          uVar114 = (undefined1)((uint)iVar195 >> 8);
          uVar17 = CONCAT15((char)((uint)iVar187 >> 8),
                            CONCAT14((char)iVar187,
                                     (uint)CONCAT11((char)(iVar197 >> 0x1c),(char)(iVar197 >> 0x14))
                                     + (iVar161 * -0x4000000 + 0x48000000U >> 0x10))) &
                   0xffff0000ffff;
          uVar25 = CONCAT15((char)((uint)iVar34 >> 8),
                            CONCAT14((char)iVar34,
                                     (uint)CONCAT11((char)(iVar229 >> 0x1c),(char)(iVar229 >> 0x14))
                                     + (iVar10 * -0x4000000 + 0x48000000U >> 0x10))) &
                   0xffff0000ffff;
          auVar93._2_2_ = (short)(uVar25 >> 0x20);
          auVar93._0_2_ = (short)uVar25;
          auVar93._4_2_ =
               CONCAT11((char)(iVar236 >> 0x1c),(char)(iVar236 >> 0x14)) +
               (short)((uint)(iVar35 * -0x4000000 + 0x48000000) >> 0x10);
          auVar93._6_2_ =
               CONCAT11((char)(iVar238 >> 0x1c),(char)(iVar238 >> 0x14)) +
               (short)((uint)(iVar179 * -0x4000000 + 0x48000000) >> 0x10);
          auVar93._8_2_ = (short)uVar17;
          auVar93._10_2_ = (short)(uVar17 >> 0x20);
          auVar93._12_2_ =
               CONCAT11((char)(iVar182 >> 0x1c),(char)(iVar182 >> 0x14)) +
               (short)((uint)(iVar163 * -0x4000000 + 0x48000000) >> 0x10);
          auVar93._14_2_ =
               CONCAT11((char)(iVar184 >> 0x1c),(char)(iVar184 >> 0x14)) +
               (short)((uint)(iVar164 * -0x4000000 + 0x48000000) >> 0x10);
          auVar19._12_4_ = 0x80018001;
          auVar93 = vec128_bit(auVar93, auVar93, auVar19, auVar92);
          auVar217.b[2] = uVar98;
          auVar217._0_2_ = sVar209;
          auVar217.b[3] = uVar99;
          auVar217.b[4] = uVar100;
          auVar217.b[5] = uVar101;
          auVar217.b[6] = uVar103;
          auVar217.b[7] = uVar104;
          auVar217.b[8] = uVar105;
          auVar217.b[9] = uVar106;
          auVar217.b[10] = uVar108;
          auVar217.b[0xb] = uVar109;
          auVar217.b[0xc] = uVar110;
          auVar217.b[0xd] = uVar111;
          auVar217.b[0xe] = uVar113;
          auVar217.b[0xf] = uVar114;
          auVar20._12_4_ = 0x80018001;
          auVar232.b[2] = uVar98;
          auVar232._0_2_ = sVar209;
          auVar232.b[3] = uVar99;
          auVar232.b[4] = uVar100;
          auVar232.b[5] = uVar101;
          auVar232.b[6] = uVar103;
          auVar232.b[7] = uVar104;
          auVar232.b[8] = uVar105;
          auVar232.b[9] = uVar106;
          auVar232.b[10] = uVar108;
          auVar232.b[0xb] = uVar109;
          auVar232.b[0xc] = uVar110;
          auVar232.b[0xd] = uVar111;
          auVar232.b[0xe] = uVar113;
          auVar232.b[0xf] = uVar114;
          auVar232 = vec128_bit(auVar232, auVar217, auVar20, auVar83);
          uVar25 = CONCAT15((char)(-(uint)(auVar128._4_4_ == 0) >> 8),
                            CONCAT14((char)-(uint)(auVar128._4_4_ == 0),-(uint)(auVar128._0_4_ == 0)
                                    )) & 0xffff0000ffff;
          sVar174 = (short)((int)((uint)(ushort)((short)((uint)((((sVar205 * -0x579 >> 0xf) + 0x9f1)
                                                                 * iVar218 + -0x14610000 >> 0x10) *
                                                               (int)sVar205) >> 0xf) + 0x3d82) *
                                  iVar218 + -0x1a890000) >> 0x14) +
                    (short)((uint)(iVar155 * -0x4000000 + 0x48000000) >> 0x10);
          uVar119 = (undefined2)
                    ((uint)(ushort)((int)((uint)(ushort)((short)((uint)((((sVar79 * -0x579 >> 0xf) +
                                                                         0x9f1) * iVar219 +
                                                                         -0x14610000 >> 0x10) *
                                                                       (int)sVar79) >> 0xf) + 0x3d82
                                                        ) * iVar219 + -0x1a890000) >> 0x14) +
                    (iVar158 * -0x4000000 + 0x48000000U >> 0x10));
          uVar120 = (undefined2)
                    ((uint)(ushort)((int)((uint)(ushort)((short)((uint)((((sVar80 * -0x579 >> 0xf) +
                                                                         0x9f1) * iVar226 +
                                                                         -0x14610000 >> 0x10) *
                                                                       (int)sVar80) >> 0xf) + 0x3d82
                                                        ) * iVar226 + -0x1a890000) >> 0x14) +
                    (iVar159 * -0x4000000 + 0x48000000U >> 0x10));
          uVar121 = (undefined2)
                    ((uint)(ushort)((int)((uint)(ushort)((short)((uint)((((sVar123 * -0x579 >> 0xf)
                                                                         + 0x9f1) * iVar153 +
                                                                         -0x14610000 >> 0x10) *
                                                                       (int)sVar123) >> 0xf) +
                                                        0x3d82) * iVar153 + -0x1a890000) >> 0x14) +
                    (iVar160 * -0x4000000 + 0x48000000U >> 0x10));
          sVar205 = (short)((int)(uVar84 * iVar228 + -0x1a890000) >> 0x14) +
                    (short)((uint)(iVar143 * -0x4000000 + 0x48000000) >> 0x10);
          sVar209 = (short)((int)((uint)(ushort)(CONCAT15((char)((uint)iVar220 >> 8),
                                                          CONCAT14((char)iVar220,uVar84)) >> 0x20) *
                                  iVar233 + -0x1a890000) >> 0x14) +
                    (short)((uint)(iVar146 * -0x4000000 + 0x48000000) >> 0x10);
          sVar79 = (short)((int)((uVar243 & 0xffff) * iVar235 + -0x1a890000) >> 0x14) +
                   (short)((uint)(iVar147 * -0x4000000 + 0x48000000) >> 0x10);
          sVar80 = (short)((int)((uint)auVar85._12_2_ * iVar237 + -0x1a890000) >> 0x14) +
                   (short)((uint)(iVar148 * -0x4000000 + 0x48000000) >> 0x10);
          iVar10 = (uint)CONCAT11((char)(iVar171 >> 0x1c),(char)(iVar171 >> 0x14)) +
                   (iVar139 * -0x4000000 + 0x48000000U >> 0x10);
          uVar17 = CONCAT15((char)(-(uint)(auVar126._4_4_ == 0) >> 8),
                            CONCAT14((char)-(uint)(auVar126._4_4_ == 0),-(uint)(auVar126._0_4_ == 0)
                                    )) & 0xffff0000ffff;
          uVar33 = CONCAT15((char)(-(uint)(auVar254._4_4_ == 0) >> 8),
                            CONCAT14((char)-(uint)(auVar254._4_4_ == 0),-(uint)(auVar254._0_4_ == 0)
                                    )) & 0xffff0000ffff;
          auVar115._2_2_ = (short)(uVar33 >> 0x20);
          auVar115._0_2_ = (short)uVar33;
          auVar115._4_2_ = -(ushort)(auVar254._8_4_ == 0);
          auVar115._6_2_ = -(ushort)(auVar254._12_4_ == 0);
          auVar115._8_2_ = (short)uVar17;
          auVar115._10_2_ = (short)(uVar17 >> 0x20);
          auVar115._12_2_ = -(ushort)(auVar126._8_4_ == 0);
          auVar115._14_2_ = -(ushort)(auVar126._12_4_ == 0);
          cVar12 = *pcVar70;
          cVar42 = pcVar70[1];
          cVar43 = pcVar70[2];
          cVar44 = pcVar70[3];
          cVar45 = pcVar70[4];
          cVar46 = pcVar70[5];
          cVar47 = pcVar70[6];
          cVar48 = pcVar70[7];
          cVar49 = pcVar70[8];
          cVar50 = pcVar70[9];
          cVar51 = pcVar70[10];
          cVar52 = pcVar70[0xb];
          cVar53 = pcVar70[0xc];
          cVar54 = pcVar70[0xd];
          cVar55 = pcVar70[0xe];
          cVar56 = pcVar70[0xf];
          uVar17 = CONCAT15((char)((uint)iVar10 >> 8),
                            CONCAT14((char)iVar10,
                                     (uint)CONCAT11((char)(iVar169 >> 0x1c),(char)(iVar169 >> 0x14))
                                     + (iVar248 * -0x4000000 + 0x48000000U >> 0x10))) &
                   0xffff0000ffff;
          auVar88._2_2_ = (short)(uVar17 >> 0x20);
          auVar88._0_2_ = (short)uVar17;
          auVar88._4_2_ =
               CONCAT11((char)(iVar172 >> 0x1c),(char)(iVar172 >> 0x14)) +
               (short)((uint)(iVar141 * -0x4000000 + 0x48000000) >> 0x10);
          auVar88._6_2_ =
               CONCAT11((char)(iVar173 >> 0x1c),(char)(iVar173 >> 0x14)) +
               (short)((uint)(iVar142 * -0x4000000 + 0x48000000) >> 0x10);
          auVar88._8_2_ =
               (short)((int)((uint)(ushort)((short)((uint)(CONCAT13(cVar97,CONCAT12(cVar97,(short)((
                                                  uint)iVar221 >> 0x10))) * iVar196) >> 0xf) +
                                           0x3d82) * iVar204 + -0x1a890000) >> 0x14) +
               (short)((uint)(iVar149 * -0x4000000 + 0x48000000) >> 0x10);
          auVar88._10_2_ =
               (short)((int)((uint)(ushort)((short)((uint)(CONCAT13(cVar102,CONCAT12(cVar102,(short)
                                                  ((uint)iVar225 >> 0x10))) * iVar203) >> 0xf) +
                                           0x3d82) * iVar207 + -0x1a890000) >> 0x14) +
               (short)((uint)(iVar151 * -0x4000000 + 0x48000000) >> 0x10);
          auVar88._12_2_ =
               (short)((int)((uint)(ushort)((short)((uint)(CONCAT13(cVar107,CONCAT12(cVar107,(short)
                                                  ((uint)iVar175 >> 0x10))) * iVar206) >> 0xf) +
                                           0x3d82) * iVar211 + -0x1a890000) >> 0x14) +
               (short)((uint)(iVar152 * -0x4000000 + 0x48000000) >> 0x10);
          auVar88._14_2_ =
               (short)(((int)((uint)(ushort)((short)((uint)(CONCAT13(cVar112,CONCAT12(cVar112,(short
                                                  )((uint)iVar180 >> 0x10))) * iVar210) >> 0xf) +
                                            0x3d82) * iVar212 + -0x1a890000) >> 0x14) +
                      (iVar154 * -0x4000000 + 0x48000000U >> 0x10));
          auVar145._2_2_ = sVar209;
          auVar145._0_2_ = sVar205;
          auVar145._4_2_ = sVar79;
          auVar145._6_2_ = sVar80;
          auVar145._8_2_ = sVar174;
          auVar145._10_2_ = uVar119;
          auVar145._12_2_ = uVar120;
          auVar145._14_2_ = uVar121;
          auVar21._12_4_ = 0x80018001;
          auVar253._2_2_ = sVar209;
          auVar253._0_2_ = sVar205;
          auVar253._4_2_ = sVar79;
          auVar253._6_2_ = sVar80;
          auVar253._8_2_ = sVar174;
          auVar253._10_2_ = uVar119;
          auVar253._12_2_ = uVar120;
          auVar253._14_2_ = uVar121;
          auVar253 = vec128_bit(auVar253, auVar145, auVar21, auVar115);
          auVar22._12_4_ = 0x80018001;
          auVar202.b[2] = (char)(uVar25 >> 0x20);
          auVar202._0_2_ = (short)uVar25;
          auVar202.b[3] = (char)(uVar25 >> 0x28);
          auVar202.b[4] = (char)-(uint)(auVar128._8_4_ == 0);
          auVar202.b[5] = (char)(-(uint)(auVar128._8_4_ == 0) >> 8);
          auVar202.b[6] = (char)-(uint)(auVar128._12_4_ == 0);
          auVar202.b[7] = (char)(-(uint)(auVar128._12_4_ == 0) >> 8);
          auVar202.b[8] = (char)-(ushort)(auVar131._0_4_ == 0);
          auVar202.b[9] = (char)((ushort)-(ushort)(auVar131._0_4_ == 0) >> 8);
          auVar202.b[10] = (char)-(uint)(auVar131._4_4_ == 0);
          auVar202.b[0xb] = (char)(-(uint)(auVar131._4_4_ == 0) >> 8);
          auVar202.b[0xc] = (char)-(uint)(auVar131._8_4_ == 0);
          auVar202.b[0xd] = (char)(-(uint)(auVar131._8_4_ == 0) >> 8);
          auVar202.b[0xe] = (char)-(uint)(auVar131._12_4_ == 0);
          auVar202.b[0xf] = (char)(-(uint)(auVar131._12_4_ == 0) >> 8);
          auVar88 = vec128_bit(auVar88, auVar88, auVar22, auVar202);
          sVar205 = auVar253._2_2_ + cVar50 * -0x40;
          sVar209 = auVar253._4_2_ + cVar51 * -0x40;
          sVar79 = auVar253._6_2_ + cVar52 * -0x40;
          sVar80 = auVar253._10_2_ + cVar54 * -0x40;
          sVar123 = auVar253._12_2_ + cVar55 * -0x40;
          sVar174 = auVar253._14_2_ + cVar56 * -0x40;
          psVar72[4] = auVar232._8_2_ + cVar45 * -0x40;
          psVar72[5] = auVar232._10_2_ + cVar46 * -0x40;
          psVar72[6] = auVar232._12_2_ + cVar47 * -0x40;
          psVar72[7] = auVar232._14_2_ + cVar48 * -0x40;
          *psVar72 = auVar232._0_2_ + cVar12 * -0x40;
          psVar72[1] = auVar232._2_2_ + cVar42 * -0x40;
          psVar72[2] = auVar232._4_2_ + cVar43 * -0x40;
          psVar72[3] = auVar232._6_2_ + cVar44 * -0x40;
          psVar72[0xc] = auVar93._8_2_ + cVar53 * -0x40;
          psVar72[0xd] = auVar93._10_2_ + cVar54 * -0x40;
          psVar72[0xe] = auVar93._12_2_ + cVar55 * -0x40;
          psVar72[0xf] = auVar93._14_2_ + cVar56 * -0x40;
          psVar72[8] = auVar93._0_2_ + cVar49 * -0x40;
          psVar72[9] = auVar93._2_2_ + cVar50 * -0x40;
          psVar72[10] = auVar93._4_2_ + cVar51 * -0x40;
          psVar72[0xb] = auVar93._6_2_ + cVar52 * -0x40;
          psVar74[4] = auVar88._8_2_ + cVar45 * -0x40;
          psVar74[5] = auVar88._10_2_ + cVar46 * -0x40;
          psVar74[6] = auVar88._12_2_ + cVar47 * -0x40;
          psVar74[7] = auVar88._14_2_ + cVar48 * -0x40;
          *psVar74 = auVar88._0_2_ + cVar12 * -0x40;
          psVar74[1] = auVar88._2_2_ + cVar42 * -0x40;
          psVar74[2] = auVar88._4_2_ + cVar43 * -0x40;
          psVar74[3] = auVar88._6_2_ + cVar44 * -0x40;
          *(ssc_u64_u *)(psVar74 + 0xc) =
               CONCAT17((char)((ushort)sVar174 >> 8),
                        CONCAT16((char)sVar174,
                                 CONCAT15((char)((ushort)sVar123 >> 8),
                                          CONCAT14((char)sVar123,
                                                   CONCAT13((char)((ushort)sVar80 >> 8),
                                                            CONCAT12((char)sVar80,
                                                                     auVar253._8_2_ + cVar53 * -0x40
                                                                    ))))));
          *(ssc_u64_u *)(psVar74 + 8) =
               CONCAT17((char)((ushort)sVar79 >> 8),
                        CONCAT16((char)sVar79,
                                 CONCAT15((char)((ushort)sVar209 >> 8),
                                          CONCAT14((char)sVar209,
                                                   CONCAT13((char)((ushort)sVar205 >> 8),
                                                            CONCAT12((char)sVar205,
                                                                     auVar253._0_2_ + cVar49 * -0x40
                                                                    ))))));
          pcVar70 = pcVar70 + 0x10;
          psVar72 = psVar72 + 0x10;
          psVar74 = psVar74 + 0x10;
        } while (uVar75 != 0);
        if (uVar63 == uVar65) {
          return;
        }
        if ((uVar63 & 0xc) == 0) {
          lVar62 = lVar62 + uVar65;
          goto LAB_001140dc;
        }
      }
      lVar71 = (long)iVar13;
      lVar73 = (uVar65 + lVar61) - lVar71;
      lVar66 = lVar61;
      if (lVar61 < (lVar61 - lVar71) + 1) {
        lVar66 = (lVar61 - lVar71) + 1;
      }
      lVar64 = (uVar65 + lVar61 * 2) - lVar71;
      uVar63 = (lVar66 + lVar71) - lVar61;
      uVar75 = uVar63 & 0xfffffffffffffffc;
      lVar62 = lVar62 + uVar75;
      lVar66 = uVar65 - uVar75;
      lVar71 = param_3;
      puVar69 = (ssc_u32_u *)(puVar60 + lVar73);
      puVar68 = (ssc_u64_u *)(uintptr_t)((param_4 + lVar73 * 2));
      puVar77 = (ssc_u64_u *)(uintptr_t)((param_4 + lVar64 * 2));
      do {
        puVar15 = (ssc_u64_u *)(uintptr_t)((lVar71 + lVar73 * 4));
        uVar28 = puVar15[1];
        uVar26 = *puVar15;
        lVar66 = lVar66 + 4;
        puVar15 = (ssc_u64_u *)(uintptr_t)((lVar71 + lVar64 * 4));
        uVar32 = puVar15[1];
        uVar31 = *puVar15;
        lVar71 = lVar71 + 0x10;
        uVar11 = (int)uVar26 << 2;
        uVar84 = (int)((ulong)uVar26 >> 0x20) << 2;
        uVar98 = (undefined1)(uVar84 >> 8);
        uVar99 = (undefined1)(uVar84 >> 0x10);
        uVar100 = (undefined1)(uVar84 >> 0x18);
        uVar27 = (int)uVar28 << 2;
        uVar101 = (undefined1)(uVar27 >> 8);
        uVar103 = (undefined1)(uVar27 >> 0x10);
        uVar104 = (undefined1)(uVar27 >> 0x18);
        uVar243 = (int)((ulong)uVar28 >> 0x20) << 2;
        uVar105 = (undefined1)(uVar243 >> 8);
        uVar106 = (undefined1)(uVar243 >> 0x10);
        uVar108 = (undefined1)(uVar243 >> 0x18);
        uVar250 = (int)uVar31 << 2;
        uVar133 = (int)((ulong)uVar31 >> 0x20) << 2;
        uVar119 = (undefined2)(uVar133 >> 0x10);
        uVar134 = (int)uVar32 << 2;
        uVar120 = (undefined2)(uVar134 >> 0x10);
        uVar140 = (int)((ulong)uVar32 >> 0x20) << 2;
        uVar121 = (undefined2)(uVar140 >> 0x10);
        iVar13 = LZCOUNT(uVar11);
        iVar10 = LZCOUNT(uVar84);
        iVar221 = LZCOUNT(uVar27);
        iVar34 = LZCOUNT(uVar243);
        iVar225 = LZCOUNT(uVar250);
        iVar35 = LZCOUNT(uVar133);
        iVar183 = LZCOUNT(uVar134);
        iVar185 = LZCOUNT(uVar140);
        auVar178._0_4_ = -(uint)(0xffff < uVar11);
        auVar178._4_4_ = -(uint)(0xffff < uVar84);
        auVar178._8_4_ = -(uint)(0xffff < uVar27);
        auVar178._12_4_ = -(uint)(0xffff < uVar243);
        auVar190._0_4_ = -(uint)(0xffff < uVar250);
        auVar190._4_4_ = -(uint)(0xffff < uVar133);
        auVar190._8_4_ = -(uint)(0xffff < uVar134);
        auVar190._12_4_ = -(uint)(0xffff < uVar140);
        auVar201._0_4_ = iVar13 + -0x10;
        auVar201._4_4_ = iVar10 + -0x10;
        auVar201._8_4_ = iVar221 + -0x10;
        auVar201._12_4_ = iVar34 + -0x10;
        auVar216._0_4_ = iVar13 + -0x10;
        auVar216._4_4_ = iVar10 + -0x10;
        auVar216._8_4_ = iVar221 + -0x10;
        auVar216._12_4_ = iVar34 + -0x10;
        auVar223._0_4_ = iVar225 + -0x10;
        auVar223._4_4_ = iVar35 + -0x10;
        auVar223._8_4_ = iVar183 + -0x10;
        auVar223._12_4_ = iVar185 + -0x10;
        auVar231._0_4_ = iVar225 + -0x10;
        auVar231._4_4_ = iVar35 + -0x10;
        auVar231._8_4_ = iVar183 + -0x10;
        auVar231._12_4_ = iVar185 + -0x10;
        auVar23.b[4] = (char)uVar84;
        auVar23._0_4_ = uVar11;
        auVar23.b[5] = uVar98;
        auVar23.b[6] = uVar99;
        auVar23.b[7] = uVar100;
        auVar23.b[8] = (char)uVar27;
        auVar23.b[9] = uVar101;
        auVar23.b[10] = uVar103;
        auVar23.b[0xb] = uVar104;
        auVar23.b[0xc] = (char)uVar243;
        auVar23.b[0xd] = uVar105;
        auVar23.b[0xe] = uVar106;
        auVar23.b[0xf] = uVar108;
        auVar202 = NEON_sshl(auVar23,auVar201,4);
        auVar24.b[4] = (char)uVar84;
        auVar24._0_4_ = uVar11;
        auVar24.b[5] = uVar98;
        auVar24.b[6] = uVar99;
        auVar24.b[7] = uVar100;
        auVar24.b[8] = (char)uVar27;
        auVar24.b[9] = uVar101;
        auVar24.b[10] = uVar103;
        auVar24.b[0xb] = uVar104;
        auVar24.b[0xc] = (char)uVar243;
        auVar24.b[0xd] = uVar105;
        auVar24.b[0xe] = uVar106;
        auVar24.b[0xf] = uVar108;
        auVar217 = NEON_ushl(auVar24,auVar216,4);
        auVar29._4_2_ = (short)uVar133;
        auVar29._0_4_ = uVar250;
        auVar29._6_2_ = uVar119;
        auVar29._8_2_ = (short)uVar134;
        auVar29._10_2_ = uVar120;
        auVar29._12_2_ = (short)uVar140;
        auVar29._14_2_ = uVar121;
        auVar224 = NEON_sshl(auVar29,auVar223,4);
        auVar30._4_2_ = (short)uVar133;
        auVar30._0_4_ = uVar250;
        auVar30._6_2_ = uVar119;
        auVar30._8_2_ = (short)uVar134;
        auVar30._10_2_ = uVar120;
        auVar30._12_2_ = (short)uVar140;
        auVar30._14_2_ = uVar121;
        auVar232 = NEON_ushl(auVar30,auVar231,4);
        auVar217 = vec128_bit(auVar217, auVar217, auVar202, auVar178);
        auVar232 = vec128_bit(auVar232, auVar232, auVar224, auVar190);
        iVar175 = auVar217._0_4_ * 0x10000 + 0x40000000;
        iVar179 = auVar217._4_4_ * 0x10000 + 0x40000000;
        iVar180 = auVar217._8_4_ * 0x10000 + 0x40000000;
        iVar181 = auVar217._12_4_ * 0x10000 + 0x40000000;
        iVar187 = auVar232._0_4_ * 0x10000 + 0x40000000;
        iVar191 = auVar232._4_4_ * 0x10000 + 0x40000000;
        iVar193 = auVar232._8_4_ * 0x10000 + 0x40000000;
        iVar195 = auVar232._12_4_ * 0x10000 + 0x40000000;
        iVar197 = iVar175 >> 0x10;
        iVar204 = iVar179 >> 0x10;
        iVar207 = iVar180 >> 0x10;
        iVar211 = iVar181 >> 0x10;
        iVar175 = iVar175 >> 0xf;
        iVar179 = iVar179 >> 0xf;
        iVar180 = iVar180 >> 0xf;
        iVar181 = iVar181 >> 0xf;
        iVar212 = iVar187 >> 0x10;
        iVar218 = iVar191 >> 0x10;
        iVar219 = iVar193 >> 0x10;
        iVar220 = iVar195 >> 0x10;
        iVar187 = iVar187 >> 0xf;
        iVar191 = iVar191 >> 0xf;
        iVar193 = iVar193 >> 0xf;
        iVar195 = iVar195 >> 0xf;
        iVar226 = ((uint)((((iVar204 * -0x579 >> 0xf) + 0x9f1) * iVar179 + -0x14610000 >> 0x10) *
                         iVar204) >> 0xf) + 0x3d82;
        uVar227 = ((uint)((((iVar207 * -0x579 >> 0xf) + 0x9f1) * iVar180 + -0x14610000 >> 0x10) *
                         iVar207) >> 0xf) + 0x3d82;
        iVar211 = ((uint)((((iVar211 * -0x579 >> 0xf) + 0x9f1) * iVar181 + -0x14610000 >> 0x10) *
                         iVar211) >> 0xf) + 0x3d82;
        iVar204 = ((uint)((((iVar218 * -0x579 >> 0xf) + 0x9f1) * iVar191 + -0x14610000 >> 0x10) *
                         iVar218) >> 0xf) + 0x3d82;
        uVar208 = ((uint)((((iVar219 * -0x579 >> 0xf) + 0x9f1) * iVar193 + -0x14610000 >> 0x10) *
                         iVar219) >> 0xf) + 0x3d82;
        iVar207 = ((uint)((((iVar220 * -0x579 >> 0xf) + 0x9f1) * iVar195 + -0x14610000 >> 0x10) *
                         iVar220) >> 0xf) + 0x3d82;
        uVar213 = (uint)(ushort)((short)((uint)((((iVar197 * -0x579 >> 0xf) + 0x9f1) * iVar175 +
                                                 -0x14610000 >> 0x10) * iVar197) >> 0xf) + 0x3d82);

        auVar214.b[0xc] = (char)iVar211;
        auVar214.b[0xd] = (char)((uint)iVar211 >> 8);
        uVar198 = (uint)(ushort)((short)((uint)((((iVar212 * -0x579 >> 0xf) + 0x9f1) * iVar187 +
                                                 -0x14610000 >> 0x10) * iVar212) >> 0xf) + 0x3d82);

        auVar199.b[0xc] = (undefined1)iVar207;
        auVar199.b[0xd] = (undefined1)((uint)iVar207 >> 8);
        uVar188 = *puVar69;
        sVar205 = (short)((int)((uVar227 & 0xffff) * iVar180 + -0x1a890000) >> 0x14) +
                  (short)((uint)(iVar221 * -0x4000000 + 0x48000000) >> 0x10);
        sVar209 = (short)((int)((uint)auVar214._12_2_ * iVar181 + -0x1a890000) >> 0x14) +
                  (short)((uint)(iVar34 * -0x4000000 + 0x48000000) >> 0x10);
        uVar78 = CONCAT22((short)((int)((uint)(ushort)(CONCAT15((char)((uint)iVar226 >> 8),
                                                                CONCAT14((char)iVar226,uVar213)) >>
                                                      0x20) * iVar179 + -0x1a890000) >> 0x14) +
                          (short)((uint)(iVar10 * -0x4000000 + 0x48000000) >> 0x10),
                          (short)((int)(uVar213 * iVar175 + -0x1a890000) >> 0x14) +
                          (short)((uint)(iVar13 * -0x4000000 + 0x48000000) >> 0x10));
        sVar80 = (short)(char)((uint)uVar188 >> 8);
        sVar123 = (short)(char)((uint)uVar188 >> 0x10);
        sVar174 = (short)(char)((uint)uVar188 >> 0x18);
        uVar65 = CONCAT26(sVar209,CONCAT24(sVar205,uVar78)) ^
                 (CONCAT26(sVar209,CONCAT24(sVar205,uVar78)) ^ 0x8001800180018001) &
                 CONCAT17((char)((ushort)-(ushort)(uVar243 == 0) >> 8),
                          CONCAT16((char)-(ushort)(uVar243 == 0),
                                   CONCAT15((char)((ushort)-(ushort)(uVar27 == 0) >> 8),
                                            CONCAT14((char)-(ushort)(uVar27 == 0),
                                                     CONCAT13((char)((ushort)-(ushort)(uVar84 == 0)
                                                                    >> 8),
                                                              CONCAT12((char)-(ushort)(uVar84 == 0),
                                                                       -(ushort)(uVar11 == 0)))))));
        uVar176 = CONCAT26((short)((int)((uint)auVar199._12_2_ * iVar195 + -0x1a890000) >> 0x14) +
                           (short)((uint)(iVar185 * -0x4000000 + 0x48000000) >> 0x10),
                           CONCAT24((short)((int)((uVar208 & 0xffff) * iVar193 + -0x1a890000) >>
                                           0x14) +
                                    (short)((uint)(iVar183 * -0x4000000 + 0x48000000) >> 0x10),
                                    CONCAT22((short)((int)((uint)(ushort)(CONCAT15((char)((uint)
                                                  iVar204 >> 8),CONCAT14((char)iVar204,uVar198)) >>
                                                  0x20) * iVar191 + -0x1a890000) >> 0x14) +
                                             (short)((uint)(iVar35 * -0x4000000 + 0x48000000) >>
                                                    0x10),
                                             (short)((int)(uVar198 * iVar187 + -0x1a890000) >> 0x14)
                                             + (short)((uint)(iVar225 * -0x4000000 + 0x48000000) >>
                                                      0x10))));
        uVar176 = uVar176 ^ (uVar176 ^ 0x8001800180018001) &
                            CONCAT26(-(ushort)(uVar140 == 0),
                                     CONCAT24(-(ushort)(uVar134 == 0),
                                              CONCAT22(-(ushort)(uVar133 == 0),
                                                       -(ushort)(uVar250 == 0))));
        sVar205 = (short)(uVar65 >> 0x10) + sVar80 * -0x40;
        sVar209 = (short)(uVar65 >> 0x20) + sVar123 * -0x40;
        sVar79 = (short)(uVar65 >> 0x30) + sVar174 * -0x40;
        *puVar68 = CONCAT17((char)((ushort)sVar79 >> 8),
                            CONCAT16((char)sVar79,
                                     CONCAT15((char)((ushort)sVar209 >> 8),
                                              CONCAT14((char)sVar209,
                                                       CONCAT13((char)((ushort)sVar205 >> 8),
                                                                CONCAT12((char)sVar205,
                                                                         (short)uVar65 +
                                                                         (char)uVar188 * -0x40))))))
        ;
        *puVar77 = CONCAT26((short)(uVar176 >> 0x30) + sVar174 * -0x40,
                            CONCAT24((short)(uVar176 >> 0x20) + sVar123 * -0x40,
                                     CONCAT22((short)(uVar176 >> 0x10) + sVar80 * -0x40,
                                              (short)uVar176 + (char)uVar188 * -0x40)));
        puVar69 = puVar69 + 1;
        puVar68 = puVar68 + 1;
        puVar77 = puVar77 + 1;
      } while (lVar66 != 0);
      if (uVar63 == uVar75) {
        return;
      }
    }
  }
LAB_001140dc:
  lVar66 = lVar62 + lVar61;
  do {
    uVar11 = *(ssc_u32_u *)(uintptr_t)((param_3 + lVar62 * 4));
    iVar13 = uVar11 << 2;
    if (iVar13 == 0) {
      sVar205 = -0x7fff;
    }
    else {
      iVar221 = (int)LZCOUNT(iVar13);
      iVar10 = iVar13 >> (0x10U - iVar221 & 0x1f);
      if ((uVar11 & 0x3fffffff) >> 0xe == 0) {
        iVar10 = iVar13 << (ulong)(iVar221 - 0x10U & 0x1f);
      }
      iVar13 = iVar10 * 0x10000 + 0x40000000;
      iVar10 = iVar13 >> 0x10;
      iVar13 = iVar13 >> 0xf;
      sVar205 = (short)((int)((((uint)((((iVar10 * -0x579 >> 0xf) + 0x9f1) * iVar13 + -0x14610000 >>
                                       0x10) * iVar10) >> 0xf) + 0x3d82 & 0xffff) * iVar13 +
                             -0x1a890000) >> 0x14) +
                (short)((uint)(iVar221 * -0x4000000 + 0x48000000) >> 0x10);
    }
    cVar12 = puVar60[lVar62];
    uVar11 = *(ssc_u32_u *)(uintptr_t)((param_3 + lVar66 * 4));
    iVar13 = uVar11 << 2;
    *(ssc_i16_u *)(uintptr_t)((param_4 + lVar62 * 2)) = sVar205 + cVar12 * -0x40;
    if (iVar13 == 0) {
      sVar205 = -0x7fff;
    }
    else {
      iVar221 = (int)LZCOUNT(iVar13);
      iVar10 = iVar13 >> (0x10U - iVar221 & 0x1f);
      if ((uVar11 & 0x3fffffff) >> 0xe == 0) {
        iVar10 = iVar13 << (ulong)(iVar221 - 0x10U & 0x1f);
      }
      iVar13 = iVar10 * 0x10000 + 0x40000000;
      iVar10 = iVar13 >> 0x10;
      iVar13 = iVar13 >> 0xf;
      sVar205 = (short)((int)((((uint)((((iVar10 * -0x579 >> 0xf) + 0x9f1) * iVar13 + -0x14610000 >>
                                       0x10) * iVar10) >> 0xf) + 0x3d82 & 0xffff) * iVar13 +
                             -0x1a890000) >> 0x14) +
                (short)((uint)(iVar221 * -0x4000000 + 0x48000000) >> 0x10);
    }
    lVar62 = lVar62 + 1;
    *(ssc_i16_u *)(uintptr_t)((param_4 + lVar66 * 2)) = sVar205 + cVar12 * -0x40;
    lVar66 = lVar66 + 1;
  } while (lVar62 < lVar61);
  return;
}


/* ==================================================================== */
/* Function: ssc_compute_allocation @ 001149d8 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ssc_compute_allocation(ssc_i64_u *param_1,ssc_u32_u *param_2,undefined8 param_3,uint param_4,int param_5)

{
  bool bVar1;
  undefined1 (*pauVar2) [12];
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  vec128_t auVar12;
  vec128_t auVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  vec128_t auVar16;
  vec128_t auVar17;
  vec128_t auVar18;
  unkbyte9 Var19;
  bool bVar20;
  int iVar21;
  uint uVar22;
  ssc_i32_u *piVar23;
  ulong uVar24;
  long lVar25;
  int iVar26;
  uint uVar27;
  long lVar28;
  int iVar29;
  int iVar30;
  ssc_u32_u *puVar31;
  uint uVar32;
  uint uVar33;
  long lVar34;
  ssc_i16_u *psVar35;
  long lVar36;
  ulong uVar37;
  int iVar38;
  int iVar39;
  uint uVar40;
  ulong uVar41;
  ulong uVar42;
  ssc_i16_u *psVar43;
  int iVar44;
  ssc_u64_u *puVar45;
  ssc_i32_u *piVar46;
  long lVar47;
  long lVar48;
  int iVar49;
  uint uVar50;
  short sVar51;
  short sVar52;
  short sVar53;
  short sVar54;
  short sVar55;
  short sVar56;
  short sVar57;
  short sVar58;
  byte bVar59;
  undefined1 uVar60;
  byte bVar61;
  undefined1 uVar62;
  byte bVar63;
  undefined1 uVar64;
  byte bVar65;
  undefined1 uVar66;
  byte bVar67;
  undefined1 uVar68;
  byte bVar69;
  undefined1 uVar70;
  byte bVar71;
  undefined1 uVar72;
  byte bVar73;
  undefined1 uVar74;
  byte bVar75;
  undefined1 uVar76;
  byte bVar77;
  undefined1 uVar78;
  byte bVar79;
  undefined1 uVar80;
  byte bVar81;
  undefined1 uVar82;
  byte bVar83;
  undefined1 uVar84;
  byte bVar85;
  undefined1 uVar86;
  byte bVar87;
  undefined1 uVar88;
  byte bVar89;
  undefined1 uVar90;
  vec128_t auVar91;
  vec128_t auVar92;
  vec128_t auVar93;
  undefined4 uVar94;
  vec128_t auVar95;
  vec128_t auVar96;
  byte bVar97;
  byte bVar98;
  byte bVar99;
  byte bVar100;
  byte bVar101;
  byte bVar102;
  byte bVar103;
  byte bVar104;
  byte bVar105;
  byte bVar106;
  byte bVar107;
  byte bVar108;
  byte bVar109;
  byte bVar110;
  byte bVar111;
  byte bVar112;
  vec128_t auVar113;
  vec128_t auVar115;
  vec128_t auVar116;
  vec128_t auVar117;
  int local_1e0 [22];
  undefined8 uStack_1d8;
  int aiStack_1d0 [18];
  int iStack_188;
  undefined8 auStack_184 [11];
  uint local_128 [23];
  int local_cc [23];
  long local_70;
  vec128_t auVar114;

  lVar9 = tpidr_el0;
  local_70 = *(ssc_i64_u *)(uintptr_t)((lVar9 + 0x28));
  lVar28 = (long)(int)param_4;
  lVar48 = *(ssc_i64_u *)(param_2 + 0x2e);
  uVar50 = *param_2 & ((int)*param_2 >> 0x1f ^ 0xffffffffU);
  uVar32 = (uint)(7 < uVar50);
  iVar8 = uVar50 + uVar32 * -8;
  uVar33 = (uint)((uint8_t *)(&DAT_00105df0))[lVar28];
  uVar50 = 0;
  if ((int)uVar33 <= iVar8) {
    uVar50 = uVar33;
  }
  uVar40 = (uint)((uint8_t *)(&DAT_00105df0))[lVar28];
  uVar33 = (uint)(7 < (int)(iVar8 - uVar33));
  iVar39 = 0;
  if ((int)uVar40 <= iVar8) {
    iVar39 = uVar33 * 8;
  }
  iVar49 = iVar8;
  if ((int)uVar40 <= iVar8) {
    iVar49 = (iVar8 - uVar40) + uVar33 * -8;
  }
  lVar25 = 0x28;
  if (param_2[0x60] != 0) {
    lVar25 = 0x30;
  }
  lVar34 = *param_1;
  lVar25 = *(ssc_i64_u *)(uintptr_t)((lVar34 + lVar25));
  if (0 < (int)param_4) {
    uVar33 = param_2[0x5c];
    psVar35 = *(ssc_i16_u **)(uintptr_t)((lVar34 + 0x10));
    uVar37 = (ulong)param_4;
    iVar38 = uVar33 * 2 + -0x10;
    sVar52 = *psVar35;
    if (param_4 < 8) {
      uVar42 = 0;
      sVar51 = sVar52;
    }
    else {
      uVar42 = uVar37 & 0xfffffff8;
      bVar75 = (byte)UNK_00102748;
      bVar77 = (byte)((ulong)UNK_00102748 >> 8);
      bVar79 = (byte)((ulong)UNK_00102748 >> 0x10);
      bVar81 = (byte)((ulong)UNK_00102748 >> 0x18);
      bVar83 = (byte)((ulong)UNK_00102748 >> 0x20);
      bVar85 = (byte)((ulong)UNK_00102748 >> 0x28);
      bVar87 = (byte)((ulong)UNK_00102748 >> 0x30);
      bVar89 = (byte)((ulong)UNK_00102748 >> 0x38);
      bVar59 = (byte)DAT_00102740;
      bVar61 = (byte)((ulong)DAT_00102740 >> 8);
      bVar63 = (byte)((ulong)DAT_00102740 >> 0x10);
      bVar65 = (byte)((ulong)DAT_00102740 >> 0x18);
      bVar67 = (byte)((ulong)DAT_00102740 >> 0x20);
      bVar69 = (byte)((ulong)DAT_00102740 >> 0x28);
      bVar71 = (byte)((ulong)DAT_00102740 >> 0x30);
      bVar73 = (byte)((ulong)DAT_00102740 >> 0x38);
      uVar24 = uVar42;
      psVar43 = psVar35 + 1;
      puVar45 = (ssc_u64_u *)auStack_184;
      piVar23 = (ssc_i32_u *)local_1e0;
      sVar53 = sVar52;
      sVar54 = sVar52;
      sVar55 = sVar52;
      sVar56 = sVar52;
      sVar57 = sVar52;
      sVar58 = sVar52;
      sVar51 = sVar52;
      auVar95 = *(vec128_t *)(ssc_image + 0x27d0);
      do {
        auVar96._10_2_ = sVar57;
        auVar96._8_2_ = sVar56;
        auVar96._12_2_ = sVar58;
        auVar96._14_2_ = sVar51;
        auVar96._2_2_ = sVar53;
        auVar96._0_2_ = sVar52;
        auVar96._4_2_ = sVar54;
        auVar96._6_2_ = sVar55;
        uVar24 = uVar24 - 8;
        uVar10 = *(ssc_u64_u *)(psVar43 + 4);
        sVar56 = (short)uVar10;
        sVar57 = (short)((ulong)uVar10 >> 0x10);
        sVar58 = (short)((ulong)uVar10 >> 0x20);
        sVar51 = (short)((ulong)uVar10 >> 0x30);
        uVar10 = *(ssc_u64_u *)psVar43;
        sVar52 = (short)uVar10;
        sVar53 = (short)((ulong)uVar10 >> 0x10);
        sVar54 = (short)((ulong)uVar10 >> 0x20);
        sVar55 = (short)((ulong)uVar10 >> 0x30);
        bVar97 = ~bVar59;
        bVar98 = ~bVar61;
        bVar99 = ~bVar63;
        bVar100 = ~bVar65;
        bVar101 = ~bVar67;
        bVar102 = ~bVar69;
        bVar103 = ~bVar71;
        bVar104 = ~bVar73;
        bVar105 = ~bVar75;
        bVar106 = ~bVar77;
        bVar107 = ~bVar79;
        bVar108 = ~bVar81;
        bVar109 = ~bVar83;
        bVar110 = ~bVar85;
        bVar111 = ~bVar87;
        bVar112 = ~bVar89;
        iVar30 = CONCAT13(~auVar95.b[3],CONCAT12(~auVar95.b[2],CONCAT11(~auVar95.b[1],~auVar95.b[0])));
        auVar113._0_8_ =
             CONCAT17(~auVar95.b[7],
                      CONCAT16(~auVar95.b[6],CONCAT15(~auVar95.b[5],CONCAT14(~auVar95.b[4],iVar30))));
        auVar113.b[8] = ~auVar95.b[8];
        auVar113.b[9] = ~auVar95.b[9];
        auVar113.b[10] = ~auVar95.b[10];
        auVar113.b[0xb] = ~auVar95.b[0xb];
        auVar114.b[0xc] = ~auVar95.b[0xc];
        auVar114._0_12_ = auVar113._0_12_;
        auVar114.b[0xd] = ~auVar95.b[0xd];
        auVar114.b[0xe] = ~auVar95.b[0xe];
        auVar114.b[0xf] = ~auVar95.b[0xf];
        auVar93._10_2_ = sVar57;
        auVar93._0_10_ = *(unkbyte10 *)psVar43;
        auVar93._12_2_ = sVar58;
        auVar93._14_2_ = sVar51;
        auVar93 = NEON_ext(auVar96,auVar93,0xe,1);
        auVar115._10_2_ = sVar57;
        auVar115._0_10_ = *(unkbyte10 *)psVar43;
        auVar115._12_2_ = sVar58;
        auVar115._14_2_ = sVar51;
        auVar117._10_2_ = sVar57;
        auVar117._0_10_ = *(unkbyte10 *)psVar43;
        auVar117._12_2_ = sVar58;
        auVar117._14_2_ = sVar51;
        auVar115 = NEON_ext(auVar115,auVar117,8,1);
        auVar117 = NEON_ext(auVar93,auVar93,8,1);
        auVar116._0_4_ = auVar115._0_2_ * 0xc + auVar117._0_2_ * -0xc;
        auVar116._4_4_ = auVar115._2_2_ * 0xc + auVar117._2_2_ * -0xc;
        auVar116._8_4_ = auVar115._4_2_ * 0xc + auVar117._4_2_ * -0xc;
        auVar116._12_4_ = auVar115._6_2_ * 0xc + auVar117._6_2_ * -0xc;
        iVar29 = iVar38 * (param_4 + (int)((ulong)auVar113._0_8_ >> 0x20)) *
                 ((int)sVar53 - (int)auVar93._2_2_);
        iVar44 = iVar38 * (param_4 + auVar114._12_4_) * ((int)sVar55 - (int)auVar93._6_2_);
        auVar16._8_4_ = 0x10;
        auVar16._0_8_ = 0x1000000010;
        auVar16._12_4_ = 0x10;
        auVar18._4_4_ = sVar53 * 0xc + auVar93._2_2_ * -0xc;
        auVar18._0_4_ = sVar52 * 0xc + auVar93._0_2_ * -0xc;
        auVar18._8_4_ = sVar54 * 0xc + auVar93._4_2_ * -0xc;
        auVar18._12_4_ = sVar55 * 0xc + auVar93._6_2_ * -0xc;
        auVar115 = NEON_smax(auVar18,auVar16,4);
        auVar17._8_4_ = 0x10;
        auVar17._0_8_ = 0x1000000010;
        auVar17._12_4_ = 0x10;
        auVar117 = NEON_smax(auVar116,auVar17,4);
        auVar91._0_4_ = auVar95._0_4_ + 8;
        auVar91._4_4_ = auVar95._4_4_ + 8;
        auVar91._8_4_ = auVar95._8_4_ + 8;
        auVar91._12_4_ = auVar95._12_4_ + 8;
        iVar7 = CONCAT13(bVar65,CONCAT12(bVar63,CONCAT11(bVar61,bVar59))) + 8;
        bVar59 = (byte)iVar7;
        bVar61 = (byte)((uint)iVar7 >> 8);
        bVar63 = (byte)((uint)iVar7 >> 0x10);
        bVar65 = (byte)((uint)iVar7 >> 0x18);
        iVar7 = CONCAT13(bVar73,CONCAT12(bVar71,CONCAT11(bVar69,bVar67))) + 8;
        bVar67 = (byte)iVar7;
        bVar69 = (byte)((uint)iVar7 >> 8);
        bVar71 = (byte)((uint)iVar7 >> 0x10);
        bVar73 = (byte)((uint)iVar7 >> 0x18);
        iVar7 = CONCAT13(bVar81,CONCAT12(bVar79,CONCAT11(bVar77,bVar75))) + 8;
        bVar75 = (byte)iVar7;
        bVar77 = (byte)((uint)iVar7 >> 8);
        bVar79 = (byte)((uint)iVar7 >> 0x10);
        bVar81 = (byte)((uint)iVar7 >> 0x18);
        iVar7 = CONCAT13(bVar89,CONCAT12(bVar87,CONCAT11(bVar85,bVar83))) + 8;
        bVar83 = (byte)iVar7;
        bVar85 = (byte)((uint)iVar7 >> 8);
        bVar87 = (byte)((uint)iVar7 >> 0x10);
        bVar89 = (byte)((uint)iVar7 >> 0x18);
        *(ssc_u64_u *)(piVar23 + 2) =
             CONCAT17((char)((uint)iVar44 >> 0x18),
                      CONCAT16((char)((uint)iVar44 >> 0x10),
                               CONCAT15((char)((uint)iVar44 >> 8),
                                        CONCAT14((char)iVar44,
                                                 iVar38 * (param_4 + auVar113._8_4_) *
                                                 ((int)sVar54 - (int)auVar93._4_2_)))));
        *(ssc_u64_u *)piVar23 =
             CONCAT17((char)((uint)iVar29 >> 0x18),
                      CONCAT16((char)((uint)iVar29 >> 0x10),
                               CONCAT15((char)((uint)iVar29 >> 8),
                                        CONCAT14((char)iVar29,
                                                 iVar38 * (param_4 + iVar30) *
                                                 ((int)sVar52 - (int)auVar93._0_2_)))));
        piVar23[6] = iVar38 * (param_4 +
                              CONCAT13(bVar108,CONCAT12(bVar107,CONCAT11(bVar106,bVar105)))) *
                     ((int)sVar58 - (int)auVar93._12_2_);
        piVar23[7] = iVar38 * (param_4 +
                              CONCAT13(bVar112,CONCAT12(bVar111,CONCAT11(bVar110,bVar109)))) *
                     ((int)sVar51 - (int)auVar93._14_2_);
        piVar23[4] = iVar38 * (param_4 + CONCAT13(bVar100,CONCAT12(bVar99,CONCAT11(bVar98,bVar97))))
                     * ((int)sVar56 - (int)auVar93._8_2_);
        piVar23[5] = iVar38 * (param_4 +
                              CONCAT13(bVar104,CONCAT12(bVar103,CONCAT11(bVar102,bVar101)))) *
                     ((int)sVar57 - (int)auVar93._10_2_);
        puVar45[1] = auVar115._8_8_;
        *puVar45 = auVar115._0_8_;
        puVar45[3] = auVar117._8_8_;
        puVar45[2] = auVar117._0_8_;
        psVar43 = psVar43 + 8;
        puVar45 = puVar45 + 4;
        piVar23 = piVar23 + 8;
        auVar95 = auVar91;
      } while (uVar24 != 0);
      if (uVar42 == uVar37) goto LAB_00114bec;
    }
    iVar38 = (~(uint)uVar42 + param_4) * iVar38;
    psVar35 = psVar35 + uVar42;
    lVar36 = uVar37 - uVar42;
    piVar23 = (ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((auStack_184)) + uVar42 * 4));
    piVar46 = (ssc_i32_u *)(local_1e0 + uVar42);
    do {
      psVar35 = psVar35 + 1;
      sVar52 = *psVar35;
      iVar7 = (int)sVar52 - (int)sVar51;
      iVar29 = iVar38 * iVar7;
      iVar7 = iVar7 * 0xc;
      iVar38 = iVar38 + uVar33 * -2 + 0x10;
      if (iVar7 < 0x11) {
        iVar7 = 0x10;
      }
      lVar36 = lVar36 + -1;
      *piVar46 = iVar29;
      *piVar23 = iVar7;
      piVar23 = piVar23 + 1;
      piVar46 = piVar46 + 1;
      sVar51 = sVar52;
    } while (lVar36 != 0);
  }
LAB_00114bec:
  iVar7 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_1)) + 0x2c));
  iVar29 = *(ssc_i32_u *)(uintptr_t)((lVar34 + 0x20));
  iVar38 = 1;
  lVar36 = (long)*(ssc_i32_u *)(uintptr_t)((lVar34 + 8));
  iVar44 = iVar29 + -1;
  do {
    iVar30 = iVar38 + iVar44 >> 1;
    if ((int)param_4 < 1) {
      iVar26 = 0;
    }
    else {
      iVar26 = 0;
      bVar20 = false;
      lVar47 = lVar28;
      sVar52 = *(ssc_i16_u *)(uintptr_t)((*(ssc_i64_u *)(uintptr_t)((lVar34 + 0x10)) + lVar28 * 2));
      do {
        sVar51 = *(ssc_i16_u *)(uintptr_t)((*(ssc_i64_u *)(uintptr_t)((lVar34 + 0x10)) + -2 + lVar47 * 2));
        iVar21 = ((int)sVar52 - (int)sVar51) *
                 (uint)*(byte *)(uintptr_t)((lVar25 + -1 + iVar30 * lVar36 + lVar47));
        uVar33 = iVar21 * 4;
        if (0 < iVar21) {
          uVar33 = local_1e0[lVar47 + -1] + uVar33 &
                   ((int)(local_1e0[lVar47 + -1] + uVar33) >> 0x1f ^ 0xffffffffU);
        }
        iVar21 = param_2[lVar47 + 0x2f] + uVar33;
        if ((bVar20) || (((ssc_i32_u*)auStack_184)[lVar47-1] <= iVar21)) {
          iVar4 = *(ssc_i32_u *)(uintptr_t)((lVar48 + -4 + lVar47 * 4));
          bVar20 = true;
          if (iVar4 <= iVar21) {
            iVar21 = iVar4;
          }
          lVar3 = (long)iVar21 + (long)iVar26;
          if (0x7ffffffe < lVar3) {
            lVar3 = 0x7fffffff;
          }
          iVar4 = (int)lVar3;
          if (lVar3 < -0x7ffffffe) {
            iVar4 = -0x7fffffff;
          }
        }
        else {
          bVar20 = false;
          iVar4 = iVar26 + 0x10;
          if (iVar21 < 0x10) {
            iVar4 = iVar26;
          }
        }
        iVar26 = iVar4;
        bVar1 = 1 < lVar47;
        lVar47 = lVar47 + -1;
        sVar52 = sVar51;
      } while (bVar1);
    }
    iVar21 = iVar30 + -1;
    if (iVar26 <= iVar49) {
      iVar38 = iVar30 + 1;
      iVar21 = iVar44;
    }
    iVar44 = iVar21;
  } while (iVar38 <= iVar44);
  if ((int)param_4 < 1) {
    iVar44 = 0;
  }
  else {
    psVar35 = *(ssc_i16_u **)(uintptr_t)((lVar34 + 0x10));
    uVar37 = 0;
    iVar30 = 0;
    sVar52 = *psVar35;
    do {
      sVar51 = psVar35[uVar37 + 1];
      iVar44 = (int)sVar51 - (int)sVar52;
      if (iVar38 < iVar29) {
        uVar33 = iVar44 * (uint)*(byte *)(uintptr_t)((lVar25 + iVar38 * lVar36 + uVar37)) * 4;
      }
      else {
        uVar33 = *(ssc_u32_u *)(uintptr_t)((lVar48 + uVar37 * 4));
      }
      iVar44 = iVar44 * (uint)*(byte *)(uintptr_t)((lVar25 + ((long)iVar38 + -1) * lVar36 + uVar37));
      uVar22 = iVar44 * 4;
      if (0 < iVar44) {
        uVar22 = local_1e0[uVar37] + uVar22 &
                 ((int)(local_1e0[uVar37] + uVar22) >> 0x1f ^ 0xffffffffU);
      }
      if (0 < (int)uVar33) {
        uVar33 = local_1e0[uVar37] + uVar33 &
                 ((int)(local_1e0[uVar37] + uVar33) >> 0x1f ^ 0xffffffffU);
      }
      uVar27 = param_2[uVar37 + 0x30];
      uVar5 = uVar27;
      if (iVar38 < 2) {
        uVar5 = 0;
      }
      uVar24 = uVar37 + 1;
      iVar44 = (int)uVar37;
      if ((int)uVar27 < 1) {
        iVar44 = iVar30;
      }
      uVar27 = (uVar33 - (uVar22 + uVar5)) + uVar27;
      local_cc[uVar37] = uVar22 + uVar5;
      local_128[uVar37] = uVar27 & ((int)uVar27 >> 0x1f ^ 0xffffffffU);
      uVar37 = uVar24;
      iVar30 = iVar44;
      sVar52 = sVar51;
    } while (param_4 != uVar24);
  }
  uVar37 = (ulong)param_4;
  iVar29 = 0;
  iVar38 = 0;
  iVar30 = 0x40;
LAB_00114e60:
  do {
    iVar26 = iVar30 + iVar29 >> 1;
    if ((int)param_4 < 1) goto LAB_00114edc;
    bVar20 = false;
    lVar28 = uVar37 + 1;
    iVar21 = 0;
    do {
      uVar24 = (ulong)((int)lVar28 - 2);
      iVar4 = local_cc[uVar24] + ((int)(local_128[uVar24] * iVar26) >> 6);
      if ((bVar20) || (*(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((auStack_184)) + uVar24 * 4)) <= iVar4)) {
        iVar6 = *(ssc_i32_u *)(uintptr_t)((lVar48 + uVar24 * 4));
        if (iVar6 <= iVar4) {
          iVar4 = iVar6;
        }
        bVar20 = true;
        iVar6 = iVar4 + iVar21;
      }
      else {
        bVar20 = false;
        iVar6 = iVar21 + 0x10;
        if (iVar4 < 0x10) {
          iVar6 = iVar21;
        }
      }
      lVar28 = lVar28 + -1;
      iVar21 = iVar6;
    } while (1 < lVar28);
    iVar38 = iVar38 + 1;
    if (iVar6 <= iVar49) {
      iVar29 = iVar26;
      iVar26 = iVar30;
    }
    iVar30 = iVar26;
  } while (iVar38 != 6);
  iVar38 = 0;
  lVar28 = uVar37 + 1;
  bVar20 = false;
  do {
    uVar24 = (ulong)((int)lVar28 - 2);
    lVar28 = lVar28 + -1;
    uVar22 = *(ssc_u32_u *)(uintptr_t)((lVar48 + uVar24 * 4));
    uVar33 = local_cc[uVar24] + ((int)(local_128[uVar24] * iVar29) >> 6);
    bVar1 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((auStack_184)) + uVar24 * 4)) <= (int)uVar33;
    if (!bVar20 && !bVar1) {
      uVar33 = (uint)(0xf < (int)uVar33) << 4;
    }
    if ((int)uVar22 <= (int)uVar33) {
      uVar33 = uVar22;
    }
    iVar38 = uVar33 + iVar38;
    param_2[uVar24 + 0x17] = uVar33;
    bVar20 = bVar20 || bVar1;
  } while (1 < lVar28);
  goto LAB_00114f7c;
LAB_00114edc:
  iVar38 = iVar38 + 1;
  if (-1 < iVar49) {
    iVar29 = iVar26;
    iVar26 = iVar30;
  }
  iVar30 = iVar26;
  if (iVar38 == 6) goto code_r0x00114ef4;
  goto LAB_00114e60;
code_r0x00114ef4:
  iVar38 = 0;
LAB_00114f7c:
  uVar33 = param_4;
  if (iVar44 < (int)(param_4 - 1)) {
    lVar28 = (long)(int)(param_4 - 1);
    do {
      psVar35 = *(ssc_i16_u **)(uintptr_t)((lVar34 + 0x10));
      uVar22 = param_2[lVar28 + 0x17];
      iVar30 = (int)psVar35[(int)uVar33] - (int)*psVar35;
      iVar29 = 0;
      if (iVar30 != 0) {
        iVar29 = (iVar49 - iVar38) / iVar30;
      }
      iVar21 = (int)psVar35[(int)uVar33] - (int)psVar35[lVar28];
      iVar26 = *(ssc_i32_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((auStack_184)) + lVar28 * 4));
      uVar27 = ((int)*psVar35 - (int)psVar35[lVar28]) + ((iVar49 - iVar38) - iVar30 * iVar29);
      iVar29 = uVar22 + iVar21 * iVar29 + (uVar27 & ((int)uVar27 >> 0x1f ^ 0xffffffffU));
      if (iVar26 < 0x19) {
        iVar26 = 0x18;
      }
      if (iVar26 <= iVar29) {
        if (2 < (int)uVar33) {
          iVar30 = 0x24;
          if ((int)uVar33 <= iVar7) {
            iVar30 = 0x1c;
          }
          if (iVar29 <= iVar21 * iVar30 || param_5 < lVar28) {
            ssc_ec_enc_bit_logp(param_3,0,1);
            uVar22 = param_2[lVar28 + 0x17];
            iVar38 = iVar38 + 8;
            iVar29 = iVar29 + -8;
            goto LAB_00114fb0;
          }
        }
        ssc_ec_enc_bit_logp(param_3,1,1);
        goto LAB_001150d8;
      }
LAB_00114fb0:
      if (uVar50 == 0) {
        uVar27 = 0;
      }
      else {
        uVar27 = (uint)((uint8_t *)(&DAT_00105df0))[lVar28];
      }
      iVar30 = (iVar38 - (uVar22 + uVar50)) + uVar27;
      uVar33 = uVar33 - 1;
      iVar38 = iVar30 + 0x10;
      if (iVar29 < 0x10) {
        iVar38 = iVar30;
      }
      param_2[lVar28 + 0x17] = (uint)(0xf < iVar29) << 4;
      lVar28 = lVar28 + -1;
      uVar50 = uVar27;
    } while (iVar44 < lVar28);
  }
  iVar49 = iVar49 + uVar32 * 8;
LAB_001150d8:
  if (uVar50 == 0) {
    *(ssc_u32_u *)(param_1 + 10) = 0;
LAB_00115164:
    param_2[0x5d] = 0;
  }
  else {
    uVar50 = *(ssc_u32_u *)(param_1 + 10);
    if ((int)uVar33 <= (int)*(ssc_u32_u *)(param_1 + 10)) {
      uVar50 = uVar33;
    }
    *(ssc_u32_u *)(param_1 + 10) = uVar50;
    ssc_ec_enc_uint((ssc_i64_u *)((void *)(uintptr_t)((uintptr_t)param_3)),uVar50,uVar33 + 1);
    if ((((int)param_1[10] < 1) || (iVar39 = 0, iVar8 < (int)uVar40)) || ((int)(iVar8 - uVar40) < 8)
       ) goto LAB_00115164;
    ssc_ec_enc_bit_logp(param_3,param_2[0x5d],1);
    iVar39 = 0;
  }
  if ((int)uVar33 < 1) {
    uVar50 = 0;
    uVar32 = 0;
    goto LAB_001153e0;
  }
  iVar39 = iVar39 + (iVar49 - iVar38);
  psVar35 = *(ssc_i16_u **)(uintptr_t)((lVar34 + 0x10));
  sVar52 = *psVar35;
  iVar49 = (int)psVar35[(int)uVar33] - (int)sVar52;
  iVar8 = 0;
  if (iVar49 != 0) {
    iVar8 = iVar39 / iVar49;
  }
  iVar39 = iVar39 - iVar49 * iVar8;
  uVar24 = (ulong)uVar33;
  if (uVar33 < 0x10) {
    uVar41 = 0;
    sVar51 = sVar52;
LAB_00115220:
    psVar43 = psVar35 + uVar41;
    lVar28 = uVar24 - uVar41;
    puVar31 = param_2 + uVar41 + 0x17;
    do {
      psVar43 = psVar43 + 1;
      sVar53 = *psVar43;
      lVar28 = lVar28 + -1;
      *puVar31 = *puVar31 + ((int)sVar53 - (int)sVar51) * iVar8;
      puVar31 = puVar31 + 1;
      sVar51 = sVar53;
    } while (lVar28 != 0);
  }
  else {
    uVar41 = uVar24 & 0xfffffff0;
    psVar43 = psVar35 + 9;
    uVar60 = (undefined1)sVar52;
    uVar62 = (undefined1)((ushort)sVar52 >> 8);
    puVar31 = param_2 + 0x1f;
    uVar42 = uVar41;
    uVar64 = uVar60;
    uVar66 = uVar62;
    uVar68 = uVar60;
    uVar70 = uVar62;
    uVar72 = uVar60;
    uVar74 = uVar62;
    uVar76 = uVar60;
    uVar78 = uVar62;
    uVar80 = uVar60;
    uVar82 = uVar62;
    uVar84 = uVar60;
    uVar86 = uVar62;
    uVar88 = uVar60;
    uVar90 = uVar62;
    do {
      auVar92.b[9] = uVar78;
      auVar92.b[8] = uVar76;
      auVar92.b[10] = uVar80;
      auVar92.b[0xb] = uVar82;
      auVar92.b[0xc] = uVar84;
      auVar92.b[0xd] = uVar86;
      auVar92.b[0xe] = uVar88;
      auVar92.b[0xf] = uVar90;
      auVar92.b[1] = uVar62;
      auVar92.b[0] = uVar60;
      auVar92.b[2] = uVar64;
      auVar92.b[3] = uVar66;
      auVar92.b[4] = uVar68;
      auVar92.b[5] = uVar70;
      auVar92.b[6] = uVar72;
      auVar92.b[7] = uVar74;
      uVar42 = uVar42 - 0x10;
      pauVar2 = (undefined1 (*) [12])(psVar43 + -8);
      uVar15 = *(ssc_u64_u *)(psVar43 + -4);
      uVar94 = (undefined4)((ulong)uVar15 >> 0x20);
      uVar14 = *(ssc_u64_u *)*pauVar2;
      uVar11 = *(ssc_u64_u *)(psVar43 + 4);
      uVar76 = (undefined1)uVar11;
      uVar78 = (undefined1)((ulong)uVar11 >> 8);
      uVar80 = (undefined1)((ulong)uVar11 >> 0x10);
      uVar82 = (undefined1)((ulong)uVar11 >> 0x18);
      uVar84 = (undefined1)((ulong)uVar11 >> 0x20);
      uVar86 = (undefined1)((ulong)uVar11 >> 0x28);
      uVar88 = (undefined1)((ulong)uVar11 >> 0x30);
      uVar90 = (undefined1)((ulong)uVar11 >> 0x38);
      uVar10 = *(ssc_u64_u *)psVar43;
      Var19 = *(unkbyte9 *)psVar43;
      uVar60 = (undefined1)uVar10;
      uVar62 = (undefined1)((ulong)uVar10 >> 8);
      uVar64 = (undefined1)((ulong)uVar10 >> 0x10);
      uVar66 = (undefined1)((ulong)uVar10 >> 0x18);
      uVar68 = (undefined1)((ulong)uVar10 >> 0x20);
      uVar70 = (undefined1)((ulong)uVar10 >> 0x28);
      uVar72 = (undefined1)((ulong)uVar10 >> 0x30);
      uVar74 = (undefined1)((ulong)uVar10 >> 0x38);
      psVar43 = psVar43 + 0x10;
      auVar12._12_4_ = uVar94;
      auVar12._0_12_ = *(unkbyte12 *)*pauVar2;
      auVar93 = NEON_ext(auVar92,auVar12,0xe,1);
      auVar95.b[9] = uVar78;
      auVar95._0_9_ = Var19;
      auVar95.b[10] = uVar80;
      auVar95.b[0xb] = uVar82;
      auVar95.b[0xc] = uVar84;
      auVar95.b[0xd] = uVar86;
      auVar95.b[0xe] = uVar88;
      auVar95.b[0xf] = uVar90;
      auVar13._12_4_ = uVar94;
      auVar13._0_12_ = *(unkbyte12 *)*pauVar2;
      auVar95 = NEON_ext(auVar13,auVar95,0xe,1);
      sVar51 = (short)((ulong)uVar11 >> 0x30);
      *(ssc_u64_u *)(puVar31 + -6) =
           CONCAT44((int)((ulong)*(ssc_u64_u *)(puVar31 + -6) >> 0x20) +
                    ((int)(short)((ulong)uVar14 >> 0x30) - (int)auVar93._6_2_) * iVar8,
                    (int)*(ssc_u64_u *)(puVar31 + -6) +
                    ((int)(short)((ulong)uVar14 >> 0x20) - (int)auVar93._4_2_) * iVar8);
      *(ssc_u64_u *)(puVar31 + -8) =
           CONCAT44((int)((ulong)*(ssc_u64_u *)(puVar31 + -8) >> 0x20) +
                    ((int)(short)((ulong)uVar14 >> 0x10) - (int)auVar93._2_2_) * iVar8,
                    (int)*(ssc_u64_u *)(puVar31 + -8) +
                    ((int)(short)uVar14 - (int)auVar93._0_2_) * iVar8);
      *(ssc_u64_u *)(puVar31 + -2) =
           CONCAT44((int)((ulong)*(ssc_u64_u *)(puVar31 + -2) >> 0x20) +
                    ((int)(short)((ulong)uVar15 >> 0x30) - (int)auVar93._14_2_) * iVar8,
                    (int)*(ssc_u64_u *)(puVar31 + -2) +
                    ((int)(short)((ulong)uVar15 >> 0x20) - (int)auVar93._12_2_) * iVar8);
      *(ssc_u64_u *)(puVar31 + -4) =
           CONCAT44((int)((ulong)*(ssc_u64_u *)(puVar31 + -4) >> 0x20) +
                    ((int)(short)((ulong)uVar15 >> 0x10) - (int)auVar93._10_2_) * iVar8,
                    (int)*(ssc_u64_u *)(puVar31 + -4) +
                    ((int)(short)uVar15 - (int)auVar93._8_2_) * iVar8);
      puVar31[2] = puVar31[2] + ((int)(short)((ulong)uVar10 >> 0x20) - (int)auVar95._4_2_) * iVar8;
      puVar31[3] = puVar31[3] + ((int)(short)((ulong)uVar10 >> 0x30) - (int)auVar95._6_2_) * iVar8;
      *puVar31 = *puVar31 + ((int)(short)uVar10 - (int)auVar95._0_2_) * iVar8;
      puVar31[1] = puVar31[1] + ((int)(short)((ulong)uVar10 >> 0x10) - (int)auVar95._2_2_) * iVar8;
      *(ssc_u64_u *)(puVar31 + 6) =
           CONCAT44((int)((ulong)*(ssc_u64_u *)(puVar31 + 6) >> 0x20) +
                    ((int)sVar51 - (int)auVar95._14_2_) * iVar8,
                    (int)*(ssc_u64_u *)(puVar31 + 6) +
                    ((int)(short)((ulong)uVar11 >> 0x20) - (int)auVar95._12_2_) * iVar8);
      *(ssc_u64_u *)(puVar31 + 4) =
           CONCAT44((int)((ulong)*(ssc_u64_u *)(puVar31 + 4) >> 0x20) +
                    ((int)(short)((ulong)uVar11 >> 0x10) - (int)auVar95._10_2_) * iVar8,
                    (int)*(ssc_u64_u *)(puVar31 + 4) +
                    ((int)(short)uVar11 - (int)auVar95._8_2_) * iVar8);
      puVar31 = puVar31 + 0x10;
    } while (uVar42 != 0);
    if (uVar41 != uVar24) goto LAB_00115220;
  }
  puVar31 = param_2 + 0x17;
  uVar42 = uVar24;
  psVar43 = psVar35;
  sVar51 = sVar52;
  do {
    psVar43 = psVar43 + 1;
    sVar53 = *psVar43;
    iVar49 = (int)sVar53 - (int)sVar51;
    iVar8 = iVar39;
    if (iVar49 <= iVar39) {
      iVar8 = iVar49;
    }
    uVar42 = uVar42 - 1;
    iVar39 = iVar39 - iVar8;
    *puVar31 = iVar8 + *puVar31;
    puVar31 = puVar31 + 1;
    sVar51 = sVar53;
  } while (uVar42 != 0);
  uVar42 = 0;
  uVar50 = 0;
  lVar28 = *(ssc_i64_u *)(uintptr_t)((lVar34 + 0x38));
  puVar31 = param_2;
  do {
    sVar51 = psVar35[uVar42 + 1];
    uVar40 = (puVar31[0x17] + uVar50) - *(ssc_i32_u *)(uintptr_t)((lVar48 + uVar42 * 4));
    uVar32 = uVar40 & ((int)uVar40 >> 0x1f ^ 0xffffffffU);
    iVar8 = (int)sVar51 - (int)sVar52;
    uVar22 = (puVar31[0x17] + uVar50) - uVar32;
    puVar31[0x17] = uVar22;
    if ((iVar8 < 1) || (param_2[0x5d] != 0)) {
      uVar27 = 0;
    }
    else {
      uVar27 = (uint)((long)uVar42 < (long)(int)param_1[10]);
    }
    uVar27 = iVar8 * 0x10 | uVar27;
    iVar49 = (*(ssc_i16_u *)(uintptr_t)((lVar28 + uVar42 * 2)) + 0x18) * uVar27;
    iVar8 = uVar27 * -0x15 + (iVar49 >> 1);
    iVar39 = iVar8;
    if ((int)(iVar8 + uVar22) < (int)(uVar27 * 0x18)) {
      iVar39 = iVar8 + (iVar49 >> 3);
    }
    if ((int)(iVar8 + uVar22) < (int)(uVar27 * 0x10)) {
      iVar39 = iVar8 + (iVar49 >> 2);
    }
    iVar8 = uVar27 * 8;
    uVar5 = 0;
    if (iVar8 != 0) {
      uVar5 = (int)(iVar39 + uVar22 + uVar27 * 4) / iVar8;
    }
    uVar5 = uVar5 & ((int)uVar5 >> 0x1f ^ 0xffffffffU);
    uVar27 = (int)uVar22 >> 4;
    if ((int)(uVar5 * 2) <= (int)uVar22 >> 3) {
      uVar27 = uVar5;
    }
    if (7 < (int)uVar27) {
      uVar27 = 8;
    }
    puVar31[1] = uVar27;
    puVar31[0x17] = uVar22 + uVar27 * -0x10;
    puVar31[0x46] = (uint)((int)(iVar39 + uVar22) <= (int)(uVar27 * iVar8));
    if ((int)uVar40 < 1) {
      uVar50 = 0;
    }
    else {
      iVar8 = uVar32 - uVar50;
      uVar40 = uVar32 >> 4;
      if (8 - uVar27 <= uVar32 >> 4) {
        uVar40 = 8 - uVar27;
      }
      uVar50 = uVar32 + uVar40 * -0x10;
      puVar31[1] = uVar40 + uVar27;
      puVar31[0x46] = (uint)(iVar8 <= (int)(uVar40 * 0x10));
    }
    uVar42 = uVar42 + 1;
    puVar31 = puVar31 + 1;
    uVar32 = uVar33;
    sVar52 = sVar51;
  } while (uVar24 != uVar42);
LAB_001153e0:
  param_2[0x5e] = uVar50;
  if ((int)uVar32 < (int)param_4) {
    lVar28 = uVar37 - uVar32;
    puVar31 = param_2 + uVar32;
    do {
      uVar50 = puVar31[0x17];
      puVar31[0x17] = 0;
      lVar28 = lVar28 + -1;
      puVar31[1] = (int)uVar50 >> 4;
      puVar31[0x46] = (uint)((int)uVar50 < 0x10);
      puVar31 = puVar31 + 1;
    } while (lVar28 != 0);
  }
  if (*(ssc_i64_u *)(uintptr_t)((lVar9 + 0x28)) == local_70) {
    return uVar33;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ==================================================================== */
/* Function: SSC_COPY32 @ 00115460 */
/* ==================================================================== */

void SSC_COPY32(ulong param_1,ulong param_2,uint param_3)

{
  ssc_u64_u *puVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  ssc_u32_u *puVar5;
  ssc_u64_u *puVar6;
  ssc_u32_u *puVar7;
  ssc_u64_u *puVar8;
  ulong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;

  if (0 < (int)param_3) {
    uVar2 = (ulong)param_3;
    if ((param_3 < 8) || ((param_1 < param_2 + uVar2 * 4 && (param_2 < param_1 + uVar2 * 4)))) {
      uVar4 = 0;
    }
    else {
      uVar4 = uVar2 & 0xfffffff8;
      puVar6 = (ssc_u64_u *)(uintptr_t)((param_2 + 0x10));
      puVar8 = (ssc_u64_u *)(uintptr_t)((param_1 + 0x10));
      uVar9 = uVar4;
      do {
        puVar1 = puVar6 + -1;
        uVar10 = puVar6[-2];
        uVar12 = puVar6[1];
        uVar11 = *puVar6;
        puVar6 = puVar6 + 4;
        uVar9 = uVar9 - 8;
        puVar8[-1] = *puVar1;
        puVar8[-2] = uVar10;
        puVar8[1] = uVar12;
        *puVar8 = uVar11;
        puVar8 = puVar8 + 4;
      } while (uVar9 != 0);
      if (uVar4 == uVar2) {
        return;
      }
    }
    lVar3 = uVar2 - uVar4;
    puVar5 = (ssc_u32_u *)(uintptr_t)((param_1 + uVar4 * 4));
    puVar7 = (ssc_u32_u *)(uintptr_t)((param_2 + uVar4 * 4));
    do {
      lVar3 = lVar3 + -1;
      *puVar5 = *puVar7;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    } while (lVar3 != 0);
  }
  return;
}


/* ==================================================================== */
/* Function: SSC_COPY16 @ 001154ec */
/* ==================================================================== */

void SSC_COPY16(ulong param_1,ulong param_2,uint param_3)

{
  ssc_u64_u *puVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  ssc_u16_u *puVar5;
  ssc_u64_u *puVar6;
  ssc_u16_u *puVar7;
  ssc_u64_u *puVar8;
  ulong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;

  if (0 < (int)param_3) {
    uVar2 = (ulong)param_3;
    if ((param_3 < 0x10) || ((param_1 < param_2 + uVar2 * 2 && (param_2 < param_1 + uVar2 * 2)))) {
      uVar4 = 0;
    }
    else {
      uVar4 = uVar2 & 0xfffffff0;
      puVar6 = (ssc_u64_u *)(uintptr_t)((param_2 + 0x10));
      puVar8 = (ssc_u64_u *)(uintptr_t)((param_1 + 0x10));
      uVar9 = uVar4;
      do {
        puVar1 = puVar6 + -1;
        uVar10 = puVar6[-2];
        uVar12 = puVar6[1];
        uVar11 = *puVar6;
        puVar6 = puVar6 + 4;
        uVar9 = uVar9 - 0x10;
        puVar8[-1] = *puVar1;
        puVar8[-2] = uVar10;
        puVar8[1] = uVar12;
        *puVar8 = uVar11;
        puVar8 = puVar8 + 4;
      } while (uVar9 != 0);
      if (uVar4 == uVar2) {
        return;
      }
    }
    lVar3 = uVar2 - uVar4;
    puVar5 = (ssc_u16_u *)(uintptr_t)((param_1 + uVar4 * 2));
    puVar7 = (ssc_u16_u *)(uintptr_t)((param_2 + uVar4 * 2));
    do {
      lVar3 = lVar3 + -1;
      *puVar5 = *puVar7;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    } while (lVar3 != 0);
  }
  return;
}


/* ==================================================================== */
/* Function: SSC_COPY8 @ 00115578 */
/* ==================================================================== */

void SSC_COPY8(ulong param_1,ulong param_2,uint param_3)

{
  ssc_u64_u *puVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  undefined1 *puVar6;
  ssc_u64_u *puVar7;
  undefined1 *puVar8;
  ssc_u64_u *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;

  if ((int)param_3 < 1) {
    return;
  }
  uVar2 = (ulong)param_3;
  if ((param_3 < 8) || ((param_1 < param_2 + uVar2 && (param_2 < param_1 + uVar2)))) {
    uVar4 = 0;
  }
  else {
    if (param_3 < 0x20) {
      uVar5 = 0;
    }
    else {
      uVar4 = uVar2 & 0xffffffe0;
      puVar7 = (ssc_u64_u *)(uintptr_t)((param_2 + 0x10));
      puVar9 = (ssc_u64_u *)(uintptr_t)((param_1 + 0x10));
      uVar5 = uVar4;
      do {
        puVar1 = puVar7 + -1;
        uVar10 = puVar7[-2];
        uVar12 = puVar7[1];
        uVar11 = *puVar7;
        puVar7 = puVar7 + 4;
        uVar5 = uVar5 - 0x20;
        puVar9[-1] = *puVar1;
        puVar9[-2] = uVar10;
        puVar9[1] = uVar12;
        *puVar9 = uVar11;
        puVar9 = puVar9 + 4;
      } while (uVar5 != 0);
      if (uVar4 == uVar2) {
        return;
      }
      uVar5 = uVar4;
      if ((param_3 & 0x18) == 0) goto LAB_001155a8;
    }
    uVar4 = uVar2 & 0xfffffff8;
    lVar3 = uVar5 - uVar4;
    puVar7 = (ssc_u64_u *)(uintptr_t)((param_2 + uVar5));
    puVar9 = (ssc_u64_u *)(uintptr_t)((param_1 + uVar5));
    do {
      lVar3 = lVar3 + 8;
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    } while (lVar3 != 0);
    if (uVar4 == uVar2) {
      return;
    }
  }
LAB_001155a8:
  lVar3 = uVar2 - uVar4;
  puVar6 = (undefined1 *)(uintptr_t)((param_1 + uVar4));
  puVar8 = (undefined1 *)(uintptr_t)((param_2 + uVar4));
  do {
    lVar3 = lVar3 + -1;
    *puVar6 = *puVar8;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  } while (lVar3 != 0);
  return;
}


/* ==================================================================== */
/* Function: SSC_CLEAR @ 00115640 */
/* ==================================================================== */

void SSC_CLEAR(void *param_1,uint param_2)

{
  if (0 < (int)param_2) {
    memset(param_1,0,(ulong)param_2);
  }
  return;
}


/* ==================================================================== */

/* ==================================================================== */




/* ==================================================================== */
/* Function: ssc_alg_quant @ 0011571c */
/* ==================================================================== */

ulong ssc_alg_quant(ssc_i16_u *param_4,uint param_5,int param_6,int param_7,uint param_8,
                   undefined8 param_9)

{
  if (param_5 == 4 && param_6 == 30) {;
  }
  vec128_t param_3 = {0};
  bool bVar1;
  undefined1 (*pauVar2) [16];
  ssc_i16_u *psVar3;
  vec128_t auVar4;
  vec128_t auVar5;
  vec128_t auVar6;
  vec128_t auVar7;
  int iVar8;
  undefined4 uVar9;
  short extraout_var;
  uint uVar10;
  ssc_i16_u *psVar11;
  ulong uVar12;
  undefined1 (*pauVar13) [16];
  ulong uVar14;
  ulong uVar15;
  ssc_i16_u *psVar16;
  ssc_i16_u *psVar17;
  ssc_i16_u *psVar18;
  long lVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  ssc_i16_u *psVar24;
  ulong uVar25;
  ssc_i16_u *psVar26;
  long lVar27;
  ssc_u64_u *puVar28;
  long lVar29;
  ssc_u16_u *puVar30;
  ssc_u64_u *puVar31;
  undefined1 (*pauVar32) [16];
  ssc_i16_u *psVar33;
  ulong uVar34;
  ulong uVar35;
  long lVar36;
  uint uVar37;
  long lVar38;
  undefined *puVar39;
  ulong uVar40;
  ssc_i16_u *psVar41;
  long lVar42;
  long lVar43;
  long lVar44;
  short sVar45;
  short sVar46;
  short sVar47;
  short sVar48;
  short sVar49;
  short sVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  uint uVar54;
  undefined8 uVar55;
  int iVar57;
  undefined8 uVar56;
  int iVar58;
  undefined8 uVar59;
  int iVar60;
  int iVar61;
  undefined1 uVar62;
  byte bVar63;
  undefined1 uVar64;
  byte bVar65;
  char cVar66;
  undefined1 uVar67;
  byte bVar68;
  undefined1 uVar69;
  byte bVar70;
  undefined1 uVar71;
  byte bVar72;
  undefined1 uVar73;
  byte bVar74;
  char cVar75;
  undefined1 uVar76;
  byte bVar77;
  undefined1 uVar78;
  byte bVar79;
  undefined1 uVar80;
  byte bVar81;
  undefined1 uVar82;
  byte bVar83;
  undefined1 uVar84;
  byte bVar85;
  undefined1 uVar86;
  byte bVar87;
  undefined1 uVar88;
  byte bVar89;
  undefined1 uVar90;
  byte bVar91;
  undefined1 uVar92;
  byte bVar93;
  undefined1 uVar94;
  byte bVar95;
  byte bVar96;
  int iVar97;
  byte bVar99;
  byte bVar100;
  byte bVar102;
  int iVar103;
  byte bVar104;
  byte bVar105;
  byte bVar107;
  int iVar108;
  byte bVar109;
  byte bVar110;
  byte bVar112;
  byte bVar114;
  byte bVar115;
  byte bVar101;
  byte bVar106;
  byte bVar111;
  int iVar113;
  byte bVar116;
  vec128_t auVar98;
  short sVar117;
  undefined2 uVar118;
  int iVar119;
  undefined8 uVar120;
  short sVar123;
  vec128_t auVar121;
  vec128_t auVar122;
  uint uVar126;
  uint uVar127;
  uint uVar128;
  vec128_t auVar124;
  vec128_t auVar125;
  int iVar129;
  int iVar130;
  int iVar131;
  int iVar132;

  if ((param_6 * 2 < (int)param_5) && (param_7 != 0)) {
    iVar8 = ssc_rcp(param_5 + *(ssc_i32_u *)(ssc_image + 0x5eb8 + (long)param_7 * 4) *
                              param_6);
    iVar8 = (int)((ulong)((long)iVar8 *
                         (long)(int)((-(param_5 >> 0xf & 1) & 0x80000000 | (param_5 & 0xffff) << 0xf
                                     ) - (int)(short)param_5)) >> 0xf) >> 0x10;
    uVar37 = (uint)(iVar8 * iVar8) >> 0x10;
    uVar9 = ssc_cos_norm(uVar37);
    iVar8 = ssc_cos_norm(uVar37 ^ 0x7fff);
    if ((int)param_5 < (int)(param_8 * 8)) {
      iVar57 = 0;
      if (param_8 != 0) {
        iVar57 = (int)param_5 / (int)param_8;
      }
      iVar58 = param_8 - 1;
      if (iVar58 != 0) {
        psVar18 = param_4 + (long)iVar57 * (long)iVar58;
        do {
          FUN_001167d0((ssc_u16_u *)(psVar18),iVar57,uVar9,-iVar8);
          iVar58 = iVar58 + -1;
          psVar18 = psVar18 + -(long)iVar57;
        } while (iVar58 != 0);
      }
      FUN_001167d0((ssc_u16_u *)(param_4),iVar57,uVar9,-iVar8);
    }
    else {
      uVar34 = 1;
      psVar18 = param_4;
      iVar57 = -3;
      iVar58 = -2;
      psVar26 = param_4;
      do {
        iVar97 = iVar58;
        iVar61 = iVar57;
        psVar33 = psVar18;
        uVar12 = uVar34;
        psVar26 = psVar26 + 1;
        uVar37 = (uint)uVar12;
        psVar18 = psVar33 + 1;
        uVar34 = uVar12 + 1;
        iVar57 = iVar61 + -2;
        iVar58 = iVar97 + -1;
      } while ((int)(((int)param_8 >> 2) + (uVar37 + uVar37 * uVar37) * param_8) < (int)param_5);
      uVar10 = 0;
      if (param_8 != 0) {
        uVar10 = (int)param_5 / (int)param_8;
      }
      uVar20 = (ulong)uVar10;
      iVar58 = (int)(short)iVar8;
      sVar117 = -(short)uVar9;
      iVar103 = (int)sVar117;
      uVar126 = uVar10 + ~uVar37;
      uVar40 = (ulong)uVar126;
      uVar34 = uVar12 & 0xffffffff;
      uVar37 = (uVar37 << 1 ^ 0xffffffff) + uVar10;
      uVar35 = (ulong)uVar37;
      iVar57 = param_8 - 1;
      if (iVar57 != 0) {
        lVar43 = (long)iVar57;
        lVar27 = 0;
        lVar38 = (long)(int)uVar10 * (long)iVar57;
        lVar21 = uVar34 + (long)(int)uVar10 * (long)iVar57;
        lVar44 = lVar38 * 2;
        lVar36 = uVar35 + (long)(int)uVar10 * (long)iVar57;
        psVar41 = param_4 + lVar38;
        uVar22 = uVar40 + 1 & 0x1fffffff8;
        uVar14 = uVar35 + 1 & 0x1fffffffe;
        uVar15 = -(ulong)(uVar10 >> 0x1f) & 0xfffffffe00000000 | uVar20 << 1;
        uVar23 = (ulong)(uVar10 + iVar61);
        lVar19 = -uVar15;
        psVar11 = psVar41 + (uVar23 - 1);
        do {
          lVar42 = lVar27 * (int)uVar10;
          psVar17 = param_4 + lVar43 * (int)uVar10;
          FUN_001167d0((ssc_u16_u *)(psVar17),uVar20,uVar9,-iVar8);
          if (-1 < (int)uVar126) {
            psVar16 = psVar17;
            uVar127 = uVar126;
            if ((6 < uVar126) &&
               ((param_4 + ((uVar40 + (long)(int)uVar10 * (long)iVar57 + 1) - lVar42) <=
                 param_4 + (lVar21 - lVar42) ||
                (param_4 + ((lVar21 + uVar40 + 1) - lVar42) <= param_4 + (lVar38 - lVar42))))) {
              uVar25 = (ulong)(uVar10 + iVar97) + 1 & 0x1fffffff8;
              lVar29 = lVar44;
              psVar16 = psVar41;
              do {
                uVar59 = ((ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar18)) + lVar29)))[1];
                uVar55 = *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar18)) + lVar29));
                uVar25 = uVar25 - 8;
                uVar56 = *(ssc_u64_u *)(psVar16 + 4);
                uVar120 = *(ssc_u64_u *)psVar16;
                iVar129 = (int)(short)((ulong)uVar55 >> 0x10);
                iVar130 = (int)(short)((ulong)uVar55 >> 0x20);
                iVar131 = (int)(short)((ulong)uVar55 >> 0x30);
                sVar48 = (short)((ulong)uVar120 >> 0x10);
                iVar132 = (int)(short)((ulong)uVar120 >> 0x20);
                iVar119 = (int)(short)((ulong)uVar120 >> 0x30);
                iVar108 = (int)(short)((ulong)uVar59 >> 0x10);
                iVar113 = (int)(short)((ulong)uVar59 >> 0x20);
                iVar60 = (int)(short)((ulong)uVar59 >> 0x30);
                sVar45 = (short)uVar56;
                sVar46 = (short)((ulong)uVar56 >> 0x10);
                sVar49 = (short)((ulong)uVar56 >> 0x20);
                sVar47 = (short)((ulong)uVar56 >> 0x30);
                param_3._0_4_ =
                     iVar103 * CONCAT13(sVar45 >> 0xf,(int3)sVar45) + iVar58 * (short)uVar59;
                param_3._4_4_ = iVar103 * CONCAT13(sVar46 >> 0xf,(int3)sVar46) + iVar58 * iVar108;
                param_3._8_4_ = iVar103 * CONCAT13(sVar49 >> 0xf,(int3)sVar49) + iVar58 * iVar113;
                param_3._12_4_ = iVar103 * CONCAT13(sVar47 >> 0xf,(int3)sVar47) + iVar58 * iVar60;
                uVar127 = (uint)(iVar58 * sVar48 - iVar103 * iVar129) >> 0xf;
                uVar51 = (uint)(iVar58 * iVar132 - iVar103 * iVar130) >> 0xf;
                uVar53 = (uint)(iVar58 * iVar119 - iVar103 * iVar131) >> 0xf;
                uVar128 = (uint)(iVar58 * CONCAT13(sVar46 >> 0xf,(int3)sVar46) - iVar103 * iVar108)
                          >> 0xf;
                uVar52 = (uint)(iVar58 * CONCAT13(sVar49 >> 0xf,(int3)sVar49) - iVar103 * iVar113)
                         >> 0xf;
                uVar54 = (uint)(iVar58 * CONCAT13(sVar47 >> 0xf,(int3)sVar47) - iVar103 * iVar60) >>
                         0xf;
                ((ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar18)) + lVar29)))[1] =
                     CONCAT26((short)(param_3._12_4_ >> 0xf),
                              CONCAT24((short)(param_3._8_4_ >> 0xf),
                                       CONCAT22((short)(param_3._4_4_ >> 0xf),
                                                (short)(param_3._0_4_ >> 0xf))));
                *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar18)) + lVar29)) =
                     CONCAT26((short)((uint)(iVar103 * iVar119 + iVar58 * iVar131) >> 0xf),
                              CONCAT24((short)((uint)(iVar103 * iVar132 + iVar58 * iVar130) >> 0xf),
                                       CONCAT22((short)((uint)(iVar103 * sVar48 + iVar58 * iVar129)
                                                       >> 0xf),
                                                (short)((uint)(iVar103 * (short)uVar120 +
                                                              iVar58 * (short)uVar55) >> 0xf))));
                lVar29 = lVar29 + 0x10;
                *(ssc_u64_u *)(psVar16 + 4) =
                     CONCAT17((char)(uVar54 >> 8),
                              CONCAT16((char)uVar54,
                                       CONCAT15((char)(uVar52 >> 8),
                                                CONCAT14((char)uVar52,
                                                         CONCAT13((char)(uVar128 >> 8),
                                                                  CONCAT12((char)uVar128,
                                                                           (short)((uint)(iVar58 *
                                                  CONCAT13(sVar45 >> 0xf,(int3)sVar45) -
                                                  iVar103 * (short)uVar59) >> 0xf)))))));
                *(ssc_u64_u *)psVar16 =
                     CONCAT17((char)(uVar53 >> 8),
                              CONCAT16((char)uVar53,
                                       CONCAT15((char)(uVar51 >> 8),
                                                CONCAT14((char)uVar51,
                                                         CONCAT13((char)(uVar127 >> 8),
                                                                  CONCAT12((char)uVar127,
                                                                           (short)((uint)(iVar58 * (
                                                  short)uVar120 - iVar103 * (short)uVar55) >> 0xf)))
                                                  ))));
                psVar16 = psVar16 + 8;
              } while (uVar25 != 0);
              psVar16 = psVar17 + uVar22;
              uVar127 = uVar126 - (int)uVar22;
              if (uVar40 + 1 == uVar22) goto LAB_00115b44;
            }
            iVar108 = uVar127 + 1;
            psVar24 = psVar16 + uVar12;
            do {
              sVar45 = *psVar16;
              iVar108 = iVar108 + -1;
              sVar48 = *psVar24;
              *psVar24 = (short)((uint)(sVar45 * iVar103 + sVar48 * iVar58) >> 0xf);
              *psVar16 = (short)((uint)(sVar45 * iVar58 - sVar48 * iVar103) >> 0xf);
              psVar16 = psVar16 + 1;
              psVar24 = psVar24 + 1;
            } while (iVar108 != 0);
          }
LAB_00115b44:
          if (-1 < (int)uVar37) {
            psVar17 = psVar17 + uVar35;
            uVar127 = uVar37;
            if ((((uVar37 != 0) &&
                 (param_4 + ((lVar21 + uVar35) - lVar42) + -uVar35 <=
                  param_4 + ((lVar21 + uVar35) - lVar42))) &&
                (param_4 + (lVar36 - lVar42) + -uVar35 <= param_4 + (lVar36 - lVar42))) &&
               ((param_4 + ((lVar36 + 1) - lVar42) <= param_4 + (lVar21 - lVar42) ||
                (param_4 + ((lVar21 + uVar35 + 1) - lVar42) <= param_4 + (lVar38 - lVar42))))) {
              psVar17 = psVar17 + -uVar14;
              uVar25 = uVar23 + 1 & 0x1fffffffe;
              psVar16 = psVar33 + uVar23;
              psVar24 = psVar11;
              do {
                psVar3 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar16)) + lVar44));
                psVar16 = psVar16 + -2;
                uVar25 = uVar25 - 2;
                sVar45 = psVar24[1];
                sVar48 = *psVar24;
                cVar66 = (char)(sVar45 >> 0xf);
                cVar75 = (char)(sVar48 >> 0xf);
                uVar128 = iVar103 * CONCAT13(cVar66,CONCAT12(cVar66,sVar45)) + iVar58 * psVar3[1];
                uVar51 = iVar103 * CONCAT13(cVar75,CONCAT12(cVar75,sVar48)) + iVar58 * *psVar3;
                param_3._0_4_ =
                     iVar58 * CONCAT13(cVar66,CONCAT12(cVar66,sVar45)) - iVar103 * psVar3[1];
                param_3._4_4_ =
                     iVar58 * CONCAT13(cVar75,CONCAT12(cVar75,sVar48)) - iVar103 * *psVar3;
                param_3._8_8_ = 0;
                uVar127 = uVar51 >> 0xf;
                uVar120 = NEON_rev64((ulong)CONCAT16((byte)(uVar51 >> 0x1f),
                                                     CONCAT15((char)(uVar127 >> 8),
                                                              CONCAT14((char)uVar127,
                                                                       (uint)CONCAT12((byte)(uVar128
                                                                                            >> 0x1f)
                                                                                      ,(short)(
                                                  uVar128 >> 0xf))))),4);
                uVar56 = NEON_rev64(CONCAT44(param_3._4_4_ >> 0xf,param_3._0_4_ >> 0xf),4);
                *psVar24 = (short)uVar56;
                psVar24[1] = (short)((ulong)uVar56 >> 0x20);
                psVar24 = psVar24 + -2;
                psVar3[1] = (short)((ulong)uVar120 >> 0x20);
                *psVar3 = (short)uVar120;
              } while (uVar25 != 0);
              uVar127 = uVar37 - (int)uVar14;
              if (uVar35 + 1 == uVar14) goto LAB_001159d0;
            }
            iVar108 = uVar127 + 1;
            psVar16 = psVar17 + uVar12;
            do {
              sVar45 = *psVar17;
              iVar108 = iVar108 + -1;
              sVar48 = *psVar16;
              *psVar16 = (short)((uint)(sVar45 * iVar103 + sVar48 * iVar58) >> 0xf);
              *psVar17 = (short)((uint)(sVar45 * iVar58 - sVar48 * iVar103) >> 0xf);
              psVar17 = psVar17 + -1;
              psVar16 = psVar16 + -1;
            } while (iVar108 != 0);
          }
LAB_001159d0:
          lVar43 = lVar43 + -1;
          lVar27 = lVar27 + 1;
          psVar41 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar41)) + lVar19));
          psVar11 = (ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((psVar11)) + lVar19));
          lVar44 = lVar44 - uVar15;
        } while ((int)lVar43 != 0);
      }
      FUN_001167d0((ssc_u16_u *)(param_4),uVar20,uVar9,-iVar8);
      cVar66 = (char)(sVar117 >> 0xf);
      if (-1 < (int)uVar126) {
        psVar18 = param_4;
        if ((6 < uVar126) &&
           ((param_4 + uVar40 + 1 <= param_4 + uVar34 || (param_4 + uVar34 + uVar40 + 1 <= param_4))
           )) {
          uVar14 = uVar40 + 1 & 0x1fffffff8;
          uVar126 = uVar126 - (int)uVar14;
          uVar20 = (ulong)(uVar10 + iVar97) + 1 & 0x1fffffff8;
          do {
            sVar45 = *psVar26;
            sVar48 = psVar26[1];
            sVar46 = psVar26[2];
            sVar49 = psVar26[3];
            uVar20 = uVar20 - 8;
            uVar55 = *(ssc_u64_u *)(psVar18 + 4);
            uVar56 = *(ssc_u64_u *)psVar18;
            iVar97 = (int)(short)((ulong)uVar56 >> 0x10);
            iVar108 = (int)(short)((ulong)uVar56 >> 0x20);
            iVar113 = (int)(short)((ulong)uVar56 >> 0x30);
            sVar47 = (short)((ulong)uVar55 >> 0x10);
            iVar8 = (int)(short)((ulong)uVar55 >> 0x20);
            iVar57 = (int)(short)((ulong)uVar55 >> 0x30);
            param_3._0_8_ =
                 CONCAT26((short)((uint)(CONCAT13(cVar66,(int3)sVar117) * iVar113 + iVar58 * sVar49)
                                 >> 0xf),
                          CONCAT24((short)((uint)(CONCAT13(cVar66,(int3)sVar117) * iVar108 +
                                                 iVar58 * sVar46) >> 0xf),
                                   CONCAT22((short)((uint)(CONCAT13(cVar66,(int3)sVar117) * iVar97 +
                                                          iVar58 * sVar48) >> 0xf),
                                            (short)((uint)(CONCAT13(cVar66,(int3)sVar117) *
                                                           (int)(short)uVar56 + iVar58 * sVar45) >>
                                                   0xf))));
            uVar120 = CONCAT26((short)((uint)(CONCAT13(cVar66,(int3)sVar117) * iVar57 +
                                             iVar58 * psVar26[7]) >> 0xf),
                               CONCAT24((short)((uint)(CONCAT13(cVar66,(int3)sVar117) * iVar8 +
                                                      iVar58 * psVar26[6]) >> 0xf),
                                        CONCAT22((short)((uint)(CONCAT13(cVar66,(int3)sVar117) *
                                                                (int)sVar47 + iVar58 * psVar26[5])
                                                        >> 0xf),
                                                 (short)((uint)(CONCAT13(cVar66,(int3)sVar117) *
                                                                (int)(short)uVar55 +
                                                               iVar58 * psVar26[4]) >> 0xf))));
            param_3._8_8_ = uVar120;
            uVar9 = CONCAT22((short)((uint)(iVar58 * sVar47 -
                                           CONCAT13(cVar66,(int3)sVar117) * (int)psVar26[5]) >> 0xf)
                             ,(short)((uint)(iVar58 * (short)uVar55 -
                                            CONCAT13(cVar66,(int3)sVar117) * (int)psVar26[4]) >> 0xf
                                     ));
            *(ssc_u64_u *)(psVar26 + 4) = uVar120;
            *(ssc_u64_u *)psVar26 = param_3._0_8_;
            *(ssc_u64_u *)(psVar18 + 4) =
                 CONCAT44((int)(CONCAT26((short)((uint)(iVar58 * iVar57 -
                                                       CONCAT13(cVar66,(int3)sVar117) *
                                                       (int)psVar26[7]) >> 0xf),
                                         CONCAT24((short)((uint)(iVar58 * iVar8 -
                                                                CONCAT13(cVar66,(int3)sVar117) *
                                                                (int)psVar26[6]) >> 0xf),uVar9)) >>
                               0x20),uVar9);
            *(ssc_u64_u *)psVar18 =
                 CONCAT26((short)((uint)(iVar58 * iVar113 -
                                        CONCAT13(cVar66,(int3)sVar117) * (int)sVar49) >> 0xf),
                          CONCAT24((short)((uint)(iVar58 * iVar108 -
                                                 CONCAT13(cVar66,(int3)sVar117) * (int)sVar46) >>
                                          0xf),
                                   CONCAT22((short)((uint)(iVar58 * iVar97 -
                                                          CONCAT13(cVar66,(int3)sVar117) *
                                                          (int)sVar48) >> 0xf),
                                            (short)((uint)(iVar58 * (short)uVar56 -
                                                          CONCAT13(cVar66,(int3)sVar117) *
                                                          (int)sVar45) >> 0xf))));
            psVar18 = psVar18 + 8;
            psVar26 = psVar26 + 8;
          } while (uVar20 != 0);
          psVar18 = param_4 + uVar14;
          if (uVar40 + 1 == uVar14) goto LAB_00115de4;
        }
        iVar8 = uVar126 + 1;
        psVar26 = psVar18 + uVar12;
        do {
          sVar45 = *psVar18;
          iVar8 = iVar8 + -1;
          sVar48 = *psVar26;
          *psVar26 = (short)((uint)(sVar45 * iVar103 + sVar48 * iVar58) >> 0xf);
          *psVar18 = (short)((uint)(sVar45 * iVar58 - sVar48 * iVar103) >> 0xf);
          psVar18 = psVar18 + 1;
          psVar26 = psVar26 + 1;
        } while (iVar8 != 0);
      }
LAB_00115de4:
      if (-1 < (int)uVar37) {
        psVar18 = param_4 + uVar35;
        if ((((uVar37 != 0) && (param_4 + uVar34 + uVar35 + -uVar35 <= param_4 + uVar34 + uVar35))
            && (psVar26 = psVar18 + -uVar35, psVar26 <= psVar18)) &&
           ((param_4 + uVar35 + 1 <= param_4 + uVar34 || (param_4 + uVar34 + uVar35 + 1 <= param_4))
           )) {
          uVar34 = (ulong)(uVar10 + iVar61);
          uVar20 = uVar35 + 1 & 0x1fffffffe;
          uVar37 = uVar37 - (int)uVar20;
          psVar18 = psVar18 + -uVar20;
          psVar26 = psVar26 + (uVar34 - 1);
          psVar33 = psVar33 + uVar34;
          uVar34 = uVar34 + 1 & 0x1fffffffe;
          do {
            uVar34 = uVar34 - 2;
            uVar10 = iVar58 * psVar26[1] - CONCAT13(cVar66,(int3)sVar117) * (int)psVar33[1];
            uVar126 = iVar58 * *psVar26 - CONCAT13(cVar66,(int3)sVar117) * (int)*psVar33;
            param_3._0_8_ =
                 NEON_rev64(CONCAT44((uint)(CONCAT13(cVar66,(int3)sVar117) * (int)*psVar26 +
                                           iVar58 * *psVar33) >> 0xf,
                                     (uint)(CONCAT13(cVar66,(int3)sVar117) * (int)psVar26[1] +
                                           iVar58 * psVar33[1]) >> 0xf),4);
            param_3._8_8_ = 0;
            uVar120 = NEON_rev64(CONCAT26((ushort)(uVar126 >> 0x1f),
                                          CONCAT24((short)(uVar126 >> 0xf),
                                                   CONCAT22((ushort)(uVar10 >> 0x1f),
                                                            (short)(uVar10 >> 0xf)))),4);
            *psVar33 = (short)param_3._0_8_;
            psVar33[1] = (short)(param_3._0_8_ >> 0x20);
            psVar33 = psVar33 + -2;
            *psVar26 = (short)uVar120;
            psVar26[1] = (short)((ulong)uVar120 >> 0x20);
            psVar26 = psVar26 + -2;
          } while (uVar34 != 0);
          if (uVar35 + 1 == uVar20) goto LAB_00115f4c;
        }
        iVar8 = uVar37 + 1;
        psVar26 = psVar18 + uVar12;
        do {
          sVar117 = *psVar18;
          iVar8 = iVar8 + -1;
          sVar45 = *psVar26;
          *psVar26 = (short)((uint)(sVar117 * iVar103 + sVar45 * iVar58) >> 0xf);
          *psVar18 = (short)((uint)(sVar117 * iVar58 - sVar45 * iVar103) >> 0xf);
          psVar18 = psVar18 + -1;
          psVar26 = psVar26 + -1;
        } while (iVar8 != 0);
      }
    }
  }
LAB_00115f4c:
  puVar39 = PTR_in_shared_0011bd00;
  lVar19 = (long)(int)(param_5 - 1);
  puVar30 = (ssc_u16_u *)(PTR_in_shared_0011bd00 + (long)(int)(param_5 - 1) * 2 + 0xfc0);
  lVar27 = lVar19;
  do {
    if (param_4[lVar27] < 1) {
      puVar30[0x120] = 0xffff;
      param_4[lVar27] = -param_4[lVar27];
    }
    else {
      puVar30[0x120] = 1;
    }
    *puVar30 = 0;
    *(ssc_u32_u *)(puVar39 + lVar27 * 4 + 0xd80) = 0;
    bVar1 = 0 < lVar27;
    puVar30 = puVar30 + -1;
    lVar27 = lVar27 + -1;
  } while (bVar1);
  if ((int)param_5 >> 1 < param_6) {
    uVar34 = lVar19 + 1;
    if (uVar34 < 4) {
      iVar8 = 0;
      lVar27 = lVar19;
LAB_00116050:
      do {
        psVar18 = param_4 + lVar27;
        lVar27 = lVar27 + -1;
        iVar8 = iVar8 + *psVar18;
      } while (lVar27 != -1);
    }
    else {
      uVar20 = uVar34 & 0xfffffffffffffffc;
      iVar8 = 0;
      iVar57 = 0;
      lVar27 = lVar19 - uVar20;
      uVar62 = 0;
      uVar64 = 0;
      uVar67 = 0;
      uVar69 = 0;
      uVar71 = 0;
      uVar73 = 0;
      uVar76 = 0;
      uVar78 = 0;
      psVar18 = param_4 + lVar19 + -1;
      uVar12 = uVar20;
      do {
        psVar33 = psVar18 + -1;
        uVar12 = uVar12 - 4;
        memcpy((void *)(auVar121.b + 2), (const void *)(param_3.b + 2), 14);
        auVar121._0_2_ = psVar18[1];
        psVar26 = psVar18 + -2;
        memcpy((void *)(auVar124.b + 6), (const void *)(param_3.b + 6), 10);
        auVar124._0_4_ = auVar121._0_4_;
        auVar124._4_2_ = *psVar18;
        psVar18 = psVar18 + -4;
        param_3._0_4_ = auVar124._0_4_ << 0x10;
        param_3._4_4_ = auVar124._4_4_ << 0x10;
        param_3._8_8_ = 0;
        iVar8 = iVar8 + ((int)param_3._0_4_ >> 0x10);
        iVar57 = iVar57 + ((int)param_3._4_4_ >> 0x10);
        iVar58 = CONCAT13(uVar69,CONCAT12(uVar67,CONCAT11(uVar64,uVar62))) + (int)*psVar33;
        uVar62 = (undefined1)iVar58;
        uVar64 = (undefined1)((uint)iVar58 >> 8);
        uVar67 = (undefined1)((uint)iVar58 >> 0x10);
        uVar69 = (undefined1)((uint)iVar58 >> 0x18);
        iVar61 = CONCAT13(uVar78,CONCAT12(uVar76,CONCAT11(uVar73,uVar71))) + (int)*psVar26;
        uVar71 = (undefined1)iVar61;
        uVar73 = (undefined1)((uint)iVar61 >> 8);
        uVar76 = (undefined1)((uint)iVar61 >> 0x10);
        uVar78 = (undefined1)((uint)iVar61 >> 0x18);
      } while (uVar12 != 0);
      iVar8 = iVar58 + iVar8 + iVar61 + iVar57;
      if (uVar34 != uVar20) goto LAB_00116050;
    }
    if (iVar8 <= param_6) {
      iVar8 = 0x4000;
      *param_4 = 0x4000;
      memset((void *)(param_4 + (lVar19 - (ulong)(param_5 - 2))),0,(ulong)(param_5 - 2) * 2 + 2);
    }
    sVar117 = (short)param_6 + -1;
    extraout_var = (short)((int)ssc_rcp(iVar8) >> 16);
    uVar10 = ssc_rcp(iVar8);
    uVar37 = param_5 + 3;
    if (-1 < (int)param_5) {
      uVar37 = param_5;
    }
    sVar117 = extraout_var * sVar117 + (short)((uVar10 & 0xffff) * (int)sVar117 >> 0x10);
    int sum_pulses = 0;
    iVar8 = 0;
    iVar57 = 0;
    for (uint idx = 0; idx < param_5; idx++) {
      int32_t val = (int32_t)param_4[idx];
      int32_t prod = val * (int32_t)sVar117;
      int16_t pulse = (int16_t)(prod >> 15);
      int32_t pulse32 = (int32_t)pulse;
      *(ssc_i32_u *)(puVar39 + idx * 4 + 0xd80) = pulse32;
      *(ssc_i16_u *)(puVar39 + idx * 2 + 0xfc0) = (short)(pulse << 1);
      sum_pulses += pulse32;
      iVar8 += (int)pulse * pulse;
      iVar57 += (int)val * pulse;
    }
    iVar58 = param_6 - sum_pulses;
  }
  else {
    iVar8 = 0;
    iVar57 = 0;
    iVar58 = param_6;
  }
  if ((int)(param_5 + 3) < iVar58) {
    *(ssc_i32_u *)(puVar39 + 0xd80) = *(ssc_i32_u *)(puVar39 + 0xd80) + iVar58;
  }
  else if (0 < iVar58) {
    iVar61 = 0;
    uVar37 = param_5;
    if ((int)param_5 < 2) {
      uVar37 = 1;
    }
    do {
      iVar61 = iVar61 + 1;
      uVar34 = 0;
      iVar97 = 0;
      uVar12 = 0;
      uVar10 = 0xffff8001;
      do {
        iVar103 = (uint)*(ssc_u16_u *)(puVar39 + uVar34 * 2 + 0xfc0) + iVar8 + 1;
        iVar108 = (int)(short)(iVar57 + param_4[uVar34] >>
                              (0x20U - (int)LZCOUNT((iVar61 + param_6) - iVar58) & 0x1f));
        lVar27 = (long)(short)iVar103 * (long)(int)uVar10;
        uVar127 = (uint)(iVar108 * iVar108) >> 7;
        lVar19 = (ulong)uVar127 * (long)(short)iVar97;
        uVar126 = (uint)uVar34;
        if (lVar19 - lVar27 == 0 || lVar19 < lVar27) {
          uVar126 = (uint)uVar12;
          uVar127 = uVar10;
          iVar103 = iVar97;
        }
        iVar97 = iVar103;
        uVar10 = uVar127;
        uVar12 = (ulong)uVar126;
        uVar34 = uVar34 + 1;
      } while (uVar37 != uVar34);
      uVar34 = -(ulong)(uVar126 >> 0x1f) & 0xfffffffe00000000 | uVar12 << 1;
      iVar97 = *(ssc_i32_u *)(puVar39 + (long)(int)uVar126 * 4 + 0xd80);
      iVar57 = iVar57 + *(ssc_i16_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((param_4)) + uVar34));
      iVar8 = (uint)*(ssc_u16_u *)(puVar39 + uVar34 + 0xfc0) + iVar8 + 1;
      *(ssc_u16_u *)(puVar39 + uVar34 + 0xfc0) = *(ssc_u16_u *)(puVar39 + uVar34 + 0xfc0) + 2;
      *(ssc_i32_u *)(puVar39 + (long)(int)uVar126 * 4 + 0xd80) = iVar97 + 1;
    } while (iVar61 != iVar58);
  }
  uVar37 = param_5 + 3;
  if (-1 < (int)param_5) {
    uVar37 = param_5;
  }
  if ((int)(uVar37 & 0xfffffffc) < 1) {
    uVar34 = 0;
    if ((int)param_5 < 1) goto LAB_0011639c;
  }
  else {
    uVar34 = 0;
    puVar28 = (ssc_u64_u *)(puVar39 + 0x1200);
    puVar31 = (ssc_u64_u *)(puVar39 + 0xd80);
    psVar18 = param_4;
    do {
      uVar56 = *puVar28;
      uVar120 = *(ssc_u64_u *)psVar18;
      uVar34 = uVar34 + 4;
      sVar46 = (short)((ulong)uVar56 >> 0x10);
      sVar117 = (short)((ulong)uVar120 >> 0x10) * sVar46;
      sVar49 = (short)((ulong)uVar56 >> 0x20);
      sVar45 = (short)((ulong)uVar120 >> 0x20) * sVar49;
      sVar47 = (short)((ulong)uVar56 >> 0x30);
      sVar48 = (short)((ulong)uVar120 >> 0x30) * sVar47;
      *(ssc_u64_u *)psVar18 =
           CONCAT17((char)((ushort)sVar48 >> 8),
                    CONCAT16((char)sVar48,
                             CONCAT15((char)((ushort)sVar45 >> 8),
                                      CONCAT14((char)sVar45,
                                               CONCAT13((char)((ushort)sVar117 >> 8),
                                                        CONCAT12((char)sVar117,
                                                                 (short)uVar120 * (short)uVar56)))))
                   );
      puVar31[1] = CONCAT44((int)((ulong)puVar31[1] >> 0x20) * (int)sVar47,
                            (int)puVar31[1] * (int)sVar49);
      *puVar31 = CONCAT44((int)((ulong)*puVar31 >> 0x20) * (int)sVar46,
                          (int)*puVar31 * (int)(short)uVar56);
      puVar28 = puVar28 + 1;
      puVar31 = puVar31 + 2;
      psVar18 = psVar18 + 4;
    } while (uVar34 < (uVar37 & 0xfffffffc));
    if ((int)param_5 <= (int)uVar34) goto LAB_0011639c;
  }
  uVar34 = uVar34 & 0xffffffff;
  uVar20 = (ulong)param_5;
  uVar35 = uVar20 - uVar34;
  uVar12 = uVar34;
  if (7 < uVar35) {
    if (((undefined1 (*) [16])(puVar39 + uVar20 * 2 + 0x1200) <=
         (undefined1 (*) [16])(param_4 + uVar34)) ||
       (param_4 + uVar20 <= (ssc_i16_u *)(puVar39 + uVar34 * 2 + 0x1200))) {
      uVar40 = uVar35 & 0xfffffffffffffff8;
      uVar12 = uVar40 + uVar34;
      pauVar32 = (undefined1 (*) [16])(param_4 + uVar34);
      puVar28 = (ssc_u64_u *)(puVar39 + uVar34 * 2 + 0x1200);
      pauVar13 = (undefined1 (*) [16])(puVar39 + uVar34 * 4 + 0xd80);
      uVar34 = uVar40;
      do {
        uVar59 = puVar28[1];
        uVar55 = *puVar28;
        auVar121 = *(vec128_t *)*pauVar13;
        uVar56 = *(ssc_u64_u *)(pauVar13[1] + 8);
        uVar120 = *(ssc_u64_u *)pauVar13[1];
        uVar34 = uVar34 - 8;
        sVar117 = (short)uVar59;
        sVar45 = (short)((ulong)uVar59 >> 0x10);
        sVar46 = (short)((ulong)uVar59 >> 0x20);
        sVar47 = (short)((ulong)uVar59 >> 0x30);
        sVar48 = (short)((ulong)uVar55 >> 0x10);
        sVar49 = (short)((ulong)uVar55 >> 0x20);
        sVar50 = (short)((ulong)uVar55 >> 0x30);
        auVar124 = *(vec128_t *)*pauVar32;
        iVar8 = (int)((ulong)uVar120 >> 0x20) * CONCAT13(sVar45 >> 0xf,(int3)sVar45);
        iVar57 = (int)((ulong)uVar56 >> 0x20) * CONCAT13(sVar47 >> 0xf,(int3)sVar47);
        auVar98._0_8_ = CONCAT44(auVar121._4_4_ * (int)sVar48,auVar121._0_4_ * (int)(short)uVar55);
        auVar98._8_4_ = auVar121._8_4_ * (int)sVar49;
        auVar98._12_4_ = auVar121._12_4_ * (int)sVar50;
        *(ssc_i64_u *)(*pauVar13 + 8) = auVar98._8_8_;
        *(ssc_u64_u *)*pauVar13 = auVar98._0_8_;
        *(ssc_u64_u *)(pauVar13[1] + 8) =
             CONCAT17((char)((uint)iVar57 >> 0x18),
                      CONCAT16((char)((uint)iVar57 >> 0x10),
                               CONCAT15((char)((uint)iVar57 >> 8),
                                        CONCAT14((char)iVar57,
                                                 (int)uVar56 * CONCAT13(sVar46 >> 0xf,(int3)sVar46))
                                       )));
        *(ssc_u64_u *)pauVar13[1] =
             CONCAT17((char)((uint)iVar8 >> 0x18),
                      CONCAT16((char)((uint)iVar8 >> 0x10),
                               CONCAT15((char)((uint)iVar8 >> 8),
                                        CONCAT14((char)iVar8,
                                                 (int)uVar120 *
                                                 CONCAT13(sVar117 >> 0xf,(int3)sVar117)))));
        *(ssc_u64_u *)(uintptr_t)(((long)(uintptr_t)(uintptr_t)((*pauVar32)) + 8)) =
             CONCAT26(auVar124._14_2_ * sVar47,
                      CONCAT24(auVar124._12_2_ * sVar46,
                               CONCAT22(auVar124._10_2_ * sVar45,auVar124._8_2_ * sVar117)));
        *(ssc_u64_u *)*pauVar32 =
             CONCAT26(auVar124._6_2_ * sVar50,
                      CONCAT24(auVar124._4_2_ * sVar49,
                               CONCAT22(auVar124._2_2_ * sVar48,auVar124._0_2_ * (short)uVar55)));
        pauVar32 = pauVar32 + 1;
        puVar28 = puVar28 + 2;
        pauVar13 = pauVar13 + 2;
      } while (uVar34 != 0);
      if (uVar35 == uVar40) goto LAB_0011639c;
    }
  }
  do {
    uVar34 = uVar12 + 1;
    param_4[uVar12] = param_4[uVar12] * *(ssc_i16_u *)(puVar39 + uVar12 * 2 + 0x1200);
    *(ssc_i32_u *)(puVar39 + uVar12 * 4 + 0xd80) =
         *(ssc_i32_u *)(puVar39 + uVar12 * 4 + 0xd80) * (int)*(ssc_i16_u *)(puVar39 + uVar12 * 2 + 0x1200);
    uVar12 = uVar34;
  } while (uVar20 != uVar34);
LAB_0011639c:
  ssc_encode_pulses((int64_t)(uintptr_t)(puVar39 + 0xd80),param_5,param_6,param_9);
  if ((int)param_8 < 2) {
    uVar12 = 1;
  }
  else {
    iVar8 = 0;
    if (param_8 != 0) {
      iVar8 = (int)param_5 / (int)param_8;
    }
    uVar34 = (ulong)param_8;
    uVar12 = 0;
    lVar19 = (long)iVar8;
    lVar27 = lVar19;
    if (0 < lVar19) {
      lVar27 = 1;
    }
    uVar20 = (lVar19 - lVar27) + 1;
    uVar35 = uVar20 & 0xfffffffffffffff8;
    pauVar32 = (undefined1 (*) [16])(puVar39 + lVar19 * uVar34 * 4 + 0xd70);
    puVar39 = puVar39 + (uVar34 - 1) * lVar19 * 4 + 0xd7c;
    do {
      uVar40 = uVar34 - 1;
      uVar37 = (uint)uVar40;
      lVar27 = lVar19;
      if (uVar20 < 8) {
LAB_001164d8:
        do {
          lVar21 = lVar27 + -1;
          uVar12 = (ulong)((uint)(*(ssc_i32_u *)(puVar39 + lVar27 * 4) != 0) << (ulong)(uVar37 & 0x1f) |
                          (uint)uVar12);
          bVar1 = 0 < lVar27;
          lVar27 = lVar21;
        } while (lVar21 != 0 && bVar1);
      }
      else {
        bVar72 = 0;
        bVar74 = 0;
        bVar77 = 0;
        bVar79 = 0;
        bVar81 = 0;
        bVar83 = 0;
        bVar85 = 0;
        bVar87 = 0;
        bVar89 = 0;
        bVar91 = 0;
        bVar93 = 0;
        bVar95 = 0;
        bVar96 = 0;
        bVar99 = 0;
        bVar100 = 0;
        bVar101 = 0;
        bVar102 = 0;
        bVar104 = 0;
        bVar105 = 0;
        bVar106 = 0;
        bVar107 = 0;
        bVar109 = 0;
        bVar110 = 0;
        bVar111 = 0;
        bVar112 = 0;
        bVar114 = 0;
        bVar115 = 0;
        bVar116 = 0;
        uVar118 = (undefined2)(uVar40 >> 0x10);
        bVar63 = (byte)uVar12;
        bVar65 = (byte)(uVar12 >> 8);
        bVar68 = (byte)(uVar12 >> 0x10);
        bVar70 = (byte)(uVar12 >> 0x18);
        pauVar13 = pauVar32;
        uVar12 = uVar35;
        do {
          pauVar2 = pauVar13 + -1;
          auVar121 = *(vec128_t *)*pauVar13;
          pauVar13 = pauVar13 + -2;
          uVar12 = uVar12 - 8;
          auVar124 = NEON_rev64(*(vec128_t *)*pauVar2,4);
          auVar121 = NEON_rev64(auVar121,4);
          auVar124 = NEON_ext(auVar124,auVar124,8,1);
          auVar121 = NEON_ext(auVar121,auVar121,8,1);
          auVar125.s[0] = ~-(auVar124._0_4_ == 0) & 1;
          auVar125.s[1] = ~-(auVar124._4_4_ == 0) & 1;
          auVar125.s[2] = ~-(auVar124._8_4_ == 0) & 1;
          auVar125.s[3] = ~-(auVar124._12_4_ == 0) & 1;
          auVar122.s[0] = ~-(auVar121._0_4_ == 0) & 1;
          auVar122.s[1] = ~-(auVar121._4_4_ == 0) & 1;
          auVar122.s[2] = ~-(auVar121._8_4_ == 0) & 1;
          auVar122.s[3] = ~-(auVar121._12_4_ == 0) & 1;
          auVar6._4_2_ = (short)uVar40;
          auVar6._0_4_ = uVar37;
          auVar6._6_2_ = uVar118;
          auVar6._8_4_ = uVar37;
          auVar6._12_4_ = uVar37;
          auVar124 = NEON_ushl(auVar125,auVar6,4);
          auVar7._4_2_ = (short)uVar40;
          auVar7._0_4_ = uVar37;
          auVar7._6_2_ = uVar118;
          auVar7._8_4_ = uVar37;
          auVar7._12_4_ = uVar37;
          auVar121 = NEON_ushl(auVar122,auVar7,4);
          bVar96 = auVar124.b[0] | bVar96;
          bVar99 = auVar124.b[1] | bVar99;
          bVar100 = auVar124.b[2] | bVar100;
          bVar101 = auVar124.b[3] | bVar101;
          bVar102 = auVar124.b[4] | bVar102;
          bVar104 = auVar124.b[5] | bVar104;
          bVar105 = auVar124.b[6] | bVar105;
          bVar106 = auVar124.b[7] | bVar106;
          bVar107 = auVar124.b[8] | bVar107;
          bVar109 = auVar124.b[9] | bVar109;
          bVar110 = auVar124.b[10] | bVar110;
          bVar111 = auVar124.b[0xb] | bVar111;
          bVar112 = auVar124.b[0xc] | bVar112;
          bVar114 = auVar124.b[0xd] | bVar114;
          bVar115 = auVar124.b[0xe] | bVar115;
          bVar116 = auVar124.b[0xf] | bVar116;
          bVar63 = auVar121.b[0] | bVar63;
          bVar65 = auVar121.b[1] | bVar65;
          bVar68 = auVar121.b[2] | bVar68;
          bVar70 = auVar121.b[3] | bVar70;
          bVar72 = auVar121.b[4] | bVar72;
          bVar74 = auVar121.b[5] | bVar74;
          bVar77 = auVar121.b[6] | bVar77;
          bVar79 = auVar121.b[7] | bVar79;
          bVar81 = auVar121.b[8] | bVar81;
          bVar83 = auVar121.b[9] | bVar83;
          bVar85 = auVar121.b[10] | bVar85;
          bVar87 = auVar121.b[0xb] | bVar87;
          bVar89 = auVar121.b[0xc] | bVar89;
          bVar91 = auVar121.b[0xd] | bVar91;
          bVar93 = auVar121.b[0xe] | bVar93;
          bVar95 = auVar121.b[0xf] | bVar95;
        } while (uVar12 != 0);
        bVar96 = bVar96 | bVar63;
        bVar99 = bVar99 | bVar65;
        bVar100 = bVar100 | bVar68;
        bVar101 = bVar101 | bVar70;
        bVar102 = bVar102 | bVar72;
        bVar104 = bVar104 | bVar74;
        bVar105 = bVar105 | bVar77;
        bVar106 = bVar106 | bVar79;
        auVar4.b[1] = bVar99;
        auVar4.b[0] = bVar96;
        auVar4.b[2] = bVar100;
        auVar4.b[3] = bVar101;
        auVar4.b[4] = bVar102;
        auVar4.b[5] = bVar104;
        auVar4.b[6] = bVar105;
        auVar4.b[7] = bVar106;
        auVar4.b[8] = bVar107 | bVar81;
        auVar4.b[9] = bVar109 | bVar83;
        auVar4.b[10] = bVar110 | bVar85;
        auVar4.b[0xb] = bVar111 | bVar87;
        auVar4.b[0xc] = bVar112 | bVar89;
        auVar4.b[0xd] = bVar114 | bVar91;
        auVar4.b[0xe] = bVar115 | bVar93;
        auVar4.b[0xf] = bVar116 | bVar95;
        auVar5.b[1] = bVar99;
        auVar5.b[0] = bVar96;
        auVar5.b[2] = bVar100;
        auVar5.b[3] = bVar101;
        auVar5.b[4] = bVar102;
        auVar5.b[5] = bVar104;
        auVar5.b[6] = bVar105;
        auVar5.b[7] = bVar106;
        auVar5.b[8] = bVar107 | bVar81;
        auVar5.b[9] = bVar109 | bVar83;
        auVar5.b[10] = bVar110 | bVar85;
        auVar5.b[0xb] = bVar111 | bVar87;
        auVar5.b[0xc] = bVar112 | bVar89;
        auVar5.b[0xd] = bVar114 | bVar91;
        auVar5.b[0xe] = bVar115 | bVar93;
        auVar5.b[0xf] = bVar116 | bVar95;
        auVar121 = NEON_ext(auVar4,auVar5,8,1);
        uVar12 = (ulong)(CONCAT13(bVar101 | auVar121.b[3],
                                  CONCAT12(bVar100 | auVar121.b[2],
                                           CONCAT11(bVar99 | auVar121.b[1],bVar96 | auVar121.b[0]))) |
                        CONCAT13(bVar106 | auVar121.b[7],
                                 CONCAT12(bVar105 | auVar121.b[6],
                                          CONCAT11(bVar104 | auVar121.b[5],bVar102 | auVar121.b[4]))));
        lVar27 = lVar19 - uVar35;
        if (uVar20 != uVar35) goto LAB_001164d8;
      }
      pauVar32 = (undefined1 (*) [16])(uintptr_t)(((long)(uintptr_t)(uintptr_t)((pauVar32)) + (long)iVar8 * -4));
      puVar39 = puVar39 + (long)iVar8 * -4;
      bVar1 = 1 < (long)uVar34;
      uVar34 = uVar40;
    } while (bVar1);
  }
  return uVar12;
}


/* ==================================================================== */
/* Function: ssc_stereo_itheta @ 00116554 */
/* ==================================================================== */

int ssc_stereo_itheta(long param_1,long param_2,uint param_3)

{
  ssc_i16_u *psVar1;
  ssc_i16_u *psVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined8 uVar19;
  int iVar20;
  undefined8 uVar21;
  int iVar22;
  int iVar23;
  undefined8 uVar24;
  int iVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  undefined8 uVar15;

  if ((int)param_3 < 1) {
    iVar17 = 1;
    iVar6 = 1;
  }
  else {
    uVar10 = (ulong)param_3;
    if (((param_3 < 4) || (uVar13 = uVar10 - 1, param_3 - 1 < (uint)uVar13)) ||
       (uVar13 >> 0x20 != 0)) {
      iVar6 = 1;
      iVar17 = 1;
      uVar11 = uVar10;
    }
    else {
      iVar6 = 0;
      iVar16 = 0;
      uVar11 = uVar10 & 3;
      iVar17 = 0;
      iVar18 = 0;
      uVar9 = uVar10 & 0xfffffffc;
      uVar15 = DAT_00102820;
      uVar19 = DAT_00102820;
      do {
        lVar12 = (uVar13 & 0xffffffff) * 2;
        uVar13 = uVar13 - 4;
        psVar1 = (ssc_i16_u *)(uintptr_t)((param_1 + lVar12));
        psVar2 = (ssc_i16_u *)(uintptr_t)((param_2 + lVar12));
        uVar9 = uVar9 - 4;
        uVar21 = NEON_rev64(CONCAT44((int)*psVar1 >> 1,(int)psVar1[-1] >> 1),4);
        uVar24 = NEON_rev64(CONCAT44((int)psVar1[-2] >> 1,(int)psVar1[-3] >> 1),4);
        uVar26 = NEON_rev64(CONCAT44((int)*psVar2 >> 1,(int)psVar2[-1] >> 1),4);
        uVar27 = NEON_rev64(CONCAT44((int)psVar2[-2] >> 1,(int)psVar2[-3] >> 1),4);
        iVar28 = (int)uVar26 + (int)uVar21;
        iVar22 = (int)((ulong)uVar21 >> 0x20);
        iVar14 = (int)((ulong)uVar26 >> 0x20);
        iVar29 = iVar14 + iVar22;
        iVar20 = (int)uVar21 - (int)uVar26;
        iVar22 = iVar22 - iVar14;
        iVar30 = (int)uVar27 + (int)uVar24;
        iVar25 = (int)((ulong)uVar24 >> 0x20);
        iVar14 = (int)((ulong)uVar27 >> 0x20);
        iVar31 = iVar14 + iVar25;
        iVar23 = (int)uVar24 - (int)uVar27;
        iVar25 = iVar25 - iVar14;
        iVar14 = (int)uVar15 + iVar28 * iVar28;
        iVar28 = (int)((ulong)uVar15 >> 0x20) + iVar29 * iVar29;
        uVar15 = CONCAT44(iVar28,iVar14);
        iVar20 = (int)uVar19 + iVar20 * iVar20;
        iVar22 = (int)((ulong)uVar19 >> 0x20) + iVar22 * iVar22;
        uVar19 = CONCAT44(iVar22,iVar20);
        iVar6 = iVar6 + iVar30 * iVar30;
        iVar16 = iVar16 + iVar31 * iVar31;
        iVar17 = iVar17 + iVar23 * iVar23;
        iVar18 = iVar18 + iVar25 * iVar25;
      } while (uVar9 != 0);
      iVar17 = iVar17 + iVar20 + iVar18 + iVar22;
      iVar6 = iVar6 + iVar14 + iVar16 + iVar28;
      if ((uVar10 & 0xfffffffc) == uVar10) goto LAB_001166bc;
    }
    uVar11 = uVar11 + 1;
    do {
      iVar16 = (int)uVar11;
      uVar11 = uVar11 - 1;
      lVar12 = (ulong)(iVar16 - 2) * 2;
      iVar18 = (int)*(ssc_i16_u *)(uintptr_t)((param_1 + lVar12)) >> 1;
      iVar14 = (int)*(ssc_i16_u *)(uintptr_t)((param_2 + lVar12)) >> 1;
      iVar16 = iVar14 + iVar18;
      iVar18 = iVar18 - iVar14;
      iVar6 = iVar6 + iVar16 * iVar16;
      iVar17 = iVar17 + iVar18 * iVar18;
    } while (1 < uVar11);
  }
LAB_001166bc:
  uVar4 = ssc_sqrt(iVar6);
  uVar5 = ssc_sqrt(iVar17);
  if ((short)uVar5 < (short)uVar4) {
    iVar6 = ssc_rcp((int)((uint)uVar4 << 0x10) >> 0x10);
    uVar8 = (uint)((ulong)((long)iVar6 * (long)((int)((uint)uVar5 << 0x10) >> 1)) >> 0x1f);
    if (0x7ffe < (int)uVar8) {
      uVar8 = 0x7fff;
    }
    uVar3 = -(uVar8 >> 0xf & 1) & 0xfffe0000 | (uVar8 & 0xffff) << 1;
    sVar7 = (short)(((int)(((int)(((short)uVar8 * 0x2690 + -0x2ea68000 >> 0x10) * uVar3 + -0x148000)
                           >> 0x10) * uVar3 + 0x7fff8000) >> 0x10) * (int)(short)uVar8 + 0x4000U >>
                   0xf) >> 1;
  }
  else {
    iVar6 = ssc_rcp((int)((uint)uVar5 << 0x10) >> 0x10);
    uVar8 = (uint)((ulong)((long)iVar6 * (long)((int)((uint)uVar4 << 0x10) >> 1)) >> 0x1f);
    if (0x7ffe < (int)uVar8) {
      uVar8 = 0x7fff;
    }
    uVar3 = -(uVar8 >> 0xf & 1) & 0xfffe0000 | (uVar8 & 0xffff) << 1;
    sVar7 = 0x6488 - (short)((((int)(((int)(((short)uVar8 * 0x2690 + -0x2ea68000 >> 0x10) * uVar3 +
                                           -0x148000) >> 0x10) * uVar3 + 0x7fff8000) >> 0x10) *
                              (int)(short)uVar8 + 0x4000) * 2 >> 0x11);
  }
  return sVar7 * 0x517d >> 0xf;
}


/* ==================================================================== */
/* Function: FUN_001167d0 @ 001167d0 */
/* ==================================================================== */

void FUN_001167d0(ssc_u16_u *param_1,int param_2,short param_3,short param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  ssc_u16_u *puVar9;
  ssc_u16_u *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;

  uVar5 = param_2 - 1;
  iVar7 = (int)param_4;
  uVar13 = param_2 + 2;
  if (-1 < (int)uVar5) {
    uVar13 = uVar5;
  }
  iVar8 = (int)param_3;
  if ((int)(uVar13 & 0xfffffffc) < 1) {
    uVar12 = 0;
    puVar10 = param_1;
    if ((int)uVar5 < 1) goto LAB_0011690c;
  }
  else {
    uVar12 = 0;
    uVar14 = (uint)*param_1;
    puVar9 = param_1;
    do {
      uVar12 = uVar12 + 4;
      iVar11 = ((short)uVar14 * iVar7 + (short)puVar9[1] * iVar8) * 2 >> 0x10;
      puVar10 = puVar9 + 4;
      iVar2 = ((short)puVar9[2] * iVar8 + iVar11 * iVar7) * 2 >> 0x10;
      iVar3 = ((short)puVar9[3] * iVar8 + iVar2 * iVar7) * 2 >> 0x10;
      *puVar9 = (ushort)((uint)((short)uVar14 * iVar8 - (short)puVar9[1] * iVar7) >> 0xf);
      puVar9[1] = (ushort)((uint)(iVar11 * iVar8 - (short)puVar9[2] * iVar7) >> 0xf);
      puVar9[2] = (ushort)((uint)(iVar2 * iVar8 - (short)puVar9[3] * iVar7) >> 0xf);
      uVar14 = (uint)((short)*puVar10 * iVar8 + iVar3 * iVar7) >> 0xf;
      puVar9[3] = (ushort)((uint)(iVar3 * iVar8 - (short)*puVar10 * iVar7) >> 0xf);
      *puVar10 = (ushort)uVar14;
      puVar9 = puVar10;
    } while ((int)uVar12 < (int)(uVar13 & 0xfffffffc));
    if ((int)uVar5 <= (int)uVar12) goto LAB_0011690c;
  }
  uVar13 = (uint)*puVar10;
  iVar11 = ~uVar12 + param_2;
  do {
    puVar9 = puVar10 + 1;
    uVar1 = *puVar9;
    sVar6 = (short)uVar13;
    iVar11 = iVar11 + -1;
    uVar13 = (uint)(sVar6 * iVar7 + (short)uVar1 * iVar8) >> 0xf;
    *puVar9 = (ushort)uVar13;
    *puVar10 = (ushort)((uint)(sVar6 * iVar8 - (short)uVar1 * iVar7) >> 0xf);
    puVar10 = puVar9;
  } while (iVar11 != 0);
LAB_0011690c:
  uVar5 = param_2 - 2;
  uVar13 = uVar5;
  if ((int)uVar5 < 0) {
    uVar13 = param_2 + 1;
  }
  param_1 = param_1 + (param_2 + -3);
  if ((int)(uVar13 & 0xfffffffc) < 1) {
    iVar11 = 0;
    if ((int)uVar5 < 1) {
      return;
    }
  }
  else {
    iVar11 = 0;
    do {
      iVar11 = iVar11 + 4;
      iVar2 = ((short)*param_1 * iVar8 - (short)param_1[1] * iVar7) * 2 >> 0x10;
      iVar3 = ((short)param_1[-1] * iVar8 - iVar2 * iVar7) * 2 >> 0x10;
      param_1[1] = (ushort)((uint)((short)*param_1 * iVar7 + (short)param_1[1] * iVar8) >> 0xf);
      iVar4 = ((short)param_1[-2] * iVar8 - iVar3 * iVar7) * 2 >> 0x10;
      *param_1 = (ushort)((uint)((short)param_1[-1] * iVar7 + iVar2 * iVar8) >> 0xf);
      param_1[-1] = (ushort)((uint)((short)param_1[-2] * iVar7 + iVar3 * iVar8) >> 0xf);
      param_1[-2] = (ushort)((uint)((short)param_1[-3] * iVar7 + iVar4 * iVar8) >> 0xf);
      param_1[-3] = (ushort)((uint)((short)param_1[-3] * iVar8 - iVar4 * iVar7) >> 0xf);
      param_1 = param_1 + -4;
    } while (iVar11 < (int)(uVar13 & 0xfffffffc));
    if ((int)uVar5 <= iVar11) {
      return;
    }
  }
  iVar11 = (param_2 - iVar11) + -2;
  do {
    iVar11 = iVar11 + -1;
    uVar1 = param_1[1];
    param_1[1] = (ushort)((uint)((short)*param_1 * iVar7 + (short)uVar1 * iVar8) >> 0xf);
    *param_1 = (ushort)((uint)((short)*param_1 * iVar8 - (short)uVar1 * iVar7) >> 0xf);
    param_1 = param_1 + -1;
  } while (iVar11 != 0);
  return;
}


/* ==================================================================== */
/* Function: ssc_comb_filter_const_asm @ 00116b00 */

void ssc_comb_filter_const_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, long param_4, int param_5, int param_6, int param_7) {
    int T = (int)param_3;
    int N = (int)param_4;
    int32_t g10 = param_5, g11 = param_6, g12 = param_7;
    for (int i = 0; i < N; i++) {
        int32_t x0 = param_2[i - T + 2];
        int32_t x1 = param_2[i - T + 1];
        int32_t x2 = param_2[i - T];
        int32_t x3 = param_2[i - T - 1];
        int32_t x4 = param_2[i - T - 2];
        int64_t acc = (int64_t)g10 * x2 + (int64_t)g11 * (x1 + x3) + (int64_t)g12 * (x0 + x4) + 0x4000LL;
        param_1[i] = param_2[i] + (int32_t)(acc >> 15);
    }
}

/* Function: ssc_comb_filter_function1_asm @ 00116b90 */

static inline int32_t mult_win_gain(uint32_t win, int32_t g) {
    int32_t hi = (int32_t)win >> 16;
    int32_t lo = (int32_t)(win & 0xffff);
    return (g * hi * 2) + ((lo * g) >> 15);
}

void ssc_comb_filter_function1_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, int param_4, int param_5, ssc_u32_u *param_6) {
    int T = (int)param_3;
    int g1 = param_4;
    int N = param_5;
    ssc_u32_u *win = (ssc_u32_u *)param_6;
    int32_t g10 = (0x2740 * g1) >> 15;
    int32_t g11 = (0x1bc8 * g1) >> 15;
    int32_t g12 = (0x1098 * g1) >> 15;
    for (int i = 0; i < N; i++) {
        int32_t x0 = param_2[i - T + 2];
        int32_t x1 = param_2[i - T + 1];
        int32_t x2 = param_2[i - T];
        int32_t x3 = param_2[i - T - 1];
        int32_t x4 = param_2[i - T - 2];
        int32_t g10_s = mult_win_gain(win[i], g10);
        int32_t g11_s = mult_win_gain(win[i], g11);
        int32_t g12_s = mult_win_gain(win[i], g12);
        int64_t acc = (int64_t)g10_s * x2 + (int64_t)g11_s * (x1 + x3) + (int64_t)g12_s * (x0 + x4) + 0x40000000LL;
        param_1[i] = param_2[i] + (int32_t)(acc >> 31);
    }
}

/* Function: ssc_comb_filter_function2_asm @ 00116c98 */

void ssc_comb_filter_function2_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, int param_4, int param_5, ssc_i32_u *param_6) {
    int T = (int)param_3;
    int g0 = param_4;
    int N = param_5;
    ssc_u32_u *win = (ssc_u32_u *)param_6;
    int32_t g00 = (0x2740 * g0) >> 15;
    int32_t g01 = (0x1bc8 * g0) >> 15;
    int32_t g02 = (0x1098 * g0) >> 15;
    for (int i = 0; i < N; i++) {
        int32_t x0 = param_2[i - T + 2];
        int32_t x1 = param_2[i - T + 1];
        int32_t x2 = param_2[i - T];
        int32_t x3 = param_2[i - T - 1];
        int32_t x4 = param_2[i - T - 2];
        uint32_t w_inv = 0x7fffffffU - win[i];
        int32_t g00_s = mult_win_gain(w_inv, g00);
        int32_t g01_s = mult_win_gain(w_inv, g01);
        int32_t g02_s = mult_win_gain(w_inv, g02);
        int64_t acc = (int64_t)g00_s * x2 + (int64_t)g01_s * (x1 + x3) + (int64_t)g02_s * (x0 + x4) + 0x40000000LL;
        param_1[i] = param_2[i] + (int32_t)(acc >> 31);
    }
}

/* Function: ssc_comb_filter_function3_asm @ 00116dac */

void ssc_comb_filter_function3_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, int param_4, int param_5, int param_6, ssc_u32_u *param_7) {
    int T = (int)param_3;
    int g0 = param_4;
    int g1 = param_5;
    int N = param_6;
    ssc_u32_u *win = (ssc_u32_u *)param_7;
    int32_t g00 = (0x2740 * g0) >> 15;
    int32_t g01 = (0x1bc8 * g0) >> 15;
    int32_t g02 = (0x1098 * g0) >> 15;
    int32_t g10 = (0x2740 * g1) >> 15;
    int32_t g11 = (0x1bc8 * g1) >> 15;
    int32_t g12 = (0x1098 * g1) >> 15;
    for (int i = 0; i < N; i++) {
        int32_t x0 = param_2[i - T + 2];
        int32_t x1 = param_2[i - T + 1];
        int32_t x2 = param_2[i - T];
        int32_t x3 = param_2[i - T - 1];
        int32_t x4 = param_2[i - T - 2];
        uint32_t w_inv = 0x7fffffffU - win[i];
        int32_t gt0 = mult_win_gain(w_inv, g00) + mult_win_gain(win[i], g10);
        int32_t gt1 = mult_win_gain(w_inv, g01) + mult_win_gain(win[i], g11);
        int32_t gt2 = mult_win_gain(w_inv, g02) + mult_win_gain(win[i], g12);
        int64_t acc = (int64_t)gt0 * x2 + (int64_t)gt1 * (x1 + x3) + (int64_t)gt2 * (x0 + x4) + 0x40000000LL;
        param_1[i] = param_2[i] + (int32_t)(acc >> 31);
    }
}

/* Function: ssc_comb_filter_function4_asm @ 00116f48 */

void ssc_comb_filter_function4_asm(ssc_i32_u *param_1, ssc_i32_u *param_2, long param_3, long param_4, int param_5, int param_6, int param_7, ssc_u32_u *param_8) {
    int T0 = (int)param_3;
    int T1 = (int)param_4;
    int g0 = param_5;
    int g1 = param_6;
    int N = param_7;
    ssc_u32_u *win = (ssc_u32_u *)param_8;
    int32_t g00 = (0x2740 * g0) >> 15;
    int32_t g01 = (0x1bc8 * g0) >> 15;
    int32_t g02 = (0x1098 * g0) >> 15;
    int32_t g10 = (0x2740 * g1) >> 15;
    int32_t g11 = (0x1bc8 * g1) >> 15;
    int32_t g12 = (0x1098 * g1) >> 15;
    for (int i = 0; i < N; i++) {
        uint32_t w_inv = 0x7fffffffU - win[i];
        int32_t g00_s = mult_win_gain(w_inv, g00);
        int32_t g01_s = mult_win_gain(w_inv, g01);
        int32_t g02_s = mult_win_gain(w_inv, g02);
        int32_t g10_s = mult_win_gain(win[i], g10);
        int32_t g11_s = mult_win_gain(win[i], g11);
        int32_t g12_s = mult_win_gain(win[i], g12);
        int64_t acc = (int64_t)g00_s * param_2[i - T0] +
                      (int64_t)g01_s * (param_2[i - T0 + 1] + param_2[i - T0 - 1]) +
                      (int64_t)g02_s * (param_2[i - T0 + 2] + param_2[i - T0 - 2]) +
                      (int64_t)g10_s * param_2[i - T1] +
                      (int64_t)g11_s * (param_2[i - T1 + 1] + param_2[i - T1 - 1]) +
                      (int64_t)g12_s * (param_2[i - T1 + 2] + param_2[i - T1 - 2]) + 0x40000000LL;
        param_1[i] = param_2[i] + (int32_t)(acc >> 31);
    }
}

/* Function: ssc_amp2Log2_asm @ 00117200 */

static inline int16_t celt_log2_band(int32_t val, int8_t emean) {
    uint32_t x = (uint32_t)val << 2;
    int lz = (x == 0) ? 32 : __builtin_clz(x);
    int32_t v3 = 18 - lz;
    int32_t v2 = 2 - v3;
    int32_t n;
    if (v2 >= 32) n = 0;
    else if (v2 >= 0) n = (int32_t)(x << v2);
    else if (v2 <= -32) n = ((int32_t)x) >> 31;
    else n = ((int32_t)x) >> (-v2);
    n -= 0xc000;
    int32_t p = -1401;
    p = (int16_t)(((n * p) >> 15) + 2545);
    p = (int16_t)(((n * p) >> 15) - 5217);
    p = (int16_t)(((n * p) >> 15) + 15746);
    p = (int16_t)(((n * p) >> 15) - 6793);
    int32_t res = (p >> 4) + (v3 << 10) - ((int32_t)emean << 6);
    return (int16_t)res;
}

void ssc_amp2Log2_asm(long param_1, ssc_u64_u *param_2, ssc_i16_u *param_3, char *param_4) {
    int n = (int)param_1;
    ssc_i32_u *pE = (ssc_i32_u *)param_2;
    for (int i = 0; i < n; i++) {
        param_3[i] = celt_log2_band(pE[i], (int8_t)param_4[i]);
        param_3[i + n] = celt_log2_band(pE[i + n], (int8_t)param_4[i]);
    }
}

/* Function: ssc_bitexact_cos_asm @ 00117400 */

static inline int32_t bitexact_cos(int32_t x) {
    int32_t x2 = (x * x + 4096) >> 13;
    int32_t m1 = (-626 * x2 + 16384) >> 15;
    int32_t m2 = (x2 * (8277 + m1) + 16384) >> 15;
    int32_t m3 = (x2 * (-7651 + m2) + 16384) >> 15;
    return 32768 - x2 + m3;
}

void ssc_bitexact_cos_asm(int param_1, int param_2, ssc_i32_u *param_3, ssc_i32_u *param_4) {
    *param_3 = bitexact_cos(param_1);
    *param_4 = bitexact_cos(param_2);
}

void ssc_encoder_destroy(void *st) {
    if (st) free(st);
}
