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
 * test_concatenation_constructor_normal:
 * @fn test_concatenation_constructor_normal
 * Tests compilerkit_concatenation_method in CompilerKitConcatenation struct.
 * @pre None
 * @param None
 * @return void
 */
void test_concatenation_constructor_normal (void)
{
	GObject* ckc;
	GObject* left;
	GObject* right;

    g_test_message ("Testing concatenation constructor");
    g_test_timer_start ();

    left = compilerkit_symbol_new('a');
    right = compilerkit_symbol_new('b');
    ckc = compilerkit_concatenation_new(left,right);

    g_assert(COMPILERKIT_IS_CONCATENATION(ckc));
    g_assert (left != ckc);
    g_assert (right != ckc);

    g_object_unref (ckc); // This will unref left and right as well

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
void test_concatenation_constuctor_empty_set (void)
{

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

}

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
	GObject* left;
	GObject* right;

    g_test_message ("Testing Concatenation method");
    g_test_timer_start ();
    
    /** @todo Test here  */
    
	// Both parameters are symbols
    {
        left = compilerkit_symbol_new('a');
        right = compilerkit_symbol_new('b');
        ckc = compilerkit_concatenation_new(left,right);

        g_assert(COMPILERKIT_IS_CONCATENATION(ckc));
        g_assert (left != ckc);
        g_assert (right != ckc);

        g_object_unref (ckc); // This will unref left and right as well
    }

	// Right parameter is EmptyString
    {
        left = compilerkit_symbol_new('a');
        right = compilerkit_empty_string_new ();
        ckc = compilerkit_concatenation_new(left,right);

        g_assert(COMPILERKIT_IS_SYMBOL(ckc));
        g_assert (left == ckc);
        
        g_object_unref (left);
        g_object_unref (right);
    }

	// Left parameter is EmptyString
    {
        left = compilerkit_empty_string_new ();
        right = compilerkit_symbol_new('a');
        ckc = compilerkit_concatenation_new(left,right);

        g_assert(COMPILERKIT_IS_SYMBOL(ckc));
        g_assert (ckc == right);
        
        g_object_unref (left);
        g_object_unref (right);
    }

	// Right parameter is EmptySet
    {
        left = compilerkit_symbol_new('a');
        right = compilerkit_empty_set_get_instance();
        ckc = compilerkit_concatenation_new(left,right);
        
        // Assert that ckc is the empty set, and that emptyset is a singleton.
        g_assert (right == ckc);
        g_assert(COMPILERKIT_IS_EMPTY_SET(ckc));
        
        g_printf ("\nckc:   %p\nleft:  %p\nright: %p\n", ckc, left, right);

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

        g_printf ("\nckc:   %p\nleft:  %p\nright: %p\n\n", ckc, left, right);
        
        g_object_unref (left);
        g_object_unref (right);
    }
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}