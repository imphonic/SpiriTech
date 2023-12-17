cmake_minimum_required(VERSION 3.26)
project(SpiriTech_ClionSupport)

set(CMAKE_CXX_STANDARD 20)

# As the name suggests, this CMakeLists file is not used
# to build SpiriTech libraries. It's used solely to help
# JetBrains CLion recognize project sources and settings
# until I can figure out how to integrate FASTBuild
# support in the future (likely with a plugin, if that's
# even possible).

# I use Visual Studio Code to edit .bff files, and I run
# FASTBuild from the command line; this only exists to
# use CLion's infinitely better ReSharper engine (available
# in CLion Nova as of this writing).

# Add all headers and sources - it's okay, we aren't building
# with this
file(GLOB_RECURSE HEADERS engine/*.h)
file(GLOB_RECURSE INLINES engine/*.inl)
file(GLOB_RECURSE SOURCES engine/*.cpp)

# Create our "modules" (since the engine is so large)
set(ModRoot					"engine/include/engine")

# Now create module include paths (must mirror para_general.bff)
set(ModPath_Math			"${ModRoot}/math")
set(ModPath_Scene			"${ModRoot}/scene")
set(ModPath_Stdlib			"${ModRoot}/stdlib")

# Add the executable so CLion can do something with it
add_executable(${PROJECT_NAME} ${HEADERS} ${INLINES} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "engine/include/")

target_compile_definitions(${PROJECT_NAME} PUBLIC rpf_engine_platform=win32)