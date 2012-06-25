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

/** @todo Write test cases for CompilerKitFSM. */
 
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
    
    /** @todo Test here  */
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

    /** @todo Test here  */
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

int main (int argc, char ** argv)
{
    g_test_init (&argc, &argv, NULL);
    g_type_init ();

    g_test_add_func ("/automata/start-state", test_FSM_start_state);
    g_test_add_func ("/automata/states", test_FSM_states);
    
    g_test_run ();
}