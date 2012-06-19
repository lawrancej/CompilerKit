#include <glib.h>
#include "CompilerKit/symbol.h"

/** Symbol unicode works, but there's got to be an easier way. */
int main (int argc, char ** argv)
{
    CompilerKitSymbol* symbol;
    g_type_init();
    
    symbol = COMPILERKIT_SYMBOL(compilerkit_symbol_new('a'));
    g_printf ("The symbol is: %c\n", compilerkit_symbol_get_symbol(symbol));
    g_object_unref (symbol);

    symbol = COMPILERKIT_SYMBOL(compilerkit_symbol_new(21488));
    gchar character[4];
    g_unichar_to_utf8 (compilerkit_symbol_get_symbol(symbol), character);
	g_printf ("Here's a Japanese symbol: %s\n", character);
    g_object_unref (symbol);
    return 0;
}
