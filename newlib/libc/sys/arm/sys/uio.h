#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#include <sys/cdefs.h>
#include <sys/types.h>

#define UIO_MAXIOV 64

struct iovec {
	void *iov_base;
	size_t iov_len;
};

ssize_t readv(int fd, const struct iovec *iov, int iovcnt);
ssize_t writev(int fd, const struct iovec *iov, int iovcnt);

#endif

