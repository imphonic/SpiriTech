#pragma once

#include "engine/common.h"

#include "engine/math/simd/simd_types.h"

RPF_OPEN_SUB(math::simd )

    /// \section    SIMD Math
    /// \brief      Loads a vector register from aligned memory.
    ///
    /// \param in_src            The address of the aligned memory.
    /// \param out_vec           The vector in which to store the loaded memory.
    rpf_always_inline void load(const double *in_src, simd::v256 *out_vec);

    /// \section    SIMD Math
    /// \brief      Loads one value from a vector register into all four register
    ///             elements.
    ///
    /// \param in_src            The address of the value.
    /// \param out_vec           The vector in which to store the result.
    rpf_always_inline void load1(const double *in_src, simd::v256 *out_vec);

    /// \section    SIMD Math
    /// \brief      Loads values XY from a vector register into the ZW
    ///             elements.
    ///
    /// \param in_src            The address of the X and Y values.
    /// \param out_vec           The vector in which to store the result.
    rpf_always_inline void load2(const double *in_src, d256 *out_vec);

    /// \section    SIMD Math
    /// \brief      Sets all four elements of a vector register to one value.
    ///
    /// \param in_src            The value to assign.
    /// \param out_vec           The vector in which to store the result.
    rpf_always_inline void set1(double in_val, d256 *out_vec);

    /// \section    SIMD Math
    /// \brief      Stores a vector register to aligned memory.
    ///
    /// \param in_vec            The vector to store.
    /// \param in_dest           The address of the aligned memory.
    rpf_always_inline void store(const d256 *in_vec, double* in_dest);

    /// \section    SIMD Math
    /// \brief      Non-temporally store a vector register to aligned memory.
    ///
    /// \param in_vec            The vector to store.
    /// \param in_dest           The address of the aligned memory.
    rpf_always_inline void store_stream(const d256 *in_vec, double* in_dest);

    /// \section    SIMD Math
    /// \brief      Data used for bi-operand vector ops (add, subtract, etc.)
    ///
    /// \components a_           Left-hand vector.
    /// \components b_           Right-hand vector.
    /// \components result_      Resulting vector. Overwrites a_ so keep a backup if needed.
    ///
    /// \notes      You may be able to use result_ immediately, instead of
    ///             calling make_vecreg128, but I haven't tried it. To my understanding
    ///             the intrinsics it calls are required for initialization.
    struct alignas(16) d256_op_info
        {
        union alignas(16)
            {
            d256 a_;
            d256 result_;
            };
        d256 b_;
        };

    /// \section    SIMD Math
    /// \brief      Data used to create a 128-bit double-precision vector register.
    ///
    /// \components in_x_        X component of the vector.
    /// \components in_y_        Y component of the vector.
    /// \components result_      Resulting vector. Overwrites init info (x_, y_).
    ///
    /// \notes      You may be able to use result_ immediately, instead of
    ///             calling make_vecreg128, but I haven't tried it. To my understanding
    ///             the intrinsics it calls are required for initialization.
    union alignas(16) d128_make_info
        {
        d128 result_;
        struct { double in_x_, in_y_; };
        double raw_[2];
        };

    /// \section    SIMD Math
    /// \brief      Creates a 128-bit vector register.
    ///
    /// \param in_out_info       in_x and in_y are the X and Y values.
    ///                          Result is stored in result_.
    rpf_always_inline void make_vecreg128(d128_make_info *in_out_info);

    /// \section    SIMD Math
    /// \brief      Data used to create a 256-bit double-precision vector register.
    ///
    /// \components in_x_        X component of the vector.
    /// \components in_y_        Y component of the vector.
    /// \components in_z_        Z component of the vector.
    /// \components in_w_        W component of the vector.
    /// \components result_      Resulting vector. Overwrites init info (x_, y_, z_, w_).
    ///
    /// \notes      You may be able to use result_ immediately, instead of
    ///             calling make_vecreg256, but I haven't tried it. Using the make
    ///             functions guarantees that you'll avoid any issues that may crop up when
    ///             moving between SSE (x86) and NEON (ARM).
    union alignas(16) d256_make_info
        {
        d256 result_;
        struct { double in_x_, in_y_, in_z_, in_w_; };
        double raw_[4];
        };

    /// \section    SIMD Math
    /// \brief      Creates a 256-bit vector register.
    ///
    /// \param in_out_info       in_x, in_y, in_z, and in_w are the X/Y/Z/W values.
    ///                          Result is stored in result_.
    rpf_always_inline void make_vecreg256(d256_make_info *in_out_info);

RPF_CLOSE

#include "regmathsse.inl"
