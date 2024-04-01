#include <sys/types.h>
#include <dirent.h>
#include <sys/syscalls.h>
#include <errno.h>



void rewinddir (DIR *dir)
{    	
    int sc;
    
    if (dir == NULL)
    {
        errno = EINVAL;
        return;
    }

    sc = _swi_rewinddir(dir->fd);

    if (sc < 0) {
        errno = -sc;
        return;
    }

    dir->buf_offset = 0;
    dir->buf_sz = 0;
    dir->eof = false;    
    return;
}


