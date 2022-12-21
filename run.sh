#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error: Incorrect number of arguments. Usage: $0 (c|c++)"
    exit 1
fi

if [ $1 = "c" ]; then
    gcc main.c
elif [ $1 = "c++" ]; then
    g++ main.cpp
else
    echo "Error: Invalid argument. Only 'c' or 'c++' are allowed."
    exit 1
fi

./a.out < example_in.txt > out.txt
diff out.txt example_out.txt

if [ $? -eq 0 ]; then
    echo "Congratulations! All Correct!"
else
    echo "Differences exist, please check and debug."
fi