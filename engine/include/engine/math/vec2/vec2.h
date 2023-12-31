#pragma once

#include "engine/common.h"

RPF_OPEN_SUB(math::vec2 )

    /// \section    Types
    /// \brief      Two-dimensional vector.
    ///
    /// \components x_           Horizontal axis (right/left). Index 0 in raw_.
    /// \components y_           Vertical axis   (up/down).    Index 1 in raw_.
    ///
    /// \notes      raw_ is for vectorization purposes.
    union type { struct { double x_,y_; }; double raw_[2]; };

RPF_CLOSE
