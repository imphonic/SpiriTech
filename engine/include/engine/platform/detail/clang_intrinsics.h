#pragma once

#include "engine/common.h"

#include "engine/platform/intern_compiler_intrinsics.h"
#include "engine/platform/detail/gcc_intrinsics.h"

namespace rpf::internal
  {
    using clang_intrinsics = gcc_intrinsics;
  }
