#!/bin/bash

SOURCE_FOLDER=$(pwd)

mkdir -p Builds

git submodule update --init --recursive

cmake -B $SOURCE_FOLDER/Builds
cmake --build $SOURCE_FOLDER/Builds

ls Builds/Client/bin Builds/Server/bin
