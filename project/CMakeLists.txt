cmake_minimum_required(VERSION 3.8)
project(YEngine CXX)

set(BINARY_DIR_TOP ${CMAKE_CURRENT_BINARY_DIR}/..)

enable_testing()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../src ${CMAKE_CURRENT_BINARY_DIR}/../src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../tests ${CMAKE_CURRENT_BINARY_DIR}/../tests)