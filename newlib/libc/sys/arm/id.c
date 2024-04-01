#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>


/*
 *
 */
int getpgrp(void)
{
  return _swi_getpgrp();
}


/*
 * 
 */
int setpgrp(void)
{
  int sc;
  
  sc = _swi_setpgrp();
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return 0;
}


/*
 *
 */
uid_t getuid(void)
{
  return _swi_getuid();
}


/*
 *
 */
int setuid(uid_t uid)
{
  int sc;
  
  sc = _swi_setuid(uid);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return 0;
}


/*
 *
 */
gid_t getgid(void)
{
  return _swi_getgid();
}


/*
 *
 */
int setgid(gid_t gid)
{
  int sc;
  
  sc = _swi_setgid(gid);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return 0;
}


/*
 *
 */
uid_t geteuid(void)
{
  return _swi_geteuid();
}


/*
 *
 */
gid_t getegid(void)
{  
  return _swi_getegid();
}


/*
 *
 */
int setegid(gid_t gid)
{
  int sc;
  
  sc = _swi_setegid(gid);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return 0;
}


/*
 *
 */
int seteuid(uid_t uid)
{
  int sc;
  
  sc = _swi_seteuid(uid);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return 0;
}


/*
 *
 */
int issetugid(void)
{
  return _swi_issetugid();
}


/*
 *
 */
int	setgroups(int ngroups, const gid_t *grouplist)
{
  int sc;
  
  sc = _swi_setgroups(ngroups, grouplist);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return 0;
}


/*
 *
 */
int getgroups(int gidsetsize, gid_t grouplist[])
{
  int sc;
  
  sc = _swi_getgroups(gidsetsize, grouplist);
  
  if (sc < 0) {
    errno = -sc;
    return -1;
  }
  
  return 0;
}



