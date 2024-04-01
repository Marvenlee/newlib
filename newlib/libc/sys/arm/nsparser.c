/* original parser id follows */
/* _nsyysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use _NSYYMAJOR/_NSYYMINOR for ifdefs dependent on parser version) */

#define _NSYYBYACC 1
#define _NSYYMAJOR 2
#define _NSYYMINOR 0
#define _NSYYPATCH 20220114

#define _ns_nsyytext   _nsyytext
#define _ns_nsyylineno	_nsyylineno

#define _NSYYEMPTY        (-1)
#define _nsyyclearin      (_nsyychar = _NSYYEMPTY)
#define _nsyyerrok        (_nsyyerrflag = 0)
#define _NSYYRECOVERING() (_nsyyerrflag != 0)
#define _NSYYENOMEM       (-2)
#define _NSYYEOF          0
#undef _NSYYBTYACC
#define _NSYYBTYACC 0
#define _NSYYDEBUGSTR _NSYYPREFIX "debug"
#define _NSYYPREFIX "_nsyy"

#define _NSYYPURE 0

#line 2 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
/*	$NetBSD: nsparser.y,v 1.12 2012/03/20 17:44:18 matt Exp $	*/

/*-
 * Copyright (c) 1997, 1998, 1999 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Luke Mewburn.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#if defined(LIBC_SCCS) && !defined(lint)
__RCSID("$NetBSD: nsparser.y,v 1.12 2012/03/20 17:44:18 matt Exp $");
#endif /* LIBC_SCCS and not lint */

#include "namespace.h"

#include <assert.h>
#define _NS_PRIVATE
#include <nsswitch.h>
#include <stdio.h>
#include <string.h>
/*#include <syslog.h>*/
#include <sys/debug.h>

static	void	_nsaddsrctomap(const char *);

static	ns_dbt		curdbt;
static	ns_src		cursrc;

extern char *	_ns_nsyytext;
extern int _ns_nsyylineno;
#ifdef _NSYYSTYPE
#undef  _NSYYSTYPE_IS_DECLARED
#define _NSYYSTYPE_IS_DECLARED 1
#endif
#ifndef _NSYYSTYPE_IS_DECLARED
#define _NSYYSTYPE_IS_DECLARED 1
#line 57 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
typedef union _NSYYSTYPE {
	char *str;
	int   mapval;
} _NSYYSTYPE;
#endif /* !_NSYYSTYPE_IS_DECLARED */
#line 90 "nsparser.c"

/* compatibility with bison */
#ifdef _NSYYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef _NSYYPARSE_PARAM_TYPE
#  define _NSYYPARSE_DECL() _nsyyparse(_NSYYPARSE_PARAM_TYPE _NSYYPARSE_PARAM)
# else
#  define _NSYYPARSE_DECL() _nsyyparse(void *_NSYYPARSE_PARAM)
# endif
#else
# define _NSYYPARSE_DECL() _nsyyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef _NSYYLEX_PARAM
# define _NSYYLEX_DECL() _nsyylex(void *_NSYYLEX_PARAM)
# define _NSYYLEX _nsyylex(_NSYYLEX_PARAM)
#else
# define _NSYYLEX_DECL() _nsyylex(void)
# define _NSYYLEX _nsyylex()
#endif

#if !(defined(_nsyylex) || defined(_NSYYSTATE))
int _NSYYLEX_DECL();
#endif

/* Parameters sent to _nsyyerror. */
#ifndef _NSYYERROR_DECL
#define _NSYYERROR_DECL() _ns_nsyyerror(const char *s)
#endif
#ifndef _NSYYERROR_CALL
#define _NSYYERROR_CALL(msg) _ns_nsyyerror(msg)
#endif

extern int _NSYYPARSE_DECL();

#define NL 257
#define SUCCESS 258
#define UNAVAIL 259
#define NOTFOUND 260
#define TRYAGAIN 261
#define RETURN 262
#define CONTINUE 263
#define STRING 264
#define _NSYYERRCODE 256
typedef int _NSYYINT;
static const _NSYYINT _nsyylhs[] = {                           -1,
    0,    0,    3,    3,    4,    4,    4,    4,    5,    6,
    6,    7,    9,    7,    8,    8,   10,    1,    1,    1,
    1,    2,    2,
};
static const _NSYYINT _nsyylen[] = {                            2,
    0,    1,    1,    2,    1,    3,    4,    2,    1,    1,
    2,    1,    0,    5,    1,    2,    3,    1,    1,    1,
    1,    1,    1,
};
static const _NSYYINT _nsyydefred[] = {                         0,
    0,    5,    9,    0,    0,    3,    0,    8,    4,    0,
    6,    0,    0,   10,   13,    7,   11,    0,   18,   19,
   20,   21,    0,    0,   15,    0,   14,   16,   22,   23,
   17,
};
#if defined(_NSYYDESTRUCT_CALL) || defined(_NSYYSTYPE_TOSTRING)
static const _NSYYINT _nsyystos[] = {                           0,
  256,  257,  264,  266,  269,  270,  271,  257,  270,   58,
  257,  264,  272,  273,   91,  257,  273,  275,  258,  259,
  260,  261,  267,  274,  276,   61,   93,  276,  262,  263,
  268,
};
#endif /* _NSYYDESTRUCT_CALL || _NSYYSTYPE_TOSTRING */
static const _NSYYINT _nsyydgoto[] = {                          4,
   23,   31,    5,    6,    7,   13,   14,   24,   18,   25,
};
static const _NSYYINT _nsyysindex[] = {                      -255,
 -249,    0,    0,    0, -255,    0,  -41,    0,    0, -254,
    0,  -73, -253,    0,    0,    0,    0, -245,    0,    0,
    0,    0,  -42,  -93,    0, -256,    0,    0,    0,    0,
    0,
};
static const _NSYYINT _nsyyrindex[] = {                        20,
    0,    0,    0,    0,   21,    0,    0,    0,    0,    0,
    0, -252,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#if _NSYYBTYACC
static const _NSYYINT _nsyycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#endif
static const _NSYYINT _nsyygindex[] = {                         0,
    0,    0,    0,   17,    0,    0,   10,    0,    0,    1,
};
#define _NSYYTABLESIZE 168
static const _NSYYINT _nsyytable[] = {                         27,
    1,    2,   11,   16,   12,   29,   30,    8,    3,   12,
   12,   12,   19,   20,   21,   22,   10,   15,   26,    1,
    2,    9,   17,    0,   28,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,   20,   21,   22,
};
static const _NSYYINT _nsyycheck[] = {                         93,
  256,  257,  257,  257,  257,  262,  263,  257,  264,  264,
  264,  264,  258,  259,  260,  261,   58,   91,   61,    0,
    0,    5,   13,   -1,   24,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  258,  259,  260,  261,
};
#if _NSYYBTYACC
static const _NSYYINT _nsyyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define _NSYYFINAL 4
#ifndef _NSYYDEBUG
#define _NSYYDEBUG 0
#endif
#define _NSYYMAXTOKEN 264
#define _NSYYUNDFTOKEN 277
#define _NSYYTRANSLATE(a) ((a) > _NSYYMAXTOKEN ? _NSYYUNDFTOKEN : (a))
#if _NSYYDEBUG
static const char *const _nsyyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"':'",0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","NL","SUCCESS",
"UNAVAIL","NOTFOUND","TRYAGAIN","RETURN","CONTINUE","STRING","$accept","File",
"Status","Action","Lines","Entry","Database","Srclist","Item","Criteria","$$1",
"Criterion","illegal-symbol",
};
static const char *const _nsyyrule[] = {
"$accept : File",
"File :",
"File : Lines",
"Lines : Entry",
"Lines : Lines Entry",
"Entry : NL",
"Entry : Database ':' NL",
"Entry : Database ':' Srclist NL",
"Entry : error NL",
"Database : STRING",
"Srclist : Item",
"Srclist : Srclist Item",
"Item : STRING",
"$$1 :",
"Item : STRING '[' $$1 Criteria ']'",
"Criteria : Criterion",
"Criteria : Criteria Criterion",
"Criterion : Status '=' Action",
"Status : SUCCESS",
"Status : UNAVAIL",
"Status : NOTFOUND",
"Status : TRYAGAIN",
"Action : RETURN",
"Action : CONTINUE",

};
#endif

