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

/**
 * \page contextfree Context free language classes
 * 
 * Context-free languages extend regular languages with recursion.
 * * Context-free grammars define the context-free languages.
 * * Pushdown automata recognize context-free languages.
 * * Parsers derive tree structures from strings or token sequences using pushdown automata or context-free grammars.
 *
 * \section grammar Grammar
 * A grammar consists of:
 * * A set of productions (rewriting rules) with a left and right hand side.
 * * A set of terminals
 * * A set of nonterminals
 * * A start symbol
 *
 * \section cfg Context Free Grammar
 * A context-free grammar is a grammar in which the left-hand side of every production is a single nonterminal symbol, and the right hande side of ever production is a (possibly empty) sequence of terminals and nonterminals.
 *
 * For example, this CFG matches parentheses:
 *
 *     S -> SS
 *     S -> (S)
 *     S -> ()
 *
 * \section pda Pushdown Automata
 * A pushdown automaton is a finite automaton with a stack memory.
 */
/* Context-free grammar includes */
#include "nonterminal.h"
#include "terminal.h"
#include "grammar.h"
#include "production.h"

#endif /* INCLUDE_CompilerKit_cfg_h__ */