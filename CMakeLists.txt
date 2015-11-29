project(Aethina CXX)
cmake_minimum_required(VERSION 2.8)

# Only interpret if() arguments as variables or
# keywords when unquoted.
cmake_policy(SET CMP0054 NEW)

include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)
include(CheckIncludeFiles)

include(cmake/configure_platform.cmake)
include(cmake/configure_compiler.cmake)

add_executable(Dummy src/dummy.cpp)
