cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type VERSION ${VERSION})

set(EXECUTABLE_NAME r-type_test)

enable_testing()

include_directories(
    ../Libraries/ECS/Source/
    ../Libraries/Network/Serialization/
    ../Libraries/Network/UdpCommunication/
    ../Server/Source/Component/
)

file(GLOB TEST_SOURCES
    Source/TestComponent.cpp
    Source/TestNetwork.cpp
    Source/TestRegistry.cpp
    Source/TestSystem.cpp
)

add_executable(${EXECUTABLE_NAME} ${SOURCES} ${TEST_SOURCES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC criterion)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC asio)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC raylib)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC -lpthread)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC r-type_library_network)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC r-type_library_ecs)
