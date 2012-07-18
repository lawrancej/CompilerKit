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
#ifndef INCLUDE_CompilerKit_scanner_h__
#define INCLUDE_CompilerKit_scanner_h__

#include <glib-object.h>
#include <glib.h>
#include <stdio.h>
#include "token.h"

G_BEGIN_DECLS
#define COMPILERKIT_TYPE_SCANNER                  (compilerkit_scanner_get_type ())
#define COMPILERKIT_SCANNER(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_SCANNER, CompilerKitScanner))
#define COMPILERKIT_IS_SCANNER(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_SCANNER))
#define COMPILERKIT_SCANNER_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_SCANNER, CompilerKitScannerClass))
#define COMPILERKIT_IS_SCANNER_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_SCANNER))
#define COMPILERKIT_SCANNER_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_SCANNER, CompilerKitScannerClass))

typedef struct _CompilerKitScannerPrivate CompilerKitScannerPrivate;

/**
 * @struct CompilerKitScanner
 * The scanner breaks down a text file into a sequence of tokens using the supplied regexes.
 *
 * @see #_CompilerKitScannerPrivate for private fields.
 * @see #CompilerKitScannerClass for virtual public methods.
 * @example scanner-demo.c
 * This is an example of how to use the CompilerKitScanner struct.
 */
typedef struct _CompilerKitScanner
{
  /** Base instance (GObject) */
  GObject parent_instance;

  /** @todo Define public fields here */

  /** Opaque pointer to private fields */
  CompilerKitScannerPrivate *priv;

} CompilerKitScanner;

/**
 * @struct CompilerKitScannerClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitScanner for a list of fields.
 */
typedef struct _CompilerKitScannerClass
{
  /** Base class (GobjectClass) */
  GObjectClass parent_class;

  /** @todo Virtual public methods (function pointers) go here */
  // void (*method_name) (CompilerKitScanner *self, ...);
  
} CompilerKitScannerClass;

/**
 * @fn compilerkit_scanner_get_type
 * Returns the runtime type information for CompilerKitScanner. Macro COMPILERKIT_TYPE_SCANNER uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_scanner_get_type (void);

/** Public method function prototypes 
 * @todo Add function prototypes here for both virtual and non-virtual public methods.
 * @see http://developer.gnome.org/gobject/stable/howto-gobject-methods.html
 */
CompilerKitScanner *compilerkit_scanner_new (void);
CompilerKitScanner *compilerkit_scanner_new_from_file (char *);
void compilerkit_scanner_open_filename(CompilerKitScanner *, char *);
void compilerkit_scanner_open_file(CompilerKitScanner *, FILE *);
void compilerkit_scanner_close_file(CompilerKitScanner *);
GList *compilerkit_scanner_get_tokens (CompilerKitScanner *);
CompilerKitToken *compilerkit_scanner_next_token (CompilerKitScanner *);
GList *compilerkit_scanner_register (CompilerKitScanner *, CompilerKitToken *, GObject *regex);

G_END_DECLS
#endif /* INCLUDE_CompilerKit_scanner_h__ */