#pragma once
#define LIBPNG_LIB_NAME "png15"

#if defined(LIBPNG_LIB_DYNAMIC)
#  define LIBPNG_LIB_PREFIX
#elif defined(_WIN32)
#  define LIBPNG_LIB_PREFIX "lib"
#endif

#if defined(_WIN64)
#  define LIBPNG_LIB_PLATFORM "-x64"
#elif defined(_WIN32)
#  define LIBPNG_LIB_PLATFORM "-x86"
#endif

#ifdef _DLL
#  if defined(_DEBUG)
// MDd
#    define LIBPNG_LIB_RT_OPT "-gd"
#  else
// MD
#    define LIBPNG_LIB_RT_OPT
#  endif
#else
#  if defined(_DEBUG)
// MTd
#    define LIBPNG_LIB_RT_OPT "-sgd"
#  else
// MT
#    define LIBPNG_LIB_RT_OPT "-s"
#  endif
#endif

#  pragma comment(lib, LIBPNG_LIB_PREFIX LIBPNG_LIB_NAME LIBPNG_LIB_RT_OPT LIBPNG_LIB_PLATFORM ".lib")
// static MDd x86 : libpng-gd-x86.lib
// static MD x86 : libpng-x86.lib
// static MTd x86 : libpng-sgd-x86.lib
// static MT x86 : libpng-s-x86.lib

// dll MDd x86 : png-gd-x86.lib
// dll MD x86 : png-x86.lib
// dll MTd x86 : png-sgd-x86.lib
// dll MT x86 : png-s-x86.lib


