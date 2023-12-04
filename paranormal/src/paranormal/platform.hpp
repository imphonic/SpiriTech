/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: platform.hpp
 * @brief: Implements a full kitchen sink of platform utilities.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_PLATFORM_HEAD__
#define __PARA_PLATFORM_HEAD__

namespace Para
  {
    /**
     * System which implements some generic platform-level
     * utilities. Must be implemented for each platform.
     */
    class Platform
      {
      public:
        /* Initializes the Platform system. */
        static int Init();
        /* Gets directory of the running executable. */
        static const char* GetBaseDir();
        /* Sets working directory as running executable directory. */
        static void SetWorkingDirAsBase();
        /* Whether the platform supports quitting directly. */
        static bool CanQuit();

        /* Platform time utilities. */
        class Time
          {
          public:
            /* Gets the clock frequency. */
            static double ClockFreq();
            /* Get the current time in seconds. */
            static double Milliseconds();
          };
      };
  }

#endif /* __PARA_PLATFORM_HEAD__ */