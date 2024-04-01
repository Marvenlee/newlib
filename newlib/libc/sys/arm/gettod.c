#include <_ansi.h>
#include <_syslist.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
int gettimeofday (struct timeval *tp, void *tzp)
{
    int sc;

    sc = _swi_gettimeofday(tp);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return 0;
}


/*
 *
 */
int settimeofday(const struct timeval *tp, const struct timezone *tzp)
{
    int sc;

    sc = _swi_settimeofday(tp);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return 0;
}






