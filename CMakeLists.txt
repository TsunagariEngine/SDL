cmake_minimum_required(VERSION 2.8.9...3.19)
project(SDL2 C)
#https://cmake.org/cmake/help/v2.8.9/cmake.html


#
# Options
#

if(APPLE)
    option(UNIVERSAL "Build an AMD64/ARM64 universal binary")
endif()


#
# Variables
#

# Project generator
if(CMAKE_GENERATOR MATCHES Ninja)
    set(NINJA 1)
endif()

# Compiler
if(CMAKE_C_COMPILER_ID MATCHES Clang)
    set(CLANG 1)
endif()
if(CMAKE_C_COMPILER_ID MATCHES GNU)
    set(GCC 1)
endif()
if(CMAKE_C_COMPILER_ID MATCHES MSVC)
    set(MSVC 1)
endif()

# OS
if(CMAKE_SYSTEM_NAME MATCHES Linux)
    set(LINUX 1)
endif()
if(CMAKE_SYSTEM_NAME MATCHES FreeBSD)
    set(FREEBSD 1)
endif()
if(CMAKE_SYSTEM_NAME MATCHES NetBSD)
    set(NETBSD 1)
endif()

# Build type
set(IS_DEBUG
    "$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>")
set(IS_RELEASE
    "$<OR:$<CONFIG:Release>,$<CONFIG:MinSizeRel>,$<CONFIG:RelWithDebInfo>>")


#
# Sources
#

set(HERE ${CMAKE_CURRENT_LIST_DIR})


#
# Sources in src
#

set(SDL2_SOURCES ${SDL2_SOURCES}
    ${HERE}/src/SDL.c
    ${HERE}/src/SDL_assert.c
    ${HERE}/src/SDL_dataqueue.c
    ${HERE}/src/SDL_error.c
    ${HERE}/src/SDL_hints.c
    ${HERE}/src/SDL_log.c
    ${HERE}/src/atomic/SDL_atomic.c
    ${HERE}/src/atomic/SDL_spinlock.c
    ${HERE}/src/audio/SDL_audio.c
    ${HERE}/src/audio/SDL_audiocvt.c
    ${HERE}/src/audio/SDL_audiotypecvt.c
    ${HERE}/src/audio/SDL_mixer.c
    ${HERE}/src/audio/SDL_wave.c
    ${HERE}/src/cpuinfo/SDL_cpuinfo.c
    ${HERE}/src/events/SDL_clipboardevents.c
    ${HERE}/src/events/SDL_displayevents.c
    ${HERE}/src/events/SDL_dropevents.c
    ${HERE}/src/events/SDL_events.c
    ${HERE}/src/events/SDL_keyboard.c
    ${HERE}/src/events/SDL_mouse.c
    ${HERE}/src/events/SDL_quit.c
    ${HERE}/src/events/SDL_windowevents.c
    ${HERE}/src/file/SDL_rwops.c
    ${HERE}/src/render/SDL_render.c
    ${HERE}/src/stdlib/SDL_crc32.c
    ${HERE}/src/stdlib/SDL_malloc.c
    ${HERE}/src/stdlib/SDL_qsort.c
    ${HERE}/src/stdlib/SDL_stdlib.c
    ${HERE}/src/stdlib/SDL_string.c
    ${HERE}/src/stdlib/SDL_strtokr.c
    ${HERE}/src/thread/SDL_thread.c
    ${HERE}/src/timer/SDL_timer.c
    ${HERE}/src/video/SDL_bmp.c
    ${HERE}/src/video/SDL_fillrect.c
    ${HERE}/src/video/SDL_pixels.c
    ${HERE}/src/video/SDL_rect.c
    ${HERE}/src/video/SDL_shape.c
    ${HERE}/src/video/SDL_surface.c
    ${HERE}/src/video/SDL_video.c
    ${HERE}/src/video/SDL_yuv.c
)

if(APPLE)
    set(SDL2_SOURCES ${SDL2_SOURCES}
        ${HERE}/src/audio/coreaudio/SDL_coreaudio.m
        ${HERE}/src/core/unix/SDL_poll.c
        ${HERE}/src/core/unix/SDL_poll.c
        ${HERE}/src/file/cocoa/SDL_rwopsbundlesupport.m
        ${HERE}/src/loadso/dlopen/SDL_sysloadso.c
        ${HERE}/src/render/metal/SDL_render_metal.m
        ${HERE}/src/render/opengl/SDL_render_gl.c
        ${HERE}/src/render/opengl/SDL_shaders_gl.c
        ${HERE}/src/thread/pthread/SDL_syscond.c
        ${HERE}/src/thread/pthread/SDL_sysmutex.c
        ${HERE}/src/thread/pthread/SDL_syssem.c
        ${HERE}/src/thread/pthread/SDL_systhread.c
        ${HERE}/src/thread/pthread/SDL_systls.c
        ${HERE}/src/timer/unix/SDL_systimer.c
        ${HERE}/src/timer/unix/SDL_systimer.c
        ${HERE}/src/video/cocoa/SDL_cocoaclipboard.m
        ${HERE}/src/video/cocoa/SDL_cocoaevents.m
        ${HERE}/src/video/cocoa/SDL_cocoakeyboard.m
        ${HERE}/src/video/cocoa/SDL_cocoamessagebox.m
        ${HERE}/src/video/cocoa/SDL_cocoametalview.m
        ${HERE}/src/video/cocoa/SDL_cocoamodes.m
        ${HERE}/src/video/cocoa/SDL_cocoamouse.m
        ${HERE}/src/video/cocoa/SDL_cocoaopengl.m
        ${HERE}/src/video/cocoa/SDL_cocoashape.m
        ${HERE}/src/video/cocoa/SDL_cocoavideo.m
        ${HERE}/src/video/cocoa/SDL_cocoawindow.m
    )
