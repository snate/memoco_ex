#!/bin/bash
arg1=$1
arg2=$2
bash scripts/build/build_ru.sh $arg1 $arg2
./main ru
