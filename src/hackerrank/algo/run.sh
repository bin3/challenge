#!/usr/bin/env sh

g++ equations.cpp

if [ ! $? -eq 0 ]
then
    echo '---Compile failed---'
    exit 1
fi
echo '---Compile succeeded---'
./a.out
