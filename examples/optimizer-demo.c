#include <stdio.h>
#include "CompilerKit/optimizer.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitoptimizer* optimizer;
    g_type_init();
    
    optimizer = compilerkit_optimizer_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitoptimizer to accomplish the task. */

    g_object_unref (optimizer);
}