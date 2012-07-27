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
#ifndef INCLUDE_CompilerKit_visitors_h__
#define INCLUDE_CompilerKit_visitors_h__

#include "visitor.h"

/* Visitor function prototypes */
CompilerKitVisitor *compilerkit_derivative_visitor ();
GObject *compilerkit_derivative_apply_char (CompilerKitVisitor *derivative_visitor, GObject *regex, gunichar symbol);
GObject *compilerkit_derivative_apply_string (CompilerKitVisitor *derivative_visitor, GObject *regex, gchar *symbol);
gboolean compilerkit_regex_matches_string (GObject *regex, gchar *symbol);

CompilerKitVisitor *compilerkit_nullable_visitor ();
gboolean compilerkit_nullable(GObject *regex);

gchar *compilerkit_to_string (GObject *regex);
CompilerKitVisitor *compilerkit_to_nfa_visitor ();
CompilerKitVisitor *compilerkit_to_graphviz_visitor ();
CompilerKitVisitor *compilerkit_to_grammar_visitor ();

#endif