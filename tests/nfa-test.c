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
#include "CompilerKit/automata.h"
#include "test.h"


/** 
 * @todo Write test cases, add prototype to `test.h`, call `g_test_add_func` in `test.c:main`
 * A test case for nfa should be in a function in this file called: `void test_nfa_case (void);`
 * The prototype for the function `void test_nfa_case (void);` belongs in `test.h`
 * In `test.c:main` add this function: g_test_add_func ("/nfa/case", test_nfa_case);
 * @todo The more test cases the better, until reaching sufficient coverage.
 */

/**
 * test_nfa_case:
 * @fn test_nfa_case
 * Tests compilerkit_nfa_case in CompilerKitnfa struct.
 * @pre None
 * @param None
 * @return void
 */
void test_nfa_case (void)
{
    CompilerKitnfa *obj;

    g_test_message ("Testing nfa case");
    g_test_timer_start ();
    
    /** @todo Test here  */
    g_assert(FALSE);
    
    g_object_unref (obj);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
