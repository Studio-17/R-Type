cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type-Server VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
)

# specify the test sources
file(GLOB TEST_FILES
    Tests/
)

# specify the headers
include_directories(
    Source/
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(r-type_server ${SOURCE_FILES})

#Include the Doxygen documentation
option(DOXYGEN "Generate Doxyegn documentation" OFF) #OFF by default
if(DOXYGEN)
    include(cmake-modules/Doxygen.cmake)
else()
    # Do nothing
endif(DOXYGEN)
unset(DOXYGEN CACHE) # Unset the cache variable
