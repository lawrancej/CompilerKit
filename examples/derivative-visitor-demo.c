#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *derivative;
    g_type_init();
    
    derivative = compilerkit_derivative_visitor ();
    /** @todo Briefly show how to use the derivative visitor. */

    g_object_unref (derivative);
}