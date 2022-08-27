#!/bin/bash

g++ src/$1.cpp -o x.$1 -I ./inc -g -fsanitize=address 

time ./x.$1

rm ./x.$1
