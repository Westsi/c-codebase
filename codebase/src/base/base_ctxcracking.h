/* date = 26 Apr 2023 18:25 */

#ifndef BASE_CTXCRACKING_H_
#define BASE_CTXCRACKING_H_

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


#endif //BASE_CTXCRACKING_H