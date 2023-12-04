/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: chunk.hpp
 * @brief: Chunks are persistent or streamed sub-levels of a scene.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_CHUNK_HEAD__
#define __PARA_CHUNK_HEAD__

#include "entity_container.hpp"

namespace Para
  {
    struct Chunk
      {
        /**
         * All entities contained within this chunk.
         * Individual types can be accessed and processed in bulk
         * by their type.
         */
        EntityContainer entities;
      };
  }

#endif /* __PARA_CHUNK_HEAD__ */
