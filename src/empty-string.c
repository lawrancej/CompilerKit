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
#include "CompilerKit/empty-string.h"
G_DEFINE_TYPE(CompilerKitEmptyString, compilerkit_empty_string, G_TYPE_OBJECT);

static void compilerkit_empty_string_finalize (GObject* object);
static void compilerkit_empty_string_dispose (GObject* object);
static GObject *compilerkit_empty_string_new (void);
static GObject *compilerkit_empty_string_constructor (GType gtype, guint n_properties, GObjectConstructParam *properties);

/**
 * compilerkit_empty_string_class_init:
 * @fn compilerkit_empty_string_class_init
 * Initializes the CompilerKitEmptyStringClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitEmptyStringClass to initialize
 * @return void
 */
static void
compilerkit_empty_string_class_init (CompilerKitEmptyStringClass *klass)
{
    GObjectClass *g_object_class;

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /* Hook finalization functions */
	g_object_class->constructor = compilerkit_empty_string_constructor;
    g_object_class->dispose = compilerkit_empty_string_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_empty_string_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_empty_string_init:
 * @fn compilerkit_empty_string_init 
 * Initializes the CompilerKitEmptyString instance.
 * @pre self is not NULL.
 * @param CompilerKitEmptyString to initialize
 * @return void
 */
static void
compilerkit_empty_string_init (CompilerKitEmptyString *self)
{
}

/**
 * compilerkit_empty_string_new:
 * @fn compilerkit_empty_string_new
 * Construct a CompilerKitEmptyString instance.
 * @pre None
 * @param None
 * @return A new CompilerKitEmptyString struct.
 */
static GObject *compilerkit_empty_string_new (void)
{
	return g_object_new (COMPILERKIT_TYPE_EMPTY_STRING, NULL);
}

/**
 * compilerkit_empty_string_constructor:
 * This overrides the default constructor for GObject to implement the singleton pattern.
 * This borrows from: <http://blogs.gnome.org/xclaesse/2010/02/11/how-to-make-a-gobject-singleton/>
 * @pre Unsure ;-)
 * @param GType The GObject type to construct.
 * @param gunit The number of properties (there aren't any here).
 * @param GObjectConstructParam* A pointer to GObject properties (there aren't any here).
 * @return A new reference to the single instance of CompilerKitEmptySet.
 */
static GObject *compilerkit_empty_string_constructor (GType gtype, guint n_properties, GObjectConstructParam *properties)
{
    // Static instance of EmptySet
    static GObject *self = NULL;
    
    if (self == NULL) {
        self = G_OBJECT_CLASS (compilerkit_empty_string_parent_class)->constructor (gtype, n_properties, properties);
        g_object_add_weak_pointer (self, (gpointer) &self);
        return self;
    }
    return g_object_ref (self);
}

/**
 * compilerkit_empty_string_get_instance:
 * @fn compilerkit_empty_string_get_instance
 * @memberof CompilerKitEmptyString
 * Returns the single instance of Empty String
 * @pre None
 * @param None
 * @return The instance of the CompilerKitEmptyString struct.
 */
GObject *compilerkit_empty_string_get_instance (void)
{
    return compilerkit_empty_string_new ();
}

/**
 * compilerkit_empty_string_finalize:
 * @fn compilerkit_empty_string_finalize
 * Reverse what compilerkit_empty_string_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_empty_string_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_empty_string_parent_class)->finalize (object);
}

/**
 * compilerkit_empty_string_dispose:
 * @fn compilerkit_empty_string_dispose
 * Reverse what compilerkit_empty_string_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_empty_string_dispose (GObject* object)
{
    CompilerKitEmptyString *self = COMPILERKIT_EMPTY_STRING (object);

    G_OBJECT_CLASS (compilerkit_empty_string_parent_class)->dispose (object);
}