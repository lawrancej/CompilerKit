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
#include <glib/gprintf.h>
#include "CompilerKit.h"
#include "test.h"

/**
 * expression_grammar:
 * @fn expression_grammar
 * Create a grammar to parse mathematical expressions unambiguously.
 * @pre None
 * @param None
 * @return void
 */
CompilerKitGrammar *expression_grammar()
{
    CompilerKitNonterminal *value = compilerkit_nonterminal_new ("value");
    CompilerKitNonterminal *product = compilerkit_nonterminal_new ("product");
    CompilerKitNonterminal *sum = compilerkit_nonterminal_new ("sum");
    CompilerKitNonterminal *expr = compilerkit_nonterminal_new ("expr");

    /*
     Define the grammar below:
     value -> [0-9]+ | (expr)
     product -> value ((*|/) value)*
     sum -> product ((+|-) product)*
     expr -> sum
     */
    
    return compilerkit_grammar_new (expr, 
        compilerkit_production_new (value, MANY1 (DIGIT), NULL),
        compilerkit_production_new (value, PARENS (expr), NULL),
        compilerkit_production_new (product, value, MANY (SEQ (OR (SYMB ('*'), SYMB ('/')), value)), NULL),
        compilerkit_production_new (sum, product, MANY (SEQ (OR (SYMB ('+'), SYMB ('-')), product)), NULL),
        compilerkit_production_new (expr, sum, NULL),
        NULL);
}

/**
 * test_grammar_method:
 * @fn test_grammar_method
 * Tests method compilerkit_grammar_new in CompilerKitGrammar struct.
 * @pre None
 * @param None
 * @return void
 */
void test_grammar_method (void)
{
    CompilerKitGrammar *grammar;
    g_test_message ("Testing Grammar method");
    g_test_timer_start ();
    
    grammar = expression_grammar();
    g_printf("%s\n", compilerkit_to_string(grammar));
    /* Return whether the formula parser matched the expression "(1+2+3+4)/2". Should return true */
//    formula->match("(1+2+3+4)/2");
    g_object_unref (grammar);

    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}
