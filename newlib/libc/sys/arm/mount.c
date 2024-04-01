#include <_ansi.h>
#include <errno.h>
#include <sys/mount.h>
#include <sys/syscalls.h>


/*
 * TODO: Rename to createmsgport
 *
 * Add separate library functions that handles mounting
 * by launching and detaching the appropriate filesystem handler. 
 */
int createmsgport(char *path, uint32_t flags, struct stat *stat, int backlog)
{
    int sc;
    
    sc = _swi_mount(path, flags, stat, backlog);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

/*
 *
 */
int unmount(int fd, bool force)
{
    int sc;
    
    sc = _swi_unmount(fd, force);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

/*
 *
 */
int renamemsgport(char *new_path, char *old_path)
{
    int sc;
    
    sc = _swi_renamemsgport(new_path, old_path);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

/*
 *
 */
int pivotroot(char *new_root, char *old_root)
{
    int sc;
    
    sc = _swi_pivotroot(new_root, old_root);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

/*
 *
 */
int getfsstat(struct statfs *buf, int bufsize, int flags)
{
    return 0;
}

/*
 *
 */
int getmntinfo(struct statfs **mntbufp, int flags)
{
    return 0;
}

