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
#include "CompilerKit/visitor.h"
#include "test-suite.h"

/** @todo Write test cases of the form: void test_visitor_method (void); */
/** @todo Add function prototypes for all functions into test-suite.h */
/** @todo Add to test-suite.c: g_test_add_func ("/test-visitor/test-visitor-method", test_visitor_method); */

/**
 * test_visitor_method:
 * @fn test_visitor_method
 * Tests method compilerkit_visitor_method in CompilerKitVisitor struct.
 * @pre None
 * @param None
 * @return void
 */
void test_visitor_method (void)
{
    g_test_message ("Testing Visitor method");
    g_test_timer_start ();
    
    /** @todo Test here  */
	/* Make sure that visitor repsonds correctly to NULL data */
	g_assert(FALSE);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

GObject *print_alternation(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    if (!COMPILERKIT_IS_ALTERNATION(obj)) return NULL;
    
    alt = COMPILERKIT_ALTERNATION (obj);
    
    compilerkit_visitor_visit(self, compilerkit_alternation_get_left (alt));
    putchar ('|');
    compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));
    return NULL;
}

GObject *print_concatenation(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    if (!COMPILERKIT_IS_CONCATENATION(obj)) return NULL;
    
    cat = COMPILERKIT_CONCATENATION (obj);
    
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_left (cat));
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));
    return NULL;
}

GObject *print_kleene_star(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    if (!COMPILERKIT_IS_KLEENE_STAR(obj)) return NULL;
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    
    putchar('(');
    compilerkit_visitor_visit(self, compilerkit_kleene_star_get_node (star));
    printf(")*");
    return NULL;
}

GObject *print_empty_set(CompilerKitVisitor *self, GObject *obj)
{
    if (!COMPILERKIT_IS_EMPTY_SET(obj)) return NULL;
    printf("{}");
    return NULL;
}

GObject *print_empty_string(CompilerKitVisitor *self, GObject *obj)
{
    if (!COMPILERKIT_IS_EMPTY_STRING(obj)) return NULL;
    printf("\"\"");
    return NULL;
}

GObject *print_symbol(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    if (!COMPILERKIT_IS_SYMBOL(obj)) return NULL;
    
    symbol = COMPILERKIT_SYMBOL (obj);
    
    printf("%c", compilerkit_symbol_get_symbol(symbol));
    return NULL;
}

/* Construct a visitor that prints out regular expressions. */
CompilerKitVisitor* regex_printer ()
{
    CompilerKitVisitor *visitor;
    visitor = compilerkit_visitor_new();
    
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_ALTERNATION, print_alternation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_CONCATENATION, print_concatenation);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_KLEENE_STAR, print_kleene_star);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_SET, print_empty_set);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_EMPTY_STRING, print_empty_string);
    compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_SYMBOL, print_symbol);

    return visitor;
}

void test_visitor_null_visit(void)
{
	CompilerKitVisitor* visitor = regex_printer();
	g_assert(compilerkit_visitor_visit(visitor, G_OBJECT(compilerkit_symbol_new('a'))) != NULL);
	g_assert(compilerkit_visitor_visit(visitor, NULL) != NULL);
}