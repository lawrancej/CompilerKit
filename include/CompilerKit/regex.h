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
#ifndef INCLUDE_CompilerKit_regex_h__
#define INCLUDE_CompilerKit_regex_h__

/**
 * \page regular Regular language classes
 * 
 * Regular expressions and finite automata define and recognize regular languages.
 * * Regular expressions define the regular languages.
 * * Finite automata recognize regular languages.
 * * Scanners tokenize strings using finite automata or regular expressions. 
 * 
 * \section regex Regular Expressions
 * 
 * Regular expressions consist of:
 * 
 * * The empty set (CompilerKitEmptySet)
 * * The empty string (CompilerKitEmptyString)
 * * A symbol (CompilerKitSymbol)
 * * Concatenation (CompilerKitConcatenation)
 * * Alternation (CompilerKitAlternation)
 * * Kleene closure (CompilerKitKleeneStar)
 * * Complement (CompilerKitComplement)
 * 
 * For example, the regular expression `(a|ab)*` is: `Kleene Star (Alternation (Symbol (a), Concatenation (a, b)))`
 * 
 * \section fsm Finite Automata
 * 
 * A finite automaton is a machine that can be in only one of a finite number of states.
 * 
 * It has:
 * * A start state
 * * A set of states
 * * A set of accepting states
 * * A set of transitions from (state, symbol) to *something*.
 * 
 * In a deterministic finite automaton (DFA), *something* is the next state.
 * In a nondeterministic finite automaton (NFA), *something* is the set of possible next states.
 */
/* Regular expression includes */
#include "automata.h"
#include "dfa.h"
#include "nfa.h"
#include "scanner.h"

#include "empty-set.h"
#include "empty-string.h"
#include "symbol.h"
#include "range.h"
#include "alternation.h"
#include "complement.h"
#include "concatenation.h"
#include "kleene-star.h"

#endif /* INCLUDE_CompilerKit_regex_h__ */
