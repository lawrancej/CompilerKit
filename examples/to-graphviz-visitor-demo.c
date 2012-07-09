#include <stdio.h>
#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor *to_graphviz;
    g_type_init();
    
    to_graphviz = compilerkit_to_graphviz_visitor ();
    /** @todo Briefly show how to use the to_graphviz visitor. */

    g_object_unref (to_graphviz);
}