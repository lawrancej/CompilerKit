/** 
 * Boilerplate header.
 * 
 * Read the GObject Tutorial and follow the given directions. DO NOT: #include ".boilerplate.h"
 * 
 * @see http://syscall.org/doku.php/gobjectutorial/start 
 * @see http://irrepupavel.com/documents/gtk/gobject-faq.html
 * @see http://developer.gnome.org/gobject/stable/
 * @see http://article.gmane.org/gmane.comp.gnome.gtk%2B.devel.general/6329 (mostly out of date)
 * 
 * @todo Directions:
 * 1. Save a copy of this header file (named for the type) into the include/CompilerKit folder.
 * 2. Replace "BAR" with TYPE, "Bar" with Type, and "bar" with type, declare a class called Type.
 * 3. Replace "header" with the file name from step 1.
 * 4. Search for all @todo items.
 * 5. Follow the instructions for .boilerplate.c (the corresponding .c file)
 * 6. Remove this comment.
 */
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
#ifndef INCLUDE_CompilerKit_header_h__
#define INCLUDE_CompilerKit_header_h__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_BAR                  (compilerkit_bar_get_type ())
#define COMPILERKIT_BAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_BAR, CompilerKitBar))
#define COMPILERKIT_IS_BAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_BAR))
#define COMPILERKIT_BAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_BAR, CompilerKitBarClass))
#define COMPILERKIT_IS_BAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_BAR))
#define COMPILERKIT_BAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_BAR, CompilerKitBarClass))

typedef struct _CompilerKitBarPrivate CompilerKitBarPrivate;

/**
 * @struct CompilerKitBar
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitBarPrivate for private fields.
 * @see #CompilerKitBarClass for virtual public methods.
 */
typedef struct _CompilerKitBar
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** @todo Define public fields here */

  /** Opaque pointer to private fields */
  CompilerKitBarPrivate *priv;

} CompilerKitBar;

/**
 * @struct CompilerKitBarClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitBar for a list of fields.
 */
typedef struct _CompilerKitBarClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;

  /** @todo Virtual public methods (function pointers) go here */
  // void (*method_name) (CompilerKitBar *self, ...);
  
} CompilerKitBarClass;

/**
 * @fn compilerkit_bar_get_type
 * Returns the runtime type information for CompilerKitBar. Macro COMPILERKIT_TYPE_BAR uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_bar_get_type (void);

/** Public method function prototypes 
 * @todo Add function prototypes here for both virtual and non-virtual public methods.
 * @see http://developer.gnome.org/gobject/stable/howto-gobject-methods.html
 */
CompilerKitBar* compilerkit_bar_new (void);
G_END_DECLS
#endif /* INCLUDE_CompilerKit_header_h__ */