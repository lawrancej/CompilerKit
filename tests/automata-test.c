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
#include "test-suite.h"

/** @todo Write test cases of the form: void test_bar_method (void); */
/** @todo Add function prototypes for all functions into test-suite.h */
/** @todo Add to test-suite.c: g_test_add_func ("/test-automata/test-FSM-method", test_bar_method); */

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
    g_test_message ("Testing FSM set_start_state");
    g_test_timer_start ();
    
    /** @todo Test here  */
    fsm = compilerkit_FSM_new ("constructor");
    g_assert (g_strcmp0 (compilerkit_FSM_get_start_state (fsm), "constructor") == 0);
    compilerkit_FSM_set_start_state (fsm, "start_state");
    
    g_assert (g_strcmp0 (compilerkit_FSM_get_start_state (fsm), "start_state") == 0);
    
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
    g_object_unref (fsm);
}