#if _NSYYDEBUG
int      _nsyydebug;
#endif

int      _nsyyerrflag;
int      _nsyychar;
_NSYYSTYPE  _nsyyval;
_NSYYSTYPE  _nsyylval;
int      _nsyynerrs;

#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
_NSYYLTYPE  _nsyyloc; /* position returned by actions */
_NSYYLTYPE  _nsyylloc; /* position from the lexer */
#endif

#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
#ifndef _NSYYLLOC_DEFAULT
#define _NSYYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = _NSYYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = _NSYYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = _NSYYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = _NSYYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = _NSYYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = _NSYYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = _NSYYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = _NSYYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* _NSYYLLOC_DEFAULT */
#endif /* defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED) */
#if _NSYYBTYACC

#ifndef _NSYYLVQUEUEGROWTH
#define _NSYYLVQUEUEGROWTH 32
#endif
#endif /* _NSYYBTYACC */

/* define the initial stack-sizes */
#ifdef _NSYYSTACKSIZE
#undef _NSYYMAXDEPTH
#define _NSYYMAXDEPTH  _NSYYSTACKSIZE
#else
#ifdef _NSYYMAXDEPTH
#define _NSYYSTACKSIZE _NSYYMAXDEPTH
#else
#define _NSYYSTACKSIZE 10000
#define _NSYYMAXDEPTH  10000
#endif
#endif

#ifndef _NSYYINITSTACKSIZE
#define _NSYYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    _NSYYINT    *s_base;
    _NSYYINT    *s_mark;
    _NSYYINT    *s_last;
    _NSYYSTYPE  *l_base;
    _NSYYSTYPE  *l_mark;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _NSYYLTYPE  *p_base;
    _NSYYLTYPE  *p_mark;
#endif
} _NSYYSTACKDATA;
#if _NSYYBTYACC

struct _NSYYParseState_s
{
    struct _NSYYParseState_s *save;    /* Previously saved parser state */
    _NSYYSTACKDATA            _nsyystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    _NSYYINT                  ctry;    /* saved index in _nsyyctable[] for this conflict */
};
typedef struct _NSYYParseState_s _NSYYParseState;
#endif /* _NSYYBTYACC */
/* variables for the parser stack */
static _NSYYSTACKDATA _nsyystack;
#if _NSYYBTYACC

/* Current parser state */
static _NSYYParseState *_nsyyps = 0;

/* _nsyypath != NULL: do the full parse, starting at *_nsyypath parser state. */
static _NSYYParseState *_nsyypath = 0;

/* Base of the lexical value queue */
static _NSYYSTYPE *_nsyylvals = 0;

/* Current position at lexical value queue */
static _NSYYSTYPE *_nsyylvp = 0;

/* End position of lexical value queue */
static _NSYYSTYPE *_nsyylve = 0;

/* The last allocated position at the lexical value queue */
static _NSYYSTYPE *_nsyylvlim = 0;

#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static _NSYYLTYPE *_nsyylpsns = 0;

/* Current position at lexical position queue */
static _NSYYLTYPE *_nsyylpp = 0;

/* End position of lexical position queue */
static _NSYYLTYPE *_nsyylpe = 0;

/* The last allocated position at the lexical position queue */
static _NSYYLTYPE *_nsyylplim = 0;
#endif

/* Current position at lexical token queue */
static _NSYYINT  *_nsyylexp = 0;

static _NSYYINT  *_nsyylexemes = 0;
#endif /* _NSYYBTYACC */
#line 155 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"

static void
_nsaddsrctomap(const char *elem)
{
	unsigned int	i;
	int		lineno;

	_DIAGASSERT(elem != NULL);

	lineno = _ns_nsyylineno - (*_ns_nsyytext == '\n' ? 1 : 0);
	if (curdbt.srclistsize > 0) {
		if ((strcasecmp(elem, NSSRC_COMPAT) == 0) ||
		    (strcasecmp(curdbt.srclist[0].name, NSSRC_COMPAT) == 0)) {
			log_warn(
			    "libc nsdispatch: %s line %d: %s",
			    _PATH_NS_CONF, lineno,
			    "'compat' used with other sources");
			return;
		}
	}
	for (i = 0; i < curdbt.srclistsize; i++) {
		if (strcasecmp(curdbt.srclist[i].name, elem) == 0) {
			log_warn(
			    "libc nsdispatch: %s line %d: %s '%s'",
			    _PATH_NS_CONF, lineno,
			    "duplicate source", elem);
			return;
		}
	}
	cursrc.name = elem;
	if (_nsdbtaddsrc(&curdbt, &cursrc) == -1) {
		log_warn(
		    "libc nsdispatch: %s line %d: %s '%s'",
		    _PATH_NS_CONF, lineno,
		    "error adding", elem);
	}
}
#line 462 "nsparser.c"

