#include <stdio.h>
#include "CompilerKit.h"
#include "CompilerKit/make-deterministic.h"

// Build up the NFA
CompilerKitFSM *create_nfa (GList **vocab)
{
    CompilerKitFSM* nfa; // Creates pointer for nfa
    
    nfa = COMPILERKIT_FSM(compilerkit_nfa_new());  // Calls the constructor for the nfa
    compilerkit_FSM_set_start_state(nfa, "1");
    compilerkit_FSM_add_transition (nfa, "1", "1", 'b');
    compilerkit_FSM_add_transition (nfa, "1", "2", '?');
    compilerkit_FSM_add_transition (nfa, "1", "3", 'a');
    compilerkit_FSM_add_transition (nfa, "2", "4", 'a');
    compilerkit_FSM_add_transition (nfa, "3", "4", 'b');
    compilerkit_FSM_add_transition (nfa, "4", "5", 'a');
    compilerkit_FSM_add_transition (nfa, "4", "5", 'b');
    compilerkit_FSM_add_transition (nfa, "2", "5", 'a');
    compilerkit_FSM_add_accepting_state (nfa, "5");

    *vocab = g_list_append (*vocab, 'a');
    *vocab = g_list_append (*vocab, 'b');

    return nfa;
}

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

/** @todo Describe what task main will accomplish. */
int main (int argc, char ** argv)
{
    CompilerKitFSM* nfa;
    CompilerKitFSM* dfa;
    // Initialize GObject type system.
    // Allow us to query the types of an object.
    // Only needs to be called once, Test suite already calls it and is not necessary there.
    g_type_init(); 

    GList *vocab = NULL;    

    nfa = create_nfa (&vocab);
    print_states(nfa);

    dfa = compilerkit_make_deterministic (nfa, vocab);
    print_states(dfa);

    printf ("Should match b*a(a|b[a|b]?)? ");
    match_string(dfa);
    
    g_object_unref (nfa); // Decreases the reference count by 1, if count becomes 0, then free memeory.
    g_object_unref (dfa);

}
