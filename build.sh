#!/bin/bash

if [ $# = 0 ]; then
	echo "Build CompilerKit."
	echo ""
	echo "Usage:	$0 COMMAND [-v]"
	echo ""
	echo "Where COMMAND is one of the following:"
	echo "build		Builds CompilerKit."
	echo "rebuild		Removes the existing binaries and rebuilds CompilerKit."
	echo "clean		Removes the existing binaries."
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
	if [ $1 = "build" ] || [ $1 = "rebuild" ]; then
		echo "Building CompilerKit"
		cd build
		cmake .. 
		if [ "$2" = "-v" ]; then
			cmake --build .
		else
			cmake --build . | grep -iE "error|warning"
		fi
	fi
fi