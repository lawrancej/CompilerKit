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
#include "test-suite.h"

/** 
 * @todo Write test cases for compilerkit_derivative_visitor.
 * 1. Use this prototype (replace `case` as appropriate):
 *  `void test_derivative_visitor (void);` 
 * 2. Add function prototypes for all functions into `test-suite.h`
 * 3. Add to `test-suite.c`:
 *  `g_test_add_func ("/derivative/visitor", test_derivative_visitor);`
 */

/**
 * test_derivative_visitor:
 * @fn test_derivative_visitor
 * Tests compilerkit_derivative_visitor.
 * @pre None
 * @param None
 * @return void
 */
void test_derivative_case (void)
{
    CompilerKitVisitor *derivative;
    g_test_message ("Testing Derivative visitor");
    g_test_timer_start ();
    
    /** @todo Test here  */
    derivative = compilerkit_derivative_visitor();
    g_assert(FALSE);
    
    g_object_unref (derivative);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}