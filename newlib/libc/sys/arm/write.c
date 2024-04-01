#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>

/* @brief Write to a file
 * 
 */
ssize_t write (int fd, const void *buf, size_t nbyte)
{
    ssize_t sz;
    
    sz = _swi_write(fd, buf, nbyte);
    
    if (sz < 0) {
        errno = -sz;
        return -1;
    }
	
	return sz;
}

