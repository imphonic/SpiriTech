#pragma once

#include "engine/platform/compiler.h"

#if RF_ENGINE_USING_MSVC
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
