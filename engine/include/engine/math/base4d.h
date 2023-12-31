#pragma once

#include "engine/common.h"

#include <immintrin.h>

namespace rpf::internal
{

struct base4d_t
    {
    union
        {
        struct { float x,y,z,w; };
        __m128 raw;
        };
    };

}

namespace rpf
{

struct vec4 : public internal::base4d_t {};
struct quat4 : public internal::base4d_t {};

}
