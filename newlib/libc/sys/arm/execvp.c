/* execvp.c */

/* This and the other exec*.c files in this directory require 
   the target to provide the _execve syscall.  */

#include <_ansi.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define PATH_DELIM ':'

/*
 * Copy string, until c or <nul> is encountered.
 * NUL-terminate the destination string (s1).
 */

static char *strccpy (char *s1, char *s2, char c)
{
    char *dest = s1;

    while (*s2 && *s2 != c) {
        *s1++ = *s2++;
    }
    *s1 = 0;

    return dest;
}

/*
 *
 */
int execvp (const char *file, char * const argv[])
{
  char *path = getenv ("PATH");
  char buf[MAXNAMLEN];

  if (!path)
    return execv (file, argv);

  if (strchr (file, '/'))
    return execv (file, argv);

  while (*path) {
      strccpy (buf, path, PATH_DELIM);

      if (*buf != 0 && buf[strlen(buf) - 1] != '/')
          strcat (buf, "/");
      
      strcat (buf, file);
      
      if (execv (buf, argv) == -1 && errno != ENOENT)
          return -1;
      
      while (*path && *path != PATH_DELIM) {
        path++;
      }
      
      if (*path == PATH_DELIM)
         path++;
  }

  return -1;
}

