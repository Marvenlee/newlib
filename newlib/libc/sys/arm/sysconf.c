#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <unistd.h>
#include <errno.h>


/*
 *
 */
long sysconf(int name)
{
	errno = -ENOSYS;
	return -1;
}


/*
 *
 */
int getdtablesize(void)
{
	return 512;
}
