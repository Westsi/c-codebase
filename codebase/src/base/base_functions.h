/* date = 26 Apr 2023 18:26 */

#ifndef BASE_FUNCTIONS_H_
#define BASE_FUNCTIONS_H_
#include "base_types.h"
#include "base_constants.h"
#include <stdio.h>

// Symbolic Constant Functions
#pragma region SYMCONSTFUNCS

OperatingSystem operating_system_from_ctx(void);

char* string_from_operating_system(OperatingSystem os);
char* string_from_month(Month month);
char* string_from_day_of_week(DayOfWeek day_of_week);

#pragma endregion SYMCONSTFUNCS

// math functions
#pragma region MATHFUNCS
F32 abs_F32(F32 x);
F64 abs_F64(F64 x);

F32 sqrt_F32(F32 x);
F32 sin_F32(F32 x);
F32 cos_F32(F32 x);
F32 tan_F32(F32 x);
F32 ln_F32(F32 x);

F64 sqrt_F64(F64 x);
F64 sin_F64(F64 x);
F64 cos_F64(F64 x);
F64 tan_F64(F64 x);
F64 ln_F64(F64 x);

F32 lerp(F32 a, F32 t, F32 b);
F32 unlerp(F32 a, F32 x, F32 b);


#pragma endregion MATHFUNCS


// Compound Type Functions
#pragma region COMPTYPEFUNCS
V2S32 v2s32(S32 x, S32 y);

V2F32 v2f32(F32 x, F32 y);
V3F32 v3f32(F32 x, F32 y, F32 z);
V4F32 v4f32(F32 x, F32 y, F32 z, F32 w);

I1F32 i1f32(F32 min, F32 max);
I1U64 i1u64(U64 min, U64 max);

I2S32 i2s32(S32 x0, S32 x1, S32 y0, S32 y1);
I2S32 i2s32_vec(V2S32 min, V2S32 max);

I2F32 i2f32(F32 x0, F32 x1, F32 y0, F32 y1);
I2F32 i2f32_vec(V2F32 min, V2F32 max);
I2F32 i2f32_range(I1F32 x, I1F32 y);

V2S32 add_v2s32(V2S32 *a, V2S32 *b);
V2F32 add_v2f32(V2F32 *a, V2F32 *b);
V3F32 add_v3f32(V3F32 *a, V3F32 *b);
V4F32 add_v4f32(V4F32 *a, V4F32 *b);

V2S32 subtract_v2s32(V2S32 *a, V2S32 *b);
V2F32 subtract_v2f32(V2F32 *a, V2F32 *b);
V3F32 subtract_v3f32(V3F32 *a, V3F32 *b);
V4F32 subtract_v4f32(V4F32 *a, V4F32 *b);

V2S32 multiply_v2s32_a1(V2S32 *v, S32 *s);
V2F32 multiply_v2f32_a1(V2F32 *v, F32 *s);
V3F32 multiply_v3f32_a1(V3F32 *v, F32 *s);
V4F32 multiply_v4f32_a1(V4F32 *v, F32 *s);

V2S32 multiply_v2s32_a2(S32 *s, V2S32 *v);
V2F32 multiply_v2f32_a2(F32 *s, V2F32 *v);
V3F32 multiply_v3f32_a2(F32 *s, V3F32 *v);
V4F32 multiply_v4f32_a2(F32 *s, V4F32 *v);

V2F32 hadamard_v2(V2F32 a, V2F32 b);
V3F32 hadamard_v3(V3F32 a, V3F32 b);
V4F32 hadamard_v4(V4F32 a, V4F32 b);

F32 dot_v2(V2F32 a, V2F32 b);
F32 dot_v3(V3F32 a, V3F32 b);
F32 dot_v4(V4F32 a, V4F32 b);

B32 overlaps_i1f(I1F32 a, I1F32 b);
B32 contains_i1f(I1F32 r, F32 x);

B32 overlaps_i2f(I2F32 a, I2F32 b);
B32 contains_i2f(I2F32 r, V2F32 x);

B32 overlaps_i2s(I2S32 a, I2S32 b);
B32 contains_i2s(I2S32 r, V2S32 x);

F32 dim_i1f(I1F32 r);
U64 dim_i1u(I1U64 r);
V2F32 dim_i2f(I2F32 r);
V2S32 dim_i2s(I2S32 r);

F32 center_i1f(I1F32 r);
U64 center_i1u(I1U64 r);
V2F32 center_i2f(I2F32 r);

I1F32 axis(I2F32 r, Axis axis);

// TODO: implement generic macros for operators using add(), subtract() notation
#define add(a,b) _Generic((a), \
    V2S32: add_v2s32, \
    V2F32: add_v2f32, \
    V3F32: add_v3f32, \
    V4F32: add_v4f32, \
    default: generic_stmt_err)(a,b)

#define subtract(a,b) _Generic((a), \
    V2S32: subtract_v2s32, \
    V2F32: subtract_v2f32, \
    V3F32: subtract_v3f32, \
    V4F32: subtract_v4f32, \
    default: generic_stmt_err)(a,b)

#define multiply(a,b) _Generic((a), \
    V2S32: multiply_v2s32_a1, \
    V2F32: multiply_v2f32_a1, \
    V3F32: multiply_v3f32_a1, \
    V4F32: multiply_v4f32_a1, \
    S32: multiply_v2s32_a2, \
    F32: _Generic((b), \
        V2F32: multiply_v2f32_a2, \
        V3F32: multiply_v3f32_a2, \
        V4F32: multiply_v4f32_a2, \
        default: generic_stmt_err), \
    default: generic_stmt_err)(a,b)


// generic macro functions for the specific functions
#define hadamard(a,b) _Generic((a), \
    V2F32: hadamard_v2, \
    V3F32: hadamard_v3, \
    V4F32: hadamard_v4, \
    default: generic_stmt_err)(a,b)

#define dot(a,b) _Generic((a), \
    V2F32: dot_v2, \
    V3F32: dot_v3, \
    V4F32: dot_v4, \
    default: generic_stmt_err)(a,b)

#define dim(a,b) _Generic((a), \
    I1F32: dim_i1f, \
    I1U64: dim_i1u, \
    I2F32: dim_i2f, \
    I2S32: dim_i2s, \
    default: generic_stmt_err)(a,b)

#define center(a,b) _Generic((a), \
    I1F32: center_i1f, \
    I1U64: center_i1u, \
    I2F32: center_i2f, \
    default: generic_stmt_err)(a,b)

#define overlaps(a,b) _Generic((a), \
    I1F32: overlaps_i1f, \
    I2F32: overlaps_i2f, \
    I2S32: overlaps_i2s, \
    default: generic_stmt_err)(a,b)

#define contains(a,b) _Generic((a), \
    I1F32: contains_i1f, \
    I2F32: contains_i2f, \
    I2S32: contains_i2s, \
    default: generic_stmt_err)(a,b)

void generic_stmt_err(a,b);

#pragma endregion COMPTYPEFUNCS


#endif //BASE_FUNCTIONS_H