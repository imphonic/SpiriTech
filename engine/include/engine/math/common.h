#pragma once

#include "engine/common.h"

rpf_engine_begin_subspace( math )

    template <typename tp_a, typename tp_b = tp_a>
    auto min(tp_a in_a, tp_b in_b)
        {
        return in_a < in_b ? in_a : in_b;
        }

    template <typename tp_a, typename tp_b = tp_a>
    auto max(tp_a in_a, tp_b in_b)
        {
        return in_a > in_b ? in_a : in_b;
        }

rpf_engine_end
