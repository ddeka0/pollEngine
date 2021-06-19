cmake_minimum_required (VERSION 3.15)
set(CMAKE_BUILD_TYPE Debug)

# set project name and C++ compiler version
project(pollEngine LANGUAGES C CXX)
message(STATUS "Compiling Project : ${PROJECT_NAME}")
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  MESSAGE("-- Using Clang")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  MESSAGE("-- Using GNU")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  MESSAGE("-- Using Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  MESSAGE("-- Using MSVC")
endif()

message(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(common bin_common)
add_subdirectory(core bin_core)
add_subdirectory(app bin_app)
add_subdirectory(adapter bin_adapter)
add_subdirectory(testApp bin_testApp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -g -fsanitize=address -fsanitize=leak -v")



