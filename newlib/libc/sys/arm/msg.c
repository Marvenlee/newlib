#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscalls.h>


/*
 *
 */

int sendrec(int fd, int siov_cnt, struct IOV *siov, int riov_cnt, struct IOV *riov)
{
    int sc;

    sc = _swi_sendrec(fd, siov_cnt, siov, riov_cnt, riov);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


/*
 *
 */
int getmsg(int portid, msgid_t *msgid, void *buf, size_t buf_sz)
{
    int sc;

    sc = _swi_getmsg(portid, msgid, buf, buf_sz);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}

/*
 *
 */
int replymsg(int portid, msgid_t msgid, int status, void *buf, size_t buf_sz)
{
    int sc;

    sc = _swi_replymsg(portid, msgid, status, buf, buf_sz);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}

/*
 *
 */
int readmsg(int portid, msgid_t msgid, void *buf, size_t buf_sz, off_t offset)
{
    int sc;

    sc = _swi_readmsg(portid, msgid, buf, buf_sz, offset);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}

/*
 *
 */
int writemsg(int portid, msgid_t msgid, void *buf, size_t buf_sz, off_t offset)
{
    int sc;

    sc = _swi_writemsg(portid, msgid, buf, buf_sz, offset);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}

