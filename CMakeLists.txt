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
file(GLOB_RECURSE HEADERS paranormal/src/*.hpp solara/src/*.hpp)
file(GLOB_RECURSE SOURCES paranormal/src/*.cpp solara/src/*.cpp)

# Add the executable so CLion can do something with it
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})