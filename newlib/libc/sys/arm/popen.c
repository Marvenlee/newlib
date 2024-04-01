#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <stdio.h>


/*
 *
 */
FILE *popen (const char *command, const char *mode)
{
    errno = ENOSYS;
    return NULL;
}


/*
 *
 */
int pclose (FILE *stream)
{
    errno = ENOSYS;
    return -1;
}



