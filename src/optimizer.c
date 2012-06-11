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
#include "CompilerKit/optimizer.h"
#define COMPILERKIT_OPTIMIZER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_OPTIMIZER, CompilerKitoptimizerPrivate))
G_DEFINE_TYPE(CompilerKitoptimizer, compilerkit_optimizer, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_optimizer_finalize (GObject* object);
static void compilerkit_optimizer_dispose (GObject* object);

/**
 * @struct _CompilerKitoptimizerPrivate
 * The private fields of the CompilerKitoptimizer struct.
 * 
 * @see #CompilerKitoptimizer
 */
struct _CompilerKitoptimizerPrivate
{
/** @todo Declare private members here */
};

/**
 * compilerkit_optimizer_class_init:
 * @fn compilerkit_optimizer_class_init
 * Initializes the CompilerKitoptimizerClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitoptimizerClass to initialize
 * @return void
 */
static void
compilerkit_optimizer_class_init (CompilerKitoptimizerClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitoptimizerPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_optimizer_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_optimizer_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_optimizer_init:
 * @fn compilerkit_optimizer_init 
 * Initializes the CompilerKitoptimizer instance.
 * @pre self is not NULL.
 * @param CompilerKitoptimizer to initialize
 * @return void
 */
static void
compilerkit_optimizer_init (CompilerKitoptimizer *self)
{
  CompilerKitoptimizerPrivate *priv;

  self->priv = priv = COMPILERKIT_OPTIMIZER_GET_PRIVATE (self);

  /** @todo Initialize public fields */
  // self->public_field = some_value;

  /** @todo Initialize private fields */
  // priv->member = whatever;
}

/**
 * compilerkit_optimizer_new:
 * @fn compilerkit_optimizer_new
 * @memberof CompilerKitoptimizer
 * Construct a CompilerKitoptimizer instance.
 * @pre None
 * @param None
 * @return A new CompilerKitoptimizer struct.
 */
CompilerKitoptimizer* compilerkit_optimizer_new (void)
{
	return COMPILERKIT_OPTIMIZER (g_object_new (COMPILERKIT_TYPE_OPTIMIZER, NULL));
}

/**
 * compilerkit_optimizer_finalize:
 * @fn compilerkit_optimizer_finalize
 * Reverse what compilerkit_optimizer_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_optimizer_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_optimizer_parent_class)->finalize (object);
}

/**
 * compilerkit_optimizer_dispose:
 * @fn compilerkit_optimizer_dispose
 * Reverse what compilerkit_optimizer_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_optimizer_dispose (GObject* object)
{
  CompilerKitoptimizer *self = COMPILERKIT_OPTIMIZER (object);
  CompilerKitoptimizerPrivate* priv;

  priv = COMPILERKIT_OPTIMIZER_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_optimizer_parent_class)->dispose (object);
}