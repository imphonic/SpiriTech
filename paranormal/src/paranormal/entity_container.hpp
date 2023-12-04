/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: entity_container.hpp
 * @brief: Container for all entity types in the Engine.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_ENTITY_CONTAINER_HEAD__
#define __PARA_ENTITY_CONTAINER_HEAD__

namespace Para
  {
    /**
     * An Entity Container contains arrays of each entity type.
     * Every Chunk and Archetype contains one of these.
     */
    struct EntityContainer
      {

      };

    class EntityContainerManager
      {
      public:
        /**
         * Copies the contents of one entity container to another.
         * Used frequently to copy an Archetype into a Scene Chunk.
         * \param in_dst Destination container to copy to
         * \param in_src Source container to copy from
         * \return 0 if succeeded, nonzero if failed
         */
        static int CopyTo(EntityContainer* in_dst, EntityContainer* in_src);
      };
  }

#endif /* __PARA_ENTITY_CONTAINER_HEAD__ */
