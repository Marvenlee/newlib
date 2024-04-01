#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>


/*
 *
 */
ssize_t read (int fd, void *buf, size_t nbyte)
{
  ssize_t sz;

  sz = _swi_read(fd, buf, nbyte);

  if (sz < 0) {
    errno = -sz;
    return -1;
  }

  return sz;
}

