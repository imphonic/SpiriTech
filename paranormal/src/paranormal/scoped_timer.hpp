/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: scoped_timer.cpp
 * @brief: Scoped timer for debug/log purposes.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_MODULE_HEAD__
#define __PARA_MODULE_HEAD__

namespace Para
  {
    /**
     * A scoped timer. Prints the duration taken to perform
     * a task upon going out of scope. For debug only; does
     * nothing in release builds.
     */
    struct ScopedTimer
      {
        explicit ScopedTimer(const char* in_task_desc);
        ~ScopedTimer();
      private:
        const char* task;
        double start_time;
      };
  }

#if defined(PARADBG) || defined(PARADEV)
  #define SCOPED_TIMER(in_description) Para::ScopedTimer(in_description)
#else
  #define SCOEPD_TIMER(in_description)
#endif

#endif /* __PARA_MODULE_HEAD__ */