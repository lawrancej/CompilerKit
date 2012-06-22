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
#include "CompilerKit/nonterminal.h"
#define COMPILERKIT_NONTERMINAL_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_NONTERMINAL, CompilerKitNonterminalPrivate))
G_DEFINE_TYPE(CompilerKitNonterminal, compilerkit_nonterminal, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_nonterminal_finalize (GObject* object);
static void compilerkit_nonterminal_dispose (GObject* object);

/**
 * @struct _CompilerKitNonterminalPrivate
 * The private fields of the CompilerKitNonterminal struct.
 * 
 * @see #CompilerKitNonterminal
 */
struct _CompilerKitNonterminalPrivate
{
    /** The name of the nonterminal */
    gchar *name;
};

/**
 * compilerkit_nonterminal_class_init:
 * @fn compilerkit_nonterminal_class_init
 * Initializes the CompilerKitNonterminalClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitNonterminalClass to initialize
 * @return void
 */
static void
compilerkit_nonterminal_class_init (CompilerKitNonterminalClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitNonterminalPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_nonterminal_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_nonterminal_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_nonterminal_init:
 * @fn compilerkit_nonterminal_init 
 * Initializes the CompilerKitNonterminal instance.
 * @pre self is not NULL.
 * @param CompilerKitNonterminal to initialize
 * @return void
 */
static void
compilerkit_nonterminal_init (CompilerKitNonterminal *self)
{
  CompilerKitNonterminalPrivate *priv;

  self->priv = priv = COMPILERKIT_NONTERMINAL_GET_PRIVATE (self);

  priv->name = NULL;
}

/**
 * compilerkit_nonterminal_new:
 * @fn compilerkit_nonterminal_new
 * @memberof CompilerKitNonterminal
 * Construct a CompilerKitNonterminal instance.
 * @pre Parameter name is not NULL.
 * @param char* Name of the nonterminal
 * @return A new CompilerKitNonterminal struct.
 */
CompilerKitNonterminal* compilerkit_nonterminal_new (gchar *name)
{
	CompilerKitNonterminal *result = COMPILERKIT_NONTERMINAL (g_object_new (COMPILERKIT_TYPE_NONTERMINAL, NULL));
    result->priv->name = name;
    return result;
}

/**
 * compilerkit_nonterminal_finalize:
 * @fn compilerkit_nonterminal_finalize
 * Reverse what compilerkit_nonterminal_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_nonterminal_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_nonterminal_parent_class)->finalize (object);
}

/**
 * compilerkit_nonterminal_dispose:
 * @fn compilerkit_nonterminal_dispose
 * Reverse what compilerkit_nonterminal_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_nonterminal_dispose (GObject* object)
{
  CompilerKitNonterminal *self = COMPILERKIT_NONTERMINAL (object);
  CompilerKitNonterminalPrivate* priv;

  priv = COMPILERKIT_NONTERMINAL_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_nonterminal_parent_class)->dispose (object);
}

/**
 * compilerkit_nonterminal_get_name:
 * @fn compilerkit_nonterminal_get_name
 * @memberof CompilerKitNonterminal
 * Return the name of the nonterminal.
 * @pre The parameter self is not NULL.
 * @param CompilerKit* A pointer to the nonterminal.
 * @return The name of the nonterminal.
 */
char *compilerkit_nonterminal_get_name(CompilerKitNonterminal *self)
{
    return self->priv->name;
}