cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type-Client VERSION ${VERSION})

# set executable name
set(EXECUTABLE_NAME r-type_client)

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Client/*.cpp
    Source/Network/*.cpp
    Source/System/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Client/
    Source/Component/
    Source/Network/
    Source/System/
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} r-type_library_ecs)
target_link_libraries(${EXECUTABLE_NAME} r-type_library_network)
target_link_libraries(${EXECUTABLE_NAME} r-type_library_errors)

target_link_libraries(${EXECUTABLE_NAME} raylib)

target_link_libraries(${EXECUTABLE_NAME} -lpthread)

target_link_libraries(${EXECUTABLE_NAME} asio)
