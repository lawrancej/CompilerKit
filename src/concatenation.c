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
#include "CompilerKit/concatenation.h"
#include "CompilerKit/empty-set.h"
#include "CompilerKit/empty-string.h"
#define COMPILERKIT_CONCATENATION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_CONCATENATION, CompilerKitConcatenationPrivate))
G_DEFINE_TYPE(CompilerKitConcatenation, compilerkit_concatenation, G_TYPE_OBJECT);

static void compilerkit_concatenation_finalize (GObject* object);
static void compilerkit_concatenation_dispose (GObject* object);

/**
 * @struct _CompilerKitConcatenationPrivate
 * The private fields of the CompilerKitConcatenation struct.
 * 
 * @see #CompilerKitConcatenation
 */
struct _CompilerKitConcatenationPrivate
{
    /* Left side of the concatenation */
    GObject *left;
    /* Right side of the concatenation */
    GObject *right;
};

/**
 * compilerkit_concatenation_class_init:
 * @fn compilerkit_concatenation_class_init
 * Initializes the CompilerKitConcatenationClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitConcatenationClass to initialize
 * @return void
 */
static void
compilerkit_concatenation_class_init (CompilerKitConcatenationClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitConcatenationPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_concatenation_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_concatenation_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_concatenation_init:
 * @fn compilerkit_concatenation_init 
 * Initializes the CompilerKitConcatenation instance.
 * @pre self is not NULL.
 * @param CompilerKitConcatenation to initialize
 * @return void
 */
static void
compilerkit_concatenation_init (CompilerKitConcatenation *self)
{
  CompilerKitConcatenationPrivate *priv;

  self->priv = priv = COMPILERKIT_CONCATENATION_GET_PRIVATE (self);

  priv->left = NULL;
  priv->right = NULL;
}

/**
 * compilerkit_concatenation_new:
 * @fn compilerkit_concatenation_new
 * @memberof CompilerKitConcatenation
 * Construct a CompilerKitConcatenation instance.
 * @pre GObject* are all non NULL.
 * @param GObject* Left side of concatenation
 * @param GObject* Right side of concatenation
 * @return A new CompilerKitConcatenation struct if concatenation is necessary otherwise return the single element or EmptySet.
 */
GObject *compilerkit_concatenation_new (GObject *left, GObject *right)
{
	CompilerKitConcatenation* result;
	if (COMPILERKIT_IS_EMPTY_SET(left) || COMPILERKIT_IS_EMPTY_SET(right))//if left or right is EmptySet
		return compilerkit_empty_set_new();
	if (COMPILERKIT_IS_EMPTY_STRING(left)) //if left is EmptyString, return right
		return right;
	if (COMPILERKIT_IS_EMPTY_STRING(right)) //if right is EmpltyString, return left
		return left;
	result = COMPILERKIT_CONCATENATION (g_object_new (COMPILERKIT_TYPE_CONCATENATION, NULL));
    result->priv->left = left;
    result->priv->right = right;
    return G_OBJECT(result);
}

/**
 * compilerkit_concatenation_finalize:
 * @fn compilerkit_concatenation_finalize
 * Reverse what compilerkit_concatenation_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_concatenation_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_concatenation_parent_class)->finalize (object);
}

/**
 * compilerkit_concatenation_dispose:
 * @fn compilerkit_concatenation_dispose
 * Reverse what compilerkit_concatenation_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_concatenation_dispose (GObject* object)
{
  CompilerKitConcatenation *self = COMPILERKIT_CONCATENATION (object);
  CompilerKitConcatenationPrivate* priv;

  priv = COMPILERKIT_CONCATENATION_GET_PRIVATE (self);
  
  g_object_unref (priv->left);
  g_object_unref (priv->right);

  G_OBJECT_CLASS (compilerkit_concatenation_parent_class)->dispose (object);
}


/**
 * compilerkit_concatenation_get_left:
 * @fn compilerkit_concatenation_get_left
 * In an concatenation `a|b`, return `a`.
 * @pre CompilerKitConcatenation* is not NULL.
 * @param CompilerKitConcatenation* The concatenation to query.
 * @return The left side of the concatenation.
 */
GObject* compilerkit_concatenation_get_left (CompilerKitConcatenation *self)
{
    return self->priv->left;
}

/**
 * compilerkit_concatenation_get_right:
 * @fn compilerkit_concatenation_get_right
 * In an concatenation `a|b`, return `b`.
 * @pre CompilerKitConcatenation* is not NULL.
 * @param CompilerKitConcatenation* The concatenation to query.
 * @return The right side of the concatenation.
 */
GObject* compilerkit_concatenation_get_right (CompilerKitConcatenation *self)
{
    return self->priv->right;
}
