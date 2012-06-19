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
#include "CompilerKit.h"
#include "test-suite.h"

/** @todo Write test cases of the form: void test_concatenation_method (void); */
/** @todo Add function prototypes for all functions into test-suite.h */
/** @todo Add to test-suite.c: g_test_add_func ("/test-concatenation/test-concatenation-method", test_concatenation_method); */

/**
 * test_concatenation_method:
 * @fn test_concatenation_method
 * Tests method compilerkit_concatenation_method in CompilerKitConcatenation struct.
 * @pre None
 * @param None
 * @return void
 */
void test_concatenation_constructor (void)
{
	GObject* ckc;

    g_test_message ("Testing Concatenation method");
    g_test_timer_start ();
    
    /** @todo Test here  */
	//both parameters are symbols
	ckc = compilerkit_concatenation_new(compilerkit_symbol_new('a'),compilerkit_symbol_new('b'));
    g_assert(COMPILERKIT_IS_CONCATENATION(ckc));
	g_object_unref (ckc);

	//right parameter is EmptyString
	ckc = compilerkit_concatenation_new(compilerkit_symbol_new('a'),compilerkit_empty_string_new());
	g_assert(COMPILERKIT_IS_SYMBOL(ckc));
	g_object_unref (ckc);

	//left parameter is EmptyString
	ckc = compilerkit_concatenation_new(compilerkit_empty_string_new(),compilerkit_symbol_new('a'));
	g_assert(COMPILERKIT_IS_SYMBOL(ckc));
	g_object_unref (ckc);

	//right parameter is EmptySet
	ckc = compilerkit_concatenation_new(compilerkit_symbol_new('a'),compilerkit_empty_set_new());
	g_assert(COMPILERKIT_IS_EMPTY_SET(ckc));
	g_object_unref (ckc);

	//left parameter is EmptySet
	ckc = compilerkit_concatenation_new(compilerkit_empty_set_new(),compilerkit_symbol_new('a'));
	g_assert(COMPILERKIT_IS_EMPTY_SET(ckc));
	g_object_unref (ckc);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}