cmake_minimum_required(VERSION 3.17)

# set the project name and version
project("R-Type" VERSION ${VERSION})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set project variables
set(VERSION 0.1.0)

# set executable name
set(EXECUTABLE_NAME r-type_client)

find_package(raylib 4.0.0 QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

# set compilation flags
if(UNIX)
    add_compile_options("-Wall" "-Wextra" "-Werror" "-Wuninitialized" "-Winit-self")
endif()

# specify the sources
file(GLOB SOURCE_FILES
    Source/*.cpp
    Source/Client/*.cpp
    Source/GraphicalLib/*.cpp
    Source/GraphicalLib/Position/*.cpp
    Source/GraphicalLib/Music/*.cpp
    Source/GraphicalLib/Sound/*.cpp
    Source/GraphicalLib/MyTexture/*.cpp
    Source/GraphicalLib/Keyboard/*.cpp
    Source/System/*.cpp
    Source/System/ControlSystem/*.cpp
    Source/System/DrawSpriteSystem/*.cpp
    Source/System/DrawTextSystem/*.cpp
    Source/System/GetInfoInLobbySystem/*.cpp
    Source/System/MoveSystem/*.cpp
    Source/System/NetworkSystem/*.cpp
    Source/System/NewEntitySystem/*.cpp
    Source/System/PositionSystem/*.cpp
    Source/System/RectSystem/*cpp
    Source/System/KillEntityTypeSystem/*cpp
    Source/System/KillSystem/*cpp
    Source/System/GetLobbiesSystem/*.cpp
    Source/System/SetNbPlayerInLobbySystem/*.cpp
    Source/System/NewClientResponseSystem/*.cpp
    Source/System/MouseSystem/*cpp
    Source/System/UpdateEntityInfosSystem/*.cpp
    Source/fileConfig/*.cpp
    Source/AssetManager/*.cpp
)

# specify the headers
include_directories(
    Source/
    Source/Client/
    Source/Component/
    Source/Constant/
    Source/GraphicalLib/
    Source/GraphicalLib/Position/
    Source/GraphicalLib/Music/
    Source/GraphicalLib/Sound/
    Source/GraphicalLib/MyTexture/
    Source/GraphicalLib/Keyboard/
    Source/System/
    Source/System/ControlSystem/
    Source/System/DrawSpriteSystem/
    Source/System/DrawTextSystem/
    Source/System/GetInfoInLobbySystem/
    Source/System/MoveSystem/
    Source/System/NetworkSystem/
    Source/System/NewEntitySystem/
    Source/System/PositionSystem/
    Source/System/RectSystem/
    Source/System/KillEntityTypeSystem/
    Source/System/KillSystem/
    Source/System/GetLobbiesSystem/
    Source/System/SetNbPlayerInLobbySystem/
    Source/System/NewClientResponseSystem/
    Source/System/MouseSystem/
    Source/System/UpdateEntityInfosSystem/
    Source/AssetManager/
    Source/fileConfig/
)

if(MSVC)
    include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/include/")
    link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/lib/")
endif()

if(UNIX)
    include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include/")
endif()

find_package(asio CONFIG REQUIRED)
#find_package(raylib CONFIG REQUIRED)
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
