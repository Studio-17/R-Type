cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION 0.1.0)

add_subdirectory(raylib)
add_subdirectory(boost)

add_subdirectory(Client)
add_subdirectory(Server)
