#!/bin/bash

if [ $# = 0 ]; then
    echo "Build CompilerKit."
    echo ""
    echo "Usage:    $0 COMMAND [-v]"
    echo ""
    echo "Where COMMAND is one of the following:"
    echo "build       Builds CompilerKit."
    echo "rebuild     Removes the existing binaries and rebuilds CompilerKit."
    echo "clean       Removes the existing binaries."
    echo "test        Builds and Tests CompilerKit."
    echo "coverage    Generate test coverage report."
    echo "total       Generate leader board by total line contributions."
    echo "lastweek    Generate leader board by commits within last week."
    echo "mergestats  Generate leader board by merges within last week."
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
    if [ $1 = "total" ]; then
        # Adapted from: http://stackoverflow.com/questions/4589731/git-blame-statistics

        git ls-tree -r HEAD|sed -E -e 's/^.{53}//'|while read filename; do file "$filename"; done|grep -E ': .*text'|sed -E -e 's/: .*//'|while read filename; do git blame -w "$filename"; done|sed -E -e 's/.*\((.*)[0-9]{4}-[0-9]{2}-[0-9]{2} .*/\1/' -e 's/ +$//'|sort|uniq -c|sort -nr
    fi
    if [ $1 = "lastweek" ]; then
        git shortlog --no-merges -s -n --since="(7days)"
    fi
    if [ $1 = "mergestats" ]; then
        git shortlog --merges -s -n --since="(7days)"
    fi
fi
