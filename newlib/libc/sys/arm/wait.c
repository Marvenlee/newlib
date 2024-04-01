#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>


/* @brief Wait for a process terminate
 * 
 */
pid_t waitpid (pid_t pid, int *status, int options)
{
  pid_t rpid;
  
  rpid = _swi_waitpid (pid, status, options);
  
  if (rpid < 0) {
    errno = -rpid;
    return -1;
  }
  
  return rpid;
}


/* @brief Wait for any process to terminate
 * 
 */
int wait (int *status)
{
 return waitpid (-1, status, 0);
}

