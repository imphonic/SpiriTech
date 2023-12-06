/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: min_max.hpp
 * @brief: Picks which value is smaller (min) or larger (max).
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_MATH_MAX_HEAD__
#define __PARA_MATH_MAX_HEAD__

namespace Para::Math
  {
    template <typename First_T, typename Second_T = First_T>
    First_T Min(First_T in_a, Second_T in_b)
     {
      return in_a < in_b ? in_a : in_b;
     }

    template <typename First_T, typename Second_T = First_T>
    First_T Max(First_T in_a, Second_T in_b)
     {
      return in_a > in_b ? in_a : in_b;
     }
  }

#endif /* __PARA_MATH_MAX_HEAD__ */
