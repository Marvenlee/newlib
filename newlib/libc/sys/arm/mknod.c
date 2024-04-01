#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <sys/stat.h>
#include <unistd.h>


/*
 *
 */
int mknod (const char *path, mode_t mode, dev_t dev)
{
    errno = ENOSYS;
    return -1;
}



/*
 *
 */
int mknod2(char *path, uint32_t flags, struct stat *stat)
{
    int sc;
    
    sc = _swi_mknod(path, flags, stat);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

