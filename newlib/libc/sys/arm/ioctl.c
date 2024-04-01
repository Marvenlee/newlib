#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdarg.h>


int ioctl (int fd, int request, ... )
{
    va_list ap;
    int sc;

    va_start(ap, request);
    sc = _swi_ioctl(fd, request, va_arg(ap, void *));
    va_end(ap);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


