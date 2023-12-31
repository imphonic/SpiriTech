#include "engine/common.h"

#include "engine/math/common.h"

#include <cmath>

RPF_OPEN_ANON

    template <typename tp_a, typename tp_b = tp_a>
    auto tp_min(tp_a in_a, tp_b in_b)
        {
        return in_a < in_b ? in_a : in_b;
        }

    template <typename tp_a, typename tp_b = tp_a>
    auto tp_max(tp_a in_a, tp_b in_b)
        {
        return in_a > in_b ? in_a : in_b;
        }

RPF_CLOSE

RPF_OPEN_SUB(math )

    float minf(float in_a, float in_b)
        {
        return tp_min(in_a, in_b);
        }

    float maxf(float in_a, float in_b)
        {
        return tp_max(in_a, in_b);
        }

    float squaref(float in_v)
        {
        return in_v * in_v;
        }

    float sqrtf(float in_v)
        {
        return std::sqrt(in_v);
        }

    float rsqrtf(float in_v)
        {
        // This should optimize to rsqrtss
        return 1 / std::sqrt(in_v);
        }

    double min(double in_a, double in_b)
        {
        return tp_min(in_a, in_b);
        }

    double max(double in_a, double in_b)
        {
        return tp_max(in_a, in_b);
        }

    double square(double in_v)
        {
        return in_v * in_v;
        }

    double sqrt(double in_v)
        {
        return std::sqrt(in_v);
        }

    double rsqrt(double in_v)
        {
        // This should optimize to rsqrtss
        return 1 / std::sqrt(in_v);
        }

    double random_flt()
        {
        // Thanks Kaze Emanuar for this trick
        float loc_result;
        *(u32 *) &loc_result = 0x3F800000 | (random_ushrt() << 7);
        return loc_result - 1;
        }

    ushort random_ushrt()
        {
        return 0;
        }

    RPF_CLOSE
