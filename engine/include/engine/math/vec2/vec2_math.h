#pragma once

#include "engine/common.h"

#include "engine/math/vec2/vec2.h"
#include "engine/math/vec2/vec2_constants.h"

RPF_OPEN_SUB(math::vec2 )

    /// \section    Types
    /// \brief      Contains info for 2D vector operations involving two operands.
    ///
    /// \components a_           Left-hand operand vector. Result is stored here in
    ///                          case of mutating operations (e.g. add, subtract)
    /// \components b_           Right-hand operand vector.
    ///
    /// \notes      Used to ensure the two vectors are placed in a floating-point register.
    ///             Two vec2::type objects fit in a 256-bit (32-byte) register. Two vec2
    ///             operations are possible per 64-byte cache line.
    union op_group { struct { vec2::type a_, b_; }; double raw_[4]; vec2::type vec_raw_[2]; };

    /// \section    Algorithms
    /// \brief      Returns whether two vectors are the same.
    ///
    /// \param in_vecs          Vectors to compare.
    ///
    /// \returns    Whether the two vectors are the same.
    bool equivalent(const vec2::op_group *in_vecs);

    /// \section    Types
    /// \brief      Struct containing info to initialize or set a vector.
    struct set_info { double x_, y_; };

    /// \section    Algorithms
    /// \brief      Sets a vector to the given component (XY) values.
    ///
    /// \param in_components    XY components of the vector.
    /// \param out_vec          Vector which will have its components assigned.
    void set(const vec2::set_info *in_components, vec2::type *out_vec);

    /// \section    Algorithms
    /// \brief      Element-wise addition of two 2D vectors.
    ///
    /// \param in_vecs          Vectors to add.
    ///                         Result stored in a_.
    void add(vec2::op_group *in_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise subtraction of two 2D vectors.
    ///
    /// \param in_vecs          Vectors to subtract.
    ///                         Result stored in a_.
    void sub(vec2::op_group *in_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise multiplication of two 2D vectors.
    ///
    /// \param in_vecs          Vectors to multiply.
    ///                         Result stored in a_.
    void mul(vec2::op_group *in_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise division of two 2D vectors.
    ///
    /// \param in_vecs          Vectors to divide.
    ///                         Result stored in a_.
    void div(vec2::op_group *in_vecs);

    /// \section    Algorithms
    /// \brief      Calculates the cross product of two 2D vectors.
    ///
    /// \param in_vecs          Vectors to calculate the cross product of.
    /// \param out_result       Number in which the result will be stored.
    void cross(const vec2::op_group *in_vecs, double *out_result);

    /// \section    Algorithms
    /// \brief      Calculates the dot product of two 2D vectors.
    ///
    /// \param in_vecs          Vectors to calculate the dot product of.
    /// \param out_result       Number in which the result will be stored.
    void dot(const vec2::op_group *in_vecs, double *out_result);

    /// \section    Algorithms
    /// \brief      Gets the smallest of the vector's components.
    ///
    /// \param in_a             Vector to obtain the value from.
    /// \param out_v            Number in which the value will be stored.
    void min(const vec2::type *in_vec, double *out_v);

    /// \section    Algorithms
    /// \brief      Gets the largest of the vector's components.
    ///
    /// \param in_a             Vector to obtain the value from.
    /// \param out_v            Number in which the value will be stored.
    void max(const vec2::type *in_vec, double *out_v);

    /// \section    Algorithms
    /// \brief      Calculates the total length of the vector's components.
    ///
    /// \param in_a             Vector to calculate the value from.
    /// \param out_v            Number in which the value will be stored.
    void length(const vec2::type *in_vec, double *out_v);

RPF_CLOSE
