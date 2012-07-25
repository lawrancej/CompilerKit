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

/* Nullable alternation. */
static GObject *nullable_alternation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    GObject *left, *right;
    g_assert(COMPILERKIT_IS_ALTERNATION(obj));
    
    alt = COMPILERKIT_ALTERNATION (obj);

    left = compilerkit_visitor_visit(self, compilerkit_alternation_get_left  (alt));
    right = compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));

    // Since left and right are going to be either emptyset or emptystring, alternation_new will work for us.
    return compilerkit_alternation_new (left, right);
}

/* Nullable concatenation. */
static GObject *nullable_concatenation (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    GObject *left, *right;
    g_assert(COMPILERKIT_IS_CONCATENATION(obj));
    
    cat = COMPILERKIT_CONCATENATION (obj);

    left = compilerkit_visitor_visit(self, compilerkit_concatenation_get_left  (cat));
    right = compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));

    // Since left and right are going to be emptyset or emptystring, concatenation_new will do the work for us.
    return compilerkit_concatenation_new (left, right);
}

/* Nullable Kleene star. */
static GObject *nullable_kleene_star (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    g_assert(COMPILERKIT_IS_KLEENE_STAR(obj));
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    
    return compilerkit_empty_string_get_instance();
}

/* Nullable complement. */
static GObject *nullable_complement (CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitComplement *comp;
    g_assert(COMPILERKIT_IS_COMPLEMENT(obj));
    
    comp = COMPILERKIT_COMPLEMENT (obj);
    
    if (COMPILERKIT_IS_EMPTY_SET(compilerkit_visitor_visit(self, compilerkit_complement_get_node (comp))))
        return compilerkit_empty_string_get_instance();
    else
        return compilerkit_empty_set_get_instance();
}

/* Nullable symbol. */
static GObject *nullable_symbol (CompilerKitVisitor *self, GObject *obj)
{
    return compilerkit_empty_set_get_instance();
}

/* Nullable grammar. */
static GObject *nullable_grammar (CompilerKitVisitor *self, GObject *obj)
{
   return NULL;
}

/* Nullable terminal. */
static GObject *nullable_terminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Nullable nonterminal. */
static GObject *nullable_nonterminal (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/* Nullable production. */
static GObject *nullable_production (CompilerKitVisitor *self, GObject *obj)
{
    return NULL;
}

/**
 * compilerkit_nullable:
 * @fn compilerkit_nullable
 * Determine whether a regular expression is nullable.
 * @pre None
 * @param GObject* A regular expression.
 * @return TRUE if the regular expression is nullable, FALSE otherwise.
 * @memberof CompilerKitVisitor
 */
gboolean compilerkit_nullable(GObject *regex)
{
    return compilerkit_visitor_visit(compilerkit_nullable_visitor(), regex) == compilerkit_empty_string_get_instance();
}

/**
 * compilerkit_nullable_visitor:
 * @fn compilerkit_nullable_visitor
 * Construct a nullable visitor.
 * @pre None
 * @param None
 * @return A CompilerKitVisitor*.
 * @memberof CompilerKitVisitor
 */
CompilerKitVisitor *compilerkit_nullable_visitor ()
{
    static CompilerKitVisitor *visitor = NULL;
    if (visitor == NULL) {
        visitor = compilerkit_visitor_new();
        
        /* Regular expression visitors */
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_ALTERNATION, nullable_alternation);
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_CONCATENATION, nullable_concatenation);
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_KLEENE_STAR, nullable_kleene_star);
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_COMPLEMENT, nullable_complement);
        compilerkit_visitor_register_identity (visitor, COMPILERKIT_TYPE_EMPTY_SET);
        compilerkit_visitor_register_identity (visitor, COMPILERKIT_TYPE_EMPTY_STRING);
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, nullable_symbol);
        
        /* CFG visitors */
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_GRAMMAR, nullable_grammar);
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_NONTERMINAL, nullable_concatenation);
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_TERMINAL, nullable_kleene_star);
        compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_PRODUCTION, nullable_production);
    }
    return visitor;
}
