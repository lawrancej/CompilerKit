# CMake build script for CompilerKit
# Building:
# > mkdir build && cd build
# > cmake ..
# > cmake --build .
#
# Or, use:
# > ./generate.sh build
# > ./generate.sh build -DBUILD_EXAMPLES=ON # Build all demos
# > ./generate.sh build -DBUILD_NONTERMINAL_DEMO=ON # Build only the nonterminal demo
#
# CMake Tutorial: http://www.cmake.org/cmake/help/cmake_tutorial.html
# CMake Example:  https://github.com/libgit2/libgit2/blob/development/CMakeLists.txt

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(libCompilerKit C)

# Define shortcuts for src, test_suite and example folders.
FILE (GLOB SRC src/*.c)
FILE (GLOB TEST_SUITE tests/*.c)
FILE (GLOB EXAMPLES examples/*.c)

# Build options
OPTION (BUILD_EXAMPLES "Build all examples" OFF)
OPTION (BUILD_DOCS "Build documentation" OFF)
OPTION (BUILD_TESTS "Build tests" ON)

# Build examples
FOREACH(FILE ${EXAMPLES})
    GET_FILENAME_COMPONENT(FNAME ${FILE} NAME_WE)
    STRING (TOUPPER ${FNAME} FNAME)
    STRING (REPLACE "-" "_" FNAME ${FNAME})
    OPTION (BUILD_${FNAME} "Build ${FNAME}" OFF)
ENDFOREACH(FILE)

# Generate documentation
IF (BUILD_DOCS)
    FIND_PACKAGE(Doxygen)
    IF (DOXYGEN_FOUND)
        ADD_CUSTOM_TARGET(doc ALL ${DOXYGEN_EXECUTABLE} "${PROJECT_SOURCE_DIR}/Doxyfile" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
    ENDIF (DOXYGEN_FOUND)
ENDIF()

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
ENDIF()

INCLUDE_DIRECTORIES(${GLIB2_INCLUDE_DIRS} ${GOBJECT_PKG_INCLUDE_DIRS} src include)
LINK_LIBRARIES(${GLIB2_LIBRARIES} ${GOBJECT_PKG_LIBRARIES})
LINK_DIRECTORIES(${GLIB2_LIBRARY_DIRS} ${GOBJECT_PKG_LIBRARY_DIRS})

# Compile and link CompilerKit
ADD_LIBRARY(CompilerKit ${SRC})

# Test suite
IF (BUILD_TESTS)
    ENABLE_TESTING()
    ADD_EXECUTABLE(test-suite ${TEST_SUITE})
    IF (MSVC)
        TARGET_LINK_LIBRARIES(test-suite CompilerKit)
    ELSE ()
        TARGET_LINK_LIBRARIES(test-suite CompilerKit gcov)
    ENDIF()
    FILE (READ "tests/test.c" contents)
    FOREACH (LINE ${contents})
        IF (${LINE} MATCHES "g_test_add_func")
            STRING (REGEX REPLACE ".*\"/(.*)\".*" "\\1" TEST_NAME "${LINE}")
            ADD_TEST(${TEST_NAME} test-suite -k -v -p ${TEST_NAME})
        ENDIF()
    ENDFOREACH()
ENDIF()

# Build demo applications
# To build only a handful of demos, use -DBUILD_COMPONENT_NAME_HERE_DEMO=ON
# For example, -DBUILD_SCANNER_DEMO=ON to build only the scanner demo
FOREACH(FILE ${EXAMPLES})
    GET_FILENAME_COMPONENT(FNAME ${FILE} NAME_WE)
    STRING (TOUPPER ${FNAME} NEW_FNAME)
    STRING (REPLACE "-" "_" NEW_FNAME ${NEW_FNAME})
    IF (BUILD_${NEW_FNAME} OR BUILD_EXAMPLES)
        ADD_EXECUTABLE(${FNAME} ${FILE})
        TARGET_LINK_LIBRARIES(${FNAME} CompilerKit)
    ENDIF()
ENDFOREACH(FILE)
