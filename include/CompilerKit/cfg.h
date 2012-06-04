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
#ifndef INCLUDE_CompilerKit_cfg_h__
#define INCLUDE_CompilerKit_cfg_h__

#include <glib-object.h>

#define COMPILERKIT_TYPE_NONTERMINAL                  (compilerkit_nonterminal_get_type ())
#define COMPILERKIT_NONTERMINAL(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_NONTERMINAL, CompilerKitNonterminal))
#define COMPILERKIT_IS_NONTERMINAL(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_NONTERMINAL))
#define COMPILERKIT_NONTERMINAL_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_NONTERMINAL, CompilerKitNonterminalClass))
#define COMPILERKIT_IS_NONTERMINAL_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_NONTERMINAL))
#define COMPILERKIT_NONTERMINAL_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_NONTERMINAL, CompilerKitNonterminalClass))

typedef struct _CompilerKitNonterminal        CompilerKitNonterminal;
typedef struct _CompilerKitNonterminalClass   CompilerKitNonterminalClass;
typedef struct _CompilerKitNonterminalPrivate CompilerKitNonterminalPrivate;

struct _CompilerKitNonterminal
{
  GObject parent_instance;

  /* instance members */
  /*< private >*/
  CompilerKitNonterminalPrivate *priv;
};

struct _CompilerKitNonterminalClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_NONTERMINAL */
GType compilerkit_nonterminal_get_type (void);


#define COMPILERKIT_TYPE_TERMINAL                  (compilerkit_terminal_get_type ())
#define COMPILERKIT_TERMINAL(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_TERMINAL, CompilerKitTerminal))
#define COMPILERKIT_IS_TERMINAL(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_TERMINAL))
#define COMPILERKIT_TERMINAL_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_TERMINAL, CompilerKitTerminalClass))
#define COMPILERKIT_IS_TERMINAL_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_TERMINAL))
#define COMPILERKIT_TERMINAL_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_TERMINAL, CompilerKitTerminalClass))

typedef struct _CompilerKitTerminal        CompilerKitTerminal;
typedef struct _CompilerKitTerminalClass   CompilerKitTerminalClass;

struct _CompilerKitTerminal
{
  GObject parent_instance;

  /* instance members */
};

struct _CompilerKitTerminalClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_TERMINAL */
GType compilerkit_terminal_get_type (void);

#define COMPILERKIT_TYPE_PARSER                  (compilerkit_parser_get_type ())
#define COMPILERKIT_PARSER(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPILERKIT_TYPE_PARSER, CompilerKitParser))
#define COMPILERKIT_IS_PARSER(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPILERKIT_TYPE_PARSER))
#define COMPILERKIT_PARSER_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), COMPILERKIT_TYPE_PARSER, CompilerKitParserClass))
#define COMPILERKIT_IS_PARSER_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPILERKIT_TYPE_PARSER))
#define COMPILERKIT_PARSER_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPILERKIT_TYPE_PARSER, CompilerKitParserClass))

typedef struct _CompilerKitParser        CompilerKitParser;
typedef struct _CompilerKitParserClass   CompilerKitParserClass;

struct _CompilerKitParser
{
  GObject parent_instance;

  /* instance members */
};

struct _CompilerKitParserClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by COMPILERKIT_TYPE_PARSER */

GType compilerkit_parser_get_type (void);
#endif