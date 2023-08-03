#!/bin/sh

echo "Remove old build folder"
rm -rf build

echo "Generate cmake files and create build folder"
cmake -S . -B build

echo "Build tests"
cmake --build build

echo "Run tests"
./build/calculator_test
