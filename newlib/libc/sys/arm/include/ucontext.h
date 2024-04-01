#ifndef	_UCONTEXT_H
#define	_UCONTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <signal.h>
#include <sys/signal.h>

typedef struct mcontext {
  uint32_t sp;
  uint32_t lr;
  uint32_t cpsr; // Should be svc_mode spsr
  uint32_t r1;
  uint32_t r2;
  uint32_t r3;
  uint32_t r4;
  uint32_t r5;
  uint32_t r6;
  uint32_t r7;
  uint32_t r8;
  uint32_t r9;
  uint32_t r10;
  uint32_t r11;
  uint32_t r12;
  uint32_t r0;
  uint32_t pc; // Should be xyz_ svc_mode LR register.
  uint32_t pad;
} mcontext_t __attribute__((packed));



/*
 * ucontext_t
 */

#define UCF_SWAPPED     0x00000001      /* Used by swapcontext(3). */

typedef struct __ucontext
{
	mcontext_t	uc_mcontext;
	
	sigset_t	uc_sigmask;
	stack_t		uc_stack;
	int			uc_flags;
	struct __ucontext *uc_link;

} ucontext_t;
 
 

/*
 *
 */
 
typedef void __sighandler_t (int);
typedef	void __siginfohandler_t (int, siginfo_t *, void *);




/*
 * struct sigframe
 */

struct sigframe
{
  int          sf_signum;
  siginfo_t    *sf_siginfo;     /* pointer to sf_si */
  ucontext_t   *sf_ucontext;    /* pointer to sf_uc */

  union
  {
		__siginfohandler_t      *sf_action;
		__sighandler_t          *sf_handler;
	} sf_ahu;
    
  ucontext_t      sf_uc;          /* = *sf_ucontext */
  siginfo_t       sf_si;          /* = *sf_siginfo (SA_SIGINFO case) */
};


 

#ifdef __cplusplus
}
#endif


#endif


