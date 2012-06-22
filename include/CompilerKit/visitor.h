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
#ifndef INCLUDE_CompilerKit_visitor_h__
#define INCLUDE_CompilerKit_visitor_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_VISITOR                  (compilerkit_visitor_get_type ())
#define COMPILERKIT_VISITOR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_VISITOR, CompilerKitVisitor))
#define COMPILERKIT_IS_VISITOR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_VISITOR))
#define COMPILERKIT_VISITOR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_VISITOR, CompilerKitVisitorClass))
#define COMPILERKIT_IS_VISITOR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_VISITOR))
#define COMPILERKIT_VISITOR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_VISITOR, CompilerKitVisitorClass))

typedef struct _CompilerKitVisitorPrivate CompilerKitVisitorPrivate;

/**
 * @struct CompilerKitVisitor
 * A visitor struct.
 *
 * A typical visitor implementation uses function overloading.
 * C, however, does not support function overloading.
 * To get around this limitation, the visitor class uses the GObject type system.
 * Every GObject has a type associated with it. This serves as a key into a hash table of function pointers.
 * To define a visitor, see the example below.
 * @see #_CompilerKitVisitorPrivate for private fields.
 * @see #CompilerKitVisitorClass for virtual public methods.
 * @example visitor-demo.c
 * This is an example of how to use the CompilerKitVisitor struct.
 */
typedef struct _CompilerKitVisitor
{
    /** Base instance (GObject) */
    GObject parent_instance;

    /** Pointer to any useful data during traversal. */
    gpointer state;

    /** Opaque pointer to private fields */
    CompilerKitVisitorPrivate *priv;

} CompilerKitVisitor;

/**
 * @typedef CompilerKitVisitorFunc
 * @memberof CompilerKitVisitor
 * A function pointer type for visitors. To use, define a function like this:
 * 
 *     GObject *do_something (CompilerKitVisitor *visitor, GObject *object)
 *     {
 *     
 *     }
 *
 * Then, when registering function pointers into the visitor, do this (replace `CLASSNAMEGOESHERE` with the right thing):
 *
 *     compilerkit_visitor_register (visitor, COMPILERKIT_TYPE_CLASSNAMEGOESHERE, do_something);
 */
typedef GObject *(*CompilerKitVisitorFunc) (CompilerKitVisitor *, GObject *);

/**
 * @struct CompilerKitVisitorClass
 *
 * This struct declares the virtual public methods of visitor (there aren't any).
 * @see #CompilerKitVisitor for a list of fields.
 */
typedef struct _CompilerKitVisitorClass
{
    /** Base class (GobjectClass) */
    GObjectClass parent_class;
} CompilerKitVisitorClass;

/**
 * compilerkit_visitor_get_type:
 * @fn compilerkit_visitor_get_type
 * Returns the runtime type information for CompilerKitVisitor. Macro COMPILERKIT_TYPE_VISITOR uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_visitor_get_type (void);

/** Public method function prototypes */
CompilerKitVisitor *compilerkit_visitor_new (void);
void compilerkit_visitor_register (CompilerKitVisitor *visitor, GType the_type, CompilerKitVisitorFunc);
void compilerkit_visitor_register_identity (CompilerKitVisitor *self, GType the_type);
GObject *compilerkit_visitor_visit (CompilerKitVisitor *visitor, GObject *obj);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_visitor_h__ */