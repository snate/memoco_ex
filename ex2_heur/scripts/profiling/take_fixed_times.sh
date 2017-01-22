#!/bin/bash
tuning=$1
(cd src_GA; make clean; make)
for (( i = 0; i < 7; i++ )); do
	bash scripts/run/run_345.sh $tuning
	bash scripts/run/run_tsp12.sh $tuning
	bash scripts/run/run_tsp60.sh $tuning
	bash scripts/run/run_gerber.sh $tuning
done
