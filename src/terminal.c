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
#include "CompilerKit/terminal.h"
#define COMPILERKIT_TERMINAL_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_TERMINAL, CompilerKitTerminalPrivate))
G_DEFINE_TYPE(CompilerKitTerminal, compilerkit_terminal, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_terminal_finalize (GObject* object);
static void compilerkit_terminal_dispose (GObject* object);

/**
 * @struct _CompilerKitTerminalPrivate
 * The private fields of the CompilerKitTerminal struct.
 * 
 * @see #CompilerKitTerminal
 */
struct _CompilerKitTerminalPrivate
{
    /** @todo Declare private members here */
    GObject *content;
};

/**
 * compilerkit_terminal_class_init:
 * @fn compilerkit_terminal_class_init
 * Initializes the CompilerKitTerminalClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitTerminalClass to initialize
 * @return void
 */
static void
compilerkit_terminal_class_init (CompilerKitTerminalClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitTerminalPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_terminal_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_terminal_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_terminal_init:
 * @fn compilerkit_terminal_init 
 * Initializes the CompilerKitTerminal instance.
 * @pre self is not NULL.
 * @param CompilerKitTerminal to initialize
 * @return void
 */
static void
compilerkit_terminal_init (CompilerKitTerminal *self)
{
    CompilerKitTerminalPrivate *priv;

    self->priv = priv = COMPILERKIT_TERMINAL_GET_PRIVATE (self);

    priv->content = NULL;
}

/**
 * compilerkit_terminal_new:
 * @fn compilerkit_terminal_new
 * Construct a CompilerKitTerminal instance.
 * @pre None
 * @param GObject* Content of the terminal.
 * @return A new CompilerKitTerminal struct.
 * @memberof CompilerKitTerminal
 */
GObject *compilerkit_terminal_new (GObject *content)
{
	CompilerKitTerminal *term = COMPILERKIT_TERMINAL (g_object_new (COMPILERKIT_TYPE_TERMINAL, NULL));
    term->priv->content = content;
    return G_OBJECT(term);
}

/**
 * compilerkit_terminal_finalize:
 * @fn compilerkit_terminal_finalize
 * Reverse what compilerkit_terminal_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_terminal_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_terminal_parent_class)->finalize (object);
}

/**
 * compilerkit_terminal_dispose:
 * @fn compilerkit_terminal_dispose
 * Reverse what compilerkit_terminal_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_terminal_dispose (GObject* object)
{
    CompilerKitTerminal *self = COMPILERKIT_TERMINAL (object);
    CompilerKitTerminalPrivate* priv;

    priv = COMPILERKIT_TERMINAL_GET_PRIVATE (self);

    /** @todo Deallocate memory as necessary */
    g_object_unref (priv->content);

    G_OBJECT_CLASS (compilerkit_terminal_parent_class)->dispose (object);
}

/**
 * compilerkit_terminal_get_content:
 * @fn compilerkit_terminal_get_content
 * Return the "content" of a terminal.
 * @pre CompilerKitTerminal* is not NULL.
 * @param CompilerKitTerminal* A CompilerKitTerminal struct.
 * @return GObject* Content of the terminal.
 * @memberof CompilerKitTerminal
 */
GObject *compilerkit_terminal_get_content (CompilerKitTerminal *self)
{
    return self->priv->content;
}