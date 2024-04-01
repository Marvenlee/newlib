#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>


/*
 * fcntl();
 */
int fcntl(int fd, int cmd, ...)
{
    va_list ap;
    int arg;
    int rc;

    va_start(ap, cmd);

    switch (cmd) {
	      case F_DUPFD:
	      case F_SETFD:
	      case F_SETFL:
	      case F_SETOWN:
		        arg = va_arg(ap, int);
		        rc = _swi_fcntl(fd, cmd, arg);
		
		        if (rc < 0) {
		          errno = -rc;
		          rc = -1;
		        }
		
		        break;

	      case F_GETFD:
	      case F_GETFL:
	      case F_GETOWN:
		        rc = _swi_fcntl(fd, cmd, 0);

		        if (rc < 0) {
		          errno = -rc;
		          rc = -1;
		        }

		        break;

	      default:
		        errno = EINVAL;
		        rc = -1;
    }

    va_end(ap);
    return rc;
}

