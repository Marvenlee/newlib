#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <paths.h>


#define MAX_ENTROPY     256

int getentropy(void *buf, size_t buflen)
{
  int ret = -1;

	if (buflen > MAX_ENTROPY) {
		errno = -EIO;
		return -1;
	}

	int fd = open(_PATH_RANDOM, O_RDONLY);
	if (fd >= 0) {
		ret = read(fd, buf, buflen);
		close(fd);
	}

  return (ret == buflen) ? 0 : -1;
}

