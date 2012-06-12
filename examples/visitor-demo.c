#include <stdio.h>
#include "CompilerKit.h"

void print_alternation(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitAlternation *alt;
    g_return_if_fail (COMPILERKIT_IS_ALTERNATION(obj));
    
    alt = COMPILERKIT_ALTERNATION (obj);
    
    compilerkit_visitor_visit(self, compilerkit_alternation_get_left (alt));
    putchar ('|');
    compilerkit_visitor_visit(self, compilerkit_alternation_get_right (alt));
}

void print_concatenation(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitConcatenation *cat;
    g_return_if_fail (COMPILERKIT_IS_CONCATENATION(obj));
    
    cat = COMPILERKIT_CONCATENATION (obj);
    
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_left (cat));
    compilerkit_visitor_visit(self, compilerkit_concatenation_get_right (cat));
}

void print_kleene_star(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitKleeneStar *star;
    g_return_if_fail (COMPILERKIT_IS_KLEENE_STAR(obj));
    
    star = COMPILERKIT_KLEENE_STAR (obj);
    
    putchar('(');
    compilerkit_visitor_visit(self, compilerkit_kleene_star_get_node (star));
    printf(")*");
}

void print_empty_set(CompilerKitVisitor *self, GObject *obj)
{
    g_return_if_fail (COMPILERKIT_IS_EMPTY_SET(obj));
    printf("{}");
}

void print_empty_string(CompilerKitVisitor *self, GObject *obj)
{
    g_return_if_fail (COMPILERKIT_IS_EMPTY_STRING(obj));
    printf("\"\"");
}

void print_symbol(CompilerKitVisitor *self, GObject *obj)
{
    CompilerKitSymbol *symbol;
    g_return_if_fail (COMPILERKIT_IS_SYMBOL(obj));
    
    symbol = COMPILERKIT_SYMBOL (obj);
    
    printf("%c", compilerkit_symbol_get_symbol(symbol));
}


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

/** 
 * main:
 * @fn main
 * Demonstrate the visitor class by printing out arbitrary regular expressions.
 */
int main (int argc, char ** argv)
{
    CompilerKitVisitor* visitor;
    GObject *regex;
    g_type_init();
    
    visitor = regex_printer();
    
    /** @todo Briefly show how to use the methods in CompilerKitVisitor to accomplish the task. */
    regex = G_OBJECT(compilerkit_kleene_star_new (G_OBJECT(compilerkit_alternation_new(G_OBJECT(compilerkit_symbol_new('a')),
                                                                    G_OBJECT(compilerkit_concatenation_new(
                                                                        G_OBJECT(compilerkit_symbol_new('a')),
                                                                        G_OBJECT(compilerkit_symbol_new('b')))
                                                                    ))
                                        ))); 
    compilerkit_visitor_visit (visitor, regex);
//    printf ("hi");
    g_object_unref (visitor);
}