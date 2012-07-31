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
#ifndef INCLUDE_CompilerKit_convenience_h__
#define INCLUDE_CompilerKit_convenience_h__

#define MANY(x) (compilerkit_kleene_star_new(x))
#define MANY1(x) (compilerkit_positive_closure_new(x))
#define OPTION(x) (compilerkit_optional_new(x))
#define SYMB(x) (compilerkit_symbol_new(x))
#define OR(x,...) (compilerkit_alternation_vlist_new(x,__VA_ARGS__,NULL))
#define SEQ(x,...) (compilerkit_concatenation_vlist_new(x,__VA_ARGS__,NULL))
#define EMPTY_STRING (compilerkit_empty_string_get_instance())
#define EMPTY_SET (compilerkit_empty_set_get_instance())
#define DIGIT (compilerkit_regex_digits())
#define PARENS(x) (compilerkit_parens(x))

GObject* compilerkit_character_class_new(gunichar, gunichar);
gboolean compilerkit_character_is_alpha_numeric(gunichar);
GObject* compilerkit_alpha_numeric_character_class_new(gunichar, gunichar);
GObject *compilerkit_positive_closure_new (GObject *);
GObject *compilerkit_optional_new (GObject *);
GObject *compilerkit_times_new(GObject *regex, guint lo);
GObject *compilerkit_regex_digits(void);
GObject *compilerkit_regex_lower(void);
GObject *compilerkit_regex_upper(void);
GObject *compilerkit_regex_punct(void);
GObject *compilerkit_regex_parens(void);
GObject *compilerkit_regex_whitespace(void);

#endif
