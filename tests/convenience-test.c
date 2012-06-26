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

void test_convenience_alternation(void)
{
	 GObject* expression1 = compilerkit_character_class_new('0','h');
	 GObject* expression2 = compilerkit_character_class_new(33,'h');
	 GObject* expression3 = compilerkit_character_class_new('0',137);
	 g_assert(expression1 != NULL);
	 g_assert(expression2 == NULL);
	 g_assert(expression3 == NULL);
	 g_object_unref(expression1);
	 g_object_unref(expression2);
	 g_object_unref(expression3);
}

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/convenience/alternation", test_convenience_alternation);
    
    g_test_run ();
}
