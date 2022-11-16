#!/bin/bash

make && clear
BIN=sed
STR="pineapple strawberry watermelon watermelon fruit juice lemon"
echo $STR > test

echo -e "\e[1;32mOriginal text: $STR\e[0m\n"
echo -e "\e[1;32mFT is the student made sed version\e[0m"
echo -e "\e[1;32mOG is the original sed version\e[0m\n"

echo -e "\e[1;32mTest 1: "a" => "b"\e[0m"
echo -n "FT: "
./$BIN test "a" "b" && cat test.replace
echo -n "OG: "
sed 's/a/b/g' test

echo

echo -e "\e[1;32mTest 2: "pineapple" => "pear"\e[0m"
echo -n "FT: "
./$BIN test "pineapple" "pear" && cat test.replace
echo -n "OG: "
sed 's/pineapple/pear/g' test

echo

echo -e "\e[1;32mTest 3: "strawberry" => "orange"\e[0m"
echo -n "FT: "
./$BIN test "strawberry" "orange" && cat test.replace
echo -n "OG: "
sed 's/strawberry/orange/g' test

echo

echo -e "\e[1;32mTest 4: "fruit" => "car"\e[0m"
echo -n "FT: "
./$BIN test "fruit" "car" && cat test.replace
echo -n "OG: "
sed 's/fruit/car/g' test

echo

echo -e "\e[1;32mTest 5: "r" => "l"\e[0m"
echo -n "FT: "
./$BIN test "r" "l" && cat test.replace
echo -n "OG: "
sed 's/r/l/g' test

echo

echo -e "\e[1;32mTest 6: "watermelon" => "watermelonTomato"\e[0m"
echo -n "FT: "
./$BIN test "watermelon" "watermelonTomato" && cat test.replace
echo -n "OG: "
sed 's/watermelon/watermelonTomato/g' test

echo

echo -e "\e[1;32mTest 7: "empty string" => "empty string"\e[0m"
echo -n "FT: "
./$BIN test "" "" && cat test.replace
echo -n "OG: "
sed 's/""/""/g' test

echo

echo -e "\e[1;31mTest 8: nonexistent file\e[0m"
echo -n "FT: "
./$BIN nonexistent_file "fruit" "fruit"
echo -n "OG: "
sed 's/"fruit"/"fruit"/g' nonexistent_file

echo

echo -e "\e[1;31mTest 9: invalid reading permissions\e[0m"
install -m 000 /dev/null noread
echo -n "FT: "
./$BIN noread "fruit" "fruit"
echo -n "OG: "
sed 's/"fruit"/"fruit"/g' noread

echo

echo -e "\e[1;31mTest 10: invalid writing permissions\e[0m"
chmod 000 test.replace
./$BIN test "fruit" "fruit"
chmod 644 test.replace

echo

echo -e "\e[1;31mTest 11: two arguments\e[0m"
./$BIN test "fruit"

echo

echo -e "\e[1;31mTest 12: four arguments\e[0m"
./$BIN test "fruit" "fruit" "fruit"

echo

rm -rf test test.replace noread
