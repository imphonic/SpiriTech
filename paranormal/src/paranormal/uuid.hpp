/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: uuid.hpp
 * @brief: Implements a universal unique identifier.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_UUID_HEAD__
#define __PARA_UUID_HEAD__
#include "types.hpp"

namespace Para
  {
    struct UUID
      {
        u8 bits[128];
      }

    class UuidTools
      {

      }
  }

#endif /* __PARA_UUID_HEAD__ */
