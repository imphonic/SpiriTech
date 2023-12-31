/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: light_entity.hpp
 * @brief: Light entities of different types.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_POINT_LIGHT_ENTITY_HEAD__
#define __PARA_POINT_LIGHT_ENTITY_HEAD__

#include "../types.hpp"

namespace Para
  {
    /**
     * A Point Light emits light from a fixed point
     * in all directions. ALl lights contribute to shadows.
     */
    struct PointLightEntity
      {
        f32 radius;
        f32 soft_radius;
        f32 length;
      };

    /**
     * A Point Light which uses a brightness scale,
     * versus the traditional inverse squared falloff.
     * Useful if you don't want a super bright spot
     * near the light.
     */
    struct PointLightSclEntity
      {

      };

    class PointLightUtils
      {
      public:
        static int
        ConvertToInverseSquared(
          PointLightEntity* in_point,
          PointLightSclEntity* in_linf_point);
      };
  }

#endif /* __PARA_POINT_LIGHT_ENTITY_HEAD__ */
