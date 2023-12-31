#include "engine/common.h"

#include "engine/math/vec3/vec3_math.h"

#include "engine/math/common.h"

#include <cstring>

RPF_OPEN_SUB(math::vec3 )

    bool equivalent(const vec3::op_group *in_vecs)
        {
        bool loc_return = true;
        vec3::type loc_a = in_vecs->a_;
        vec3::type loc_b = in_vecs->b_;
        for (u16 i = 0; i < 3; ++i)
            {
            loc_return ^= (loc_a.raw_[i] == loc_b.raw_[i]);
            }
        return loc_return;
        }

    void set(const vec3::set_info *in_components, vec3::type *out_vec)
        {
        static_assert(sizeof(set_info) == sizeof(vec3::type));
        std::memcpy(out_vec, in_components, sizeof(*in_components));
        }

    void add(vec3::op_group *in_vecs)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            in_vecs->a_.raw_[i] += in_vecs->b_.raw_[i];
            }
        }

    void sub(vec3::op_group *in_vecs)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            in_vecs->a_.raw_[i] -= in_vecs->b_.raw_[i];
            }
        }

    void mul(vec3::op_group *in_vecs)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            in_vecs->a_.raw_[i] *= in_vecs->b_.raw_[i];
            }
        }

    void div(vec3::op_group *in_vecs)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            in_vecs->a_.raw_[i] /= in_vecs->b_.raw_[i];
            }
        }

    void set_uniform(op_unif_info *out_vec)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            out_vec->raw_[i] = out_vec->val_;
            }
        }

    void add_uniform(const op_unif_info *in_info, vec3::type *out_result)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_info->raw_[i] + in_info->val_;
            }
        }

    void sub_uniform(const op_unif_info *in_info, vec3::type *out_result)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_info->raw_[i] - in_info->val_;
            }
        }

    void mul_uniform(const op_unif_info *in_info, vec3::type *out_result)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_info->raw_[i] * in_info->val_;
            }
        }

    void div_uniform(const op_unif_info *in_info, vec3::type *out_result)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            out_result->raw_[i] = in_info->raw_[i] / in_info->val_;
            }
        }

    void cross(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result)
        {
        out_result->x_ = (in_a->y_ * in_b->z_ - in_a->z_ * in_b->y_);
        out_result->y_ = (in_a->z_ * in_b->x_ - in_a->x_ * in_b->z_);
        out_result->z_ = (in_a->x_ * in_b->y_ - in_a->y_ * in_b->x_);
        }

    void dot(const vec3::type *in_a, const vec3::type *in_b, double *out_result)
        {
        for (u16 i = 0; i < 3; ++i)
            {
            *out_result += (in_a->raw_[i] * in_b->raw_[i]);
            }
        }

    void min(const vec3::type *in_vec, float *out_v)
        {
        // std::min_element (from <algorithm>) complexity not needed here
        *out_v = minf(minf(in_vec->x_, in_vec->y_), in_vec->z_);
        }

    void max(const vec3::type *in_vec, float *out_v)
        {
        // same here, standard library complexity is unnecessary
        *out_v = maxf(maxf(in_vec->x_, in_vec->y_), in_vec->z_);
        }

    void length(const vec3::type *in_vec, float *out_v)
        {
        float loc_out = 0.f;
        for (u16 i = 0; i < 3; ++i)
            {
            loc_out += math::squaref(in_vec->raw_[i]);
            }
        *out_v = math::sqrtf(loc_out);
        }

    void length2d(const vec3::type *in_vec, float *out_v)
        {
        *out_v = math::sqrtf(math::squaref(in_vec->x_) + math::squaref(in_vec->y_));
        }

RPF_CLOSE
