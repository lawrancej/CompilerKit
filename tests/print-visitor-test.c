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
 * test_print_visitor:
 * @fn test_print_visitor
 * Tests compilerkit_print_visitor.
 * @pre None
 * @param None
 * @return void
 */
void test_print_visitor (void)
{
    CompilerKitVisitor* visitor;
    GObject *regex;
    g_type_init();
    
    g_test_message ("Testing Print visitor");
    g_test_timer_start ();

    visitor = compilerkit_print_visitor();
    
    /* Construct regex (a|ab|{}|"")* programmatically. */
    regex = compilerkit_complement_new(compilerkit_kleene_star_new (compilerkit_alternation_vlist_new(compilerkit_symbol_new('a'),
                                                                    compilerkit_concatenation_new(
                                                                        compilerkit_symbol_new('a'),
                                                                        compilerkit_symbol_new('b')),
                                                                    compilerkit_empty_string_get_instance(),
                                                                    NULL
                                                                    )));

    /* Traverse through the regex structure using the regex_printer. */
    compilerkit_visitor_visit (visitor, regex);
    
    compilerkit_visitor_visit (visitor, compilerkit_complement_new(compilerkit_empty_set_get_instance()));

    /* Clean up after ourselves. */
    g_object_unref (visitor);
    g_object_unref (regex);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

