/**
 * Copyright (C) 2012 The CompilerKit contributors.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
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
	GObject* newExpression;
    int i;
    
    if(!compilerkit_character_is_alpha_numeric(hi) || compilerkit_character_is_alpha_numeric(lo))
		return NULL;
    newExpression = G_OBJECT(compilerkit_symbol_new(lo));
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