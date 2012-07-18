#include "CompilerKit.h"

/** The following program creates concatenation objects in multiple ways showing the different behaviors. This also shows how to de-reference a GObject */

int main (int argc, char ** argv)
{
    GObject *concatenation;
	GObject *left;
	GObject *right;
    g_type_init();
    
	//Creating a concatenation with 2 symbols
    concatenation = compilerkit_concatenation_new(compilerkit_symbol_new('a'),compilerkit_symbol_new('b'));

	//Getting the left and right side of the concatenation
    left = compilerkit_concatenation_get_left(COMPILERKIT_CONCATENATION(concatenation));
    right = compilerkit_concatenation_get_right(COMPILERKIT_CONCATENATION(concatenation));

    g_object_unref (concatenation); //Also de-references the parts (left and right)
	
	//Creating a concatenation with a symbol and an EmptySet. This will return an EmptySet object
	concatenation = compilerkit_concatenation_new(compilerkit_symbol_new('a'),compilerkit_empty_set_get_instance ());

    g_object_unref (concatenation); //Also de-references the parts (left and right)
	
	//Creating a concatenation with an EmptyString and a symbol. This will return the symbol in a symbol object
	concatenation = compilerkit_concatenation_new(compilerkit_empty_string_get_instance (),compilerkit_symbol_new('a'));

    g_object_unref (concatenation); //Also de-references the parts (left and right)
}
