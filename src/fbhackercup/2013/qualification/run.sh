#!/usr/bin/env sh

name=balanced_smileys
g++ $name.cpp

if [ ! $? -eq 0 ]
then
    echo '---Compile Error---'
    exit 1
fi
echo '---Compile Succeeded---'

./a.out < $name.in
