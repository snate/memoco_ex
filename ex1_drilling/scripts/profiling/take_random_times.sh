#!/bin/bash
holes=$1
size=$2
divisions=$3
bash scripts/generation/generateRandomData_ru.sh $holes $size
bash scripts/generation/generateRandomData_rg.sh $holes $size $divisions
bash scripts/generation/generateRandomData_rg_Manh.sh $holes $size $divisions
for (( i = 0; i < 7; i++ )); do
	echo "Run $i for Random Uniform"
	bash scripts/run/run_ru.sh
	echo "Run $i for Random Grid Uniform"
	bash scripts/run/run_rg.sh
	echo "Run $i for Random Grid Uniform with Manhattan distance"
	bash scripts/run/run_rg_Manh.sh
done
