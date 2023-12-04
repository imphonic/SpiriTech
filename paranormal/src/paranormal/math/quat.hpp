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
    struct Quat
      {
        /* Type used for quaternion values. */
        using val_t = float;
        /* Storage for the quaternion. Easily vectorized.. */
        val_t data[4];
        enum { X=0, Y=1, Z=2, W=3 };
      };

    constexpr Quat operator+(const Quat in_a, const Quat in_b)
      {
        Quat loc_return;
        /* Designed for easy vectorization. */
        for (int i = 0; i < 4; i++)
          {
            loc_return.data[i] = in_a.data[i] + in_b.data[i];
          }
        return loc_return;
      }

    constexpr Quat operator-(const Quat in_a, const Quat in_b)
      {
        Quat loc_return;
        /* Designed for easy vectorization. */
        for (int i = 0; i < 4; i++)
          {
            loc_return.data[i] = in_a.data[i] - in_b.data[i];
          }
        return loc_return;
      }

    constexpr Quat::val_t Dot(const Quat in_a, const Quat in_b)
      {
        Quat::val_t loc_return {};
        for (int i = 0; i < 4; i++)
          {
            loc_return += in_a.data[i] * in_b.data[i];
          }
        return loc_return;
      }
  }

#endif /* __PARA_QUAT_HEAD__ */
