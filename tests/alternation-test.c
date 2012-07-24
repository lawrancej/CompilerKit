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
 * test_alternation_constructor:
 * @fn test_alternation_constructor
 * Tests method compilerkit_alternation_new in CompilerKitAlternation struct.
 * @pre None
 * @param None
 * @return void
 */
void test_alternation_constructor (void)
{
	GObject* alt;
	GObject* left;
	GObject* right;
	
    g_test_message ("Testing Alternation constructor");
    g_test_timer_start ();
	
	left = compilerkit_symbol_new('a');
	right = compilerkit_symbol_new('b');
	alt = compilerkit_alternation_new(left, right);
    
    g_assert (COMPILERKIT_IS_ALTERNATION(alt));
	g_assert (left != right);
	g_assert (left != alt);
	g_assert (right != alt);

	g_object_unref (alt); // This will unref left and right as well
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_alternation_get_left_and_right:
 * @fn test_alternation_get_left_and_right
 * Tests method compilerkit_alternation_get_left and compilerkit_alternation_get_right in CompilerKitAlternation struct.
 * @pre None
 * @param None
 * @return void
 */
void test_alternation_get_left_and_right (void)
{
	GObject* alt;
	GObject* left;
	GObject* right;
	
    g_test_message ("Testing Alternation get_left and get_right");
    g_test_timer_start ();
	
	left = compilerkit_symbol_new('a');
	right = compilerkit_symbol_new('b');
	alt = compilerkit_alternation_new(left, right);
    
    g_assert (COMPILERKIT_IS_ALTERNATION(alt));
	g_assert (left == compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(alt)));
	g_assert (right == compilerkit_alternation_get_right(COMPILERKIT_ALTERNATION(alt)));
	g_assert (left != alt);
	g_assert (right != alt);

	g_object_unref (alt); // This will unref left and right as well
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_alternation_vlist_new:
 * @fn test_alternation_vlist_new
 * Tests method compilerkit_alternation_vlist_new in CompilerKitAlternation struct.
 * @pre None
 * @param None
 * @return void
 */
void test_alternation_vlist_new (void)
{
	GObject* alt;
	GObject* one;
	GObject* two;
	GObject* three;
	
    g_test_message ("Testing Alternation vlist new");
    g_test_timer_start ();
	
	one = compilerkit_symbol_new('a');
	two = compilerkit_symbol_new('b');
	three = compilerkit_symbol_new('c');
	alt = compilerkit_alternation_vlist_new(one, two, three, NULL);
   
    g_assert (COMPILERKIT_IS_ALTERNATION(alt));
	g_assert (one != two);
	g_assert (two != three);
	g_assert (one != three);
	g_assert (one != alt);
	g_assert (two != alt);
	g_assert (three != alt);
	g_assert (three == compilerkit_alternation_get_right(COMPILERKIT_ALTERNATION(alt)));
	g_assert (one == compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(alt)))));
	g_assert (two == compilerkit_alternation_get_right(COMPILERKIT_ALTERNATION(compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(alt)))));

	g_object_unref (alt); // This will unref one, two and three as well
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_alternation_flyweight:
 * @fn test_alternation_flyweight
 * Tests whether the alternation constructor is a flyweight constructor.
 * @pre None
 * @param None
 * @return void
 */
void test_alternation_flyweight(void)
{
    GObject *alt1, *alt2;
    
    g_test_message ("Testing Alternation flyweight constructor");
    g_test_timer_start ();
    
    alt1 = compilerkit_alternation_new (compilerkit_symbol_new ('A'), compilerkit_symbol_new ('B'));
    alt2 = compilerkit_alternation_new (compilerkit_symbol_new ('A'), compilerkit_symbol_new ('B'));
    
    g_assert (alt1 == alt2);
    
	g_object_unref (alt1);
	g_object_unref (alt2);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
    
}