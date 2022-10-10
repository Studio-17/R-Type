cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION ${VERSION})

add_subdirectory(ECS)
add_subdirectory(Errors)
add_subdirectory(Network)
