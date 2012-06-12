#include <stdio.h>
#include "CompilerKit/nonterminal.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitNonterminal* nonterminal;
    g_type_init();
    
    nonterminal = compilerkit_nonterminal_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitNonterminal to accomplish the task. */

    g_object_unref (nonterminal);
}