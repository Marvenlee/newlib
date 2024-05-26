#ifndef _SYS_DEBUG_H
#define _SYS_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/syscalls.h>
#include <stdlib.h>
#include <stdio.h>


#if !defined(NDEBUG)

/* @brief   Debug level constants
 *
 * Define one of these log level constants at the top of a source file and include
 * this sys/debug.h header file.  Ensure that NDEBUG is not defined.
 *
 * - LOG_LEVEL_ERROR
 * - LOG_LEVEL_WARN
 * - LOG_LEVEL_INFO
 * - LOG_LEVEL_DEBUG
 * - LOG_LEVEL_TRACE
 */

// Set a default log level if none are defined
#if (!defined(LOG_LEVEL_ERROR) && !defined(LOG_LEVEL_WARN) \
      && !defined(LOG_LEVEL_INFO) && !defined(LOG_LEVEL_DEBUG) \
      && !defined(LOG_LEVEL_TRACE))
#define LOG_LEVEL_INFO
#endif

#if defined(LOG_LEVEL_TRACE)
#define LOG_LEVEL_DEBUG
#endif

#if defined(LOG_LEVEL_DEBUG)
#define LOG_LEVEL_INFO
#endif

#if defined(LOG_LEVEL_INFO)
#define LOG_LEVEL_WARN
#endif

#if defined(LOG_LEVEL_WARN)
#define LOG_LEVEL_ERROR
#endif


/*
 * Prototypes
 */
void debug_printf(const char *format, ...);


/*
 *
 */
#if defined(LOG_LEVEL_ERROR)
#define log_error(fmt, args...)   debug_printf(fmt, ##args)
#endif

#if defined(LOG_LEVEL_WARN)
#define log_warn(fmt, args...)    debug_printf(fmt, ##args)
#else
#define log_warn(fmt, args...)
#endif

#if defined(LOG_LEVEL_INFO)
#define log_info(fmt, args...)    debug_printf(fmt, ##args)
#else
#define log_info(fmt, args...)
#endif

#if defined(LOG_LEVEL_DEBUG)
#define log_debug(fmt, args...)   debug_printf(fmt, ##args)
#else
#define log_debug(fmt, args...)
#endif

#if defined(LOG_LEVEL_TRACE)
#define log_trace(fmt, args...)   debug_printf(fmt, ##args)
#else
#define log_trace(fmt, args...)
#endif

#else

#define log_error(fmt, args...)
#define log_warn(fmt, args...)
#define log_info(fmt, args...)
#define log_debug(fmt, args...)
#define log_trace(fmt, args...)

#endif


#ifdef __cplusplus
}
#endif
#endif


