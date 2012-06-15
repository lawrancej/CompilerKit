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
#ifndef __COMPILERKIT_IBAR_H__
#define __COMPILERKIT_IBAR_H__

#include <glib-object.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_IBAR                 (compilerkit_ibar_get_type ())
#define COMPILERKIT_IBAR(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_IBAR, CompilerKitIBar))
#define COMPILERKIT_IS_IBAR(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_IBAR))
#define COMPILERKIT_IBAR_GET_INTERFACE(inst)  (G_TYPE_INSTANCE_GET_INTERFACE ((inst), COMPILERKIT_TYPE_IBAR, CompilerKitIBarInterface))

typedef struct _CompilerKitIBar               CompilerKitIBar; /* dummy object */

typedef struct _CompilerKitIBarInterface
{
    GTypeInterface parent_iface;
    void (*do_action) (CompilerKitIBar *self);
};

GType compilerkit_ibar_get_type (void);

void compilerkit_ibar_do_action (CompilerKitIBar *self);

G_END_DECLS
#endif /* __COMPILERKIT_IBAR_H__ */