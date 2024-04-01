#ifndef _UNISTD_H_
#define _UNISTD_H_

# include <sys/unistd.h>

#define	GETPASS_NEED_TTY		0x001	/* Fail if we cannot set tty */
#define	GETPASS_FAIL_EOF		0x002	/* Fail on EOF */
#define	GETPASS_BUF_LIMIT		0x004	/* beep on buffer limit */
#define	GETPASS_NO_SIGNAL		0x008	/* don't make ttychars send signals */
#define	GETPASS_NO_BEEP			0x010	/* don't beep */
#define	GETPASS_ECHO				0x020	/* echo characters as they are typed */
#define	GETPASS_ECHO_STAR		0x040	/* echo '*' for each character */
#define	GETPASS_7BIT				0x080	/* mask the high bit each char */
#define	GETPASS_FORCE_LOWER	0x100	/* lowercase each char */
#define	GETPASS_FORCE_UPPER	0x200	/* uppercase each char */
#define	GETPASS_ECHO_NL			0x400	/* echo a newline if successful */

#define	_SC_PASS_MAX				70

#endif /* _UNISTD_H_ */
