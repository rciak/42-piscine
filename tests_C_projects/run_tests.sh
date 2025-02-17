#!/bin/bash

# Some parts of this scripts were created by Perplexity with the promts
#
#   Good evening. Do you have time and resources to help me building some testing script
#
#   Thanks for offering. I need the following information / building bricks: 
#   It should be a bash script named "run_tests.sh" contained in a folder tests_C_projects. 
#   When started from the command line with ./run_tests C01 the following should happen:
#    1. it should create anew a directory ../C01_with_tests 
#    2. It should copy all subdirectories of the form ex* of ../C01 to ../C01_with_tests
#    3. It should copy the files C01_ex*.c from the folder 
#       tests_C_projects to the corresponding folder ../C_01_with_tests/ex*
#    4. All c files in ../C01_with_tests/ex* should be compiled according to 
#       cc -Wall -Wextra -Werror *.c -o test_ex*
#
#   The first parts were ok; the latter one not so much. ;-)


# Check if the project name is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: ./run_tests.sh <project_name>"
    exit 1
fi

PROJECT_NAME=$1

# Create the new directory for tests
NEW_DIR="../${PROJECT_NAME}_with_tests"
mkdir -p "$NEW_DIR"

# Copy subdirectories of the form ex* from the original project directory
for dir in ../"$PROJECT_NAME"/ex*; do
    if [ -d "$dir" ]; then
        cp -r "$dir" "$NEW_DIR"
    fi
done

