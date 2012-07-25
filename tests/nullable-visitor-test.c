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
#include <glib.h>
#include "CompilerKit.h"
#include "test.h"

/**
 * test_nullable_visitor:
 * @fn test_nullable_visitor
 * Tests compilerkit_nullable_visitor.
 * @pre None
 * @param None
 * @return void
 */
void test_nullable_visitor (void)
{
    CompilerKitVisitor *nullable;
    GObject *symbol, *star, *cat, *alt1, *alt2, *comp1, *comp2;
    
    g_test_message ("Testing Nullable visitor");
    g_test_timer_start ();

    // symbol is a
    symbol = compilerkit_symbol_new ('a');
    // star is a*
    star = compilerkit_kleene_star_new (symbol);
    // cat is aa*
    cat = compilerkit_concatenation_new (symbol, star);
    // alt1 is emptystring|aa*
    alt1 = compilerkit_alternation_new (cat, compilerkit_empty_string_get_instance());
    // alt2 is aa*|a
    alt2 = compilerkit_alternation_new (cat, symbol);
    
    comp1 = compilerkit_complement_new (compilerkit_empty_set_get_instance());
    comp2 = compilerkit_complement_new (compilerkit_empty_string_get_instance());
    
    nullable = compilerkit_nullable_visitor();
    
    // Symbol is not nullable, hence it should return EmptySet here.
    g_assert (compilerkit_visitor_visit(nullable, symbol) == compilerkit_empty_set_get_instance());
    
    // KleeneStar is nullable, so it should return EmptyString here.
    g_assert (compilerkit_visitor_visit(nullable, star) == compilerkit_empty_string_get_instance());
    
    // Concatenation is not nullable, so it should return EmptySet here.
    g_assert (compilerkit_visitor_visit(nullable, cat) == compilerkit_empty_set_get_instance());
    
    // Alt1 is nullable, because one side is nullable. 
    g_assert (compilerkit_visitor_visit(nullable, alt1) == compilerkit_empty_string_get_instance());
    
    // Alt2 is not nullable, because neither side is nullable. 
    g_assert (compilerkit_visitor_visit(nullable, alt2) == compilerkit_empty_set_get_instance());
    
    // comp1 is nullable, since it's the complement of the emptyset
    g_assert (compilerkit_visitor_visit(nullable, comp1) == compilerkit_empty_string_get_instance());

    // comp2 is not nullable, since it's the complement of the emptystring
    g_assert (compilerkit_visitor_visit(nullable, comp2) == compilerkit_empty_set_get_instance());

    g_object_unref (nullable);
    g_object_unref (comp1);
    g_object_unref (comp2);
//    g_object_unref (alt2);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
