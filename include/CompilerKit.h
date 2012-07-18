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

/**
 * \mainpage CompilerKit
 * CompilerKit is a compiler construction library in C.
 * 
 * \section Organization
 * Just as compilers consist of distinct phases, CompilerKit library functionality fits into these groups:
 * 
 * * \ref testing
 * * \ref visitor
 * * \ref regular (lexical analysis)
 * * \ref contextfree (syntax analysis)
 * * Abstract syntax tree classes (not yet implemented)
 * * Intermediate representation classes (not yet implemented)
 * * Code generation classes (not yet implemented)
 * * Optimization classes (not yet implemented)
 * \page testing Testing
 * <http://developer.gnome.org/glib/2.31/glib-Testing.html>
 */

#include "CompilerKit/regex.h"
#include "CompilerKit/cfg.h"

#include "CompilerKit/convenience.h"

#include "CompilerKit/token.h"
#include "CompilerKit/scanner.h"

#include "CompilerKit/visitor.h"
#include "CompilerKit/visitors.h"

#endif