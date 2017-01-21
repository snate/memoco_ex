#!/bin/bash
cd ex1_drilling
bash scripts/profiling/take_fixed_times.sh
cd ../
cd ex2_heur/
bash scripts/profiling/take_fixed_times.sh
cd ../              # current folder: ex2_heur/

rm -f ex1_drilling/output/performance_*
rm -f ex2_heur/output/performance_*
while IFS='' read -r line || [[ -n "$line" ]]; do
  # for each setting, run the program
  cd ex1_drilling;
  echo "Testing program with input: $line"
  bash scripts/profiling/take_random_times.sh $line
  cd output/
  for file in *.tmp; do
    mv "$file" "`basename "$file" .tmp`$line.prf"
  done
  cd ../

  cp -rf instances/* ../ex2_heur/instances/
  cd ../;
  cd ex2_heur;
  rm -f output/performance_*
  bash scripts/profiling/take_random_times.sh $line
  cd output/
  for file in *.tmp; do
    mv "$file" "`basename "$file" .tmp`$line.prf"
  done
  cd ../

  cd ../;
done < "conf/settings.conf"
