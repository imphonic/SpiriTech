/**
 * Copyright Rapidfire Computer Entertainment.
 * Licensed under GNU LGPL - see LICENSE for details.
 * @file: pointer.hpp
 * @brief: Reference-counted object pointer.
 * @author: Will Pimentel-Tonche
**/

#ifndef __PARA_REF_PTR_HEAD__
#define __PARA_REF_PTR_HEAD__

#include <memory>

namespace Para
  {
    template <typename Pointer_Tp>
    using Ptr = std::shared_ptr<Pointer_Tp>;

    template <typename Pointer_Tp>
    using WeakPtr = std::weak_ptr<Pointer_Tp>;
  }

#endif /* __PARA_REF_PTR_HEAD__ */
