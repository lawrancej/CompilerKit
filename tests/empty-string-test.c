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
 * test_empty_string_singleton:
 * @fn test_empty_string_singleton
 * Tests compilerkit_empty_string_get_instance in CompilerKitEmptyString struct to verify it's a singleton.
 * @pre None
 * @param None
 * @return void
 */
void test_empty_string_singleton (void)
{
    GObject *emptystring1, *emptystring2;

    g_test_message ("Testing EmptyString to see if it is a singleton");
    g_test_timer_start ();

    /** Create two pointers to empty_string  */
    emptystring1 = compilerkit_empty_string_get_instance();
    emptystring2 = compilerkit_empty_string_get_instance();

    // Are the pointers the same? They should be.
    g_assert(emptystring1 == emptystring2);

    g_object_unref (emptystring1);
    g_object_unref (emptystring2);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
