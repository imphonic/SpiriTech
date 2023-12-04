/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: player.hpp
 * @brief: Implements the local player system.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_LOCAL_PLAYER_HEAD__
#define __PARA_LOCAL_PLAYER_HEAD__

namespace Para
  {
    /**
     * The Player system manages the local representation
     * of the game's player. Over networks this is represented as
     * a Net Connection.
     */
    class Player
      {
      public:
        static int Init();
      };
  }

#endif /* __PARA_LOCAL_PLAYER_HEAD__ */
