#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *to_nfa;
    g_type_init();
    
    to_nfa = compilerkit_to_nfa_visitor ();
    /** @todo Briefly show how to use the to_nfa visitor. */

    g_object_unref (to_nfa);
}