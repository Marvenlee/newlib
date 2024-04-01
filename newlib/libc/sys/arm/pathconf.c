#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>



long fpathconf(int filedes, int name)
{
    return -1;
}


long pathconf(const char *path, int name)
{
    return -1;
}


