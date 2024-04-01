#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
int fstat(int fd, struct stat *buf)
{
    int sc;
    
    sc = _swi_fstat(fd, buf);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}


/*
 *
 */
int stat (const char *path, struct stat *buf)
{
    int sc;

    sc = _swi_stat(path, buf);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}


/*
 *
 */
int lstat (const char *pathname, struct stat *st)
{
    return stat(pathname, st);
}


/*
 *
 */
int statfs(const char *path, struct statfs *buf)
{
    errno = ENOSYS;
    return -1;
}


/*
 *
 */
int fstatfs(int fd, struct statfs *buf)
{
    errno = ENOSYS;
    return -1;
}



