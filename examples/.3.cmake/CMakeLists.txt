cmake_minimum_required(VERSION 3.8)

project(example3)# project name

set(CMAKE_CXX_STANDARD 20)


find_package(sclMath REQUIRED)

add_executable(exe src/main.cpp) # executable file for example3

target_link_libraries(exe# executable name
  sclMath)# name o the library to be added
