#ifndef _SYS_KSYSCALLS_H
#define _SYS_KSYSCALLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/execargs.h>
#include <sys/signal.h>
#include <sys/event.h>
#include <poll.h>
#include <time.h>
#include <sys/time.h>
#include <_ansi.h>
#include <_syslist.h>
#include <sys/resource.h>
#include <sys/types.h>


// Types
typedef signed char 		    int8;
typedef unsigned char 		  uint8;
typedef signed short		    int16;
typedef unsigned short		  uint16;
typedef signed long			    int32;
typedef unsigned long		    uint32;
typedef signed long long 	  int64;
typedef unsigned long long 	uint64;
typedef signed long			    err32;
typedef uint32_t				    vm_offset;
typedef uint32_t				    vm_size;
typedef unsigned char		    bits8_t;
typedef unsigned short		  bits16_t;
typedef unsigned long		    bits32_t;
typedef long long			      uuid_t;

typedef uint32_t            msgid_t;

/*
 * Exit()/Join() Status
 */
#define EXIT_OK                 0
#define EXIT_ERROR              1
#define EXIT_FATAL              2
#define EXIT_KILLED             3



/*
 * Multi-part messages
 */
struct IOV
{
  void *addr;
  size_t size;
  uint32_t flags;						// TODO: Use iov flags to control zero-copy
};


/*
 * Time related structures
 */
struct TimeVal
{
	long long seconds;
	long microseconds;
};


struct InterruptAPI;


/*
 * Timer types
 */
#define TIMER_TYPE_RELATIVE     0
#define TIMER_TYPE_ABSOLUTE     1


/*
 * VirtualAlloc() protections
 */
#define PROT_NONE			        0
#define PROT_READ			        (1<<0)
#define PROT_WRITE			      (1<<1)
#define PROT_EXEC			        (1<<2)
#define PROT_ALL			        (PROT_READ | PROT_WRITE | PROT_EXEC)
#define PROT_READWRITE 		    (PROT_READ | PROT_WRITE)
#define PROT_READEXEC		      (PROT_READ | PROT_EXEC)

#define MAP_FIXED				      (1<<3)
#define MAP_WIRED				      (1<<4)
#define MAP_NOX64				      (1<<5)
#define MAP_BELOW16M			    (1<<6)
#define MAP_BELOW4G				    (1<<7)

#define CACHE_DEFAULT	 		    (0<<8)
#define CACHE_WRITEBACK	 		  (1<<8)
#define CACHE_WRITETHRU	 		  (2<<8)
#define CACHE_WRITECOMBINE 		(3<<8)
#define CACHE_UNCACHEABLE  		(4<<8)
#define CACHE_WEAKUNCACHEABLE	(5<<8)
#define CACHE_WRITEPROTECT		(6<<8)

#define PROT_MASK				  0x00000007
#define CACHE_MASK   		  0x00000f00


/*
 * System call prototypes
 */

void _swi_debug (char *str);

int _swi_fork (void);
int _swi_exec (const char *filename, struct execargs *args);
void _swi_exit (int status);
int _swi_waitpid (int pid, int *loc_stat, int options);
int _swi_kill (int pid, int sig);
int _swi_setschedparams (int policy, int priority);

void *_swi_virtualalloc (void *addr, size_t size, bits32_t flags);
void *_swi_virtualallocphys (void *addr, size_t size, bits32_t flags, void *phys_addr);
int _swi_virtualfree (void *addr, size_t sz);
int _swi_virtualprotect (void *addr, size_t sz, bits32_t flags);
void *_swi_virtualtophysaddr(void *addr);

int _swi_open (char *name, int oflags, mode_t mode);
int _swi_close (int handle);

ssize_t _swi_read (int fd, void *buf, size_t nbyte);
ssize_t _swi_write (int fd, void *buf, size_t nbyte);

int _swi_dup(int fd); 
int _swi_dup2(int fd1, int fd2);

int _swi_mkdir(const char *path, mode_t mode);
int _swi_rmdir(const char *path);
int _swi_unlink(const char *path);
int _swi_ftruncate (int fd, off_t size);


int _swi_rename (const char *oldname, const char *newname);

int _swi_pipe (int fdp[2]);

int _swi_createinterrupt (int irq, void (*interrupt_handler)(int irq, struct InterruptAPI *api));
int _swi_maskinterrupt (int irq);
int _swi_unmaskinterrupt (int irq);

int _swi_sleep(int seconds);
int _swi_alarm(int seconds);
int _swi_nanosleep(struct timespec *req, struct timespec *rem);

int _swi_opendir(const char *path);
ssize_t _swi_readdir (int fd, void *buf, size_t buf_sz);
int _swi_rewinddir (int fd);

off_t _swi_lseek(int fd, off_t offs, int whence);
off64_t _swi_lseek64(int fd, off64_t *offs, int whence);

