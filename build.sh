#!/usr/bin/bash

git submodule update --init vcpkg

cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install asio
./vcpkg install nlohmann-json

cd ..
cmake -B Builds -G "Unix Makefiles" -S .  -DCMAKE_BUILD_TYPE=Debug
cmake --build Builds --config Debug