#!/bin/bash
count=$1
size=$2
div=$3
(cd gen;
g++ generator_rg.cpp;
./a.out $count $size $div
rm a.out)
