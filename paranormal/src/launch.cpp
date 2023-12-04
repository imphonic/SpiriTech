/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: launch.cpp
 * @brief: Implements the guarded main function.
 * @author: Will Pimentel-Tonche
**/

#include "paranormal\game_loop.hpp"

namespace Para
  {
    void
    Exit()
      {

      }

    void
    PreInit(const char* in_cmd_ln)
      {

      }

    /**
     * Guarded main function. It's "guarded" because the caller
     * wraps it in a try-catch block to ensure safety, and it
     * ensures that the engine exits safely upon returning.
     */
    int
    GuardedMain(const char* in_cmd_ln)
      {
        /**
         * This ensures that under all circumstances, the engine
         * shuts down safely.
         */
        struct ExitGuard
          {
            ~ExitGuard() { GameLoop::Shutdown(); }
          } loc_exit_guard;

        int loc_err_lvl = GameLoop::Init();
        if (loc_err_lvl != 0)
          {
            return loc_err_lvl;
          }

        loc_err_lvl = GameLoop::Loop();
        return loc_err_lvl;
      }
  }