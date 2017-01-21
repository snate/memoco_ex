#!/bin/bash
for (( i = 0; i < 7; i++ )); do
	bash scripts/run/run_345.sh
	bash scripts/run/run_tsp12.sh
	bash scripts/run/run_tsp60.sh
	bash scripts/run/run_gerber.sh
done
