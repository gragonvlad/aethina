# Select the compiler specific cmake file
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  include("${CMAKE_SOURCE_DIR}/cmake/compiler/clang.cmake")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  include("${CMAKE_SOURCE_DIR}/cmake/compiler/gcc.cmake")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  include("${CMAKE_SOURCE_DIR}/cmake/compiler/msvc.cmake")
else()
  message(FATAL_ERROR "Unknown compiler!")
endif()
