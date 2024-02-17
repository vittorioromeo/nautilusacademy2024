#!/bin/bash

mkdir -p build && \
cd build && \
for f in $(find .. | grep ".cpp\$"); do \
    echo "Compiling $f..."
    g++ -std=c++17 -Wall -Wextra -Wpedantic \
        $f \
        -lsfml-graphics -lsfml-window -lsfml-system \
        -o $f.exe
    echo "Done"
done
