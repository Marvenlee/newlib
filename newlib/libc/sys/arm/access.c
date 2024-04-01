#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>


/*
 *
 */
int access(const char *path, int amode)
{
    int sc;
    
  	sc = _swi_access(path, amode);
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}


/*
 *
 */
mode_t umask(mode_t cmask)
{
    mode_t mask;
    
  	mask = _swi_umask(cmask);
    return mask;
}

