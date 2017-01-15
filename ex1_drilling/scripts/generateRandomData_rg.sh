#!/bin/bash
count=$1
div=$2
(cd ../gen; g++ generator_rg.cpp;
./a.out $count $div
rm a.out)
