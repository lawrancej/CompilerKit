/* 
 * Boilerplate implementation.
 * 
 * Directions:
 * 1. Replace BAR, Bar, and bar with TYPE, Type, and type, respectively to declare the private members of the Type.
 * 2. #include the respective header file.
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
#define COMPILERKIT_BAR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_BAR, CompilerKitBarPrivate))

struct _CompilerKitBarPrivate
{
  int hsize;
}

static void
compilerkit_bar_class_init (CompilerKitBarClass *klass)
{
  g_type_class_add_private (klass, sizeof (CompilerKitBarPrivate));
}

static void
compilerkit_bar_init (CompilerKitBar *self)
{
  CompilerKitBarPrivate *priv;

  self->priv = priv = COMPILERKIT_BAR_GET_PRIVATE (self);

  priv->hsize = 42;
}