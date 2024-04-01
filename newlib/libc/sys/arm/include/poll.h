#ifndef _POLL_H
#define _POLL_H

#include <sys/types.h>
#include <sys/time.h>


#define POLLIN      (1<<0)
#define POLLRDNORM  (1<<1)
#define POLLRDBAND  (1<<2)
#define POLLPRI     (1<<3)
#define POLLOUT     (1<<4)
#define POLLWRNORM  (1<<5)
#define POLLWRBAND  (1<<6)
#define POLLERR     (1<<7)
#define POLLNVAL    (1<<8)

typedef unsigned int  nfds_t;

struct pollfd
{
  int fd;
  short events;
  short revents;
};


int poll (struct pollfd[], nfds_t nfds, int timeout);
		   
#endif 
