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
        /* Whether this is an x86-based platform. */
        static constexpr bool IsX86()
          {
            #if defined(_M_IX86) || defined(_M_X64)
              return true;
            #else
              return false;
            #endif
          }
        /* Whether this is an ARM-based platform. */
        static constexpr bool IsARM()
          {
            #if defined(_M_ARM) || defined(_M_ARM64) || defined(_M_ARM64EC)
              return true;
            #else
              return false;
            #endif
          }
        /* Whether the platform supports vectorization intrinsics. */
        static constexpr bool HasVectorInstrinsics()
          {
            // ReSharper disable once CppRedundantBooleanExpressionArgument
            // This causes stupid static analysis errors because only one
            // can be true at a time.
            return IsX86() || IsARM();
          }

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