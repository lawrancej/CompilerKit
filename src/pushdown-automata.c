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
#include "CompilerKit/pushdown-automata.h"
#define COMPILERKIT_PUSHDOWN_AUTOMATA_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_PUSHDOWN_AUTOMATA, CompilerKitPushdownAutomataPrivate))
G_DEFINE_TYPE(CompilerKitPushdownAutomata, compilerkit_pushdown_automata, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_pushdown_automata_finalize (GObject* object);
static void compilerkit_pushdown_automata_dispose (GObject* object);

/**
 * @struct _CompilerKitPushdownAutomataPrivate
 * The private fields of the CompilerKitPushdownAutomata struct.
 * 
 * @see #CompilerKitPushdownAutomata
 */
struct _CompilerKitPushdownAutomataPrivate
{
/** @todo Declare private members here */

int i;
};

/**
 * compilerkit_pushdown_automata_class_init:
 * @fn compilerkit_pushdown_automata_class_init
 * Initializes the CompilerKitPushdownAutomataClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitPushdownAutomataClass to initialize
 * @return void
 */
static void
compilerkit_pushdown_automata_class_init (CompilerKitPushdownAutomataClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitPushdownAutomataPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_pushdown_automata_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_pushdown_automata_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_pushdown_automata_init:
 * @fn compilerkit_pushdown_automata_init 
 * Initializes the CompilerKitPushdownAutomata instance.
 * @pre self is not NULL.
 * @param CompilerKitPushdownAutomata to initialize
 * @return void
 */
static void
compilerkit_pushdown_automata_init (CompilerKitPushdownAutomata *self)
{
  CompilerKitPushdownAutomataPrivate *priv;

  self->priv = priv = COMPILERKIT_PUSHDOWN_AUTOMATA_GET_PRIVATE (self);

  /** @todo Initialize public fields */
  // self->public_field = some_value;

  /** @todo Initialize private fields */
  // priv->member = whatever;
}

/**
 * compilerkit_pushdown_automata_new:
 * @fn compilerkit_pushdown_automata_new
 * @memberof CompilerKitPushdownAutomata
 * Construct a CompilerKitPushdownAutomata instance.
 * @pre None
 * @param None
 * @return A new CompilerKitPushdownAutomata struct.
 */
CompilerKitPushdownAutomata* compilerkit_pushdown_automata_new (void)
{
	return COMPILERKIT_PUSHDOWN_AUTOMATA (g_object_new (COMPILERKIT_TYPE_PUSHDOWN_AUTOMATA, NULL));
}

/**
 * compilerkit_pushdown_automata_finalize:
 * @fn compilerkit_pushdown_automata_finalize
 * Reverse what compilerkit_pushdown_automata_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_pushdown_automata_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_pushdown_automata_parent_class)->finalize (object);
}

/**
 * compilerkit_pushdown_automata_dispose:
 * @fn compilerkit_pushdown_automata_dispose
 * Reverse what compilerkit_pushdown_automata_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_pushdown_automata_dispose (GObject* object)
{
  CompilerKitPushdownAutomata *self = COMPILERKIT_PUSHDOWN_AUTOMATA (object);
  CompilerKitPushdownAutomataPrivate* priv;

  priv = COMPILERKIT_PUSHDOWN_AUTOMATA_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_pushdown_automata_parent_class)->dispose (object);
}