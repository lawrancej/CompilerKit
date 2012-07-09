#include <stdio.h>
#include "CompilerKit/grammar.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitGrammar* grammar;
    CompilerKitNonterminal *start;
    
    g_type_init();
    
    start = compilerkit_nonterminal_new("S");
    grammar = compilerkit_grammar_new(start, NULL);

    g_object_unref (grammar);
}