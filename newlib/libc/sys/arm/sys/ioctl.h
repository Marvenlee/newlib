#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>


#define  IOCTL_CON_SETMAP	0



int ioctl (int fd, int request, ...);


#ifdef __cplusplus
}
#endif 
#endif
