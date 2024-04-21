#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/*
 *
 */
int addinterruptserver(int irq, int thread_id, int event)
{
    int sc;
    
    sc = _swi_addinterruptserver(irq, thread_id, event);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}


/*
 *
 */
int maskinterrupt(int irq)
{
    int sc;
    
    sc = _swi_maskinterrupt(irq);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

/*
 *
 */
int unmaskinterrupt(int irq)
{
    int sc;
    
    sc = _swi_unmaskinterrupt(irq);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

