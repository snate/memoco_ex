#!/bin/bash
count=$1
g++ generator.cpp
./a.out  $count
rm a.out
