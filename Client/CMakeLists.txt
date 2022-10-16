cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type-Client VERSION ${VERSION})

# set executable name
set(EXECUTABLE_NAME r-type_client)

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Client/*.cpp
    Source/Datas/Position/*.cpp
    Source/GraphicalLib/*.cpp
    Source/GraphicalLib/Music/*.cpp
    Source/GraphicalLib/Sound/*.cpp
    Source/GraphicalLib/Sprite/*.cpp
    Source/GraphicalLib/Text/*.cpp
    Source/GraphicalLib/Keyboard/*.cpp
    Source/System/*.cpp
    Source/System/ControlSystem/*.cpp
    Source/System/DrawSystem/*.cpp
    Source/System/EventSystem/*.cpp
    Source/System/MoveSystem/*.cpp
    Source/System/NetworkSystem/*.cpp
    Source/System/NewEntitySystem/*.cpp
    Source/System/PositionSystem/*.cpp
    Source/System/RectSystem/*cpp
    Source/System/HitboxSystem/*cpp
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
    Source/GraphicalLib/Text/
    Source/GraphicalLib/Keyboard/
    Source/System/
    Source/System/ControlSystem/
    Source/System/DrawSystem/
    Source/System/EventSystem/
    Source/System/MoveSystem/
    Source/System/NetworkSystem/
    Source/System/NewEntitySystem/
    Source/System/PositionSystem/
    Source/System/RectSystem/
    Source/System/HitboxSystem/
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} r-type_library_ecs)
target_link_libraries(${EXECUTABLE_NAME} r-type_library_network)
target_link_libraries(${EXECUTABLE_NAME} r-type_library_errors)

target_link_libraries(${EXECUTABLE_NAME} raylib)

target_link_libraries(${EXECUTABLE_NAME} -lpthread)

target_link_libraries(${EXECUTABLE_NAME} asio)
