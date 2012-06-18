#include <stdio.h>
#include "CompilerKit.h"

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm;
    GList *list;
    char *state;
    gchar buf[20];
    gchar *str;
    g_type_init();
    
    // Build up the state machine
    fsm = compilerkit_FSM_new("A");
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
    compilerkit_FSM_add_accepting_state (fsm, "E");
    compilerkit_FSM_add_accepting_state (fsm, "H");
    
    // Print out the states
    printf ("states: ");
    list = compilerkit_FSM_get_states (fsm);
    while (list) {
        printf ((compilerkit_FSM_is_accepting_state(fsm, list->data) ? "(%s) " : "%s "), list->data);
        list = g_list_next(list);
    }
    printf ("\n");
    g_list_free (list);
    
    // Match a string. Should match "fsm" or "demo", separated by (but not ending with) spaces.
    printf ("Enter a string: ");
    scanf ("%20[^\n]s", buf);
    str = buf;
    state = compilerkit_FSM_get_start_state(fsm);
    while (*str) {
        printf ("%s %c\n", state, *str);
        state = compilerkit_FSM_get_next_state (fsm, state, *str);
        *str++;
    }
    printf ((compilerkit_FSM_is_accepting_state(fsm, state)) ? 
             "Accepted!\n" : "Not accepted!\n");
    
    g_object_unref (fsm);
}