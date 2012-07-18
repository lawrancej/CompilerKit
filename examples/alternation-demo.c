#include "CompilerKit.h"

/** The following program creates concatenation objects in two different ways. The first is with two parameters 'a' and 'b'. The second is with a NULL terminated list with at least 2 parameters. Finally, we de-reference the variables. */

int main (int argc, char ** argv)
{
    GObject *alternationOne;
    GObject *alternationTwo;
    GObject *left;
    GObject *right;
	GObject *left_left;
	GObject *left_right;
	GObject *subAlternation;
	
    g_type_init();
    
    alternationOne = compilerkit_alternation_new(compilerkit_symbol_new('a'),compilerkit_symbol_new('b')); // creates an alternation ('a' | 'b')
	alternationTwo = compilerkit_alternation_vlist_new(compilerkit_symbol_new('c'), compilerkit_symbol_new('d'), compilerkit_symbol_new('e'), NULL); //NULL terminated list of at least 2 GObjects
																																					 //creates an alternation (('c' | 'd') | 'e')

	left = compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(alternationOne)); //returns the symbol 'a'
	right = compilerkit_alternation_get_right(COMPILERKIT_ALTERNATION(alternationOne)); //returns the symbol 'b'
	
	subAlternation = compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(alternationTwo)); //returns the alternation ('c' | 'd')
	left_left = compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(alternationTwo)))); //returns the symbol 'c'
	left_right = compilerkit_alternation_get_right(COMPILERKIT_ALTERNATION(compilerkit_alternation_get_left(COMPILERKIT_ALTERNATION(alternationTwo)))); //returns the symbol 'd'
	right = compilerkit_alternation_get_right(COMPILERKIT_ALTERNATION(alternationTwo)); //returns the symbol 'e'
	
    g_object_unref (alternationOne); //Also de-references the parts (left and right)
    g_object_unref (alternationTwo); //Also de-references the parts (subAlternation, left_left, left_right, and right)
}
