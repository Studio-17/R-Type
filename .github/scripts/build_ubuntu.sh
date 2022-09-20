#!/bin/bash

pwd
mkdir -p Builds
cd Builds
cmake ..
cmake --build .
ls -lR Builds | grep "r-type_"
