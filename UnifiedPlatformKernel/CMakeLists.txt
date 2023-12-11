#
# Unified Platform Kernel (UPK): High-performance C++ library
# which abstracts away graphics API, math, user interfaces,
# and other often platform-specific technologies behind a thin,
# lightweight, easy-to-use library. Designed for use in video
# games and workstation applications.
#

cmake_minimum_required(VERSION 3.26)
project(Renker_CLION)

set(CMAKE_CXX_STANDARD 20)

set(RootPath src)
set(PublicInclude src)
set(LibType STATIC)

file(GLOB_RECURSE HeaderUnits src/*.h)
file(GLOB_RECURSE TranslUnits src/*.cpp)

add_library(${PROJECT_NAME} ${LibType} ${HeaderUnits} ${TranslUnits})

target_compile_definitions(${PROJECT_NAME} PUBLIC rfgk_build_module)

target_include_directories(${PROJECT_NAME} PUBLIC src)