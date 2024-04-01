/*-
 * Copyright (c) 1999,2000,2001 Jonathan Lemon <jlemon@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	$FreeBSD: src/sys/sys/event.h,v 1.19 2002/03/23 08:46:51 bde Exp $
 */

#ifndef _SYS_EVENT_H_
#define _SYS_EVENT_H_

#include <stdint.h>

#define EVFILT_READ		  0
#define EVFILT_WRITE		1
#define EVFILT_AIO		  2	/* attached to aio requests */
#define EVFILT_VNODE		3	/* attached to vnodes */
#define EVFILT_PROC		  4	/* attached to struct proc */
#define EVFILT_SIGNAL		5	/* attached to struct proc */
#define EVFILT_TIMER		6	/* timers */
#define EVFILT_NETDEV		7	/* network devices */
#define EVFILT_USER     8
#define EVFILT_IRQ      9
#define EVFILT_MSGPORT  10

#define EVFILT_SYSCOUNT		11


#define EV_SET(kevp, a, b, c, d, e, f) do {	\
	(kevp)->ident = (a);			\
	(kevp)->filter = (b);			\
	(kevp)->flags = (c);			\
	(kevp)->fflags = (d);			\
	(kevp)->data = (e);			\
	(kevp)->udata = (f);			\
} while(0)

struct kevent {
	uintptr_t ident;		/* identifier for this event */
	int16_t filter;		/* filter for event */
	uint16_t flags;
	uint32_t fflags;
  void *data;
	void *udata;		/* opaque user data identifier */
};

/* actions */
#define EV_ADD		0x0001		/* add event to kq (implies enable) */
#define EV_DELETE	0x0002		/* delete event from kq */
#define EV_ENABLE	0x0004		/* enable event */
#define EV_DISABLE	0x0008		/* disable event (not reported) */

/* flags */
#define EV_ONESHOT	0x0010		/* only report one occurrence */
#define EV_CLEAR	0x0020		/* clear event state after reporting */

#define EV_SYSFLAGS	0xF000		/* reserved by system */
#define EV_FLAG1	0x2000		/* filter-specific flag */

/* returned values */
#define EV_EOF		0x8000		/* EOF detected */
#define EV_ERROR	0x4000		/* error, data contains errno */


/*
 * data/hint flags for EVFILT_{READ|WRITE}, shared with userspace
 */
#define NOTE_LOWAT	0x0001			/* low water mark */

/*
 * data/hint flags for EVFILT_VNODE, shared with userspace
 */
#define	NOTE_DELETE	0x0001			/* vnode was removed */
#define	NOTE_WRITE	0x0002			/* data contents changed */
#define	NOTE_EXTEND	0x0004			/* size increased */
#define	NOTE_ATTRIB	0x0008			/* attributes changed */
#define	NOTE_LINK	0x0010			/* link count changed */
#define	NOTE_RENAME	0x0020			/* vnode was renamed */
#define	NOTE_REVOKE	0x0040			/* vnode access was revoked */

/*
 * data/hint flags for EVFILT_PROC, shared with userspace
 */
#define	NOTE_EXIT	0x80000000		/* process exited */
#define	NOTE_FORK	0x40000000		/* process forked */
#define	NOTE_EXEC	0x20000000		/* process exec'd */
#define	NOTE_PCTRLMASK	0xf0000000		/* mask for hint bits */
#define	NOTE_PDATAMASK	0x000fffff		/* mask for pid */

/* additional flags for EVFILT_PROC */
#define	NOTE_TRACK	0x00000001		/* follow across forks */
#define	NOTE_TRACKERR	0x00000002		/* could not track child */
#define	NOTE_CHILD	0x00000004		/* am a child process */

/*
 * data/hint flags for EVFILT_NETDEV, shared with userspace
 */
#define NOTE_LINKUP	0x0001			/* link is up */
#define NOTE_LINKDOWN	0x0002			/* link is down */
#define NOTE_LINKINV	0x0004			/* link state is invalid */

/*
 * data/hint flags for EVFILT_MSGPORT, message ports
 */
#define NOTE_MSG          0x10000000    /* Message has arrived on port */
#define NOTE_PORTIDMASK   0x000000ff

/*
 * data/hint flags for EVFILT_IRQ, interrupts
 */
#define NOTE_INT          0x10000000    /* Interrupt arrival */
#define NOTE_IRQMASK      0x0000ffff    /* IRQ number */


#include <sys/cdefs.h>
struct timespec;

__BEGIN_DECLS
int     kqueue(void);
int     kevent(int kq, const struct kevent *changelist, int nchanges,
	    struct kevent *eventlist, int nevents,
	    const struct timespec *timeout);
__END_DECLS

#endif /* !_SYS_EVENT_H_ */
