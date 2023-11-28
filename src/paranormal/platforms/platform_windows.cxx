/******************************************************
 * Copyright Rapidfire Computer Entertainment.        *
 * Licensed under GNU LGPL - see LICENSE for details. *
 * FILE: platform_windows.cxx                         *
 * BRIEF: Implements the Platform layer for Windows.  *
 * AUTHOR: Will Pimentel-Tonche                       *
*******************************************************/

#include "../platform.hxx"

#include <windows.h>

/* Readability macro for the Windows API. */
#define PARA_WINAPI

namespace Para
  {
    namespace
      {
        /* Struct containing global platform state. */
        struct PlatformState
          {
            PARA_WINAPI::WNDCLASSEX wnd_class {};
            PARA_WINAPI::LARGE_INTEGER start_time {};
            PARA_WINAPI::HINSTANCE inst_handle {};
            PARA_WINAPI::HWND wnd_handle {};
            double clock_freq {};
          } g_state;

        /* Window Class name for the engine's default window class. */
        constexpr PARA_WINAPI::LPCSTR g_wnd_cls_name = "ParanormalWndClass";

        /* Default window transform on Windows. */
        constexpr int g_default_transform[4]
          {
            100,    /* x-loc */
            100,    /* y-loc */
            1280,   /* width */
            720     /* height */
          };

        /* Callback to process messages on Windows. */
        PARA_WINAPI::LRESULT CALLBACK
        ProcessMessages
          (
            PARA_WINAPI::HWND inWnd,
            PARA_WINAPI::UINT inMsg,
            PARA_WINAPI::WPARAM inWParam,
            PARA_WINAPI::LPARAM inLParam
          );
      }
    /* anonymous namespace */

    bool Platform::Init(int in_screen_transform[4], const char* in_name)
      {
        return true;
      }
  }
/* namespace Para */