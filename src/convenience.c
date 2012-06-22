#include "CompilerKit.h"
#include "CompilerKit/convenience.h"

GObject* compilerkit_character_class_new(gunichar hi, gunichar lo)
{
    GObject* newExpression = G_OBJECT(compilerkit_symbol_new(lo));
    int i;
    for(i = lo+1;i <= hi;i++)
    {
        if(i == 58)
            i = 65;
        else if(i == 91)
            i = 97;

        newExpression = G_OBJECT(compilerkit_alternation_new(newExpression,G_OBJECT(compilerkit_symbol_new((gunichar)i))));
    }
    return newExpression;
}