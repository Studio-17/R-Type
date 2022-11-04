#!/usr/bin/bash

cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install

cd ..
cmake -B Builds -G "Unix Makefiles" -S .  -DCMAKE_BUILD_TYPE=Debug -DSERVER=ON
cmake --build Builds --config Debug