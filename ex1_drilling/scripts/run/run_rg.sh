#!/bin/bash
arg1=$1
arg2=$2
arg3=$3
bash scripts/build/build_rg.sh $arg1 $arg2 $arg3
./main rg
