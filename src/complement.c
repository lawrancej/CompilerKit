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
#include "CompilerKit/complement.h"
#define COMPILERKIT_COMPLEMENT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_COMPLEMENT, CompilerKitComplementPrivate))
G_DEFINE_TYPE(CompilerKitComplement, compilerkit_complement, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_complement_finalize (GObject* object);
static void compilerkit_complement_dispose (GObject* object);

/**
 * @struct _CompilerKitComplementPrivate
 * The private fields of the CompilerKitComplement struct.
 * 
 * @see #CompilerKitComplement
 */
struct _CompilerKitComplementPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    GObject *node;
};

/**
 * compilerkit_complement_class_init:
 * @fn compilerkit_complement_class_init
 * Initializes the CompilerKitComplementClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitComplementClass to initialize
 * @return void
 */
static void
compilerkit_complement_class_init (CompilerKitComplementClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitComplementPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_complement_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_complement_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_complement_init:
 * @fn compilerkit_complement_init 
 * Initializes the CompilerKitComplement instance.
 * @pre self is not NULL.
 * @param CompilerKitComplement to initialize
 * @return void
 */
static void
compilerkit_complement_init (CompilerKitComplement *self)
{
    CompilerKitComplementPrivate *priv;

    self->priv = priv = COMPILERKIT_COMPLEMENT_GET_PRIVATE (self);

    priv->node = NULL;
}

/**
 * compilerkit_complement_new:
 * @fn compilerkit_complement_new
 * @memberof CompilerKitComplement
 * Construct a CompilerKitComplement instance.
 * @pre None
 * @param GObject* Node to complement.
 * @return A new CompilerKitComplement struct, cast to GObject*.
 */
GObject *compilerkit_complement_new (GObject *node)
{
	CompilerKitComplement *result = COMPILERKIT_COMPLEMENT(g_object_new (COMPILERKIT_TYPE_COMPLEMENT, NULL));
    result->priv->node = node;
    return result;
}

/**
 * compilerkit_complement_finalize:
 * @fn compilerkit_complement_finalize
 * Reverse what compilerkit_complement_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_complement_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_complement_parent_class)->finalize (object);
}

/**
 * compilerkit_complement_dispose:
 * @fn compilerkit_complement_dispose
 * Reverse what compilerkit_complement_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_complement_dispose (GObject* object)
{
    CompilerKitComplement *self = COMPILERKIT_COMPLEMENT (object);
    CompilerKitComplementPrivate* priv;

    priv = COMPILERKIT_COMPLEMENT_GET_PRIVATE (self);

    g_object_unref (priv->node);

    G_OBJECT_CLASS (compilerkit_complement_parent_class)->dispose (object);
}

GObject *compilerkit_complement_get_node (CompilerKitComplement *self)
{
    return self->priv->node;
}