#pragma once

#include "engine/common.h"

#include "engine/math/vec3/vec3.h"
#include "engine/math/vec3/vec3_constants.h"

RPF_OPEN_SUB(math::vec3 )

    /// \section    Types
    /// \brief      Contains info for 3D vector operations involving two operands.
    ///
    /// \components a_           Left-hand operand vector. Result is stored here in
    ///                          case of mutating operations (e.g. add, subtract)
    /// \components b_           Right-hand operand vector.
    ///
    /// \notes      Used to ensure the two vectors are kept together in the cache line.
    ///             Two vec3::type objects are 384 bits (48 bytes) in width.
    union op_group { struct { vec3::type a_, b_; }; double raw_[4]; vec3::type vec_raw_[2]; };

    /// \section    Algorithms
    /// \brief      Returns whether two vectors are the same.
    ///
    /// \param in_vecs          Vectors to compare.
    ///
    /// \returns    Whether the two vectors are the same.
    bool equivalent(const vec3::op_group *in_vecs);

    /// \section    Types
    /// \brief      Struct containing info to initialize or set a vector.
    struct set_info { double x_, y_, z_; };

    /// \section    Algorithms
    /// \brief      Sets a vector to the given component (XYZ) values.
    ///
    /// \param in_components    XYZ components of the vector.
    /// \param out_vec          Vector which will have its components assigned.
    void set(const vec3::set_info *in_components, vec3::type *out_vec);

    /// \section    Algorithms
    /// \brief      Element-wise addition of two 3D vectors.
    ///
    /// \param in_vecs          Vectors to add.
    ///                         Result stored in a_.
    void add(vec3::op_group *in_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise subtraction of two 3D vectors.
    ///
    /// \param in_vecs          Vectors to subtract.
    ///                         Result stored in a_.
    void sub(vec3::op_group *in_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise multiplication of two 3D vectors.
    ///
    /// \param in_vecs          Vectors to multiply.
    ///                         Result stored in a_.
    void mul(vec3::op_group *in_vecs);

    /// \section    Algorithms
    /// \brief      Element-wise division of two 3D vectors.
    ///
    /// \param in_vecs          Vectors to divide.
    ///                         Result stored in a_.
    void div(vec3::op_group *in_vecs);

    /// \section    Types
    /// \brief      Struct containing info to initialize or set a vector by one value.
    ///
    /// \notes      Forces the vector and value to be loaded into the same floating-point
    ///             register.
    struct op_unif_info { union { vec3::type vec_; double val_; }; double raw_[4]; };

    /// \section    Algorithms
    /// \brief      Sets all components of a vector to a given value.
    ///
    /// \param out_vec          vec_ is the output, and val_ is the value to assign.
    void set_uniform(op_unif_info *out_vec);

    /// \section    Algorithms
    /// \brief      Add a value to all axes of a vector.
    ///
    /// \param in_info          Vector to operate on, and value to use.
    /// \param out_result       Vector in which the result will be stored.
    void add_uniform(const op_unif_info *in_info, vec3::type *out_result);

    /// \section    Algorithms
    /// \brief      Subtract a value from all axes of a vector.
    ///
    /// \param in_info          Vector to operate on, and value to use.
    /// \param out_result       Vector in which the result will be stored.
    void sub_uniform(const op_unif_info *in_info, vec3::type *out_result);

    /// \section    Algorithms
    /// \brief      Multiply all axes of a vector by a value.
    ///
    /// \param in_info          Vector to operate on, and value to use.
    /// \param out_result       Vector in which the result will be stored.
    void mul_uniform(const op_unif_info *in_info, vec3::type *out_result);

    /// \section    Algorithms
    /// \brief      Divide all axes of a vector by a value.
    ///
    /// \param in_info          Vector to operate on, and value to use.
    /// \param out_result       Vector in which the result will be stored.
    void div_uniform(const op_unif_info *in_info, vec3::type *out_result);

    /// \section    Algorithms
    /// \brief      Calculates the cross product of two 3D vectors.
    ///
    /// \param in_a             Left-hand operand vector.
    /// \param in_b             Right-hand operand vector.
    /// \param out_result       Vector in which the cross product will be stored.
    void cross(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result);

    /// \section    Algorithms
    /// \brief      Calculates the dot product of two 3D vectors.
    ///
    /// \param in_a             Left-hand operand vector.
    /// \param in_b             Right-hand operand vector.
    /// \param out_result       Number in which the dot product will be stored.
    ///
    /// \notes      Fills up a 256-bit (32-byte) floating-point register exactly.
    void dot(const vec3::type *in_a, const vec3::type *in_b, double *out_result);

    /// \section    Algorithms
    /// \brief      Gets the smallest of the vector's components.
    ///
    /// \param in_a             Vector to obtain the value from.
    /// \param out_v            Number in which the value will be stored.
    ///
    /// \notes      Fills a 128-bit (16-byte) floating-point register exactly.
    void min(const vec3::type *in_vec, double *out_v);

    /// \section    Algorithms
    /// \brief      Gets the largest of the vector's components.
    ///
    /// \param in_a             Vector to obtain the value from.
    /// \param out_v            Number in which the value will be stored.
    ///
    /// \notes      Fills a 128-bit (16-byte) floating-point register exactly.
    void max(const vec3::type *in_vec, double *out_v);

    /// \section    Algorithms
    /// \brief      Calculates the total length of the vector's components.
    ///
    /// \param in_a             Vector to calculate the value from.
    /// \param out_v            Number in which the value will be stored.
    ///
    /// \notes      Fills a 128-bit (16-byte) floating-point register exactly.
    void length(const vec3::type *in_vec, double *out_v);

    /// \section    Algorithms
    /// \brief      Calculates the smallest of the vector's XY components.
    ///
    /// \param in_a             Vector to calculate the value from.
    /// \param out_v            Number in which the value will be stored.
    ///
    /// \notes      Fills a 128-bit (16-byte) floating-point register exactly.
    void length2d(const vec3::type *in_vec, double *out_v);

RPF_CLOSE
