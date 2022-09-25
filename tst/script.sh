#!/bin/bash

# Compilation process
if [ ! -d build ]; then
    mkdir build
fi
cd build/
cmake ../
make
cd ../


# Excution process
time ./build/tests
rm ./build/tests
