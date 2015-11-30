include("${CMAKE_SOURCE_DIR}/cmake/compiler/enable_cxx11.cmake")

set(AETHINA_COMPILER_GCC ON CACHE INTERNAL "Aethina compiler")

# Enable full warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
