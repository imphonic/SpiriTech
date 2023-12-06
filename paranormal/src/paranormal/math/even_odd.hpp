/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: even_odd.hpp
 * @brief: Utilities for checking if a value is even/odd.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_MATH_EVEN_ODD_HEAD__
#define __PARA_MATH_EVEN_ODD_HEAD__

#include <concepts>

namespace Para::Math
  {
    template <typename Val_T> requires std::is_integral_v<Val_T>
    bool IsEven(const Val_T in_val)
      {
        return (in_val & 0x1) == 0;
      }

    template <typename Val_T> requires std::is_integral_v<Val_T>
    bool IsOdd(const Val_T in_val)
      {
        return (in_val & 0x1) > 0;
      }
  }

#endif /* __PARA_MATH_EVEN_ODD_HEAD__ */
