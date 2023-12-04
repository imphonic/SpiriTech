/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: game_loop.hpp
 * @brief: System which manages pre-init, init, loop,
 * and exit game loop functionality.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_ENGINE_LOOP_HEAD__
#define __PARA_ENGINE_LOOP_HEAD__

namespace Para
  {
    /*
     * The Game Loop system manages initializing and ticking
     * the engine and game.
     */
    class GameLoop
      {
      public:
        static int Init();
        static int Loop();
        static void Shutdown();
      };
  }

#endif /* __PARA_ENGINE_LOOP_HEAD__ */