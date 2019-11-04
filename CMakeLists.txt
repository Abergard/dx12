cmake_minimum_required(VERSION 3.15.4)

project(dx2 CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(externals)

enable_testing()

add_subdirectory(src)
