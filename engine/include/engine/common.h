#pragma once

/// Deletes a class' new/delete operators, helps enforce that a class is static.
#define rpf_engine_delete_mem_ops                                               \
  public:                                                                       \
    void* operator new      (unsigned long long) noexcept = delete;             \
    void* operator new[]    (unsigned long long) noexcept = delete;             \
    void  operator delete   (void*)              noexcept = delete;             \
    void  operator delete[] (void*)              noexcept = delete;

#define rpf_engine_class_generated() \
  rpf_engine_delete_mem_ops

#define rpf_engine_begin                            namespace rpf {
#define rpf_engine_end                              }
#define rpf_engine_begin_subspace( in_subspace )    namespace rpf::in_subspace {

rpf_engine_begin
    typedef unsigned short          ushort;
    typedef unsigned int            uint;
rpf_engine_end

rpf_engine_begin_subspace( internal )
    static_assert   (sizeof(ushort) == 2);
    static_assert   (sizeof(short)  == 2);
    static_assert   (sizeof(uint)   == 4);
    static_assert   (sizeof(int)    == 4);
rpf_engine_end