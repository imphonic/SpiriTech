#pragma once

#include "engine/common.h"

#define rpf_arch_arm 0
#define rpf_arch_x64 0

#if defined(_M_IX86) || defined(__i386__) || defined(_X86_) || defined(_M_AMD64) || defined(__amd64__) || defined(_M_X64)
  #define RF_ENGINE_ARCH_X64 1
#endif

#if defined(_M_ARM) || defined(__arm__) || defined(__aarch64__)
  #define RF_ENGINE_ARCH_ARM 1
#endif

#if RPF_ARCH_X64 && RPF_ARCH_ARM
  #error "Something's wrong with your inrinsics, pal"
#endif

#ifdef _MSC_VER
  #include <intrin.h>
#endif

#if defined(__gnuc__) || defined(__clang__)
  #if RF_ENGINE_ARCH_X64
    #include <x86intrin.h>
  #endif


#endif

namespace rpf::internal
  {
    /**
     * Base class for compiler intrinsics. Do not use directly.
     */
    class intrinsics_base
      {
      public:
        static void prefetch(auto const*, constexpr int, constexpr int) = delete;
        static int find_first_set(constexpr int) = delete;
      };
  }
