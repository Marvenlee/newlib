#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
DIR *opendir (const char *path)
{
    DIR *dir;
    void *buf;
    int fd;

    if ((dir = malloc(sizeof (DIR))) == NULL) {
        return NULL;
    }
    
    if ((buf = malloc(DIRENTS_BUF_SZ)) == NULL) {
        free (dir);
        return NULL;
    }	
      
    fd = _swi_opendir(path);

    if (fd < 0) {
        free(buf);
        free(dir);
        errno = -fd;
        return NULL;
    }
		
    dir->fd = fd;
    dir->buf = buf;
    dir->buf_offset = 0; 
    dir->buf_sz = 0;
    dir->eof = false;
    return dir;
}


/*
 *
 */
int dirfd(DIR *dirp)
{
    return dirp->fd;
}


