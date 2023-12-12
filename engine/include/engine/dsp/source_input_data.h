#pragma once

#include "engine/common.h"

#include "engine/dsp/buffer.h"

namespace rpf::dsp
  {
    struct source_input_data
      {
        unsigned int source_id_;
        unsigned int audio_id_;
        unsigned int channel_count_;
      };
  }
