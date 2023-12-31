#include "engine/debug/debug_utils.h"

namespace rpf
{


void debug::unreachable()
    {
    // write a log which indicates we've hit a supposedly unreachable path

    // lock execution
    #if RPF_GCC || RPF_CLANG
        __builtin_unreachable();
    #elif RPF_MSVC
        __assume(0);
    #endif
    }

}