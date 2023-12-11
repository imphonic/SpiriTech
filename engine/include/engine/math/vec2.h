#pragma once

namespace rpf
  {
    /**
     * 2-dimensional vector. X represents width, Y represents height.
     */
    union vec2_t
      {
        struct
          {
            double x, y;
          };
        double data[2];
      };
  }