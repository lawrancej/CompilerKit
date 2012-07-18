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
#ifndef INCLUDE_CompilerKit_token_h__
#define INCLUDE_CompilerKit_token_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_TOKEN                  (compilerkit_token_get_type ())
#define COMPILERKIT_TOKEN(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_TOKEN, CompilerKitToken))
#define COMPILERKIT_IS_TOKEN(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_TOKEN))
#define COMPILERKIT_TOKEN_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_TOKEN, CompilerKitTokenClass))
#define COMPILERKIT_IS_TOKEN_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_TOKEN))
#define COMPILERKIT_TOKEN_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_TOKEN, CompilerKitTokenClass))

typedef struct _CompilerKitTokenPrivate CompilerKitTokenPrivate;

/**
 * @struct CompilerKitToken
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitTokenPrivate for private fields.
 * @see #CompilerKitTokenClass for virtual public methods.
 * @example token-demo.c
 * This is an example of how to use the CompilerKitToken struct.
 */
typedef struct _CompilerKitToken
{
    /** Base instance (GObject) */
    GObject parent_instance;

    /** @todo Define public fields here */

    /** Opaque pointer to private fields */
    CompilerKitTokenPrivate *priv;

} CompilerKitToken;

/**
 * @struct CompilerKitTokenClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitToken for a list of fields.
 */
typedef struct _CompilerKitTokenClass
{
    /** Base class (GObjectClass) */
    GObjectClass parent_class;

    /** @todo Virtual public methods (function pointers) go here */
    // void (*method_name) (CompilerKitToken *self, ...);
} CompilerKitTokenClass;

/**
 * @fn compilerkit_token_get_type
 * Returns the runtime type information for CompilerKitToken. Macro COMPILERKIT_TYPE_TOKEN uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_token_get_type (void);

/** Public method function prototypes 
 * @todo Add function prototypes here for both virtual and non-virtual public methods.
 * @see http://developer.gnome.org/gobject/stable/howto-gobject-methods.html
 */
CompilerKitToken* compilerkit_token_new (void);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_token_h__ */