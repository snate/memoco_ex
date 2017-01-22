#!/bin/bash
tuning=$1
(cd src_GA; make clean; make)
for (( i = 0; i < 1; i++ )); do
	bash scripts/run/run_ru.sh $tuning
	bash scripts/run/run_rg.sh $tuning
	bash scripts/run/run_rg_Manh.sh $tuning
done
