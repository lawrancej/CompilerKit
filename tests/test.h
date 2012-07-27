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

#ifndef INCLUDE_CompilerKit_test_h__
#define INCLUDE_CompilerKit_test_h__

void test_alternation_constructor (void);
void test_alternation_get_left_and_right (void);
void test_alternation_vlist_new (void);
void test_alternation_flyweight(void);

void test_FSM_start_state (void);
void test_FSM_states (void);
void test_FSM_transitions (void);

void test_complement_constructor (void);
void test_complement_get_node (void);

void test_concatenation_constructor_normal (void);
void test_concatenation_constructor_empty_set (void);
void test_concatenation_constructor_empty_string (void);

void test_convenience_alternation(void);
void test_positive_closure(void);
void test_string_concatenation(void);
void test_convenience_ranges(void);
void test_convenience_times (void);

void test_derivative_visitor (void);

void test_empty_set_singleton (void);

void test_empty_string_singleton (void);

void test_grammar_method (void);

void test_kleene_star_constructor (void);

void test_nonterminal_method (void);

void test_nullable_visitor (void);

void test_production_case (void);

void test_pushdown_automata_method (void);

void test_range_case (void);

void test_scanner_method (void);

void test_string_builder_visitor (void);

void test_symbol_unicode (void);
void test_symbol_flyweight (void);

void test_terminal_method (void);

void test_to_grammar_visitor (void);

void test_to_graphviz_visitor (void);

void test_token_case (void);

void test_to_nfa_visitor (void);

void test_visitor_register_identity (void);
void test_visitor_null_visit(void);

#endif