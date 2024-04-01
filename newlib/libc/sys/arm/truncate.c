#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscalls.h>


/* @brief Truncate an already open file
 *
 */
int ftruncate (int fd, off_t size)
{
    int sc;
    
    sc = _swi_truncate(fd, size);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}


/* @brief Truncate a file
 *
 */
int truncate (const char *path, off_t size)
{
    int fd;
    int sc;
    
    fd = open(path, O_WRONLY);
    
    if (fd < 0) {
      errno = -fd;
      return -1;
    }
        
    sc = _swi_truncate(fd, size);
    close(fd);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}

