#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
int close (int fd)
{
    int sc;
    
    sc = _swi_close(fd);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;	
}

