#!/bin/bash

pwd
mkdir -p Builds
cd Builds
conan install .. --build=missing
cmake ..
cmake --build .
