cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS TARGETS)

enable_testing()

add_subdirectory(common)
add_subdirectory(tests)
add_subdirectory(v03)
add_subdirectory(v04)

