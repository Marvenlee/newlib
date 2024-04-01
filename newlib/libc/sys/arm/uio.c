#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>


/*
 *
 */
ssize_t readv(int fd, const struct iovec *iov, int iov_cnt)
{
	ssize_t total;
	ssize_t xfered;
	
	for (int t=0; t<iov_cnt; t++) {
		xfered = read(fd, iov[t].iov_base, iov[t].iov_len);
		
		if (xfered < 0) {
			return xfered;
		}

		total += xfered;
		
		if (xfered != iov[t].iov_len) {
			break;
		}		
	}
	
	return total;
}
	

/*
 *
 */
ssize_t writev(int fd, const struct iovec *iov, int iov_cnt)
{
	ssize_t total;
	ssize_t xfered;
	
	for (int t=0; t<iov_cnt; t++) {
		xfered = write(fd, iov[t].iov_base, iov[t].iov_len);
		
		if (xfered < 0) {
			return xfered;
		}

		total += xfered;
		
		if (xfered != iov[t].iov_len) {
			break;
		}		
	}
	
	return total;
}

