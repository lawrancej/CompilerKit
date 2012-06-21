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

#include "test-suite.h"

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    /** @todo Add here: g_test_add_func ("/class/method", test_class_method); */
    g_test_add_func ("/automata/start-state", test_FSM_start_state);
    g_test_add_func ("/automata/states", test_FSM_states);

    g_test_add_func ("/visitor/null-visit",test_visitor_null_visit);
    g_test_add_func ("/visitor/register_identity", test_visitor_register_identity);

    g_test_add_func ("/concatenation/constructor_normal", test_concatenation_constructor_normal);
    g_test_add_func ("/concatenation/constructor_empty_set", test_concatenation_constructor_empty_set);
    g_test_add_func ("/concatenation/constructor_empty_string", test_concatenation_constructor_empty_string);

    g_test_add_func ("/empty-set/singleton", test_empty_set_singleton);
    g_test_add_func ("/empty-string/singleton", test_empty_string_singleton);

//    g_test_add_func ("/symbol/unicode", test_symbol_unicode);
//    g_test_add_func ("/symbol/flyweight", test_symbol_flyweight);

    g_test_run();
}
