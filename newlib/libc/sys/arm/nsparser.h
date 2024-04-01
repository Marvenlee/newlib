#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NL 257
#define SUCCESS 258
#define UNAVAIL 259
#define NOTFOUND 260
#define TRYAGAIN 261
#define RETURN 262
#define CONTINUE 263
#define STRING 264
#ifdef SYYSTYPE
#undef  SYYSTYPE_IS_DECLARED
#define SYYSTYPE_IS_DECLARED 1
#endif
#ifndef _NSYYSTYPE_IS_DECLARED
#define _NSYYSTYPE_IS_DECLARED 1
typedef union _NSYYSTYPE {
	char *str;
	int   mapval;
} _NSYYSTYPE;
#endif /* !_NSYYSTYPE_IS_DECLARED */
extern _NSYYSTYPE _nsyylval;

#endif /* _yy_defines_h_ */
