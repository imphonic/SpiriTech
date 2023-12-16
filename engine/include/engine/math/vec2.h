#pragma once

#include "engine/common.h"

namespace rpf
  {
  /**
   * 2-dimensional vector.
   * Index 0: X-value (width)
   * Index 1: Y-value (height)
   */
  using vec2_t = float[2];

  /**
   * Constants for 2D vectors.
   */
  class vec2 final
    {
    public:                              /* x,  y */
      static constexpr vec2_t zero     = {  0,  0 };
      static constexpr vec2_t unit     = {  1,  1 };
      static constexpr vec2_t inverse  = { -1, -1 };
      static constexpr vec2_t right    = {  1,  0 };
      static constexpr vec2_t left     = { -1,  0 };
      static constexpr vec2_t up       = {  0,  1 };
      static constexpr vec2_t down     = {  0, -1 };
      static constexpr vec2_t unit_x   = {  1,  0 };
      static constexpr vec2_t unit_y   = {  0,  1 };
    };
  /* class vec2 */
  }
/* namespace rpf */
