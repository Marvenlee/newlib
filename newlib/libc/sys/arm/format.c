#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscall.h>


/*
 *
 */
int kos_format (char *mount, char *label, unsigned long flags, unsigned long cluster_size)
{
    errno = ENOSYS;
    return -1;
}


