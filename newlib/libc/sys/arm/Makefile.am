## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = -I$(srcdir)/include $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS) -I$(newlib_basedir)/libc/machine/arm

AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

lib_a_SOURCES = \
  _exit.c \
  access.c \
	alarm.c \
	bdflush.c \
	chmod.c \
	clock.c \
	close.c \
	closedir.c \
	creat.c \
	debug.c \
	dir.c \
	dup.c \
	environ.c \
	execl.c \
	execle.c \
	execlp.c \
	execv.c \
	execve.c \
	execvp.c \
	fcntl.c \
	fork.c \
	fstat.c \
	getpid.c \
	gettod.c \
	id.c \
	interrupt.c \
	ioctl.c \
	kqueue.c \
	link.c \
	lseek.c \
	malloc.c \
	mknod.c \
	mntent.c \
	mount.c \
	msg.c \
	open.c \
	opendir.c \
	pathconf.c \
	pipe.c \
	popen.c \
	pwcache.c \
	read.c \
	readdir.c \
	rename.c \
	resource.c \
	rewinddir.c \
	select.c \
	siglist.c \
	signal.c \
	syscall.S \
	sleep.c \
	stat.c \
	statvfs.c \
	sync.c \
	sysconf.c \
	termios.c \
	time.c \
	times.c \
	timespec.c \
	truncate.c \
	unlink.c \
	user_strerror.c \
  virtualalloc.c \
	wait.c \
	write.c \
	\
	err.c \
  errx.c \
  expand_number.c \
	fnmatch.c \
  getbsize.c \
  getpass.c \
  gethostname.c \
  getprogname.c \
	getgrouplist.c \
	getgroupmembership.c \
	getgrent.c \
	getlogin.c \
	__getlogin.c \
	getnetgrent.c \
	getpwent.c \
  heapsort.c \
  humanize_number.c \
  initgroups.c \
  merge.c \
	nsdispatch.c \
	nsparser.c \
	nslexer.c \
  setmode.c \
	setproctitle.c \
  signames.c \
	stringlist.c \
  strmode.c \
	ttyaction.c \
	reallocarray.c \
	reallocarr.c \
  verrx.c \
  vwarn.c \
  vwarnc.c \
  vwarnx.c \
  warn.c \
  warnc.c \
  warnx.c \
  vis.c
	
	
lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

all-local: crt0.o

ACLOCAL_AMFLAGS = -I ../../.. -I ../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
