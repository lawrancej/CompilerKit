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
 * TODO: implement 
 */
#define COMPILERKIT_TYPE_REGEX                  (compilerkit_regex_get_type ())
#define COMPILERKIT_REGEX(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_REGEX, CompilerKitRegex))
#define COMPILERKIT_IS_REGEX(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_REGEX))
#define COMPILERKIT_REGEX_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_REGEX, CompilerKitRegexClass))
#define COMPILERKIT_IS_REGEX_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_REGEX))
#define COMPILERKIT_REGEX_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_REGEX, CompilerKitRegexClass))

typedef struct _CompilerKitRegex        CompilerKitRegex;
typedef struct _CompilerKitRegexClass   CompilerKitRegexClass;
typedef struct _CompilerKitRegexPrivate CompilerKitRegexPrivate;

struct _CompilerKitRegex
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitRegexPrivate *priv;
};

struct _CompilerKitRegexClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_REGEX */
GType compilerkit_regex_get_type (void);

#endif