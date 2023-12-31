#pragma once

#include "engine/common.h"

#include "engine/math/simd/simd_types.h"

#include <immintrin.h>
#include <cstring>

RPF_OPEN_SUB(math::simd )

    void load(const double *in_src, d256 *out_vec)
        {
        out_vec->xy_ = _mm_load_pd(in_src);
        out_vec->zw_ = _mm_load_pd(in_src + 2);
        }

    void load1(const double *in_src, d256 *out_vec)
        {
        out_vec->xy_ = _mm_load1_pd(in_src);
        out_vec->zw_ = out_vec->xy_;
        }

    void load2(const double *in_src, d256 *out_vec)
        {
        out_vec->xy_ = _mm_loadu_pd(in_src);
        out_vec->zw_ = out_vec->xy_;
        }

    void set1(double in_val, d256 *out_vec)
        {
        out_vec->xy_ = _mm_set1_pd(in_val);
        out_vec->zw_ = out_vec->xy_;
        }

    void store(const d256 *in_vec, double* in_dest)
        {
        _mm_store_pd(in_dest, in_vec->xy_);
        _mm_store_pd(in_dest + 2, in_vec->zw_);
        }

    void store_stream(const d256 *in_vec, double* in_dest)
        {
        _mm_stream_pd(in_dest, in_vec->xy_);
        _mm_stream_pd(in_dest + 2, in_vec->zw_);
        }

    void make_vecreg128(d128_make_info *in_out_info)
        {
        // This will copy the values of in_x_ and in_y_ on invocation, and
        // store the result directly in the same location.
        in_out_info->result_ = _mm_setr_pd(in_out_info->in_x_, in_out_info->in_y_);
        }

    void make_vecreg256(d256_make_info *in_out_info)
        {
        in_out_info->result_.xy_ = _mm_setr_pd(in_out_info->in_x_, in_out_info->in_y_);
        // At this point in_x and in_y were overwriten but we aren't reading from them
        // so we shouldn't care
        in_out_info->result_.zw_ = _mm_setr_pd(in_out_info->in_z_, in_out_info->in_w_);
        }

RPF_CLOSE
