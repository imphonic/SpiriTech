/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: viewport.hpp
 * @brief: Implements the viewport, an abstraction
 * over the rendering window.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_VIEWPORT_HEAD__
#define __PARA_VIEWPORT_HEAD__

namespace Para
  {
    enum ESplitscreenType : int
      {
        None,           /* no split (singleplayer and non-local multiplayer) */
        Vertical,       /* split vertically */
        Horizontal,     /* split horizontally */
        OneTop,         /* one on top and two on bottom, 3-player only */
        OneBottom,      /* two on top and one on bottom, 3-player only */
        Grid            /* four equally-sized corners, 4-player only */
      };

    /* Stores splitscreen info. Array of floats to enable vectorization. */
    using SplitscreenData = f32[4];
    enum
      {
        SD_SizeX   = 0,     /* width of the splitscreen area */
        SD_SizeY   = 1,     /* height of the splitscreen area */
        SD_OriginX = 2,     /* viewport origin of area along x-axis */
        SD_OriginY = 3      /* viewport origin of area along y-axis */
      };

    /* The Viewport is an abstraction over rendering functionality. */
    class Viewport
      {
      public:
        /* Initializes the viewport system. */
        static int Init();
        /* Creates the actual viewport widget. */
        static int Create();
      };
  }

#endif /* __PARA_VIEWPORT_HEAD__ */
