/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: engine.hpp
 * @brief: Implements the base engine system.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_ENGINE_HEAD__
#define __PARA_ENGINE_HEAD__

#include "map_url.hpp"

namespace Para
  {
    /**
     * The Engine system handles some critical game and
     * editor functionality, such as switching maps.
     */
    class Engine
      {
      public:
        static int Init();
        static int LoadMap(map_id_t in_map_name);
      };
  }

#endif /* __PARA_ENGINE_HEAD__ */
