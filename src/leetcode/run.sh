#!/usr/bin/env sh

g++ CountAndSay.cpp

if [ ! $? -eq 0 ]
then
    echo '---Compile Error---'
    exit 1
fi
./a.out
