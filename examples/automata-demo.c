#include <stdio.h>
#include "CompilerKit.h"

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm;
    g_type_init();
    
    fsm = compilerkit_FSM_new();

    compilerkit_FSM_set_start_state (fsm, "A");
    compilerkit_FSM_add_transition (fsm, "A", "B", 'd');
    compilerkit_FSM_add_transition (fsm, "B", "C", 'e');
    compilerkit_FSM_add_transition (fsm, "C", "D", 'm');
    compilerkit_FSM_add_transition (fsm, "D", "E", 'o');
    compilerkit_FSM_add_accepting_state (fsm, "E");
    
    g_assert (compilerkit_FSM_match (fsm, "demo"));

    g_object_unref (fsm);
}