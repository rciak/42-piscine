#!/bin/bash

# Some parts of this scripts were created by Perplexity with the promts and somewhat editied
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

# Create (anew) the new directory for tests
NEW_DIR="../${PROJECT_NAME}_with_tests"
echo -e "Creating directory\n  $NEW_DIR"
rm -fr "$NEW_DIR"
mkdir "$NEW_DIR"

# Copy subdirectories of the form ex* from the original project directory to NEW_DIR
echo
echo "Copying subfolders of  ../$PROJECT_NAME  to  $NEW_DIR"
for dir in ../"$PROJECT_NAME"/ex*; do
	echo "  $dir"
    cp -r "$dir" "$NEW_DIR"
done

##
## Own stuff, perplexity did not do what I had in mind. ;-)
##

#Add the test files (containing the testing  main  function) to where they belong
echo
echo "Copying test sourcefiles, containing  int main ...  :"
for dir in "$NEW_DIR"/ex*; do 
    ex_folder=$(basename "$dir")
    file="$PROJECT_NAME"_"$ex_folder".c
    echo "  $file  -->  $NEW_DIR"/"$ex_folder"
    cp     "$file"     "$NEW_DIR"/"$ex_folder"
done

#Add "COPY_" in front of all C_files in the "$NEW_DIR/ex*" folders
echo
echo "Reduce danger of editing accidentically the wrong files by renaming:"
for dir in "$NEW_DIR"/ex*; do
	for file in "$dir"/*.c; do
		file_bn=$(basename "$file")
		echo "  $file  ~~>  $dir/COPY_$file_bn"
		mv     "$file"     "$dir/COPY_$file_bn"
	done
	echo "  ----------------------"	
done

#Add also the file test.h to the just created copies of the testing C source files
echo
echo "Copying test.h and tools.c"
for dir in "$NEW_DIR"/ex*; do
    ex_folder=$(basename "$dir")
    file='test.h'
    file2='tools.c'
    echo "  $file   -->  $NEW_DIR"/"$ex_folder"
    cp "$file" "$NEW_DIR"/"$ex_folder"
    echo "  $file2  -->  $NEW_DIR"/"$ex_folder"
    cp "$file2" "$NEW_DIR"/"$ex_folder"

done

#Compile the tests and store compile command in  compile_command.sh
echo
echo "Compiling:"
for dir in "$NEW_DIR"/ex*; do
    ex_folder=$(basename "$dir")
    out_file=test_"$PROJECT_NAME"_"$ex_folder"
    compile_cmd_file='normal_recompile.sh'
    compile_with_g_flag_cmd_file='debug_recompile.sh'
    ####
    echo "#!/bin/bash"                                               > "$dir/$compile_cmd_file"
    chmod u+x "$dir/$compile_cmd_file"
    echo   "cc -Wall -Wextra -Werror -lbsd -o $out_file *.c"        >> "$dir/$compile_cmd_file"
    ####
    echo "#!/bin/bash"                                               > "$dir/$compile_with_g_flag_cmd_file"
    chmod u+x "$dir/$compile_with_g_flag_cmd_file"
    echo   "cc -Wall -Wextra -Werror -lbsd -g -o $out_file *.c"     >> "$dir/$compile_with_g_flag_cmd_file"
    ####
    echo "  cc -Wall -Wextra -Werror -lbsd -o $dir/$out_file $dir/*.c"
    cc -Wall -Wextra -Werror -lbsd -o "$dir/$out_file" "$dir"/*.c
done

#Open file viewer
echo 
echo "Please choose action by pressing a key:"
echo "  ENTER : Print command for cd'ing to prepared folder"
echo "  g     : Open in graphical file viewer"
echo "  n     : Do nothing"
read -n 1 -s answer
if [[ "$answer" == 'g' ]];
then
    echo
    echo "Happy testing. ;-)"
    sleep 1
    open "$NEW_DIR"
elif [[ "$answer" == 'n' ]];
then
    :
else
    echo
    echo "Happy testing. ;-)"
    echo
    echo "cd $NEW_DIR"
	cd "$NEW_DIR"
fi
