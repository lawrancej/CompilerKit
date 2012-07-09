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
#include <glib-object.h>
#include "CompilerKit.h"

/**
 * test_derivative_visitor:
 * @fn test_derivative_visitor
 * Tests compilerkit_derivative_visitor.
 * @pre None
 * @param None
 * @return void
 */
void test_derivative_visitor (void)
{
    CompilerKitVisitor *derivative;
    GObject *regex, *symbol, *new_regex, *cat, *star;
    
    g_test_message ("Testing Derivative visitor");
    g_test_timer_start ();
    
    /** @todo Test here  */
    derivative = compilerkit_derivative_visitor();
    regex = compilerkit_symbol_new ('h');
    
    // When we match a single character, h, against the single character 'h', we should get the empty string, because they match.
    new_regex = compilerkit_derivative_apply_char (derivative, regex, 'h');
    g_assert (new_regex == compilerkit_empty_string_get_instance());
    
    // When we match a single character, h, against the single character 'e', we should get the empty set, because they don't match.
    new_regex = compilerkit_derivative_apply_char (derivative, regex, 'e');
    g_assert (new_regex == compilerkit_empty_set_get_instance());
    
    // When we match a single character, h, against a string, we should get the empty set, because they don't match.
    new_regex = compilerkit_derivative_apply_string (derivative, regex, "hello");
    g_assert (new_regex == compilerkit_empty_set_get_instance());
    
    // When we match "hi!" against the string "hi", we should get the symbol "!", because that's what remains.
    regex = compilerkit_concatenation_new (regex, compilerkit_concatenation_new (compilerkit_symbol_new ('i'), compilerkit_symbol_new ('!')));
    new_regex = compilerkit_derivative_apply_string (derivative, regex, "hi");
//    g_warn_if_fail (g_type_name(G_OBJECT_TYPE(new_regex)));
//    g_assert (COMPILERKIT_IS_SYMBOL (new_regex));
//    g_assert (compilerkit_symbol_get_symbol(COMPILERKIT_SYMBOL(new_regex)) == '!');
    
    g_object_unref (derivative);
    g_object_unref (regex);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/visitors/derivative", test_derivative_visitor);
   
    g_test_run ();
}