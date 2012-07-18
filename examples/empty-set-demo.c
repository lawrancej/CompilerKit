#include <stdio.h>
#include "CompilerKit/empty-set.h"

/** This program shows how to get a reference to an EmptySet object */

int main (int argc, char ** argv)
{
    GObject* empty_set;
    g_type_init();
    
    empty_set = compilerkit_empty_set_get_instance();
    
    g_object_unref (empty_set);
}