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
#include "CompilerKit/alternation.h"
#define COMPILERKIT_ALTERNATION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternationPrivate))
G_DEFINE_TYPE(CompilerKitAlternation, compilerkit_alternation, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_alternation_finalize (GObject* object);
static void compilerkit_alternation_dispose (GObject* object);

/**
 * @struct _CompilerKitAlternationPrivate
 * The private fields of the CompilerKitAlternation struct.
 * 
 * @see #CompilerKitAlternation
 */
struct _CompilerKitAlternationPrivate
{
/** @todo Declare private members here */
};

/**
 * compilerkit_alternation_class_init:
 * @fn compilerkit_alternation_class_init
 * Initializes the CompilerKitAlternationClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitAlternationClass to initialize
 * @return void
 */
static void
compilerkit_alternation_class_init (CompilerKitAlternationClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitAlternationPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_alternation_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_alternation_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_alternation_init:
 * @fn compilerkit_alternation_init 
 * Initializes the CompilerKitAlternation instance.
 * @pre self is not NULL.
 * @param CompilerKitAlternation to initialize
 * @return void
 */
static void
compilerkit_alternation_init (CompilerKitAlternation *self)
{
  CompilerKitAlternationPrivate *priv;

  self->priv = priv = COMPILERKIT_ALTERNATION_GET_PRIVATE (self);

  /** @todo Initialize public fields */
  // self->public_field = some_value;

  /** @todo Initialize private fields */
  // priv->member = whatever;
}

/**
 * compilerkit_alternation_new:
 * @fn compilerkit_alternation_new
 * @memberof CompilerKitAlternation
 * Construct a CompilerKitAlternation instance.
 * @pre None
 * @param None
 * @return A new CompilerKitAlternation struct.
 */
CompilerKitAlternation* compilerkit_alternation_new (void)
{
	return COMPILERKIT_ALTERNATION (g_object_new (COMPILERKIT_TYPE_ALTERNATION, NULL));
}

/**
 * compilerkit_alternation_finalize:
 * @fn compilerkit_alternation_finalize
 * Reverse what compilerkit_alternation_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_alternation_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_alternation_parent_class)->finalize (object);
}

/**
 * compilerkit_alternation_dispose:
 * @fn compilerkit_alternation_dispose
 * Reverse what compilerkit_alternation_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_alternation_dispose (GObject* object)
{
  CompilerKitAlternation *self = COMPILERKIT_ALTERNATION (object);
  CompilerKitAlternationPrivate* priv;

  priv = COMPILERKIT_ALTERNATION_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_alternation_parent_class)->dispose (object);
}