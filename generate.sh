#!/bin/bash

pushd dependencies/lcov/bin > /dev/null
PATH=$PATH:$(pwd)
popd > /dev/null

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

# Cross platform file open
file_open() {
    if [ $OSTYPE == "msys" ] || [ $OSTYPE == "cygwin" ]; then
        start "$1"
    elif [ $OSTYPE == "linux-gnu" ]; then
        gnome-open "$1"
    elif [[ $OSTYPE == darwin* ]]; then
        open "$1"
    else
        echo "Unable to open file $1. What OS is this, anyway? $OSTYPE?"
    fi
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
    git add ${replacement[@]}
    echo
    echo "To properly implement $CamelClassName,"
    echo "1. Address all @todo items in:"
    echo
    echo "${replacement[@]}" | tr ' ' '\n'
    echo
    echo "2. Update include/CompilerKit.h as necessary."
    echo "3. Test, document, code, build, and debug as necessary."
    echo "4. Commit changes. Git is already aware of the new files."
    echo "5. Happy Hacking!"
}

usage() {
    echo "Build CompilerKit."
    echo ""
    echo "Usage:        $0 COMMAND [-v]"
    echo ""
    echo "Where COMMAND is one of the following:"
    echo ""
    echo "build         Builds CompilerKit library, binaries and documentation."
    echo "rebuild       Removes the existing binaries and rebuilds CompilerKit."
    echo "clean         Removes the existing binaries."
    echo "docs          Builds CompilerKit documentation only."
    echo "tests         Builds and Tests CompilerKit."
    echo "coverage      Generate test coverage report."
    echo ""
    echo "class         Generate a class"
    echo "visitor       Generate a visitor"
    echo "interface     Generate an interface (WARNING: untested boilerplate interface)"
    echo "rm            Remove an existing class or interface"
    echo ""
    echo "total         Generate leader board by total non-whitespace line contributions."
    echo "totalcommits  Generate leader board by total commits."
    echo "lastweek      Generate leader board by commits within last week."
    echo "mergestats    Generate leader board by merges within last week."
    echo ""
    echo "And -v builds verbosely."
    echo ""
    echo "Example: $0 rebuild -v"
}

# Main driver function
main() {
    if [ $# == 0 ]; then
        usage
        exit
    fi
	mkdir -p build
	if [ $1 = "clean" ] || [ $1 = "rebuild" ]; then
		echo "Clearing build folder."
		rm build/* -r
	fi
	if [ $1 = "build" ] || [ $1 = "rebuild" ] || [ $1 = "test" ] || [ $1 = "tests" ] || [ $1 = "tests/" ] || [ $1 = "coverage" ]; then
		echo "Building CompilerKit"
		cd build
		command="cmake ${@:2} .."
        eval "$command"
		if [ "$2" = "-v" ]; then
			cmake --build .
		else
			cmake --build . | grep -iE "error |warning |error:|warning:|======"
		fi
	fi
    if [ $1 = "docs" ] || [ $1 = "docs/" ]; then
        doxygen
        file_open docs/html/index.html
    fi
    if [ $1 = "coverage" ]; then
        lcov --directory . --zerocounters
    fi
    if [ $1 = "test" ] || [ $1 = "tests" ] || [ $1 = "tests/" ] || [ $1 = "coverage" ]; then
        if [ "$2" = "-v" ]; then
            ctest -V
        else
            ctest
        fi
    fi
    if [ $1 = "coverage" ]; then
        mkdir -p coverage
        lcov --directory . --capture --output-file app.info
        genhtml -o coverage app.info
        file_open coverage/index.html
    fi

    if [[ $1 == "class" || $1 == "interface" ]]; then
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
    elif [[ $1 == "visitor" ]]; then
        export choice="$1"
        get_identifier
        boilerplate=( ".boilerplate/visitor.c" ".boilerplate/visitor-test.c" ".boilerplate/visitor-demo.c" )
        replacement=( "src/$class_filename-visitor.c" "tests/$class_filename-visitor-test.c" "examples/$class_filename-visitor-demo.c" )
        for i in 0 1 2
        do
            exit_if_file_exists ${replacement[$i]}
            cp ${boilerplate[$i]} ${replacement[$i]}
            generate ${replacement[$i]}
        done
        next_steps
    elif [ $1 == "rm" ]; then
        get_identifier
        replacement=( "src/$class_filename-visitor.c" "tests/$class_filename-visitor-test.c" "examples/$class_filename-visitor-demo.c" "src/$class_filename.c" "include/CompilerKit/$class_filename.h" "examples/$class_filename-demo.c" "tests/$class_filename-test.c" )
        for filename in "${replacement[@]}"
        do
            if [ -e $filename ]; then
                rm $filename
                git rm $filename
            fi
        done
    elif [ $1 = "total" ]; then
        echo "Non-whitespace lines added and removed by author."
        echo ""
        SAVEIFS=$IFS
        IFS=$(echo -en "\n\b")
        authors=( $(git log --format="%aN" | sort -u ) )
        for author in "${authors[@]}"; do
            sum=0
            LINES=`git log --author="$author" --no-merges -C -C --numstat --pretty=format:""| cut -f1,2|tr '\t' '
'| tr -d '-' | sed '/^$/d'`
            for line in $LINES; do
                sum=$(($sum+$line))
            done
            echo -e "$sum\t$author"
        done | sort -nr
        IFS=$SAVEIFS
    elif [ $1 = "totalcommits" ]; then
        git shortlog --no-merges -s -n
    elif [ $1 = "lastweek" ]; then
        echo "Last week's commits."
        echo ""
        git shortlog --no-merges -s -n --since="(7days)"
    elif [ $1 = "mergestats" ]; then
        git shortlog --merges -s -n --since="(7days)"
    fi
}

main $*
