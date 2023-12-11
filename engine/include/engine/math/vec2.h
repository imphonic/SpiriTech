#pragma once

#include "engine/common.h"

namespace rpf
  {
    /**
     * 2-dimensional vector. X represents width, Y represents height.
     */
    union vec2_t
      {
        struct
          {
            double x_, y_;
          };
        double data_[2];
      };
  }
