#pragma once

#include "engine/common.h"

#include "engine/math/vec2/vec2.h"

RPF_OPEN_SUB(math::vec2 )

    /// \section    Constants
    /// \brief      Index to a vector's horizontal axis (X) component.
    constexpr int  x_        = 0;

    /// \section    Constants
    /// \brief      Index to a vector's vertical axis (Y) component.
    constexpr int  y_        = 1;

    /// \section    Constants
    /// \brief      Vector with all axes set to zero.
    constexpr type zero_     = {  0,  0 };

    /// \section    Constants
    /// \brief      Vector with all axes set to one.
    constexpr type identity_ = {  1,  1 };

    /// \section    Constants
    /// \brief      Inverted identity vector.
    constexpr type inverse_  = { -1, -1 };

    /// \section    Constants
    /// \brief      Vector with the horizontal axis (X) set to one, pointing right.
    constexpr type unit_x_   = {  1,  0 };

    /// \section    Constants
    /// \brief      Inverted unit X vector, pointing left.
    constexpr type inv_x_    = { -1,  0 };

    /// \section    Constants
    /// \brief      Vector with the vertical axis (Y) set to one, pointing up.
    constexpr type unit_y_   = {  0,  1 };

    /// \section    Constants
    /// \brief      Inverted unit Y vector, pointing down.
    constexpr type inv_y_    = {  0, -1 };

RPF_CLOSE
