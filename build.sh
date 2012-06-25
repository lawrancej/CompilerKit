#!/bin/bash

if [ $# = 0 ]; then
	echo "Build CompilerKit."
	echo ""
	echo "Usage:	$0 COMMAND [-v]"
	echo ""
	echo "Where COMMAND is one of the following:"
	echo "build     Builds CompilerKit."
	echo "rebuild   Removes the existing binaries and rebuilds CompilerKit."
	echo "clean     Removes the existing binaries."
    echo "test      Builds and Tests CompilerKit."
    echo "coverage  Generate test coverage report."
	echo ""
	echo "And -v builds verbosely."
	echo ""
	echo "Example: $0 rebuild -v"
else
	mkdir -p build
	if [ $1 = "clean" ] || [ $1 = "rebuild" ]; then
		echo "Clearing build folder."
		rm build/* -r
	fi
	if [ $1 = "build" ] || [ $1 = "rebuild" ] || [ $1 = "test" ] || [ $1 = "coverage" ]; then
		echo "Building CompilerKit"
		cd build
		cmake .. 
		if [ "$2" = "-v" ]; then
			cmake --build .
		else
			cmake --build . | grep -iE "error|warning|======"
		fi
	fi
    if [ $1 = "coverage" ]; then
        lcov --directory . --zerocounters
    fi
    if [ $1 = "test" ] || [ $1 = "coverage" ]; then
        if [ "$2" = "-v" ]; then
            ctest -v
        else
            ctest
        fi
    fi
    if [ $1 = "coverage" ]; then
        lcov --directory . --capture --output-file app.info
        genhtml app.info
        echo "Open build/index.html for the test coverage report."
    fi
fi
