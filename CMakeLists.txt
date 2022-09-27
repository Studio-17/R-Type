cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION 0.1.0)

find_package(OpenGL REQUIRED)

add_subdirectory(raylib)

find_package(raylib 4.0.0 QUIET)

add_subdirectory(boost)

find_package(Boost 1.80.0 QUIET)

add_subdirectory(Client)
# add_subdirectory(Server)
