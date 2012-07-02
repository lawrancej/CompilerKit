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
	GObject* newComplement;
    g_test_message ("Testing Complement constructor");
    g_test_timer_start ();
    
	//@todo check to see if this usage is correct
	newComplement = compilerkit_complement_new (compilerkit_symbol_new('a'));
    
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
	GObject* result;
	
    g_test_message ("Testing Complement get_node method");
    g_test_timer_start ();
    
	result = compilerkit_complement_get_node (COMPILERKIT_COMPLEMENT (g_object_new (COMPILERKIT_TYPE_COMPLEMENT, NULL)));
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/complement/constructor", test_complement_constructor);
	g_test_add_func ("/complement/get_node", test_complement_get_node);

    g_test_run ();
}