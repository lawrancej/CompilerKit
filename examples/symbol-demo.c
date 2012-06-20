#include <windows.h>
#include <stdio.h>
#include <glib-object.h>
#include <glib/gunicode.h>
#include "CompilerKit/symbol.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitSymbol* symbol;
	
    g_type_init();
    
	SetConsoleOutputCP(65001);
    symbol = compilerkit_symbol_new('\u5fb0');
	printf ("This is a Japanese character: %c \n", compilerkit_symbol_get_symbol(symbol) );
    
    /** @todo Briefly show how to use the methods in CompilerKitSymbol to accomplish the task. */

    g_object_unref (symbol);
}