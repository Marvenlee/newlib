#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscalls.h>
#include <pthread.h>
#include "pthread_internals.h"

/* @brief   Signal an event to another thread
 *
 */
int cthread_event_signal(pthread_t tid, int event)
{
  int sc;

  sc = _swi_thread_event_signal(tid, event);

  if (sc < 0) {
    errno = -sc;
    return -1;
  }

  return 0;
}


/* @brief   Wait for a set of events
 *
 * TODO: Add a timed wait variant of thread_event_wait
 */
uint32_t cthread_event_wait(uint32_t event_mask)
{
  return _swi_thread_event_wait(event_mask);    
}


/* @brief   Wait for a set of events
 *
 * TODO: Add a timed wait variant of thread_event_wait
 */
uint32_t cthread_event_check(uint32_t event_mask)
{
  return _swi_thread_event_check(event_mask);    
}

