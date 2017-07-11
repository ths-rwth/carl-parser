cmake_minimum_required(VERSION 3.0.0)
project(carl-parser)
include(ExternalProject)


set(DYNAMIC_EXT ".so")
set(STATIC_EXT ".a")
if(APPLE)
    set(DYNAMIC_EXT ".dylib")
    set(STATIC_EXT ".a")
elseif (WIN32)
    set(DYNAMIC_EXT ".dll")
    set(STATIC_EXT ".lib")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang") # Matches "Clang" and "AppleClang"
    if (APPLE)
        message(STATUS "Using clang ${CMAKE_CXX_COMPILER_VERSION} on apple")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -stdlib=libc++")

        ##  RPATH settings
        set(CMAKE_MACOSX_RPATH 1)
        # don't skip the full RPATH for the build tree
        SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
        # when building, don't use the install RPATH already (but only when installing)
        SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
        # the RPATH to be used when installing
        SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
        # add the automatically determined parts of the RPATH
        # which point to directories outside the build tree to the install RPATH
        SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

    else()
        message(STATUS "Using clang ${CMAKE_CXX_COMPILER_VERSION}")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_RELEASE_FLAGS} -O3 -fomit-frame-pointer -msse -msse2 -funroll-loops")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_DEBUG_FLAGS} -O1")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "Using g++ ${CMAKE_CXX_COMPILER_VERSION}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wunknown-pragmas")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmax-errors=5 -fdiagnostics-color=auto")
    set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_RELEASE_FLAGS} -O3")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_DEBUG_FLAGS} -O1")
else()
    message(WARNING "Possibly unsupported compiler ${CMAKE_CXX_COMPILER_ID}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

find_package(carl REQUIRED)
set(ANTLR_VERSION "4.7")
include(resources/antlr4.cmake)
include(cmake/export_target.cmake)
message(STATUS "Use shipped version of ANTLR ${ANTLR_VERSION}")

add_subdirectory(src)
add_subdirectory(test)

# Add all targets to the build-tree export set
set(EXPORT_TARGETS "carl-parser")
export(TARGETS ${EXPORT_TARGETS} FILE "${PROJECT_BINARY_DIR}/carlparserTargets.cmake")

message(STATUS "Registered with cmake")
export(PACKAGE carlparser)

export_target(DEP_TARGETS antlr4shared)

set(INCLUDE_DIR include/)

include(CMakePackageConfigHelpers)

set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/src")
configure_package_config_file(
        cmake/carlparserConfig.cmake.in
        ${PROJECT_BINARY_DIR}/carlparserConfig.cmake
        INSTALL_DESTINATION ${PROJECT_BINARY_DIR}
        PATH_VARS INCLUDE_DIR
)

