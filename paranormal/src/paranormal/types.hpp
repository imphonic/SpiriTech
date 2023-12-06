/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: types.hpp
 * @brief: Primitive engine types.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_TYPES_HEAD__
#define __PARA_TYPES_HEAD__

#include <cstdint>

namespace Para
  {
    using s8          = std::int8_t;
    using u8          = std::uint8_t;

    using s16         = std::int16_t;
    using u16         = std::uint16_t;

    using s32         = std::int32_t;
    using u32         = std::uint32_t;

    using s64         = std::int64_t;
    using u64         = std::uint64_t;

    using f32         = float;
    using f64         = double;

    using str         = const char*;
  }

#endif /* __PARA_TYPES_HEAD__ */
