#!/bin/bash

SOURCE_FOLDER=$(pwd)

mkdir -p Builds

git submodule update --init raylib/ boost/
cd boost && git submodule update --init libs/asio/ libs/array/ libs/system/ tools/
cd ..

cmake -B $SOURCE_FOLDER/Builds
cmake --build $SOURCE_FOLDER/Builds

ls Builds/Client/bin Builds/Server/bin
