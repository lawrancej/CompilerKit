Tests
=====
Generic tests
-------------
These tests should pass for all classes:

 - No memory leaks if used properly
 - Executes within deadline
 - Reentrant
 - Thread safety
 - Unicode interoperability
 - No segmentation faults.
 - Fuzz testing

Demonstration
=============
These demonstration programs should link against the CompilerKit library implementation:

 - Demonstrate a working Brainf*** compiler, interpreter, debugger. Show the parse tree in GraphViz.
 - Demonstrate a whitespace compiler, interpreter.
 - Demonstrate a JSON parser. Show the grammar in GraphViz.

Documentation
=============
We will use Doxygen to document code, and follow GLib/GObject conventions.

Implementation
==============
Visitors and Visitables
-----------------------
At a high level, we split implementation classes into two types:

 - *Visitable* classes are data structures that have a single `void* accept (visitor* v)` virtual method.
 - *Visitor* classes traverse data structures (Visitables) to work, and have `void* visit(visitable* v)` virtual methods for each class they visit.

### Generic visitors
These visitor classes should apply to every visitable class.

 - ToString. Write out a textual representation of the structure.
 - ToGraphViz. Write out a GraphViz representation of the structure.
 - ToCode. Write out equivalent C source code.

Classes
-------
### Regular Expression
The main class `Regex` should be a Factory for these visitable classes, with appropriate static methods to build these classes.
These classes are structural, and don't do anything other than support visitors.

 - EmptySet (Singleton). Rejects everything.
 - EmptyString (Singleton). Accepts "".
 - Symbol (Flyweight). Accepts a given symbol in a given alphabet.
 - Concatenation. Accepts a followed by b.
 - Alternation. Accepts a or b.
 - KleeneStar. Accepts a 0 or more times.
 - Complement. Accepts anything but a.

### Regular Expression visitors:
Note that Regex here refers to the Regular expression data structures, not the Regex class.

 - Optimizer (Regex -> Regex)
 - Derivative Matcher (Regex, Symbol -> Regex)
 - NFA conversion (Regex -> NFA)
 - Grammar conversion (Regex -> CFG)

### Scanner
This uses regular expressions to tokenize strings.

### Context free
These classes are structural as well, and don't do anything but support different visitors.

 - Nonterminal
 - Terminal
 - Grammar

#### Context free visitors:
These classes prepare for parsing.

 - Compaction / Optimization (CFG -> CFG)
 - Derivative (CFG, Terminal -> CFG)
 - LR (CFG -> DPDA)
 - GLR (CFG -> NPDA)

### Automata
Finite automaton is the base class for these classes, and should support automata visitors.
These automata should also do matching or parsing.

 - Nondeterministic (NFA)
 - Deterministic (DFA)
 - Pushdown (PDA)

#### Automata visitors:
These visitors traverse the autmata themselves.

 - Make deterministic (NFA -> PDA)
 - Optimize (DFA -> DFA)
 - Optimize (PDA -> PDA)
 - Conversion (NFA -> Regex)
 - Conversion (DFA -> Regex)
 - Conversion (PDA -> CFG)

### Extras
Beyond this, once context-free parsing works, an API on top should support these:

 - Backus-Naur Form. Parse BNF strigs into CFG structure.
 - Regex strings. Parse regular expression strings into the Regex structure.