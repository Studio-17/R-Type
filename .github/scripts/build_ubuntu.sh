#!/bin/bash

pwd
mkdir -p Builds
cd Builds
cmake ..
cmake --build .
