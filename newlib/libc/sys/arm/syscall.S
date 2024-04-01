.extern __real_set_errno

.text

#define SYSCALL_SWI(name, idx)  \
.global name;                   \
name:;                          \
    swi idx;                    \
    bx lr;

#define SYSCALL_SWI5(name, idx)     \
.global name;                       \
name:;                              \
    sub sp, #8;                     \
  	str	r4, [sp, #0];               \
    ldr r4, [sp, #8];               \
    swi idx;                        \
    ldr	r4, [sp, #0];               \
    add sp, #8;                     \
    bx lr;

#define SYSCALL_SWI6(name, idx)     \
.global name;                       \
name:;                              \
    sub sp, #8;                     \
  	str	r4, [sp, #0];               \
  	str	r5, [sp, #4];               \
    ldr r4, [sp, #8];               \
    ldr r5, [sp, #12];              \
    swi idx;                        \
    ldr	r4, [sp, #0];               \
  	ldr	r5, [sp, #4];               \
    add sp, #8;                     \
    bx lr;



#define SYSCALL0 SYSCALL_SWI
#define SYSCALL1 SYSCALL_SWI
#define SYSCALL2 SYSCALL_SWI
#define SYSCALL3 SYSCALL_SWI
#define SYSCALL4 SYSCALL_SWI
#define SYSCALL5 SYSCALL_SWI5
#define SYSCALL6 SYSCALL_SWI6

SYSCALL1( _swi_debug, 1)
SYSCALL1( _swi_fork, 2)
SYSCALL1( _swi_exit, 3)
SYSCALL3( _swi_waitpid, 4)
SYSCALL0( _swi_kill, 5)
SYSCALL2( _swi_setschedparams, 6)

SYSCALL1( _swi_sleep, 7)
SYSCALL1( _swi_alarm, 8)
SYSCALL2( _swi_nanosleep, 9)
SYSCALL0( _swi_gettimeofday, 10)
SYSCALL1( _swi_settimeofday, 11)

SYSCALL3( _swi_virtualalloc, 12)
SYSCALL4( _swi_virtualallocphys, 13)
SYSCALL2( _swi_virtualfree, 14)
SYSCALL2( _swi_virtualprotect, 15)

SYSCALL1( _swi_createinterrupt, 16)
SYSCALL1( _swi_maskinterrupt, 17)
SYSCALL1( _swi_unmaskinterrupt, 18)

SYSCALL3( _swi_poll, 19)

SYSCALL2( _swi_exec, 20)

SYSCALL4( _swi_mount, 21)
SYSCALL2( _swi_unmount, 22)

SYSCALL5( _swi_sendrec, 24)
SYSCALL4( _swi_getmsg, 24)
SYSCALL5( _swi_replymsg, 25)
SYSCALL5( _swi_readmsg, 26)
SYSCALL5( _swi_writemsg, 27)

SYSCALL3( _swi_open, 28)
SYSCALL1( _swi_close, 29)
SYSCALL1( _swi_dup, 30)
SYSCALL1( _swi_dup2, 31)

SYSCALL3( _swi_read, 32)
SYSCALL3( _swi_write, 33)
SYSCALL3( _swi_lseek, 34)
SYSCALL3( _swi_lseek64, 35)

SYSCALL2( _swi_truncate, 36)
SYSCALL1( _swi_unlink, 37)

SYSCALL2( _swi_mkdir, 38)
SYSCALL1( _swi_opendir, 39)
SYSCALL3( _swi_readdir, 40)
SYSCALL1( _swi_rewinddir, 41)
SYSCALL1( _swi_rmdir, 42)

SYSCALL2( _swi_rename, 43)

SYSCALL1( _swi_pipe, 44)
SYSCALL1( _swi_socketpair, 45)

SYSCALL1( _swi_chdir, 46)
SYSCALL1( _swi_fchdir, 47)

SYSCALL2( _swi_stat, 48)
SYSCALL2( _swi_fstat, 49)
    
SYSCALL2( _swi_symlink, 50)
SYSCALL2( _swi_readlink, 51)

SYSCALL2( _swi_chmod, 52)
SYSCALL2( _swi_chown, 53)
SYSCALL2( _swi_access, 54)
SYSCALL1( _swi_umask, 55)

SYSCALL0( _swi_getpid, 56)
SYSCALL0( _swi_getppid, 57)
SYSCALL0( _swi_getuid, 58)
SYSCALL0( _swi_getgid, 59)
SYSCALL0( _swi_geteuid, 60)
SYSCALL0( _swi_getegid, 61)
SYSCALL1( _swi_setuid, 62)
SYSCALL1( _swi_setgid, 63)

SYSCALL0( _swi_setpgrp, 64)
SYSCALL0( _swi_getpgrp, 65)

SYSCALL1( _swi_virtualtophysaddr, 66)

SYSCALL3( _swi_signalnotify, 67)

SYSCALL3( _swi_pollnotify, 68)

SYSCALL2( _swi_pivotroot, 69)

SYSCALL3( _swi_fcntl, 70)
SYSCALL1( _swi_isatty, 71)
SYSCALL3( _swi_ioctl, 72)

SYSCALL0( _swi_sync, 73)
SYSCALL1( _swi_fsync, 74)

SYSCALL3( _swi_sigaction, 75)
SYSCALL3( _swi_sigprocmask, 76)
SYSCALL1( _swi_sigpending, 77)
SYSCALL1( _swi_sigsuspend, 78)
SYSCALL3( _swi_mknod, 79)

SYSCALL2( _swi_renamemsgport, 80)
SYSCALL1( _swi_chroot, 81)

SYSCALL0( _swi_kqueue, 82)

SYSCALL6( _swi_kevent, 83)

SYSCALL1( _swi_setegid, 84)
SYSCALL1( _swi_seteuid, 85)
SYSCALL0( _swi_issetugid, 86)
SYSCALL2( _swi_setgroups, 87)
SYSCALL2( _swi_getgroups, 88)

SYSCALL2( _swi_get_priority, 89)
SYSCALL2( _swi_setpriority, 90)


SYSCALL2( _swi_fchmod, 92)
SYSCALL3( _swi_fchown, 93)

SYSCALL2( _swi_clock_gettime, 94)

SYSCALL2( _swi_clock_settime, 98)

SYSCALL1( _swi_bdflush, 99)

