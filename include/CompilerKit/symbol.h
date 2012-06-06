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
#ifndef INCLUDE_CompilerKit_symbol_h__
#define INCLUDE_CompilerKit_symbol_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_SYMBOL                  (compilerkit_symbol_get_type ())
#define COMPILERKIT_SYMBOL(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_SYMBOL, CompilerKitSymbol))
#define COMPILERKIT_IS_SYMBOL(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_SYMBOL))
#define COMPILERKIT_SYMBOL_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_SYMBOL, CompilerKitSymbolClass))
#define COMPILERKIT_IS_SYMBOL_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_SYMBOL))
#define COMPILERKIT_SYMBOL_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_SYMBOL, CompilerKitSymbolClass))

typedef struct _CompilerKitSymbolPrivate CompilerKitSymbolPrivate;

/**
 * @struct CompilerKitSymbol
 * A symbol struct.
 *
 * This struct merely boxes up a single character into a regular expression to match said character.
 * @see #_CompilerKitSymbolPrivate for private fields.
 * @see #CompilerKitSymbolClass for virtual public methods.
 * @example symbol-demo.c
 * This is an example of how to use the CompilerKitSymbol struct.
 */
typedef struct _CompilerKitSymbol
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** Opaque pointer to private fields */
  CompilerKitSymbolPrivate *priv;

} CompilerKitSymbol;

/**
 * @struct CompilerKitSymbolClass
 *
 * This struct declares the virtual public methods of symbol (there aren't any).
 * @see #CompilerKitSymbol for a list of fields.
 */
typedef struct _CompilerKitSymbolClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;

} CompilerKitSymbolClass;

/**
 * @fn compilerkit_symbol_get_type
 * Returns the runtime type information for CompilerKitSymbol. Macro COMPILERKIT_TYPE_SYMBOL uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_symbol_get_type (void);

/** Public method function prototypes  */
GObject *compilerkit_symbol_new (char symbol);
char compilerkit_symbol_get_symbol(CompilerKitSymbol *self);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_symbol_h__ */