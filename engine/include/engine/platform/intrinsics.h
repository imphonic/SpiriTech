#pragma once

#include "engine/platform/platform_support.h"

#if RPF_MSVC
  #include "engine/platform/detail/msvc_intrinsics.h"
#endif



namespace rpf
  {
    using intrinsics = internal::msvc_intrinsics;

    void test()
      {
        constexpr int thing = 0;
        intrinsics::prefetch(&thing);
      }
  }
