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
#ifndef INCLUDE_CompilerKit_grammar_h__
#define INCLUDE_CompilerKit_grammar_h__

#include "nonterminal.h"
#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_GRAMMAR                  (compilerkit_grammar_get_type ())
#define COMPILERKIT_GRAMMAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_GRAMMAR, CompilerKitGrammar))
#define COMPILERKIT_IS_GRAMMAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_GRAMMAR))
#define COMPILERKIT_GRAMMAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_GRAMMAR, CompilerKitGrammarClass))
#define COMPILERKIT_IS_GRAMMAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_GRAMMAR))
#define COMPILERKIT_GRAMMAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_GRAMMAR, CompilerKitGrammarClass))

typedef struct _CompilerKitGrammarPrivate CompilerKitGrammarPrivate;

/**
 * @struct CompilerKitGrammar
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitGrammarPrivate for private fields.
 * @see #CompilerKitGrammarClass for virtual public methods.
 * @example grammar-demo.c
 * This is an example of how to use the CompilerKitGrammar struct.
 */
typedef struct _CompilerKitGrammar
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** @todo Define public fields here */

  /** Opaque pointer to private fields */
  CompilerKitGrammarPrivate *priv;

} CompilerKitGrammar;

/**
 * @struct CompilerKitGrammarClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitGrammar for a list of fields.
 */
typedef struct _CompilerKitGrammarClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;

  /** @todo Virtual public methods (function pointers) go here */
  // void (*method_name) (CompilerKitGrammar *self, ...);
  
} CompilerKitGrammarClass;

/**
 * @fn compilerkit_grammar_get_type
 * Returns the runtime type information for CompilerKitGrammar. Macro COMPILERKIT_TYPE_GRAMMAR uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_grammar_get_type (void);

/** Public method function prototypes 
 * @todo Add function prototypes here for both virtual and non-virtual public methods.
 * @see http://developer.gnome.org/gobject/stable/howto-gobject-methods.html
 */
CompilerKitGrammar *compilerkit_grammar_new (CompilerKitNonterminal *start, ...);
GList *compilerkit_grammar_nonterminals (CompilerKitGrammar *grammar);
GList *compilerkit_grammar_productions (CompilerKitGrammar *grammar);
GList *compilerkit_grammar_productions_for (CompilerKitGrammar *grammar, CompilerKitNonterminal *variable);
CompilerKitNonterminal *compilerkit_grammar_get_start (CompilerKitGrammar *grammar);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_grammar_h__ */