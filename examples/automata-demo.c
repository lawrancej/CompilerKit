#include <stdio.h>
#include "CompilerKit.h"

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm; //creates pointer for FSM
    g_type_init(); //initializes gobject type system. Allows us to query the types of an object Only needs to be called once, Test suite already calls it and is not necessary there.
    
    fsm = compilerkit_FSM_new(); //Calls the constructor for the FSM

    compilerkit_FSM_set_start_state (fsm, "A");
    compilerkit_FSM_add_transition (fsm, "A", "B", 'd');
    compilerkit_FSM_add_transition (fsm, "B", "C", 'e');
    compilerkit_FSM_add_transition (fsm, "C", "D", 'm');
    compilerkit_FSM_add_transition (fsm, "D", "E", 'o');
    compilerkit_FSM_add_accepting_state (fsm, "E");
    
    compilerkit_FSM_match (fsm, "demo");

    g_object_unref (fsm); //decreases the reference count by 1, if count becomes 0 free memeory.
}