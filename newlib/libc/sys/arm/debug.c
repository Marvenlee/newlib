#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/debug.h>
#include <stdarg.h>
#include <string.h>

uint32_t canary1 = 0xdeadbeef;
static char __klog_buf[100];
uint32_t canary2 = 0xdeadbeef;

/*
 *
 */
void debug_printf(const char *format, ...) {
    va_list ap;

		if (canary1 != 0xdeadbeef || canary2 != 0xdeadbeef) {
			_swi_debug("** debug_printf canary trampled **");
			exit(-1);
		}

    va_start(ap, format);

    vsnprintf(__klog_buf, sizeof __klog_buf - 10, format, ap);
    _swi_debug(__klog_buf);

    va_end(ap);
}

