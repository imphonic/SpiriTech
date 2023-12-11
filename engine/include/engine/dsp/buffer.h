#pragma once


namespace rpf::dsp
  {
    namespace consts
      {
        constexpr auto BUFFER_DEPTH = 128;
      }
    using buffer = float[consts::BUFFER_DEPTH];
  }