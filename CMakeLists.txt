# CMake build script for CompilerKit
# Building:
# > mkdir build && cd build
# > cmake ..
# > cmake --build .
#
# CMake Tutorial: http://www.cmake.org/cmake/help/cmake_tutorial.html
# CMake Example:  https://github.com/libgit2/libgit2/blob/development/CMakeLists.txt

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(libCompilerKit C)

# Generate documentation
FIND_PACKAGE(Doxygen)
IF (DOXYGEN_FOUND)
ADD_CUSTOM_TARGET(doc ALL ${DOXYGEN_EXECUTABLE} "${PROJECT_SOURCE_DIR}/Doxyfile" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
ENDIF (DOXYGEN_FOUND)

# Use pkg-config to configure GLib and GObject includes, link libraries and link directories
FIND_PACKAGE (PkgConfig REQUIRED)
pkg_check_modules (GLIB2 glib-2.0>=2.26)
pkg_check_modules (GOBJECT_PKG gobject-2.0)

# Platform-specific flags
IF (MSVC)
    SET(CMAKE_C_FLAGS "/W4 /MP /nologo /Zi ${CMAKE_C_FLAGS}")
    SET(CMAKE_C_FLAGS_DEBUG "/Od /MP /DEBUG /Zi /MTd /RTC1 /RTCs /RTCu")
    SET(CMAKE_C_FLAGS_RELEASE "/MT /O2")
ELSE ()
    SET(CMAKE_C_FLAGS "-O2 -g -D_GNU_SOURCE -Wall -Wextra -Wno-missing-field-initializers -Wstrict-aliasing=2 -Wstrict-prototypes -Wmissing-prototypes -fprofile-arcs -ftest-coverage ${CMAKE_C_FLAGS}")
    SET(CMAKE_C_FLAGS_DEBUG "-O0 -g")
    SET(CMAKE_EXE_LINKER_FLAGS="-fprofile-arcs -ftest-coverage")
ENDIF ()

FILE (GLOB SRC src/*.c)
FILE (GLOB TEST_SUITE tests/*.c)
FILE (GLOB EXAMPLES examples/*.c)

INCLUDE_DIRECTORIES(${GLIB2_INCLUDE_DIRS} ${GOBJECT_PKG_INCLUDE_DIRS} src include)
LINK_LIBRARIES(${GLIB2_LIBRARIES} ${GOBJECT_PKG_LIBRARIES})
LINK_DIRECTORIES(${GLIB2_LIBRARY_DIRS} ${GOBJECT_PKG_LIBRARY_DIRS})

# Compile and link CompilerKit
ADD_LIBRARY(CompilerKit ${SRC})

# Test suite
ENABLE_TESTING()
FOREACH(FILE ${TEST_SUITE})
    GET_FILENAME_COMPONENT(FNAME ${FILE} NAME_WE)

    ADD_EXECUTABLE(${FNAME} ${FILE})
    IF (MSVC)
        TARGET_LINK_LIBRARIES(${FNAME} CompilerKit)
    ELSE ()
        TARGET_LINK_LIBRARIES(${FNAME} CompilerKit gcov)
    ENDIF()
    ADD_TEST(${FNAME} ${FNAME})
ENDFOREACH(FILE)

# Build demo applications
FOREACH(FILE ${EXAMPLES})
    GET_FILENAME_COMPONENT(FNAME ${FILE} NAME_WE)
    ADD_EXECUTABLE(${FNAME} ${FILE})
    TARGET_LINK_LIBRARIES(${FNAME} CompilerKit)
ENDFOREACH(FILE)
