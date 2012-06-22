#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *string_builder;
    g_type_init();
    
    string_builder = compilerkit_string_builder_visitor ();
    /** @todo Briefly show how to use the string_builder visitor. */

    g_object_unref (string_builder);
}