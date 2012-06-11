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
#include "CompilerKit/empty-set.h"
#define COMPILERKIT_EMPTY_SET_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_EMPTY_SET, CompilerKitEmptySetPrivate))
G_DEFINE_TYPE(CompilerKitEmptySet, compilerkit_empty_set, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_empty_set_finalize (GObject* object);
static void compilerkit_empty_set_dispose (GObject* object);

/**
 * @struct _CompilerKitEmptySetPrivate
 * The private fields of the CompilerKitEmptySet struct.
 * 
 * @see #CompilerKitEmptySet
 */
struct _CompilerKitEmptySetPrivate
{
/** @todo Declare private members here */
};

/**
 * compilerkit_empty_set_class_init:
 * @fn compilerkit_empty_set_class_init
 * Initializes the CompilerKitEmptySetClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitEmptySetClass to initialize
 * @return void
 */
static void
compilerkit_empty_set_class_init (CompilerKitEmptySetClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitEmptySetPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_empty_set_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_empty_set_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_empty_set_init:
 * @fn compilerkit_empty_set_init 
 * Initializes the CompilerKitEmptySet instance.
 * @pre self is not NULL.
 * @param CompilerKitEmptySet to initialize
 * @return void
 */
static void
compilerkit_empty_set_init (CompilerKitEmptySet *self)
{
  CompilerKitEmptySetPrivate *priv;

  self->priv = priv = COMPILERKIT_EMPTY_SET_GET_PRIVATE (self);

  /** @todo Initialize public fields */
  // self->public_field = some_value;

  /** @todo Initialize private fields */
  // priv->member = whatever;
}

/**
 * compilerkit_empty_set_new:
 * @fn compilerkit_empty_set_new
 * @memberof CompilerKitEmptySet
 * Construct a CompilerKitEmptySet instance.
 * @pre None
 * @param None
 * @return A new CompilerKitEmptySet struct.
 */
CompilerKitEmptySet* compilerkit_empty_set_new (void)
{
	return COMPILERKIT_EMPTY_SET (g_object_new (COMPILERKIT_TYPE_EMPTY_SET, NULL));
}

/**
 * compilerkit_empty_set_finalize:
 * @fn compilerkit_empty_set_finalize
 * Reverse what compilerkit_empty_set_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_empty_set_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_empty_set_parent_class)->finalize (object);
}

/**
 * compilerkit_empty_set_dispose:
 * @fn compilerkit_empty_set_dispose
 * Reverse what compilerkit_empty_set_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_empty_set_dispose (GObject* object)
{
  CompilerKitEmptySet *self = COMPILERKIT_EMPTY_SET (object);
  CompilerKitEmptySetPrivate* priv;

  priv = COMPILERKIT_EMPTY_SET_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_empty_set_parent_class)->dispose (object);
}