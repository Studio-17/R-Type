cmake_minimum_required(VERSION 3.17)

# set the project name and version
project("R-Type" VERSION ${VERSION})

# set executable name
set(EXECUTABLE_NAME r-type_server)

# set compilation flags
if(UNIX)
    add_compile_options("-Wall" "-Wextra" "-Werror" "-Wuninitialized" "-Winit-self")
endif()

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Component/*.cpp
    Source/Server/*.cpp
    Source/System/*.cpp
    Source/System/DirectionSystem/*.cpp
    Source/System/DisconnectionSystem/*.cpp
    Source/System/EndGameSystem/*.cpp
    Source/System/MoveSystem/*.cpp
    Source/System/ReceiveSystem/*.cpp
    Source/System/ShootSystem/*.cpp
    Source/System/HitboxSystem/*.cpp
    Source/System/SpawnEnemySystem/*.cpp
    Source/System/NewClientSystem/*.cpp
    Source/System/JoinLobbySystem/*.cpp
    Source/System/StartGameSystem/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Component/
    Source/Constant/
    Source/Server/
    Source/System/
    Source/System/DirectionSystem/
    Source/System/DisconnectionSystem/
    Source/System/EndGameSystem/
    Source/System/MoveSystem/
    Source/System/ReceiveSystem/
    Source/System/ShootSystem/
    Source/System/HitboxSystem/
    Source/System/SpawnEnemySystem/
    Source/System/NewClientSystem/
    Source/System/JoinLobbySystem/
    Source/System/StartGameSystem/
)

if(MSVC)
    include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/include/")
    link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/lib/")
endif()

if(UNIX)
    include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include/")
endif()

find_package(asio CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE r-type_library_ecs)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE r-type_library_network)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE -lpthread)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE asio::asio)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE nlohmann_json::nlohmann_json)
