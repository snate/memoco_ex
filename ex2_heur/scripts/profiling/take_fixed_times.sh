#!/bin/bash
tuning=$1
(cd src_GA; make clean; make)
for (( i = 0; i < 7; i++ )); do
	echo "Run $i for 345"
	bash scripts/run/run_345.sh $tuning
	echo "Run $i for tsp12"
	bash scripts/run/run_tsp12.sh $tuning
	echo "Run $i for tsp60"
	bash scripts/run/run_tsp60.sh $tuning
	echo "Run $i for gerber"
	bash scripts/run/run_gerber.sh $tuning
done
