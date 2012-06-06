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
#ifndef INCLUDE_CompilerKit_automata_h__
#define INCLUDE_CompilerKit_automata_h__

#include <glib-object.h>
#include <glib.h>
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_FSM                  (compilerkit_FSM_get_type ())
#define COMPILERKIT_FSM(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_FSM, CompilerKitFSM))
#define COMPILERKIT_IS_FSM(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_FSM))
#define COMPILERKIT_FSM_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_FSM, CompilerKitFSMClass))
#define COMPILERKIT_IS_FSM_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_FSM))
#define COMPILERKIT_FSM_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_FSM, CompilerKitFSMClass))

typedef struct _CompilerKitFSMPrivate CompilerKitFSMPrivate;

typedef struct _CompilerKitFSM
{
  GObject parent_instance;
  
  /*< define private member variables inside CompilerKitFSMPrivate in the corresponding .c file >*/
  CompilerKitFSMPrivate *priv;
  
} CompilerKitFSM;

typedef struct _CompilerKitFSMClass
{
  GObjectClass parent_class;

  /* Virtual public methods */
  void (*add_transition) (CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition);
} CompilerKitFSMClass;

/** Public method function prototypes */
CompilerKitFSM* compilerkit_FSM_new (void);
void compilerkit_FSM_add_transition (CompilerKitFSM* self, gchar *from_state, gchar *to_state, gchar transition);
void compilerkit_FSM_add_state (CompilerKitFSM* self, gchar *state);
void compilerkit_FSM_add_accepting_state (CompilerKitFSM* self, gchar *state);
void compilerkit_FSM_merge (CompilerKitFSM *self, CompilerKitFSM *other);
G_END_DECLS
#endif