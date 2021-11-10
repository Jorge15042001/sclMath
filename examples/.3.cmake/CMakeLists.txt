cmake_minimum_required(VERSION 3.8)

find_package(sclMath REQUIRED)

set(CMAKE_CXX_STANDARD 17)

project(example3)# project name

add_executable(exe src/main.cpp) # executable file for example3

target_link_libraries(exe# executable name
  sclMath)# name o the library to be added
