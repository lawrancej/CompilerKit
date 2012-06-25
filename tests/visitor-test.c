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

static GObject *symbol_check(CompilerKitVisitor *self, GObject *obj)
{
    g_assert (COMPILERKIT_IS_SYMBOL(obj));
    return obj;
}

/* Construct a visitor that checks whether symbol is a symbol. */
static CompilerKitVisitor* check_symbol ()
{
    CompilerKitVisitor *visitor;
    visitor = compilerkit_visitor_new();
    
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, symbol_check);

    return visitor;
}

/**
 * test_visitor_register_identity:
 * @fn test_visitor_register_identity
 * Tests whether compilerkit_visitor_register_identity function works as intended.
 * @pre None
 * @param None
 * @return void
 */
void test_visitor_register_identity (void)
{
    GObject *symbol;
    GObject *empty_set;
    CompilerKitVisitor *visitor;

    g_test_message ("Testing visitor register identity");
    g_test_timer_start ();

    symbol    = compilerkit_symbol_new ('a');
    empty_set = compilerkit_empty_set_get_instance ();
    visitor   = compilerkit_visitor_new();
    
    // Register the identity function (it returns whatever GObject* gets as a parameter during the visit)
    compilerkit_visitor_register_identity (visitor, COMPILERKIT_TYPE_EMPTY_SET);
    
    // Since we didn't register the symbol, the visitor should return NULL
    g_assert (compilerkit_visitor_visit (visitor, symbol) == NULL);
    
    // The visitor should produce symbol here, since we registered the identity function for the symbol class.
    g_assert (compilerkit_visitor_visit (visitor, empty_set) == empty_set);
    
    // Decrease the reference count for objects to free them.
    g_object_unref (symbol);
    g_object_unref (empty_set);
    g_object_unref (visitor);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_visitor_null_visit:
 * @fn test_visitor_null_visit
 * Tests whether compilerkit_visitor_visit produces appropriate results in the CompilerKitVisitor struct.
 * @pre None
 * @param None
 * @return void
 */
void test_visitor_null_visit(void)
{
    GObject *symbol;
    GObject *empty_set;
    CompilerKitVisitor* visitor;

    g_test_message ("Testing visitor null visits");
    g_test_timer_start ();

    symbol = compilerkit_symbol_new ('a');
    empty_set = compilerkit_empty_set_get_instance ();
    visitor = check_symbol();

    // Assert that visitor produces the correct result
    g_assert(compilerkit_visitor_visit(visitor, symbol) == symbol);

    // NULL objects will produce NULL
    g_assert(compilerkit_visitor_visit(visitor, NULL) == NULL);

    // Nothing registered for empty set, so return NULL
    g_assert(compilerkit_visitor_visit(visitor, empty_set) == NULL);

    // Decrease the reference count for objects to free them.
    g_object_unref (symbol);
    g_object_unref (empty_set);
    g_object_unref (visitor);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/visitor/null_visit", test_visitor_null_visit);
    g_test_add_func ("/visitor/register_identity", test_visitor_register_identity);
    
    g_test_run ();
}