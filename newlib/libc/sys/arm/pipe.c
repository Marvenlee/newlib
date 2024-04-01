#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/*
 * pipe()
 */ 
int pipe (int fdp[2])
{
    int sc;

    sc = _swi_pipe(fdp);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return 0;
}


