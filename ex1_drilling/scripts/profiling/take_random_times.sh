#!/bin/bash
holes=$1
size=$2
divisions=$3
(cd gen; bash ../scripts/generation/generateRandomData_ru.sh $holes $size)
(cd gen; bash ../scripts/generation/generateRandomData_rg.sh $holes $size $divisions)
(cd gen; bash ../scripts/generation/generateRandomData_rg_Manh.sh $holes $size $divisions)
for (( i = 0; i < 7; i++ )); do
	bash scripts/run/run_ru.sh $holes $size
	bash scripts/run/run_rg.sh $holes $size $divisions
	bash scripts/run/run_rg_Manh.sh $holes $size $divisions
done
