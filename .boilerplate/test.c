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

/** @todo Write test cases for Bar.
 * 1. Use this prototype (replace `case` as appropriate):
 *  `void test_bar_case (void);` 
 * 2. Add function prototypes for all functions into `test-suite.h`
 * 3. Add to `test-suite.c`:
 *  `g_test_add_func ("/bar/case", test_bar_case);`
 */

/**
 * test_bar_case:
 * @fn test_bar_case
 * Tests compilerkit_bar_case in CompilerKitBar struct.
 * @pre None
 * @param None
 * @return void
 */
void test_bar_case (void)
{
    CompilerKitBar *obj;

    g_test_message ("Testing Bar case");
    g_test_timer_start ();
    
    /** @todo Test here  */
    g_assert(FALSE);
    
    g_object_unref (obj);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}