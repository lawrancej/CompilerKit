#include <stdio.h>
#include "CompilerKit/visitor.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitVisitor* visitor;
    g_type_init();
    
    visitor = compilerkit_visitor_new();
    
    /** @todo Briefly show how to use the methods in CompilerKitVisitor to accomplish the task. */

    g_object_unref (visitor);
}