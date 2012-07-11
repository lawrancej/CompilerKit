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
	int i, j;
	FILE *fp;
	GList *states, *transitions;


	fp = fopen("visualizer-demo.dot", "w");
	fprintf(fp, "digraph NFA {\nrankdir=LR;\n");
	fprintf(fp, "node [style=invisible]; ");
	fprintf(fp, " state_");
	fprintf(fp, compilerkit_FSM_get_start_state(fsm) );
	fprintf(fp, ";\n");
	fprintf(fp, "node [style=solid,shape=doublecircle,fontsize=2];");
	
	states = compilerkit_FSM_get_accepting_states(fsm);
    while (states) {
		fprintf(fp, " state_\n");
		fprintf(fp, (gchar*)states->data );
        states = g_list_next(states);
    }

	fprintf(fp, ";\nnode [shape=circle];\n");
	printf(" states done\n");
	
	/*
		for (StateCharacter sc : fa.transitions.keySet ()) {
			for (State s : fa.transitions.get (sc)) {
				sb.append ("state_");
				sb.append (sc.s.hashCode ());
				sb.append (" -> ");
				sb.append ("state_");
				sb.append (s.hashCode ());
				sb.append (" [ label = \"");
				sb.append ((sc.c != null) ? sc.c : "λ");
				sb.append ("\" ];\n");
			}
		}
	*/
	
	transitions = compilerkit_FSM_get_transitions(fsm);
	while(transitions)
	{
		printf(" transition %c\n", (transitions->data));
		states = g_hash_table_get_keys((GHashTable*)(transitions->data));
		while(states)
		{
			printf(" + to %c\n", states->data);
			fprintf(fp, "state_");
			fprintf(fp, (gchar*)states->data);
			fprintf(fp, " -> ");
			fprintf(fp, "state_");
			fprintf(fp, (gchar*)transitions->data);
			fprintf(fp, " [ label = \"");
			if(states->data != NULL)
			{
				fprintf(fp, (gchar*)states->data);
			}
			else
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

int main (int argc, char ** argv)
{
    CompilerKitFSM* fsm;
	
    g_type_init();
    
    fsm = state_machine();
    print_states(fsm);
    compilerkit_FSM_graphviz_render(fsm);
    
    g_object_unref (fsm);
}