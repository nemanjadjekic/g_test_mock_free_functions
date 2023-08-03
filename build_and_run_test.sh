#!/bin/sh

# Generate cmake files and create build folder
cmake -S . -B build

# Build code
cmake --build build

# Run tests
./build/calculator_test
