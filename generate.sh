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
get_identifier() {
    echo -n "Enter the $choice name in CamelCase (e.g., ClassName): "
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

next_steps() {
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
    echo "4. Test, document, code, build, and debug as necessary."
    echo "5. Commit changes. To commit, git must be aware of the new files:"
    echo "   git add ${replacement[@]}"
    echo "6. Happy Hacking!"
}

usage() {
    echo "Usage: $0 cmd"
    echo 
    echo "Where cmd is:"
    echo "class      Generate a class"
    echo "interface  Generate an interface (WARNING: untested boilerplate interface)"
    echo "rm         Remove an existing class or interface"
}

# Main driver function
main() {
    if [ $# == 0 ]; then
        usage
    elif [[ $1 == "class" || $1 == "interface" ]]; then
        export choice="$1"
        get_identifier
        boilerplate=( ".boilerplate/$choice.c" ".boilerplate/$choice.h" ".boilerplate/demo.c" ".boilerplate/test.c" )
        replacement=( "src/$class_filename.c" "include/CompilerKit/$class_filename.h" "examples/$class_filename-demo.c" "tests/$class_filename-test.c" )
        for i in 0 1 2 3
        do
            exit_if_file_exists ${replacement[$i]}
            cp ${boilerplate[$i]} ${replacement[$i]}
            generate ${replacement[$i]}
        done
        next_steps
    elif [ $1 == "rm" ]; then
        get_identifier
        replacement=( "src/$class_filename.c" "include/CompilerKit/$class_filename.h" "examples/$class_filename-demo.c" "tests/$class_filename-test.c" )
        for filename in "${replacement[@]}"
        do
            [ -e $filename ] && echo rm $filename && rm $filename
        done
    else
        usage
    fi
}

main $*
