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
    GObject *symbol, *star, *cat, *alt1, *alt2;
    
    g_test_message ("Testing Nullable visitor");
    g_test_timer_start ();
    
    /** @todo Test here  */
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
    
    nullable = compilerkit_nullable_visitor();
    
    // Symbol is not nullable, hence it should return NULL here.
    g_assert (compilerkit_visitor_visit(nullable, symbol) == NULL);
    
    // KleeneStar is nullable, so it should return EmptyString here.
    g_assert (compilerkit_visitor_visit(nullable, star) == compilerkit_empty_string_get_instance());
    
    // Concatenation is not nullable, so it should return NULL here.
    g_assert (compilerkit_visitor_visit(nullable, cat) == NULL);
    
    // Alt1 is nullable, because one side is nullable. 
    g_assert (compilerkit_visitor_visit(nullable, alt1) == compilerkit_empty_string_get_instance());
    
    // Alt2 is not nullable, because neither side is nullable. 
    g_assert (compilerkit_visitor_visit(nullable, alt2) == NULL);

    g_object_unref (nullable);
    g_object_unref (alt1);
    g_object_unref (alt2);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/visitors/nullable", test_nullable_visitor);
    
    g_test_run ();
}