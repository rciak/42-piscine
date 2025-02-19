#!/bin/bash

cc -Wall -Wextra -Werror -g ./calc_boundary.c ./calc_boundary_helpers.c ./find_solution.c ./initialise.c ./is_matching.c ./print_solution.c ./rush01.h ./main.c

echo "------T1(Correct)-----"
./a.out "1 3 2 3 3 1 3 2 1 2 3 2 3 2 1 2" | cat -e
echo

echo "------T2(Correct)-----"
./a.out "1 2 3 3 2 3 2 1 1 2 3 2 3 3 2 1" | cat -e
echo

echo "------T3(Correct)-----"
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
echo

echo "------T4(Correct)-----"
./a.out "3 2 2 1 2 1 3 3 3 2 1 2 1 2 3 2" | cat -e
echo

echo "------T5--------"
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2" | cat -e
echo

echo "------T6--------"
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 3" | cat -e
echo

echo "------T7--------"
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 5" | cat -e
echo

echo "------T8--------"
./a.out "a 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
echo

echo "------T9--------"
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 " | cat -e
echo

echo "------T10--------"
./a.out "" | cat -e
echo
