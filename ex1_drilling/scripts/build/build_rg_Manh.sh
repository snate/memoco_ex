#!/bin/bash
count=$1
size=$2
div=$3
(cd gen; bash ../scripts/generation/generateRandomData_rg_Manh.sh $count $size $div)
cp -rf instances/rg_data.dat instances/data.dat
make clean
make
