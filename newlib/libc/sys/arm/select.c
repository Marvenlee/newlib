#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <sys/signal.h>


/*
 *
 */
int poll (struct pollfd *pfds, nfds_t nfds, int timeout)
{
    int sc;

    sc = _swi_poll (pfds, nfds, timeout);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }  
    return sc;
}


/*
 *
 */
int pselect(int nfds, fd_set *readfds,
       fd_set *writefds, fd_set *errorfds,
       const struct timespec *timeout,
       const sigset_t *sigmask)
{
	  errno = EINTR;
	  return -1;
}

       
/* 
 *
 */    
int select(int nfds, fd_set *readfds,
       fd_set *writefds, fd_set *errorfds,
       struct timeval *timeout)
{
	  errno = EINTR;
	  return -1;
}

