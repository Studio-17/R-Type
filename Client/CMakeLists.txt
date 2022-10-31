cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION ${VERSION})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set project variables
set(VERSION 0.1.0)

# set executable name
set(EXECUTABLE_NAME r-type_client)

# set compilation flags
add_compile_options("-Wall" "-Wextra" "-Werror" "-Wuninitialized" "-Winit-self")

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Client/*.cpp
    Source/Datas/Position/*.cpp
    Source/GraphicalLib/*.cpp
    Source/GraphicalLib/Music/*.cpp
    Source/GraphicalLib/Sound/*.cpp
    Source/GraphicalLib/Sprite/*.cpp
    Source/GraphicalLib/MyTexture/*.cpp
    Source/GraphicalLib/Text/*.cpp
    Source/GraphicalLib/Keyboard/*.cpp
    Source/System/*.cpp
    Source/System/ControlSystem/*.cpp
    Source/System/DrawSystem/*.cpp
    Source/System/MoveSystem/*.cpp
    Source/System/NetworkSystem/*.cpp
    Source/System/NewEntitySystem/*.cpp
    Source/System/PositionSystem/*.cpp
    Source/System/RectSystem/*cpp
    Source/System/KillSystem/*cpp
    Source/AssetManager/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Client/
    Source/Component/
    Source/Constant/
    Source/Datas/Position/
    Source/GraphicalLib/
    Source/GraphicalLib/Music/
    Source/GraphicalLib/Sound/
    Source/GraphicalLib/Sprite/
    Source/GraphicalLib/MyTexture/
    Source/GraphicalLib/Text/
    Source/GraphicalLib/Keyboard/
    Source/System/
    Source/System/ControlSystem/
    Source/System/DrawSystem/
    Source/System/MoveSystem/
    Source/System/NetworkSystem/
    Source/System/NewEntitySystem/
    Source/System/PositionSystem/
    Source/System/RectSystem/
    Source/System/KillSystem/
    Source/AssetManager/
)

find_package(asio CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE r-type_library_ecs)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE r-type_library_network)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE r-type_library_errors)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE -lpthread)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE asio::asio)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE raylib)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE nlohmann_json::nlohmann_json)
