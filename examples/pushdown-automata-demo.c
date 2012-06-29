#include <stdio.h>
#include "CompilerKit/pushdown-automata.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitPushdownAutomata* pushdown_automata;
    g_type_init();
    
    pushdown_automata = compilerkit_pushdown_automata_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitPushdownAutomata to accomplish the task. */

    g_object_unref (pushdown_automata);
}