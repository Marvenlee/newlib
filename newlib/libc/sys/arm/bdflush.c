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
int bdflush(int fd)
{
    int sc;
    
    sc = _swi_bdflush(fd);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}

