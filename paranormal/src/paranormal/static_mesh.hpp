/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: static_mesh.hpp
 * @brief: Static group of mesh polygons.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_STATIC_MESH_HEAD__
#define __PARA_STATIC_MESH_HEAD__

namespace Para
  {
    /**
     * Static meshes are a static grouping of polygons. They can be
     * moved, rotated, and scaled as a whole, but not by individual
     * verticies, making them efficient to render. Levels that don't
     * use BSP brushes are often composed mostly of these.
     */
    struct StaticMesh
      {

      };
  }

#endif /* __PARA_STATIC_MESH_HEAD__ */
