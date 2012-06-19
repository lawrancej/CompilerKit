Hacking CompilerKit
===================
<https://www.ohloh.net/p/CompilerKit> <script type="text/javascript" src="http://www.ohloh.net/p/602736/widgets/project_partner_badge.js"></script>

To develop CompilerKit, 

1. Install the dependencies for your platform.
    - [Windows](#what-to-install-on-windows)
    - [Linux](#what-to-install-on-linux)
    - [Mac](#what-to-install-on-mac)
2. [Build CompilerKit.](#how-do-i-build-compilerkit)
3. [Read Documentation](#where-is-the-documentation)

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
After building CompilerKit, look inside the `docs/html` folder.

Also, read up on [GLib](#how-do-i-use-glib) and [GObject](#how-do-i-use-gobject).

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
```

## How do I use GObject?
GObject may seem intimidating. Learn how it works, and realize that OOP languages provide a lot of shortcuts that C exposes to the programmer.

To use GObject, read these first:

* [GObject Tutorial](http://syscall.org/doku.php/gobjectutorial/start)
* [GObject FAQ](http://irrepupavel.com/documents/gtk/gobject-faq.html)
* [GObject Documentation](http://developer.gnome.org/gobject/stable/)

## How do I write GObject classes?
Run `./generate.sh`, and follow the instructions.
