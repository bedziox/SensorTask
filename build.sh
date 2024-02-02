#!/bin/bash

rm -rf build
mkdir build && cd build
cmake .. && cmake --build .
cd Debug
./Task.exe
cd ../..