cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION 0.1.0)

include(cmake-modules/FindBoost.cmake)

add_subdirectory(Client)
add_subdirectory(Server)
