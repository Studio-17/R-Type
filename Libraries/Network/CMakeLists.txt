cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type_Library_Network VERSION ${VERSION})

# set executable name
set(LIBRARY_NAME r-type_library_network)

# specify the headers
file(GLOB LIB_HEADER
    ./**
    Packets/*.hpp
    Protocol/*.hpp
    Serialization/*.hpp
)

# Add executable target with source files listed in SOURCE_FILES variable
add_library(${LIBRARY_NAME} INTERFACE)
target_include_directories(${LIBRARY_NAME} INTERFACE ${LIB_HEADER})
