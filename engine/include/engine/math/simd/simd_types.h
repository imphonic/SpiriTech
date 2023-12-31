#pragma once

#include "engine/common.h"

#if RPF_MSVC
#   include <intrin.h>
#else
#   include <immintrin.h>
#endif

RPF_OPEN_SUB(math::simd )

    constexpr int vec_align =
    #if rpf_use_avx
        32;
    #else
        16;
    #endif

    typedef union alignas(16) v128
        {
        struct { double x_, y_; };
        __m128d reg_;
        } v128;

    typedef union alignas(vec_align) v256
        {
        struct { double x_, y_, z_, w_; };
        struct { v128 xy_, zw_; };
        #if rpf_use_avx
        __m256d reg_;
        #endif
        } v256;

    using d128 = __m128d;

    union alignas(vec_align) d256
        {
        struct { double x_, y_, z_, w_; };
        struct { d128 xy_, zw_; };
        double m256d_[4];
        };

RPF_CLOSE
