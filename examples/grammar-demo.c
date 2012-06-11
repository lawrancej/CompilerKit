#include <stdio.h>
#include "CompilerKit/grammar.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitGrammar* grammar;
    g_type_init();
    
    grammar = compilerkit_grammar_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitGrammar to accomplish the task. */

    g_object_unref (grammar);
}