#include "engine/common.h"

#include "engine/math/vec4/vec4.h"
#include "engine/math/vec4/vec4_math.h"

#include "engine/math/common.h"

#include <string>

#if RPF_MSVC
#   include <intrin.h>
#else
#   include <immintrin.h>
#endif

RPF_OPEN_SUB(math::vec4 )

    void add(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs)
        {
        #if rpf_use_avx
            for (int i = 0; i < in_cnt; ++i)
                {
                out_vecs[i].c_.raw_ =
                    _mm256_add_pd(in_vecs[i].a_.raw_, in_vecs[i].b_.raw_);
                }
        #else // non-AVX (ARM-based, e.g. Apple Silicon)
        for (int i = 0; i < in_cnt; ++i)
                {
                out_vecs[i].c_.xy_ =
                    _mm_add_pd(in_vecs[i].a_.xy_, in_vecs[i].b_.xy_);
                out_vecs[i].c_.zw_ =
                    _mm_add_pd(in_vecs[i].a_.zw_, in_vecs[i].b_.zw_);
                }
        #endif
        }

    void sub(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs)
        {
        #if rpf_use_avx
        for (int i = 0; i < in_cnt; ++i)
            {
            out_vecs[i].c_.raw_ =
                _mm256_sub_pd(in_vecs[i].a_.raw_, in_vecs[i].b_.raw_);
            }
        #else // non-AVX (ARM-based, e.g. Apple Silicon)
        for (int i = 0; i < in_cnt; ++i)
                {
                out_vecs[i].c_.xy_ =
                    _mm_sub_pd(in_vecs[i].a_.xy_, in_vecs[i].b_.xy_);
                out_vecs[i].c_.zw_ =
                    _mm_sub_pd(in_vecs[i].a_.zw_, in_vecs[i].b_.zw_);
                }
        #endif
        }

    void mul(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs)
        {
        #if rpf_use_avx
        for (int i = 0; i < in_cnt; ++i)
            {
            out_vecs[i].c_.raw_ =
                _mm256_mul_pd(in_vecs[i].a_.raw_, in_vecs[i].b_.raw_);
            }
        #else // non-AVX (ARM-based, e.g. Apple Silicon)
        for (int i = 0; i < in_cnt; ++i)
                {
                out_vecs[i].c_.xy_ =
                    _mm_mul_pd(in_vecs[i].a_.xy_, in_vecs[i].b_.xy_);
                out_vecs[i].c_.zw_ =
                    _mm_mul_pd(in_vecs[i].a_.zw_, in_vecs[i].b_.zw_);
                }
        #endif
        }

    void div(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs)
        {
        #if rpf_use_avx
        for (int i = 0; i < in_cnt; ++i)
            {
            out_vecs[i].c_.raw_ =
                _mm256_div_pd(in_vecs[i].a_.raw_, in_vecs[i].b_.raw_);
            }
        #else // non-AVX (ARM-based, e.g. Apple Silicon)
        for (int i = 0; i < in_cnt; ++i)
                {
                out_vecs[i].c_.xy_ =
                    _mm_div_pd(in_vecs[i].a_.xy_, in_vecs[i].b_.xy_);
                out_vecs[i].c_.zw_ =
                    _mm_div_pd(in_vecs[i].a_.zw_, in_vecs[i].b_.zw_);
                }
        #endif
        }

    void print_vec4(const vec4::t *in_vec)
        {
            printf("Vec4: X=%f Y=%f Z=%f W=%f \n", in_vec->x_, in_vec->y_, in_vec->z_, in_vec->w_);
        }

    RPF_CLOSE
