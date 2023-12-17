#pragma once

#include "engine/common.h"

namespace rpf
{
    /**
    * 3-dimensional quaternion.
    * Indices 0-2: Imaginary 3d vector (corresponds to vec3_t)
    * Index 3: W-value (real angle)
    */
    using quat_t = float[4];
}
/* namespace rpf */
