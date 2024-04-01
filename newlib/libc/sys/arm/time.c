#include <_ansi.h>
#include <_syslist.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>
#include <utime.h>
#include <errno.h>


/*
 *
 */
time_t time (time_t *tloc)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	
	return tv.tv_sec;
}


/* @brief		TODO: Set the timestamp of a file
 *
 */
int utime(const char *path, const struct utimbuf *times)
{
	return 0;
}


