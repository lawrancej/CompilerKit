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

gboolean compilerkit_character_is_alpha_numeric (gunichar character)
{
    return ('0' <= character && character <= '9') ||
           ('A' <= character && character <= 'Z') ||
           ('a' <= character && character <= 'z');
}

/* Ensure lo is indeed lower than hi */
static void sort_chars (gunichar *lo, gunichar *hi)
{
    gunichar temp;

    if (*lo > *hi)
    {
        temp = *lo;
        *lo = *hi;
        *hi = temp;
    }
}

/**
 * compilerkit_alpha_numeric_character_class_new:
 * @fn compilerkit_alpha_numeric_character_class_new
 *
 * Constructs an alphanumeric character class object (internally the equivalent CompilerKitAlternation).
 * 
 * For example, `compilerkit_character_class_new('0','z')` produces the regex `[0-9A-Za-z]`.
 * Note that only alphanumeric characters will be included in the character class, and nothing else.
 *
 * @pre None.
 * @param gunichar `lo` The low end of the character class. If this is `'\0'`, `lo` is the next higher character.
 * @param gunichar `hi` The high end of the character class. If this is `'\0'`, return the empty string.
 * @return GObject* a pointer to the new character class regex, or NULL if `lo` or `hi` are non-alphanumeric.
 */
GObject* compilerkit_alpha_numeric_character_class_new(gunichar lo, gunichar hi)
{
    GObject *result;
    if (!compilerkit_character_is_alpha_numeric(lo)) return NULL;
    if (!compilerkit_character_is_alpha_numeric(hi)) return NULL;
    
    sort_chars (&lo, &hi);

    result = compilerkit_empty_set_get_instance ();
    if (lo <= '9' && hi >= 'A')
    {
        result = compilerkit_character_class_new (lo, '9');
        lo = 'A';
    }
    if ('A' <= lo && lo <= 'Z' && hi >= 'a')
    {
        result = compilerkit_alternation_new (result, compilerkit_character_class_new (lo, 'Z'));
        lo = 'a';
    }
    if ('a' <= lo)
    {
        result = compilerkit_alternation_new (result, compilerkit_character_class_new (lo, hi));
    }
    return result;
}

/**
 * compilerkit_character_class_new:
 * @fn compilerkit_character_class_new
 *
 * Constructs a character class object (internally the equivalent CompilerKitAlternation).
 * compilerkit_character_class_new(compilerkit_symbol_new('a'), compilerkit_symbol_new('b'))
 * 
 * For example, `compilerkit_character_class_new('a','z')` produces the regex `[a-z]`.
 * `compilerkit_character_class_new('!','~')` produces the a regex to match all characters between ASCII '!' and '~' (this happens to include all Latin printable characters).
 * 
 * @pre None.
 * @param gunichar `lo` The low end of the character class. If this is `'\0'`, `lo` is the next higher character.
 * @param gunichar `hi` The high end of the character class. If this is `'\0'`, return the empty string.
 * @return GObject* a pointer to the new character class regex.
 */
GObject* compilerkit_character_class_new(gunichar lo, gunichar hi)
{
	GObject* newExpression;
    gunichar i;

    sort_chars (&lo, &hi);

    /* If they're the same, return the symbol instead. */
    if (lo == hi)
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

/**
 * compilerkit_postive_closure_new:
 * @fn compilerkit_postive_closure_new
 *
 * Constructs a positive closure (internally the equivalent CompilerKitConcatenation and CompilerKitKleeneStar).
 * 
 * For example, `compilerkit_positive_closure_new(compilerkit_concatenation_new(compilerkit_symbol_new('a'),compilerkit_symbol_new('b')))` produces the regex `(ab)+`.
 * 
 * @pre `regex` is not NULL.
 * @param GObject* `regex` The regex to match one or more times.
 * @return GObject* regex that matches the given regex one or more times.
 */
GObject *compilerkit_positive_closure_new (GObject *regex)
{
    g_assert (regex);
    return compilerkit_concatenation_new (regex, compilerkit_kleene_star_new (regex));
}