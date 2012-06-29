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

void render (CompilerKitFSM *fsm) {
	int i, j;
	FILE *fp;
	GList *states, *transitions;
	gchar *current;


	fp = fopen("visualizer-demo.dot", "w");
	fprintf(fp, "digraph NFA {\nrankdir=LR;\n");
	fprintf(fp, "node [style=invisible]; ");
	fprintf(fp, " state_");
	fprintf(fp, compilerkit_FSM_get_start_state(fsm) );
	fprintf(fp, ";\n");
	fprintf(fp, "node [style=solid,shape=doublecircle,fontsize=2];");
	
	states = compilerkit_FSM_get_states(fsm);
    while (states) {
		fprintf(fp, " state_\n");
		fprintf(fp, (gchar*)states->data );
        states = g_list_next(states);
    }

	fprintf(fp, ";\nnode [shape=circle];\n");
	printf(" states done\n");
	
	transitions = compilerkit_FSM_get_transitions(fsm);
	while(transitions)
	{
		states = compilerkit_FSM_get_states((CompilerKitFSM*) transitions->data);
		printf(" transition %c\n", transitions->data);
		while(states)
		{
			printf(" + to %c\n", states->data);
			fprintf(fp, "state_");
			fprintf(fp, (gchar*)states->data);
			fprintf(fp, " -> ");
			fprintf(fp, "state_");
			fprintf(fp, (gchar*)transitions->data);
			fprintf(fp, " [ label = \"");
			if(fsm->priv != NULL)
			{
				fprintf(fp, "λ");
			}
			fprintf(fp, "\" ];\n");
			states = g_list_next(states);
		}
		transitions = g_list_next(transitions);
	}
	
	fprintf(fp, "}");
	fclose(fp);
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
        *str++;
    }
    printf ((compilerkit_FSM_is_accepting_state(fsm, state)) ? 
             "Accepted!\n" : "Not accepted!\n");
}

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm;
    g_type_init();
    
    fsm = state_machine();
    print_states(fsm);
    render(fsm);
    
    g_object_unref (fsm);
}