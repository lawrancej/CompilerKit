#include <stdio.h>
#include "CompilerKit/empty-string.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitEmptyString* empty_string;
    g_type_init();
    
    empty_string = compilerkit_empty_string_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitEmptyString to accomplish the task. */

    g_object_unref (empty_string);
}