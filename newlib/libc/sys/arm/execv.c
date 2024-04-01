#include <_ansi.h>
#include <unistd.h>

/*
 *
 */
static char ***p_environ = &environ;


/*
 *
 */
int execv (const char *path, char * const argv[])
{
    return execve (path, (char **) argv, *p_environ);
}

