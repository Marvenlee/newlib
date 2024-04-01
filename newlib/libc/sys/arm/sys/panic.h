#ifndef _SYS_PANIC_H
#define _SYS_PANIC_H

#ifdef __cplusplus
extern "C" {
#endif


#include <sys/syscalls.h>
#include <stdlib.h>
#include <stdio.h>


void debug_printf(const char *format, ...);


#ifndef NDEBUG
#define panic(fmt, args...)   { debug_printf(fmt, ##args); exit(EXIT_FAILURE); }
#else
#define panic(fmt, args...)   { exit(EXIT_FAILURE) }
#endif



#endif


