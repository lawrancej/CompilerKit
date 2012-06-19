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
#include "CompilerKit/header.h"
#define COMPILERKIT_BAR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_BAR, CompilerKitBarPrivate))
G_DEFINE_TYPE(CompilerKitBar, compilerkit_bar, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_bar_finalize (GObject* object);
static void compilerkit_bar_dispose (GObject* object);

/**
 * @struct _CompilerKitBarPrivate
 * The private fields of the CompilerKitBar struct.
 * 
 * @see #CompilerKitBar
 */
struct _CompilerKitBarPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    int dummy;
};

/**
 * compilerkit_bar_class_init:
 * @fn compilerkit_bar_class_init
 * Initializes the CompilerKitBarClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitBarClass to initialize
 * @return void
 */
static void
compilerkit_bar_class_init (CompilerKitBarClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitBarPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /** @todo Hook virtual methods to implementations */
    // klass->method = method_implementation;

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_bar_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_bar_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_bar_init:
 * @fn compilerkit_bar_init 
 * Initializes the CompilerKitBar instance.
 * @pre self is not NULL.
 * @param CompilerKitBar to initialize
 * @return void
 */
static void
compilerkit_bar_init (CompilerKitBar *self)
{
    CompilerKitBarPrivate *priv;

    self->priv = priv = COMPILERKIT_BAR_GET_PRIVATE (self);

    /** @todo Initialize public fields */
    // self->public_field = some_value;

    /** @todo Initialize private fields */
    // priv->member = whatever;
}

/**
 * compilerkit_bar_new:
 * @fn compilerkit_bar_new
 * @memberof CompilerKitBar
 * Construct a CompilerKitBar instance.
 * @pre None
 * @param None
 * @return A new CompilerKitBar struct.
 */
CompilerKitBar* compilerkit_bar_new (void)
{
	return COMPILERKIT_BAR (g_object_new (COMPILERKIT_TYPE_BAR, NULL));
}

/**
 * compilerkit_bar_finalize:
 * @fn compilerkit_bar_finalize
 * Reverse what compilerkit_bar_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_bar_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_bar_parent_class)->finalize (object);
}

/**
 * compilerkit_bar_dispose:
 * @fn compilerkit_bar_dispose
 * Reverse what compilerkit_bar_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_bar_dispose (GObject* object)
{
    CompilerKitBar *self = COMPILERKIT_BAR (object);
    CompilerKitBarPrivate* priv;

    priv = COMPILERKIT_BAR_GET_PRIVATE (self);

    /** @todo Deallocate memory as necessary */

    G_OBJECT_CLASS (compilerkit_bar_parent_class)->dispose (object);
}