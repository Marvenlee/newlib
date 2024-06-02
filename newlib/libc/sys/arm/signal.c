#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <signal.h>
#include <sys/signal.h>
#include <unistd.h>
#include <string.h>


/*
 *
 */
void __signal_trampoline(void);
 

/*
 *
 */
_sig_func_ptr signal (int sig, _sig_func_ptr handler)
{
    struct sigaction act;

    act.sa_flags = SA_RESETHAND;
    act.sa_mask = 0;
    act.sa_handler = handler;
	
    sigaction (sig, &act, NULL);
}


/*
 *
 */
int kill (int pid, int sig)
{
    int sc;

    sc = _swi_kill(pid, sig);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


/*
 *
 */
int sigaction (int sig, const struct sigaction *act, struct sigaction *oact)
{
    int sc;
    struct sigaction tact;
    
    memcpy(&tact, act, sizeof tact);
    tact.sa_restorer = __signal_trampoline;
    tact.sa_flags |= SA_RESTORER;
    
    sc = _swi_sigaction(sig, &tact, oact);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


/*
 *
 */
int raise (int sig)
{
    int sc;

    sc = _swi_kill(getpid(), sig);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


/*
 *
 */
int sigprocmask (int how, const sigset_t *set, sigset_t *oset)
{
    int sc;

    sc = _swi_sigprocmask(how, set, oset);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


/*
 *
 */
int sigsuspend (const sigset_t *sigmask)
{
    int sc;

    sc = _swi_sigsuspend(sigmask);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}


/*
 *
 */
int sigpending (sigset_t *set)
{
    int sc;

    sc = _swi_sigpending(set);

    if (sc < 0) {
        errno = -sc;
        return -1;
    }

    return sc;
}

