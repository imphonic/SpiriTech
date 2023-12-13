#pragma once

#include "engine/common.h"

namespace rpf
  {
    /**
     * 2-dimensional vector. X represents width, Y represents height.
     */
    union vec2_t
      {
        /* Use this to access elements individually. */
        struct
          {
            /* x = Forward, y = Right */
            float x_, y_;
          };

        /* Allows for easy vectorization. Don't use directly. */
        float data_[2];

        struct /* constants */
          {
            static constexpr vec2_t zero     = {  0,  0 };
            static constexpr vec2_t unit     = {  1,  1 };
            static constexpr vec2_t inverse  = { -1, -1 };
            static constexpr vec2_t right    = {  1,  0 };
            static constexpr vec2_t left     = { -1,  0 };
            static constexpr vec2_t up       = {  0,  1 };
            static constexpr vec2_t down     = {  0, -1 };
            static constexpr vec2_t unit_x   = right;
            static constexpr vec2_t uint_y   = up;
          };
      };
  }
