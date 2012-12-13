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
 * @todo Write test cases, add prototype to `test.h`, call `g_test_add_func` in `test.c:main`
 * A test case for MakeDeterministic should be in a function in this file called: `void test_make_deterministic_case (void);`
 * The prototype for the function `void test_make_deterministic_case (void);` belongs in `test.h`
 * In `test.c:main` add this function: g_test_add_func ("/make-deterministic/case", test_make_deterministic_case);
 * @todo The more test cases the better, until reaching sufficient coverage.
 */

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
    *vocab = g_list_append (*vocab, 'c');

    return nfa;
}

/**
 * test_make_deterministic_end_to_end:
 * @fn test_make_deterministic_end_to_end
 * Runs a complete end to end test of compilerkit_make_deterministic
 * @pre None
 * @param None
 * @return void
 */
void test_make_deterministic_end_to_end (void)
{

    GList *vocab = NULL;

    
    
    g_test_message ("Testing MakeDeterministic case");
    g_test_timer_start ();

    CompilerKitFSM *nfa = create_nfa (&vocab);  

    CompilerKitFSM *dfa = compilerkit_make_deterministic (nfa, vocab);  

    g_object_unref (nfa);
    g_object_unref (dfa);


    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);

   
}
