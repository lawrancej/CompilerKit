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
#include <glib.h>

/* StringBuilder alternation. */
static GObject *string_builder_alternation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    GString *str = (GString *) compilerkit_visitor_get_state(self);
    g_assert(COMPILERKIT_IS_ALTERNATION(obj));
    
    alt = COMPILERKIT_ALTERNATION (obj);

    compilerkit_visitor_visit(self, compilerkit_alternation_get_left  (alt));
    g_string_append_c(str, '|');
    compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));

    return NULL;
}

/* StringBuilder concatenation. */
static GObject *string_builder_concatenation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    g_assert(COMPILERKIT_IS_CONCATENATION(obj));
    
    cat = COMPILERKIT_CONCATENATION (obj);

    compilerkit_visitor_visit(self, compilerkit_concatenation_get_left  (cat));
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));

    return NULL;
}

/* StringBuilder Kleene star. */
static GObject *string_builder_kleene_star (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    GString *str = (GString *) compilerkit_visitor_get_state(self);

    g_assert(COMPILERKIT_IS_KLEENE_STAR(obj));
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    
    g_string_append_c (str, '(');
    compilerkit_visitor_visit(self, compilerkit_kleene_star_get_node (star));
    g_string_append (str, ")*");

    return NULL;
}

/* StringBuilder complement. */
static GObject *string_builder_complement (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitComplement *comp;
    GString *str = (GString *) compilerkit_visitor_get_state(self);

    g_assert(COMPILERKIT_IS_COMPLEMENT(obj));
    
    comp = COMPILERKIT_COMPLEMENT (obj);
    
    g_string_append_c (str, '!');
    compilerkit_visitor_visit(self, compilerkit_complement_get_node (comp));

    return NULL;
}


/* StringBuilder symbol. */
static GObject *string_builder_symbol (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    GString *str = (GString *) compilerkit_visitor_get_state(self);
    g_assert(COMPILERKIT_IS_SYMBOL(obj));
    
    symbol = COMPILERKIT_SYMBOL (obj);
    
    g_string_append_unichar(str, compilerkit_symbol_get_symbol(symbol));
    return NULL;
}

/* StringBuilder empty set. */
static GObject *string_builder_empty_set (CompilerKitVisitor *self, GObject *obj)
{
    GString *str = (GString *) compilerkit_visitor_get_state(self);
    g_string_append (str, "{}");

    return NULL;
}

/* StringBuilder empty string. */
static GObject *string_builder_empty_string (CompilerKitVisitor *self, GObject *obj)
{
    GString *str = (GString *) compilerkit_visitor_get_state(self);
    g_string_append (str, "''");

    return NULL;
}

/* StringBuilder grammar. */
static GObject *string_builder_grammar (CompilerKitVisitor *self, GObject *obj)
{
   return NULL;
}

/* StringBuilder terminal. */
static GObject *string_builder_terminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* StringBuilder nonterminal. */
static GObject *string_builder_nonterminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* StringBuilder production. */
static GObject *string_builder_production (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/**
 * compilerkit_string_builder_visitor:
 * @fn compilerkit_string_builder_visitor
 * Construct a string_builder visitor.
 * @pre None
 * @param None
 * @return A CompilerKitVisitor*.
 * @memberof CompilerKitVisitor
 */
CompilerKitVisitor *compilerkit_string_builder_visitor ()
{
    CompilerKitVisitor *visitor;
    visitor = compilerkit_visitor_new();
    
    /* Regular expression visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_ALTERNATION, string_builder_alternation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_CONCATENATION, string_builder_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_KLEENE_STAR, string_builder_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_COMPLEMENT, string_builder_complement);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_SET, string_builder_empty_set);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_STRING, string_builder_empty_string);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, string_builder_symbol);
    
    /* CFG visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_GRAMMAR, string_builder_grammar);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_NONTERMINAL, string_builder_nonterminal);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_TERMINAL, string_builder_terminal);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_PRODUCTION, string_builder_production);
    
    compilerkit_visitor_set_state (visitor, g_string_new(""));
    
    return visitor;
}

/**
 * compilerkit_regex_to_string:
 * @fn compilerkit_regex_to_string
 * Return a string representation of a regex.
 * @pre None
 * @param GObject* A regex
 * @return A string representation of the regex. The caller must free the returned string with `g_free()`
 * @memberof CompilerKitVisitor
 */
gchar *compilerkit_regex_to_string (GObject *regex)
{
    GString *str;
    CompilerKitVisitor *visitor = compilerkit_string_builder_visitor();
    
    compilerkit_visitor_visit(visitor, regex);
    
    str = (GString *) compilerkit_visitor_get_state(visitor);
    
    return g_string_free (str, FALSE);
}