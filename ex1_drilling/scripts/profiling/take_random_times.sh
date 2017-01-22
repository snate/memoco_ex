#!/bin/bash
holes=$1
size=$2
divisions=$3
(cd gen; bash ../scripts/generation/generateRandomData_ru.sh $holes $size)
(cd gen; bash ../scripts/generation/generateRandomData_rg.sh $holes $size $divisions)
(cd gen; bash ../scripts/generation/generateRandomData_rg_Manh.sh $holes $size $divisions)
for (( i = 0; i < 7; i++ )); do
	echo "Run $i for Random Uniform"
	bash scripts/run/run_ru.sh $holes $size
	echo "Run $i for Random Grid Uniform"
	bash scripts/run/run_rg.sh $holes $size $divisions
	echo "Run $i for Random Grid Uniform with Manhattan distance"
	bash scripts/run/run_rg_Manh.sh $holes $size $divisions
done
