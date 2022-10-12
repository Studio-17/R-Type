cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type-Server VERSION ${VERSION})

# set executable name
set(EXECUTABLE_NAME r-type_server)

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Component/*.cpp
    Source/Server/*.cpp
    Source/Server/System/*.cpp
    Source/Server/System/HitSystem/*.cpp
    Source/Server/System/MoveSystem/*.cpp
    Source/Server/System/ShootSystem/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Component/
    Source/Server/
    Source/Server/System/
    Source/Server/System/HitSystem/
    Source/Server/System/MoveSystem/
    Source/Server/System/ShootSystem/
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} r-type_library_ecs)
target_link_libraries(${EXECUTABLE_NAME} r-type_library_network)

target_link_libraries(${EXECUTABLE_NAME} -lpthread)

target_link_libraries(${EXECUTABLE_NAME} asio)
