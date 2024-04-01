#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
int closedir (DIR *dir)
{
    int sc;
    	
    if (dir == NULL) {
        errno = EINVAL;
        return -1;
    }

    sc = _swi_close (dir->fd);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    free (dir->buf);
    free (dir);
    return 0;
}

