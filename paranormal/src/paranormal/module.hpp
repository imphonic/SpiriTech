/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: exception.hpp
 * @brief: Implementation for an engine module.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_MODULE_HEAD__
#define __PARA_MODULE_HEAD__

namespace Para
  {
    /* A module represents a fragment of the larger Engine or Game. */
    struct Module
      {
        /* The initialization function for this module. */
        int(*InitFunc)();
        /* The shutdown function for this module. */
        int(*ShutdownFunc)();
      };
  }

#endif /* __PARA_MODULE_HEAD__ */