#pragma once

#include "engine/common.h"

#include "engine/math/vec4/vec4.h"

RPF_OPEN_SUB(math::vec4 )

    /// \section    Math Types
    /// \brief      Contains info for 4D vector operations involving two operands.
    ///
    /// \components a_           Left-hand operand vector.
    /// \components b_           Right-hand operand vector.
    ///
    /// \notes      Used to ensure the two vectors are kept together in the cache line.
    ///             Two vec4::t objects are 512 bits (64 bytes) in width, and fit into
    ///             precisely one cache line.
    typedef struct { vec4::t a_, b_; } pair_in; // 64b

    /// \section    Math Types
    /// \brief      Contains info for 4D vector operations involving two operands.
    ///
    /// \components c_           Result of the mutating operation.
    ///
    /// \notes      Used to ensure the two vectors are kept together in the cache line.
    ///             Two vec4::t objects are 256 bits (32 bytes) in width, and fit into
    ///             precisely one cache line.
    typedef struct { vec4::t c_;     } pair_out; // 32b

    /// \section    Algorithms
    /// \brief      Element-wise addition of two 4D vectors.
    ///
    /// \param in_vecs          Vectors to add.
    /// \param in_cnt           How many vectors are processed. Enter the size of
    ///                         the array, else 0 if only processing one.
    /// \param out_vecs         Resulting vectors.
    ///
    /// \notes      Performance characteristics:
    ///             64-byte input (full cache line, no waste).
    ///             32-byte output (half cache line, fits two outputs per line).
    ///             This function scales well with large numbers of arrays.
    void add(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise subtraction of two 4D vectors.
    ///
    /// \param in_vecs          Vectors to subtract.
    /// \param in_cnt           How many vectors are processed. Enter the size of
    ///                         the array, else 0 if only processing one.
    /// \param out_vecs         Resulting vectors.
    ///
    /// \notes      Performance characteristics:
    ///             64-byte input (full cache line, no waste).
    ///             32-byte output (half cache line, fits two outputs per line).
    ///             This function scales well with large numbers of arrays.
    void sub(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise multiplication of two 4D vectors.
    ///
    /// \param in_vecs          Vectors to multiply.
    /// \param in_cnt           How many vectors are processed. Enter the size of
    ///                         the array, else 0 if only processing one.
    /// \param out_vecs         Resulting vectors.
    ///
    /// \notes      Performance characteristics:
    ///             64-byte input (full cache line, no waste).
    ///             32-byte output (half cache line, fits two outputs per line).
    ///             This function scales well with large numbers of arrays.
    void mul(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise division of two 4D vectors.
    ///
    /// \param in_vecs          Vectors to divide.
    /// \param in_cnt           How many vectors are processed. Enter the size of
    ///                         the array, else 0 if only processing one.
    /// \param out_vecs         Resulting vectors.
    ///
    /// \notes      Performance characteristics:
    ///             64-byte input (full cache line, no waste).
    ///             32-byte output (half cache line, fits two outputs per line).
    ///             This function scales well with large numbers of arrays.
    void div(const vec4::pair_in *in_vecs, int in_cnt, vec4::pair_out *out_vecs);

    void print_vec4(const vec4::t *in_vec);

RPF_CLOSE
