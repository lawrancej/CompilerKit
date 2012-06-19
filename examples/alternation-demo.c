#include <stdio.h>
#include "CompilerKit/alternation.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitAlternation* alternation;
    g_type_init();
    
    alternation = compilerkit_alternation_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitAlternation to accomplish the task. */

    g_object_unref (alternation);
}