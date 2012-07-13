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
#ifndef INCLUDE_CompilerKit_range_h__
#define INCLUDE_CompilerKit_range_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_RANGE                  (compilerkit_range_get_type ())
#define COMPILERKIT_RANGE(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_RANGE, CompilerKitrange))
#define COMPILERKIT_IS_RANGE(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_RANGE))
#define COMPILERKIT_RANGE_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_RANGE, CompilerKitrangeClass))
#define COMPILERKIT_IS_RANGE_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_RANGE))
#define COMPILERKIT_RANGE_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_RANGE, CompilerKitrangeClass))

typedef struct _CompilerKitrangePrivate CompilerKitrangePrivate;

/**
 * @struct CompilerKitrange
 * A range struct
 *
 * if a is a symbol and b is a symbol then [a-b] is a regular expression that matches all symbols between a and b
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitrangePrivate for private fields.
 * @see #CompilerKitrangeClass for virtual public methods.
 * @example range-demo.c
 * This is an example of how to use the CompilerKitrange struct.
 */
typedef struct _CompilerKitrange
{
    /** Base instance (GObject) */
    GObject parent_instance;

    /** Opaque pointer to private fields */
    CompilerKitrangePrivate *priv;

} CompilerKitrange;

/**
 * @struct CompilerKitrangeClass
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitrange for a list of fields.
 */
typedef struct _CompilerKitrangeClass
{
    /** Base class (GObjectClass) */
    GObjectClass parent_class;

} CompilerKitrangeClass;

/**
 * @fn compilerkit_range_get_type
 * Returns the runtime type information for CompilerKitrange. Macro COMPILERKIT_TYPE_RANGE uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_range_get_type (void);

/** Public method function prototypes 
 * @todo Add function prototypes here for both virtual and non-virtual public methods.
 * @see http://developer.gnome.org/gobject/stable/howto-gobject-methods.html
 */
CompilerKitrange* compilerkit_range_new (CompilerKitSymbol a, CompilerKitSymbol b);
GObject* compilerkit_range_get+equivelent(CompilerKitRange *self);
CompilerKitSymbol* compilerkit_range_get_left(CompilerKitRange *self);
CompilerKitSymbol* compilerkit_range_get_right(CompilerKitRange *self);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_range_h__ */