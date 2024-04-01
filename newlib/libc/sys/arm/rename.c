#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/*
 * open();
 *
 * Needs fixing, to use the vararg 'mode' depending on flags.
 */

int rename (const char *oldname, const char *newname)
{
    int sc;

    sc = _swi_rename(oldname, newname);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}

