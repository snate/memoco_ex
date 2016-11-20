#!/bin/bash
count=$1
(cd ../gen; g++ generator.cpp;
./a.out  $count
rm a.out)
