/*
 *
 */
 
.global __signal_trampoline


/* @brief   Offsets within the sigframe structure
 *
 * The sigframe structure is defined in ucontext.h
 */
.equ SF_SIGNUM,     0
.equ SF_SIGINFO,    4
.equ SF_UCONTEXT,   8
.equ SF_SIGHANDLER, 12


.text
.align 16


/* Kernel passes control to __signal_trampoline to begin signal handling.
 * A sigframe is placed on the stack by the kernel, stack pointer points to
 * the sigframe structure.
 */ 
__signal_trampoline:
	ldr	r0, [sp, #SF_SIGINFO]
	
	cmp r0, #0
	bne Lcall_siginfohandler

  // Call the appropriate signal handler with signum as parameter		
	ldr	r0, [sp, #SF_SIGNUM]
  ldr r1, [sp, #SF_SIGHANDLER]
	blx r1	

	ldr	r0, [sp, #SF_UCONTEXT]
	bl _swi_sigreturn
	
Lcall_siginfohandler:
  // Call the appropriate signal handler with signum, signinfo and ucontext as parameters		
	ldr	r0, [sp, #SF_SIGNUM]
	ldr	r1, [sp, #SF_SIGINFO]
	ldr	r2, [sp, #SF_UCONTEXT]
  ldr r3, [sp, #SF_SIGHANDLER]
	blx r3

  ldr	r0, [sp, #SF_UCONTEXT]
	bl _swi_sigreturn


