#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/*
 *
 */
off_t lseek (int fd, off_t offset, int whence)
{
    int sc;
    
    sc = _swi_lseek(fd, offset, whence);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}


/*
 *
 */
off64_t lseek64 (int fd, off64_t offset, int whence)
{
    int sc;
    
    sc = _swi_lseek64(fd, &offset, whence);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return offset;
}

