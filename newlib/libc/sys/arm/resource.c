#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <sys/resource.h>
#include <sys/types.h>


/*
 *
 */
int getpriority(int which, id_t who)
{
	int sc;
	int prio;
	
	if (which != PRIO_PROCESS) {
		errno = ENOSYS;
		return -1;
	}

	sc = _swi_get_priority(who, &prio);
	if (sc != 0) {
		errno = -sc;
		return -1;
	}

	errno = 0;
	return prio;
}


/*
 *
 */
int setpriority(int which, id_t who, int prio)
{
	int sc;
	
	if (which != PRIO_PROCESS) {
		errno = ENOSYS;
		return -1;
	}

	sc = _swi_setpriority(who, prio);
	if (sc < 0) {
		errno = -sc;
		return -1;
	}

	return sc;
}


/*
 *
 */
int getrlimit(int resource, struct rlimit *rlp)
{
  errno = ENOSYS;
  return -1;
}


/*
 *
 */
int setrlimit(int resource, const struct rlimit *rlp)
{
  errno = ENOSYS;
  return -1;
}


/*
 *
 */
int getrusage(int who, struct rusage *usage)
{
	errno = ENOSYS;
	return -1;
}

