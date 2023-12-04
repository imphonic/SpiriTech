/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: launch_win.cpp
 * @brief: Implements startup for Windows.
 * @author: Will Pimentel-Tonche
**/

#include "paranormal/exception.hpp"

#include <exception>
#include <iostream>

#include <windows.h>

/* readability macro */
#define PARA_WINAPI

namespace Para
  {
    extern int
    GuardedMain(char*);
    extern void
    ReportError(const char*);

    int
    WinInit(HINSTANCE in_instance, LPSTR in_cmd_ln, int in_show)
      {
        int loc_err_lvl = 0;

        /**
         * Nobody likes when someone does this, but Unreal does it,
         * so I will too.
         * 
         * Look, it's easier to make a crash reporter doing this.
         */
        try
        {
          loc_err_lvl = GuardedMain(PARA_WINAPI::GetCommandLineA());
        }
        catch(const Exception& loc_exception)
        {
          // Engine has crashed, show reporter and exit.
          loc_err_lvl = -1;
          std::cerr << loc_exception.what() << '\n';
          ReportError(loc_exception.what());
        }

        return loc_err_lvl;
      }

    void
    WinShutdown()
      {
        // ...
      }
  }

int
WINAPI
WinMain
  (
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance, /* unused */
    LPSTR lpCmdLine,
    int nCmdShow
  )
  {
    int loc_err_lvl = Para::WinInit(hInstance, lpCmdLine, nCmdShow);
    Para::WinShutdown();
    return loc_err_lvl;
  }