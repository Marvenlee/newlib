#ifndef	_MNTENT_H
#define	_MNTENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <paths.h>


struct mntent
{
	char    *mnt_fsname;    /* name of mounted file system */
	char    *mnt_dir;      /* file system path prefix */
	char    *mnt_type;      /* mount type (see mntent.h) */
	char    *mnt_opts;      /* mount options (see mntent.h) */
	int     mnt_freq;      /* dump frequency in days */
	int     mnt_passno;     /* pass number on parallel fsck */
};


/* Generic mount options.  */
#define MNTOPT_DEFAULTS	"defaults"	/* Use all default options.  */
#define MNTOPT_RO	"ro"          /* Read only.  */
#define MNTOPT_RW	"rw"          /* Read/write.  */
#define MNTOPT_SUID	"suid"      /* Set uid allowed.  */
#define MNTOPT_NOSUID	"nosuid"	/* No set uid allowed.  */
#define MNTOPT_NOAUTO	"noauto"	/* Do not auto mount.  */


#define MNT_CHECKLIST  "/etc/fstab" 
#define	MNTTAB		"/etc/mnttab"
#define	VFSTAB		"/etc/vfstab"
#define	MNTMAXSTR	128

#define MNTTYPE_IGNORE	"ignore"  /* Ignore this entry.  */
#define MNTTYPE_NFS	"nfs"         /* Network file system.  */
#define MNTTYPE_SWAP	"swap"      /* Swap device.  */


FILE *setmntent(const char *filename, const char *type);
struct mntent *getmntent(FILE *filep);
int addmntent(FILE *filep, const struct mntent *mnt);
int endmntent(FILE *filep);
char *hasmntopt(const struct mntent *mnt, const char *opt);
struct mntent *getmntent_r (FILE *stream, struct mntent *result, char *buffer, int bufsize);


#ifdef __cplusplus
}
#endif

#endif


