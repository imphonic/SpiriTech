#pragma once

#include "engine/view/view_mode..h"

namespace rpf
  {
    enum splitscreen_type_t : int
      {
        none,           /* no split (singleplayer and non-local multiplayer) */
        vertical,       /* split vertically */
        horizontal,     /* split horizontally */
        one_top,        /* one on top and two on bottom, 3-player only */
        one_bottom,     /* two on top and one on bottom, 3-player only */
        grid            /* four equally-sized corners, 4-player only */
      };

    union splitscreen_info_t
      {
        struct
          {
            float size_x, size_y, origin_x, origin_y;
          };
        float data[4];
      };

    static constexpr auto MAX_SPLITSCREEN_PLAYERS = 4;

    struct viewport_t
      {
        splitscreen_info_t splitscreen_info[MAX_SPLITSCREEN_PLAYERS];
        view_mode_t view_mode;
      };
  }
