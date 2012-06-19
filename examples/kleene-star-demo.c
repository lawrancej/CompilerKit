#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    GObject *kleene_star;
    g_type_init();
    
    kleene_star = compilerkit_kleene_star_new(compilerkit_symbol_new('a'));
    
    /** @todo Briefly show how to use the methods in CompilerKitKleeneStar to accomplish the task. */

    g_object_unref (kleene_star);
}
