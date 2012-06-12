#include <stdio.h>
#include "CompilerKit/scanner.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitScanner* scanner;
    g_type_init();
    
    scanner = compilerkit_scanner_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitScanner to accomplish the task. */

    g_object_unref (scanner);
}