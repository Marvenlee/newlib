#include "newlib.h"
#include "arm.h"

.extern environ

/* ANSI concatenation macros.  */
#define CONCAT(a, b) CONCAT2(a, b)
#define CONCAT2(a, b) a ## b

#ifdef __USER_LABEL_PREFIX__
#define FUNCTION( name ) CONCAT (__USER_LABEL_PREFIX__, name)
#else
#error __USER_LABEL_PREFIX is not defined
#endif


#ifdef HAVE_INITFINI_ARRAY
#define _init	__libc_init_array
#define _fini	__libc_fini_array
#endif

#if defined(__ARM_EABI__) && defined(__thumb__) && !defined(__thumb2__)
/* For Thumb1 we need to force the architecture to be sure that we get the
   correct attributes on the object file; otherwise the assembler will get
   confused and mark the object as being v6T2.  */
#if defined(__ARM_ARCH_4T__)
	.arch armv4t
#elif defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__)
	/* Nothing in this object requires higher than v5.  */
	.arch armv5t
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) \
	|| defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) \
	|| defined(__ARM_ARCH_6ZK__)
	/* Nothing in this object requires higher than v6.  */
	.arch armv6
#elif defined(__ARM_ARCH_6M__)
#ifdef ARM_RDP_MONITOR
	/* Object file uses SVC, so mark as v6s-m.  */
	.arch armv6s-m
#else
	.arch armv6-m
#endif
#endif
#endif



/* .text is used instead of .section .text so it works with arm-aout too.  */
	.text
	.syntax unified
#ifdef THUMB_V7_V6M
	.thumb
.macro FUNC_START name
	.global \name
	.thumb_func
\name:
.endm	
#else
	.code 32
.macro FUNC_START name
	.global	\name
\name:
.endm	
#endif

.macro indirect_call reg
#ifdef HAVE_CALL_INDIRECT
	blx \reg
#else
	mov	lr, pc
	mov	pc, \reg
#endif
.endm






.balign 	16

	FUNC_START	_mainCRTStartup
	FUNC_START	_start
	FUNC_START	start

// r0 argc
// r1 argv
// r2 envc
// r3 envv

    ldr r4, =environ
    str r3, [r4]

#if defined(__ELF__) && !defined(__USING_SJLJ_EXCEPTIONS__)
	/* Annotation for EABI unwinding tables.  */
	.fnstart
#endif


// FIXME:  Assumes bss/common is clear.

#ifdef __USES_INITFINI__
	movs	r4, r0
	movs	r5, r1
	ldr	r0, .Lfini
	bl	FUNCTION (atexit)
	bl	FUNCTION (_init)
	movs	r0, r4
	movs	r1, r5
#endif	
	bl	FUNCTION (main)
	bl	FUNCTION (exit)		/* Should not return.  */









.balign 16


#if defined(__ELF__) && !defined(__USING_SJLJ_EXCEPTIONS__)
	/* Protect against unhandled exceptions.  */
	.cantunwind
	.fnend
#endif


.LC1:
	.word	__bss_start__
.LC2:
	.word	__bss_end__


#ifdef __USES_INITFINI__
.Lfini:
	.word	FUNCTION(_fini)
#endif


.balign 16

