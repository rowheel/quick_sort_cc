#!/usr/bin/bash

echo "[*] Generating test data"
./gen_random_data.py

echo "[*] Compiling code"
clang++ -std=c++20 -o quick_sort -g quick_sort.cc

echo "[*] Executing program"
time (./quick_sort >result.txt)
wc -l result.txt
