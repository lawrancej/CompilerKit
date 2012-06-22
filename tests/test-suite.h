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

/** Test case function prototypes of the form: void test_class_case (void); */
void test_FSM_start_state (void);
void test_FSM_states (void);

void test_concatenation_constructor_normal (void);
void test_concatenation_constructor_empty_string (void);
void test_concatenation_constructor_empty_set (void);

void test_visitor_null_visit(void);
void test_visitor_register_identity(void);

void test_empty_set_singleton (void);
void test_empty_string_singleton (void);

void test_symbol_unicode (void);
void test_symbol_flyweight (void);
