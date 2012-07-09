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
#ifndef INCLUDE_CompilerKit_alternation_h__
#define INCLUDE_CompilerKit_alternation_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_ALTERNATION                  (compilerkit_alternation_get_type ())
#define COMPILERKIT_ALTERNATION(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternation))
#define COMPILERKIT_IS_ALTERNATION(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_ALTERNATION))
#define COMPILERKIT_ALTERNATION_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternationClass))
#define COMPILERKIT_IS_ALTERNATION_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_ALTERNATION))
#define COMPILERKIT_ALTERNATION_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternationClass))

typedef struct _CompilerKitAlternationPrivate CompilerKitAlternationPrivate;

/**
 * @struct CompilerKitAlternation
 * An alternation struct. 
 *
 * If `a` is a regular expression, and `b` is a regular expression, then alternation `a|b` is a regular expression that matches `a` or `b`.
 * @see #_CompilerKitAlternationPrivate for private fields.
 * @see #CompilerKitAlternationClass for virtual public methods.
 * @example alternation-demo.c
 * This is an example of how to use the CompilerKitAlternation struct.
 */
typedef struct _CompilerKitAlternation
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** Opaque pointer to private fields */
  CompilerKitAlternationPrivate *priv;
} CompilerKitAlternation;

/**
 * @struct CompilerKitAlternationClass
 * 
 * This struct declares the virtual public methods (there aren't any).
 * @see #CompilerKitAlternation for a list of fields.
 */
typedef struct _CompilerKitAlternationClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;
} CompilerKitAlternationClass;

/**
 * @fn compilerkit_alternation_get_type
 * Returns the runtime type information for CompilerKitAlternation. Macro COMPILERKIT_TYPE_ALTERNATION uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_alternation_get_type (void);

/** Public method function prototypes */
GObject* compilerkit_alternation_new (GObject *left, GObject *right);
GObject* compilerkit_alternation_vlist_new (GObject *left, GObject *right, ...);
GObject* compilerkit_alternation_get_left (CompilerKitAlternation *self);
GObject* compilerkit_alternation_get_right (CompilerKitAlternation *self);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_alternation_h__ */