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
 * Macro to quickly create a vectorizable for-loop for quaternions.
 * \param in_logic Logic to execute on each loop.
 */
#define VEC_LOOP( in_logic )      for (int i = 0; i < 4; i++) in_logic

#undef  VEC_LOOP

#endif /* __PARA_QUAT_OPS_HEAD__ */
