#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitScanner* scanner;
    CompilerKitToken *token;
    g_type_init();
    
    scanner = compilerkit_scanner_new();
    
    // Specify lexical structure of the language.
    compilerkit_scanner_register(scanner, compilerkit_token_new("IDENTIFIER"), 
        compilerkit_positive_closure_new(compilerkit_character_class_new('A','Z')));
    
    // Attach it to a parser
    compilerkit_scanner_open_filename(scanner, "scanner-demo.c");
    while (token = compilerkit_scanner_next_token(scanner))
    {
        // do something with the token
    }
    compilerkit_scanner_close_file(scanner);

    g_object_unref (scanner);
}