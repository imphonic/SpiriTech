#pragma once

// Supported compiler flags

#define RPF_MSVC    0
#define RPF_GCC     0
#define RPF_CLANG   0

#ifdef _MSC_VER
#   undef RPF_MSVC
#   define RPF_MSVC 1
#endif

#ifdef __GNUC__
#   undef RPF_GCC
#   define RPF_GCC 1
#endif

#ifdef __clang__
#   undef RPF_CLANG
#   define RPF_CLANG 1
#endif

// we can use clang with MSVC but not GCC
#if RPF_MSVC && RPF_GCC
#   error "Something's wrong with your compiler check, pal"
#endif
