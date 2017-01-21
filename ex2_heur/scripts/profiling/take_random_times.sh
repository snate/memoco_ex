#!/bin/bash
(cd src_GA; make clean; make)
for (( i = 0; i < 7; i++ )); do
	bash scripts/run/run_ru.sh
	bash scripts/run/run_rg.sh
	bash scripts/run/run_rg_Manh.sh
done
