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

#include "CompilerKit/automata.h"
#include "CompilerKit/nfa.h"
#include "CompilerKit/dfa.h"

#define NULL_TRANSITION '?' /**< The character we'll use to represent the lambda transition. */

/** compilerkit_make_deterministic converts a non-deterministic finite automaton into a deterministic finite automaton using subset construction.
 * 
 * *Each state of a DFA represents a set of the original NFA's states, the states of DFA returned from this function are represented as comma-separated strings. 
 * *The constant NULL_TRANSITION is used to represent the lambda, or empty string.
 * *Beware of anything beyond utf-8 (ASCII).
 *
 * @param nfa the nfa to be transformed. Should be a CompilerKitnfa object cast to CompilerKitFSM.
 * @param vocab a GList containig the characters that make up the automaton's vocabulary. See make-deterministic-demo.c for an example.
 * @return a CompilerKitdfa cast to CompilerKitFSM.
**/
CompilerKitFSM *compilerkit_make_deterministic (CompilerKitFSM *nfa, GList *vocab);

//nothing to see past here. See Fischer, Charles. Crafting A Compiler. Menlo Park, Calif.: Benjamin/Cummings, 1988. Print. page 95 for details of the algorithm.

/**compilerkit_close
 * 
**/
GList *_compilerkit_close (GList *states, CompilerKitFSM *nfa, CompilerKitFSM *dfa);

/**compilerkit_record_state
 * 
**/
gchar *_compilerkit_record_state (GList *states, CompilerKitFSM *nfa, CompilerKitFSM *dfa, GList **worklist);

/**compilerkit_set_dfa_accepting_states
 * Set the accepting states of a DFA. Accepting states of the DFA are any states containing an accepting state from the NFA. 
**/
void _compilerkit_set_dfa_accepting_states (CompilerKitFSM *nfa, CompilerKitFSM *dfa);

/**compilerkit_get_nfa_states 
 * Takes a comma-separated string (representing a set of states from an NFA and a state in a DFA) and returns a list of pointers to the original NFA states.
**/
GList *_compilerkit_get_nfa_states (gchar *dfaState, CompilerKitFSM *nfa);

/**compilerkit_get_dfa_state
 * Sorts a list of NFA states and concatenates them into a comma-separated string to represent a state in a DFA.
**/
GList *_compilerkit_get_dfa_state (GList *nfaStates);
