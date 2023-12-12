#pragma once

#include "engine/common.h"

namespace rpf
  {
    union vec3_t
      {
        using this_t      = vec3_t;
        /* Type used to store individual values. */
        using val_t       = float;
        /* Type used to store values as an array. */
        using data_t      = val_t[3];

        /* Use this to access elements individually. */
        struct
          {
            /* x = Forward, y = Right, z = Up */
            val_t x_, y_, z_;
          };

        /* Allows for easy vectorization. Don't use directly. */
        data_t data_;

        struct /* constants */
          {
            static constexpr this_t zero     = {  0,  0,  0 };
            static constexpr this_t identity = {  1,  1,  1 };
            static constexpr this_t inverse  = { -1, -1, -1 };
            static constexpr this_t forward  = {  1,  0,  0 };
            static constexpr this_t backward = { -1,  0,  0 };
            static constexpr this_t right    = {  0,  1,  0 };
            static constexpr this_t left     = {  0, -1,  0 };
            static constexpr this_t up       = {  0,  0,  1 };
            static constexpr this_t down     = {  0,  0, -1 };
            static constexpr this_t unit_x   = forward;
            static constexpr this_t uint_y   = right;
            static constexpr this_t unit_z   = up;
          };
      };
  }
