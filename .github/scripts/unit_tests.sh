#!/bin/bash

if [ ! -d "Builds/" ]
then
  mkdir -p Builds
fi

cmake -B Builds -DUNIT_TESTS=ON
cmake --build Builds
./Builds/Tests/r-type_test
