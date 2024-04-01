#ifndef	_SYS_STATVFS_H
#define	_SYS_STATVFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <time.h>
#include <sys/types.h>


struct statvfs 
{
  int f_type;
  char *f_mntfromname;
  char *f_mntonname;  
	unsigned long f_bsize;    /* File system block size */
	unsigned long f_frsize;   /* Fundamental file system block size */
	fsblkcnt_t    f_blocks;   /* Num blocks in units of f_frsize */
	fsblkcnt_t    f_bfree;    /* Num free blocks */
	fsblkcnt_t    f_bavail;   /* Num free blocks for non-privileged process */
	fsfilcnt_t    f_files;    /* Total number of file serial numbers */ 
	fsfilcnt_t    f_ffree;    /* Total number of free file serial numbers */ 
	fsfilcnt_t    f_favail;   /* ... for non-privileged process */ 
	unsigned long f_fsid;     /* File system ID */ 
	unsigned long f_flag;     /* Bit mask of f_flag values */  
	unsigned long f_namemax ; /* Maximum filename length */ 
};


struct statfs 
{
  int f_type;
  char *f_mntfromname;
  char *f_mntonname;  
	unsigned long f_bsize;    /* File system block size */
	unsigned long f_frsize;   /* Fundamental file system block size */
	fsblkcnt_t    f_blocks;   /* Num blocks in units of f_frsize */
	fsblkcnt_t    f_bfree;    /* Num free blocks */
	fsblkcnt_t    f_bavail;   /* Num free blocks for non-privileged process */
	fsfilcnt_t    f_files;    /* Total number of file serial numbers */ 
	fsfilcnt_t    f_ffree;    /* Total number of free file serial numbers */ 
	fsfilcnt_t    f_favail;   /* ... for non-privileged process */ 
	unsigned long f_fsid;     /* File system ID */ 
	unsigned long f_flag;     /* Bit mask of f_flag values */  
	unsigned long f_namemax ; /* Maximum filename length */ 
};



#ifdef __cplusplus
}
#endif
#endif /* _SYS_STATVFS_H */

