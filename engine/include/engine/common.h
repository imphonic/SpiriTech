#pragma once

// This file is currently empty, but should be included in all engine headers.
// This allows for trivial fixes when an assumption my dumb ass made has gone wrong.

/**
 * Creates a constant in the rpf::consts namespace.
 * \param in_tp Type of the constant.
 * \param in_id Name of the constant.
 */
#define RF_ENGINE_DECL_CONSTANT( in_tp, in_id, ... /* val */ )                 \
  namespace rpf::consts                                                        \
    {                                                                          \
      constexpr in_tp in_id = __VA_ARGS__;                                     \
    }
/**
 * Creates a constant in the rpf::consts::in_ns namespace.
 * \param in_ns Sub-namespace this constant belongs to (e.g. dsp).
 * \param in_tp Type of the constant.
 * \param in_id Name of the constant.
 */
#define RF_ENGINE_DECL_CONSTANT_SUBSPACE( in_ns, in_tp, in_id, ... /* val */ ) \
  namespace rpf::consts::in_ns                                                 \
    {                                                                          \
      constexpr in_tp in_id = __VA_ARGS__;                                     \
    }

/**
 * Deletes a class' new/delete operators, can help enforce that a class is static.
 */
#define rpf_engine_delete_mem_ops                                               \
  public:                                                                       \
    void* operator new      (unsigned long long) noexcept = delete;             \
    void* operator new[]    (unsigned long long) noexcept = delete;             \
    void  operator delete   (void*)              noexcept = delete;             \
    void  operator delete[] (void*)              noexcept = delete;

#define rpf_engine_class_generated() \
  rpf_engine_delete_mem_ops