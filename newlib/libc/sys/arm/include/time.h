/*
 * time.h
 * 
 * Struct and function declarations for dealing with time.
 */

#ifndef _TIME_H_
#define _TIME_H_

#include "_ansi.h"
#include <sys/cdefs.h>
#include <sys/reent.h>

#define __need_size_t
#define __need_NULL
#include <stddef.h>

/* Get _CLOCKS_PER_SEC_ */
#include <machine/time.h>

#ifndef _CLOCKS_PER_SEC_
#define _CLOCKS_PER_SEC_ 100
#endif

#define CLOCKS_PER_SEC _CLOCKS_PER_SEC_
#define CLK_TCK CLOCKS_PER_SEC

#include <sys/types.h>
#include <sys/timespec.h>

#if __POSIX_VISIBLE >= 200809
#include <sys/_locale.h>
#endif

_BEGIN_STD_C

struct tm
{
  int	tm_sec;
  int	tm_min;
  int	tm_hour;
  int	tm_mday;
  int	tm_mon;
  int	tm_year;
  int	tm_wday;
  int	tm_yday;
  int	tm_isdst;
#ifdef __TM_GMTOFF
  long	__TM_GMTOFF;
#endif
#ifdef __TM_ZONE
  const char *__TM_ZONE;
#endif
};

clock_t	   clock (void);
double	   difftime (time_t _time2, time_t _time1);
time_t	   mktime (struct tm *_timeptr);
time_t	   time (time_t *_timer);

#ifndef _REENT_ONLY
char	  *asctime (const struct tm *_tblock);
char	  *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);
#endif

size_t	   strftime (char *__restrict _s,
			     size_t _maxsize, const char *__restrict _fmt,
			     const struct tm *__restrict _t);

int diff_timespec(struct timespec *result, struct timespec *t2, struct timespec *t1);
void add_timespec(struct timespec *result, struct timespec *t2, struct timespec *t1);


#if __POSIX_VISIBLE >= 200809
extern size_t strftime_l (char *__restrict _s, size_t _maxsize,
			  const char *__restrict _fmt,
			  const struct tm *__restrict _t, locale_t _l);
#endif

char	  *asctime_r 	(const struct tm *__restrict,
				 char *__restrict);
char	  *ctime_r 	(const time_t *, char *);
struct tm *gmtime_r 	(const time_t *__restrict,
				 struct tm *__restrict);
struct tm *localtime_r 	(const time_t *__restrict,
				 struct tm *__restrict);

_END_STD_C

#ifdef __cplusplus
extern "C" {
#endif

#if __XSI_VISIBLE
char      *strptime (const char *__restrict,
				 const char *__restrict,
				 struct tm *__restrict);
#endif
#if __GNU_VISIBLE
char *strptime_l (const char *__restrict, const char *__restrict,
		  struct tm *__restrict, locale_t);
#endif

#if __POSIX_VISIBLE
void      tzset 	(void);
#endif
void      _tzset_r 	(struct _reent *);

/* getdate functions */

#ifdef HAVE_GETDATE
#if __XSI_VISIBLE >= 4
#ifndef _REENT_ONLY
#define getdate_err (*__getdate_err())
int *__getdate_err (void);

struct tm *	getdate (const char *);
/* getdate_err is set to one of the following values to indicate the error.
     1  the DATEMSK environment variable is null or undefined,
     2  the template file cannot be opened for reading,
     3  failed to get file status information,
     4  the template file is not a regular file,
     5  an error is encountered while reading the template file,
     6  memory allication failed (not enough memory available),
     7  there is no line in the template that matches the input,
     8  invalid input specification  */
#endif /* !_REENT_ONLY */
#endif /* __XSI_VISIBLE >= 4 */

#if __GNU_VISIBLE
/* getdate_r returns the error code as above */
int		getdate_r (const char *, struct tm *);
#endif /* __GNU_VISIBLE */
#endif /* HAVE_GETDATE */

/* defines for the opengroup specifications Derived from Issue 1 of the SVID.  */
#if __SVID_VISIBLE || __XSI_VISIBLE
extern __IMPORT long _timezone;
extern __IMPORT int _daylight;
#endif
#if __POSIX_VISIBLE
extern __IMPORT char *_tzname[2];

/* POSIX defines the external tzname being defined in time.h */
#ifndef tzname
#define tzname _tzname
#endif
#endif /* __POSIX_VISIBLE */

#ifdef __cplusplus
}
#endif

#include <sys/features.h>
#include <sys/types.h>
#include <signal.h>


/* High Resolution Sleep, P1003.1b-1993, p. 269 */

#ifdef __cplusplus
extern "C" {
#endif

int clock_getres(clockid_t clk_id, struct timespec *res);
int clock_gettime(clockid_t clk_id, struct timespec *tp);
int clock_settime(clockid_t clk_id, const struct timespec *tp);

int nanosleep(const struct timespec  *rqtp, struct timespec *rmtp);
int clock_nanosleep(clockid_t clock_id, int flags,
	const struct timespec *rqtp, struct timespec *rmtp);

/* CPU-time Clock Attributes, P1003.4b/D8, p. 54 */

/* values for the clock enable attribute */

#define CLOCK_ENABLED  1  /* clock is enabled, i.e. counting execution time */
#define CLOCK_DISABLED 0  /* clock is disabled */

/* values for the pthread cputime_clock_allowed attribute */

#define CLOCK_ALLOWED    1 /* If a thread is created with this value a */
                           /*   CPU-time clock attached to that thread */
                           /*   shall be accessible. */
#define CLOCK_DISALLOWED 0 /* If a thread is created with this value, the */
                           /*   thread shall not have a CPU-time clock */
                           /*   accessible. */

/* Flag indicating time is "absolute" with respect to the clock
   associated with a time.  Value 4 is historic. */

#define TIMER_ABSTIME	4

/* Manifest Constants, P1003.1b-1993, p. 262 */

#define CLOCK_REALTIME		((clockid_t) 1)

/* Manifest Constants, P1003.4b/D8, p. 55 */

/*  The identifier for the system-wide monotonic clock, which is defined
 *  as a clock whose value cannot be set via clock_settime() and which
 *  cannot have backward clock jumps. */

#define CLOCK_MONOTONIC				((clockid_t) 4)

/*  The identify for the free-running hardware timer.  In the case
 *  of the Raspberry Pi this is the 1MHz system timer.
 *
 */
 
#define CLOCK_MONOTONIC_RAW		((clockid_t) 5)



#ifdef __cplusplus
}
#endif

#endif /* _TIME_H_ */

