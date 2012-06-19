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
#include <glib.h>
#include <string.h>

#define COMPILERKIT_FSM_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_FSM, CompilerKitFSMPrivate))

G_DEFINE_TYPE(CompilerKitFSM, compilerkit_FSM, G_TYPE_OBJECT);

/** Private method function prototypes */
static void compilerkit_FSM_finalize (GObject* object);
static void compilerkit_FSM_dispose (GObject* object);
static void compilerkit_FSM_mergeTables(GHashTable* table1, GHashTable* table2);

/**
 * Get the key for a state and transition. (Private function)
 */
static gchar *compilerkit_FSM_get_transition_key (gchar *state, gchar transition)
{
    int key_length = strlen (state) + 1;
    gchar *key = g_malloc (key_length);
    int i = 0;
    key[0] = transition;
    for (i = 1; i < key_length; i++)
        key[i] = *state++;
    return key;
}

/**
 * @struct _CompilerKitFSMPrivate
 * The private fields of the finite state machine.
 * 
 * @see #CompilerKitFSM
 */
struct _CompilerKitFSMPrivate
{
    /** Starting state of the finite automaton. */
    gchar *start;
    /** Set of states (vertices) in the finite automaton. */
    GHashTable *states;
    /** Transitions between states (edges) in the finite automaton. */
    GHashTable *transitions;
    /** If we are in any of these accepting states by the end of a match, then the match succeeds. */
    GHashTable *accept_states;
};

/**
 * compilerkit_FSM_class_init:
 * Initializes the CompilerKitFSMClass struct.
 * @pre klass is not NULL.
 * @param CompilerKitFSMClass to initialize
 * @return void
 */
