#pragma once

#include "engine/common.h"

#include "engine/math/vec3.h"
#include "engine/math/vec3_constants.h"

rpf_engine_begin_subspace( math::vec3 )

    struct init_info { float x_, y_, z_; };

    /// \section Algorithms \brief Sets a vector to the given component (XYZ) values.
    void set(const init_info *in_components, vec3::type *out_vec);

    /// \section Algorithms \brief Element-wise addition of two 3D vectors.
    void add(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result);

    /// \section Algorithms \brief Element-wise subtraction of two 3D vectors.
    void sub(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result);

    /// \section Algorithms \brief Element-wise multiplication of two 3D vectors.
    void mul(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result);

    /// \section Algorithms \brief Element-wise division of two 3D vectors.
    void div(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result);

    /// \section Algorithms \brief Calculates the cross-product of two vectors.
    void cross(const vec3::type *in_a, const vec3::type *in_b, vec3::type *out_result);

    /// \section Algorithms \brief Calculates the dot-product of two vectors.
    /// \note Fills up a 256-bit (32-byte) floating-point register exactly.
    void dot(const vec3::type *in_a, const vec3::type *in_b, double *out_result);

    /// \section Algorithms \brief Returns whether two vectors are the same.
    bool equivalent(const vec3::type *in_a, const vec3::type *in_b);

rpf_engine_end
