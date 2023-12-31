#include "engine/common.h"

#include "engine/math/vec2/vec2_math.h"

#include "engine/math/common.h"

#include <cstring>

RPF_OPEN_SUB(math::vec2 )

    bool equivalent(const vec2::op_group *in_vecs)
        {
        bool loc_return = true;
        vec2::type loc_a = in_vecs->a_;
        vec2::type loc_b = in_vecs->b_;
        for (u16 i = 0; i < 2; ++i)
            {
            loc_return &= (loc_a.raw_[i] == loc_b.raw_[i]);
            }
        return loc_return;
        }

    void set(const vec2::set_info *in_components, vec2::type *out_vec)
        {
        static_assert(sizeof(set_info) == sizeof(vec2::type));
        std::memcpy(out_vec, in_components, sizeof(*in_components));
        }

    void add(vec2::op_group *in_vecs)
        {
        for (u16 i = 0; i < 2; ++i)
            {
            in_vecs->a_.raw_[i] += in_vecs->b_.raw_[i];
            }
        }

    void sub(vec2::op_group *in_vecs)
        {
        for (u16 i = 0; i < 2; ++i)
            {
            in_vecs->a_.raw_[i] -= in_vecs->b_.raw_[i];
            }
        }

    void mul(vec2::op_group *in_vecs)
        {
        for (u16 i = 0; i < 2; ++i)
            {
            in_vecs->a_.raw_[i] *= in_vecs->b_.raw_[i];
            }
        }

    void div(vec2::op_group *in_vecs)
        {
        for (u16 i = 0; i < 2; ++i)
            {
            in_vecs->a_.raw_[i] /= in_vecs->b_.raw_[i];
            }
        }

    void cross(const vec2::op_group *in_vecs, double *out_result)
        {
        *out_result = (in_vecs->a_.x_ * in_vecs->b_.y_ - in_vecs->a_.y_ * in_vecs->b_.x_);
        }

    void dot(const vec2::op_group *in_vecs, double *out_result)
        {
        *out_result = (in_vecs->a_.x_ * in_vecs->b_.x_ + in_vecs->a_.y_ * in_vecs->b_.y_);
        }

    void min(const vec2::type *in_vec, double *out_v)
        {
        // std::min_element (from <algorithm>) complexity not needed here
        *out_v = math::min(in_vec->x_, in_vec->y_);
        }

    void max(const vec2::type *in_vec, double *out_v)
        {
        // same here, standard library complexity is unnecessary
        *out_v = math::max(in_vec->x_, in_vec->y_);
        }

    void length(const vec2::type *in_vec, double *out_v)
        {
        *out_v = math::sqrt(math::square(in_vec->x_) + math::square(in_vec->y_));
        }

RPF_CLOSE
