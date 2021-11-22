cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)# get compile_commands.json
find_package(Catch2 3 REQUIRED) # require for testing the code

project(sclMath
  DESCRIPTION "A header only c++ library that provides an easy interface and simpe interface to make simple linear algebra calculations"
  )

SET(CMAKE_CXX_FLAGS  "-w -Werror -Wpedantic -Wall -Wextra -Wconversion -Wsign-compare -Wsign-conversion ")
SET(CMAKE_CXX_STANDARD 20)

# wont work because in a header only definitios
SET(CMAKE_BUILD_TYPE DEBUG)
if (${CMAKE_BUILD_TYPE} STREQUAL "DEBUG")
  add_compile_definitions(SCLMATH_DEBUG_BUILD)
elseif (${CMAKE_BUILD_TYPE} STREQUAL "RELEASE")
  add_compile_definitions(SCLMATH_RELEASE_BUILD)
endif()

# compile the library
FILE(GLOB sclMathMatrix_src src/sclMatrix/*)
add_library(sclMath INTERFACE)


include (GNUInstallDirs)



#include list dir
target_include_directories(
  ${PROJECT_NAME}

  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

# write versioning of the files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake" 
    VERSION 0.1
    COMPATIBILITY AnyNewerVersion
)


#installing the library in the system
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}_Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(CMakePackageConfigHelpers)
configure_package_config_file( 
        "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)



install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)



install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/sclMath DESTINATION include)


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
  COMMAND cppcheck --project=${CMAKE_CURRENT_LIST_DIR}/compile_commands.json 
  COMMAND ${CMAKE_CURRENT_LIST_DIR}/build/tests
  )
