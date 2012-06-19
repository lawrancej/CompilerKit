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
#ifndef INCLUDE_CompilerKit_empty_set_h__
#define INCLUDE_CompilerKit_empty_set_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_EMPTY_SET                  (compilerkit_empty_set_get_type ())
#define COMPILERKIT_EMPTY_SET(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_EMPTY_SET, CompilerKitEmptySet))
#define COMPILERKIT_IS_EMPTY_SET(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_EMPTY_SET))
#define COMPILERKIT_EMPTY_SET_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_EMPTY_SET, CompilerKitEmptySetClass))
#define COMPILERKIT_IS_EMPTY_SET_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_EMPTY_SET))
#define COMPILERKIT_EMPTY_SET_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_EMPTY_SET, CompilerKitEmptySetClass))

typedef struct _CompilerKitEmptySetPrivate CompilerKitEmptySetPrivate;

/**
 * @struct CompilerKitEmptySet
 * An empty set struct.
 *
 * This struct is a tag for the empty set.
 * @see #_CompilerKitEmptySetPrivate for private fields.
 * @see #CompilerKitEmptySetClass for virtual public methods.
 * @example empty-set-demo.c
 * This is an example of how to use the CompilerKitEmptySet struct.
 */
typedef struct _CompilerKitEmptySet
{
  /** Base instance (GObject) */
  GObject parent_instance;

} CompilerKitEmptySet;

/**
 * @struct CompilerKitEmptySetClass
 *
 * This struct declares the virtual public methods of empty set (there aren't any).
 * @see #CompilerKitEmptySet for a list of fields.
 */
typedef struct _CompilerKitEmptySetClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;  
} CompilerKitEmptySetClass;

/**
 * @fn compilerkit_empty_set_get_type
 * Returns the runtime type information for CompilerKitEmptySet. Macro COMPILERKIT_TYPE_EMPTY_SET uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_empty_set_get_type (void);

/** Public method function prototypes */
GObject *compilerkit_empty_set_new (void);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_empty_set_h__ */