/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: vector.hpp
 * @brief: Positional and rotational vector types.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_VECTOR_HEAD__
#define __PARA_VECTOR_HEAD__

#define DECLARE_CONSTANT( in_type, in_name, /* in_args */ ... )   \
  constexpr in_type in_name = /* in_args */ __VA_ARGS__

namespace Para::Math
  {
    using vec3_t = union Vector
      {
        using val_t = float;

        /* Use this to access elements individually. */
        struct
          {
            /* x = Forward, y = Right, z = Up */
            val_t x, y, z;
          };

        /* Allows for easy vectorization. Don't use directly. */
        val_t data[3];
      };

    DECLARE_CONSTANT(vec3_t, k_zero_vec,      { 0.f, 0.f, 0.f }   );
    DECLARE_CONSTANT(vec3_t, k_identity_vec,  { 1.f, 1.f, 1.f }   );
    DECLARE_CONSTANT(vec3_t, k_forward_vec,   { 1.f, 0.f, 0.f }   );
    DECLARE_CONSTANT(vec3_t, k_backward_vec,  { -1.f, 0.f, 0.f }  );
    DECLARE_CONSTANT(vec3_t, k_right_vec,     { 0.f, 1.f, 0.f }   );
    DECLARE_CONSTANT(vec3_t, k_left_vec,      { 0.f, -1.f, 0.f }  );
    DECLARE_CONSTANT(vec3_t, k_up_vec,        { 0.f, 0.f, 1.f }   );
    DECLARE_CONSTANT(vec3_t, k_down_vec,      { 0.f, 0.f, -1.f }  );
    DECLARE_CONSTANT(vec3_t, k_x_vec,         k_forward_vec       );
    DECLARE_CONSTANT(vec3_t, k_y_vec,         k_right_vec         );
    DECLARE_CONSTANT(vec3_t, k_z_vec,         k_up_vec            );
  }


#undef DECLARE_CONSTANT

#endif /* __PARA_VECTOR_HEAD__ */
