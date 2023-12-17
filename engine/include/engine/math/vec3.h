#pragma once

#include "engine/common.h"

rpf_engine_begin_subspace( math::vec3 )

    /// \section Types \brief 3-dimensional vector.
    /// \components X: Forward/Backward (index 0)
    /// \components Y: Right/Left (index 1)
    /// \components Z: Up/Down (index 2)
    union type { struct { float x_,y_,z_; }; float raw_[3]; };

rpf_engine_end
