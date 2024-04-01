.global __kielder_sigtramp
.equ SF_SIGNUM,     0
.equ SF_SIGINFO,    4
.equ SF_UCONTEXT,   8
.equ SF_SIGHANDLER, 12




.text
.align 16




/ ****************************************************************************
/ __kielder_sigtramp:
/
/ 
/ Kernel passes control to __sigtramp to begin signal handling.
/ A sigframe is placed on the stack by the kernel, stack pointer points to
/ the sigframe structure.



__kielder_sigtramp:
	movl SF_SIGINFO(%esp), %eax
	cmpl $0x00000000, %eax
	jne Lcall_siginfohandler


Lcall_sighandler:
	movl SF_SIGNUM(%esp), %eax
	movl SF_SIGHANDLER(%esp), %edx
	
	push %eax
	call *%edx
	
	add $4, %esp
	movl %esp, %ebx
	movl $0xffffffff, %eax
	int $0x30
	
	
Lcall_siginfohandler:
	movl SF_UCONTEXT(%esp), %eax
	movl SF_SIGINFO(%esp), %ebx
	movl SF_SIGNUM(%esp), %ecx
	movl SF_SIGHANDLER(%esp), %edx
		
	push %eax
	push %ebx
	push %ecx
	
	call *%edx

	add $4, %esp
	movl %esp, %ebx
	movl $0xffffffff, %eax
	int $0x30




	

