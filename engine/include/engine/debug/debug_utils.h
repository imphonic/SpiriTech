#pragma once

#include "engine/common.h"

namespace rpf
{

class debug
    {
    RPF_DEL_MEMOPS

    [[noreturn]] static void unreachable();
    };

#define panic()

}
