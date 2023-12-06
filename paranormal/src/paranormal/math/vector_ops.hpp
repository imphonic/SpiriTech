/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: vector_ops.hpp
 * @brief: Operations which can be done on 3D vectors.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_VEC_OPS_HEAD__
#define __PARA_VEC_OPS_HEAD__

#include "vector.hpp"

/**
 * smaller but frequent functions like this are packed into
 * their own header so we don't have to pull tons of inline
 * math functions just to use one
 */
#include "min_max.hpp"
#include "square_root.hpp"

/**
 * Macro to quickly create a for-loop for a vector. I'm not sure if
 * the 12-byte vectors can actually be vectorized (I know the 16-byte
 * quats can), but if they can't, worst case scenario is that the compiler
 * will just unroll the loops for me; at least I tried.
 * \param in_logic Logic to execute on each loop.
 */
#define VEC_LOOP( in_logic )      for (int i = 0; i < 3; i++) in_logic

namespace Para::Math
  {
    /**
     * Element-wise addition of two vectors.
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return The output vector.
     */
    inline vec3_t operator+(const vec3_t in_a, const vec3_t in_b)
      {
        vec3_t loc_return;
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] + in_b.data[i]; })
        return loc_return;
      }

    /**
     * Element-wise subtraction of two vectors.
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return The output vector.
     */
    inline vec3_t operator-(const vec3_t in_a, const vec3_t in_b)
      {
        vec3_t loc_return;
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] - in_b.data[i]; })
        return loc_return;
      }

    /**
     * Element-wise multiplication of two vectors.
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return The output vector.
     */
    inline vec3_t operator*(const vec3_t in_a, const vec3_t in_b)
      {
        vec3_t loc_return;
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] * in_b.data[i]; })
        return loc_return;
      }

    /**
     * Element-wise division of two vectors.
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return The output vector.
     */
    inline vec3_t operator/(const vec3_t in_a, const vec3_t in_b)
      {
        vec3_t loc_return;
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] / in_b.data[i]; })
        return loc_return;
      }

    /**
     * Element-wise add-assign of a vector, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand vector which will be modified.
     * \param in_b Right-hand vector.
     */
    inline void operator+=(vec3_t *in_a, const vec3_t in_b)
      {
        VEC_LOOP({ in_a->data[i] += in_b.data[i]; })
      }

    /**
     * Element-wise subtract-assign of a vector, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand vector which will be modified.
     * \param in_b Right-hand vector.
     */
    inline void operator-=(vec3_t *in_a, const vec3_t in_b)
      {
        VEC_LOOP({ in_a->data[i] -= in_b.data[i]; })
      }

    /**
     * Element-wise multiply-assign of a vector, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand vector which will be modified.
     * \param in_b Right-hand vector.
     */
    inline void operator*=(vec3_t *in_a, const vec3_t in_b)
      {
        VEC_LOOP({ in_a->data[i] *= in_b.data[i]; })
      }

    /**
     * Element-wise divide-assign of a vector, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand vector which will be modified.
     * \param in_b Right-hand vector.
     */
    inline void operator/=(vec3_t *in_a, const vec3_t in_b)
      {
        VEC_LOOP({ in_a->data[i] /= in_b.data[i]; })
      }

    /**
     * Sets a vector to the given value.
     * \param in_target Vector to set.
     * \param in_v Value to set the vector to (form { X, Y, Z }).
     */
    inline void operator=(vec3_t *in_target, const vec3_t::data_t in_v)
      {
        VEC_LOOP({ in_target->data[i] = in_v[i]; })
      }

    /**
     * Check if two vectors are equivalent (all axes are the same).
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return Whether the two vectors are equivalent.
     * \note I'd like to try vectorizing this once my bitwise arithmetic
     * skills have improved.
     */
    inline bool operator==(const vec3_t in_a, const vec3_t in_b)
      {
        bool loc_return = true;
        VEC_LOOP({ loc_return ^= in_a.data[i] == in_b.data[i]; })
        return loc_return;
      }

    /**
     * Check if two vectors are NOT equivalent (at least one pair
     * of axes differ).
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return Whether the two vectors are NOT equivalent.
     */
    inline bool operator!=(const vec3_t in_a, const vec3_t in_b)
      {
        bool loc_return = false;
        VEC_LOOP({ loc_return |= in_a.data[i] != in_b.data[i]; })
        return loc_return;
      }

    /**
     * Computes the cross-product of two vectors.
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return The output vector.
     * \note I'd like to try vectorizing this later but it's not really
     * a concern right now.
     */
    inline vec3_t CrossProduct(const vec3_t in_a, const vec3_t in_b)
      {
        return vec3_t
          {
            in_a.y * in_b.z - in_a.z * in_b.y,
            in_a.z * in_b.x - in_a.x * in_b.z,
            in_a.x * in_b.y - in_a.y * in_b.z
          };
      }

    /**
     * Computes the dot-product of two vectors.
     * \param in_a Left-hand vector.
     * \param in_b Right-hand vector.
     * \return The output value.
     */
    inline vec3_t::val_t DotProduct(const vec3_t in_a, const vec3_t in_b)
      {
        vec3_t::val_t loc_return {};
        VEC_LOOP({ loc_return += in_a.data[i] * in_b.data[i]; })
        return loc_return;
      }

    /* Why did I choose to make every function non-member?
     *
     * The pointer costs below are identical to a member function
     * call, but the cost is much more obvious up-front. Same reason
     * that I'm using pointers and not references; cost is the same
     * but pointers make that more verbose.
     *
     * Remember: We need performance. I'm willing to make the code
     * more verbose if it makes the cost of the work more obvious.
     */

    /**
     * \param in_target Vector to evaluate.
     * \return Axis of the vector with the greatest value.
     */
    inline vec3_t::val_t GetMaxVal(vec3_t const * const in_target)
      {
        return Max(Max(in_target->x, in_target->y), in_target->z);
      }

    /**
     * \param in_target Vector to evaluate.
     * \return Axis of the vector with the smallest value.
     */
    inline vec3_t::val_t GetMinVal(vec3_t const * const in_target)
      {
        return Min(Min(in_target->x, in_target->y), in_target->z);
      }

    /**
     * \param in_target Vector to evaluate.
     * \return Length of the vector.
     */
    inline vec3_t::val_t VecLength(const vec3_t in_target)
      {
        vec3_t::val_t loc_to_sq {};
        VEC_LOOP({ loc_to_sq += Square(in_target.data[i]); })
        return Sqrt(loc_to_sq);
      }

    /**
     * \param in_target Vector to evaluate.
     * \return 2D (XY) length of the vector.
     */
    inline vec3_t::val_t VecLength2D(const vec3_t in_target)
      {
        return Sqrt(Square(in_target.x) + Square(in_target.y));
      }
  }

#undef VEC_LOOP

#endif /* __PARA_VEC_OPS_HEAD__ */
