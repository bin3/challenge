#!/usr/bin/env sh

g++ ValidPalindrome.cpp

if [ ! $? -eq 0 ]
then
    echo '---Compile Error---'
    exit 1
fi
echo '---Compile Succeeded---'

./a.out
