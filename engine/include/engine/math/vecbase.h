#pragma once

#include "engine/common.h"

namespace rpf::internal
  {
    /**
     * A 2D, 3D, or "4D" vector with a fixed number of elements.
     *
     * This is a heavily templated base struct. Do NOT, under
     * ANY circumstances, use this directly. Use vec2_t, vec3_t,
     * or quat_t, based on which one fits your use case.
     */
    template <typename t_data, unsigned... t_num_elems>
    struct vecbase_t
      {

      };
  }
