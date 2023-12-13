#pragma once

#include "engine/common.h"

#include "engine/platform/intern_compiler_intrinsics.h"

namespace rpf::internal
  {
    class gcc_intrinsics : public intrinsics_base
      {
      public:
        /**
         * Prefetches data at a memory address.
         * \param in_adr Memory address to prefetch.
         * \param in_write Whether this is preparing for a read or write.
         * \param in_hint Data locality hint. For GCC/Clang:
         * - 0 = Prefetch with non-temporal access
         * - 1 to 3: Cache levels data should be left in, with 3 being all.
         */
        static void prefetch(auto const *in_adr, constexpr int in_write = 0, constexpr int in_hint = 3)
          {
            __builtin_prefetch(&in_adr, in_write, in_hint);
          }
        /**
         * \returns One plus the index of the least significant 1-bit of x,
         *          or zero if x is zero. (From the GCC website.)
         */
        static int find_first_set(constexpr int in_x)
          {
            //return __builtin_ffs(in_x);
          }
      };
  }
