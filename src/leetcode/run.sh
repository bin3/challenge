#!/usr/bin/env sh

g++ SearchInRotatedSortedArray2.cpp

if [ ! $? -eq 0 ]
then
    echo '---Compile Error---'
    exit 1
fi
echo '---Compile Succeeded---'

./a.out
