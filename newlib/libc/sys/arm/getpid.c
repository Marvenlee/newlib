#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <unistd.h>


/*
 *
 */
pid_t getpid(void)
{
    pid_t pid;
    
    pid = _swi_getpid();

    return pid;
}


/*
 *
 */
pid_t getppid(void)
{
    pid_t ppid;
    
    ppid = _swi_getppid();
    
    return ppid;
}


