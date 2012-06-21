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
#include "CompilerKit/symbol.h"
#include "test-suite.h"

/**
 * test_symbol_unicode:
 * @fn test_symbol_unicode
 * Tests compilerkit_symbol_new in CompilerKitSymbol struct for the ability to deal with Unicode (specifically, UTF-8).
 * @pre None
 * @param None
 * @return void
 */
void test_symbol_unicode (void)
{
    CompilerKitSymbol *symbol;
    g_test_message ("Testing Symbol unicode");
    g_test_timer_start ();
    
    /** @todo Test here  */
    symbol = COMPILERKIT_SYMBOL (compilerkit_symbol_new(21488));

    g_assert(compilerkit_symbol_get_symbol (symbol) == '台');

    g_object_unref(symbol);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

/**
 * test_symbol_flyweight:
 * @fn test_symbol_unicode
 * Tests whether compilerkit_symbol_new in CompilerKitSymbol struct allocates new space only for unique symbols.
 * @pre None
 * @param None
 * @return void
 */
void test_symbol_flyweight (void)
{
    CompilerKitSymbol *symbol1, *symbol2, *symbol3;
    
    g_test_message ("Testing Symbol unicode");
    g_test_timer_start ();
    
    /** @todo Test here  */
    symbol1 = COMPILERKIT_SYMBOL (compilerkit_symbol_new('a'));
    symbol2 = COMPILERKIT_SYMBOL (compilerkit_symbol_new('b'));
    symbol3 = COMPILERKIT_SYMBOL (compilerkit_symbol_new('a'));

    /* Symbol b is distinct from Symbol a */
    g_assert (symbol2 != symbol3);
    g_assert (symbol2 != symbol1);

    /* The pointer to Symbol('a') should equal the pointer to Symbol('a').
       This of course, would make Ayn Rand proud ;-) */
    g_assert (symbol1 == symbol3);

    g_object_unref(symbol1);
    g_object_unref(symbol2);
    g_object_unref(symbol3);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
