#include <stdio.h>
#include "CompilerKit.h"

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
    
    /* Construct regex (a|ab)* programmatically. */
    regex = G_OBJECT(compilerkit_kleene_star_new (G_OBJECT(compilerkit_alternation_new(G_OBJECT(compilerkit_symbol_new('a')),
                                                                    G_OBJECT(compilerkit_concatenation_new(
                                                                        G_OBJECT(compilerkit_symbol_new('a')),
                                                                        G_OBJECT(compilerkit_symbol_new('b')))
                                                                    ))
                                        )));
    /* Traverse through the regex structure using the regex_printer. */
    compilerkit_visitor_visit (visitor, regex);

    /* Clean up after ourselves. */
    g_object_unref (visitor);
    g_object_unref (regex);
}