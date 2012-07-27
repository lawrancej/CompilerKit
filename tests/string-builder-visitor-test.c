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
 * test_string_builder_visitor:
 * @fn test_string_builder_visitor
 * Tests compilerkit_string_builder_visitor.
 * @pre None
 * @param None
 * @return void
 */
void test_string_builder_visitor (void)
{
    GObject *regex = compilerkit_alternation_vlist_new(
        compilerkit_symbol_new('a'),
        compilerkit_concatenation_new(
            compilerkit_symbol_new('b'),
            compilerkit_kleene_star_new(compilerkit_symbol_new('c'))
        ),
        compilerkit_empty_string_get_instance(),
        compilerkit_complement_new (compilerkit_empty_set_get_instance()),
        NULL);
    gchar *str;
    g_test_message ("Testing StringBuilder digits");
    g_test_timer_start ();
    
    str = compilerkit_to_string (regex);
    g_assert(g_strcmp0(str, "a|b(c)*|''|!{}") == 0);
    g_free (str);
    
    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

