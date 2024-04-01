#ifndef SYS_FSREQ_H
#define SYS_FSREQ_H


#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/dirent.h>
#include <sys/stat.h>


// TODO Move into newlib
#define WSTAT_MODE  (1<<0)
#define WSTAT_UID   (1<<1)
#define WSTAT_GID   (1<<2)
#define WSTAT_SIZE  (1<<3)
#define WSTAT_ATIME (1<<4)
#define WSTAT_MTIME (1<<5)
#define WSTAT_CTIME (1<<6)


/* @brief   VFS commands
 */
#define CMD_LOOKUP          0
#define CMD_CLOSE           1
#define CMD_READ            2
#define CMD_WRITE           3
#define CMD_READDIR         4
#define CMD_UNLINK          5
#define CMD_RMDIR           6
#define CMD_MKDIR           7
#define CMD_MKNOD           8
#define CMD_RENAME          9
#define CMD_STAT            10
#define CMD_MKLINK          11
#define CMD_CREATE          12
#define CMD_TRUNCATE        13
#define CMD_CHOWN           14
#define CMD_CHMOD           15
#define CMD_ISATTY          16
#define CMD_TCGETATTR       17
#define CMD_TCSETATTR       18
#define CMD_SENDREC         19


/* @brief   Common command header of VFS messages
 */
struct fsreq
{
    int cmd;    

    union
    {
        struct {
            uint32_t dir_inode_nr;
            int name_sz;
        } lookup;

        struct {
            uint32_t dir_inode_nr;
            uint32_t name_sz;
            uint32_t oflags;
            mode_t mode;
            int uid;
            int gid;
        } create;
        
        struct {
            uint32_t inode_nr;
        } close;
        
        struct {
            uint32_t inode_nr;
            off64_t offset;
            uint32_t sz;
        } read;
        
        struct {
            uint32_t inode_nr;
            off64_t offset;
            uint32_t sz;            
        } write;
        
        struct {
            uint32_t inode_nr;
            off64_t offset;
            uint32_t sz;
        } readdir;
        
        struct {
            uint32_t dir_inode_nr;
            uint32_t name_sz;
            mode_t mode;
            int uid;
            int gid;
        } mkdir;
        
        struct {
            uint32_t dir_inode_nr;
            uint32_t name_sz;
        } unlink;
        
        struct {
            uint32_t dir_inode_nr;
            uint32_t name_sz;
        } rmdir;
        
        struct {
            uint32_t inode_nr;
            int uid;
            int gid;
        } chown;
        
        struct {
            uint32_t inode_nr;
            mode_t mode;
        } chmod;
        
        struct {
            uint32_t inode_nr;
            off64_t size;
        } truncate;

        struct {
            uint32_t inode_nr;
        } stat;
        
        struct {
           uint32_t src_dir_inode_nr;
           uint32_t src_name_sz;
           uint32_t dst_dir_inode_nr;
           uint32_t dst_name_sz;
        } rename;
        
        struct {
            uint32_t dir_inode_nr;
            uint32_t name_sz;
            mode_t mode;
            int uid;
            int gid;
        } mknod;

        struct {
            uint32_t dir_inode_nr;
            uint32_t name_sz;
            uint32_t link_sz;
        } mklink;

        struct {
            uint32_t inode_nr;
        } rdlink;
        
        struct {
            uint32_t inode_nr;
        } isatty;

        struct
        {
          uint32_t inode_nr;
        } tcgetattr;

        struct
        {
          uint32_t inode_nr;
        } tcsetattr;
    } args;
};


/* @brief   Common reply header to VFS messages
 */
struct fsreply
{
    union
    {
        // The comments for each command indicate what the status value in
        // replymsg indicates.
        
        // In most cases this is 0 for success, or negative errno value on failure.
        // For transfers such as read, write and readdir the status indicates
        // the number of bytes transferred or negative errno on failure.
        
        // lookup - int status
        struct {
            uint32_t inode_nr;
            mode_t mode;
            int uid;
            int gid;
            off64_t size;
            time_t atime;
            time_t mtime;
            time_t ctime;
        } lookup;
        
        // create - int status
        struct {
            uint32_t inode_nr;
            mode_t mode;
            int uid;
            int gid;
            off64_t size;
            time_t atime;
            time_t mtime;
            time_t ctime;
        } create;

        // mkdir - int status
        struct {
            uint32_t inode_nr;
            mode_t mode;
            int uid;
            int gid;
            off64_t size;
            time_t atime;
            time_t mtime;
            time_t ctime;
        } mkdir;

        // readdir - ssize_t nbytes_read        
        struct {
            off64_t offset;
        } readdir;

        // stat - int status
        struct {
            struct stat stat;
        } stat;

        // mknod - int status           
        struct {
            uint32_t inode_nr;
            mode_t mode;
            int uid;
            int gid;
            off64_t size;
            time_t atime;
            time_t mtime;
            time_t ctime;
        } mknod;
        
        // mklink - int status
        struct {
            uint32_t inode_nr;
        } mklink;   
        
        // rdlink - int status
        struct {
            uint32_t inode_nr;
        } rdlink;
                
        // close - int status
        // read - ssize_t nbytes_read (data follows fsreply)
        // write - ssize_t nbytes_written
        // unlink - int status
        // mkdir - int status
        // rmdir - int status
        // chown - int status
        // chmod - int status
        // truncate - int status
        // rename - int status
        // isatty - int status, 0 if tty, -ENOTTY if not tty
        // tcgetattr - int status (returns tcattr separately)        
        // tcsetattr - int status        
    } args;
};


#endif
