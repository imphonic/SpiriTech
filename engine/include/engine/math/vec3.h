#pragma once

#include "engine/common.h"

namespace rpf
  {
  /**
   * 3-dimensional vector.
   * Index 0: X-value (forward/backward)
   * Index 1: Y-value (right/left)
   * Index 2: Z-value (up/down)
   */
  using vec3_t = float[3];

  /**
   * Constants for 3D vectors.
   */
  class vec3 final
    {
    public:                              /* x,  y,  z */
      static constexpr vec3_t zero     = {  0,  0,  0 };
      static constexpr vec3_t identity = {  1,  1,  1 };
      static constexpr vec3_t inverse  = { -1, -1, -1 };
      static constexpr vec3_t forward  = {  1,  0,  0 };
      static constexpr vec3_t backward = { -1,  0,  0 };
      static constexpr vec3_t right    = {  0,  1,  0 };
      static constexpr vec3_t left     = {  0, -1,  0 };
      static constexpr vec3_t up       = {  0,  0,  1 };
      static constexpr vec3_t down     = {  0,  0, -1 };
      static constexpr vec3_t unit_x   = {  1,  0,  0 };
      static constexpr vec3_t unit_y   = {  0,  1,  0 };
      static constexpr vec3_t unit_z   = {  0,  0,  1 };
    };
  /* class vec3 */
  }
/* namespace rpf */
