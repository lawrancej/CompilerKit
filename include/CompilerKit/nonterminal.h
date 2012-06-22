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
#ifndef INCLUDE_CompilerKit_nonterminal_h__
#define INCLUDE_CompilerKit_nonterminal_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_NONTERMINAL                  (compilerkit_nonterminal_get_type ())
#define COMPILERKIT_NONTERMINAL(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_NONTERMINAL, CompilerKitNonterminal))
#define COMPILERKIT_IS_NONTERMINAL(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_NONTERMINAL))
#define COMPILERKIT_NONTERMINAL_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_NONTERMINAL, CompilerKitNonterminalClass))
#define COMPILERKIT_IS_NONTERMINAL_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_NONTERMINAL))
#define COMPILERKIT_NONTERMINAL_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_NONTERMINAL, CompilerKitNonterminalClass))

typedef struct _CompilerKitNonterminalPrivate CompilerKitNonterminalPrivate;

/**
 * @struct CompilerKitNonterminal
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitNonterminalPrivate for private fields.
 * @see #CompilerKitNonterminalClass for virtual public methods.
 * @example nonterminal-demo.c
 * This is an example of how to use the CompilerKitNonterminal struct.
 */
typedef struct _CompilerKitNonterminal
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** @todo Define public fields here */

  /** Opaque pointer to private fields */
  CompilerKitNonterminalPrivate *priv;

} CompilerKitNonterminal;

/**
 * @struct CompilerKitNonterminalClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitNonterminal for a list of fields.
 */
typedef struct _CompilerKitNonterminalClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;

  /** @todo Virtual public methods (function pointers) go here */
  // void (*method_name) (CompilerKitNonterminal *self, ...);
  
} CompilerKitNonterminalClass;

/**
 * @fn compilerkit_nonterminal_get_type
 * Returns the runtime type information for CompilerKitNonterminal. Macro COMPILERKIT_TYPE_NONTERMINAL uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_nonterminal_get_type (void);

/** Public method function prototypes */
CompilerKitNonterminal* compilerkit_nonterminal_new (gchar *name);

char *compilerkit_nonterminal_get_name(CompilerKitNonterminal *self);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_nonterminal_h__ */