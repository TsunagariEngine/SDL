/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2021 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL_config_macosx_h_
#define SDL_config_macosx_h_
#define SDL_config_h_

#include "SDL_platform.h"

/* This gets us MAC_OS_X_VERSION_MIN_REQUIRED... */
#include <AvailabilityMacros.h>

/* This is a set of defines to configure the SDL features */

#ifdef __LP64__
    #define SIZEOF_VOIDP 8
#else
    #define SIZEOF_VOIDP 4
#endif

/* Useful headers */
#define STDC_HEADERS    1
#define HAVE_ALLOCA_H       1
#define HAVE_CTYPE_H    1
#define HAVE_FLOAT_H    1
#define HAVE_INTTYPES_H 1
#define HAVE_LIMITS_H   1
#define HAVE_MATH_H 1
#define HAVE_SIGNAL_H   1
#define HAVE_STDINT_H   1
#define HAVE_STRING_H   1
#define HAVE_SYS_TYPES_H    1
#define HAVE_LIBUNWIND_H    1

/* C library functions */
#define HAVE_MALLOC 1
#define HAVE_CALLOC 1
#define HAVE_REALLOC    1
#define HAVE_FREE   1
#define HAVE_ALLOCA 1
#define HAVE_QSORT  1
#define HAVE_ABS    1
#define HAVE_BCOPY  1
#define HAVE_MEMSET 1
#define HAVE_MEMCPY 1
#define HAVE_MEMMOVE    1
#define HAVE_MEMCMP 1
#define HAVE_STRLEN 1
#define HAVE_STRLCPY    1
#define HAVE_STRLCAT    1
#define HAVE_STRCHR 1
#define HAVE_STRRCHR    1
#define HAVE_STRSTR 1
#define HAVE_STRTOK_R 1
#define HAVE_STRTOL 1
#define HAVE_STRTOUL    1
#define HAVE_STRTOLL    1
#define HAVE_STRTOULL   1
#define HAVE_STRTOD 1
#define HAVE_ATOI   1
#define HAVE_ATOF   1
#define HAVE_STRCMP 1
#define HAVE_STRNCMP    1
#define HAVE_STRCASECMP 1
#define HAVE_STRNCASECMP 1
#define HAVE_VSSCANF 1
#define HAVE_VSNPRINTF  1
#define HAVE_M_PI   1
#define HAVE_ACOS   1
#define HAVE_ACOSF  1
#define HAVE_ASIN   1
#define HAVE_ASINF  1
#define HAVE_ATAN   1
#define HAVE_ATANF  1
#define HAVE_ATAN2  1
#define HAVE_ATAN2F 1
#define HAVE_CEIL   1
#define HAVE_CEILF  1
#define HAVE_COPYSIGN   1
#define HAVE_COPYSIGNF  1
#define HAVE_COS    1
#define HAVE_COSF   1
#define HAVE_EXP    1
#define HAVE_EXPF   1
#define HAVE_FABS   1
#define HAVE_FABSF  1
#define HAVE_FLOOR  1
#define HAVE_FLOORF 1
#define HAVE_FMOD   1
#define HAVE_FMODF  1
#define HAVE_LOG    1
#define HAVE_LOGF   1
#define HAVE_LOG10  1
#define HAVE_LOG10F 1
#define HAVE_LROUND 1
#define HAVE_LROUNDF 1
#define HAVE_POW    1
#define HAVE_POWF   1
#define HAVE_ROUND 1
#define HAVE_ROUNDF 1
#define HAVE_SCALBN 1
#define HAVE_SCALBNF    1
#define HAVE_SIN    1
#define HAVE_SINF   1
#define HAVE_SQRT   1
#define HAVE_SQRTF  1
#define HAVE_TAN    1
#define HAVE_TANF   1
#define HAVE_TRUNC    1
#define HAVE_TRUNCF   1
#define HAVE_SIGACTION  1
#define HAVE_SETJMP 1
#define HAVE_NANOSLEEP  1
#define HAVE_SYSCONF    1
#define HAVE_SYSCTLBYNAME 1

#define HAVE_GCC_ATOMICS 1

/* Enable various audio drivers */
#define SDL_AUDIO_DRIVER_COREAUDIO  1

/* Enable various shared object loading systems */
#define SDL_LOADSO_DLOPEN   1

/* Enable various threading systems */
#define SDL_THREAD_PTHREAD  1
#define SDL_THREAD_PTHREAD_RECURSIVE_MUTEX  1

/* Enable various timer systems */
#define SDL_TIMER_UNIX  1

/* Enable various video drivers */
#define SDL_VIDEO_DRIVER_COCOA  1

//#ifndef SDL_VIDEO_RENDER_OGL
//#define SDL_VIDEO_RENDER_OGL    1
//#endif

/* Metal only supported on 64-bit architectures with 10.11+ */
#ifdef TSU_METAL
#if TARGET_RT_64_BIT && (MAC_OS_X_VERSION_MAX_ALLOWED >= 101100)
#define SDL_PLATFORM_SUPPORTS_METAL    1
#else
#define SDL_PLATFORM_SUPPORTS_METAL    0
#endif
#endif

#ifdef TSU_METAL
#ifndef SDL_VIDEO_RENDER_METAL
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_RENDER_METAL    1
#else
#define SDL_VIDEO_RENDER_METAL    0
#endif
#endif
#endif

/* Enable OpenGL support */
#ifdef TSU_OPENGL
#ifndef SDL_VIDEO_OPENGL
#define SDL_VIDEO_OPENGL    1
#endif
#ifndef SDL_VIDEO_OPENGL_CGL
#define SDL_VIDEO_OPENGL_CGL    1
#endif
#endif

/* Enable Metal support */
#ifdef TSU_METAL
#ifndef SDL_VIDEO_METAL
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_METAL 1
#else
#define SDL_VIDEO_METAL 0
#endif
#endif
#endif

/* Enable assembly routines */
#define SDL_ASSEMBLY_ROUTINES   1
#ifdef __ppc__
#define SDL_ALTIVEC_BLITTERS    1
#endif

#define SDL_JOYSTICK_DISABLED 1
#define SDL_HAPTIC_DISABLED 1
#define SDL_GAMECONTROLLER_DISABLED 1
#define SDL_SENSOR_DISABLED 1
#define SDL_POWER_DISABLED 1
//#define SDL_LOADSO_DISABLED 1  // Can we do this?
#define SDL_FILESYSTEM_DISABLED 1

#endif /* SDL_config_macosx_h_ */
