#!/bin/bash

# Builds the dependencies using vcpkg
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install

# Builds the application using cmake
cd ..
cmake -B Builds -S .  -DCMAKE_BUILD_TYPE=Debug -DSERVER=ON
cmake --build Builds --config Debug
