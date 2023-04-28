/* date = 17 Apr 2023 11:46 */

#ifndef BASE_H_
#define BASE_H_

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

#define AlignUpPow2(x,p) (((x) + (p) - 1)&~((p) - 1))
#define AlignDownPow2(x,p) ((x)&~((p) - 1))

#define KB(x) ((x) << 10)
#define MB(x) ((x) << 20)
#define GB(x) ((x) << 30)
#define TB(x) ((x) << 40)

#define global static
#define local static
#define private static

#pragma endregion HELPMACROS


#endif //BASE_H