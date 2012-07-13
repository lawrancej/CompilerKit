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
#define COMPILERKIT_RANGE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_RANGE, CompilerKitrangePrivate))
G_DEFINE_TYPE(CompilerKitrange, compilerkit_range, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_range_finalize (GObject* object);
static void compilerkit_range_dispose (GObject* object);

/**
 * @struct _CompilerKitrangePrivate
 * The private fields of the CompilerKitrange struct.
 * 
 * @see #CompilerKitrange
 */
struct _CompilerKitrangePrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    int dummy;
};

/**
 * compilerkit_range_class_init:
 * @fn compilerkit_range_class_init
 * Initializes the CompilerKitrangeClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitrangeClass to initialize
 * @return void
 */
static void
compilerkit_range_class_init (CompilerKitrangeClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitrangePrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /** @todo Hook virtual methods to implementations */
    // klass->method = method_implementation;

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_range_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_range_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_range_init:
 * @fn compilerkit_range_init 
 * Initializes the CompilerKitrange instance.
 * @pre self is not NULL.
 * @param CompilerKitrange to initialize
 * @return void
 */
static void
compilerkit_range_init (CompilerKitrange *self)
{
    CompilerKitrangePrivate *priv;

    self->priv = priv = COMPILERKIT_RANGE_GET_PRIVATE (self);

    /** @todo Initialize public fields */
    // self->public_field = some_value;

    /** @todo Initialize private fields */
    // priv->member = whatever;
}

/**
 * compilerkit_range_new:
 * @fn compilerkit_range_new
 * @memberof CompilerKitrange
 * Construct a CompilerKitrange instance.
 * @pre None
 * @param None
 * @return A new CompilerKitrange struct.
 */
CompilerKitrange* compilerkit_range_new (void)
{
	return COMPILERKIT_RANGE (g_object_new (COMPILERKIT_TYPE_RANGE, NULL));
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
    CompilerKitrange *self = COMPILERKIT_RANGE (object);
    CompilerKitrangePrivate* priv;

    priv = COMPILERKIT_RANGE_GET_PRIVATE (self);

    /** @todo Deallocate memory as necessary */

    G_OBJECT_CLASS (compilerkit_range_parent_class)->dispose (object);
}