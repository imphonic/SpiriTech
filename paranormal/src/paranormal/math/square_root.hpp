/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: square_root.hpp
 * @brief: Implementation of standard and inverse square root.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_SQUARE_ROOT_HEAD__
#define __PARA_SQUARE_ROOT_HEAD__

#include <concepts>
#include <cmath>

namespace Para::Math
  {
    /**
     * Squares a value. I was today years old when i learned
     * that e.g. 2^6 isn't actually squaring in C++.
     * \tparam Val_T Type of the input value.
     * \param in_val Value to square.
     * \return Squared value.
     */
    template <typename Val_T>
    Val_T Square(Val_T in_val)
      {
        return in_val * in_val;
      }

    /**
     * Gets the square root of a value.
     * \tparam Val_T Type of the input value.
     * \param in_of Value to get the square root of.
     * \return Square root of input.
     */
    template <typename Val_T> requires std::is_floating_point_v<Val_T>
    Val_T Sqrt(const Val_T in_of)
      {
        return std::sqrt(in_of);
      }
    template <typename Val_T> requires std::is_floating_point_v<Val_T>
    Val_T RSqrt(const Val_T in_of)
      {
        /**
         * Modern x86 has an rsqrtss instruction which this
         * should compile to... if not we will try FISR or
         * a variant.
         */
        return (Val_T) 1 / Sqrt(in_of);
      }
  }

#endif /* __PARA_SQUARE_ROOT_HEAD__ */
