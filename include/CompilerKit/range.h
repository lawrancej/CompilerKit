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
#define COMPILERKIT_RANGE(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_RANGE, CompilerKitRange))
#define COMPILERKIT_IS_RANGE(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_RANGE))
#define COMPILERKIT_RANGE_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_RANGE, CompilerKitRangeClass))
#define COMPILERKIT_IS_RANGE_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_RANGE))
#define COMPILERKIT_RANGE_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_RANGE, CompilerKitRangeClass))

typedef struct _CompilerKitRangePrivate CompilerKitRangePrivate;

/**
 * @struct CompilerKitRange
 * A range struct
 *
 * if a is a symbol and b is a symbol then [a-b] is a regular expression that matches all symbols between a and b
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitRangePrivate for private fields.
 * @see #CompilerKitRangeClass for virtual public methods.
 * @example range-demo.c
 * This is an example of how to use the CompilerKitRange struct.
 */
typedef struct _CompilerKitRange
{
    /** Base instance (GObject) */
    GObject parent_instance;

    /** Opaque pointer to private fields */
    CompilerKitRangePrivate *priv;

} CompilerKitRange;

/**
 * @struct CompilerKitRangeClass
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitRange for a list of fields.
 */
typedef struct _CompilerKitRangeClass
{
    /** Base class (GObjectClass) */
    GObjectClass parent_class;

} CompilerKitRangeClass;

/**
 * @fn compilerkit_range_get_type
 * Returns the runtime type information for CompilerKitRange. Macro COMPILERKIT_TYPE_RANGE uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_range_get_type (void);

/** Public method function prototypes 
 * @see http://developer.gnome.org/gobject/stable/howto-gobject-methods.html
 */
GObject* compilerkit_range_new (GObject *a, GObject *b);
GObject* compilerkit_range_get_equivalent (CompilerKitRange *self);
GObject* compilerkit_range_get_left (CompilerKitRange *self);
GObject* compilerkit_range_get_right (CompilerKitRange *self);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_range_h__ */