/* date = 17 Apr 2023 11:46 */

#include "base.h"
#include <stdio.h>
#include <stdlib.h>

F32 inf_F32(void) {
    union{ F32 f; U32 u; } r;
    r.u = 0x7f800000;
    return r.f;
}

F32 neg_inf_F32(void) {
    union{ F32 f; U32 u; } r;
    r.u = 0xff800000;
    return r.f;
}

F64 inf_F64(void) {
    union{ F64 f; U64 u; } r;
    r.u = 0x7ff0000000000000;
    return r.f;
}

F64 neg_inf_F64(void) {
    union{ F64 f; U64 u; } r;
    r.u = 0xfff0000000000000;
    return r.f;
}

F32 abs_F32(F32 x) {
    union{ F32 f; U32 u; } r;
    r.f = x;
    r.u &= 0x7fffffff;
    return r.f;
}

F64 abs_F64(F64 x) {
    union{ F64 f; U64 u; } r;
    r.f = x;
    r.u &= 0x7fffffffffffffff;
    return r.f;
}

#include <math.h>

F32 sqrt_F32(F32 x) {
    return sqrtf(x);
}

F32 sin_F32(F32 x) {
    return sinf(x);
}

F32 cos_F32(F32 x) {
    return cosf(x);
}

F32 tan_F32(F32 x) {
    return tanf(x);
}

F32 ln_F32(F32 x) {
    return logf(x);
}

F64 sqrt_F64(F64 x) {
    return sqrt(x);
}

F64 sin_F64(F64 x) {
    return sin(x);
}

F64 cos_F64(F64 x) {
    return cos(x);
}

F64 tan_F64(F64 x) {
    return tan(x);
}

F64 ln_F64(F64 x) {
    return log(x);
}

F32 lerp(F32 a, F32 t, F32 b) {
    F32 x = a + (b - a)*t;
    return x;
}

F32 unlerp(F32 a, F32 x, F32 b) {
    F32 t = 0.f;
    if (a != b) {
        t = (x - a)/(b - a);
    }

    return t;
}

void generic_stmt_err(a,b) {
    // basically, incorrect types passed into function
    printf("Incorrect type passed into function.\n");
    exit(1);
}


V2S32 v2s32(S32 x, S32 y) {
    V2S32 r = {x, y};
    return r;
}

V2F32 v2f32(F32 x, F32 y) {
    V2F32 r = {x, y};
    return r;
}
V3F32 v3f32(F32 x, F32 y, F32 z) {
    V3F32 r = {x, y, z};
    return r;
}
V4F32 v4f32(F32 x, F32 y, F32 z, F32 w) {
    V4F32 r = {x, y, z, w};
    return r;
}

I1F32 i1f32(F32 min, F32 max) {
    I1F32 r = {min, max};
    if (max < min) {
        r.min = max;
        r.max = min;
    }
    return r;
}
I1U64 i1u64(U64 min, U64 max) {
    I1U64 r = {min, max};
    if (max < min) {
        r.min = max;
        r.max = min;
    }
    return r;
}

I2S32 i2s32(S32 x0, S32 x1, S32 y0, S32 y1) {
    I2S32 r = {x0, y0, x1, y1};
    if (x1 < x0) {
        r.x0 = x1;
        r.x1 = x0;
    }
    if (y1 < y0) {
        r.y0 = y1;
        r.y1 = y0;
    }
    return r;
}
I2S32 i2s32_vec(V2S32 min, V2S32 max) {
    I2S32 r = i2s32(min.x, min.y, max.x, max.y);
    return r;
}

I2F32 i2f32(F32 x0, F32 x1, F32 y0, F32 y1) {
    I2F32 r = {x0, y0, x1, y1};
    if (x1 < x0) {
        r.x0 = x1;
        r.x1 = x0;
    }
    if (y1 < y0) {
        r.y0 = y1;
        r.y1 = y0;
    }
    return r;
}
I2F32 i2f32_vec(V2F32 min, V2F32 max) {
    I2F32 r = i2f32(min.x, min.y, max.x, max.y);
    return r;
}
I2F32 i2f32_range(I1F32 x, I1F32 y) {
    I2F32 r = i2f32(x.min, y.min, x.max, y.max);
    return r;
}

V2S32 add_v2s32(V2S32 *a, V2S32 *b) {
    V2S32 r = {a->x + b->x, a->y + b->y};
    return r;
}
V2F32 add_v2f32(V2F32 *a, V2F32 *b) {
    V2F32 r = {a->x + b->x, a->y + b->y};
    return r;
}
V3F32 add_v3f32(V3F32 *a, V3F32 *b) {
    V3F32 r = {a->x + b->x, a->y + b->y, a->z + b->z};
    return r;
}
V4F32 add_v4f32(V4F32 *a, V4F32 *b) {
    V4F32 r = {a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w};
    return r;
}

