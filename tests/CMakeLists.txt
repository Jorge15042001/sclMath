find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)# get compile_commands.json

add_subdirectory (.. build)


FILE(GLOB TestSources tests_src/*.cpp)

add_executable(tests 
  ${TestSources})
  

target_link_libraries(tests 
  PRIVATE Catch2::Catch2WithMain
  sclMath)
