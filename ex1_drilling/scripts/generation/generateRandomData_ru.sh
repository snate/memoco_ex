#!/bin/bash
count=$1
size=$2
(cd gen/;
g++ generator_ru.cpp;
./a.out $count $size
rm a.out)
