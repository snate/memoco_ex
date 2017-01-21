#!/bin/bash
count=$1
size=$2
div=$3
cp -rf instances/rg_data.dat instances/data.dat
make clean
make
