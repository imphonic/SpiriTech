/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: platform_win.cpp
 * @brief: Windows platform utilities.
 * @author: Will Pimentel-Tonche
**/

#include "paranormal/platform.hpp"

#include "paranormal/exception.hpp"

#include <windows.h>

/* readability macro */
#define PARA_WINAPI

// Exceptions thrown by this translation unit
//-----------------------------------------------------------------------------

namespace Para::Exceptions
  {
    struct WorkingDirFail final : Exception
      {
        virtual const char* what() const override
          {
            return "Couldn't set working directory to base!";
          }
      };
  }

// Platform Interface
//-----------------------------------------------------------------------------

int
Para::Platform::Init()
  {
    return 0;
  }

void
Para::Platform::SetWorkingDirAsBase()
  {
    if (!PARA_WINAPI::SetCurrentDirectoryA(GetBaseDir()))
    {
      throw Exceptions::WorkingDirFail();
    }
  }

bool
Para::Platform::CanQuit()
  {
    return true;
  }

// Date/Time
//-----------------------------------------------------------------------------

double
Para::Platform::Time::ClockFreq()
  {
    static PARA_WINAPI::LARGE_INTEGER loc_freq;
    PARA_WINAPI::QueryPerformanceFrequency(&loc_freq);
    return 1 / (double)loc_freq.QuadPart;
  }

double
Para::Platform::Time::Milliseconds()
  {
    static PARA_WINAPI::LARGE_INTEGER loc_now;
    PARA_WINAPI::QueryPerformanceCounter(&loc_now);
    return (double)loc_now.QuadPart / ClockFreq();
  }