cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION 0.1.0)

find_package(OpenGL REQUIRED)

add_subdirectory(raylib)

find_package(raylib 4.0.0 QUIET)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_add_remote(
    NAME
    bincrafters
    URL
    https://api.bintray.com/conan/bincrafters/public-conan)
conan_cmake_run(
    REQUIRES
    ${CONAN_EXTRA_REQUIRES}
    boost/1.80.0
    OPTIONS
    ${CONAN_EXTRA_OPTIONS}
    BASIC_SETUP
    CMAKE_TARGETS
    BUILD
    missing)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

Set(Boost_INSTALL_DIR ${CONAN_BOOST_ROOT})
find_package(Boost 1.80.0 REQUIRED)

add_subdirectory(Libraries)
add_subdirectory(Client)
add_subdirectory(Server)
