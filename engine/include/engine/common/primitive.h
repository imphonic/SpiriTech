#pragma once

#include "engine/common/utility_macros.h"

#include <cstdint>

RPF_OPEN_SUB(internal)

    struct GenericTypes
        {
        typedef uint8_t         u8;
        typedef uint16_t        u16;
        typedef uint32_t        u32;
        typedef uint64_t        u64;

        typedef int8_t          s8;
        typedef int16_t         s16;
        typedef int32_t         s32;
        typedef int64_t         s64;

        typedef float           f32;
        typedef double          f64;

        typedef unsigned int    UINT;
        typedef signed int      INT;
        typedef float           FLT;
        typedef char16_t        CHAR;

        static_assert   (sizeof(INT)    == 4);
        static_assert   (sizeof(FLT)    == 4);
        static_assert   (sizeof(CHAR)   == 2);
        };

RPF_CLOSE
