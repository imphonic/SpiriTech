#pragma once

#include "engine/common.h"

#define RPF_MAKE_4D_TYPE( in_name )     \
typedef union type                      \
    {                                   \
    struct { float x_, y_, z_, w_; };   \
    __m128 raw_;                        \
    } type ;
