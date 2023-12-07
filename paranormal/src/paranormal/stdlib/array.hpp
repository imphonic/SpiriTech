/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: array.hpp
 * @brief: Basic fixed-size array structure.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_STDLIB_ARRAY_HEAD__
#define __PARA_STDLIB_ARRAY_HEAD__

#include "paranormal/stdlib/types.hpp"

namespace Para
  {
    /**
     * The problem we want to solve:
     *
     * We need to be able to pass around the size of a C array:
     * - Without using cache line space to pass it around (by parameter)
     * - Without having to inline the function at hand
     *
     * Current solutions I can think of:
     * - constexpr parameters
     */

    /**
     * Convenience template for creating a C-style array.
     */
    template <typename T, idx N>
    using Array = T[N];

    template <typename T, idx N>
    constexpr idx ArLength(constexpr Array<T, N> in_array)
      {
        return N;
      }

    template <typename T, idx N>
    constexpr idx ArLength(T (&)[N])
      {
        return N;
      }

    inline void Test()
      {
        int Obj[32];
        constexpr idx ObjNum = ArLength(Obj);
      }
  }

#endif /* __PARA_STDLIB_ARRAY_HEAD__ */
