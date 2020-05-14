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

target_link_libraries(${PROJECT_NAME} CONAN_PKG::catch2)
target_link_libraries(${PROJECT_NAME} common)

target_include_directories(${PROJECT_NAME} PRIVATE ../common) 
target_include_directories(${PROJECT_NAME} PRIVATE ../v02) 

add_test(
  NAME test_all
  COMMAND tests)

