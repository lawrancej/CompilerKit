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
#include <glib.h>
#include "CompilerKit.h"
#include "test.h"
 
/**
 * test_FSM_start_state:
 * @fn test_FSM_set_start_state
 * Tests `compilerkit_FSM_*_start_state` in CompilerKitFSM struct.
 * @pre None
 * @param None
 * @return void
 */
void test_FSM_start_state (void)
{
    CompilerKitFSM *fsm;
    g_test_message ("Testing FSM start_state");
    g_test_timer_start ();
    
    fsm = compilerkit_FSM_new ("constructor");
    g_assert (g_strcmp0 (compilerkit_FSM_get_start_state (fsm), "constructor") == 0);
    compilerkit_FSM_set_start_state (fsm, "start_state");
    
    g_assert (g_strcmp0 (compilerkit_FSM_get_start_state (fsm), "start_state") == 0);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
    g_object_unref (fsm);
}

/**
 * test_FSM_state:
 * @fn test_FSM_state
 * Tests `compilerkit_FSM_*_state` in CompilerKitFSM struct.
 * @pre None
 * @param None
 * @return void
 */
void test_FSM_states (void)
{
    CompilerKitFSM *fsm;
    g_test_message ("Testing FSM state");
    g_test_timer_start ();

    fsm = compilerkit_FSM_new ("zero");
    compilerkit_FSM_add_state (fsm, "one");
    compilerkit_FSM_add_state (fsm, "two");
    compilerkit_FSM_add_state (fsm, "three");
    
    g_assert (compilerkit_FSM_has_state (fsm, "zero"));
    g_assert (compilerkit_FSM_has_state (fsm, "one"));
    g_assert (compilerkit_FSM_has_state (fsm, "two"));
    g_assert (compilerkit_FSM_has_state (fsm, "three"));
    g_assert (!compilerkit_FSM_has_state (fsm, "four"));
    g_assert (!compilerkit_FSM_has_state (fsm, NULL));
    
    compilerkit_FSM_add_transition (fsm, "zero", "five", '5');
    compilerkit_FSM_add_accepting_state (fsm, "six");
    g_assert (compilerkit_FSM_has_state (fsm, "five"));
    g_assert (compilerkit_FSM_has_state (fsm, "six"));
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
    g_object_unref (fsm);
}

// Build up the state machine. Should match "fsm" or "demo", separated by (but not ending with) spaces.
static CompilerKitFSM *state_machine ()
{
    CompilerKitFSM* fsm; // Creates pointer for FSM
    
    fsm = compilerkit_FSM_new("A");  // Calls the constructor for the FSM
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

void test_FSM_transitions (void)
{
    CompilerKitFSM *fsm = state_machine();    
    char *state;
    gchar *pass = "fsm demo";
    gchar *fail = "FSM";

    g_test_message ("Testing FSM state");
    g_test_timer_start ();

    /* Assert there are indeed 8 unique states in the state machine. */
    g_assert (g_list_length(compilerkit_FSM_get_states(fsm)) == 8);
    
    /* Assert there are indeed 9 transitions in the state machine. */
    g_assert (g_list_length(compilerkit_FSM_get_transitions(fsm)) == 9);

    /* Assert there are indeed 2 acceptings states in the state machine. */
    g_assert (g_list_length(compilerkit_FSM_get_accepting_states(fsm)) == 2);

    /* "fsm demo" should pass */
    state = compilerkit_FSM_get_start_state(fsm);
    while (*pass) {
        state = compilerkit_FSM_get_next_state (fsm, state, *pass);
        *pass++;
    }
    g_assert (compilerkit_FSM_is_accepting_state(fsm, state));

    /* "FSM" should fail */
    state = compilerkit_FSM_get_start_state(fsm);
    while (*fail) {
        state = compilerkit_FSM_get_next_state (fsm, state, *fail);
        *fail++;
    }
    g_assert (!compilerkit_FSM_is_accepting_state(fsm, state));
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
    g_object_unref (fsm);
}