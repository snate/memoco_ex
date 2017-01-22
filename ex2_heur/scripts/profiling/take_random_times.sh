#!/bin/bash
tuning=$1
(cd src_GA; make clean; make)
for (( i = 0; i < 7; i++ )); do
	echo "Run $i for Random Uniform"
	bash scripts/run/run_ru.sh $tuning
	echo "Run $i for Random Grid Uniform"
	bash scripts/run/run_rg.sh $tuning
	echo "Run $i for Random Grid Uniform with Manhattan distance"
	bash scripts/run/run_rg_Manh.sh $tuning
done
