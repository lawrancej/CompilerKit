#include <stdio.h>
#include "CompilerKit.h"

/** The following shows how to build up a Finite State Machine and search through it. */

// Build up the state machine. Should match "fsm" or "demo", separated by (but not ending with) spaces.
CompilerKitFSM *state_machine ()
{
    CompilerKitFSM* fsm; // Creates pointer for FSM
    
    fsm = compilerkit_FSM_new("A");  // Calls the constructor for the FSM
    printf("Object created\r\n");
//    compilerkit_FSM_set_start_state(fsm, "A");
    compilerkit_FSM_add_transition (fsm, "A", "B", 'd');
    compilerkit_FSM_add_transition (fsm, "A", "F", 'f');
    compilerkit_FSM_add_transition (fsm, "B", "C", 'e');
    compilerkit_FSM_add_transition (fsm, "C", "D", 'm');
    compilerkit_FSM_add_transition (fsm, "D", "E", 'o');
    compilerkit_FSM_add_transition (fsm, "E", "A", ' ');
    compilerkit_FSM_add_transition (fsm, "F", "G", 's');
    compilerkit_FSM_add_transition (fsm, "G", "H", 'm');
    compilerkit_FSM_add_transition (fsm, "H", "A", ' ');
    printf("Transitions added\r\n");
    compilerkit_FSM_add_end_state (fsm, "F");
    compilerkit_FSM_add_end_state (fsm, "E");
    compilerkit_FSM_add_end_state (fsm, "H");
    printf("End states added\r\n");
    return fsm;
}

// Print out the states
void print_states(CompilerKitFSM *fsm)
{
     
}

// Match a string.
void match_string(CompilerKitFSM *fsm)
{
    char *state;
    gchar buf[20];
    gchar *str;

    printf ("Enter a string: ");
    scanf ("%20[^\n]s", buf);
    str = buf;
    state = compilerkit_FSM_get_start_state(fsm);
    while (*str) {
        printf ("%s %c\n", state, *str);
        state = compilerkit_FSM_get_next_state (fsm, state, *str);
	if(state == NULL)
	  break;
        *str++;
    }
    printf ((compilerkit_FSM_is_accepting_state(fsm, state)) ? 
             "Accepted!\n" : "Not accepted!\n");
}

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm;
    // Initialize GObject type system.
    // Allow us to query the types of an object.
    // Only needs to be called once, Test suite already calls it and is not necessary there.
    g_type_init(); 
    
    fsm = state_machine();
    /*print_states(fsm);*/
    match_string(fsm);
    g_object_unref (fsm); // Decreases the reference count by 1, if count becomes 0, then free memeory.
}