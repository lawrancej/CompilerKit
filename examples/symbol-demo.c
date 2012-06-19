#include <stdio.h>
#include "CompilerKit/symbol.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    GObject* symbol;
    g_type_init();
    
//    symbol = compilerkit_symbol_new('a');
    symbol = compilerkit_symbol_new(21488);
	wprintf (L"Here's a Japanese character: %lc\n", compilerkit_symbol_get_symbol(symbol));
    
    /** @todo Briefly show how to use the methods in CompilerKitSymbol to accomplish the task. */

    g_object_unref (symbol);
}