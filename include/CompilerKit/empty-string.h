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
#ifndef INCLUDE_CompilerKit_empty_string_h__
#define INCLUDE_CompilerKit_empty_string_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_EMPTY_STRING                  (compilerkit_empty_string_get_type ())
#define COMPILERKIT_EMPTY_STRING(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_EMPTY_STRING, CompilerKitEmptyString))
#define COMPILERKIT_IS_EMPTY_STRING(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_EMPTY_STRING))
#define COMPILERKIT_EMPTY_STRING_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_EMPTY_STRING, CompilerKitEmptyStringClass))
#define COMPILERKIT_IS_EMPTY_STRING_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_EMPTY_STRING))
#define COMPILERKIT_EMPTY_STRING_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_EMPTY_STRING, CompilerKitEmptyStringClass))

typedef struct _CompilerKitEmptyStringPrivate CompilerKitEmptyStringPrivate;

/**
 * @struct CompilerKitEmptyString
 * An empty string struct.
 *
 * This struct is a tag for the empty string
 * @see #_CompilerKitEmptyStringPrivate for private fields.
 * @see #CompilerKitEmptyStringClass for virtual public methods.
 * @example empty-string-demo.c
 * This is an example of how to use the CompilerKitEmptyString struct.
 */
typedef struct _CompilerKitEmptyString
{
  /** Base instance (GObject) */
  GObject parent_instance;
  
} CompilerKitEmptyString;

/**
 * @struct CompilerKitEmptyStringClass
 *
 * This struct declares the virtual public methods of empty string (there aren't any).
 * @see #CompilerKitEmptyString for a list of fields.
 */
typedef struct _CompilerKitEmptyStringClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;
  
} CompilerKitEmptyStringClass;

/**
 * @fn compilerkit_empty_string_get_type
 * Returns the runtime type information for CompilerKitEmptyString. Macro COMPILERKIT_TYPE_EMPTY_STRING uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_empty_string_get_type (void);

/** Public method function prototypes */
GObject *compilerkit_empty_string_get_instance (void);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_empty_string_h__ */