V2S32 subtract_v2s32(V2S32 *a, V2S32 *b) {
    V2S32 r = {a->x - b->x, a->y - b->y};
    return r;
}
V2F32 subtract_v2f32(V2F32 *a, V2F32 *b) {
    V2F32 r = {a->x - b->x, a->y - b->y};
    return r;
}
V3F32 subtract_v3f32(V3F32 *a, V3F32 *b) {
    V3F32 r = {a->x - b->x, a->y - b->y, a->z - b->z};
    return r;
}
V4F32 subtract_v4f32(V4F32 *a, V4F32 *b) {
    V4F32 r = {a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w};
    return r;
}

V2S32 multiply_v2s32_a1(V2S32 *v, S32 *s) {
    S32 is = *s;
    V2S32 r = {v->x * is, v->y * is};
    return r;
}
V2F32 multiply_v2f32_a1(V2F32 *v, F32 *s) {
    F32 is = *s;
    V2F32 r = {v->x * is, v->y * is};
    return r;
}
V3F32 multiply_v3f32_a1(V3F32 *v, F32 *s) {
    F32 is = *s;
    V3F32 r = {v->x * is, v->y * is, v->z * is};
    return r;
}
V4F32 multiply_v4f32_a1(V4F32 *v, F32 *s) {
    F32 is = *s;
    V4F32 r = {v->x * is, v->y * is, v->z * is, v->w * is};
    return r;
}

V2S32 multiply_v2s32_a2(S32 *s, V2S32 *v) {
    S32 is = *s;
    V2S32 r = {v->x * is, v->y * is};
    return r;
}
V2F32 multiply_v2f32_a2(F32 *s, V2F32 *v) {
    F32 is = *s;
    V2F32 r = {v->x * is, v->y * is};
    return r;
}
V3F32 multiply_v3f32_a2(F32 *s, V3F32 *v) {
    F32 is = *s;
    V3F32 r = {v->x * is, v->y * is, v->z * is};
    return r;
}
V4F32 multiply_v4f32_a2(F32 *s, V4F32 *v) {
    F32 is = *s;
    V4F32 r = {v->x * is, v->y * is, v->z * is, v->w * is};
    return r;
}



V2F32 hadamard_v2(V2F32 a, V2F32 b) {
    V2F32 r = {a.x * b.x, a.y * b.y};
    return r;
}
V3F32 hadamard_v3(V3F32 a, V3F32 b) {
    V3F32 r = {a.x * b.x, a.y * b.y, a.z * b.z};
    return r;
}
V4F32 hadamard_v4(V4F32 a, V4F32 b) {
    V4F32 r = {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
    return r;
}

F32 dot_v2(V2F32 a, V2F32 b) {
    F32 r = a.x * b.x + a.y * b.y;
    return r;
}
F32 dot_v3(V3F32 a, V3F32 b) {
    F32 r = a.x * b.x + a.y * b.y + a.z * b.z;
    return r;
}
F32 dot_v4(V4F32 a, V4F32 b) {
    F32 r = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return r;
}

B32 overlaps_i1f(I1F32 a, I1F32 b) {
    B32 result = (b.min < a.max && a.min < b.max);
    return result;
}
B32 contains_i1f(I1F32 r, F32 x) {
    B32 result = (r.min <= x && x < r.max);
    return result;
}

B32 overlaps_i2f(I2F32 a, I2F32 b) {
    B32 result = (b.x0 < a.x1 && a.x0 < b.x1 && b.y0 < a.y1 && a.y0 < b.y1);
    return result;
}
B32 contains_i2f(I2F32 r, V2F32 x) {
    B32 result = (r.x0 <= x.x && x.x < r.x1 && r.y0 <= x.y && x.y < r.y1);
    return result;
}

B32 overlaps_i2s(I2S32 a, I2S32 b) {
    B32 result = (b.x0 < a.x1 && a.x0 < b.x1 && b.y0 < a.y1 && a.y0 < b.y1);
    return result;
}
B32 contains_i2s(I2S32 r, V2S32 x) {
    B32 result = (r.x0 <= x.x && x.x < r.x1 && r.y0 <= x.y && x.y < r.y1);
    return result;
}

F32 dim_i1f(I1F32 r) {
    F32 result = r.max - r.min;
    return result;
}
U64 dim_i1u(I1U64 r) {
    U64 result = r.max - r.min;
    return result;
}
V2F32 dim_i2f(I2F32 r) {
    V2F32 result = v2f32(r.x1 - r.x0, r.y1 - r.y0);
    return result;
}
V2S32 dim_i2s(I2S32 r) {
    V2S32 result = v2s32(r.x1 - r.x0, r.y1 - r.y0);
    return result;
}

F32 center_i1f(I1F32 r) {
    F32 result = (r.min + r.max) * 0.5f;
    return result;
}
U64 center_i1u(I1U64 r) {
    U64 result = (U64) (r.min + r.max) * 0.5f;
    return result;
}
V2F32 center_i2f(I2F32 r) {
    F32 mul = (F32) 0.5f;
    V2F32 result = add_v2f32(&(r.min), &(r.max));
    result = multiply_v2f32_a1(&result, &mul);
    return result;
}

I1F32 axis(I2F32 r, Axis axis) {
    I1F32 result = { r.p[0].v[axis], r.p[1].v[axis]};
    return result;
}