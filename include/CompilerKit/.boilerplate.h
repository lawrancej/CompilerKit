/* 
 * Boilerplate header.
 * 
 * DO NOT: #include ".boilerplate.h"
 * 
 * Directions:
 * 1. Replace BAR, Bar, and bar with TYPE, Type, and type, respectively to declare a class called Type.
 * 2. Replace header with the file name.
 * 3. Remove this comment.
 */
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
#ifndef INCLUDE_CompilerKit_header_h__
#define INCLUDE_CompilerKit_header_h__

#include <glib-object.h>


#define COMPILERKIT_TYPE_BAR                  (compilerkit_bar_get_type ())
#define COMPILERKIT_BAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_BAR, CompilerKitBar))
#define COMPILERKIT_IS_BAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_BAR))
#define COMPILERKIT_BAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_BAR, CompilerKitBarClass))
#define COMPILERKIT_IS_BAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_BAR))
#define COMPILERKIT_BAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_BAR, CompilerKitBarClass))

typedef struct _CompilerKitBar        CompilerKitBar;
typedef struct _CompilerKitBarClass   CompilerKitBarClass;
typedef struct _CompilerKitBarPrivate CompilerKitBarPrivate;

struct _CompilerKitBar
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitBarPrivate *priv;
};

struct _CompilerKitBarClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_BAR */
GType compilerkit_bar_get_type (void);
#endif