#!/bin/bash
#clean
rm -f ex1_drilling/output/performance_*
rm -f ex2_heur/output/performance_*

cd ex1_drilling
bash scripts/profiling/take_fixed_times.sh

cd output/
for file in *.tmp; do
  mv "$file" "`basename "$file" .tmp`.prf"
done
cd ../
