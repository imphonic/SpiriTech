#pragma once

#include "engine/common.h"

#include "engine/math/vec3/vec3.h"

RPF_OPEN_SUB(math::vec3 )

    /// \section    Constants
    /// \brief      Index to a vector's forward axis (X) component.
    constexpr int  x_        = 0;

    /// \section    Constants
    /// \brief      Index to a vector's right axis (Y) component.
    constexpr int  y_        = 1;

    /// \section    Constants
    /// \brief      Index to a vector's vertical axis (Z) component.
    constexpr int  z_        = 2;

    /// \section    Constants
    /// \brief      Vector with all axes set to zero.
    constexpr type zero_     = {  0,  0,  0 };

    /// \section    Constants
    /// \brief      Vector with all axes set to one.
    constexpr type identity_ = {  1,  1,  1 };

    /// \section    Constants
    /// \brief      Inverted identity vector.
    constexpr type inverse_  = { -1, -1, -1 };

    /// \section    Constants
    /// \brief      Vector with the forward axis (X) set to one, pointing forward.
    constexpr type unit_x_   = {  1,  0,  0 };

    /// \section    Constants
    /// \brief      Inverted unit X vector, pointing backward.
    constexpr type inv_x_    = { -1,  0,  0 };

    /// \section    Constants
    /// \brief      Vector with the right axis (Y) set to one, pointing right.
    constexpr type unit_y_   = {  0,  1,  0 };

    /// \section    Constants
    /// \brief      Inverted unit Y vector, pointing left.
    constexpr type inv_y_    = {  0, -1,  0 };

    /// \section    Constants
    /// \brief      Vector with the vertical axis (Z) set to one, pointing up.
    constexpr type unit_z_   = {  0,  0,  1 };

    /// \section    Constants
    /// \brief      Inverted unit Z vector, pointing down.
    constexpr type inv_z_    = {  0,  0, -1 };

RPF_CLOSE
