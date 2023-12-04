/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: archetype.hpp
 * @brief: Archetype data and system.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_ARCHETYPE_HEAD__
#define __PARA_ARCHETYPE_HEAD__

#include "entity_container.hpp"

namespace Para
  {
    /**
     * An Archetype is a reusable collection of entities.
     * Archetypes can be dragged into a scene, and the entities are
     * pasted into the scene automatically as configured, also
     * retaining information about their associated archetype.
     *
     * Unlike other engine components, Archetypes are much more
     * object-oriented at the asset level:
     * - When the base type is updated, all scene instances are
     *   updated as well
     * - Single inheritance is supported, and updates are propagated
     *   to scene instances, child archetypes, and their instances
     */
    struct Archetype
      {
        EntityContainer entities;
      };
  }

#endif /* __PARA_ARCHETYPE_HEAD__ */
