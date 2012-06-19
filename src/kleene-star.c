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
#include "CompilerKit/kleene-star.h"
#define COMPILERKIT_KLEENE_STAR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_KLEENE_STAR, CompilerKitKleeneStarPrivate))
G_DEFINE_TYPE(CompilerKitKleeneStar, compilerkit_kleene_star, G_TYPE_OBJECT);

static void compilerkit_kleene_star_finalize (GObject* object);
static void compilerkit_kleene_star_dispose (GObject* object);

/**
 * @struct _CompilerKitKleeneStarPrivate
 * The private fields of the CompilerKitKleeneStar struct.
 * 
 * @see #CompilerKitKleeneStar
 */
struct _CompilerKitKleeneStarPrivate
{
    /** The regular expression to match 0 or more times. */
    GObject *node;
};

/**
 * compilerkit_kleene_star_class_init:
 * @fn compilerkit_kleene_star_class_init
 * Initializes the CompilerKitKleeneStarClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitKleeneStarClass to initialize
 * @return void
 */
static void
compilerkit_kleene_star_class_init (CompilerKitKleeneStarClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitKleeneStarPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_kleene_star_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_kleene_star_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_kleene_star_init:
 * @fn compilerkit_kleene_star_init 
 * Initializes the CompilerKitKleeneStar instance.
 * @pre self is not NULL.
 * @param CompilerKitKleeneStar to initialize
 * @return void
 */
static void
compilerkit_kleene_star_init (CompilerKitKleeneStar *self)
{
    CompilerKitKleeneStarPrivate *priv;

    self->priv = priv = COMPILERKIT_KLEENE_STAR_GET_PRIVATE (self);

    priv->node = NULL;
}

/**
 * compilerkit_kleene_star_new:
 * @fn compilerkit_kleene_star_new
 * @memberof CompilerKitKleeneStar
 * Construct a CompilerKitKleeneStar instance.
 * @pre None
 * @param None
 * @return A new CompilerKitKleeneStar struct, cast to GObject*.
 */
GObject *compilerkit_kleene_star_new (GObject *node)
{
	CompilerKitKleeneStar* result = COMPILERKIT_KLEENE_STAR (g_object_new (COMPILERKIT_TYPE_KLEENE_STAR, NULL));
    result->priv->node = node;
    return G_OBJECT(result);
}

/**
 * compilerkit_kleene_star_finalize:
 * @fn compilerkit_kleene_star_finalize
 * Reverse what compilerkit_kleene_star_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_kleene_star_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_kleene_star_parent_class)->finalize (object);
}

/**
 * compilerkit_kleene_star_dispose:
 * @fn compilerkit_kleene_star_dispose
 * Reverse what compilerkit_kleene_star_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_kleene_star_dispose (GObject* object)
{
    CompilerKitKleeneStar *self = COMPILERKIT_KLEENE_STAR (object);
    CompilerKitKleeneStarPrivate* priv;

    priv = COMPILERKIT_KLEENE_STAR_GET_PRIVATE (self);
  
    g_object_unref (priv->node);

    G_OBJECT_CLASS (compilerkit_kleene_star_parent_class)->dispose (object);
}

/**
 * compilerkit_kleene_star_get_node:
 * @fn compilerkit_kleene_star_get_node
 * @memberof CompilerKitKleeneStar
 * In a Kleene star `a*`, return `a`.
 * @pre CompilerKitKleeneStar* is not NULL.
 * @param CompilerKitKleeneStar* The Kleene star to query.
 * @return The regular expression in the Kleene star.
 */
GObject* compilerkit_kleene_star_get_node (CompilerKitKleeneStar *self)
{
    return self->priv->node;
}
