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
 * test_complement_constructor:
 * @fn test_complement_constructor
 * Tests method compilerkit_complement_new in CompilerKitComplement struct.
 * @pre None
 * @param None
 * @return void
 */
void test_complement_constructor (void)
{
	GObject* complement;
	GObject* regex;
	
    g_test_message ("Testing Complement constructor");
    g_test_timer_start ();

	regex = compilerkit_symbol_new('a');
	complement = compilerkit_complement_new (regex);
    
	g_assert (COMPILERKIT_IS_COMPLEMENT(complement));
	g_assert (regex != complement);
	
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_complement_get_node:
 * @fn test_complement_get_node
 * Tests method compilerkit_complement_get_node in CompilerKitComplement struct.
 * @pre None
 * @param None
 * @return void
 */
void test_complement_get_node (void)
{
	GObject* regex;
	GObject* complement;
	GObject* result;
	
    g_test_message ("Testing Complement get_node method");
    g_test_timer_start ();
    
	regex = compilerkit_symbol_new('a');
	complement = compilerkit_complement_new (regex);
	result = compilerkit_complement_get_node (COMPILERKIT_COMPLEMENT(complement));
	
	g_assert (COMPILERKIT_IS_COMPLEMENT(complement));
	g_assert (regex != complement);
	g_assert (complement != result);
	g_assert (regex == result);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
