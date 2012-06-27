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
#ifndef INCLUDE_CompilerKit_complement_h__
#define INCLUDE_CompilerKit_complement_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_COMPLEMENT                  (compilerkit_complement_get_type ())
#define COMPILERKIT_COMPLEMENT(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_COMPLEMENT, CompilerKitComplement))
#define COMPILERKIT_IS_COMPLEMENT(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_COMPLEMENT))
#define COMPILERKIT_COMPLEMENT_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_COMPLEMENT, CompilerKitComplementClass))
#define COMPILERKIT_IS_COMPLEMENT_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_COMPLEMENT))
#define COMPILERKIT_COMPLEMENT_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_COMPLEMENT, CompilerKitComplementClass))

typedef struct _CompilerKitComplementPrivate CompilerKitComplementPrivate;

/**
 * @struct CompilerKitComplement
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitComplementPrivate for private fields.
 * @see #CompilerKitComplementClass for virtual public methods.
 * @example complement-demo.c
 * This is an example of how to use the CompilerKitComplement struct.
 */
typedef struct _CompilerKitComplement
{
    /** Base instance (GObject) */
    GObject parent_instance;

    /** Opaque pointer to private fields */
    CompilerKitComplementPrivate *priv;

} CompilerKitComplement;

/**
 * @struct CompilerKitComplementClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitComplement for a list of fields.
 */
typedef struct _CompilerKitComplementClass
{
    /** Base class (GobjectClass) */
    GObjectClass parent_class;

} CompilerKitComplementClass;

/**
 * @fn compilerkit_complement_get_type
 * Returns the runtime type information for CompilerKitComplement. Macro COMPILERKIT_TYPE_COMPLEMENT uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_complement_get_type (void);

/** Public method function prototypes */
GObject *compilerkit_complement_new (GObject *node);
GObject *compilerkit_complement_get_node (CompilerKitComplement *self);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_complement_h__ */