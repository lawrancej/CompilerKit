#include <stdio.h>
#include <glib.h>
#include "CompilerKit.h"

int main (int argc, char ** argv)
{
#ifdef G_OS_WIN32
    printf ("Hello, Windows!");
#endif
#ifdef G_OS_UNIX
    printf ("Hello, Unix!\n");
#endif
}