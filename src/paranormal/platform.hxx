/******************************************************
 * Copyright Rapidfire Computer Entertainment.        *
 * Licensed under GNU LGPL - see LICENSE for details. *
 * FILE: platform_windows.hxx                         *
 * BRIEF: Interface to the Platform layer.            *
 * AUTHOR: Will Pimentel-Tonche                       *
*******************************************************/

#ifndef __PARA_PLATFORM_HEAD__
#define __PARA_PLATFORM_HEAD__

namespace Para
  {
    /* System which manages the Platform layer. */
    class Platform final
      {
      public:
        static bool Init(int in_screen_transform[4], const char* in_name);
      };
  }

#endif /* __PARA_PLATFORM_HEAD__ */
