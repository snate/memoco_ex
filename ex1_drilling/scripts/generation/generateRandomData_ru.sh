#!/bin/bash
count=$1
size=$2
(g++ generator_ru.cpp;
./a.out $count $size
rm a.out)
