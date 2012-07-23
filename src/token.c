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
#include "CompilerKit/token.h"
#define COMPILERKIT_TOKEN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_TOKEN, CompilerKitTokenPrivate))
G_DEFINE_TYPE(CompilerKitToken, compilerkit_token, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_token_finalize (GObject* object);
static void compilerkit_token_dispose (GObject* object);

/**
 * @struct _CompilerKitTokenPrivate
 * The private fields of the CompilerKitToken struct.
 * 
 * @see #CompilerKitToken
 */
struct _CompilerKitTokenPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    int dummy;
};

/**
 * compilerkit_token_class_init:
 * @fn compilerkit_token_class_init
 * Initializes the CompilerKitTokenClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitTokenClass to initialize
 * @return void
 */
static void
compilerkit_token_class_init (CompilerKitTokenClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitTokenPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /** @todo Hook virtual methods to implementations */
    // klass->method = method_implementation;

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_token_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_token_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_token_init:
 * @fn compilerkit_token_init 
 * Initializes the CompilerKitToken instance.
 * @pre self is not NULL.
 * @param CompilerKitToken to initialize
 * @return void
 */
static void
compilerkit_token_init (CompilerKitToken *self)
{
    CompilerKitTokenPrivate *priv;

    self->priv = priv = COMPILERKIT_TOKEN_GET_PRIVATE (self);

    /** @todo Initialize public fields */
    // self->public_field = some_value;

    /** @todo Initialize private fields */
    // priv->member = whatever;
}

/**
 * compilerkit_token_new:
 * @fn compilerkit_token_new
 * @memberof CompilerKitToken
 * Construct a CompilerKitToken instance.
 * @pre None
 * @param char* The name of the token
 * @return A new CompilerKitToken struct.
 */
CompilerKitToken* compilerkit_token_new (char *name)
{
	return COMPILERKIT_TOKEN (g_object_new (COMPILERKIT_TYPE_TOKEN, NULL));
}

/**
 * compilerkit_token_finalize:
 * @fn compilerkit_token_finalize
 * Reverse what compilerkit_token_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_token_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_token_parent_class)->finalize (object);
}

/**
 * compilerkit_token_dispose:
 * @fn compilerkit_token_dispose
 * Reverse what compilerkit_token_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_token_dispose (GObject* object)
{
    CompilerKitToken *self = COMPILERKIT_TOKEN (object);
    CompilerKitTokenPrivate* priv;

    priv = COMPILERKIT_TOKEN_GET_PRIVATE (self);

    /** @todo Deallocate memory as necessary */

    G_OBJECT_CLASS (compilerkit_token_parent_class)->dispose (object);
}