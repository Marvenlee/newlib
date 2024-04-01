#include <_syslist.h>
#include <sys/types.h>
#include <sys/syscalls.h>
#include <stdlib.h>
#include <errno.h>


/*
 *
 */
void *virtualalloc (void *addr, size_t size, bits32_t flags)
{
    return _swi_virtualalloc(addr, size, flags);
}


/*
 *
 */
void *virtualallocphys (void *addr, size_t size, bits32_t flags, void *phys_addr)
{
    return _swi_virtualallocphys(addr, size, flags, phys_addr);
}


/*
 *
 */
int virtualfree (void *addr, size_t size)
{
    int sc;
      
    sc = _swi_virtualfree(addr, size);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}


/*
 *
 */
int virtualprotect (void *addr, size_t sz, bits32_t flags)
{
    int sc;
      
    sc = _swi_virtualprotect(addr, sz, flags);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }
    
    return 0;
}


/*
 *
 */
void *virtualtophysaddr(void *addr)
{
    return _swi_virtualtophysaddr(addr);
}

