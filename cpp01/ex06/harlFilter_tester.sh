#!/bin/bash

make && clear
BIN=harlFilter

echo -e "\e[1;32mTest 1: DEBUG\e[0m"
./$BIN DEBUG
echo

echo -e "\e[1;32mTest 2: INFO\e[0m"
./$BIN INFO
echo

echo -e "\e[1;32mTest 3: WARNING\e[0m"
./$BIN WARNING
echo

echo -e "\e[1;32mTest 4: ERROR\e[0m"
./$BIN ERROR
echo

echo -e "\e[1;32mTest 5: Invalid argument\e[0m"
./$BIN "INVALID"
echo

echo -e "\e[1;31mTest 6: No argument\e[0m"
./$BIN
echo

echo -e "\e[1;31mTest 7: Two arguments\e[0m"
./$BIN "DEBUG" "INFO"
echo
