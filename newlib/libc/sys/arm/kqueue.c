#include <stdint.h>
#include <sys/event.h>
#include <sys/syscalls.h>
#include <errno.h>

int kqueue(void)
{
    int kq;
    
    kq = _swi_kqueue();
    
    if (kq < 0) {
        errno = -kq;
        return -1;
    }
    
    return kq;    

}

int kevent(int kq, const struct kevent *changelist, int nchanges,
	    struct kevent *eventlist, int nevents,
	    const struct timespec *timeout)
{
    int sc;
    
    sc = _swi_kevent(kq, changelist, nchanges, eventlist, nevents, timeout);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return sc;    

}

