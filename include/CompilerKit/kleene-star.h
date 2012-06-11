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
#ifndef INCLUDE_CompilerKit_kleene_star_h__
#define INCLUDE_CompilerKit_kleene_star_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_KLEENE_STAR                  (compilerkit_kleene_star_get_type ())
#define COMPILERKIT_KLEENE_STAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_KLEENE_STAR, CompilerKitKleeneStar))
#define COMPILERKIT_IS_KLEENE_STAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_KLEENE_STAR))
#define COMPILERKIT_KLEENE_STAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_KLEENE_STAR, CompilerKitKleeneStarClass))
#define COMPILERKIT_IS_KLEENE_STAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_KLEENE_STAR))
#define COMPILERKIT_KLEENE_STAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_KLEENE_STAR, CompilerKitKleeneStarClass))

typedef struct _CompilerKitKleeneStarPrivate CompilerKitKleeneStarPrivate;

/**
 * @struct CompilerKitKleeneStar
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitKleeneStarPrivate for private fields.
 * @see #CompilerKitKleeneStarClass for virtual public methods.
 * @example kleene-star-demo.c
 * This is an example of how to use the CompilerKitKleeneStar struct.
 */
typedef struct _CompilerKitKleeneStar
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** @todo Define public fields here */

  /** Opaque pointer to private fields */
  CompilerKitKleeneStarPrivate *priv;

} CompilerKitKleeneStar;

/**
 * @struct CompilerKitKleeneStarClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitKleeneStar for a list of fields.
 */
typedef struct _CompilerKitKleeneStarClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;

  /** @todo Virtual public methods (function pointers) go here */
  // void (*method_name) (CompilerKitKleeneStar *self, ...);
  
} CompilerKitKleeneStarClass;

/**
 * @fn compilerkit_kleene_star_get_type
 * Returns the runtime type information for CompilerKitKleeneStar. Macro COMPILERKIT_TYPE_KLEENE_STAR uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_kleene_star_get_type (void);

/** Public method function prototypes 
 * @todo Add function prototypes here for both virtual and non-virtual public methods.
 * @see http://developer.gnome.org/gobject/stable/howto-gobject-methods.html
 */
CompilerKitKleeneStar* compilerkit_kleene_star_new (void);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_kleene_star_h__ */