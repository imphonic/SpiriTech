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
#include <cstddef>

namespace Para
  {
    using s8          = std::int8_t;      /* signed 8-bit int */
    using u8          = std::uint8_t;     /* unsigned 8-bit int */

    using s16         = std::int16_t;     /* signed 16-bit int */
    using u16         = std::uint16_t;    /* unsigned 16-bit int */

    using s32         = std::int32_t;     /* signed 32-bit int */
    using u32         = std::uint32_t;    /* unsigned 32-bit int */

    using s64         = std::int64_t;     /* signed 64-bit int */
    using u64         = std::uint64_t;    /* unsigned 64-bit int */

    using f32         = float;            /* signed 32-bit float */
    using f64         = double;           /* signed 64-bit float */

    using str         = const char*;      /* string literal */

    using idx         = std::size_t;      /* container index */
    using dif         = std::ptrdiff_t;   /* container index difference */
  }

#endif /* __PARA_TYPES_HEAD__ */
