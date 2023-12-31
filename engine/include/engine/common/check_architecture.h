#pragma once

// Supported CPU architectures

#define RPF_ARCH_ARM    0
#define RPF_ARCH_RISCV  0
#define RPF_ARCH_X64    0

#if defined(_M_X64) || defined(__i386__) || defined(_X86_) || defined(__x86_64__)
#   undef RPF_ARCH_X64
#   define RPF_ARCH_X64 1
#endif

#if defined(_M_ARM) || defined(__arm__) || defined(__aarch64__)
#   undef RPF_ARCH_ARM
#   define RPF_ARCH_ARM 1
#endif

#if 0 // We don't have a check for RISC-V yet but hope to in the future
#   undef RPF_ARCH_RISCV
#   define RPF_ARCH_RISCV 1
#endif

// Only one architecture should be valid at any given time
#if (RPF_ARCH_X64 + RPF_ARCH_ARM + RPF_ARCH_RISCV > 1)
#   error "Something's wrong with your architecture check, pal"
#endif
