#!/bin/bash
count=$1
size=$2
(cd gen; bash ../scripts/generateRandomData.sh $count $size)
cp -rf instances/ru_data.dat instances/data.dat
make clean
make