endif()


#
# Targets
#

add_library(sdl2 ${SDL2_SOURCES})

include_directories(include)


#
# Source groups for IDEs
#

if(NOT ${CMAKE_VERSION} VERSION_LESS 3.8.0)
    get_target_property(SDL2_SOURCES sdl2 SOURCES)
    source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
        FILES ${SDL2_SOURCES}
    )
endif()


#
# Preprocessor definitions
#

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-strict-aliasing -D_THREAD_SAFE -x objective-c -DHAVE_GCC_ATOMICS=1 -DSDL_ASSEMBLY_ROUTINES=1 -DSDL_AUDIO_DRIVER_COREAUDIO=1 -DSDL_DYNAMIC_API=0 -DSDL_LEAN_AND_MEAN=1 -DSDL_LOADSO_DLOPEN=1 -DSDL_TIMER_UNIX=1 -DSDL_VIDEO_DRIVER_COCOA=1 -DSDL_VIDEO_METAL=1 -DSDL_VIDEO_OPENGL=1 -DSDL_VIDEO_OPENGL_CGL=1 -DSDL_VIDEO_RENDER_OGL=1")

#EXTRA_LDFLAGS="$EXTRA_LDFLAGS -Wl,-framework,CoreAudio -Wl,-framework,AudioToolbox"
#EXTRA_LDFLAGS="$EXTRA_LDFLAGS -lobjc"
#EXTRA_LDFLAGS="$EXTRA_LDFLAGS -Wl,-framework,CoreVideo"
#EXTRA_LDFLAGS="$EXTRA_LDFLAGS -Wl,-framework,Cocoa"
#EXTRA_LDFLAGS="$EXTRA_LDFLAGS -Wl,-framework,Carbon"
#EXTRA_LDFLAGS="$EXTRA_LDFLAGS -Wl,-framework,IOKit"
#if metal
#EXTRA_LDFLAGS="$EXTRA_LDFLAGS -Wl,-weak_framework,QuartzCore -Wl,-weak_framework,Metal"
#endif


#
# Compilation options
#

if(CLANG OR GCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()

# Hide most symbols
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS
        "${CMAKE_C_FLAGS} -fvisibility-inlines-hidden")
    set(CMAKE_C_FLAGS_RELEASE
        "${CMAKE_C_FLAGS_RELEASE} -fvisibility=hidden")
    set(CMAKE_C_FLAGS_MINSIZEREL
        "${CMAKE_C_FLAGS_MINSIZEREL} -fvisibility=hidden")
endif()

# Don't allow enum values outside enum range
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-enums")
endif()

# Don't allow thread-safe function-local static variables
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-threadsafe-statics")
endif()

# Disable warnings
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated-declarations")
endif()

# Reduce code size
if(CLANG)
    set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -Oz")
endif()

# Enable floating point optimizations
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffast-math")
elseif(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /fp:fast")
endif()

# Disable stack canary
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-stack-protector")
elseif(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /GS-")
endif()

# Disable frame pointer
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS_RELEASE
        "${CMAKE_C_FLAGS_RELEASE} -fomit-frame-pointer")
    set(CMAKE_C_FLAGS_MINSIZEREL
        "${CMAKE_C_FLAGS_MINSIZEREL} -fomit-frame-pointer")
endif()

# Optimize at link time
if(CLANG OR GCC)
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -flto")
    set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -flto")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO
        "${CMAKE_C_FLAGS_RELWITHDEBINFO} -flto")
endif()

# Enable NDEBUG anything not a debug build.
if(${CMAKE_VERSION} VERSION_LESS 2.8.10)
    set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -DNDEBUG")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DNDEBUG")
else()
    target_compile_definitions(sdl2 PUBLIC $<$<NOT:${IS_DEBUG}>:NDEBUG>)
endif()

# Enable RELEASE in anything with optimizations.
if(${CMAKE_VERSION} VERSION_LESS 2.8.10)
    set(CMAKE_C_FLAGS_MINSIZEREL
        "${CMAKE_C_FLAGS_MINSIZEREL} -DRELEASE")
    set(CMAKE_C_FLAGS_RELEASE
        "${CMAKE_C_FLAGS_RELEASE} -DRELEASE")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO
       "${CMAKE_C_FLAGS_MINSIZEREL} -DRELEASE")
else()
    target_compile_definitions(sdl2 PUBLIC $<${IS_RELEASE}:RELEASE>)
endif()

# Enable color within compiler's output
if(NOT DEFINED ENV{CI})
    if(NINJA AND CLANG)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcolor-diagnostics")
    endif()
    if(NINJA AND GCC AND NOT CMAKE_C_COMPILER_VERSION VERSION_LESS 4.9)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdiagnostics-color=always")
    endif()
endif()

if(UNIVERSAL)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -arch x86_64 -arch arm64")
endif()

if(APPLE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mmacosx-version-min=10.11")
endif()


#
# Policies
#

# Do not turn on -rdynamic. Also solved with CMP0065 in CMake 3.4
# FIXME: Apply it only to local targets, or possibly just try to
#        remove -rdynamic from these.
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
