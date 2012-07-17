#include <stdio.h>
#include "CompilerKit/empty-string.h"

/** This program shows how to get a reference to an EmptyString object */

int main (int argc, char ** argv)
{
    GObject* empty_string;
    g_type_init();
    
    empty_string = compilerkit_empty_string_get_instance();
    
    g_object_unref (empty_string);
}