int _swi_mknod2(const char *path, uint32_t flags, struct stat *stat);
int _swi_createmsgport(const char *path, uint32_t flags, struct stat *stat, int backlog);
int _swi_unmount(int fd, bool force);
int _swi_renamemsgport(const char *new_path, const char *old_path);
int _swi_pivotroot(const char *new_root, const char *old_root);

int _swi_sendrec(int fd, int siov_cnt, struct IOV *siov, int riov_cnt, struct IOV *riov);
int _swi_getmsg(int portid, msgid_t *msgid, void *buf, size_t buf_sz);
int _swi_replymsg(int portid, msgid_t msgid, int status, void *buf, size_t buf_sz);
int _swi_readmsg(int portid, msgid_t msgid, void *buf, size_t buf_sz, off_t offset);
int _swi_writemsg(int portid, msgid_t msgid, void *buf, size_t buf_sz, off_t offset);

int _swi_stat(char *path, struct stat *stat);
int _swi_fstat(int fd, struct stat *stat);

int _swi_poll(struct pollfd *pfds, nfds_t nfds, int timeout);

int _swi_signalnotify(int fd, int ino, int signal);
int _swi_pollnotify(int fd, int ino, short events);

int _swi_chdir(const char *path);
int _swi_fchdir(int fd);

int _swi_fcntl(int fd, int cmd, int arg);
int _swi_isatty(int fd);

int _swi_fsync(int fd);
int _swi_sync(void);
int _swi_chmod(const char *_path, mode_t mode);
int _swi_chown(const char *_path, uid_t uid, gid_t gid);
int _swi_fchmod(int fd, mode_t mode);
int _swi_fchown(int fd, uid_t uid, gid_t gid);

int _swi_symlink(const char *path1, const char *path2);
int _swi_readlink(const char *path, char *buf, size_t bufsize);

int _swi_ioctl(int fd, int cmd, void *arg);

int _swi_sigprocmask(int how, const sigset_t *set, sigset_t *oset);
int _swi_sigaction(int sig, const struct sigaction *act, struct sigaction *oact);
int _swi_sigpending(sigset_t *set);
int _swi_sigsuspend(const sigset_t *set);

int _swi_mknod(char *_path, uint32_t flags, struct stat *stat);

int _swi_kqueue(void);
int _swi_kevent(int kq, const struct kevent *changelist, int nchanges,
	                struct kevent *eventlist, int nevents,
	                const struct timespec *timeout);

int _swi_setegid(gid_t gid);
int _swi_seteuid(uid_t uid);
int _swi_issetugid(void);
int	_swi_setgroups(int ngroups, const gid_t *grouplist);
int _swi_getgroups(int gidsetsize, gid_t grouplist[]);

int _swi_get_priority(id_t who, int *prio);
int _swi_setpriority(id_t who, int prio);

int _swi_access(const char *path, int amode);
mode_t _swi_umask(mode_t cmask);

int _swi_bdflush(int fd);
int _swi_chroot(const char *path);

pid_t _swi_getpid(void);
pid_t _swi_getppid(void);

int _swi_gettimeofday(struct timeval *tp);
int _swi_settimeofday(const struct timeval *tp);

int _swi_getpgrp(void);
int _swi_setpgrp(void);
uid_t _swi_getuid(void);
int _swi_setuid(uid_t uid);
gid_t _swi_getgid(void);
int _swi_setgid(gid_t gid);
uid_t _swi_geteuid(void);
int _swi_setegid(gid_t gid);
int _swi_seteuid(uid_t uid);
int _swi_issetugid(void);
int	_swi_setgroups(int ngroups, const gid_t *grouplist);
int _swi_getgroups(int gidsetsize, gid_t grouplist[]);

/*
 * unistd.h 64-bit syscalls.
 */
off64_t lseek64(int fd, off64_t offset, int whence);

/*
 * Virtual Memory system calls
 */
void *virtualalloc (void *addr, size_t size, bits32_t flags);
void *virtualallocphys (void *addr, size_t size, bits32_t flags, void *phys_addr);
int virtualfree (void *addr, size_t sz);
int virtualprotect (void *addr, size_t sz, bits32_t flags);
void *virtualtophysaddr(void *addr);

/*
 * Interprocess Communication system calls
 */
int sendrec(int fd, int siov_cnt, struct IOV *siov, int riov_cnt, struct IOV *riov);
int getmsg(int portid, msgid_t *msgid, void *buf, size_t buf_sz);
int replymsg(int portid, msgid_t msgid, int status, void *buf, size_t buf_sz);
int readmsg(int portid, msgid_t msgid, void *buf, size_t buf_sz, off_t offset);
int writemsg(int portid, msgid_t msgid, void *buf, size_t buf_sz, off_t offset);

/*
 * Interrupt system calls
 */
int createinterrupt (int irq, void (*interrupt_handler)(int irq, struct InterruptAPI *api));
int maskinterrupt (int irq);
int unmaskinterrupt (int irq);


#ifdef __cplusplus
}
#endif

#endif

