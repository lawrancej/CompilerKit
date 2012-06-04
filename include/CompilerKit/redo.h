/*
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
#ifndef INCLUDE_CompilerKit_re_h__
#define INCLUDE_CompilerKit_re_h__

#include <glib-object.h>

/*
 * http://en.wikipedia.org/wiki/Regular_expression#Formal_language_theory
 */
#define COMPILERKIT_TYPE_EMPTYSET                  (compilerkit_emptyset_get_type ())
#define COMPILERKIT_EMPTYSET(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_EMPTYSET, CompilerKitEmptySet))
#define COMPILERKIT_IS_EMPTYSET(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_EMPTYSET))
#define COMPILERKIT_EMPTYSET_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_EMPTYSET, CompilerKitEmptySetClass))
#define COMPILERKIT_IS_EMPTYSET_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_EMPTYSET))
#define COMPILERKIT_EMPTYSET_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_EMPTYSET, CompilerKitEmptySetClass))

typedef struct _CompilerKitEmptySet        CompilerKitEmptySet;
typedef struct _CompilerKitEmptySetClass   CompilerKitEmptySetClass;
typedef struct _CompilerKitEmptySetPrivate CompilerKitEmptySetPrivate;

struct _CompilerKitEmptySet
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitEmptySetPrivate *priv;
};

struct _CompilerKitEmptySetClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_EMPTYSET */
GType compilerkit_emptyset_get_type (void);

#define COMPILERKIT_TYPE_EMPTYSTRING                  (compilerkit_emptystring_get_type ())
#define COMPILERKIT_EMPTYSTRING(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_EMPTYSTRING, CompilerKitEmptyString))
#define COMPILERKIT_IS_EMPTYSTRING(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_EMPTYSTRING))
#define COMPILERKIT_EMPTYSTRING_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_EMPTYSTRING, CompilerKitEmptyStringClass))
#define COMPILERKIT_IS_EMPTYSTRING_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_EMPTYSTRING))
#define COMPILERKIT_EMPTYSTRING_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_EMPTYSTRING, CompilerKitEmptyStringClass))

typedef struct _CompilerKitEmptyString        CompilerKitEmptyString;
typedef struct _CompilerKitEmptyStringClass   CompilerKitEmptyStringClass;
typedef struct _CompilerKitEmptyStringPrivate CompilerKitEmptyStringPrivate;

struct _CompilerKitEmptyString
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitEmptyStringPrivate *priv;
};

struct _CompilerKitEmptyStringClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_EMPTYSTRING */
GType compilerkit_emptystring_get_type (void);

#define COMPILERKIT_TYPE_SYMBOL                  (compilerkit_symbol_get_type ())
#define COMPILERKIT_SYMBOL(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_SYMBOL, CompilerKitSymbol))
#define COMPILERKIT_IS_SYMBOL(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_SYMBOL))
#define COMPILERKIT_SYMBOL_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_SYMBOL, CompilerKitSymbolClass))
#define COMPILERKIT_IS_SYMBOL_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_SYMBOL))
#define COMPILERKIT_SYMBOL_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_SYMBOL, CompilerKitSymbolClass))

typedef struct _CompilerKitSymbol        CompilerKitSymbol;
typedef struct _CompilerKitSymbolClass   CompilerKitSymbolClass;
typedef struct _CompilerKitSymbolPrivate CompilerKitSymbolPrivate;

struct _CompilerKitSymbol
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitSymbolPrivate *priv;
};

struct _CompilerKitSymbolClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_SYMBOL */
GType compilerkit_symbol_get_type (void);

#define COMPILERKIT_TYPE_KLEENESTAR                  (compilerkit_kleenestar_get_type ())
#define COMPILERKIT_KLEENESTAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_KLEENESTAR, CompilerKitKleeneStar))
#define COMPILERKIT_IS_KLEENESTAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_KLEENESTAR))
#define COMPILERKIT_KLEENESTAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_KLEENESTAR, CompilerKitKleeneStarClass))
#define COMPILERKIT_IS_KLEENESTAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_KLEENESTAR))
#define COMPILERKIT_KLEENESTAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_KLEENESTAR, CompilerKitKleeneStarClass))

typedef struct _CompilerKitKleeneStar        CompilerKitKleeneStar;
typedef struct _CompilerKitKleeneStarClass   CompilerKitKleeneStarClass;
typedef struct _CompilerKitKleeneStarPrivate CompilerKitKleeneStarPrivate;

struct _CompilerKitKleeneStar
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitKleeneStarPrivate *priv;
};

struct _CompilerKitKleeneStarClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_KLEENESTAR */
GType compilerkit_kleenestar_get_type (void);

#define COMPILERKIT_TYPE_CONCATENATION                  (compilerkit_concatenation_get_type ())
#define COMPILERKIT_CONCATENATION(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_CONCATENATION, CompilerKitConcatenation))
#define COMPILERKIT_IS_CONCATENATION(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_CONCATENATION))
#define COMPILERKIT_CONCATENATION_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_CONCATENATION, CompilerKitConcatenationClass))
#define COMPILERKIT_IS_CONCATENATION_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_CONCATENATION))
#define COMPILERKIT_CONCATENATION_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_CONCATENATION, CompilerKitConcatenationClass))

typedef struct _CompilerKitConcatenation        CompilerKitConcatenation;
typedef struct _CompilerKitConcatenationClass   CompilerKitConcatenationClass;
typedef struct _CompilerKitConcatenationPrivate CompilerKitConcatenationPrivate;

struct _CompilerKitConcatenation
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitConcatenationPrivate *priv;
};

struct _CompilerKitConcatenationClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_CONCATENATION */
GType compilerkit_concatenation_get_type (void);

#define COMPILERKIT_TYPE_ALTERNATION                  (compilerkit_alternation_get_type ())
#define COMPILERKIT_ALTERNATION(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternation))
#define COMPILERKIT_IS_ALTERNATION(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_ALTERNATION))
#define COMPILERKIT_ALTERNATION_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternationClass))
#define COMPILERKIT_IS_ALTERNATION_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_ALTERNATION))
#define COMPILERKIT_ALTERNATION_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_ALTERNATION, CompilerKitAlternationClass))

typedef struct _CompilerKitAlternation        CompilerKitAlternation;
typedef struct _CompilerKitAlternationClass   CompilerKitAlternationClass;
typedef struct _CompilerKitAlternationPrivate CompilerKitAlternationPrivate;

struct _CompilerKitAlternation
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitAlternationPrivate *priv;
};

struct _CompilerKitAlternationClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_ALTERNATION */
GType compilerkit_alternation_get_type (void);
#endif