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
#include "CompilerKit/symbol.h"
#define COMPILERKIT_SYMBOL_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_SYMBOL, CompilerKitSymbolPrivate))
G_DEFINE_TYPE(CompilerKitSymbol, compilerkit_symbol, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_symbol_finalize (GObject* object);
static void compilerkit_symbol_dispose (GObject* object);

/**
 * @struct _CompilerKitSymbolPrivate
 * The private fields of the CompilerKitSymbol struct.
 * 
 * @see #CompilerKitSymbol
 */
struct _CompilerKitSymbolPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    gunichar symbol;
};

/**
 * compilerkit_symbol_class_init:
 * @fn compilerkit_symbol_class_init
 * Initializes the CompilerKitSymbolClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitSymbolClass to initialize
 * @return void
 */
static void
compilerkit_symbol_class_init (CompilerKitSymbolClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitSymbolPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_symbol_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_symbol_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_symbol_init:
 * @fn compilerkit_symbol_init 
 * Initializes the CompilerKitSymbol instance.
 * @pre self is not NULL.
 * @param CompilerKitSymbol to initialize
 * @return void
 */
static void
compilerkit_symbol_init (CompilerKitSymbol *self)
{
  CompilerKitSymbolPrivate *priv;

  self->priv = priv = COMPILERKIT_SYMBOL_GET_PRIVATE (self);

  priv->symbol = '\0';
}

/**
 * compilerkit_symbol_new:
 * @fn compilerkit_symbol_new
 * @memberof CompilerKitSymbol
 * Construct a CompilerKitSymbol instance.
 * @pre None
 * @param None
 * @return A new CompilerKitSymbol struct, cast to GObject*.
 */
GObject *compilerkit_symbol_new (gunichar symbol)
{
	CompilerKitSymbol *result = COMPILERKIT_SYMBOL (g_object_new (COMPILERKIT_TYPE_SYMBOL, NULL));
    result->priv->symbol = symbol;
    return G_OBJECT(result);
}

/**
 * compilerkit_symbol_finalize:
 * @fn compilerkit_symbol_finalize
 * Reverse what compilerkit_symbol_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_symbol_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_symbol_parent_class)->finalize (object);
}

/**
 * compilerkit_symbol_dispose:
 * @fn compilerkit_symbol_dispose
 * Reverse what compilerkit_symbol_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_symbol_dispose (GObject* object)
{
  CompilerKitSymbol *self = COMPILERKIT_SYMBOL (object);
  CompilerKitSymbolPrivate* priv;

  priv = COMPILERKIT_SYMBOL_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_symbol_parent_class)->dispose (object);
}

/**
 * compilerkit_symbol_get_symbol:
 * @fn compilerkit_symbol_get_symbol
 * @memberof CompilerKitSymbol
 * Return the symbol contained herein.
 * @pre CompilerKitSymbol* is not NULL.
 * @param CompilerKitSymbol* The symbol (a box).
 * @return char The actual symbol.
 */
gunichar compilerkit_symbol_get_symbol(CompilerKitSymbol *self)
{
    return self->priv->symbol;
}
