#!/bin/bash
while IFS='' read -r sett || [[ -n "$sett" ]]; do
  # for each setting, run the program
  cd ex1_drilling;
  echo "Testing program with input: $sett"
  bash scripts/profiling/take_random_times.sh $sett
  cd output/
  for file in *.tmp; do
    mv -f "$file" "`basename "$file" .tmp`$sett.prf"
  done
  cd ../

  cp -rf instances/* ../ex2_heur/instances/
  cd ../;
  cd ex2_heur/conf;
  for tuning in *.conf; do
    cd ..
    tuned="`basename "$tuning" .conf`"
    bash scripts/profiling/take_random_times.sh conf/$tuning
    pwd
    cd output/
    for file in *.tmp; do
      mv "$file" "`basename "$file" .tmp`-$sett-$tuned.prf"
    done
    cd ..
    cd conf/;
  done

  cd ../../;
done < "conf/settings.conf"
