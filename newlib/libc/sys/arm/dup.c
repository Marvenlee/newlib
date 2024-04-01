#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscalls.h>


/*
 *
 */
int dup(int fd) {
    int dfd;

    dfd = _swi_dup(fd);
    if (dfd < 0) {
        errno = -dfd;
        return -1;
    }

    return dfd;
}

/*
 *
 */
int dup2(int fd1, int fd2) {
    int dfd;

    dfd = _swi_dup2(fd1, fd2);
    if (dfd < 0) {
        errno = -dfd;
        return -1;
    }

    return dfd;
}

