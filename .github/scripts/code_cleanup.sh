#!/bin/bash

for file in $(find Client Libraries Server -name "*[ch]pp" -print)
do
  clang-tidy $file --quiet --config-file="./.clang-tidy"
  clang-format -i $file --style="./.clang-tidy"
done
