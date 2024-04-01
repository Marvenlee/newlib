#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <sys/stat.h>
#include <unistd.h>


/*
 *
 */
int chmod(const char *__path, mode_t __mode )
{
  int sc;
  
  sc = _swi_chmod(__path, __mode);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return sc;
}


/*
 *
 */
int chown(const char *__path, uid_t __owner, gid_t __group )
{
  int sc;
  
  sc = _swi_chown(__path, __owner, __group);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return sc;
}


/*
 *
 */
int fchmod(int fd, mode_t __mode )
{
  int sc;
  
  sc = _swi_fchmod(fd, __mode);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return sc;
}


/*
 *
 */
int fchown(int fd, uid_t __owner, gid_t __group )
{
  int sc;
  
  sc = _swi_fchown(fd, __owner, __group);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return sc;
}

