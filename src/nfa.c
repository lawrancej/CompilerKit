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
#include "CompilerKit/nfa.h"
#define COMPILERKIT_NFA_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_NFA, CompilerKitnfaPrivate))
G_DEFINE_TYPE(CompilerKitnfa, compilerkit_nfa, COMPILERKIT_TYPE_FSM);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_nfa_finalize (GObject* object);
static void compilerkit_nfa_dispose (GObject* object);

/**
 * Abstract method defenitions
**/
static void add_transition_impl          (CompilerKitFSM *self, gchar *from_state, gchar *to_state, gchar input);

/**
 * @struct _CompilerKitnfaPrivate
 * The private fields of the CompilerKitnfa struct.
 * 
 * @see #CompilerKitnfa
 */
struct _CompilerKitnfaPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    int dummy;
};

/**
 * compilerkit_nfa_class_init:
 * @fn compilerkit_nfa_class_init
 * Initializes the CompilerKitnfaClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitnfaClass to initialize
 * @return void
 */
static void
compilerkit_nfa_class_init (CompilerKitnfaClass *klass)
{
    GObjectClass *g_object_class;
    CompilerKitFSMClass * compilerkit_fsm_class;

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);
    compilerkit_fsm_class = COMPILERKIT_FSM_CLASS(klass);

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitnfaPrivate));


    /**Hook virtual methods to implementations */
    compilerkit_fsm_class->add_transition = &add_transition_impl;
    compilerkit_fsm_class->destroy_transition_val = &g_list_free;

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_nfa_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_nfa_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_nfa_init:
 * @fn compilerkit_nfa_init 
 * Initializes the CompilerKitnfa instance.
 * @pre self is not NULL.
 * @param CompilerKitnfa to initialize
 * @return void
 */
static void
compilerkit_nfa_init (CompilerKitnfa *self)
{
    CompilerKitnfaPrivate *priv;

    self->priv = priv = COMPILERKIT_NFA_GET_PRIVATE (self);

    /** @todo Initialize public fields */
    // self->public_field = some_value;

    /** @todo Initialize private fields */
    // priv->member = whatever;
}

/**
 * compilerkit_nfa_new:
 * @fn compilerkit_nfa_new
 * @memberof CompilerKitnfa
 * Construct a CompilerKitnfa instance.
 * @pre None
 * @param None
 * @return A new CompilerKitnfa struct.
 */
CompilerKitnfa* compilerkit_nfa_new ()
{
    CompilerKitnfa *result = COMPILERKIT_NFA (g_object_new (COMPILERKIT_TYPE_NFA, NULL));
    return result;
}

/**
 * compilerkit_nfa_finalize:
 * @fn compilerkit_nfa_finalize
 * Reverse what compilerkit_nfa_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_nfa_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_nfa_parent_class)->finalize (object);
}

/**
 * compilerkit_nfa_dispose:
 * @fn compilerkit_nfa_dispose
 * Reverse what compilerkit_nfa_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_nfa_dispose (GObject* object)
{
    CompilerKitnfa *self = COMPILERKIT_NFA (object);
    CompilerKitnfaPrivate* priv;

    priv = COMPILERKIT_NFA_GET_PRIVATE (self);

    /** @todo Deallocate memory as necessary */

    G_OBJECT_CLASS (compilerkit_nfa_parent_class)->dispose (object);
}

void add_transition_impl (CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition)
{
    gchar *key;
    g_return_if_fail (COMPILERKIT_IS_FSM (self));

    compilerkit_FSM_add_state (self, from_state);
    compilerkit_FSM_add_state (self, to_state);

    key = compilerkit_FSM_get_transition_key (from_state, transition);
    GList *next_states = compilerkit_FSM_get_next_state (self, from_state, transition);

    next_states = g_list_append (next_states, to_state);
    compilerkit_FSM_transition_table_insert (self, key, next_states);
}
