#pragma once

#include "engine/common.h"

#include "engine/math/quat.h"

namespace rpf
  {
  /**
   * Functions, constants, and other features for 3D quaternions.
   * This is a static class. Do not instantiate.
   */
  class quat final
    {
      rpf_engine_class_generated()
    public:                            //* 0x, 1y, 2z, 3w *//
      static constexpr quat_t identity = {  1,  1,  1,  1 };
      static void add(const quat_t in_a, const quat_t in_b, quat_t out_result)
        {
          /* should be vectorized with SSE/NEON */
          for (int i = 0; i < 4; ++i)
            {
              out_result[i] = in_a[i] + in_b[i];
            }
        }
    };
  /* class quat */
  }
/* namespace rpf */