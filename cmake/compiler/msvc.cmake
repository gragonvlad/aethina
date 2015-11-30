if (${MSVC_VERSION} LESS 1800)
  message(FATAL_ERROR "You are using an unsupported version of Visual Studio "
                      "which doesn't support all required C++11 features. "
                      "(Visual Studio 2013 (version >= 1800) is required!)")
endif()

if (PLATFORM EQUAL 64)
  add_definitions("-D_WIN64")
endif()

set(AETHINA_COMPILER_MSVC ON CACHE INTERNAL "Aethina compiler")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
