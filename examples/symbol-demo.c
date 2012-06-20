#include <glib.h>
#include "CompilerKit/symbol.h"

/** Symbol unicode works (on Linux), but there's got to be an easier way. */
int main (int argc, char ** argv)
{
    CompilerKitSymbol* symbol;
    char *charset;
    gchar character[4];
//    int bytes_read, bytes_written;
//    GError *err;

    g_type_init();
    
    symbol = COMPILERKIT_SYMBOL(compilerkit_symbol_new('a'));
    g_printf ("The symbol is: %c\n", compilerkit_symbol_get_symbol(symbol));
    g_object_unref (symbol);

    g_get_charset(&charset);
    g_printf ("%s\n", charset);
    
    symbol = COMPILERKIT_SYMBOL(compilerkit_symbol_new(21488));
    
    g_unichar_to_utf8 (compilerkit_symbol_get_symbol(symbol), character);
    // I think to get this working on Windows, you'd need to convert to the UTF8 string into the locale using g_locale_from_utf8

	g_printf ("Here's a Japanese symbol: %s\n", character);
    g_object_unref (symbol);
    
//    g_printf ("%s", err->message);
    return 0;
}
