cmake_minimum_required(VERSION 3.25)

project(melee-native LANGUAGES C CXX)

include(GNUInstallDirs)

option(MELEE_ENABLE_AURORA "Configure Aurora host compatibility targets" ON)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU|MSVC")
    message(FATAL_ERROR "Aurora host runtime requires a supported C++20 desktop toolchain (Clang, GCC, or MSVC).")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "src/melee/**.c" LIST_DIRECTORIES FALSE)
file(GLOB_RECURSE HSD_SOURCES "src/sysdolphin/**.c" LIST_DIRECTORIES FALSE)
set(SOURCES ${SOURCES} ${HSD_SOURCES})

set(EXCLUSIONS
    "melee/db/dberror.c" # OSContext register usage
    "melee/gm/gmmain.c" # CARDInit
    "melee/lb/lb_0195.c" # PADSetSamplingRate
    "melee/lb/lb_01F8.c" # needs dolphin/thp
    "melee/lb/lbcardnew.c" # CARD ASync
    "melee/lb/lbmthp.c" # needs dolphin/thp
    "sysdolphin/baselib/debug.c" # PPC register usage
    "sysdolphin/baselib/debugconsole_main.c" # PPC register usage
    "sysdolphin/baselib/fog.c" # GXInitFogAdjTable
    "sysdolphin/baselib/hsd_3915.c" # requires debug font from dol
    "sysdolphin/baselib/pobj.c" # nontrivial GXSetArray usage
    "sysdolphin/baselib/sislib_font.c" # requires font from dol
    "sysdolphin/baselib/video.c" # needs VIPadFrameBufferWidth
)

foreach(_exclusion IN LISTS EXCLUSIONS)
    list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/${_exclusion}")
endforeach()

add_library(melee STATIC ${SOURCES})
target_compile_definitions(melee PRIVATE TARGET_PC bool=int)

if(MELEE_ENABLE_AURORA)
    set(AURORA_ENABLE_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(AURORA_ENABLE_TESTS OFF CACHE BOOL "" FORCE)
    set(AURORA_ENABLE_GX ON CACHE BOOL "" FORCE)
    set(AURORA_ENABLE_DVD OFF CACHE BOOL "" FORCE)
    set(AURORA_ENABLE_CARD OFF CACHE BOOL "" FORCE)
    set(AURORA_ENABLE_THP OFF CACHE BOOL "" FORCE)
    add_subdirectory(libs/aurora aurora EXCLUDE_FROM_ALL)

    add_library(melee-aurora INTERFACE)
    target_link_libraries(melee-aurora INTERFACE
        aurora::core
        aurora::main
        aurora::os
        aurora::pad
        aurora::vi
        aurora::gx
    )
endif()

if(MELEE_ENABLE_AURORA)
    add_executable(melee-platform
        libs/platform/melee_platform.cpp
        libs/platform/melee_platform_loop.cpp
    )
    target_link_libraries(melee-platform PRIVATE melee-aurora)

    target_include_directories(melee-platform PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/libs
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/dolphin/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/aurora/include
        src
    )

    include(CTest)
    if(BUILD_TESTING)
        add_executable(melee-platform-loop-test
            libs/platform/melee_platform_loop.cpp
            libs/platform/melee_platform_loop_test.cpp
        )
        target_link_libraries(melee-platform-loop-test PRIVATE aurora::core)
        target_include_directories(melee-platform-loop-test PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/libs/aurora/include
        )
        add_test(NAME melee-platform-loop COMMAND melee-platform-loop-test)
    endif()
endif()

target_include_directories(melee PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libs
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/dolphin/include
    src
)

install(TARGETS melee LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")
if(MELEE_ENABLE_AURORA)
    install(TARGETS melee-platform RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
endif()
