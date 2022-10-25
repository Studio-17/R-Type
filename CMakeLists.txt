cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set projet variables
set(VERSION 0.1.0)

find_package(OpenGL REQUIRED)

add_subdirectory(raylib)

find_package(raylib 4.0.0 QUIET)

#Generate the Doxygen documentation
option(DOXYGEN "Generate Doxygen documentation" OFF) #OFF by default
if(DOXYGEN)
    add_subdirectory(Documentation/Doxygen)
endif(DOXYGEN)
unset(DOXYGEN CACHE) # Unset the cache variable

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE asio/asio/include/)
target_link_libraries(asio INTERFACE -pthread)

option(UNIT_TESTS "Build test with Criterion" OFF) #OFF by default
if(UNIT_TESTS)
    message("-- Building unit tests with libcriterion")
    add_subdirectory(Tests)
endif()
unset(UNIT_TESTS CACHE)

# Get all project files
file(GLOB_RECURSE
    ALL_CXX_SOURCE_FILES
    Source/*.[ch]pp
    Libraries/*.[ch]pp
    Server/*.[ch]pp
)

# Adding clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    add_custom_target(
        clang-format
        COMMAND /usr/bin/clang-format
        -i
        -style=file
        ${ALL_CXX_SOURCE_FILES}
    )
    message("-- Formatted all .[ch]pp files using .clang-format instructions")
endif()

add_subdirectory(Libraries)
add_subdirectory(Client)
add_subdirectory(Server)
