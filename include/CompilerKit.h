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
#ifndef INCLUDE_CompilerKit_h__
#define INCLUDE_CompilerKit_h__

/* Regular expression includes */
#include "CompilerKit/automata.h"
#include "CompilerKit/empty-set.h"
#include "CompilerKit/empty-string.h"
#include "CompilerKit/symbol.h"
#include "CompilerKit/alternation.h"
#include "CompilerKit/complement.h"
#include "CompilerKit/concatenation.h"
#include "CompilerKit/kleene-star.h"

#include "CompilerKit/scanner.h"

/* Context-free grammar includes */
#include "CompilerKit/nonterminal.h"
#include "CompilerKit/terminal.h"
#include "CompilerKit/grammar.h"

#endif