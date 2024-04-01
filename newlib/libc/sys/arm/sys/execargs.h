#ifndef _SYS_EXECARGS_H
#define _SYS_EXECARGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>




struct execargs
{
    char **argv;
    int argc;
    char **envv;
    int envc;
    size_t total_size;   
};



#ifdef __cplusplus
}
#endif

#endif

