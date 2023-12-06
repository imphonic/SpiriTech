/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: quat_ops.hpp
 * @brief: Operations which can be done on quaternions.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_QUAT_OPS_HEAD__
#define __PARA_QUAT_OPS_HEAD__

#include "quat.hpp"

/**
 * smaller but frequent functions like this are packed into
 * their own header so we don't have to pull tons of inline
 * math functions just to use one
 */
#include "min_max.hpp"
#include "square_root.hpp"

/**
 * Macro to quickly create a vectorizable for-loop for quaternions.
 * \param in_logic Logic to execute on each loop.
 */
#define VEC_LOOP( in_logic )      for (int i = 0; i < 4; i++) in_logic

namespace Para::Math
  {
    /**
     * Element-wise addition of two quaternions.
     * \param in_a Left-hand quaternion.
     * \param in_b Right-hand quaternion.
     * \return The output quaternion.
     */
    inline quat4_t operator+(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t loc_return;
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] + in_b.data[i]; })
        return loc_return;
      }

    /**
     * Element-wise subtraction of two quaternions.
     * \param in_a Left-hand quaternion.
     * \param in_b Right-hand quaternion.
     * \return The output quaternion.
     */
    inline quat4_t operator-(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t loc_return;
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] - in_b.data[i]; })
        return loc_return;
      }

    /**
     * Element-wise multiplication of two quaternions.
     * \param in_a Left-hand quaternion.
     * \param in_b Right-hand quaternion.
     * \return The output quaternion.
     */
    inline quat4_t operator*(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t loc_return;
        // [ (Q2.w * Q1.x) + (Q2.x * Q1.w) + (Q2.y * Q1.z) - (Q2.z * Q1.y),
        //   (Q2.w * Q1.y) - (Q2.x * Q1.z) + (Q2.y * Q1.w) + (Q2.z * Q1.x),
        //   (Q2.w * Q1.z) + (Q2.x * Q1.y) - (Q2.y * Q1.x) + (Q2.z * Q1.w),
        //   (Q2.w * Q1.w) - (Q2.x * Q1.x) - (Q2.y * Q1.y) - (Q2.z * Q1.z) ]
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] * in_b.data[i]; })
        return loc_return;
      }

    /**
     * Element-wise division of two quaternions.
     * \param in_a Left-hand quaternion.
     * \param in_b Right-hand quaternion.
     * \return The output quaternion.
     */
    inline quat4_t operator/(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t loc_return;
        /* For better performance we multiply by the reciprocal */
        VEC_LOOP({ loc_return.data[i] = in_a.data[i] * (1 / in_b.data[i]); })
        return loc_return;
      }

    /**
     * Element-wise add-assign of a quaternion, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand quaternion which will be modified.
     * \param in_b Right-hand quaternion.
     */
    inline void operator+=(quat4_t &in_a, const quat4_t in_b)
      {
        VEC_LOOP({ in_a.data[i] += in_b.data[i]; })
      }

    /**
     * Element-wise subtract-assign of a quaternion, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand quaternion which will be modified.
     * \param in_b Right-hand quaternion.
     */
    inline void operator-=(quat4_t &in_a, const quat4_t in_b)
      {
        VEC_LOOP({ in_a.data[i] -= in_b.data[i]; })
      }

    /**
     * Element-wise multiply-assign of a quaternion, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand quaternion which will be modified.
     * \param in_b Right-hand quaternion.
     */
    inline void operator*=(quat4_t &in_a, const quat4_t in_b)
      {
        VEC_LOOP({ in_a.data[i] *= in_b.data[i]; })
      }

    /**
     * Element-wise divide-assign of a quaternion, given the source (in_a)
     * and operand (in_b).
     * \param in_a Left-hand quaternion which will be modified.
     * \param in_b Right-hand quaternion.
     */
    inline void operator/=(quat4_t &in_a, const quat4_t in_b)
      {
        VEC_LOOP({ in_a.data[i] *= (1 / in_b.data[i]); })
      }

    /**
     * Sets a quaternion to the given value.
     * \param in_target Quaternion to set.
     * \param in_v Value to set the quaternion to (form { X, Y, Z }).
     */
    inline void operator=(quat4_t *in_target, const quat4_t::data_t in_v)
      {
        VEC_LOOP({ in_target->data[i] = in_v[i]; })
      }

    /**
     * Check if two quaternions are equivalent (all axes are the same).
     * \param in_a Left-hand quaternion.
     * \param in_b Right-hand quaternion.
     * \return Whether the two quaternions are equivalent.
     */
    inline bool operator==(const quat4_t in_a, const quat4_t in_b)
      {
        bool loc_return = true;
        VEC_LOOP({ loc_return ^= in_a.data[i] == in_b.data[i]; })
        return loc_return;
      }

    /**
     * Check if two quaternions are NOT equivalent (at least one pair
     * of axes differ).
     * \param in_a Left-hand quaternion.
     * \param in_b Right-hand quaternion.
     * \return Whether the two quaternions are NOT equivalent.
     */
    inline bool operator!=(const quat4_t in_a, const quat4_t in_b)
      {
        bool loc_return = false;
        VEC_LOOP({ loc_return |= in_a.data[i] != in_b.data[i]; })
        return loc_return;
      }

    /**
     * Computes the dot-product of two quaternions.
     * \param in_a Left-hand quaternion.
     * \param in_b Right-hand quaternion.
     * \return The output value.
     */
    inline quat4_t::val_t DotProduct(const quat4_t in_a, const quat4_t in_b)
      {
        quat4_t::val_t loc_return {};
        VEC_LOOP({ loc_return += in_a.data[i] * in_b.data[i]; })
        return loc_return;
      }

    /**
     * \param in_target Quaternion to evaluate.
     * \return Length of the quaternion.
     */
    inline quat4_t::val_t QuatLength(const quat4_t in_target)
      {
        quat4_t::val_t loc_to_sq {};
        VEC_LOOP({ loc_to_sq += Square(in_target.data[i]); })
        return Sqrt(loc_to_sq);
      }
  }

#undef  VEC_LOOP

#endif /* __PARA_QUAT_OPS_HEAD__ */
