cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type-Client VERSION 0.1.0)

# set executable name
set(EXECUTABLE_NAME r-type_client)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(TIDY "Run clang-tidy" OFF) #OFF by default
if (TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")
else()
    # Do nothing
endif()
unset(TIDY CACHE)

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Client/*.cpp
)

# specify the test sources
file(GLOB TEST_FILES
    Tests/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Client/
)

# Add executable target with source files listed in SOURCE_FILES variable
option(UNIT_TEST "Run unit tests" OFF) #OFF by default
if (UNIT_TEST)
    add_executable(unit_tests ${SOURCE_FILES} ${TEST_FILES})
    target_link_libraries(unit_tests criterion)
else()
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
    target_link_libraries(${EXECUTABLE_NAME} r-type_library_network)
    target_link_libraries(${EXECUTABLE_NAME} raylib)
    target_link_libraries(${EXECUTABLE_NAME} -lpthread)
    target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
endif(UNIT_TEST)
unset(UNIT_TEST CACHE) # Unset the cache variable

#Include the Doxygen documentation
option(DOXYGEN "Generate Doxyegn documentation" OFF) #OFF by default
if(DOXYGEN)
    include(cmake-modules/Doxygen.cmake)
else()
    # Do nothing
endif(DOXYGEN)
unset(DOXYGEN CACHE) # Unset the cache variable
