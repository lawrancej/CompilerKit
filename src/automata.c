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

#define COMPILERKIT_FSM_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_FSM, CompilerKitFSMPrivate))

G_DEFINE_TYPE(CompilerKitFSM, compilerkit_FSM, G_TYPE_OBJECT);

/** Private method function prototypes */
static void compilerkit_FSM_finalize (GObject* object);
static void compilerkit_FSM_dispose (GObject* object);
static void real_compilerkit_FSM_add_transition(CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition);
static gboolean real_compilerkit_FSM_match (CompilerKitFSM* self, gchar *str);

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
  GHashTable *acceptStates;
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
  
  /* Hook overridable methods */
  klass->add_transition = real_compilerkit_FSM_add_transition;
  klass->match = real_compilerkit_FSM_match;
  
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
  /** @todo What to do about start state? */
  priv->states = g_hash_table_new(g_direct_hash, g_direct_equal);
  priv->transitions = g_hash_table_new(g_direct_hash, g_direct_equal);
  priv->acceptStates = g_hash_table_new(g_direct_hash, g_direct_equal);
}

/**
 * compilerkit_FSM_new:
 * @fn compilerkit_FSM_new
 * Construct a CompilerKitFSM
 * @pre None
 * @param None
 * @return A new CompilerKitFSM struct.
 * @memberof CompilerKitFSM
 */
CompilerKitFSM* compilerkit_FSM_new (void)
{
	return COMPILERKIT_FSM (g_object_new (COMPILERKIT_TYPE_FSM, NULL));
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
 * @fn compilerkit_FSM_dispose
 * Reverse what compilerkit_FSM_init allocated.
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
  
  /** @todo Deallocate memory as necessary */
  /** @todo What to do about start state? */
  g_hash_table_destroy(priv->states);
  g_hash_table_destroy(priv->transitions);
  g_hash_table_destroy(priv->acceptStates);
  
  G_OBJECT_CLASS (compilerkit_FSM_parent_class)->dispose (object);
}

/**
 * compilerkit_FSM_add_transition:
 * @fn compilerkit_FSM_add_transition
 * Add a transition to a finite state machine.
 * If the start and end states aren't already in the set of states, this function adds them in.
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
    g_return_if_fail (COMPILERKIT_IS_FSM (self));
    COMPILERKIT_FSM_GET_CLASS (self)->add_transition (self, from_state, to_state, transition);
}

/**
 * compilerkit_FSM_match:
 * @fn compilerkit_FSM_match
 * @memberof CompilerKitFSM
 * Match a string with the finite state machine.
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer.
 * @param gchar*           The string to read in.
 * @return TRUE or FALSE. Whether the FSM was in an accepting state by the end of the string.
 */
gboolean compilerkit_FSM_match (CompilerKitFSM* self, gchar *str)
{
    g_return_if_fail (COMPILERKIT_IS_FSM (self));
    return COMPILERKIT_FSM_GET_CLASS (self)->match (self, str);
}

/**
 * compilerkit_FSM_add_accepting_state:
 * @fn compilerkit_FSM_add_accepting_state
 * @memberof CompilerKitFSM
 * Add an accepting state to a finite state machine.
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer.
 * @param gchar*           An accepting state.
 * @return void
 */
void compilerkit_FSM_add_accepting_state (CompilerKitFSM* self, gchar *state)
{
	CompilerKitFSMPrivate* priv = self->priv;
	g_hash_table_add(priv->acceptStates,state);
}

/**
 * compilerkit_FSM_merge:
 * @fn compilerkit_FSM_merge
 * @memberof CompilerKitFSM
 * Copy all states and transitions (but not accepting states) from another CompilerKitFSM into self.
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (self).
 * @param CompilerKitFSM*  The other CompilerKitFSM pointer.
 * @return void
 */
void compilerkit_FSM_merge (CompilerKitFSM *self, CompilerKitFSM *other)
{
	CompilerKitFSMPrivate* priv = self->priv;
	CompilerKitFSMPrivate* newPriv = other->priv;
	
	compilerkit_FSM_mergeTables(priv->states, newPriv->states);
	compilerkit_FSM_mergeTables(priv->transitions, newPriv->transitions);
	compilerkit_FSM_mergeTables(priv->acceptStates, newPriv->acceptStates);
}

void compilerkit_FSM_mergeTables(GHashTable* table1, GHashTable* table2)
{
	GHashTableIter iter;
	gpointer key, value;

	g_hash_table_iter_init (&iter, table2);
	while (g_hash_table_iter_next (&iter, &key, &value))
	{
		g_hash_table_add(table1, key);
	}
}

/**
 * compilerkit_FSM_add_state:
 * @fn compilerkit_FSM_add_state
 * @memberof CompilerKitFSM
 * Add a state into the set of states of a finite state machine.
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (self).
 * @param CompilerKitFSM*  The other CompilerKitFSM pointer.
 * @return void
 */
void compilerkit_FSM_add_state (CompilerKitFSM* self, gchar *state)
{
	CompilerKitFSMPrivate* priv = self->priv;
	g_hash_table_add(priv->states,state);
}

/**
 * compilerkit_FSM_set_start_state:
 * @fn compilerkit_FSM_set_start_state
 * @memberof CompilerKitFSM
 * Designate the starting state of a finite state machine.
 * @pre No NULL parameters.
 * @param CompilerKitFSM*  A CompilerKitFSM pointer (self).
 * @param gchar*           The starting state
 * @return void
*/
void compilerkit_FSM_set_start_state (CompilerKitFSM* self, gchar *state)
{
	CompilerKitFSMPrivate* priv = self->priv;
	priv->start = state;
}

// For virtual methods only, we have a layer of indirection. The actual implementation goes here.
static void real_compilerkit_FSM_add_transition(CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition)
{

}

// For virtual methods only, we have a layer of indirection. The actual implementation goes here.
static gboolean real_compilerkit_FSM_match (CompilerKitFSM* self, gchar *str)
{
    return TRUE;
}
