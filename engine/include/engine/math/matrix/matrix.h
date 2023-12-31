#pragma once

#include "engine/common.h"

RPF_OPEN_SUB(math::matrix )

    /// \section    Types
    /// \brief      A 4x4 floating-point matrix. Access by [Row][Column]
    ///
    /// \components x_, y_, z_   Imaginary 3D vector.          Indices 0, 1, 2 in raw_.
    /// \components w_           Scalar, no spatial direction. Index 3 in raw_.
    ///
    /// \notes      raw_ is for vectorization purposes.
    struct alignas(16) type { double data_[4][4]; };

RPF_CLOSE
