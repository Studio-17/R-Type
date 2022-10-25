#!/usr/bin/bash

conan install . --install-folder cmake-build-release --build=missing -c tools.system.package_manager:mode=installs -c tools.system.package_manager:sudo=True
cmake -B Builds -DCMAKE_TOOLCHAIN_FILE=cmake-build-release/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build Builds
