#!/bin/bash
count=$1
div=$2
(cd gen; bash ../scripts/generateRandomData_rg.sh $count $div)
cp -rf instances/rg_data.dat instances/data.dat
make clean
make
