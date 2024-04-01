#include <_ansi.h>
#include <_syslist.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>
#include <utime.h>
#include <errno.h>


/* @brief		Helper function to subtract time t2 from time t1
 *
 * @return	1 if t2 is after or equal to t1, else return 0.
 */
int diff_timespec(struct timespec *result, struct timespec *t2, struct timespec *t1)
{
  result->tv_nsec = t2->tv_nsec - t1->tv_nsec;
  result->tv_sec  = t2->tv_sec - t1->tv_sec;

  if (result->tv_sec > 0 && result->tv_nsec < 0)
  {
      result->tv_nsec += 1000000000;
      result->tv_sec--;
  }
  else if (result->tv_sec < 0 && result->tv_nsec > 0)
  {
      result->tv_nsec -= 1000000000;
      result->tv_sec++;
  }

  return (result->tv_sec >= 0 && result->tv_nsec >= 0) ? 1 : 0;
}


/* @brief		Helper function to add t2 to t1
 *
 */
void add_timespec(struct timespec *result, struct timespec *t2, struct timespec *t1)
{
  result->tv_sec = t2->tv_sec + t1->tv_sec;
  result->tv_nsec = t2->tv_nsec + t1->tv_nsec;
  
  if (result->tv_nsec >= 1000000000) {
    result->tv_nsec -= 1000000000;
    result->tv_sec++;
  }
}


