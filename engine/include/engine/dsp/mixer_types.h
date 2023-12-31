#pragma once

#include "engine/common.h"

namespace rpf::dsp
    {
    enum output_state_t : int
        {
        closed,
        open,
        stopped,
        running
        };

    union settings_t
        {
        struct
            {
            unsigned short
                sample_rate_      = 48000,
                buf_size_         = 1024,
                buf_count_        = 2,
                channel_max_      = 0,
                worker_count_     = 0;
            };
        unsigned short raw_[5];
        };
    }
