#!/bin/bash

echo "Please enter the version you want to test:"
read n
gcc $n.c -o $n.out -lm
for file in *.txt
do
    echo "testing $n, testcase $file:"
    start=$(date +%s%N)
    ./$n.out < $file
    end=$(date +%s%N)
    time_ns=$((end - start))
    time_ms=$(echo "scale=3; $time_ns / 1000000" | bc)
    echo "execution time: $time_ns ns"
    echo "execution time: $time_ms ms"
    echo "---------------------------"
done
