#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *nullable;
    g_type_init();
    
    nullable = compilerkit_nullable_visitor ();
    /** @todo Briefly show how to use the nullable visitor. */

    g_object_unref (nullable);
}