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
#ifndef INCLUDE_CompilerKit_dfa_h__
#define INCLUDE_CompilerKit_dfa_h__

#include <glib-object.h>
#include "CompilerKit/automata.h"
G_BEGIN_DECLS
#define COMPILERKIT_TYPE_DFA                  (compilerkit_dfa_get_type ())
#define COMPILERKIT_DFA(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_DFA, CompilerKitdfa))
#define COMPILERKIT_IS_DFA(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_DFA))
#define COMPILERKIT_DFA_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_DFA, CompilerKitdfaClass))
#define COMPILERKIT_IS_DFA_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_DFA))
#define COMPILERKIT_DFA_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_DFA, CompilerKitdfaClass))


/**
 * @struct CompilerKitdfa
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * Defines all public fields. Private fields live behind an opaque pointer.
 * @see #_CompilerKitdfaPrivate for private fields.
 * @see #CompilerKitdfaClass for virtual public methods.
 * @example dfa-demo.c
 * This is an example of how to use the CompilerKitdfa struct.
 */
typedef struct _CompilerKitdfa
{
    /** Base instance (CompilerKitFSM) */
    CompilerKitFSM parent_instance;

    /** @todo Define public fields here */

} CompilerKitdfa;

/**
 * @struct CompilerKitdfaClass
 * @todo Briefly describe this struct. (Remove the todo).
 *
 * This struct declares the virtual public methods.
 * @see #CompilerKitdfa for a list of fields.
 */
typedef struct _CompilerKitdfaClass
{
    /** Base class (CompilerKitFSMClass) */
    CompilerKitFSMClass parent_class;

} CompilerKitdfaClass;

/**
 * @fn compilerkit_dfa_get_type
 * Returns the runtime type information for CompilerKitdfa. Macro COMPILERKIT_TYPE_DFA uses it.
 * @pre None
 * @param None
 * @return GType (runtime type information)
 */
GType compilerkit_dfa_get_type (void);


CompilerKitdfa* compilerkit_dfa_new ();

G_END_DECLS
#endif /* INCLUDE_CompilerKit_dfa_h__ */
