cmake_minimum_required(VERSION 3.17)

# set the project name and version
project("R-Type" VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set project variables
set(VERSION 0.1.0)
set(CMAKE_DEBUG_FIND_MODE TRUE)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

# if(MSVC)
    # message("++ Microsoft Development environment detected")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x86-windows/share/asio/")
#    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x86-windows/share/raylib/")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x86-windows/share/nlohmann_json/")
# endif()

# if(UNIX)
    # message("++ Linux Development environment detected")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-linux/share/asio/")
#    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-linux/share/raylib/")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-linux/share/nlohmann_json/")
# endif()

#Generate the Doxygen documentation
option(DOXYGEN "Generate Doxygen documentation" OFF) #OFF by default
if(DOXYGEN)
    add_subdirectory(Documentation/Doxygen)
endif(DOXYGEN)
unset(DOXYGEN CACHE) # Unset the cache variable

option(UNIT_TESTS "Build test with Criterion" OFF) #OFF by default
if(UNIT_TESTS)
    message("++ Building unit tests with libcriterion")
    add_subdirectory(Tests)
endif()
unset(UNIT_TESTS CACHE)

# Get all project files
file(GLOB_RECURSE
    ALL_CXX_SOURCE_FILES
    Source/*.[ch]pp
    Libraries/*.[ch]pp
    Server/*.[ch]pp
)

# Adding clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    add_custom_target(
        clang-format
        COMMAND /usr/bin/clang-format
        -i
        -style=file
        ${ALL_CXX_SOURCE_FILES}
    )
    message("++ Formatted all .[ch]pp files using .clang-format instructions")
endif()

option(CLIENT "Generate R-Type Client" OFF)
option(SERVER "Generate R-Type Server" OFF)

add_subdirectory(Libraries)

if(CLIENT)
    add_subdirectory(Client)
elseif(SERVER)
    add_subdirectory(Server)
else()
     add_subdirectory(Client)
     add_subdirectory(Server)
endif()
