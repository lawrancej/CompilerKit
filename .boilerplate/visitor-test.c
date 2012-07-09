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

/** @todo Write test cases for compilerkit_bar_visitor of the form: void test_bar_case (void); */
/** @todo Add to `main`: g_test_add_func ("/bar/case", test_bar_case); */

/**
 * test_bar_visitor:
 * @fn test_bar_visitor
 * Tests compilerkit_bar_visitor.
 * @pre None
 * @param None
 * @return void
 */
void test_bar_visitor (void)
{
    CompilerKitVisitor *bar;
    
    g_test_message ("Testing Bar visitor");
    g_test_timer_start ();
    
    /** @todo Test here  */
    bar = compilerkit_bar_visitor();
    g_assert(FALSE);
    
    g_object_unref (bar);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/visitors/bar", test_bar_visitor);

    /**
     * @todo Add additional test cases as necessary here:
     * g_test_add_func ("/bar/other_case", test_bar_visitor_other_case);
     */
    
    g_test_run ();
}
