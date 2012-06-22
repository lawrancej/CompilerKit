#include "CompilerKit.h"
#include "CompilerKit/convenience.h"

int compilerkit_character_is_alpha_numeric(gunichar character)
{
	if(character < 47 || character > 122 || (character > 57 && character < 65) || (character > 90 && character < 97))
		return 0;
	return 1;
}

GObject* compilerkit_character_class_new(gunichar hi, gunichar lo)
{
	if(!compilerkit_character_is_alpha_numeric(hi) || compilerkit_character_is_alpha_numeric(lo))
		return NULL;
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