#pragma once

///
///
/// Compiler and platform support
///
///

#include "engine/common/check_architecture.h"
#include "engine/common/check_compiler.h"

///
///
/// Utility Macros
///
///

#include "engine/common/utility_macros.h"

///
///
/// Keywords and Attributes
///
///

#include "engine/common/keywords.h"

///
///
/// C/C++ fixed-width types
///
///

RPF_OPEN_SUB(internal)
    static_assert   (sizeof(int)    == 4);
    static_assert   (sizeof(float)  == 4);
    static_assert   (sizeof(void*)  == 8); // ensures 64-bit OS
RPF_CLOSE