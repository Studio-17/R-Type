cmake_minimum_required(VERSION 3.17)

# set the project name and version
project("R-Type" VERSION ${VERSION})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set project variables
set(VERSION 0.1.0)

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
    "${CMAKE_SOURCE_DIR}/vcpkg/installed/x86-windows/include/"
)

link_directories("${CMAKE_SOURCE_DIR}/vcpkg/installed/x86-windows/lib/")

find_package(asio CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE r-type_library_ecs)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE r-type_library_network)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE -lpthread)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE asio)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE nlohmann_json::nlohmann_json)
