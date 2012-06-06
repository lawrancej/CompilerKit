// http://www.ibm.com/developerworks/linux/tutorials/l-glib/section5.html
/*
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

struct _CompilerKitFSMPrivate
{
  // Start state
  gchar *start;
  // Set of states
  GHashTable *states;
  // Transition
  GHashTable *transitions;
  // Accepting states
  GHashTable *acceptStates;
};

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

static void
compilerkit_FSM_init (CompilerKitFSM *self)
{
  CompilerKitFSMPrivate *priv;

  self->priv = priv = COMPILERKIT_FSM_GET_PRIVATE (self);

  /** @todo Initialize hash tables here */
  self->priv->states = g_hash_table_new(g_str_hash, g_str_equal);
}

CompilerKitFSM* compilerkit_FSM_new (void)
{
	return COMPILERKIT_FSM (g_object_new (COMPILERKIT_TYPE_FSM, NULL));
}

static void
compilerkit_FSM_finalize (GObject* object)
{
	/* Reverse what was allocated by class init */
	G_OBJECT_CLASS (compilerkit_FSM_parent_class)->finalize (object);
}

static void
compilerkit_FSM_dispose (GObject* object)
{
  /* Reverse what was allocated by instance init */

  CompilerKitFSM *self = COMPILERKIT_FSM (object);
  CompilerKitFSMPrivate* priv;

  priv = COMPILERKIT_FSM_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_FSM_parent_class)->dispose (object);
}

void compilerkit_FSM_add_transition (CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition)
{
    COMPILERKIT_FSM_CLASS (self)->add_transition (self, from_state, to_state, transition);
}

gboolean compilerkit_FSM_match (CompilerKitFSM* self, gchar *str)
{
    return COMPILERKIT_FSM_CLASS (self)->match (self, str);
}

void compilerkit_FSM_add_accepting_state (CompilerKitFSM* self, gchar *state)
{

}

void compilerkit_FSM_merge (CompilerKitFSM *self, CompilerKitFSM *other)
{

}

void compilerkit_FSM_add_state (CompilerKitFSM* self, gchar *state)
{

}

static void real_compilerkit_FSM_add_transition(CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition)
{

}

static gboolean real_compilerkit_FSM_match (CompilerKitFSM* self, gchar *str)
{
    return TRUE;
}