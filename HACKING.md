Hacking CompilerKit
===================
Get up-to-speed with CompilerKit development. 

1. [Install all dependencies.](#what-software-do-i-need)
2. [Build CompilerKit](#how-to-build-compilerkit)

## What software do I need?
- A C compiler (e.g., Visual Studio, Xcode, gcc, [MinGW](http://sourceforge.net/projects/mingw/files/latest/download?source=files), or Clang)
- [Git (version control)](http://git-scm.com/downloads)
- [CMake](http://www.cmake.org/cmake/resources/software.html)
- [Doxygen](http://www.stack.nl/~dimitri/doxygen/download.html#latestsrc)
- [GLib](http://www.gtk.org/download/index.php)

## How do I install GLib and GObject?
CompilerKit depends on [GLib](http://developer.gnome.org/glib/) and [GObject](http://developer.gnome.org/gobject/).

Installation instructions for GLib depends on the platform:

### On Windows:
1. Go here: <http://www.gtk.org/download/win32.php>
2. Download 
    * [GLib Dev](http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib-dev_2.28.8-1_win32.zip) 
    * [pkg-config Tool](http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/pkg-config_0.26-1_win32.zip)
    * [GLib Run-time](http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib_2.28.8-1_win32.zip)
    * [gettext-runtime Run-time](http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/gettext-runtime_0.18.1.1-2_win32.zip)
    * [gettext-dev](http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/gettext-runtime-dev_0.18.1.1-2_win32.zip)
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

## How do I use GLib?
GLib is a C utility library similar to the Standard Template Library in C++. It provides data structures as well as [GObject](#how-do-i-use-gobject).

To use it, read the following:

* [Documentation for GLib](http://developer.gnome.org/glib/stable/)
* [GLib Hash table tutorial](http://www.ibm.com/developerworks/linux/tutorials/l-glib/section5.html)

## How do I use GObject?
GObject may seem intimidating. Learn how it works, and realize that OOP languages provide a lot of shortcuts that C exposes to the programmer.

To use GObject, read the following:

* [GObject Tutorial](http://syscall.org/doku.php/gobjectutorial/start)
* [GObject FAQ](http://irrepupavel.com/documents/gtk/gobject-faq.html)
* [GObject Documentation](http://developer.gnome.org/gobject/stable/)

## How do I write GObject classes?
Run `./generate.sh`, and follow the instructions.

## How to build CompilerKit?
CompilerKit builds with CMake. Simply do this:

```
mkdir build && cd build
cmake ..
cmake --build .
```
