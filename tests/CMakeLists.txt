cmake_minimum_required(VERSION 3.8)

project(tests)

add_executable(${PROJECT_NAME}
  main.cpp
  test_01.cpp
  test_02.cpp
  test_03.cpp
  test_04.cpp
  test_template.h
  )

target_link_libraries(
  ${PROJECT_NAME}
  CONAN_PKG::catch2
  common
  v03
  v04
  )

target_include_directories(
  ${PROJECT_NAME} PRIVATE
  ../common
  ../v01
  ../v02
  ../v03
  ../v04
  ) 

add_test(
  NAME test_all
  COMMAND tests)

