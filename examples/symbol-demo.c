#include <glib.h>
#include "CompilerKit/symbol.h"

/** Symbol unicode works (on Linux), but there's got to be an easier way. */
int main (int argc, char ** argv)
{
    CompilerKitSymbol* symbol;
    gchar character[4];
    g_type_init();
    
    symbol = COMPILERKIT_SYMBOL(compilerkit_symbol_new('a'));
    g_printf ("The symbol is: %c\n", compilerkit_symbol_get_symbol(symbol));
    g_object_unref (symbol);

    symbol = COMPILERKIT_SYMBOL(compilerkit_symbol_new(21488));
    g_unichar_to_utf8 (compilerkit_symbol_get_symbol(symbol), character);
	g_printf ("Here's a Japanese symbol: %s\n", character);
    g_object_unref (symbol);
    return 0;
}
