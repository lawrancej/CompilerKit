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
#include "CompilerKit/grammar.h"
#define COMPILERKIT_GRAMMAR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_GRAMMAR, CompilerKitGrammarPrivate))
G_DEFINE_TYPE(CompilerKitGrammar, compilerkit_grammar, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_grammar_finalize (GObject* object);
static void compilerkit_grammar_dispose (GObject* object);

/**
 * @struct _CompilerKitGrammarPrivate
 * The private fields of the CompilerKitGrammar struct.
 * 
 * @see #CompilerKitGrammar
 */
struct _CompilerKitGrammarPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    int dummy;
};

/**
 * compilerkit_grammar_class_init:
 * @fn compilerkit_grammar_class_init
 * Initializes the CompilerKitGrammarClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitGrammarClass to initialize
 * @return void
 */
static void
compilerkit_grammar_class_init (CompilerKitGrammarClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitGrammarPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_grammar_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_grammar_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_grammar_init:
 * @fn compilerkit_grammar_init 
 * Initializes the CompilerKitGrammar instance.
 * @pre self is not NULL.
 * @param CompilerKitGrammar to initialize
 * @return void
 */
static void
compilerkit_grammar_init (CompilerKitGrammar *self)
{
  CompilerKitGrammarPrivate *priv;

  self->priv = priv = COMPILERKIT_GRAMMAR_GET_PRIVATE (self);

  /** @todo Initialize public fields */
  // self->public_field = some_value;

  /** @todo Initialize private fields */
  // priv->member = whatever;
}

/**
 * compilerkit_grammar_new:
 * @fn compilerkit_grammar_new
 * @memberof CompilerKitGrammar
 * Construct a CompilerKitGrammar instance.
 * @pre None
 * @param None
 * @return A new CompilerKitGrammar struct.
 */
GObject *compilerkit_grammar_new (void)
{
	return G_OBJECT(COMPILERKIT_GRAMMAR (g_object_new (COMPILERKIT_TYPE_GRAMMAR, NULL)));
}

/**
 * compilerkit_grammar_finalize:
 * @fn compilerkit_grammar_finalize
 * Reverse what compilerkit_grammar_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_grammar_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_grammar_parent_class)->finalize (object);
}

/**
 * compilerkit_grammar_dispose:
 * @fn compilerkit_grammar_dispose
 * Reverse what compilerkit_grammar_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_grammar_dispose (GObject* object)
{
  CompilerKitGrammar *self = COMPILERKIT_GRAMMAR (object);
  CompilerKitGrammarPrivate* priv;

  priv = COMPILERKIT_GRAMMAR_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_grammar_parent_class)->dispose (object);
}