#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *to_grammar;
    g_type_init();
    
    to_grammar = compilerkit_to_grammar_visitor ();
    /** @todo Briefly show how to use the to_grammar visitor. */

    g_object_unref (to_grammar);
}