#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitComplement* complement;
    g_type_init();
    
    complement = compilerkit_complement_new(compilerkit_empty_set_get_instance());
    
    /** @todo Briefly show how to use the methods in CompilerKitComplement to accomplish the task. */

    g_object_unref (complement);
}
