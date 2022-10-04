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
    add_subdirectory(Doxygen)
else()
    # Do nothing
endif(DOXYGEN)
unset(DOXYGEN CACHE) # Unset the cache variable

add_subdirectory(Libraries)
add_subdirectory(Client)
add_subdirectory(Server)
