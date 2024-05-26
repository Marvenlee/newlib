#ifndef _SYS_MOUNT_H
#define _SYS_MOUNT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/statvfs.h>


/*
 * Major numbers
 */
#define MAJOR_ANON       0    /* Undefined major number */
#define MAJOR_MEM        1    /* Special memory devices, e.g. dev/mem, dev/null or dev/zero */
#define MAJOR_RAMDISK    2    /* RAM-disk devices with no physical backing */
#define MAJOR_MMC        3    /* MMC/SD-Card block storage devices */                              
#define MAJOR_ATA        4    /* SATA/PATA block devices */
#define MAJOR_SCSI       5    /* SCSI devices */
#define MAJOR_FD         6    /* Floppy disk */
#define MAJOR_NET        7    /* Network interfaces */
#define MAJOR_PTTY       8    /* Pseudo TTY */
#define MAJOR_PTTY_SLV   9    /* Pseudo TTY slaves */
#define MAJOR_TTY       10    /* TTY devices, virtual consoles */
#define MAJOR_TTYS      11    /* Serial consoles, e.g. /dev/ttyS0 */
#define MAJOR_LOOP      12    /* Block loopback devices, e.g. /dev/loop0 */
#define MAJOR_KEYBOARD  13    /* Keyboards and Keypads */
#define MAJOR_MOUSE     14    /* Mice */
#define MAJOR_TOUCH     15    /* Touchscreens */
#define MAJOR_TABLET    16    /* Tablets and pens */
#define MAJOR_GFX       17    /* Graphics drivers */
#define MAJOR_AUDIO     18    /* Audio */
#define MAJOR_PRINTER   19    /* Printers */
#define MAJOR_BOARD     20    /* Board-specific drivers */
#define MAJOR_SERIAL    21    /* Serial ports (non-tty) */
#define MAJOR_PARALLEL  22    /* Parallel ports */
#define MAJOR_PCI       23    /* PCI bus */
#define MAJOR_USB       24    /* USB bus */
#define MAJOR_I2C       25    /* I2C bus */
#define MAJRO_SPI       26    /* SPI bus */
#define MAJOR_I2S       27    /* I2S bus */
#define MAJOR_CAN       28    /* CAN bus */
#define MAJOR_GPIO      29    /* GPIO pin control */
#define MAJOR_MIDI      30    /* MIDI devices */
#define MAJOR_MANAGER   31    /* Manager services, e.g. window and clipboard managers */
#define MAJOR_DAEMON    32    /* Daemon background services */
#define MAJOR_PROCFS    33    /* procfs filesystem */
#define MAJOR_CAMERA    34    /* Cameras */


/*
 *
 */
#define MFSNAMELEN      15    /* length of fs type name, not inc. nul */
#define MNAMELEN        90    /* length of buffer for returned name */


/*
 * Mount flags
 */
#define MNT_RDONLY      0x00000001    /* read only filesystem */
#define MNT_SYNCHRONOUS 0x00000002    /* file system written synchronously */
#define MNT_NOEXEC      0x00000004    /* can't exec from filesystem */
#define MNT_NOSUID      0x00000008    /* don't honor setuid bits on fs */
#define MNT_NODEV       0x00000010    /* don't interpret special files */
#define MNT_UNION       0x00000020    /* union with underlying filesystem */
#define MNT_ASYNC       0x00000040    /* file system written asynchronously */
#define MNT_DONTBROWSE  0x00100000    /* file system is not ppropriate path to user data */
#define MNT_IGNORE_OWNERSHIP 0x00200000 /* VFS will ignore ownership information on filesystem objects */
#define MNT_AUTOMOUNTED 0x00400000    /* filesystem was mounted by automounter */
#define MNT_JOURNALED   0x00800000    /* filesystem is journaled */
#define MNT_NOUSERXATTR 0x01000000    /* Don't allow user extended attributes */
#define MNT_DEFWRITE    0x02000000    /* filesystem should defer writes */
#define MNT_NOCACHE     0x04000000    /* VFS does not cache files */
#define MNT_NODNLC      0x08000000    /* VFS does not use DNLC, directory name lookup cache */
#define MNT_NOWAIT      0x00000000
#define MNT_WAIT        0x10000000


/*
 * fsid_t type
 */
typedef struct { long val[2]; } fsid_t;


/*
 * Prototypes
 */
int mknod2(char *path, uint32_t flags, struct stat *stat);
int createmsgport(char *mount_path, uint32_t flags, struct stat *stat, int backlog);
int unmount(int fd, bool force);
int renamemsgport(char *new_path, char *old_path);
int pivotroot(char *new_root, char *old_root);
int ismount(const char *path);
int getfsstat(struct statfs *buf, int bufsize, int flags);
int getmntinfo(struct statfs **mntbufp, int flags);
int bdflush(int fd);


#ifdef __cplusplus
}
#endif

#endif

