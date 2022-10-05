cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type_Tests VERSION ${VERSION})

# setting up GTest environnement
enable_testing()
add_subdirectory(googletest)
include_directories(googletest/googletest/include googletest/googletest/src)

set(EXECUTABLE_NAME r-type_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
