#!/bin/bash
cd ex2_heur/conf;
for tuning in *.conf; do
  cd ..
  tuned="`basename "$tuning" .conf`"
  bash scripts/profiling/take_fixed_times.sh conf/$tuning
  cd output/
  for file in *.tmp; do
    mv "$file" "`basename "$file" .tmp`-$sett-$tuned.prf"
  done
  cd ..
  cd conf/;
done
