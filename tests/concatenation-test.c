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
 * test_concatenation_constructor_normal:
 * @fn test_concatenation_constructor_normal
 * Tests compilerkit_concatenation_new in CompilerKitConcatenation struct when both sides are symbols.
 * @pre None
 * @param None
 * @return void
 */
void test_concatenation_constructor_normal (void)
{
	GObject* ckc;
	GObject* left;
	GObject* right;
    
    g_test_message ("Testing concatenation constructor when both sides are symbols");
    g_test_timer_start ();

    left = compilerkit_symbol_new('a');
    right = compilerkit_symbol_new('b');
    ckc = compilerkit_concatenation_new (left, right);

    g_assert(COMPILERKIT_IS_CONCATENATION(ckc));
    g_assert (left != ckc);
    g_assert (right != ckc);
	g_assert (compilerkit_concatenation_get_left(COMPILERKIT_CONCATENATION(ckc)) == left);
	g_assert (compilerkit_concatenation_get_right(COMPILERKIT_CONCATENATION(ckc)) == right);
	g_assert (left != right);

    g_object_unref (ckc); // This will unref left and right as well

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_concatenation_constructor_empty_set:
 * @fn test_concatenation_constructor_empty_set
 * Tests compilerkit_concatenation_new in CompilerKitConcatenation struct when either side is an empty set.
 * @pre None
 * @param None
 * @return void
 */
void test_concatenation_constructor_empty_set (void)
{
	GObject* ckc;
	GObject* left;
	GObject* right;

    g_test_message ("Testing concatenation constructor when either side is an empty set");
    g_test_timer_start ();

	// Right parameter is EmptySet
    {
        left = compilerkit_symbol_new('a');
        right = compilerkit_empty_set_get_instance ();
        ckc = compilerkit_concatenation_new(left,right);

        // Assert that ckc is the empty set, and that emptyset is a singleton.
        g_assert (right == ckc);
        g_assert(COMPILERKIT_IS_EMPTY_SET(ckc));

        g_object_unref (left);
        g_object_unref (right);
    }

	// Left parameter is EmptySet
    {
        left = compilerkit_empty_set_get_instance();
        right = compilerkit_symbol_new('a');
        ckc = compilerkit_concatenation_new(left,right);

        // Assert that concatenation is returning the empty set here.
        g_assert (ckc == left);
        g_assert (COMPILERKIT_IS_EMPTY_SET(ckc));

        g_object_unref (left);
        g_object_unref (right);
    }

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_concatenation_method:
 * @fn test_concatenation_method
 * Tests method compilerkit_concatenation_method in CompilerKitConcatenation struct.
 * @pre None
 * @param None
 * @return void
 */
void test_concatenation_constructor_empty_string (void)
{
	GObject* ckc;
	GObject* left;
	GObject* right;

    g_test_message ("Testing Concatenation constructor when either side is an empty string");
    g_test_timer_start ();

	// Right parameter is EmptyString
    {
        left = compilerkit_symbol_new('a');
        right = compilerkit_empty_string_get_instance ();
        ckc = compilerkit_concatenation_new(left,right);

        g_assert(COMPILERKIT_IS_SYMBOL(ckc));
        g_assert (left == ckc);

        g_object_unref (left);
        g_object_unref (right);
    }

	// Left parameter is EmptyString
    {
        left = compilerkit_empty_string_get_instance ();
        right = compilerkit_symbol_new('a');
        ckc = compilerkit_concatenation_new(left,right);

        g_assert(COMPILERKIT_IS_SYMBOL(ckc));
        g_assert (ckc == right);

        g_object_unref (left);
        g_object_unref (right);
    }

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
