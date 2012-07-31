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
#ifndef INCLUDE_CompilerKit_concatenation_h__
#define INCLUDE_CompilerKit_concatenation_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_CONCATENATION                  (compilerkit_concatenation_get_type ())
#define COMPILERKIT_CONCATENATION(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_CONCATENATION, CompilerKitConcatenation))
#define COMPILERKIT_IS_CONCATENATION(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_CONCATENATION))
#define COMPILERKIT_CONCATENATION_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_CONCATENATION, CompilerKitConcatenationClass))
#define COMPILERKIT_IS_CONCATENATION_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_CONCATENATION))
#define COMPILERKIT_CONCATENATION_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_CONCATENATION, CompilerKitConcatenationClass))

typedef struct _CompilerKitConcatenationPrivate CompilerKitConcatenationPrivate;

/**
 * @struct CompilerKitConcatenation
 * A concatenation struct.
 *
 * If `a` is a regular expression, and `b` is a regular expression, then `ab` is a regular expression that matches `a` followed by `b`.
 * @see #_CompilerKitConcatenationPrivate for private fields.
 * @see #CompilerKitConcatenationClass for virtual public methods.
 * @example concatenation-demo.c
 * This is an example of how to use the CompilerKitConcatenation struct.
 */
typedef struct _CompilerKitConcatenation
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** Opaque pointer to private fields */
  CompilerKitConcatenationPrivate *priv;

} CompilerKitConcatenation;

/**
 * @struct CompilerKitConcatenationClass
 *
 * This struct declares the virtual public methods of concatenation (there aren't any).
 * @see #CompilerKitConcatenation for a list of fields.
 */
typedef struct _CompilerKitConcatenationClass
{
    /** Base class (GObjectClass) */
    GObjectClass parent_class;
} CompilerKitConcatenationClass;

/**
 * @fn compilerkit_concatenation_get_type
 * Returns the runtime type information for CompilerKitConcatenation. Macro COMPILERKIT_TYPE_CONCATENATION uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_concatenation_get_type (void);

/** Public method function prototypes */
GObject *compilerkit_concatenation_new (GObject *left, GObject *right);
GObject *compilerkit_concatenation_vlist_new (GObject *left, GObject *right, ...);
GObject *compilerkit_concatenation_get_left(CompilerKitConcatenation *self);
GObject *compilerkit_concatenation_get_right(CompilerKitConcatenation *self);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_concatenation_h__ */