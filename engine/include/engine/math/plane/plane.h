#pragma once

#include "engine/common.h"

#include "engine/math/vec3/vec3.h"

RPF_OPEN_SUB(math::plane )

    /// \section    Types
    /// \brief      Three-dimensional plane.
    ///
    /// \components normal_      Normal vector of the plane (Ax, By, Cz)
    /// \components d_           Distance of the plane from origin (D).
    ///
    /// \notes      raw_ is for vectorization purposes.
    ///             normal_ is for ease of use with vec3 functions.
    union type
        {
        struct
            {
            union
                {
                struct { double a_, b_, c_; };
                vec3::type normal_;
                };
            double      d_;
            };
        double raw_[4];
        };

RPF_CLOSE
