#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/* @brief sync a specific file to non-volatile storage
 *
 */
int fsync (int fd)
{
    int sc;

    sc = _swi_fsync(fd);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


/* @brief sync all files to non-volatile storage
 *
 */
int sync (void)
{
    int sc;

    sc = _swi_sync();

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}

