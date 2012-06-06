#include <stdio.h>
#include "CompilerKit.h"

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm;
    g_type_init();
    
    fsm = compilerkit_FSM_new();
    
#ifdef G_OS_WIN32
    printf ("Hello, Windows!");
#endif
#ifdef G_OS_UNIX
    printf ("Hello, Unix!\n");
#endif
//    compilerkit_FSM_add_transition (fsm, "A", "B");

    g_object_unref (fsm);
}