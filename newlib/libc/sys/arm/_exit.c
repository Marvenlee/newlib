#include <limits.h>
#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/debug.h>




/*
 * Exit, flushing stdio buffers if necessary.
 */

void _exit (int rc)
{
	  _swi_exit (rc);
	  while (1);
}
