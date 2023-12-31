#pragma once

#include "engine/common.h"

RPF_OPEN_SUB(viewport::view_mode )

    // imma be honest, i have no clue what the fuck any
    // of these mean.
    enum type : int
        {
        wireframe = 0,
        bsp,
        unlit,
        lit,
        light_only,
        light_complex,
        shader_complex,
        lmap_dens,
        lit_lmap_dens,
        reflection,
        buffer_vis,
        overlap,
        collision,
        overdraw,
        };

RPF_CLOSE

namespace rpf
  {
    enum view_mode_t : int
      {
        wireframe = 0,
        bsp_wireframe,
        unlit,
        lit,
        detail,
        light_only,
        light_complex,
        shader_complex,
        lmap_dens,
        lit_lmap_dens,
        reflection,
        buffer_vis,
        overlap,
        pawn_col,
        vis_col,
        overdraw,
      };
  }
