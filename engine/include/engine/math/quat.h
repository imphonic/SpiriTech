#pragma once

#include "engine/common.h"

namespace rpf
  {
    template <typename val_tp>
    union quat_t
      {
        using this_t      = quat_t;
        /* Type used to store individual values. */
        using val_t       = val_tp;
        /* Type used to store values as an array. */
        using data_t      = val_t[4];

        /* Use this to access elements individually. */
        struct
          {
            val_t x_, y_, z_, w_;
          };

        /* Allows for easy vectorization. */
        data_t data_;

        struct /* constants */
          {
            static constexpr this_t identity = {  1,  1,  1,  1 };
          };
      };
  }
