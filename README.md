CompilerKit
===========
CompilerKit will be a [parser combinator](#what-is-a-parser-combinator) based compiler construction library in C.

- [Why does this exist?](#why-does-this-library-exist)
- [What is the license?](#what-is-the-license)
- [How do I build this?](#how-do-i-build-this)
- [What problems does this solve?](#what-problems-does-this-library-solve)
- [Where can I contribute to this?](#where-can-i-contribute-to-this)

## What is the license?
LGPL version 2 or later.

## Why does this library exist?
CompilerKit aims to streamline developing any software deriving tree structures from text, including compilers and interpreters.
This library will be the final product of a compiler design class.

This library aims to [avoid problems in existing tools](#problems-in-existing-compiler-compilers) by doing these:

- Work across platforms, programming languages.
- Play nicely with Unicode.
- Never block, and be thread-safe.
- Efficiently handle all possible CFGs, even ambiguous ones.
- Work as a library.
- (Future) be a drop in replacement for Bison, yacc, lex, etc.

## What problems does this library solve?
Many existing compiler construction tools:

- Require learning a new syntax (e.g., lex, yacc, Bison)
- Add complexity to the build process (e.g., lex, yacc, Bison)
- Do not handle all possible context free grammars (e.g., lex, yacc)
- Work with only one language (e.g., lex, yacc)
- Produce blocking code (e.g., lex)
- Produce non thread-safe code (e.g., lex)
- Do not work well with Unicode or non-string sequences.

## Where can I contribute to this?
1. Fork from here: <https://github.com/lawrancej/CompilerKit>.
2. Check the issue tracker here: <https://github.com/lawrancej/CompilerKit/issues>.
3. Add your improvements to a branch in your fork named for the topic.
4. Send in a pull request.

Or, file a bug report: <https://github.com/lawrancej/CompilerKit/issues/new>

## What is a [parser combinator?](http://en.wikipedia.org/wiki/Parser_combinator)
A parser combinator is a higher-order function that creates parsers from parsers.

Similar libraries:

- [Boost Spirit (C++)](http://boost-spirit.com/home/)
- [Parsec (Haskell)](http://www.haskell.org/haskellwiki/Parsec)

Proposed example usage:

    Nonterminal * value = nonterminal ("value");
    Nonterminal * product = nonterminal ("product");
    Nonterminal * sum = nonterminal ("sum");
    Nonterminal * expr = nonterminal ("expr");
    Parser * formula = derivative_parser (expr);
    
    /*
     Define the grammar below:
     value -> [0-9]+ | (expr)
     product -> value ((*|/) value)*
     sum -> product ((+|-) product)*
     expr -> sum
     */
    value->becomes (many1(digit()));
    value->becomes (parens(expr));
    product->becomes (value, many (or(symbol('*'),symbol('/')), value));
    sum->becomes (product, many (or(symbol('+'), symbol('-')), product));
    expr->becomes (sum);
    
    /* Return whether the formula parser matched the expression "(1+2+3+4)/2". Should return true */
    formula->match("(1+2+3+4)/2");
    
    /* Free the parser. */
    parser_free (formula);

## How will this work?
This library will use [GObject](http://developer.gnome.org/gobject/stable/) internally.

We will employ test-first pair programming in the development of CompilerKit. (By the way, if you have a better name for this, I�m all ears.)

Testing and documentation first ensures that we consider the usage of this library before we develop it. It also helps track development progress by test completion and coverage.

Pair programming ensures that we learn from each other.

The library will consist of the following components:

- [Regular expression engine](#what-is-the-regular-expression-engine)
- [Scanner](#what-is-the-scanner-component)
- [Parser](#what-is-the-parser-component)
- [Language bindings](#what-are-the-language-bindings)

### What is the regular expression engine?
The regular expression engine will be swappable:

- NFA backend
- DFA backend
- Derivative backend
- PCRE backend

### What is the scanner component?
The scanner requires a regular expression engine to work.

### What is the parser component?
The parser construction will be separate from the swappable parsing backends:

- Recursive descent parser.
- [Derivative based parser](http://matt.might.net/articles/parsing-with-derivatives/).
- GLR parser, if time permits.

### What are the language bindings?
Language bindings will make use of GObject introspection. This library will target support for:

- C#
- Python
- C++
- Java

## How do I build this?
CompilerKit builds with pkg-config and [GLib installed](#how-do-i-get-glib-installed).

CompilerKit builds with CMake 2.6 or higher. Simply do this:

```
mkdir build && cd build
cmake ..
cmake --build .
```

## How do I get GLib installed?
Since CompilerKit depends on [GLib](http://developer.gnome.org/glib/) and [GObject](http://developer.gnome.org/gobject/), a little work is needed, depending on the platform.

### On Windows:
1. Go here: <http://www.gtk.org/download/win32.php>
2. Download 
- [GLib Dev](http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib-dev_2.28.8-1_win32.zip), 
- [pkg-config Tool](http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/pkg-config_0.26-1_win32.zip),
- [GLib Run-time](http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib_2.28.8-1_win32),
- [gettext-runtime Run-time](http://ftp.gnome.org/pub/gnome/binaries/win32/glib/0.18.1.1/gettext-runtime_0.18.1.1-2_win32)
3. Unzip everything into the same directory, e.g., `C:\glib`. Add `C:\glib\bin` to the system PATH. To verify it's working:

```
C:\> pkg-config --list-all
gio-2.0               GIO - glib I/O library
gmodule-2.0           GModule - Dynamic module loader for GLib
glib-2.0              GLib - C Utility Library
gmodule-no-export-2.0 GModule - Dynamic module loader for GLib
gthread-2.0           GThread - Thread support for GLib
gobject-2.0           GObject - GLib Type, Object, Parameter and Signal Library
```

### On Linux:
Debian, Ubuntu:

    sudo apt-get install libglib2.0-dev

RedHat:

    sudo yum install glib-devel

### On Mac:
Install brew from: <http://mxcl.github.com/homebrew/>
Once installed, run the following from the Terminal:

    brew install glib pkg-config

## What do I need to do?
1. [Install Software](#what-software-do-i-need).
2. [Contribute](#what-will-i-contribute).
3. [Solicit and share feedback](#how-do-i-solicit-and-share-feedback).
4. Go to 2.

## What software do I need?
- A compiler (Visual Studio, Xcode, GCC, [MinGW](http://sourceforge.net/projects/mingw/files/latest/download?source=files), or Clang)
- Version control (Git)
- Build tool ([CMake](http://www.cmake.org/cmake/resources/software.html))
- Testing tool (Clar)
- Documentation tool (Doxygen)

## What will I contribute?
Test cases, documentation, and code.

## How do I solicit and share feedback?
Via github.