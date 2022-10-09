cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(R-Type_Tests VERSION ${VERSION})

set(EXECUTABLE_NAME r-type_test)

enable_testing()

file(GLOB SOURCES
    ../Libraries/ECS/Source/Entity.hpp
)

include_directories(
    ../Libraries/ECS/Source/
)

file(GLOB TEST_SOURCES
    Test.cpp
)

add_executable(${EXECUTABLE_NAME} ${SOURCES} ${TEST_SOURCES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC criterion)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC asio)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC raylib)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC -lpthread)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC r-type_library_network)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC r-type_library_ecs)
