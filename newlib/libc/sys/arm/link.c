#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <unistd.h>


/*
 *
 */
int link (const char *existing, const char *new)
{
    errno = ENOSYS;
    return -1;
}


/*
 *
 */
int readlink(const char *path, char *buf, size_t bufsize)
{
    int sc;
    
    sc = _swi_readlink(path, buf, bufsize);
    
    if (sc < 0) {
      errno = -sc;
      return -1;
    }
    
    return 0;
}


/*
 *
 */
int symlink(const char *path1, const char *path2)
{
    int sc;
    
    sc = _swi_symlink(path1, path2);
    
    if (sc < 0) {
      errno = -sc;
      return -1;
    }
    
    return 0;
}

