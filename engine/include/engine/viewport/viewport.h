#pragma once

#include "engine/common.h"

#include "engine/viewport/view_mode.h"

constexpr auto SPLITSCREEN_MAX = 4;

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
            float size_x_, size_y_, origin_x_, origin_y_;
          };
        float data_[4];
      };

    struct viewport_t
      {
        splitscreen_info_t splitscreen_info_[SPLITSCREEN_MAX];
        view_mode_t view_mode_;
      };
  }
