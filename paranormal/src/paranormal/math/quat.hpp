/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: quat.hpp
 * @brief: Implements a quaternion.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_QUAT_HEAD__
#define __PARA_QUAT_HEAD__

#include "../platform.hpp"

namespace Para::Math
  {
    using quat4_t = union Quat
      {
        using val_t = float;

        /* Use this to access elements individually. */
        struct
          {
            val_t x, y, z, w;
          };

        /* Allows for easy vectorization. */
        val_t data[4];
      };

    constexpr quat4_t operator+(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t loc_return;
        /* Designed for easy vectorization. */
        for (int i = 0; i < 4; i++)
          {
            loc_return.data[i] = in_a.data[i] + in_b.data[i];
          }
        return loc_return;
      }

    constexpr quat4_t operator-(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t loc_return;
        /* Designed for easy vectorization. */
        for (int i = 0; i < 4; i++)
          {
            loc_return.data[i] = in_a.data[i] - in_b.data[i];
          }
        return loc_return;
      }

    constexpr quat4_t::val_t Dot(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t::val_t loc_return {};
        for (int i = 0; i < 4; i++)
          {
            loc_return += in_a.data[i] * in_b.data[i];
          }
        return loc_return;
      }
  }

#endif /* __PARA_QUAT_HEAD__ */
