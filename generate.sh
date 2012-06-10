#!/bin/bash

# Replace boilerplate (bar) names with appropriate class name variation.
# Conventions:
# CamelClassName for the struct
# lower_class_name in functions, inclusion guards
# UPPER_CLASS_NAME in macros
# class_filename in file names
generate() {
    sed -i.bak "s/header/$class_filename/g" $1
    sed -i.bak "s/bar/$lower_class_name/g" $1
    sed -i.bak "s/BAR/$UPPER_CLASS_NAME/g" $1
    sed -i.bak "s/Bar/$CamelClassName/g" $1
    rm $1.bak
}

# Ask for the class name in camel case, and export all class name variations for generate()
get_class_name() {
    echo -n "Enter the class name in CamelCase (e.g., ClassName): "
    read CamelClassName

    export CamelClassName
    export lower_class_name=`echo $CamelClassName | sed -e 's/\(.\)\([A-Z][a-z]\)/\1_\2/g' | tr [:upper:] [:lower:]`
    export UPPER_CLASS_NAME=`echo $lower_class_name | tr [:lower:] [:upper:]`
	export class_filename=`echo $lower_class_name | tr _ -`
}

# Exit if "generating" a file that already exists
exit_if_file_exists() {
    [ -e $1 ] && echo "Oops, I cannot continue! File $1 already exists." && exit
}

get_class_name

boilerplate=( ".boilerplate.c" ".boilerplate.h" ".boilerplate-demo.c" ".boilerplate-test.c" )
replacement=( "src/$class_filename.c" "include/CompilerKit/$class_filename.h" "examples/$class_filename-demo.c" "test/$class_filename-test.c" )

for i in 0 1 2 3
do
    # By default, generate the specified class
    if [ $# = 0 ]; then
        exit_if_file_exists ${replacement[$i]}
        cp ${boilerplate[$i]} ${replacement[$i]}
        generate ${replacement[$i]}
    # If the user specified rm, clean up generated class
    elif [ $1 == "rm" ]; then
        [ -e ${replacement[$i]} ] && rm ${replacement[$i]}
    fi
done

if [ $# = 0 ]; then
    echo
    echo "To properly implement $CamelClassName,"
    echo "1. Address all @todo items in:"
    echo
    echo "${replacement[@]}" | tr ' ' '\n'
    echo
    echo "2. If desired, add this to include/CompilerKit.h:"
    echo
    echo "#include \"CompilerKit/$class_filename.h\""
    echo
    echo "3. Update CMakeLists.txt"
    echo "4. Test, Document, Code, Build, Debug, Commit, Push, Rinse, Repeat."
    echo "   Happy Hacking!"
fi
