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

/* Print alternation. */
static GObject *print_alternation(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    g_assert(COMPILERKIT_IS_ALTERNATION(obj));
    
    alt = COMPILERKIT_ALTERNATION (obj);
    
    compilerkit_visitor_visit(self, compilerkit_alternation_get_left (alt));
    putchar ('|');
    compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));
    return NULL;
}

/* Print concatenation. */
static GObject *print_concatenation(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    g_assert(COMPILERKIT_IS_CONCATENATION(obj));
    
    cat = COMPILERKIT_CONCATENATION (obj);
    
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_left (cat));
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));
    return NULL;
}

/* Print kleene star. */
static GObject *print_kleene_star(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    g_assert(COMPILERKIT_IS_KLEENE_STAR(obj));
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    
    putchar('(');
    compilerkit_visitor_visit(self, compilerkit_kleene_star_get_node (star));
    printf(")*");
    return NULL;
}

/* Print empty set. */
static GObject *print_empty_set(CompilerKitVisitor *self, GObject *obj)
{
    g_assert(COMPILERKIT_IS_EMPTY_SET(obj));
    printf("{}");
    return NULL;
}

/* Print empty string. */
static GObject *print_empty_string(CompilerKitVisitor *self, GObject *obj)
{
    g_assert(COMPILERKIT_IS_EMPTY_STRING(obj));
    printf("\"\"");
    return NULL;
}

/* Print symbol. */
static GObject *print_symbol(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    g_assert(COMPILERKIT_IS_SYMBOL(obj));
    
    symbol = COMPILERKIT_SYMBOL (obj);
    
    printf("%c", compilerkit_symbol_get_symbol(symbol));
    return NULL;
}

/* Print complement. */
static GObject *print_complement(CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Print grammar. */
static GObject *print_grammar(CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Print terminal. */
static GObject *print_terminal(CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Print nonterminal. */
static GObject *print_nonterminal(CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Print production. */
static GObject *print_production(CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/**
 * compilerkit_print_visitor:
 * @fn compilerkit_print_visitor
 * Construct a visitor that prints out regular expressions.
 * @pre None
 * @param None
 * @return A CompilerKitVisitor*.
 * @memberof CompilerKitVisitor
 */
CompilerKitVisitor *compilerkit_print_visitor ()
{
    CompilerKitVisitor *visitor;
    visitor = compilerkit_visitor_new();
    
    /* Regular expression visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_ALTERNATION, print_alternation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_CONCATENATION, print_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_KLEENE_STAR, print_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_COMPLEMENT, print_complement);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_SET, print_empty_set);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_STRING, print_empty_string);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, print_symbol);
    
    /* CFG visitors */
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_GRAMMAR, print_grammar);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_NONTERMINAL, print_nonterminal);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_TERMINAL, print_terminal);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_PRODUCTION, print_production);
    
    return visitor;
}
