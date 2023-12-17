#pragma once

#include "engine/common.h"

#include "engine/math/vec3.h"

rpf_engine_begin_subspace( math::vec3 )

    /// \section Constants \brief Index to a vector's X component (forward/backward).
    constexpr int  x_        = 0;
    /// \section Constants \brief Index to a vector's Y component (right/left).
    constexpr int  y_        = 1;
    /// \section Constants \brief Index to a vector's Z component (up/down).
    constexpr int  z_        = 2;
    /// \section Constants \brief Zero vector.
    constexpr type zero_     = {  0,  0,  0 };
    /// \section Constants \brief Identity vector.
    constexpr type identity_ = {  1,  1,  1 };
    /// \section Constants \brief Inverse identity vector.
    constexpr type inverse_  = { -1, -1, -1 };
    /// \section Constants \brief Vector pointed forward.
    constexpr type unit_x_   = {  1,  0,  0 };
    /// \section Constants \brief Vector pointed backward.
    constexpr type inv_x_    = { -1,  0,  0 };
    /// \section Constants \brief Vector pointed right.
    constexpr type unit_y_   = {  0,  1,  0 };
    /// \section Constants \brief Vector pointed left.
    constexpr type inv_y_    = {  0, -1,  0 };
    /// \section Constants \brief Vector pointed up.
    constexpr type unit_z_   = {  0,  0,  1 };
    /// \section Constants \brief Vector pointed down.
    constexpr type inv_z_    = {  0,  0, -1 };

rpf_engine_end
