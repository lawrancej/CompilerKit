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
#include "CompilerKit/range.h"
#define COMPILERKIT_RANGE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_RANGE, CompilerKitRangePrivate))
G_DEFINE_TYPE(CompilerKitRange, compilerkit_range, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_range_finalize (GObject* object);
static void compilerkit_range_dispose (GObject* object);

/**
 * @struct _CompilerKitRangePrivate
 * The private fields of the CompilerKitRange struct.
 * 
 * @see #CompilerKitRange
 */
struct _CompilerKitRangePrivate
{
    GObject *left;
	GObject *right;
};

/**
 * compilerkit_range_class_init:
 * @fn compilerkit_range_class_init
 * Initializes the CompilerKitRangeClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitRangeClass to initialize
 * @return void
 */
static void
compilerkit_range_class_init (CompilerKitRangeClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitRangePrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);


    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_range_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_range_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_range_init:
 * @fn compilerkit_range_init 
 * Initializes the CompilerKitRange instance.
 * @pre self is not NULL.
 * @param CompilerKitRange to initialize
 * @return void
 */
static void
compilerkit_range_init (CompilerKitRange *self)
{
    CompilerKitRangePrivate *priv;

    self->priv = priv = COMPILERKIT_RANGE_GET_PRIVATE (self);

	priv->left = NULL;
	priv->right = NULL;
}

/**
 * compilerkit_range_new:
 * @fn compilerkit_range_new
 * @memberof CompilerKitRange
 * Construct a CompilerKitRange instance.
 * @pre None
 * @param None
 * @return A new CompilerKitRange struct as a GObject.
 */
GObject *compilerkit_range_new (GObject *a, GObject *b)
{
	CompilerKitRange* result = COMPILERKIT_RANGE (g_object_new (COMPILERKIT_TYPE_RANGE, NULL));
	result->priv->left = a;
	result->priv->right = b;
	return G_OBJECT(result);
}

/**
 * compilerkit_range_finalize:
 * @fn compilerkit_range_finalize
 * Reverse what compilerkit_range_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_range_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_range_parent_class)->finalize (object);
}

GObject* compilerkit_range_get_left (CompilerKitRange *self)
{
	return self->priv->left;
}
GObject* compilerkit_range_get_right (CompilerKitRange *self)
{
	return self->priv->right;
}

/**
 * compilerkit_range_dispose:
 * @fn compilerkit_range_dispose
 * Reverse what compilerkit_range_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_range_dispose (GObject* object)
{
    CompilerKitRange *self = COMPILERKIT_RANGE (object);
    CompilerKitRangePrivate* priv;

    priv = COMPILERKIT_RANGE_GET_PRIVATE (self);

    g_object_unref(priv->left);
    g_object_unref(priv->right);

    G_OBJECT_CLASS (compilerkit_range_parent_class)->dispose (object);
}