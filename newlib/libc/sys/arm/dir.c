#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscalls.h>
#include <sys/param.h>
#include <errno.h>


/*
 *
 */
char *getwd (char *__buf )
{
    return getcwd (__buf, MAXPATHLEN);
}

/*
 *
 */
int chroot(const char *path)
{
    int sc;
    
    sc = _swi_chroot(path);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

/*
 *
 */
int chdir (const char *path)
{
    int sc;
    
    sc = _swi_chdir(path);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return 0;
}

/*
 *
 */
int fchdir (int fd)
{
    int sc;
    
    sc = _swi_fchdir (fd);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	  return 0;
}

/*
 *
 */
int mkdir (const char *path, mode_t mode)
{
    int sc;
    
    sc = _swi_mkdir (path, mode);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	  return 0;
}

/*
 *
 */
int rmdir (const char *path)
{
    int sc;
    
    sc = _swi_rmdir (path);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	  return 0;
}


