
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)# get compile_commands.json

# compile the library
FILE(GLOB sclMath_src src/*)
add_library(sclMath SHARED
  ${sclMath_src})

#include list dir
target_include_directories(sclMath PUBLIC
  $(CMAKE_CURRENT_LIST_DIR)/src)


#TODO: how to run tests on library build
# add_custom_command(TARGET sclMath POST_BUILD
#   COMMAND mkdir -p build
#   COMMAND cd build
#   COMMAND cmake ..
#   COMMAND make
#   COMMAND ./build/tests
#   WORKING_DIRECTORY = ${CMAKE_CURRENT_LIST_DIR}/tests
#   )