/* For use in generated program */
#define _nsyydepth (int)(_nsyystack.s_mark - _nsyystack.s_base)
#if _NSYYBTYACC
#define _nsyytrial (_nsyyps->save)
#endif /* _NSYYBTYACC */

#if _NSYYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to _NSYYMAXDEPTH */
static int _nsyygrowstack(_NSYYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    _NSYYINT *newss;
    _NSYYSTYPE *newvs;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _NSYYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = _NSYYINITSTACKSIZE;
    else if (newsize >= _NSYYMAXDEPTH)
        return _NSYYENOMEM;
    else if ((newsize *= 2) > _NSYYMAXDEPTH)
        newsize = _NSYYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (_NSYYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return _NSYYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (_NSYYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return _NSYYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    newps = (_NSYYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return _NSYYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if _NSYYDEBUG
    if (_nsyydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", _NSYYPREFIX, newsize);
#endif
    return 0;
}

#if _NSYYPURE || defined(_NSYY_NO_LEAKS)
static void _nsyyfreestack(_NSYYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define _nsyyfreestack(data) /* nothing */
#endif /* _NSYYPURE || defined(_NSYY_NO_LEAKS) */
#if _NSYYBTYACC

static _NSYYParseState *
_nsyyNewState(unsigned size)
{
    _NSYYParseState *p = (_NSYYParseState *) malloc(sizeof(_NSYYParseState));
    if (p == NULL) return NULL;

    p->_nsyystack.stacksize = size;
    if (size == 0)
    {
        p->_nsyystack.s_base = NULL;
        p->_nsyystack.l_base = NULL;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
        p->_nsyystack.p_base = NULL;
#endif
        return p;
    }
    p->_nsyystack.s_base    = (_NSYYINT *) malloc(size * sizeof(_NSYYINT));
    if (p->_nsyystack.s_base == NULL) return NULL;
    p->_nsyystack.l_base    = (_NSYYSTYPE *) malloc(size * sizeof(_NSYYSTYPE));
    if (p->_nsyystack.l_base == NULL) return NULL;
    memset(p->_nsyystack.l_base, 0, size * sizeof(_NSYYSTYPE));
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    p->_nsyystack.p_base    = (_NSYYLTYPE *) malloc(size * sizeof(_NSYYLTYPE));
    if (p->_nsyystack.p_base == NULL) return NULL;
    memset(p->_nsyystack.p_base, 0, size * sizeof(_NSYYLTYPE));
#endif

    return p;
}

static void
_nsyyFreeState(_NSYYParseState *p)
{
    _nsyyfreestack(&p->_nsyystack);
    free(p);
}
#endif /* _NSYYBTYACC */

#define _NSYYABORT  goto _nsyyabort
#define _NSYYREJECT goto _nsyyabort
#define _NSYYACCEPT goto _nsyyaccept
#define _NSYYERROR  goto _nsyyerrlab
#if _NSYYBTYACC
#define _NSYYVALID        do { if (_nsyyps->save)            goto _nsyyvalid; } while(0)
#define _NSYYVALID_NESTED do { if (_nsyyps->save && \
                                _nsyyps->save->save == 0) goto _nsyyvalid; } while(0)
#endif /* _NSYYBTYACC */

int
_NSYYPARSE_DECL()
{
    int _nsyym, _nsyyn, _nsyystate, _nsyyresult;
#if _NSYYBTYACC
    int _nsyynewerrflag;
    _NSYYParseState *_nsyyerrctx = NULL;
#endif /* _NSYYBTYACC */
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _NSYYLTYPE  _nsyyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if _NSYYDEBUG
    const char *_nsyys;

    if ((_nsyys = getenv("_NSYYDEBUG")) != 0)
    {
        _nsyyn = *_nsyys;
        if (_nsyyn >= '0' && _nsyyn <= '9')
            _nsyydebug = _nsyyn - '0';
    }
    if (_nsyydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", _NSYYPREFIX);
#endif
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    memset(_nsyyerror_loc_range, 0, sizeof(_nsyyerror_loc_range));
#endif

#if _NSYYBTYACC
    _nsyyps = _nsyyNewState(0); if (_nsyyps == 0) goto _nsyyenomem;
    _nsyyps->save = 0;
#endif /* _NSYYBTYACC */
    _nsyym = 0;
    /* _nsyyn is set below */
    _nsyynerrs = 0;
    _nsyyerrflag = 0;
    _nsyychar = _NSYYEMPTY;
    _nsyystate = 0;

#if _NSYYPURE
    memset(&_nsyystack, 0, sizeof(_nsyystack));
#endif

    if (_nsyystack.s_base == NULL && _nsyygrowstack(&_nsyystack) == _NSYYENOMEM) goto _nsyyoverflow;
    _nsyystack.s_mark = _nsyystack.s_base;
    _nsyystack.l_mark = _nsyystack.l_base;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _nsyystack.p_mark = _nsyystack.p_base;
#endif
    _nsyystate = 0;
    *_nsyystack.s_mark = 0;

_nsyyloop:
    if ((_nsyyn = _nsyydefred[_nsyystate]) != 0) goto _nsyyreduce;
    if (_nsyychar < 0)
    {
#if _NSYYBTYACC
        do {
        if (_nsyylvp < _nsyylve)
        {
            /* we're currently re-reading tokens */
            _nsyylval = *_nsyylvp++;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            _nsyylloc = *_nsyylpp++;
#endif
            _nsyychar = *_nsyylexp++;
            break;
        }
        if (_nsyyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (_nsyylvp == _nsyylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (_nsyylvp - _nsyylvals);
                size_t s = (size_t) (_nsyylvlim - _nsyylvals);

                s += _NSYYLVQUEUEGROWTH;
                if ((_nsyylexemes = (_NSYYINT *)realloc(_nsyylexemes, s * sizeof(_NSYYINT))) == NULL) goto _nsyyenomem;
                if ((_nsyylvals   = (_NSYYSTYPE *)realloc(_nsyylvals, s * sizeof(_NSYYSTYPE))) == NULL) goto _nsyyenomem;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                if ((_nsyylpsns   = (_NSYYLTYPE *)realloc(_nsyylpsns, s * sizeof(_NSYYLTYPE))) == NULL) goto _nsyyenomem;
#endif
                _nsyylvp   = _nsyylve = _nsyylvals + p;
                _nsyylvlim = _nsyylvals + s;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                _nsyylpp   = _nsyylpe = _nsyylpsns + p;
                _nsyylplim = _nsyylpsns + s;
#endif
                _nsyylexp  = _nsyylexemes + p;
            }
            *_nsyylexp = (_NSYYINT) _NSYYLEX;
            *_nsyylvp++ = _nsyylval;
            _nsyylve++;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            *_nsyylpp++ = _nsyylloc;
            _nsyylpe++;
#endif
            _nsyychar = *_nsyylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* _NSYYBTYACC */
        _nsyychar = _NSYYLEX;
#if _NSYYBTYACC
        } while (0);
#endif /* _NSYYBTYACC */
        if (_nsyychar < 0) _nsyychar = _NSYYEOF;
#if _NSYYDEBUG
        if (_nsyydebug)
        {
            if ((_nsyys = _nsyyname[_NSYYTRANSLATE(_nsyychar)]) == NULL) _nsyys = _nsyyname[_NSYYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            _NSYYDEBUGSTR, _nsyydepth, _nsyystate, _nsyychar, _nsyys);
#ifdef _NSYYSTYPE_TOSTRING
#if _NSYYBTYACC
            if (!_nsyytrial)
#endif /* _NSYYBTYACC */
                fprintf(stderr, " <%s>", _NSYYSTYPE_TOSTRING(_nsyychar, _nsyylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if _NSYYBTYACC

    /* Do we have a conflict? */
    if (((_nsyyn = _nsyycindex[_nsyystate]) != 0) && (_nsyyn += _nsyychar) >= 0 &&
        _nsyyn <= _NSYYTABLESIZE && _nsyycheck[_nsyyn] == (_NSYYINT) _nsyychar)
    {
        _NSYYINT ctry;

        if (_nsyypath)
        {
            _NSYYParseState *save;
#if _NSYYDEBUG
            if (_nsyydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                _NSYYDEBUGSTR, _nsyydepth, _nsyystate);
#endif
            /* Switch to the next conflict context */
            save = _nsyypath;
            _nsyypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != _nsyystate) _NSYYABORT;
            _nsyyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            _NSYYParseState *save;
#if _NSYYDEBUG
            if (_nsyydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", _NSYYDEBUGSTR, _nsyydepth, _nsyystate);
                if (_nsyyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = _nsyyNewState((unsigned)(_nsyystack.s_mark - _nsyystack.s_base + 1));
            if (save == NULL) goto _nsyyenomem;
            save->save            = _nsyyps->save;
            save->state           = _nsyystate;
            save->errflag         = _nsyyerrflag;
            save->_nsyystack.s_mark  = save->_nsyystack.s_base + (_nsyystack.s_mark - _nsyystack.s_base);
            memcpy (save->_nsyystack.s_base, _nsyystack.s_base, (size_t) (_nsyystack.s_mark - _nsyystack.s_base + 1) * sizeof(_NSYYINT));
            save->_nsyystack.l_mark  = save->_nsyystack.l_base + (_nsyystack.l_mark - _nsyystack.l_base);
            memcpy (save->_nsyystack.l_base, _nsyystack.l_base, (size_t) (_nsyystack.l_mark - _nsyystack.l_base + 1) * sizeof(_NSYYSTYPE));
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            save->_nsyystack.p_mark  = save->_nsyystack.p_base + (_nsyystack.p_mark - _nsyystack.p_base);
            memcpy (save->_nsyystack.p_base, _nsyystack.p_base, (size_t) (_nsyystack.p_mark - _nsyystack.p_base + 1) * sizeof(_NSYYLTYPE));
#endif
            ctry                  = _nsyytable[_nsyyn];
            if (_nsyyctable[ctry] == -1)
            {
#if _NSYYDEBUG
                if (_nsyydebug && _nsyychar >= _NSYYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", _NSYYDEBUGSTR, _nsyydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (_nsyyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!_nsyylexemes)
                {
                    _nsyylexemes = (_NSYYINT *) malloc((_NSYYLVQUEUEGROWTH) * sizeof(_NSYYINT));
                    if (_nsyylexemes == NULL) goto _nsyyenomem;
                    _nsyylvals   = (_NSYYSTYPE *) malloc((_NSYYLVQUEUEGROWTH) * sizeof(_NSYYSTYPE));
                    if (_nsyylvals == NULL) goto _nsyyenomem;
                    _nsyylvlim   = _nsyylvals + _NSYYLVQUEUEGROWTH;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                    _nsyylpsns   = (_NSYYLTYPE *) malloc((_NSYYLVQUEUEGROWTH) * sizeof(_NSYYLTYPE));
                    if (_nsyylpsns == NULL) goto _nsyyenomem;
                    _nsyylplim   = _nsyylpsns + _NSYYLVQUEUEGROWTH;
#endif
                }
                if (_nsyylvp == _nsyylve)
                {
                    _nsyylvp  = _nsyylve = _nsyylvals;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                    _nsyylpp  = _nsyylpe = _nsyylpsns;
#endif
                    _nsyylexp = _nsyylexemes;
                    if (_nsyychar >= _NSYYEOF)
                    {
                        *_nsyylve++ = _nsyylval;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                        *_nsyylpe++ = _nsyylloc;
#endif
                        *_nsyylexp  = (_NSYYINT) _nsyychar;
                        _nsyychar   = _NSYYEMPTY;
                    }
                }
            }
            if (_nsyychar >= _NSYYEOF)
            {
                _nsyylvp--;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                _nsyylpp--;
#endif
                _nsyylexp--;
                _nsyychar = _NSYYEMPTY;
            }
            save->lexeme = (int) (_nsyylvp - _nsyylvals);
            _nsyyps->save   = save;
        }
        if (_nsyytable[_nsyyn] == ctry)
        {
#if _NSYYDEBUG
            if (_nsyydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                _NSYYDEBUGSTR, _nsyydepth, _nsyystate, _nsyyctable[ctry]);
#endif
            if (_nsyychar < 0)
            {
                _nsyylvp++;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                _nsyylpp++;
#endif
                _nsyylexp++;
            }
            if (_nsyystack.s_mark >= _nsyystack.s_last && _nsyygrowstack(&_nsyystack) == _NSYYENOMEM)
                goto _nsyyoverflow;
            _nsyystate = _nsyyctable[ctry];
            *++_nsyystack.s_mark = (_NSYYINT) _nsyystate;
            *++_nsyystack.l_mark = _nsyylval;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            *++_nsyystack.p_mark = _nsyylloc;
#endif
            _nsyychar  = _NSYYEMPTY;
            if (_nsyyerrflag > 0) --_nsyyerrflag;
            goto _nsyyloop;
        }
        else
        {
            _nsyyn = _nsyyctable[ctry];
            goto _nsyyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* _NSYYBTYACC */
    if (((_nsyyn = _nsyysindex[_nsyystate]) != 0) && (_nsyyn += _nsyychar) >= 0 &&
            _nsyyn <= _NSYYTABLESIZE && _nsyycheck[_nsyyn] == (_NSYYINT) _nsyychar)
    {
#if _NSYYDEBUG
        if (_nsyydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            _NSYYDEBUGSTR, _nsyydepth, _nsyystate, _nsyytable[_nsyyn]);
#endif
        if (_nsyystack.s_mark >= _nsyystack.s_last && _nsyygrowstack(&_nsyystack) == _NSYYENOMEM) goto _nsyyoverflow;
        _nsyystate = _nsyytable[_nsyyn];
        *++_nsyystack.s_mark = _nsyytable[_nsyyn];
        *++_nsyystack.l_mark = _nsyylval;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
        *++_nsyystack.p_mark = _nsyylloc;
#endif
        _nsyychar = _NSYYEMPTY;
        if (_nsyyerrflag > 0)  --_nsyyerrflag;
        goto _nsyyloop;
    }
    if (((_nsyyn = _nsyyrindex[_nsyystate]) != 0) && (_nsyyn += _nsyychar) >= 0 &&
            _nsyyn <= _NSYYTABLESIZE && _nsyycheck[_nsyyn] == (_NSYYINT) _nsyychar)
    {
        _nsyyn = _nsyytable[_nsyyn];
        goto _nsyyreduce;
    }
    if (_nsyyerrflag != 0) goto _nsyyinrecovery;
#if _NSYYBTYACC

    _nsyynewerrflag = 1;
    goto _nsyyerrhandler;
    goto _nsyyerrlab; /* redundant goto avoids 'unused label' warning */

_nsyyerrlab:
    /* explicit _NSYYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    _nsyystack.s_mark -= _nsyym;
    _nsyystate = *_nsyystack.s_mark;
    _nsyystack.l_mark -= _nsyym;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _nsyystack.p_mark -= _nsyym;
#endif

    _nsyynewerrflag = 0;
_nsyyerrhandler:
    while (_nsyyps->save)
    {
        int ctry;
        _NSYYParseState *save = _nsyyps->save;
#if _NSYYDEBUG
        if (_nsyydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            _NSYYDEBUGSTR, _nsyydepth, _nsyystate, _nsyyps->save->state,
                    (int)(_nsyylvp - _nsyylvals - _nsyyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (_nsyyerrctx == NULL || _nsyyerrctx->lexeme < _nsyylvp - _nsyylvals)
        {
            /* Free old saved error context state */
            if (_nsyyerrctx) _nsyyFreeState(_nsyyerrctx);
            /* Create and fill out new saved error context state */
            _nsyyerrctx                 = _nsyyNewState((unsigned)(_nsyystack.s_mark - _nsyystack.s_base + 1));
            if (_nsyyerrctx == NULL) goto _nsyyenomem;
            _nsyyerrctx->save           = _nsyyps->save;
            _nsyyerrctx->state          = _nsyystate;
            _nsyyerrctx->errflag        = _nsyyerrflag;
            _nsyyerrctx->_nsyystack.s_mark = _nsyyerrctx->_nsyystack.s_base + (_nsyystack.s_mark - _nsyystack.s_base);
            memcpy (_nsyyerrctx->_nsyystack.s_base, _nsyystack.s_base, (size_t) (_nsyystack.s_mark - _nsyystack.s_base + 1) * sizeof(_NSYYINT));
            _nsyyerrctx->_nsyystack.l_mark = _nsyyerrctx->_nsyystack.l_base + (_nsyystack.l_mark - _nsyystack.l_base);
            memcpy (_nsyyerrctx->_nsyystack.l_base, _nsyystack.l_base, (size_t) (_nsyystack.l_mark - _nsyystack.l_base + 1) * sizeof(_NSYYSTYPE));
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            _nsyyerrctx->_nsyystack.p_mark = _nsyyerrctx->_nsyystack.p_base + (_nsyystack.p_mark - _nsyystack.p_base);
            memcpy (_nsyyerrctx->_nsyystack.p_base, _nsyystack.p_base, (size_t) (_nsyystack.p_mark - _nsyystack.p_base + 1) * sizeof(_NSYYLTYPE));
#endif
            _nsyyerrctx->lexeme         = (int) (_nsyylvp - _nsyylvals);
        }
        _nsyylvp          = _nsyylvals   + save->lexeme;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
        _nsyylpp          = _nsyylpsns   + save->lexeme;
#endif
        _nsyylexp         = _nsyylexemes + save->lexeme;
        _nsyychar         = _NSYYEMPTY;
        _nsyystack.s_mark = _nsyystack.s_base + (save->_nsyystack.s_mark - save->_nsyystack.s_base);
        memcpy (_nsyystack.s_base, save->_nsyystack.s_base, (size_t) (_nsyystack.s_mark - _nsyystack.s_base + 1) * sizeof(_NSYYINT));
        _nsyystack.l_mark = _nsyystack.l_base + (save->_nsyystack.l_mark - save->_nsyystack.l_base);
        memcpy (_nsyystack.l_base, save->_nsyystack.l_base, (size_t) (_nsyystack.l_mark - _nsyystack.l_base + 1) * sizeof(_NSYYSTYPE));
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
        _nsyystack.p_mark = _nsyystack.p_base + (save->_nsyystack.p_mark - save->_nsyystack.p_base);
        memcpy (_nsyystack.p_base, save->_nsyystack.p_base, (size_t) (_nsyystack.p_mark - _nsyystack.p_base + 1) * sizeof(_NSYYLTYPE));
#endif
        ctry           = ++save->ctry;
        _nsyystate        = save->state;
        /* We tried shift, try reduce now */
        if ((_nsyyn = _nsyyctable[ctry]) >= 0) goto _nsyyreduce;
        _nsyyps->save     = save->save;
        save->save     = NULL;
        _nsyyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!_nsyyps->save)
        {
#if _NSYYDEBUG
            if (_nsyydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                _NSYYPREFIX, _nsyydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            _nsyylvp          = _nsyylvals   + _nsyyerrctx->lexeme;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            _nsyylpp          = _nsyylpsns   + _nsyyerrctx->lexeme;
#endif
            _nsyylexp         = _nsyylexemes + _nsyyerrctx->lexeme;
            _nsyychar         = _nsyylexp[-1];
            _nsyylval         = _nsyylvp[-1];
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            _nsyylloc         = _nsyylpp[-1];
#endif
            _nsyystack.s_mark = _nsyystack.s_base + (_nsyyerrctx->_nsyystack.s_mark - _nsyyerrctx->_nsyystack.s_base);
            memcpy (_nsyystack.s_base, _nsyyerrctx->_nsyystack.s_base, (size_t) (_nsyystack.s_mark - _nsyystack.s_base + 1) * sizeof(_NSYYINT));
            _nsyystack.l_mark = _nsyystack.l_base + (_nsyyerrctx->_nsyystack.l_mark - _nsyyerrctx->_nsyystack.l_base);
            memcpy (_nsyystack.l_base, _nsyyerrctx->_nsyystack.l_base, (size_t) (_nsyystack.l_mark - _nsyystack.l_base + 1) * sizeof(_NSYYSTYPE));
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            _nsyystack.p_mark = _nsyystack.p_base + (_nsyyerrctx->_nsyystack.p_mark - _nsyyerrctx->_nsyystack.p_base);
            memcpy (_nsyystack.p_base, _nsyyerrctx->_nsyystack.p_base, (size_t) (_nsyystack.p_mark - _nsyystack.p_base + 1) * sizeof(_NSYYLTYPE));
#endif
            _nsyystate        = _nsyyerrctx->state;
            _nsyyFreeState(_nsyyerrctx);
            _nsyyerrctx       = NULL;
        }
        _nsyynewerrflag = 1;
    }
    if (_nsyynewerrflag == 0) goto _nsyyinrecovery;
#endif /* _NSYYBTYACC */

    _NSYYERROR_CALL("syntax error");
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _nsyyerror_loc_range[1] = _nsyylloc; /* lookahead position is error start position */
#endif

#if !_NSYYBTYACC
    goto _nsyyerrlab; /* redundant goto avoids 'unused label' warning */
_nsyyerrlab:
#endif
    ++_nsyynerrs;

_nsyyinrecovery:
    if (_nsyyerrflag < 3)
    {
        _nsyyerrflag = 3;
        for (;;)
        {
            if (((_nsyyn = _nsyysindex[*_nsyystack.s_mark]) != 0) && (_nsyyn += _NSYYERRCODE) >= 0 &&
                    _nsyyn <= _NSYYTABLESIZE && _nsyycheck[_nsyyn] == (_NSYYINT) _NSYYERRCODE)
            {
#if _NSYYDEBUG
                if (_nsyydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    _NSYYDEBUGSTR, _nsyydepth, *_nsyystack.s_mark, _nsyytable[_nsyyn]);
#endif
                if (_nsyystack.s_mark >= _nsyystack.s_last && _nsyygrowstack(&_nsyystack) == _NSYYENOMEM) goto _nsyyoverflow;
                _nsyystate = _nsyytable[_nsyyn];
                *++_nsyystack.s_mark = _nsyytable[_nsyyn];
                *++_nsyystack.l_mark = _nsyylval;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                _nsyyerror_loc_range[2] = _nsyylloc;
                _NSYYLLOC_DEFAULT(_nsyyloc, _nsyyerror_loc_range, 2); /* position of error span */
                *++_nsyystack.p_mark = _nsyyloc;
#endif
                goto _nsyyloop;
            }
            else
            {
#if _NSYYDEBUG
                if (_nsyydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    _NSYYDEBUGSTR, _nsyydepth, *_nsyystack.s_mark);
#endif
                if (_nsyystack.s_mark <= _nsyystack.s_base) goto _nsyyabort;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                _nsyyerror_loc_range[1] = *_nsyystack.p_mark;
#endif
#if defined(_NSYYDESTRUCT_CALL)
#if _NSYYBTYACC
                if (!_nsyytrial)
#endif /* _NSYYBTYACC */
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                    _NSYYDESTRUCT_CALL("error: discarding state",
                                    _nsyystos[*_nsyystack.s_mark], _nsyystack.l_mark, _nsyystack.p_mark);
#else
                    _NSYYDESTRUCT_CALL("error: discarding state",
                                    _nsyystos[*_nsyystack.s_mark], _nsyystack.l_mark);
#endif /* defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED) */
#endif /* defined(_NSYYDESTRUCT_CALL) */
                --_nsyystack.s_mark;
                --_nsyystack.l_mark;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                --_nsyystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (_nsyychar == _NSYYEOF) goto _nsyyabort;
#if _NSYYDEBUG
        if (_nsyydebug)
        {
            if ((_nsyys = _nsyyname[_NSYYTRANSLATE(_nsyychar)]) == NULL) _nsyys = _nsyyname[_NSYYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            _NSYYDEBUGSTR, _nsyydepth, _nsyystate, _nsyychar, _nsyys);
        }
#endif
#if defined(_NSYYDESTRUCT_CALL)
#if _NSYYBTYACC
        if (!_nsyytrial)
#endif /* _NSYYBTYACC */
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
            _NSYYDESTRUCT_CALL("error: discarding token", _nsyychar, &_nsyylval, &_nsyylloc);
#else
            _NSYYDESTRUCT_CALL("error: discarding token", _nsyychar, &_nsyylval);
#endif /* defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED) */
#endif /* defined(_NSYYDESTRUCT_CALL) */
        _nsyychar = _NSYYEMPTY;
        goto _nsyyloop;
    }

_nsyyreduce:
    _nsyym = _nsyylen[_nsyyn];
#if _NSYYDEBUG
    if (_nsyydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        _NSYYDEBUGSTR, _nsyydepth, _nsyystate, _nsyyn, _nsyyrule[_nsyyn]);
#ifdef _NSYYSTYPE_TOSTRING
#if _NSYYBTYACC
        if (!_nsyytrial)
#endif /* _NSYYBTYACC */
            if (_nsyym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = _nsyym; i > 0; i--)
                {
                    if (i != _nsyym) fputs(", ", stderr);
                    fputs(_NSYYSTYPE_TOSTRING(_nsyystos[_nsyystack.s_mark[1-i]],
                                           _nsyystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (_nsyym > 0)
        _nsyyval = _nsyystack.l_mark[1-_nsyym];
    else
        memset(&_nsyyval, 0, sizeof _nsyyval);
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&_nsyyloc, 0, sizeof(_nsyyloc));
#if _NSYYBTYACC
    if (!_nsyytrial)
#endif /* _NSYYBTYACC */
    {
        _NSYYLLOC_DEFAULT(_nsyyloc, &_nsyystack.p_mark[-_nsyym], _nsyym);
        /* just in case _NSYYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        _nsyyerror_loc_range[1] = _nsyystack.p_mark[1-_nsyym];
    }
#endif

    switch (_nsyyn)
    {
case 7:
#line 85 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{
			int lineno;

			lineno = _ns_nsyylineno - (*_ns_nsyytext == '\n' ? 1 : 0);
			if (_nsdbtput(&curdbt) == -1)
				log_warn(
				    "libc nsdispatch: %s line %d: %s",
				    _PATH_NS_CONF, lineno,
				    "error adding entry");
		}
#line 1144 "nsparser.c"
break;
case 8:
#line 96 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{
			_nsyyerrok;
		}
#line 1151 "nsparser.c"
break;
case 9:
#line 103 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{
			curdbt.name = _nsyylval.str;
			curdbt.srclist = NULL;
			curdbt.srclistsize = 0;
		}
#line 1160 "nsparser.c"
break;
case 12:
#line 117 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{
			cursrc.flags = NS_SUCCESS;
			_nsaddsrctomap(_nsyystack.l_mark[0].str);
		}
#line 1168 "nsparser.c"
break;
case 13:
#line 121 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{ cursrc.flags = NS_SUCCESS; }
#line 1173 "nsparser.c"
break;
case 14:
#line 122 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{
			_nsaddsrctomap(_nsyystack.l_mark[-4].str);
		}
#line 1180 "nsparser.c"
break;
case 17:
#line 134 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{
			if (_nsyystack.l_mark[0].mapval)		/* if action == RETURN set RETURN bit */
				cursrc.flags |= _nsyystack.l_mark[-2].mapval;  
			else		/* else unset it */
				cursrc.flags &= ~_nsyystack.l_mark[-2].mapval;
		}
#line 1190 "nsparser.c"
break;
case 18:
#line 143 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{ _nsyyval.mapval = NS_SUCCESS; }
#line 1195 "nsparser.c"
break;
case 19:
#line 144 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{ _nsyyval.mapval = NS_UNAVAIL; }
#line 1200 "nsparser.c"
break;
case 20:
#line 145 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{ _nsyyval.mapval = NS_NOTFOUND; }
#line 1205 "nsparser.c"
break;
case 21:
#line 146 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{ _nsyyval.mapval = NS_TRYAGAIN; }
#line 1210 "nsparser.c"
break;
case 22:
#line 150 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{ _nsyyval.mapval = 1L; }
#line 1215 "nsparser.c"
break;
case 23:
#line 151 "/home/marven/Git/cheviot/bsdutils/lib/nsparser.y"
	{ _nsyyval.mapval = 0L; }
#line 1220 "nsparser.c"
break;
#line 1222 "nsparser.c"
    default:
        break;
    }
    _nsyystack.s_mark -= _nsyym;
    _nsyystate = *_nsyystack.s_mark;
    _nsyystack.l_mark -= _nsyym;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _nsyystack.p_mark -= _nsyym;
#endif
    _nsyym = _nsyylhs[_nsyyn];
    if (_nsyystate == 0 && _nsyym == 0)
    {
#if _NSYYDEBUG
        if (_nsyydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", _NSYYDEBUGSTR, _nsyydepth);
#ifdef _NSYYSTYPE_TOSTRING
#if _NSYYBTYACC
            if (!_nsyytrial)
#endif /* _NSYYBTYACC */
                fprintf(stderr, "result is <%s>, ", _NSYYSTYPE_TOSTRING(_nsyystos[_NSYYFINAL], _nsyyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", _NSYYFINAL);
        }
#endif
        _nsyystate = _NSYYFINAL;
        *++_nsyystack.s_mark = _NSYYFINAL;
        *++_nsyystack.l_mark = _nsyyval;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
        *++_nsyystack.p_mark = _nsyyloc;
#endif
        if (_nsyychar < 0)
        {
#if _NSYYBTYACC
            do {
            if (_nsyylvp < _nsyylve)
            {
                /* we're currently re-reading tokens */
                _nsyylval = *_nsyylvp++;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                _nsyylloc = *_nsyylpp++;
#endif
                _nsyychar = *_nsyylexp++;
                break;
            }
            if (_nsyyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (_nsyylvp == _nsyylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (_nsyylvp - _nsyylvals);
                    size_t s = (size_t) (_nsyylvlim - _nsyylvals);

                    s += _NSYYLVQUEUEGROWTH;
                    if ((_nsyylexemes = (_NSYYINT *)realloc(_nsyylexemes, s * sizeof(_NSYYINT))) == NULL)
                        goto _nsyyenomem;
                    if ((_nsyylvals   = (_NSYYSTYPE *)realloc(_nsyylvals, s * sizeof(_NSYYSTYPE))) == NULL)
                        goto _nsyyenomem;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                    if ((_nsyylpsns   = (_NSYYLTYPE *)realloc(_nsyylpsns, s * sizeof(_NSYYLTYPE))) == NULL)
                        goto _nsyyenomem;
#endif
                    _nsyylvp   = _nsyylve = _nsyylvals + p;
                    _nsyylvlim = _nsyylvals + s;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                    _nsyylpp   = _nsyylpe = _nsyylpsns + p;
                    _nsyylplim = _nsyylpsns + s;
#endif
                    _nsyylexp  = _nsyylexemes + p;
                }
                *_nsyylexp = (_NSYYINT) _NSYYLEX;
                *_nsyylvp++ = _nsyylval;
                _nsyylve++;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
                *_nsyylpp++ = _nsyylloc;
                _nsyylpe++;
#endif
                _nsyychar = *_nsyylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* _NSYYBTYACC */
            _nsyychar = _NSYYLEX;
#if _NSYYBTYACC
            } while (0);
#endif /* _NSYYBTYACC */
            if (_nsyychar < 0) _nsyychar = _NSYYEOF;
#if _NSYYDEBUG
            if (_nsyydebug)
            {
                if ((_nsyys = _nsyyname[_NSYYTRANSLATE(_nsyychar)]) == NULL) _nsyys = _nsyyname[_NSYYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                _NSYYDEBUGSTR, _nsyydepth, _NSYYFINAL, _nsyychar, _nsyys);
            }
#endif
        }
        if (_nsyychar == _NSYYEOF) goto _nsyyaccept;
        goto _nsyyloop;
    }
    if (((_nsyyn = _nsyygindex[_nsyym]) != 0) && (_nsyyn += _nsyystate) >= 0 &&
            _nsyyn <= _NSYYTABLESIZE && _nsyycheck[_nsyyn] == (_NSYYINT) _nsyystate)
        _nsyystate = _nsyytable[_nsyyn];
    else
        _nsyystate = _nsyydgoto[_nsyym];
#if _NSYYDEBUG
    if (_nsyydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", _NSYYDEBUGSTR, _nsyydepth);
#ifdef _NSYYSTYPE_TOSTRING
#if _NSYYBTYACC
        if (!_nsyytrial)
#endif /* _NSYYBTYACC */
            fprintf(stderr, "result is <%s>, ", _NSYYSTYPE_TOSTRING(_nsyystos[_nsyystate], _nsyyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *_nsyystack.s_mark, _nsyystate);
    }
#endif
    if (_nsyystack.s_mark >= _nsyystack.s_last && _nsyygrowstack(&_nsyystack) == _NSYYENOMEM) goto _nsyyoverflow;
    *++_nsyystack.s_mark = (_NSYYINT) _nsyystate;
    *++_nsyystack.l_mark = _nsyyval;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    *++_nsyystack.p_mark = _nsyyloc;
#endif
    goto _nsyyloop;
#if _NSYYBTYACC

    /* Reduction declares that this path is valid. Set _nsyypath and do a full parse */
_nsyyvalid:
    if (_nsyypath) _NSYYABORT;
    while (_nsyyps->save)
    {
        _NSYYParseState *save = _nsyyps->save;
        _nsyyps->save = save->save;
        save->save = _nsyypath;
        _nsyypath = save;
    }
#if _NSYYDEBUG
    if (_nsyydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        _NSYYDEBUGSTR, _nsyydepth, _nsyystate, _nsyypath->state, (int)(_nsyylvp - _nsyylvals - _nsyypath->lexeme));
#endif
    if (_nsyyerrctx)
    {
        _nsyyFreeState(_nsyyerrctx);
        _nsyyerrctx = NULL;
    }
    _nsyylvp          = _nsyylvals + _nsyypath->lexeme;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _nsyylpp          = _nsyylpsns + _nsyypath->lexeme;
#endif
    _nsyylexp         = _nsyylexemes + _nsyypath->lexeme;
    _nsyychar         = _NSYYEMPTY;
    _nsyystack.s_mark = _nsyystack.s_base + (_nsyypath->_nsyystack.s_mark - _nsyypath->_nsyystack.s_base);
    memcpy (_nsyystack.s_base, _nsyypath->_nsyystack.s_base, (size_t) (_nsyystack.s_mark - _nsyystack.s_base + 1) * sizeof(_NSYYINT));
    _nsyystack.l_mark = _nsyystack.l_base + (_nsyypath->_nsyystack.l_mark - _nsyypath->_nsyystack.l_base);
    memcpy (_nsyystack.l_base, _nsyypath->_nsyystack.l_base, (size_t) (_nsyystack.l_mark - _nsyystack.l_base + 1) * sizeof(_NSYYSTYPE));
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
    _nsyystack.p_mark = _nsyystack.p_base + (_nsyypath->_nsyystack.p_mark - _nsyypath->_nsyystack.p_base);
    memcpy (_nsyystack.p_base, _nsyypath->_nsyystack.p_base, (size_t) (_nsyystack.p_mark - _nsyystack.p_base + 1) * sizeof(_NSYYLTYPE));
#endif
    _nsyystate        = _nsyypath->state;
    goto _nsyyloop;
#endif /* _NSYYBTYACC */

_nsyyoverflow:
    _NSYYERROR_CALL("yacc stack overflow");
#if _NSYYBTYACC
    goto _nsyyabort_nomem;
_nsyyenomem:
    _NSYYERROR_CALL("memory exhausted");
_nsyyabort_nomem:
#endif /* _NSYYBTYACC */
    _nsyyresult = 2;
    goto _nsyyreturn;

_nsyyabort:
    _nsyyresult = 1;
    goto _nsyyreturn;

_nsyyaccept:
#if _NSYYBTYACC
    if (_nsyyps->save) goto _nsyyvalid;
#endif /* _NSYYBTYACC */
    _nsyyresult = 0;

_nsyyreturn:
#if defined(_NSYYDESTRUCT_CALL)
    if (_nsyychar != _NSYYEOF && _nsyychar != _NSYYEMPTY)
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
        _NSYYDESTRUCT_CALL("cleanup: discarding token", _nsyychar, &_nsyylval, &_nsyylloc);
#else
        _NSYYDESTRUCT_CALL("cleanup: discarding token", _nsyychar, &_nsyylval);
#endif /* defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED) */

    {
        _NSYYSTYPE *pv;
#if defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED)
        _NSYYLTYPE *pp;

        for (pv = _nsyystack.l_base, pp = _nsyystack.p_base; pv <= _nsyystack.l_mark; ++pv, ++pp)
             _NSYYDESTRUCT_CALL("cleanup: discarding state",
                             _nsyystos[*(_nsyystack.s_base + (pv - _nsyystack.l_base))], pv, pp);
#else
        for (pv = _nsyystack.l_base; pv <= _nsyystack.l_mark; ++pv)
             _NSYYDESTRUCT_CALL("cleanup: discarding state",
                             _nsyystos[*(_nsyystack.s_base + (pv - _nsyystack.l_base))], pv);
#endif /* defined(_NSYYLTYPE) || defined(_NSYYLTYPE_IS_DECLARED) */
    }
#endif /* defined(_NSYYDESTRUCT_CALL) */

#if _NSYYBTYACC
    if (_nsyyerrctx)
    {
        _nsyyFreeState(_nsyyerrctx);
        _nsyyerrctx = NULL;
    }
    while (_nsyyps)
    {
        _NSYYParseState *save = _nsyyps;
        _nsyyps = save->save;
        save->save = NULL;
        _nsyyFreeState(save);
    }
    while (_nsyypath)
    {
        _NSYYParseState *save = _nsyypath;
        _nsyypath = save->save;
        save->save = NULL;
        _nsyyFreeState(save);
    }
#endif /* _NSYYBTYACC */
    _nsyyfreestack(&_nsyystack);
    return (_nsyyresult);
}
