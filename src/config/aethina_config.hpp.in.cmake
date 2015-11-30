
#ifndef AETHINA_CONFIG_HPP_INCLUDED
#define AETHINA_CONFIG_HPP_INCLUDED

// Platform
#cmakedefine AETHINA_PLATFORM_WINDOWS
#cmakedefine AETHINA_PLATFORM_UNIX

// Compiler
#cmakedefine AETHINA_COMPILER_MSVC
#cmakedefine AETHINA_COMPILER_CLANG
#cmakedefine AETHINA_COMPILER_GCC

#ifdef AETHINA_PLATFORM_WINDOWS
#  define AETHINA_API_EXPORT __declspec(dllexport)
#  define AETHINA_API_IMPORT __declspec(dllimport)
#else // AETHINA_PLATFORM_UNIX
#  define AETHINA_API_EXPORT __attribute__((visibility("default")))
#  define AETHINA_API_IMPORT
#endif

namespace aethina
{
}

#endif // AETHINA_CONFIG_HPP_INCLUDED
