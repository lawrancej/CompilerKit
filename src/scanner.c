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
#include "CompilerKit/scanner.h"
#define COMPILERKIT_SCANNER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_SCANNER, CompilerKitScannerPrivate))
G_DEFINE_TYPE(CompilerKitScanner, compilerkit_scanner, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_scanner_finalize (GObject* object);
static void compilerkit_scanner_dispose (GObject* object);

/**
 * @struct _CompilerKitScannerPrivate
 * The private fields of the CompilerKitScanner struct.
 * 
 * @see #CompilerKitScanner
 */
struct _CompilerKitScannerPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    int dummy;
};

/**
 * compilerkit_scanner_class_init:
 * @fn compilerkit_scanner_class_init
 * Initializes the CompilerKitScannerClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitScannerClass to initialize
 * @return void
 */
static void
compilerkit_scanner_class_init (CompilerKitScannerClass *klass)
{
  GObjectClass *g_object_class;
  
  /* Add private structure */
  g_type_class_add_private (klass, sizeof (CompilerKitScannerPrivate));
  
  /* Get the parent gobject class */
  g_object_class = G_OBJECT_CLASS(klass);
  
  /** @todo Hook virtual methods to implementations */
  // klass->method = method_implementation;
  
  /* Hook finalization functions */
  g_object_class->dispose = compilerkit_scanner_dispose;   /* instance destructor, reverse of init */
  g_object_class->finalize = compilerkit_scanner_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_scanner_init:
 * @fn compilerkit_scanner_init 
 * Initializes the CompilerKitScanner instance.
 * @pre self is not NULL.
 * @param CompilerKitScanner to initialize
 * @return void
 */
static void
compilerkit_scanner_init (CompilerKitScanner *self)
{
  CompilerKitScannerPrivate *priv;

  self->priv = priv = COMPILERKIT_SCANNER_GET_PRIVATE (self);

  /** @todo Initialize public fields */
  // self->public_field = some_value;

  /** @todo Initialize private fields */
  // priv->member = whatever;
}

/**
 * compilerkit_scanner_new:
 * @fn compilerkit_scanner_new
 * @memberof CompilerKitScanner
 * Construct a CompilerKitScanner instance.
 * @pre None
 * @param None
 * @return A new CompilerKitScanner struct.
 */
CompilerKitScanner *compilerkit_scanner_new (void)
{
	return COMPILERKIT_SCANNER (g_object_new (COMPILERKIT_TYPE_SCANNER, NULL));
}

/**
 * compilerkit_scanner_finalize:
 * @fn compilerkit_scanner_finalize
 * Reverse what compilerkit_scanner_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_scanner_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_scanner_parent_class)->finalize (object);
}

/**
 * compilerkit_scanner_dispose:
 * @fn compilerkit_scanner_dispose
 * Reverse what compilerkit_scanner_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_scanner_dispose (GObject* object)
{
  CompilerKitScanner *self = COMPILERKIT_SCANNER (object);
  CompilerKitScannerPrivate* priv;

  priv = COMPILERKIT_SCANNER_GET_PRIVATE (self);
  
  /** @todo Deallocate memory as necessary */

  G_OBJECT_CLASS (compilerkit_scanner_parent_class)->dispose (object);
}

/**
 * An equivalent to lex. Given a filename for a scanner definition, produce the scanner.
 */
CompilerKitScanner *compilerkit_scanner_new_from_file (char *filename)
{
    return NULL;
}

/**
 * Open a file to scan by name.
 */
void compilerkit_scanner_open_filename(CompilerKitScanner *scanner, char *filename)
{

}
/**
 * Open a file to scan by file pointer.
 */
void compilerkit_scanner_open_file(CompilerKitScanner *scanner, FILE *fp)
{

}
/**
 * Close the file to scan.
 */
void compilerkit_scanner_close_file(CompilerKitScanner *scanner)
{

}
/**
 * This would be a list of tokens
 */
GList *compilerkit_scanner_get_tokens (CompilerKitScanner *scanner)
{
    return NULL;
}
/**
 * Produce the next token in the file.
 * Return NULL for the last token.
 */
CompilerKitToken *compilerkit_scanner_next_token (CompilerKitScanner *scanner)
{
    return NULL;
}

/**
 * The order in which we call this function determines priority of matching regexes.
 */
GList *compilerkit_scanner_register (CompilerKitScanner *scanner, CompilerKitToken *token, GObject *regex)
{
    return NULL;
}
