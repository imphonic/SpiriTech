#pragma once

/// \section    Keyword Macros
/// \brief      Declares a symbol constexpr.
#define RPF_CONSTEXPR       constexpr

#ifdef _MSC_VER
/// \section    Keyword Macros
/// \brief      Forces a sybol to be inlined.
#   define RPF_INLINE       __forceinline
#elif defined(__GNUC__) || defined(__clang__)
/// \section    Keyword Macros
/// \brief      Forces a sybol to be inlined.
#   define RPF_INLINE       inline __attribute__((always_inline))
#else
/// \section    Keyword Macros
/// \brief      Forces a sybol to be inlined.
#   define RPF_INLINE       inline
#endif