static void
compilerkit_FSM_class_init (CompilerKitFSMClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitFSMPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_FSM_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_FSM_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_FSM_init:
 * Initializes the CompilerKitFSM struct.
 * @pre self is not NULL.
 * @param CompilerKitFSM to initialize
 * @return void
 */
static void
compilerkit_FSM_init (CompilerKitFSM *self)
{
    CompilerKitFSMPrivate* priv;
    self->priv = priv = COMPILERKIT_FSM_GET_PRIVATE (self);

    /** @todo Initialize hash tables here */
    priv->start = NULL;
    priv->states = g_hash_table_new(g_str_hash, g_str_equal);
    priv->transitions = g_hash_table_new(g_str_hash, g_str_equal);
    priv->accept_states = g_hash_table_new(g_str_hash, g_str_equal);
}

/**
 * compilerkit_FSM_new:
 * Construct a CompilerKitFSM
 * @fn compilerkit_FSM_new
 * @pre None
 * @param None
 * @return A new CompilerKitFSM struct.
 * @memberof CompilerKitFSM
 */
CompilerKitFSM *compilerkit_FSM_new (gchar *start)
{
	CompilerKitFSM *result = COMPILERKIT_FSM (g_object_new (COMPILERKIT_TYPE_FSM, NULL));
    compilerkit_FSM_set_start_state (result, g_strdup(start));
    return result;
}

/**
 * compilerkit_FSM_finalize:
 * Reverse what compilerkit_FSM_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject to finalize
 * @return void
 */
static void
compilerkit_FSM_finalize (GObject* object)
{
	/* Reverse what was allocated by class init */
	G_OBJECT_CLASS (compilerkit_FSM_parent_class)->finalize (object);
}

/**
 * compilerkit_FSM_dispose:
 * Reverse what compilerkit_FSM_init allocated.
 * @fn compilerkit_FSM_dispose
 * @pre GObject is not NULL.
 * @param GObject to dispose.
 * @return void
 */
static void
compilerkit_FSM_dispose (GObject* object)
{
    /* Reverse what was allocated by instance init */
    CompilerKitFSM *self = COMPILERKIT_FSM (object);
    CompilerKitFSMPrivate* priv;

    priv = COMPILERKIT_FSM_GET_PRIVATE (self);

    g_free (priv->start);
    g_hash_table_destroy(priv->states);
    g_hash_table_destroy(priv->transitions);
    g_hash_table_destroy(priv->accept_states);

    G_OBJECT_CLASS (compilerkit_FSM_parent_class)->dispose (object);
}

/**
 * compilerkit_FSM_add_transition:
 * Add a transition to a finite state machine.
 * If the start and end states aren't already in the set of states, this function adds them in.
 * @fn compilerkit_FSM_add_transition
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer.
 * @param gchar*           Start state for the transition.
 * @param gchar*           End state for the transition.
 * @param gchar            The necessary input to make the transition.
 * @return void
 * @memberof CompilerKitFSM
 */
void compilerkit_FSM_add_transition (CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition)
{
    gchar *key;
    g_return_if_fail (COMPILERKIT_IS_FSM (self));

    compilerkit_FSM_add_state (self, from_state);
    compilerkit_FSM_add_state (self, to_state);
    
    /**
      * @todo Let's pretend we're a DFA, since that's simpler to implement for now.
      * This should really be split up into an abstract automaton base class, since DFA and NFA differ on what to do here.
      */
    key = compilerkit_FSM_get_transition_key (from_state, transition);

    g_hash_table_insert (self->priv->transitions, key, to_state);
}

/**
 * compilerkit_FSM_add_accepting_state:
 * Add an accepting state to a finite state machine.
 * @fn compilerkit_FSM_add_accepting_state
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer.
 * @param gchar*           An accepting state.
 * @return void
 * @memberof CompilerKitFSM
 */
void compilerkit_FSM_add_accepting_state (CompilerKitFSM* self, gchar *state)
{
    compilerkit_FSM_add_state (self, state);
    
	g_hash_table_insert(self->priv->accept_states,state, NULL);
}

/**
 * compilerkit_FSM_merge:
 * Copy all states and transitions (but not accepting states) from another CompilerKitFSM into self.
 * @fn compilerkit_FSM_merge
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @param CompilerKitFSM*  The other CompilerKitFSM pointer.
 * @return void
 * @memberof CompilerKitFSM
 */
void compilerkit_FSM_merge (CompilerKitFSM *self, CompilerKitFSM *other)
{
	CompilerKitFSMPrivate* priv = self->priv;
	CompilerKitFSMPrivate* newPriv = other->priv;
	
	compilerkit_FSM_mergeTables(priv->states, newPriv->states);
	compilerkit_FSM_mergeTables(priv->transitions, newPriv->transitions);
}

/**
 * Copy entries from table2 into table1.
 */
static void compilerkit_FSM_mergeTables(GHashTable* table1, GHashTable* table2)
{
	GHashTableIter iter;
	gpointer key, value;

	g_hash_table_iter_init (&iter, table2);
	while (g_hash_table_iter_next (&iter, &key, &value))
	{
		g_hash_table_insert(table1, key, value);
	}
}

/**
 * compilerkit_FSM_add_state:
 * Add a state into the set of states of a finite state machine.
 * @fn compilerkit_FSM_add_state
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @param CompilerKitFSM*  The other CompilerKitFSM pointer.
 * @return void
 * @memberof CompilerKitFSM
 */
void compilerkit_FSM_add_state (CompilerKitFSM* self, gchar *state)
{
    g_assert (self);
    g_assert (state);

	g_hash_table_insert(self->priv->states,state, NULL);
}

/**
 * compilerkit_FSM_has_state:
 * Return whether the state exists.
 * @fn compilerkit_FSM_has_state
 * @pre CompilerKitFSM* is not `NULL`.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @param gchar*           A `state`. (Possibly `NULL`)
 * @return gboolean        Whether the `state` exists.
 * @memberof CompilerKitFSM
 */
gboolean compilerkit_FSM_has_state (CompilerKitFSM *self, gchar *state)
{
    g_assert (self);

    if (!state) return FALSE;
    return g_hash_table_lookup_extended (self->priv->states, state, NULL, NULL);
}

/**
 * compilerkit_FSM_set_start_state:
 * Designate the starting state of a finite state machine.
 * @fn compilerkit_FSM_set_start_state
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @param gchar*           The starting state
 * @return void
 * @memberof CompilerKitFSM
 */
void compilerkit_FSM_set_start_state (CompilerKitFSM* self, gchar *state)
{
    compilerkit_FSM_add_state (self, state);

    g_free (self->priv->start);
    
	self->priv->start = g_strdup (state);
}

/**
 * compilerkit_FSM_get_start_state:
 * Return the starting state of a finite state machine.
 * @fn compilerkit_FSM_get_start_state
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @return gchar*          The start state.
 * @memberof CompilerKitFSM
 */
gchar *compilerkit_FSM_get_start_state (CompilerKitFSM* self)
{
    return self->priv->start;
}

/**
 * compilerkit_FSM_get_accepting_states:
 * Return a GList* of accepting states.
 * @fn compilerkit_FSM_get_accepting_states
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @return GList*          A GList containing all accepting states. Use `g_list_free()` when done using it.
 * @memberof CompilerKitFSM
 */
GList *compilerkit_FSM_get_accepting_states (CompilerKitFSM *self)
{
    return g_hash_table_get_keys (self->priv->accept_states);
}

/**
 * compilerkit_FSM_get_states:
 * Return a GList* of all states.
 * @fn compilerkit_FSM_get_states
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @return GList*          A GList containing all states. Use `g_list_free()` when done using it.
 * @memberof CompilerKitFSM
 */
GList *compilerkit_FSM_get_states (CompilerKitFSM *self)
{
    return g_hash_table_get_keys (self->priv->states);
}

/**
 * compilerkit_FSM_is_accepting_state:
 * Return whether the state is an accepting state.
 * @fn compilerkit_FSM_is_accepting_state
 * @pre CompilerKitFSM* is not `NULL`.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @param gchar*           A `state`. (Possibly `NULL`)
 * @return gboolean        Whether the `state` is accepting. `NULL` states are never accepting.
 * @memberof CompilerKitFSM
 */
gboolean compilerkit_FSM_is_accepting_state (CompilerKitFSM *self, gchar *state)
{
    g_assert (self);
    if (!state) return FALSE;
    return g_hash_table_lookup_extended (self->priv->accept_states, state, NULL, NULL);
}

/**
 * compilerkit_FSM_get_next_state:
 * Return the next state given a state and the transition character.
 * @fn compilerkit_FSM_get_next_state
 * @pre CompilerKitFSM* is not NULL.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (`self`).
 * @param gchar*           A `state`. (Possibly `NULL`).
 * @param gchar            A character.
 * @return gboolean        The next state.
 * @memberof CompilerKitFSM
 */
gchar *compilerkit_FSM_get_next_state (CompilerKitFSM *self, gchar *from_state, gchar transition)
{
    gchar *key;
    g_assert (self);
    if (!from_state) return from_state;
    key = compilerkit_FSM_get_transition_key (from_state, transition);
    return g_hash_table_lookup (self->priv->transitions, key);
}

