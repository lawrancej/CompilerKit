#include "CompilerKit.h"

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    GObject *alternationOne;
    GObject *alternationTwo;
    GObject *left;
    GObject *right;
	GObject *subAlternation;
	
    g_type_init();
    
    alternationOne = compilerkit_alternation_new(compilerkit_symbol_new('a'),compilerkit_symbol_new('b')); // creates an alternation ('a' | 'b')
	alternationTwo = compilerkit_alternation_vlist_new(compilerkit_symbol_new('c'), compilerkit_symbol_new('d'), compilerkit_symbol_new('e'), NULL); //NULL terminated list of at least 2 GObjects
																																					 //creates an alternation (('c' | 'd') | 'e')

	left = compilerkit_alternation_get_left(alternationOne); //returns the symbol 'a'
	right = compilerkit_alternation_get_right(alternationOne); //returns the symbol 'b'
	
	subAlternation = compilerkit_alternation_get_left(alternationTwo); //returns the alternation ('c' | 'd')
	right = compilerkit_alternation_get_right(alternationTwo); //returns the symbol 'e'
	
    g_object_unref (alternationOne);
    g_object_unref (alternationTwo);
}
