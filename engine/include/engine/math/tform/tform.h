#pragma once

#include "engine/common.h"

#include "engine/math/register/vecreg.h"

RPF_OPEN_SUB(math::tform )

    using math::simd::FP_REG_ALIGN;

    /// \section    Types
    /// \brief      Position and rotation (quaternion) in 3D space.
    ///
    /// \components pos_         Position in 3D space.
    /// \components rot_         Rotation in 3D space.
    ///
    /// \notes      raw_ is for vectorization purposes.
    ///             Fits in a 64-byte cache line.
    union alignas(FP_REG_ALIGN) stripped
        {
        struct{ simd::d256 pos_, rot_; };
        simd::d512 posrot_;
        double raw_[8];
        };

    /// \section    Types
    /// \brief      Position, rotation (quaternion), and scale in 3D space.
    ///
    /// \components x_, y_, z_   Position in 3D space.
    ///
    /// \notes      raw_ is for vectorization purposes.
    union alignas(FP_REG_ALIGN) type
        {
        struct { stripped posrot_; };
        struct { simd::d256 pos_, rot_, scl_; };
        double raw_[12];
        };

    RPF_CLOSE
