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

/** @todo Write test cases of the form: void test_visitor_method (void); */
/** @todo Add function prototypes for all functions into test-suite.h */
/** @todo Add to test-suite.c: g_test_add_func ("/test-visitor/test-visitor-method", test_visitor_method); */

static GObject *symbol_check(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    g_assert (COMPILERKIT_IS_SYMBOL(obj));
    
    return obj;
}

/* Construct a visitor checks whether symbol is a symbol. */
static CompilerKitVisitor* check_symbol ()
{
    CompilerKitVisitor *visitor;
    visitor = compilerkit_visitor_new();
    
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, symbol_check);

    return visitor;
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
    GObject *symbol = compilerkit_symbol_new ('a');
    GObject *empty_set = compilerkit_empty_set_get_instance ();
    CompilerKitVisitor* visitor = check_symbol();

    // Assert that visitor produces the correct result
    g_assert(compilerkit_visitor_visit(visitor, symbol) == symbol);

    // NULL objects will produce NULL
    g_assert(compilerkit_visitor_visit(visitor, NULL) == NULL);

    // Nothing registered for empty set, so return NULL
    g_assert(compilerkit_visitor_visit(visitor, empty_set) == NULL);

    g_object_unref (symbol);
    g_object_unref (empty_set);
}
