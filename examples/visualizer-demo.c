#include <stdio.h>
#include "CompilerKit.h"

// Build up the state machine. Should match "fsm" or "demo", separated by (but not ending with) spaces.
CompilerKitFSM *state_machine ()
{
    CompilerKitFSM* fsm;

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
    return fsm;
}

// Print out the states
void print_states(CompilerKitFSM *fsm)
{
    GList *list;

    printf ("states: ");
    list = compilerkit_FSM_get_states (fsm);
    while (list) {
        printf ((compilerkit_FSM_is_accepting_state(fsm, list->data) ? "(%s) " : "%s "), list->data);
        list = g_list_next(list);
    }
    printf ("\n");
    g_list_free (list);
}

void compilerkit_FSM_graphviz_render (CompilerKitFSM *fsm) {
    FILE *fp;
    GList *states, *transitions;
    gchar character;
    gchar* state, *new_state;

    fp = fopen("visualizer-demo.dot", "w");
    
    /* Set up start and accepting state node styles */
    fprintf(fp, "digraph NFA {\nrankdir=LR;\n");
    fprintf(fp, "node [style=invisible]; state_start;\n");
    fprintf(fp, "node [style=solid,shape=doublecircle];");
	
    /* Traverse through accepting states */
	states = compilerkit_FSM_get_accepting_states(fsm);
    while (states) {
        fprintf(fp, " state_");
        fprintf(fp, "%s", (gchar*)states->data );
        states = g_list_next(states);
    }

    fprintf(fp, ";\nnode [shape=circle];\n");
    fprintf(fp, "state_start -> state_%s;\n", compilerkit_FSM_get_start_state(fsm));
	
    /* Traverse through transitions */
	transitions = compilerkit_FSM_get_transitions(fsm);
	while(transitions)
	{
		character = ((gchar*)(transitions->data))[0];
        state = ((gchar*)(transitions->data));
        state++;
        new_state = compilerkit_FSM_get_next_state (fsm, state, character);

        fprintf(fp, "state_%s -> state_%s [ label = \"%c\" ];\n", state, new_state, character);
		transitions = g_list_next(transitions);
	}

	fprintf(fp, "}");
	fclose(fp);
}

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm;
	
    g_type_init();
    
    fsm = state_machine();
    print_states(fsm);
    compilerkit_FSM_graphviz_render(fsm);
    
    g_object_unref (fsm);
}