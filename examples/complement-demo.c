#include "CompilerKit.h"

/** The following program creates a complement object and descibes how to use it. */

int main (int argc, char ** argv)
{
    GObject* complement;
	GObject* rejectingRegex;
    g_type_init();
    
    complement = compilerkit_complement_new(compilerkit_empty_set_get_instance());//creates a complement object that accepted anything but the given regex
																				  //in this case, it will accept anything except the empty set
    rejectingRegex = compilerkit_complement_get_node(COMPILERKIT_COMPLEMENT(complement));//returns the regex which should be rejected

    g_object_unref (complement); //This also de-references its parts (rejectingRegex)
}
