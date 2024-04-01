#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/*
 *
 */
int createinterrupt (int irq, void (*interrupt_handler)(int irq, struct InterruptAPI *api))
{
    int sc;
    
    sc = _swi_createinterrupt(irq, interrupt_handler);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}


/*
 *
 */
int maskinterrupt (int irq)
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
int unmaskinterrupt (int irq)
{
    int sc;
    
    sc = _swi_unmaskinterrupt(irq);
    
    if (sc < 0) {
        errno = -sc;
        return -1;
    }
	
	return sc;
}

