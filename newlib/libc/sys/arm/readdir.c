#include <sys/types.h>
#include <dirent.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <sys/debug.h>
#include <string.h>

/*
 *
 */
struct dirent *readdir(DIR *dir)
{
  struct dirent *dent;
  int sz;
  
  if (dir == NULL) {
    errno = EINVAL;
    return NULL;
  }

  if (dir->eof == true) {
    return NULL;
  }
    
  if (dir->buf_offset >= dir->buf_sz)
  {   
    sz = _swi_readdir (dir->fd, dir->buf, DIRENTS_BUF_SZ);

    if (sz < 0) {
      errno = -sz;
      dir->buf_sz = 0;
      dir->eof = true;
      return NULL;
    } else if (sz == 0) {
      dir->buf_sz = 0;
      dir->eof = true;
      return NULL;
    } if (sz > DIRENTS_BUF_SZ) {
      exit(-1);
    }

    dir->buf_sz = sz; 
    dir->buf_offset = 0;
  }
    
  dent = (struct dirent *)((uint8_t *)dir->buf + dir->buf_offset);
  dir->buf_offset += dent->d_reclen;
  return dent;
}

