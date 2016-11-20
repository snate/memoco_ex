#!/bin/bash
count=$1
(cd gen; bash ../scripts/generateRandomData.sh $count)
make clean
make
