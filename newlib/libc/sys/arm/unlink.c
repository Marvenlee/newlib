#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/* @brief Remove a file
 *
 */
int unlink (const char *path)
{
    int sc;
    
  	sc = _swi_unlink(path);
  	
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;	
}

