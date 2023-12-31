#pragma once

#include "engine/common.h"

RPF_OPEN_SUB(math::color )

    /// \section    Types
    /// \brief      Linear 0-255 RGBA color.
    ///
    /// \components r_           Red component.                  Index 0 in raw_.
    /// \components g_           Green component.                Index 1 in raw_.
    /// \components b_           Blue component.                 Index 2 in raw_.
    /// \components a_           Alpha (transparency) component. Index 3 in raw_.
    ///
    /// \notes      raw_ is for vectorization purposes.
    union type { struct { u8 r_, g_, b_, a_; }; u8 raw_[4]; };

RPF_CLOSE

RPF_OPEN_SUB(math::color::linear )

    /// \section    Types
    /// \brief      Linear RGBA color.
    ///
    /// \components r_           Red component.                  Index 0 in raw_.
    /// \components g_           Green component.                Index 1 in raw_.
    /// \components b_           Blue component.                 Index 2 in raw_.
    /// \components a_           Alpha (transparency) component. Index 3 in raw_.
    ///
    /// \notes      raw_ is for vectorization purposes.
    union type { struct { float r_, g_, b_, a_; }; float raw_[4]; };

RPF_CLOSE
