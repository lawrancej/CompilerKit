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

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/alternation/constructor", test_alternation_constructor);
	g_test_add_func ("/alternation/get_left_and_get_right", test_alternation_get_left_and_right);
	g_test_add_func ("/alternation/vlist_new", test_alternation_vlist_new);
    g_test_add_func ("/alternation/flyweight", test_alternation_flyweight);
    
    g_test_add_func ("/automata/start-state", test_FSM_start_state);
    g_test_add_func ("/automata/states", test_FSM_states);
    g_test_add_func ("/automata/transitions", test_FSM_transitions);

    g_test_add_func ("/complement/constructor", test_complement_constructor);
	g_test_add_func ("/complement/get_node", test_complement_get_node);

    g_test_add_func ("/concatenation/constructor_normal", test_concatenation_constructor_normal);
    g_test_add_func ("/concatenation/constructor_empty_set", test_concatenation_constructor_empty_set);
    g_test_add_func ("/concatenation/constructor_empty_string", test_concatenation_constructor_empty_string);

    g_test_add_func ("/convenience/alternation", test_convenience_alternation);
    g_test_add_func ("/convenience/positive_closure", test_positive_closure);
    g_test_add_func ("/convenience/string_concatenation", test_string_concatenation);
    g_test_add_func ("/convenience/ranges", test_convenience_ranges);
    g_test_add_func ("/convenience/times", test_convenience_times);

    g_test_add_func ("/derivative-visitor/test", test_derivative_visitor);

    g_test_add_func ("/empty-set/singleton", test_empty_set_singleton);

    g_test_add_func ("/empty-string/singleton", test_empty_string_singleton);

    g_test_add_func ("/grammar/method", test_grammar_method);

    g_test_add_func ("/kleene-star/constructor", test_kleene_star_constructor);

    g_test_add_func ("/nonterminal/method", test_nonterminal_method);

    g_test_add_func ("/nullable-visitor/test", test_nullable_visitor);

    g_test_add_func ("/production/case", test_production_case);

    g_test_add_func ("/pushdown-automata/test", test_pushdown_automata_method);

    g_test_add_func ("/range/case", test_range_case);

    g_test_add_func ("/scanner/method", test_scanner_method);

    g_test_add_func ("/string-builder-visitor/test", test_string_builder_visitor);

    g_test_add_func ("/symbol/unicode", test_symbol_unicode);
    g_test_add_func ("/symbol/flyweight", test_symbol_flyweight);

    g_test_add_func ("/terminal/method", test_terminal_method);

    g_test_add_func ("/to-grammar-visitor/test", test_to_grammar_visitor);

    g_test_add_func ("/to-graphviz-visitor/test", test_to_graphviz_visitor);

    g_test_add_func ("/token/case", test_token_case);

    g_test_add_func ("/to-nfa-visitor/test", test_to_nfa_visitor);

    g_test_add_func ("/visitor/null_visit", test_visitor_null_visit);
    g_test_add_func ("/visitor/register_identity", test_visitor_register_identity);

    g_test_run ();
}