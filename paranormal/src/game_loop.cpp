/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: engine.cpp
 * @brief: System which manages pre-init, init, loop,
 * and exit game loop functionality.
 * @author: Will Pimentel-Tonche
**/

#include "paranormal/game_loop.hpp"

int
Para::GameLoop::Init()
  {
    /**
     * Figure out which version of the engine should be used.
     * There are both editor and application flavors of the
     * engine, which behave significantly different from each
     * other.
     */

    return 0;
  }

int
Para::GameLoop::Loop()
  {
    return 0;
  }

void
Para::GameLoop::Shutdown()
  {
    
  }