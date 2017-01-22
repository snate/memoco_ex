#!/bin/bash
for (( i = 0; i < 7; i++ )); do
	echo "Run $i for 345"
	bash scripts/run/run_345.sh
	echo "Run $i for tsp12"
	bash scripts/run/run_tsp12.sh
	echo "Run $i for tsp60"
	bash scripts/run/run_tsp60.sh
	echo "Run $i for gerber"
	bash scripts/run/run_gerber.sh
done
