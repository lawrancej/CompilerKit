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

int compilerkit_character_is_alpha_numeric(gunichar character)
{
    return '0' <= character && character <= '9' ||
           'a' <= character && character <= 'z' ||
           'A' <= character && character <= 'Z';
}

GObject* compilerkit_alpha_numeric_character_class_new(gunichar lo, gunichar hi)
{
    if(!compilerkit_character_is_alpha_numeric(hi) || !compilerkit_character_is_alpha_numeric(lo))
		return NULL;
    if(i == 58)
        i = 65;
    else if(i == 91)
        i = 97;
}

/**
 * compilerkit_character_class_new:
 * @fn compilerkit_character_class_new
 *
 * Constructs a character class object (internally the equivalent CompilerKitAlternation).
 * 
 * For example, `compilerkit_character_class_new('a','z')` produces the regex `[a-z]`.
 * @pre None.
 * @param gunichar `lo` The low end of the character class. If this is `'\0'`, `lo` is the next higher character.
 * @param gunichar `hi` The high end of the character class. If this is `'\0'`, return the empty string.
 * @return GObject* a pointer to the new character class.
 */
GObject* compilerkit_character_class_new(gunichar lo, gunichar hi)
{
	GObject* newExpression;
    gunichar i;
    gunichar temp;

    /* Ensure lo is indeed lower than hi */
    if (lo > hi)
    {
        temp = lo;
        lo = hi;
        hi = temp;
    }
    /* If they're the same, return the symbol instead. */
    else if (lo == hi)
    {
        return compilerkit_symbol_new (lo);
    }

    /* Don't match NULL in the regex */
    if (lo == '\0')
    {
        lo++;
    }
    /* This must mean lo and hi are both NULL. Return EmptyString instead. */
    else if (hi == '\0')
    {
        return compilerkit_empty_string_get_instance();
    }
    
    newExpression = compilerkit_symbol_new(lo);
    for(i = lo+1; i <= hi; i++)
    {
        newExpression = compilerkit_alternation_new (newExpression, compilerkit_symbol_new(i));
    }
    return newExpression;
}
