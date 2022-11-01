cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type_Library_Network VERSION ${VERSION})

# set executable name
set(LIBRARY_NAME r-type_library_network)

# set compilation flags
if(UNIX)
    add_compile_options("-Wall" "-Wextra" "-Werror" "-Wuninitialized" "-Winit-self")
endif()

# specify the headers
file(GLOB LIB_HEADER
    ./**
    Packets/*.hpp
    Packets/Structures/*.hpp
    Protocol/*.hpp
    Serialization/*.hpp
    UdpCommunication/*.hpp
)

file(GLOB LIB_DIRECTORY
    .
    Packets
    Packets/Structures
    Protocol
    Serialization
    UdpSocket
    UdpCommunication
)

# Add executable target with source files listed in SOURCE_FILES variable
add_library(${LIBRARY_NAME} INTERFACE ${LIB_HEADER})
target_include_directories(${LIBRARY_NAME} INTERFACE ${LIB_DIRECTORY})
