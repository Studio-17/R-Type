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
    Source/System/*.cpp
    Source/System/DirectionSystem/*.cpp
    Source/System/MoveSystem/*.cpp
    Source/System/NewPlayerSystem/*.cpp
    Source/System/ReceiveSystem/*.cpp
    Source/System/ShootSystem/*.cpp
    Source/System/HitboxSystem/*.cpp
    Source/System/SpawnEnemySystem/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Component/
    Source/Constant/
    Source/Server/
    Source/System/
    Source/System/DirectionSystem/
    Source/System/MoveSystem/
    Source/System/NewPlayerSystem/
    Source/System/ReceiveSystem/
    Source/System/ShootSystem/
    Source/System/HitboxSystem/
    Source/System/SpawnEnemySystem/
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} r-type_library_ecs)
target_link_libraries(${EXECUTABLE_NAME} r-type_library_network)

target_link_libraries(${EXECUTABLE_NAME} -lpthread)

target_link_libraries(${EXECUTABLE_NAME} asio)
