#include <stdio.h>
#include <mntent.h>
#include <errno.h>
#include <sys/syscalls.h>


/*
 *
 */
FILE *setmntent(const char *filename, const char *type)
{
    errno = ENOSYS;
    return NULL;
}


/*
 *
 */
struct mntent *getmntent(FILE *filep)
{
    errno = ENOSYS;
    return NULL;
}


/*
 *
 */
int addmntent(FILE *filep, const struct mntent *mnt)
{
    errno = ENOSYS;
    return 0;
}


/*
 *
 */
int endmntent(FILE *filep)
{
    errno = ENOSYS;
    return 0;
}


/*
 *
 */
char *hasmntopt(const struct mntent *mnt, const char *opt)
{
    errno = ENOSYS;
    return NULL;
}


