#include <stdio.h>
#include "CompilerKit/symbol.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitSymbol* symbol;
    g_type_init();
    
    symbol = compilerkit_symbol_new('a');
    
    /** @todo Briefly show how to use the methods in CompilerKitSymbol to accomplish the task. */

    g_object_unref (symbol);
}