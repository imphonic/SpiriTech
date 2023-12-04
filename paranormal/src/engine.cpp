/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: engine.cpp
 * @brief: Implements the base engine system.
 * @author: Will Pimentel-Tonche
**/

#include "paranormal/engine.hpp"

#include "paranormal/player.hpp"
#include "paranormal/viewport.hpp"

int
Para::Engine::Init()
  {
    Viewport::Init();
    Player::Init();
    Viewport::Create();

    /* By default we load into the startup map */

    return 0;
  }

int
Para::Engine::LoadMap(map_id_t in_map_name)
  {
    // ...

    return 0;
  }
