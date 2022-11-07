#!/bin/bash

cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install

cd ..
cmake -B Builds -S .  -DCMAKE_BUILD_TYPE=Debug -DSERVER=ON
cmake --build Builds --config Debug

# TODO: build-package.sh -> setup the .deb package with sources
# TODO: github actions -> upgrade (no ideas at the moment)
