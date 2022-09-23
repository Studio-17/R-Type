#!/bin/bash

SOURCE_FOLDER=$(pwd)

mkdir -p Builds
conan install . --install-folder=$SOURCE_FOLDER/Builds
cmake -B $SOURCE_FOLDER/Builds
cmake --build $SOURCE_FOLDER/Builds

ls Builds/Client/bin Builds/Server/bin
