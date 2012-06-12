#include <stdio.h>
#include "CompilerKit/concatenation.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitConcatenation* concatenation;
    g_type_init();
    
    concatenation = compilerkit_concatenation_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitConcatenation to accomplish the task. */

    g_object_unref (concatenation);
}