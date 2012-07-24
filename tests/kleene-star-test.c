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
 * test_kleene_star_constructor:
 * @fn test_kleene_star_constructor
 * Tests compilerkit_kleene_star_new in CompilerKitKleeneStar struct.
 * @pre None
 * @param None
 * @return void
 */
void test_kleene_star_constructor (void)
{
	GObject* e_set;
	GObject* e_string;
	GObject* a;
	GObject* result;
	
	
    g_test_message ("Testing KleeneStar method");
    g_test_timer_start ();
	
	
	//empty set
	{
	
		e_set = compilerkit_empty_set_get_instance();
		result = compilerkit_kleene_star_new(e_set);
		g_assert(COMPILERKIT_IS_EMPTY_SET (result));
        g_object_unref (result);
	}
	
	//empty string
	{
		e_string = compilerkit_empty_string_get_instance();
		result = compilerkit_kleene_star_new(e_string);
		g_assert(COMPILERKIT_IS_EMPTY_STRING (result));
        g_object_unref (result);
	}
	
	//symbol
	{
		a = compilerkit_symbol_new('a');
		result = compilerkit_kleene_star_new(a);
		g_assert(COMPILERKIT_IS_KLEENE_STAR (result));
        g_object_unref (result);
	}
    
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
