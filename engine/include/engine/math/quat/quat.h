#pragma once

#include "engine/common.h"

RPF_OPEN_SUB(math::quat )

    /// \section    Types
    /// \brief      Represents a rotation about a 3D axis.
    ///
    /// \components x_, y_, z_   Imaginary 3D vector.          Indices 0, 1, 2 in raw_.
    /// \components w_           Scalar, no spatial direction. Index 3 in raw_.
    ///
    /// \notes      raw_ is for vectorization purposes.
    union alignas(16) type { struct { double x_,y_,z_,w_; }; double raw_[4]; };

RPF_CLOSE
