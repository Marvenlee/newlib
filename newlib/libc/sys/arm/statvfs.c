#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
int fstatvfs (int fd, struct statvfs *st)
{
  errno = ENOSYS;
	return -1;
}


/*
 *
 */
int statvfs (const char *pathname, struct statvfs *st)
{
	int fd;
	
	
	if ((fd = open (pathname, O_RDONLY)) < 0) {
		return -1;
	}
	
	if (fstatvfs (fd, st) < 0) {
		return -1;
  }
  
	if (close(fd) <	0) {
		return -1;
	}
	
	return 0;
}

