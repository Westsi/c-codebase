/* date = 26 Apr 2023 18:26 */

#ifndef BASE_TYPES_H_
#define BASE_TYPES_H_

// Basic Types
#pragma region BASTYPES
#include <stdint.h>
typedef int8_t S8; // Signed 8 bit
typedef int16_t S16; // Signed 16 bit
typedef int32_t S32; // Signed 32 bit
typedef int64_t S64; // Signed 64 bit
typedef uint8_t U8; // Unsigned 8 bit
typedef uint16_t U16; // Unsigned 16 bit
typedef uint32_t U32; // Unsigned 32 bit
typedef uint64_t U64; // Unsigned 64 bit
typedef S8 B8; // 8 bit boolean
typedef S16 B16; // 16 bit boolean
typedef S32 B32; // 32 bit boolean
typedef S64 B64; // 64 bit boolean
typedef float F32; // 32 bit float
typedef double F64; // 64 bit float

typedef void VoidFunc(void);


#pragma endregion BASTYPES

// Compound Types
#pragma region COMPTYPES
typedef union V2S32 {
    struct {
        S32 x;
        S32 y;
    };
    S32 v[2];
} V2S32;

typedef union V2F32 {
    struct {
        F32 x;
        F32 y;
    };
    F32 v[2];
} V2F32;

typedef union V3F32 {
    struct {
        F32 x;
        F32 y;
        F32 z;
    };
    F32 v[3];
} V3F32;

typedef union V4F32 {
    struct {
        F32 x;
        F32 y;
        F32 z;
        F32 w;
    };
    F32 v[4];
} V4F32;

typedef union I1F32 {
    struct {
        F32 min;
        F32 max;
    };
    F32 v[2];
} I1F32;

typedef union I1U64 {
    struct {
        U64 min;
        U64 max;
    };
    struct {
        U64 first;
        U64 opl;
    };
    U64 v[2];
} I1U64;

typedef union I2S32 {
    struct {
        V2S32 min;
        V2S32 max;
    };
    struct {
        V2F32 p0;
        V2F32 p1;
    };
    struct {
        S32 x0;
        S32 x1;
        S32 y0;
        S32 y1;
    };
    V2S32 p[2];
    S32 v[4];
} I2S32;

typedef union I2F32 {
    struct {
        V2F32 min;
        V2F32 max;
    };
    struct {
        V2F32 p0;
        V2F32 p1;
    };
    struct {
        F32 x0;
        F32 x1;
        F32 y0;
        F32 y1;
    };
    V2F32 p[2];
    F32 v[4];
} I2F32;

#pragma endregion COMPTYPES

#endif //BASE_TYPES_H