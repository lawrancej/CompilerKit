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
 *     CompilerKitVisitor *compilerkit_to_nfa_visitor ();
 */

/* ToNfa alternation. */
static GObject *to_nfa_alternation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    g_assert(COMPILERKIT_IS_ALTERNATION(obj));
    
    alt = COMPILERKIT_ALTERNATION (obj);

    compilerkit_visitor_visit(self, compilerkit_alternation_get_left  (alt));
    compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));

    return NULL;
}

/* ToNfa concatenation. */
static GObject *to_nfa_concatenation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    g_assert(COMPILERKIT_IS_CONCATENATION(obj));
    
    cat = COMPILERKIT_CONCATENATION (obj);

    compilerkit_visitor_visit(self, compilerkit_concatenation_get_left  (cat));
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));

    return NULL;
}

/* ToNfa Kleene star. */
static GObject *to_nfa_kleene_star (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    g_assert(COMPILERKIT_IS_KLEENE_STAR(obj));
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    
    compilerkit_visitor_visit(self, compilerkit_kleene_star_get_node (star));

    return NULL;
}

/* ToNfa complement. */
static GObject *to_nfa_complement (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitComplement *comp;
    g_assert(COMPILERKIT_IS_COMPLEMENT(obj));
    
    comp = COMPILERKIT_COMPLEMENT (obj);
    
    compilerkit_visitor_visit(self, compilerkit_complement_get_node (comp));

    return NULL;
}


/* ToNfa symbol. */
static GObject *to_nfa_symbol (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    g_assert(COMPILERKIT_IS_SYMBOL(obj));
    
    symbol = COMPILERKIT_SYMBOL (obj);
    
    compilerkit_symbol_get_symbol(symbol);
    return NULL;
}

/* ToNfa empty set. */
static GObject *to_nfa_empty_set (CompilerKitVisitor *self, GObject *obj)
{
    g_assert(COMPILERKIT_IS_EMPTY_SET(obj));

    return NULL;
}

/* ToNfa empty string. */
static GObject *to_nfa_empty_string (CompilerKitVisitor *self, GObject *obj)
{
    g_assert(COMPILERKIT_IS_EMPTY_STRING(obj));

    return NULL;
}

/* ToNfa grammar. */
static GObject *to_nfa_grammar (CompilerKitVisitor *self, GObject *obj)
{
   return NULL;
}

/* ToNfa terminal. */
static GObject *to_nfa_terminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* ToNfa nonterminal. */
static GObject *to_nfa_nonterminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* ToNfa production. */
static GObject *to_nfa_production (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/**
 * compilerkit_to_nfa_visitor:
 * @fn compilerkit_to_nfa_visitor
 * Construct a to_nfa visitor.
 * @pre None
 * @param None
 * @return A CompilerKitVisitor*.
 * @memberof CompilerKitVisitor
 */
CompilerKitVisitor *compilerkit_to_nfa_visitor ()
{
    CompilerKitVisitor *visitor;
    visitor = compilerkit_visitor_new();
    
    /* Regular expression visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_ALTERNATION, to_nfa_alternation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_CONCATENATION, to_nfa_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_KLEENE_STAR, to_nfa_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_COMPLEMENT, to_nfa_complement);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_SET, to_nfa_empty_set);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_STRING, to_nfa_empty_string);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, to_nfa_symbol);
    
    /* CFG visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_GRAMMAR, to_nfa_grammar);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_NONTERMINAL, to_nfa_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_TERMINAL, to_nfa_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_PRODUCTION, to_nfa_production);
    
    return visitor;
}