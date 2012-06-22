#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *bar;
    g_type_init();
    
    bar = compilerkit_bar_visitor ();
    /** @todo Briefly show how to use the bar visitor. */

    g_object_unref (bar);
}