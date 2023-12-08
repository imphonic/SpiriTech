cmake_minimum_required(VERSION 3.26)
project(Solara_ClionSupport)

set(CMAKE_CXX_STANDARD 20)

set(RootPath src)
set(PublicInclude src)
set(LibType STATIC)

file(GLOB_RECURSE HeaderUnits src/*.hpp)
file(GLOB_RECURSE TranslUnits src/*.cpp)

add_library(${PROJECT_NAME} ${LibType} ${HeaderUnits} ${TranslUnits})

target_include_directories(${PROJECT_NAME} PUBLIC src)