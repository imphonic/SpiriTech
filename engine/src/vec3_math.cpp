#include "engine/common.h"

#include "engine/math/vec3_math.h"

#include <cstring>

rpf_engine_begin_subspace( math::vec3 )

    void set(const init_info *in_components, vec3::type *out_vec)
        {
        static_assert(sizeof(init_info) == sizeof(vec3::type));
        std::memcpy(out_vec, in_components, sizeof(*in_components));
        }

    void add(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result)
        {
        for (ushort i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_a->raw_[i] + in_b->raw_[i];
            }
        }

    void sub(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result)
        {
        for (ushort i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_a->raw_[i] - in_b->raw_[i];
            }
        }

    void mul(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result)
        {
        for (ushort i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_a->raw_[i] * in_b->raw_[i];
            }
        }

    void div(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result)
        {
        for (ushort i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_a->raw_[i] / in_b->raw_[i];
            }
        }

    void cross(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result)
        {
        out_result->x_ = in_a->y_ * in_b->z_ - in_a->z_ * in_b->y_;
        out_result->y_ = in_a->z_ * in_b->x_ - in_a->x_ * in_b->z_;
        out_result->z_ = in_a->x_ * in_b->y_ - in_a->y_ * in_b->x_;
        }

    void dot(const vec3::type *in_a, const vec3::type *in_b, double *out_result)
        {
        for (ushort i = 0; i < 3; ++i)
            {
            *out_result += in_a->raw_[i] * in_b->raw_[i];
            }
        }

    bool equivalent(const vec3::type *in_a, const vec3::type *in_b)
        {
        bool loc_return = true;
        for (ushort i = 0; i < 3; ++i)
            {
            loc_return ^= in_a->raw_[i] == in_b->raw_[i];
            }
        return loc_return;
        }

rpf_engine_end
