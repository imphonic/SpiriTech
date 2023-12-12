#pragma once

#include "engine/common.h"

RF_ENGINE_DECL_CONSTANT_SUBSPACE( dsp, auto, BUFFER_DEPTH, 512 )

namespace rpf::dsp
  {
    using buffer = float[consts::dsp::BUFFER_DEPTH];
  }