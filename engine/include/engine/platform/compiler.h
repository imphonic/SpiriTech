#pragma once

// Supported CPU architectures

#define RF_ENGINE_ARCH_ARM 0
#define RF_ENGINE_ARCH_X64 0

// Supported compiler flags

#define RF_ENGINE_USING_MSVC  0
#define RF_ENGINE_USING_GCC   0
#define RF_ENGINE_USING_CLANG 0

#if defined(_M_IX86) || defined(__i386__) || defined(_X86_) || \
  defined(_M_AMD64) || defined(__amd64__) || defined(_M_X64)
  #define RF_ENGINE_ARCH_X64 1
#endif

#if defined(_M_ARM) || defined(__arm__) || defined(__aarch64__)
  #define RF_ENGINE_ARCH_ARM 1
#endif

#ifdef _MSC_VER
  #define RF_ENGINE_USING_MSVC 1
#endif

#ifdef __gnuc__
  #define RF_ENGINE_USING_GCC 1
#endif

#ifdef __clang__
  #define RF_ENGINE_USING_CLANG 1
#endif

#if RF_ENGINE_ARCH_X64 && RF_ENGINE_ARCH_ARM || \
  RF_ENGINE_USING_MSVC && RF_ENGINE_USING_GCC /* we can use clang with MSVC */
  #error "Something's wrong with your inrinsics, pal"
#endif
