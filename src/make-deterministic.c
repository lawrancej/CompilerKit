/**
 * Copyright (C) 2012 The CompilerKit contributors.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include "CompilerKit/make-deterministic.h"


CompilerKitFSM *compilerkit_make_deterministic (CompilerKitFSM *nfa, GList *vocab) {

    CompilerKitFSM *dfa = COMPILERKIT_FSM (compilerkit_dfa_new());

    GList *nfaStartState = g_list_append (NULL, compilerkit_FSM_get_start_state (nfa));
    GList *worklist = NULL;

    gchar *dfaStartState = _compilerkit_record_state (nfaStartState, nfa, dfa, &worklist);
    compilerkit_FSM_set_start_state (dfa, dfaStartState);
    

    while (worklist) {
       gchar *state = g_list_first (worklist)->data;
       worklist = g_list_remove (worklist, state);

       GList *iter = vocab;
       while (iter) {
           GList *nfaStates = _compilerkit_get_nfa_states (state, nfa);
           GList *nextStates = NULL;

           while (nfaStates) {

               GList *t = compilerkit_FSM_get_next_state (nfa, nfaStates->data, iter->data);

               if (t) {
                   nextStates = g_list_concat (nextStates, g_list_copy(t));
               }
               nfaStates = g_list_next (nfaStates);
           }

           if (nextStates) {
               gchar *successor = _compilerkit_record_state (nextStates, nfa, dfa, &worklist);

               if (successor) {
                   compilerkit_FSM_add_transition (dfa, state, successor, iter->data);
               }

           }

           iter = g_list_next (iter);

           g_list_free (nfaStates);
           g_list_free (nextStates);
       }
    
    }

    _compilerkit_set_dfa_accepting_states (nfa, dfa);

    g_list_free (nfaStartState);
    g_list_free (worklist);

    return dfa;
}

GList *_compilerkit_close (GList *states, CompilerKitFSM *nfa, CompilerKitFSM *dfa) {
    GList *ans = g_list_copy (states);

    gboolean changed = FALSE;

    do {
        changed = FALSE;
        GList *iter = ans;

        while (iter) {
            GList *t = compilerkit_FSM_get_next_state (nfa, ans->data, NULL_TRANSITION);

            while (t) {
                if (!g_list_find_custom (ans, t->data, g_ascii_strcasecmp)) {
                    g_list_append (ans, t->data);
                    changed = TRUE;
                }
                t = g_list_next (t);
            }
            iter = g_list_next (iter);
        }
    } while (changed); 

    return ans;
}

gchar *_compilerkit_record_state (GList *states, CompilerKitFSM *nfa, CompilerKitFSM *dfa, GList **worklist) {	

    GList *newStateSet = _compilerkit_close (states, nfa, dfa);
    gchar *newState = _compilerkit_get_dfa_state (newStateSet);

    if (compilerkit_FSM_has_state (dfa, newState)) {

        return newState;
    } else {
        *worklist = g_list_append (*worklist, newState);
        compilerkit_FSM_add_state (dfa, newState);
    }
    g_list_free (newStateSet);

    return newState;
}

void _compilerkit_set_dfa_accepting_states (CompilerKitFSM *nfa, CompilerKitFSM *dfa) {
    GList *dfaStates = compilerkit_FSM_get_states (dfa);
    GList *nfaAcceptingStates = compilerkit_FSM_get_accepting_states (nfa);

    while (dfaStates) {

        GList *stateSet = _compilerkit_get_nfa_states (dfaStates->data, nfa);

        while (stateSet) {
            if (g_list_find_custom (nfaAcceptingStates, stateSet->data, g_ascii_strcasecmp)) {
                compilerkit_FSM_add_accepting_state (dfa, dfaStates->data);
            }
            stateSet = g_list_next (stateSet);
        }

        g_list_free (stateSet);
        dfaStates = g_list_next (dfaStates);
    }

    g_list_free (dfaStates);
    g_list_free (nfaAcceptingStates);
}

GList *_compilerkit_get_nfa_states (gchar *dfaState, CompilerKitFSM *nfa) {

    GList *ans = NULL;
    gchar **states = g_strsplit (dfaState, ",", -1);
    GList *nfaStates = compilerkit_FSM_get_states (nfa);
    gchar **ptr;

    for (ptr = states; *ptr; ptr++) {

        GList *nfaState = g_list_find_custom (nfaStates, *ptr, g_ascii_strcasecmp);

        if (nfaState) {
            ans = g_list_append (ans, nfaState->data);
        }
    }

    g_list_free(nfaStates);
    g_strfreev(states);
    return ans;
}

GList *_compilerkit_get_dfa_state (GList *nfaStates) {

    g_assert(nfaStates);

    GList *sortedStates = g_list_sort (nfaStates , g_ascii_strcasecmp);
    gchar *newState = g_strdup (sortedStates->data);
    sortedStates = g_list_next (sortedStates);

    while (sortedStates) {
        gchar *buf = g_strconcat (newState, ",", sortedStates->data, NULL);

        g_free(newState);
      
        newState = buf;
        sortedStates = g_list_next (sortedStates);
    }

    return newState;
}
