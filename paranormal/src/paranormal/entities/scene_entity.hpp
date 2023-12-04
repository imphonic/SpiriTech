/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: scene_entity.hpp
 * @brief: Base struct for all rendered entities.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_SCENE_ENTITY_HEAD__
#define __PARA_SCENE_ENTITY_HEAD__

#include "../pointer.hpp"
#include "../vector.hpp"

namespace Para
  {
    /**
     * A Scene Entity is an entity with a location, rotation, and
     * scale (otherwise known as a transform), relative to either
     * the scene or another parent entity.
     */
    struct SceneEntity
      {
        /*/
         * Type Aliases
         *
         * These allow us to create systems taking one
         * or a group of each data type for greater
         * processing efficiency. For example we can
         * have a group which takes the parent and each
         * transform component only, and always have the
         * right data types.
        /*/

        /* Pointer type used for the parent entity */
        using parent_t   = WeakPtr<SceneEntity>;
        /* Type used for entity rotation */
        using rotation_t = quat4_t;
        /* Type used for entity location */
        using location_t = vec3_t;
        /* Type used for entity scale */
        using scale_t    = location_t;

        parent_t            parent;
        rotation_t          relative_rotation;
        location_t          relative_location;
        scale_t             relative_scale;
      };

    class SceneEntUtils
      {
      public:
        static float GetFwdVec(SceneEntity* in_ent)
          {
            return 0.f;
          }
        static float GetRightVec(SceneEntity* in_ent)
          {
            return 0.f;
          }
        static float GetUpVec(SceneEntity* in_ent)
          {
            return 0.f;
          }
      }
  }

#endif /* __PARA_SCENE_ENTITY_HEAD__ */
