/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: scoped_timer.cpp
 * @brief: Scoped timer for debug/log purposes.
 * @author: Will Pimentel-Tonche
**/

#include "paranormal/scoped_timer.hpp"

#include "paranormal/platform.hpp"

#include <cstdio>

Para::ScopedTimer::ScopedTimer(const char *in_task_desc):
  task(in_task_desc)
  {
    start_time = Platform::Time::Milliseconds();
  }

Para::ScopedTimer::~ScopedTimer()
  {
    /* printf is a little more readable than iostream here */
    printf
    (
      "Execution of task \"%s\" took %f ms",
      task,
      Platform::Time::Milliseconds() - start_time
    );
  }