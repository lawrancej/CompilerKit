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
 * test_kleene_star_method:
 * @fn test_kleene_star_method
 * Tests method compilerkit_kleene_star_method in CompilerKitKleeneStar struct.
 * @pre None
 * @param None
 * @return void
 */
void test_kleene_star_method (void)
{
	GObject* e_set;
	GObject* e_string;
	GObject* a;
	GObject* result;
	
	
    g_test_message ("Testing KleeneStar method");
    g_test_timer_start ();
	
	
	//empty set
	{
	
		e_set = compilerkit_empty_set_new();
		result = compilerkit_kleene_star_new(e_set);
		g_assert(COMPILERKIT_IS_EMPTY_SET (result));
	}
	
	//empty string
	{
		e_string = compilerkit_empty_string_new();
		result = compilerkit_kleene_star_new(e_string);
		g_assert(COMPILERKIT_IS_EMPTY_STRING (result));
	}
	
	//symbol
	{
		a = compilerkit_symbol_new('a');
		result = compilerkit_kleene_star_new(a);
		g_assert(COMPILERKIT_IS_KLEENE_STAR (result));
	}
    
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/kleene_star/method", test_kleene_star_method);
   
    g_test_run ();
}