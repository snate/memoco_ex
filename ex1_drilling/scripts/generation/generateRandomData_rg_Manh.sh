#!/bin/bash
count=$1
size=$2
div=$3
(g++ generator_rg_Manhattan.cpp;
./a.out $count $size $div
rm a.out)