/* date = 17 Apr 2023 11:46 */

#ifndef BASE_H_
#define BASE_H_

// Ctx Cracking - Currently has OS and Compiler(CPL), add processor architectures if needed

// OS
#pragma region OSCTX

// GNU Linux
#if defined(__gnu_linux__)
# define OS_GNU_LINUX 1
#endif

#if !defined(OS_GNU_LINUX)
# define OS_GNU_LINUX 0
#endif

// Linux Kernel
#if defined(__linux__)
# define OS_LINUX 1
#endif

#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif

// Windows
#if defined(_WIN32)
# define OS_WINDOWS 1
#endif

#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif

// MacOS
#if defined(__APPLE__) && defined(__MACH__)
# define OS_MAC 1
#endif

#if !defined(OS_MAC)
# define OS_MAC 0
#endif

#pragma endregion OSCTX

// Compiler
#pragma region CPLCTX

// clang
#if defined(__clang__)
# define CPL_CLANG 1
#endif

#if !defined(CPL_CLANG)
# define CPL_CLANG 0
#endif

// visual c++
#if defined(_MSC_VER)
# define CPL_MSC 1
#endif

#if !defined(CPL_MSC)
# define CPL_MSC 0
#endif

// MinGW

#if defined(__MINGW32__)
# define CPL_MGW 1
#endif

#if !defined(CPL_MGW)
# define CPL_MGW 0
#endif

// gcc
#if defined(__GNUC__)
# define CPL_GCC 1
#endif

#if !defined(CPL_GCC)
# define CPL_GCC 0
#endif

// gcc version (because no default tag for it as in clang)
#if defined(__GNUC__)
# if defined(__GNUC_PATCHLEVEL__)
#  define __GNUC_VERSION__ (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
# else
#  define __GNUC_VERSION__ (__GNUC__ * 10000 + __GNUC_MINOR__ * 100)
# endif
#endif

#pragma endregion CPLCTX

#if !defined(ENABLE_ASSERT)
# define ENABLE_ASSERT 0
#endif
// Helper Macros
#pragma region HELPMACROS

#define Stmnt(S) do{ S }while(0)

#if !defined(AssertBreak)
# define AssertBreak() (*(int*)0 = 0)
#endif


// pass -DENABLE_ASSERT=1 to ccr to make #if eval to true
#if ENABLE_ASSERT
#define Assert(c) Stmnt( if (!(c)){ AssertBreak(); } )
#else
#define Assert(c)
#endif

#define Stringify_(S) #S
#define Stringify(S) Stringify_(S)
#define Glue_(A,B) A##B
#define Glue(A,B) Glue_(A,B)

#define ArrayCount(a) (sizeof(a)/sizeof(*(a)))

#define IntFromPtr(p) (unsigned long long)((char*)p - (char*)0)
#define PtrFromInt(n) (void*)((char*)0 + (n))

#define Member(T,m) (((T*)0)->m)
#define OffsetOfMember(T,m) IntFromPtr(&Member(T,m))

#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define Clamp(a,x,b) (((x)<(a))?(a):((b)<(x))?(b):(x))

#define ClampTop(a,b) Min(a,b)
#define ClampBot(a,b) Max(a,b)

#define global static
#define local static
#define private static

#pragma endregion HELPMACROS



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

// Basic Constants
#pragma region BASCONST

global S8 min_S8 = (S8) 0x80;
global S16 min_S16 = (S16) 0x8000;
global S32 min_S32 = (S32) 0x80000000;
global S64 min_S64 = (S64) 0x8000000000000000LL;

global S8 max_S8 = (S8) 0x7f;
global S16 max_S16 = (S16) 0x7fff;
global S32 max_S32 = (S32) 0x7fffffff;
global S64 max_S64 = (S64) 0x7fffffffffffffffLL ;

global U8 max_U8 = 0xff;
global U16 max_U16 = 0xffff;
global U32 max_U32 = 0xffffffff;
global U64 max_U64 = 0xffffffffffffffffllu;

global F32 machine_epsilon_F32 = 1.1920929e-7f;
global F32 pi_F32 = 3.14159265359f;
global F32 tau_F32 = 6.28318530718f;
global F32 e_F32 = 2.71828182846f;
global F32 gold_big_F32 = 1.61803398875f;
global F32 gold_small_F32 = 0.61803398875f;

global F64 machine_epsilon_F64 = 2.220446e-16;
global F64 pi_F64 = 3.14159265359;
global F64 tau_F64 = 6.28318530718;
global F64 e_F64 = 2.71828182846;
global F64 gold_big_F64 = 1.61803398875;
global F64 gold_small_F64 = 0.61803398875;

// float constant functions for infinity b/c no other way to do it
F32 inf_F32(void);
F32 neg_inf_F32(void);
F64 inf_F64(void);
F64 neg_inf_F64(void);

#pragma endregion BASCONST

// Symbolic Constants
#pragma region SYMCONST
typedef enum Axis {
    Axis_X,
    Axis_Y,
    Axis_Z,
    Axis_W,
} Axis;

#pragma endregion SYMCONST

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

// math functions
#pragma region MATHFUNC
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


#pragma endregion MATHFUNC


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


#endif //BASE_H