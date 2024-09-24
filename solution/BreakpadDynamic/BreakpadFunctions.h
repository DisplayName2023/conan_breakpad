#pragma once


/* clang-format off */
#if defined(Breakpad_STATIC)
#  define BREAKPAD_API
#elif defined(_WIN32) /*  Windows  */
#  if defined(Breakpad_EXPORTS)
#    define BREAKPAD_API         /* __declspec(dllexport) */  // should not be exported in Macro if the project has export all functions
#  else
#    define BREAKPAD_API          __declspec(dllimport)
#  endif
#endif
/* clang-format on */

extern "C" {
	BREAKPAD_API void initBreakpad();
}

