/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: scene.hpp
 * @brief: Implements the Scene system and data (World in Unreal Engine).
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_SCENE_HEAD__
#define __PARA_SCENE_HEAD__

namespace Para
  {
    /**
     * A Scene is the object in which entities are stored and rendered.
     *
     * Each Scene is made up of Chunks, which are like sub-levels, and are
     * loaded/unloaded automatically based on the game's Render Distance
     * setting and the configured chunk size (similar to how Minecraft works).
     *
     * All Scenes have at least one persistent chunk, which is/are always
     * loaded into memory. The first chunk is always at world origin.
     * Dynamically-loaded chunks are loaded in as they become visible or
     * as the player approaches them; you can configure loading distances
     * as well if desired.
     *
     * In a game, usually only one Scene exists at a time, unless seamless
     * travel is used. In the editor, though, many Scenes can exist:
     * - The level being edited
     * - Editor tools with an interactive rendered viewport (i.e. pretty
     *   much any 2D or 3D asset editor
     * - Many, many more...
     */
    class Scene
      {
      public:
      };
  }

#endif /* __PARA_SCENE_HEAD__ */
