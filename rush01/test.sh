#!/bin/bash

gcc ./calc_boundary.c ./calc_boundary_helpers.c ./check_input.c ./find_solution.c ./initialise.c ./is_matching.c ./print_solution.c ./rush01.h ./new_main.c
./a.out $@
