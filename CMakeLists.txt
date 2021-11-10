find_package(Catch2 3 REQUIRED) # require for testing the code

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)# get compile_commands.json

# compile the library
FILE(GLOB sclMath_src src/*)
add_library(sclMath SHARED
  ${sclMath_src})

#include list dir
target_include_directories(sclMath PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/src)


# compile the tests
FILE(GLOB TestSources tests/tests_src/*.cpp)

# create the executable to run test
add_executable(tests 
  ${TestSources})
  

# link the sclMath library to test exucutable
target_link_libraries(tests 
  PRIVATE Catch2::Catch2WithMain
  sclMath)



#TODO: how to run tests on library build
add_custom_command(TARGET tests POST_BUILD
  COMMAND ${CMAKE_CURRENT_LIST_DIR}/build/tests
  )
