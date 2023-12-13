#pragma once

#include "engine/common.h"

#include "engine/platform/intern_compiler_intrinsics.h"

namespace rpf::internal
  {
    class msvc_intrinsics : public intrinsics_base
      {
      public:
        /**
         * Prefetches data at a memory address.
         * \param in_adr Memory address to prefetch.
         * \param in_write Whether this is preparing for a read or write.
         * \param in_hint Prefetching hint. For MSVC:
         * - 0 = Prefetch with non-temporal access
         * - 1 to 3 = Hint T2 to T0
         * - 7 = Hint ET0 (PREFETCHW) (do not use)
         */
        static void prefetch(auto const *in_adr, constexpr int in_write = 0, constexpr int in_hint = 3)
          {
            _mm_prefetch(in_adr, in_hint);
          }
      };
  }
