#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>
#include <sys/unistd.h>
#include <sys/execargs.h>
#include <stdlib.h>
#include <errno.h>


/*
 *
 */ 
int execve (const char *__path, char * const __argv[], char * const __envp[] )
{
    struct execargs args;
    int argc = 0;
    int envc = 0;
    int sc;
    
    if (__argv != NULL) {
        for (argc = 0; __argv[argc] != NULL; argc++);
    }
    
    if (__envp != NULL) {
        for (envc = 0; __envp[envc] != NULL; envc++);
    }
        
    args.argc = argc;
    args.envc = envc;    
    args.envv = (char **)__envp;
    args.argv = (char **)__argv;
    args.total_size = 0;
    sc = _swi_exec(__path, &args);

    // It can only be an error if it fails.
    errno = -sc;
    return -1;
}




