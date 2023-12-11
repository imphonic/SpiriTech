#pragma once

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
