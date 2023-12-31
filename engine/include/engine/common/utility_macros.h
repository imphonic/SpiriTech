#pragma once

/// \section    Utility Macros
/// \brief      Deletes a type's memory management operators. Enforces stack
///             allocation, or no allocation (in case of static types).
#define RPF_DEL_MEMOPS                                                  \
    public:                                                             \
        void* operator new      (unsigned long long) noexcept = delete; \
        void* operator new[]    (unsigned long long) noexcept = delete; \
        void  operator delete   (void*)              noexcept = delete; \
        void  operator delete[] (void*)              noexcept = delete;

/// \section    Utility Macros
/// \brief      Creates an 'extern "C"' declaration. Exposes the type/method to
///             the C API.
#define RPF_EXT_C           extern "C"

/// \section    Utility Macros
/// \brief      Opens the top-level Rapidfire C++ namespace.
#define RPF_OPEN                       namespace rpf {

/// \section    Utility Macros
/// \brief      Opens a sub-space of the Rapidfire C++ namespace.
#define RPF_OPEN_SUB( in_subspace )    namespace rpf::in_subspace {

/// \section    Utility Macros
/// \brief      Opens an anonymous namespace.
#define RPF_OPEN_ANON                  namespace {

/// \section    Utility Macros
/// \brief      Closes a namespace.
#define RPF_CLOSE                      }