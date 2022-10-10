cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type-Server VERSION ${VERSION})

# set executable name
set(EXECUTABLE_NAME r-type_server)

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Server/*.cpp
    Source/ThreadPool/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Server/
    Source/ThreadPool/
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} r-type_library_network)

target_link_libraries(${EXECUTABLE_NAME} raylib)

target_link_libraries(${EXECUTABLE_NAME} -lpthread)

target_link_libraries(${EXECUTABLE_NAME} asio)
