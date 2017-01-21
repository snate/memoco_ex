#!/bin/bash
count=$1
size=$2
cp -rf instances/ru_data.dat instances/data.dat
make clean
make
