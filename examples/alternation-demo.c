#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    GObject *alternation;
    g_type_init();
    
    alternation = compilerkit_alternation_new(compilerkit_symbol_new('a'),compilerkit_symbol_new('b'));
    
    /** @todo Briefly show how to use the methods in CompilerKitAlternation to accomplish the task. */

    g_object_unref (alternation);
}
