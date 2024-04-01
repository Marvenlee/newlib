#include <_ansi.h>
#include <_syslist.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>
#include <errno.h>


/* @brief Sleep for a number of seconds
 *
 */
unsigned int sleep (unsigned int seconds)
{
    int sc;

    sc = _swi_sleep(seconds);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return 0;
}


/*
 *
 */
int nanosleep (const struct timespec *req, struct timespec *rem)
{
    int sc;

    sc = _swi_nanosleep(req, rem);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return 0;	
}

