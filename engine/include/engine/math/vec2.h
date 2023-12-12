#pragma once

#include "engine/common.h"

namespace rpf
  {
    /**
     * 2-dimensional vector. X represents width, Y represents height.
     */
    union vec2_t
      {
        using this_t      = vec2_t;
        /* Type used to store individual values. */
        using val_t       = float;
        /* Type used to store values as an array. */
        using data_t      = val_t[2];

        /* Use this to access elements individually. */
        struct
          {
            /* x = Forward, y = Right */
            val_t x_, y_;
          };

        /* Allows for easy vectorization. Don't use directly. */
        data_t data_;

        struct /* constants */
          {
            static constexpr this_t zero     = {  0,  0 };
            static constexpr this_t identity = {  1,  1 };
            static constexpr this_t inverse  = { -1, -1 };
            static constexpr this_t right    = {  1,  0 };
            static constexpr this_t left     = { -1,  0 };
            static constexpr this_t up       = {  0,  1 };
            static constexpr this_t down     = {  0, -1 };
            static constexpr this_t unit_x   = right;
            static constexpr this_t uint_y   = up;
          };
      };
  }
