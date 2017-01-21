#!/bin/bash
holes=$1
size=$2
divisions=$3
bash take_fixed_times.sh
bash take_random_times.sh $holes $size $divisions
