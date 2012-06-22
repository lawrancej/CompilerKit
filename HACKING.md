Hacking CompilerKit
===================
## Status
- [Ohloh tracker](https://www.ohloh.net/p/CompilerKit)

## Getting started
1. Install the dependencies for your platform.
    - [Windows](#what-to-install-on-windows)
    - [Linux](#what-to-install-on-linux)
    - [Mac](#what-to-install-on-mac)
2. [Fork the project here.](https://github.com/lawrancej/CompilerKit/fork)
3. [Build CompilerKit.](#how-do-i-build-compilerkit)
4. [Read Documentation.](#where-is-the-documentation)
5. [Learn how to contribute.](#how-to-contribute)

## What to install on Windows
You will need to download and install everything manually.
Therefore, verify everything is working first before building CompilerKit.

 - Visual Studio 2010 or [MinGW](http://sourceforge.net/projects/mingw/files/latest/download?source=files)
 - [Git (version control).](http://git-scm.com/downloads)
 - [CMake.](http://www.cmake.org/cmake/resources/software.html)
 - [Doxygen.](http://www.stack.nl/~dimitri/doxygen/download.html#latestsrc)
 - [GLib and GObject.](http://ftp.gnome.org/pub/gnome/binaries/win32/gtk+/2.24/gtk+-bundle_2.24.10-20120208_win32.zip) Extract to `C:\glib`. Add `C:\glib\bin` to the system PATH.

### How do I know it's working?
Open Git Bash to the `CompilerKit` folder. Type in the first line. Did you see the rest? You should.
```
pkg-config --list-all
gio-2.0               GIO - glib I/O library
gmodule-2.0           GModule - Dynamic module loader for GLib
glib-2.0              GLib - C Utility Library
gmodule-no-export-2.0 GModule - Dynamic module loader for GLib
gthread-2.0           GThread - Thread support for GLib
gobject-2.0           GObject - GLib Type, Object, Parameter and Signal Library
```

Did you see `command not found` after typing these into Git Bash? You should not.

 - `doxygen`
 - `cmake`

## What to install on Linux
In the terminal, paste this in for your distribution:

### Red Hat:

    sudo yum install git cmake doxygen glib-devel pkgconfig

### Debian, Ubuntu:

    sudo apt-get install git cmake doxygen libglib2.0-dev pkg-config

## What to install on Mac
If you do not already have it, install:

 - [Command Line Tools for Xcode](https://developer.apple.com/downloads) or [Xcode](http://itunes.apple.com/us/app/xcode/id448457090)
 - [Java Developer Update](https://connect.apple.com)

In the terminal, paste this in:

    /usr/bin/ruby -e "$(/usr/bin/curl -fsSL https://raw.github.com/mxcl/homebrew/master/Library/Contributions/install_homebrew.rb)"
    
Once installed, paste this into the Terminal:

    brew install git cmake doxygen glib pkg-config

### Troubleshooting
If you see the following error when using CMake on the Mac:

```
build User$ cmake ..
CMake Error: CMake was unable to find a build program corresponding to "Unix Makefiles". CMAKE_MAKE_PROGRAM is not set. You probably need to select a different build tool.
CMake Error: Error required internal CMake variable not set, cmake may be not be built correctly.
Missing variable is:
CMAKE_C_COMPILER_ENV_VAR
CMake Error: Error required internal CMake variable not set, cmake may be not be built correctly.
Missing variable is:
CMAKE_C_COMPILER
CMake Error: Could not find cmake module file:/Users/User/CompilerKit/build/CMakeFiles/CMakeCCompiler.cmake
CMake Error: CMAKE_C_COMPILER not set, after EnableLanguage
-- Configuring incomplete, errors occurred!
```

Follow these steps to fix the error:

1.	Open XCode
2.	Go to Preferences
3.	Download tab
4.	Install Command line

## How do I build CompilerKit?
CompilerKit builds with CMake. 

The first time you build, do this:

```
mkdir build && cd build
cmake ..
cmake --build .
```


For subsequent builds, in the `build` folder, just run `cmake --build .`

## Where is the documentation?
[CompilerKit uses Doxygen](#what-is-doxygen) to generate documentation. After building CompilerKit, look inside the `docs/html` folder.

Also, read up on [GLib](#how-do-i-use-glib) and [GObject](#how-do-i-use-gobject).

## What is Doxygen?
Doxygen generates documentation in HTML, LaTeX, RTF (MS-Word) using specially-formatted comments.
It can also extract the code structure from undocumented source files for many programming languages (C/C++, Java, Python, etc).

Example comment:
```
/**
 * compilerkit_visitor_register:
 * @fn compilerkit_visitor_register
 * @memberof CompilerKitVisitor
 * Associate the GType of a class with a visitor function.
 * @pre CompilerKitVisitor* is not NULL.
 * @param CompilerKitVisitor* The visitor instance.
 * @param GType The type of the class to visit.
 * @param CompilerKitVisitorFunc A pointer to a visitor function for the specified type.
 * @return void
 */
```

![A graph of how Doxygen works](images/Doxygen.png)

## How to contribute
### Know thy code layout
The folder structure of CompilerKit is as follows:

```
.boilerplate        Contains boilerplate that ./generate.sh copies to the appropriate folderss.
build               You should make this folder yourself and run cmake inside there. Executables are here.
build/Debug         The folder where executables go in Windows.
docs                Once you've built CompilerKit, all generated documentation goes there. Read it!
examples            Source code demonstrations for how to use each class. Shows up in the documentation.
include             The include files for the CompilerKit library.
src                 The CompilerKit library source code.
tests               The test suite to exercise the CompilerKit library.
```

The regex classes are:
* CompilerKitSymbol
* CompilerKitEmptySet,
* CompiletKitEmptystring
* CompilerKitConcatenation
* CompilerKitAlternation
* CompilerKitKleenestar
* CompilerKitComplement

The cfg classes are:
* CompilerKitGrammar
* CompilerKitTerminal
* CompilerKitNonterminal
* CompilerKitProduction

### Find an issue to work on
We use github's [issue tracker](https://github.com/lawrancej/CompilerKit/issues) to manage our work.
Check there to find unassigned issues (comment on an issue to get dibs).
Even better, find an issue yourself and [file a bug report.](https://github.com/lawrancej/CompilerKit/issues/new)
Or, best of all, pair up and split the work on an issue with someone else. 

### Use topic branches for your work
Topic branches isolate chunks of work so that it's easier to merge in changes.
Here's how it works:

```
git checkout -b issueXYZ # Create a new local branch issueXYZ
... Hack away ...
git commit -a -m "Work in progress on issueXYZ"
git push origin issueXYZ # Push local branch to remote repo
```

Using topic branches means you'll need to know how to switch among branches and remove old branches as necessary.

- To switch back to master, type: `git checkout master`
- To see the branches, type: `git branch`
- To remove a local branch, type: `git branch -D branch_name`
- To remove a remote branch, type: `git push origin :branch_name`

You will also need to understand merging.

- If you haven't already done so, type: `./collaborators.sh setup`
- To get everyone's updates, type: `git fetch --all`
- To see a list of remotes, type: `git remote`
- To merge in changes from `contributor`'s `branch` into your current branch, type: `git merge contributor/branch`
- To deal with merge conflicts, type: `git status`. Then, open up all unstaged files. Make changes as necessary, and do `git add file_name` for each file.
- To merge in only the version from `somebranch`, type: `git checkout somebranch file_name`

### Test your changes
I will not merge code into my master branch until:

 - The [project builds successfully.](#how-do-i-build-compilerkit)
 - It has a demo (see `examples/`).
 - Test cases pass in the test suite (see `tests/test-suite.c` and `tests/test-suite.h`)
 - [The documentation looks as expected](#where-is-the-documentation).

Look for the demo and test suite executables in these folders:

 - `build/Debug` (Windows)
 - `build` (Mac, Linux)

### Send in a pull request for feedback
Switch to your branch in github, and [send in a pull request](https://github.com/lawrancej/CompilerKit/pull/new/master) that describes what you did.
Do so when you think your changes are ready to be merged in. But do not hesitate to push works in progress.

## How do I use GLib?
GLib is a C utility library similar to the Standard Template Library in C++. It provides data structures as well as [GObject](#how-do-i-use-gobject).

To use it, read these first:

* [Documentation for GLib](http://developer.gnome.org/glib/stable/)
* [GLib Hash table tutorial](http://www.ibm.com/developerworks/linux/tutorials/l-glib/section5.html)

## What do the GObject macros mean?
Let's compare with some examples.

```
GObject                                Java/C#
(prefix everything with COMPILERKIT)   package CompilerKit;
COMPILERKIT_IS_ALTERNATION(obj)        (obj instanceof Alternation)
COMPILERKIT_ALTERNATION (obj)          (Alternation) obj
COMPILERKIT_TYPE_ALTERNATION           Alternation.class
G_OBJECT_TYPE (obj)                    obj.getClass()
compilerkit_alternation_get_left(alt)  alt.getLeft()
```

## How do I use GObject?
GObject may seem intimidating. Learn how it works, and realize that OOP languages provide a lot of shortcuts that C exposes to the programmer.

To use GObject, read these first:

* [GObject Tutorial](http://syscall.org/doku.php/gobjectutorial/start)
* [GObject FAQ](http://irrepupavel.com/documents/gtk/gobject-faq.html)
* [GObject Documentation](http://developer.gnome.org/gobject/stable/)

## How do I write GObject classes?
Run `./generate.sh`, and follow the instructions.
