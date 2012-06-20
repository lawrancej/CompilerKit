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
#include <stdarg.h>
#define COMPILERKIT_ALTERNATION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternationPrivate))
G_DEFINE_TYPE(CompilerKitAlternation, compilerkit_alternation, G_TYPE_OBJECT);

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
    /** Left side of alternation */
    GObject *left;
    /** Right side of alternation */
    GObject *right;
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

    priv->left = NULL;
    priv->right = NULL;
}

/**
 * compilerkit_alternation_new:
 * @fn compilerkit_alternation_new
 * @memberof CompilerKitAlternation
 * Construct a CompilerKitAlternation instance.
 * @pre GObject* are all non NULL.
 * @param GObject* Left side of alternation
 * @param GObject* Right side of alternation
 * @return A new CompilerKitAlternation struct, cast to GObject*.
 */
GObject *compilerkit_alternation_new (GObject *left, GObject *right)
{
	CompilerKitAlternation *result = COMPILERKIT_ALTERNATION (g_object_new (COMPILERKIT_TYPE_ALTERNATION, NULL));
    result->priv->left = left;
    result->priv->right = right;
    return G_OBJECT(result);
}

/**
 * compilerkit_alternation_vlist_new:
 * @fn compilerkit_alternation_vlist_new
 * @memberof CompilerKitAlternation
 * Construct a CompilerKitAlternation instance.
 * @pre all GObject* until the last one are all non NULL, and the last arg must be NULL.
 * @param GObject* left the first parameter in an alternation
 * @param GObject* right the second parameter in an alternation
 * @param ... Comma separated list of GObject*, terminated by a NULL param
 * @return A new GObject struct.
 */
GObject* compilerkit_alternation_vlist_new (GObject *left, GObject *right, ...)
{
	GObject* first;
	GObject* second;
	va_list args;
	va_start(args,right);
	
	first = compilerkit_alternation_new(left, right);
	
	while(1)
	{
		second = va_arg(args, GObject*);
		if(second == NULL)
		{
			break;
		}
		first = compilerkit_alternation_new(first, second);
	}
	
	va_end(args);

    return G_OBJECT(first);
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
  
  g_object_unref (priv->left);
  g_object_unref (priv->right);

  G_OBJECT_CLASS (compilerkit_alternation_parent_class)->dispose (object);
}

/**
 * compilerkit_alternation_get_left:
 * @fn compilerkit_alternation_get_left
 * @memberof CompilerKitAlternation
 * In an alternation `a|b`, return `a`.
 * @pre CompilerKitAlternation* is not NULL.
 * @param CompilerKitAlternation* The alternation to query.
 * @return The left side of the alternation.
 */
GObject* compilerkit_alternation_get_left (CompilerKitAlternation *self)
{
    return self->priv->left;
}

/**
 * compilerkit_alternation_get_right:
 * @fn compilerkit_alternation_get_right
 * @memberof CompilerKitAlternation
 * In an alternation `a|b`, return `b`.
 * @pre CompilerKitAlternation* is not NULL.
 * @param CompilerKitAlternation* The alternation to query.
 * @return The right side of the alternation.
 */
GObject* compilerkit_alternation_get_right (CompilerKitAlternation *self)
{
    return self->priv->right;
}
