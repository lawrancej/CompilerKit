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

/** 
 * @todo Add the following to include/visitors.h:
 *     CompilerKitVisitor *compilerkit_derivative_visitor ();
 */

/* Derivative alternation. */
static GObject *derivative_alternation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    g_assert(COMPILERKIT_IS_ALTERNATION(obj));
    
    alt = COMPILERKIT_ALTERNATION (obj);

    compilerkit_visitor_visit(self, compilerkit_alternation_get_left  (alt));
    compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));

    return NULL;
}

/* Derivative concatenation. */
static GObject *derivative_concatenation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    g_assert(COMPILERKIT_IS_CONCATENATION(obj));
    
    cat = COMPILERKIT_CONCATENATION (obj);

    compilerkit_visitor_visit(self, compilerkit_concatenation_get_left  (cat));
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));

    return NULL;
}

/* Derivative Kleene star. */
static GObject *derivative_kleene_star (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    g_assert(COMPILERKIT_IS_KLEENE_STAR(obj));
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    
    compilerkit_visitor_visit(self, compilerkit_kleene_star_get_node (star));

    return NULL;
}

/* Derivative complement. */
static GObject *derivative_complement (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitComplement *comp;
    g_assert(COMPILERKIT_IS_COMPLEMENT(obj));
    
    comp = COMPILERKIT_COMPLEMENT (obj);
    
    compilerkit_visitor_visit(self, compilerkit_complement_get_node (comp));

    return NULL;
}


/* Derivative symbol. */
static GObject *derivative_symbol (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    gunichar *character = self->state;
    gunichar regex_symb = compilerkit_symbol_get_symbol(symbol);
    g_assert(COMPILERKIT_IS_SYMBOL(obj));
    
    symbol = COMPILERKIT_SYMBOL (obj);
    
    if (*character == regex_symb)
        return compilerkit_empty_string_get_instance();
    return compilerkit_empty_set_get_instance();
}

/* Derivative empty set. */
static GObject *derivative_empty_set (CompilerKitVisitor *self, GObject *obj)
{
    g_assert(COMPILERKIT_IS_EMPTY_SET(obj));

    return compilerkit_empty_set_get_instance();
}

/* Derivative empty string. */
static GObject *derivative_empty_string (CompilerKitVisitor *self, GObject *obj)
{
    g_assert(COMPILERKIT_IS_EMPTY_STRING(obj));

    return compilerkit_empty_set_get_instance();
}

/* Derivative grammar. */
static GObject *derivative_grammar (CompilerKitVisitor *self, GObject *obj)
{
   return NULL;
}

/* Derivative terminal. */
static GObject *derivative_terminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Derivative nonterminal. */
static GObject *derivative_nonterminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Derivative production. */
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
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_SET, derivative_empty_set);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_STRING, derivative_empty_string);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, derivative_symbol);
    
    /* CFG visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_GRAMMAR, derivative_grammar);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_NONTERMINAL, derivative_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_TERMINAL, derivative_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_PRODUCTION, derivative_production);
    
    return visitor;
}