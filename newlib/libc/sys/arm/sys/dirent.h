/*
 *  $Id: utime.h,v 1.1 2002/11/07 19:27:36 jjohnstn Exp $
 */

#ifndef __DIRENT_h__
#define __DIRENT_h__

#ifdef __cplusplus
extern "C" {
#endif

/*
 *
 */

#include <sys/types.h>
#include <limits.h>
#include <stdbool.h>

#define DIRENTS_BUF_SZ 4096

typedef struct _dir
{
	int	fd;
	void *buf;
	int buf_sz;
  int buf_offset;
  bool eof;
} DIR;


# define __dirfd(dp)	((dp)->fd)

int closedir(DIR *);
DIR *opendir(const char *);
struct dirent *readdir(DIR *);



struct dirent
{
    int d_cookie;
    int d_reclen;  			/* Length of this dirent */
	long d_ino;
	char d_name[0];
};


#define DIRENT_ALIGN		32



#ifdef __cplusplus
}
#endif
#endif