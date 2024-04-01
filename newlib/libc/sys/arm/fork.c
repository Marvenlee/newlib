#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
int fork(void)
{
    int pid;
    
    pid = _swi_fork();
    
    if (pid < 0) {
        errno = -pid;
        return -1;
    }
    
    return pid;    
}

