#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *print;
    g_type_init();
    
    print = compilerkit_print_visitor ();
    /** @todo Briefly show how to use the print visitor. */

    g_object_unref (print);
}