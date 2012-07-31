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
/**
 * compilerkit_optional_new:
 * @fn compilerkit_optional_new
 *
 * Return a regex corresponding to the original regex|empty string
 * 
 * @pre regex is not NULL
 * @param GObject* regex to make optional
 * @return GObject* Alternation of the regex with the empty string
 */
GObject *compilerkit_optional_new (GObject *regex)
{
    return compilerkit_alternation_new (regex, compilerkit_empty_string_get_instance());
}
/**
 * compilerkit_regex_lower:
 * @fn compilerkit_regex_lower
 *
 * Return a character class corresponding to `[a-z]`
 * 
 * @pre None
 * @param None
 * @return GObject* regex that matches the symbols a through z.
 */
GObject *compilerkit_regex_lower(void)
{
    return compilerkit_character_class_new('a', 'z');
}
/**
 * compilerkit_regex_upper:
 * @fn compilerkit_regex_upper
 *
 * Return a character class corresponding to `[A-Z]`
 * 
 * @pre None
 * @param None
 * @return GObject* regex that matches the symbols A through Z.
 */
GObject *compilerkit_regex_upper(void)
{
    return compilerkit_character_class_new('A', 'Z');
}
/**
 * compilerkit_regex_punct:
 * @fn compilerkit_regex_punct
 *
 * Return a character class corresponding to all punctuation.
 * 
 * @pre None
 * @param None
 * @return GObject* regex that matches all punctuation.
 */
GObject *compilerkit_regex_punct(void)
{
    return compilerkit_alternation_vlist_new(
        compilerkit_character_class_new('!', '/'),
        compilerkit_character_class_new('@',':'),
        compilerkit_character_class_new('[','`'),
        compilerkit_character_class_new('{','~'),
        NULL);
}
/**
 * compilerkit_regex_whitespace:
 * @fn compilerkit_regex_whitespace
 *
 * Return a character class corresponding to all whitespace.
 * 
 * @pre None
 * @param None
 * @return GObject* regex that matches all whitespace.
 */
GObject *compilerkit_regex_whitespace(void)
{
    return compilerkit_character_class_new(' ', ' ');;
}

/**
 * compilerkit_regex_digits:
 * @fn compilerkit_regex_digits
 *
 * Return a character class corresponding to `[0-9]`
 * 
 * @pre None
 * @param None
 * @return GObject* regex that matches the digits 0 through 9.
 */
GObject *compilerkit_regex_digits()
{
	return compilerkit_character_class_new('0', '9');
}

/**
 * compilerkit_parens:
 * @fn compilerkit_parens
 *
 * Match an object surrounded by parentheses.
 * 
 * @pre None
 * @param GObject* a regex to match.
 * @return GObject* that matches itself surrounded by parentheses
 */
GObject *compilerkit_parens(GObject *obj)
{
    return compilerkit_concatenation_vlist_new (
        compilerkit_symbol_new ('('),
        obj,
        compilerkit_symbol_new (')'),
        NULL
    );
}

/**
 * compilerkit_string_concatenation:
 * @fn compilerkit_string_concatenation
 *
 * Return a concatenation based off of a string.
 * 
 * @pre None
 * @param gchar* A UTF-8 encoded string.
 * @return GObject* regex that matches the string literally.
 */
GObject *compilerkit_string_concatenation(gchar *string)
{
    GObject *result;
    g_utf8_validate(string, -1, NULL);
    result = compilerkit_symbol_new (g_utf8_get_char (string));
    string = g_utf8_next_char(string);
    while (*string)
    {
        result = compilerkit_concatenation_new (result, compilerkit_symbol_new (g_utf8_get_char(string)));
        string = g_utf8_next_char(string);
    }

    return result;
}
/**
 * compilerkit_times_new:
 * @fn compilerkit_times_new
 *
 * Match regex `k` times.
 * 
 * @pre None
 * @param GObject* A regex.
 * @param guint The number of times it should match.
 * @return GObject* regex that matches the given regex `k` times.
 */
GObject *compilerkit_times_new(GObject *regex, guint k)
{
    GObject *result = regex;
    guint i;
    
    for (i = 1; i < k; i++)
        result = compilerkit_concatenation_new (result, regex);
    
    return result;
}
/**
 * compilerkit_times_extended_new:
 * @fn compilerkit_times_extended_new
 *
 * Match regex at least `k`, and at most `l` times.
 * 
 * @pre None
 * @param GObject* A regex.
 * @param guint The minimum number of times it should match.
 * @param guint The maximum number of times it should match.
 * @return GObject* regex that matches the given regex `k` times.
 */
GObject *compilerkit_times_extended_new(GObject *regex, guint k, guint l)
{
    GObject *result;
    
    result = compilerkit_times_new(regex, k);
    for (k++; k <= l; k++)
        result = compilerkit_concatenation_new (result,
            compilerkit_optional_new(regex));
    
    return result;
}