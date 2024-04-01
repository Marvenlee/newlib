#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <unistd.h>


/*
 *
 */
unsigned int alarm (unsigned int seconds)
{
    return _swi_alarm(seconds);
}

