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

/** @todo Write test cases for range of the form: void test_range_case (void); */
/** @todo Add to `main`: g_test_add_func ("/range/case", test_range_case); */

/**
 * test_range_case:
 * @fn test_range_case
 * Tests compilerkit_range_case in CompilerKitRange struct.
 * @pre None
 * @param None
 * @return void
 */
void test_range_case (void)
{
    GObject* obj;
	GObject* left;
	GObject* right;
    CompilerKitRange *range;

    g_test_message ("Testing range case");
    g_test_timer_start ();
	
	left = compilerkit_symbol_new('A');
	right = compilerkit_symbol_new('C');
    
	obj = compilerkit_range_new(left, right);
    /** @todo Test here  */
	g_assert(COMPILERKIT_IS_RANGE(obj));
    range = COMPILERKIT_RANGE(obj);
    //g_assert(obj->priv->left->priv->node == 'A');
    
    g_object_unref (obj);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
