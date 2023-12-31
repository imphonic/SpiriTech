#pragma once

#include "engine/common.h"

#include "engine/math/utilities.h"

#include "engine/math/simd/simd_types.h"

namespace rpf
{

/// \section    Math Types
/// \brief      Four-dimensional vector.
///
/// \components x_           Forward axis.
/// \components y_           Right axis.
/// \components z_           Vertical axis.
/// \components w_           Enables efficient math (matrix multiplication with FPU, etc).
///
/// \usage      Write as vec4::t
typedef union alignas(16) vec4_t
    {
    struct { float x,y,z,w; };
    __m128 xyzw;
    } vec4_t;

}
