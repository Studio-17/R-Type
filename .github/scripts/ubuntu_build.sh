#!/bin/bash

SOURCE_FOLDER=$(pwd)

mkdir -p Builds
<<<<<<< HEAD
conan install . --install-folder=$SOURCE_FOLDER/Builds
=======

git submodule update --init raylib/ boost/
cd boost && git submodule update --init libs/asio/ libs/array/ libs/system/ tools/
cd ..

>>>>>>> master
cmake -B $SOURCE_FOLDER/Builds
cmake --build $SOURCE_FOLDER/Builds

ls Builds/Client/bin Builds/Server/bin
