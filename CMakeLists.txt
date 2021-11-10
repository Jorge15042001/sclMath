set(CMAKE_EXPORT_COMPILE_COMMANDS ON)# get compile_commands.json
find_package(Catch2 3 REQUIRED) # require for testing the code

project(sclMath)

SET(CMAKE_INSTALL_PREFIX /usr)

# compile the library
FILE(GLOB sclMath_src src/*)
add_library(sclMath SHARED
  ${sclMath_src})

#include list dir
target_include_directories(sclMath PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/sclMathConfigVersion.cmake"
    VERSION 0.1
    COMPATIBILITY AnyNewerVersion
)


#installing the library in the system
install(TARGETS sclMath
    EXPORT sclMathTargets
    LIBRARY DESTINATION lib COMPONENT Runtime
    ARCHIVE DESTINATION lib COMPONENT Development
    RUNTIME DESTINATION bin COMPONENT Runtime
    PUBLIC_HEADER DESTINATION include COMPONENT Development
    BUNDLE DESTINATION bin COMPONENT Runtime
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/sclMathConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/sclMathConfig.cmake"
    INSTALL_DESTINATION lib/cmake/sclMath
)

install(EXPORT sclMathTargets DESTINATION lib/cmake/sclMath)
install(FILES "${PROJECT_BINARY_DIR}/sclMathConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/sclMathConfig.cmake"
        DESTINATION lib/cmake/sclMath)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)


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
