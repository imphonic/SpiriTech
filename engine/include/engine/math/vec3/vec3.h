#pragma once

#include "engine/common.h"

RPF_OPEN_SUB(math::vec3 )

    /// \section    Types
    /// \brief      Three-dimensional vector.
    ///
    /// \components x_           Forward axis.  Index 0 in raw_.
    /// \components y_           Right axis.    Index 1 in raw_.
    /// \components z_           Vertical axis. Index 2 in raw_.
    ///
    /// \notes      raw_ is for vectorization purposes.
    union type { struct { double x_,y_,z_; }; double raw_[3]; };

RPF_CLOSE
