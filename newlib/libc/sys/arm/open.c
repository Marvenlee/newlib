#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdarg.h>


/*
 *
 */
int open (const char *file, int flags, ...)
{
    int mode;
    int fd;

    va_list ap;

    va_start(ap, flags);

    if (flags & O_CREAT)
        mode = va_arg(ap, int);
    else
        mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    va_end(ap);

    fd = _swi_open (file, flags, mode);

    if (fd < 0) {
        errno = -fd;
        return -1;
    }

    return fd;
}

