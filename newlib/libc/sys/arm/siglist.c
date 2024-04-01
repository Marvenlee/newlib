#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>

/*
 *
 */ 
const char * const sys_siglist[NSIG] =
{
	/*  0           */ "Unknown Signal",
	/*  1 SIGHUP    */ "Hangup",
	/*  2 SIGINT    */ "Interrupt",
	/*  3 SIGQUIT   */ "Quit",
	/*  4 SIGILL    */ "Illegal instruction",
	/*  5 SIGTRAP   */ "BPT trace/trap",
	/*  6 SIGABORT  */ "ABORT instruction",
	/*  7 SIGEMT    */ "EMT instruction",
	/*  8 SIGFPE    */ "Floating point exception",
	/*  9 SIGKILL   */ "Killed",
	/* 10 SIGBUS    */ "Bus error",
	/* 11 SIGSEGV   */ "Segmentation fault",
	/* 12 SIGSYS    */ "Bad system call",
	/* 13 SIGPIPE   */ "Broken pipe",
	/* 14 SIGALRM   */ "Alarm clock",
	/* 15 SIGTERM   */ "Terminated",
	/* 16 SIGURG    */ "Urgent IO condition",
	/* 17 SIGSTOP   */ "Stopped (signal)",
	/* 18 SIGTSTP   */ "Stopped",
	/* 19 SIGCONT   */ "Continue",
	/* 20 SIGCHLD   */ "Child death or stop",
	/* 21 SIGTTIN   */ "Stopped (tty input)",
	/* 22 SIGTTOU   */ "Stopped (tty output)",
	/* 23 SIGIO     */ "I/O ready",
	/* 24 SIGXCPU   */ "CPU limit",
	/* 25 SIGXFSZ   */ "File limit",
	/* 26 SIGVTALRM */ "Alarm (virtual)",
	/* 27 SIGPROF   */ "Alarm (profile)",
	/* 28 SIGWINCH  */ "Window changed",
	/* 29 SIGLOST   */ "Record lock",
	/* 30 SIGUSR1   */ "User signal 1",
	/* 31 SIGUSR2   */ "User signal 2"
};


/*
 *
 */
const char * const sys_signame[NSIG] =
{
	/*  0           */ "signal 0",
	/*  1 SIGHUP    */ "hup",
	/*  2 SIGINT    */ "int",
	/*  3 SIGQUIT   */ "quit",
	/*  4 SIGILL    */ "ill",
	/*  5 SIGTRAP   */ "trap",
	/*  6 SIGABORT  */ "abort",
	/*  7 SIGEMT    */ "emt",
	/*  8 SIGFPE    */ "fpe",
	/*  9 SIGKILL   */ "kill",
	/* 10 SIGBUS    */ "bus",
	/* 11 SIGSEGV   */ "segv",
	/* 12 SIGSYS    */ "sys",
	/* 13 SIGPIPE   */ "pipe",
	/* 14 SIGALRM   */ "alrm",
	/* 15 SIGTERM   */ "term",
	/* 16 SIGURG    */ "urg",
	/* 17 SIGSTOP   */ "stop",
	/* 18 SIGTSTP   */ "tstp",
	/* 19 SIGCONT   */ "cont",
	/* 20 SIGCHLD   */ "chld",
	/* 21 SIGTTIN   */ "ttin",
	/* 22 SIGTTOU   */ "ttou",
	/* 23 SIGIO     */ "io",
	/* 24 SIGXCPU   */ "xcpu",
	/* 25 SIGXFSZ   */ "xfsz",
	/* 26 SIGVTALRM */ "vtalrm",
	/* 27 SIGPROF   */ "prof",
	/* 28 SIGWINCH  */ "winch",
	/* 29 SIGLOST   */ "lost",
	/* 30 SIGUSR1   */ "usr1",
	/* 31 SIGUSR2   */ "usr2"
};


/*
 * 
 */
char *strsignal (int sig)
{
	if (sig > 0 && sig <NSIG)
		return (char *) sys_siglist[sig];
	else
		return "Unknown signal";
}


/*
 *
 */
void psignal (int sig, const char *s)
{
	const char *sig_str;
	
	if (sig > 0 && sig < NSIG)
		sig_str = sys_siglist[sig];
	else
		sig_str = "Unknown signal";

	printf ("%s: %s\n", s, sig_str);
}

