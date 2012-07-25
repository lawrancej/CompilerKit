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

/* Derivative of alternation. */
static GObject *derivative_alternation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    GObject *left, *right;
    g_assert(COMPILERKIT_IS_ALTERNATION(obj));
    
    alt = COMPILERKIT_ALTERNATION (obj);

    left = compilerkit_visitor_visit(self, compilerkit_alternation_get_left  (alt));
    right = compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));

    return compilerkit_alternation_new (left, right);
}

/* Derivative of concatenation. */
static GObject *derivative_concatenation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    GObject *left, *right, *nulled;
    g_assert(COMPILERKIT_IS_CONCATENATION(obj));
    
    cat = COMPILERKIT_CONCATENATION (obj);

    left = compilerkit_visitor_visit(self, compilerkit_concatenation_get_left  (cat));
    right = compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));
    nulled = compilerkit_visitor_visit(compilerkit_nullable_visitor (), compilerkit_concatenation_get_left  (cat));

    return compilerkit_alternation_new (compilerkit_concatenation_new(left, compilerkit_concatenation_get_right (cat)),
            compilerkit_concatenation_new (nulled, right));
}

/* Derivative of Kleene star. */
static GObject *derivative_kleene_star (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    GObject *node;
    g_assert(COMPILERKIT_IS_KLEENE_STAR(obj));
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    node = compilerkit_visitor_visit(self, compilerkit_kleene_star_get_node (star));
    
    return compilerkit_concatenation_new(node, star);
}

/* Derivative of complement. */
static GObject *derivative_complement (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitComplement *comp;
    GObject *node;
    g_assert(COMPILERKIT_IS_COMPLEMENT(obj));
    
    comp = COMPILERKIT_COMPLEMENT (obj);
    
    node = compilerkit_visitor_visit(self, compilerkit_complement_get_node (comp));

    return compilerkit_complement_new(node);
}


/* Derivative of symbol. */
static GObject *derivative_symbol (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    gunichar *character = self->state;

    g_assert(COMPILERKIT_IS_SYMBOL(obj));
    
    symbol = COMPILERKIT_SYMBOL (obj);
    
    if (*character == compilerkit_symbol_get_symbol (symbol))
        return compilerkit_empty_string_get_instance ();
    return compilerkit_empty_set_get_instance ();
}

/* Derivative of empty string. */
static GObject *derivative_empty_string (CompilerKitVisitor *self, GObject *obj)
{
    g_assert(COMPILERKIT_IS_EMPTY_STRING(obj));

    return compilerkit_empty_set_get_instance();
}

/* Derivative of grammar. */
static GObject *derivative_grammar (CompilerKitVisitor *self, GObject *obj)
{
   return NULL;
}

/* Derivative of terminal. */
static GObject *derivative_terminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Derivative of nonterminal. */
static GObject *derivative_nonterminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Derivative of production. */
static GObject *derivative_production (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/**
 * compilerkit_derivative_visitor:
 * @fn compilerkit_derivative_visitor
 * Construct a derivative visitor.
 * @pre None
 * @param None
 * @return A CompilerKitVisitor*.
 * @memberof CompilerKitVisitor
 */
CompilerKitVisitor *compilerkit_derivative_visitor ()
{
    CompilerKitVisitor *visitor;
    visitor = compilerkit_visitor_new();
    
    /* Regular expression visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_ALTERNATION, derivative_alternation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_CONCATENATION, derivative_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_KLEENE_STAR, derivative_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_COMPLEMENT, derivative_complement);
    compilerkit_visitor_register_identity (visitor, COMPILERKIT_TYPE_EMPTY_SET);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_STRING, derivative_empty_string);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, derivative_symbol);
    
    /* CFG visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_GRAMMAR, derivative_grammar);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_NONTERMINAL, derivative_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_TERMINAL, derivative_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_PRODUCTION, derivative_production);
    
    return visitor;
}

/**
 * compilerkit_derivative_apply_char:
 * @fn compilerkit_derivative_apply_char
 * Apply the derivative visitor to a Unicode character.
 * @pre None
 * @param CompilerKitVisitor* A derivative visitor.
 * @param GObject* A regex.
 * @param gunichar A Unicode code point.
 * @return A GObject representing the derivative of regex applied to symbol.
 * @memberof CompilerKitVisitor
 */
GObject *compilerkit_derivative_apply_char (CompilerKitVisitor *derivative_visitor, GObject *regex, gunichar symbol)
{
    compilerkit_visitor_set_state (derivative_visitor, &symbol);
    return compilerkit_visitor_visit (derivative_visitor, regex);
}

/**
 * compilerkit_derivative_apply_string:
 * @fn compilerkit_derivative_apply_string
 * Apply the derivative visitor to a string.
 * @pre None
 * @param CompilerKitVisitor* A derivative visitor.
 * @param GObject* A regex.
 * @param gchar* A UTF-8 string.
 * @return A GObject representing the derivative of regex applied to a string.
 * @memberof CompilerKitVisitor
 */
GObject *compilerkit_derivative_apply_string (CompilerKitVisitor *derivative_visitor, GObject *regex, gchar *string)
{
    GObject *result = regex;
    g_utf8_validate(string, -1, NULL);
    while (*string)
    {
        result = compilerkit_derivative_apply_char (derivative_visitor, result, g_utf8_get_char(string));
        string = g_utf8_next_char(string);
    }
    return result;
}

/**
 * compilerkit_regex_matches_string:
 * @fn compilerkit_derivative_matches_string
 * Determine whether the regex matches the string.
 * @pre None
 * @param GObject* A regex.
 * @param gchar* A UTF-8 string.
 * @return A gboolean indicating whether the regex matched the string completely.
 * @memberof CompilerKitVisitor
 */
gboolean compilerkit_regex_matches_string (GObject *regex, gchar *string)
{
    CompilerKitVisitor *derivative_visitor = compilerkit_derivative_visitor();
    CompilerKitVisitor *nullable_visitor = compilerkit_nullable_visitor();
    GObject *result = compilerkit_derivative_apply_string (derivative_visitor, regex, string);
    g_object_unref (derivative_visitor);
    result = compilerkit_visitor_visit (nullable_visitor, result);
    return result == compilerkit_empty_string_get_instance();
}