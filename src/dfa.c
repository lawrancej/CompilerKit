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
#include "CompilerKit/dfa.h"

G_DEFINE_TYPE(CompilerKitdfa, compilerkit_dfa, COMPILERKIT_TYPE_FSM);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_dfa_finalize (GObject* object);
static void compilerkit_dfa_dispose (GObject* object);

/**
 * Abstract method defenitions
**/
static void add_transition_impl          (CompilerKitFSM *self, gchar *from_state, gchar *to_state, gchar input);


/**
 * compilerkit_dfa_class_init:
 * @fn compilerkit_dfa_class_init
 * Initializes the CompilerKitdfaClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitdfaClass to initialize
 * @return void
 */
static void
compilerkit_dfa_class_init (CompilerKitdfaClass *klass)
{
    GObjectClass *g_object_class;
    CompilerKitFSMClass * compilerkit_fsm_class;

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);
    compilerkit_fsm_class = COMPILERKIT_FSM_CLASS(klass);

    /**Hook virtual methods to implementations */
    compilerkit_fsm_class->add_transition = &add_transition_impl;
    compilerkit_fsm_class->destroy_transition_val = &g_free;
    
    

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_dfa_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_dfa_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_dfa_init:
 * @fn compilerkit_dfa_init 
 * Initializes the CompilerKitdfa instance.
 * @pre self is not NULL.
 * @param CompilerKitdfa to initialize
 * @return void
 */
static void
compilerkit_dfa_init (CompilerKitdfa *self)
{
    return;
}

/**
 * compilerkit_dfa_new:
 * @fn compilerkit_dfa_new
 * @memberof CompilerKitdfa
 * Construct a CompilerKitdfa instance.
 * @pre None
 * @param None
 * @return A new CompilerKitdfa struct.
 */
CompilerKitdfa* compilerkit_dfa_new ()
{
    CompilerKitdfa *result = COMPILERKIT_DFA (g_object_new (COMPILERKIT_TYPE_DFA, NULL));
    return result;
}

/**
 * compilerkit_dfa_finalize:
 * @fn compilerkit_dfa_finalize
 * Reverse what compilerkit_dfa_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_dfa_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_dfa_parent_class)->finalize (object);
}

/**
 * compilerkit_dfa_dispose:
 * @fn compilerkit_dfa_dispose
 * Reverse what compilerkit_dfa_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_dfa_dispose (GObject* object)
{
    CompilerKitdfa *self = COMPILERKIT_DFA (object);

    /** @todo Deallocate memory as necessary */

    G_OBJECT_CLASS (compilerkit_dfa_parent_class)->dispose (object);
}


void add_transition_impl (CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition)
{
     gchar *key;
    g_return_if_fail (COMPILERKIT_IS_FSM (self));

    compilerkit_FSM_add_state (self, from_state);
    compilerkit_FSM_add_state (self, to_state);

    /**
     *       * @todo Let's pretend we're a DFA, since that's simpler to implement for now.
     *             * This should really be split up into an abstract automaton base class, since DFA and NFA differ on what to do here.
     *                   */

    key = compilerkit_FSM_get_transition_key (from_state, transition);

    compilerkit_FSM_transition_table_insert(self, key, to_state);
}


