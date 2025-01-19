cmake_minimum_required(VERSION 3.21)

# Project name
project(AirHockey VERSION 1.0)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH %{CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_DIRECTORY %{CMAKE_BINARY_DIR}/dist)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/internal/CMakeModules")

include(CPM)
include(CCache)

set(CPM_INCLUDE_ALL_IN_PACKAGE_LOCK ON)
cpmusepackagelock(package-lock.cmake)

add_subdirectory(internal)
add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test)