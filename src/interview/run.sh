#!/usr/bin/env sh

g++ amanzon-20130120-q1.cpp

if [ ! $? -eq 0 ]
then
    echo '---Compile Error---'
    exit 1
fi
echo '---Compile Succeeded---'

./a.out
