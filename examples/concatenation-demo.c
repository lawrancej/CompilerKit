#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    GObject *concatenation;
    g_type_init();
    
    concatenation = compilerkit_concatenation_new(compilerkit_symbol_new('a'),compilerkit_symbol_new('b'));
    
    /** @todo Briefly show how to use the methods in CompilerKitConcatenation to accomplish the task. */

    g_object_unref (concatenation);
}
