#!/usr/bin/env sh

g++ InterleavingString.cpp

if [ ! $? -eq 0 ]
then
    echo '---Compile Error---'
    exit 1
fi
./a.out
