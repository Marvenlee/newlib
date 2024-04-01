/* 
 */



#ifndef _NETDB_H_
#define _NETDB_H_

#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/cdefs.h>
#include <netinet/in.h>



/* The <netdb.h> header may define the in_port_t type and the in_addr_t type
 *  as described in <netinet/in.h>.
 */



struct hostent
{
	char   *h_name;
	char  **h_aliases;
	int     h_addrtype;
	int     h_length;
	char  **h_addr_list;
}; 
   


struct netent
{
	char     *n_name;
	char    **n_aliases;
	int       n_addrtype;
	uint32_t n_net;
};




struct protoent
{
	char   *p_name;
	char  **p_aliases;
	int     p_proto;
};



struct servent
{
	char   *s_name;
	char  **s_aliases;
	int     s_port;
	char   *s_proto;
};




#define IPPORT_RESERVED   1

extern int h_errno;




#define HOST_NOT_FOUND 1
#define NO_DATA 2
#define NO_RECOVERY 3
#define TRY_AGAIN 4



struct addrinfo
{
	int               ai_flags;
	int               ai_family;
	int               ai_socktype;
	int               ai_protocol;
	socklen_t         ai_addrlen;
	struct sockaddr  *ai_addr;
	char             *ai_canonname;
	struct addrinfo  *ai_next;
};




#define AI_PASSIVE			(1<<0)
#define AI_CANONNAME		(1<<1)
#define AI_NUMERICHOST		(1<<2)
#define AI_NUMERICSERV		(1<<3)
#define AI_V4MAPPED			(1<<4)
#define AI_ALL				(1<<5)
#define AI_ADDRCONFIG		(1<<6)




#define NI_NOFQDN			(1<<0)
#define NI_NUMERICHOST		(1<<1)
#define NI_NAMEREQD			(1<<2)
#define NI_NUMERICSERV		(1<<3)
#define NI_NUMERICSCOPE		(1<<4)
#define NI_DGRAM			(1<<5)




#define EAI_AGAIN			1
#define EAI_BADFLAGS		2
#define EAI_FAIL			3
#define EAI_FAMILY			4
#define EAI_MEMORY			5
#define EAI_NONAME			6
#define EAI_SERVICE			7
#define EAI_SOCKTYPE		8
#define EAI_SYSTEM			9
#define EAI_OVERFLOW		10
#define EAI_NODATA          11

#define EAI_ADDRFAMILY      12






void endhostent (void);
void endnetent (void);
void endprotoent (void);
void endservent (void);
void freeaddrinfo (struct addrinfo *);
const char *gai_strerror (int);
int getaddrinfo (const char *restrict, const char *restrict, const struct addrinfo *restrict, struct addrinfo **restrict);
struct hostent *gethostbyaddr (const void *, socklen_t, int);
struct hostent *gethostbyname (const char *);
struct hostent *gethostent (void);
int getnameinfo (const struct sockaddr *restrict, socklen_t, char *restrict, socklen_t, char *restrict, socklen_t, int);
struct netent *getnetbyaddr (uint32_t, int);
struct netent *getnetbyname (const char *);
struct netent *getnetent (void);
struct protoent *getprotobyname (const char *);
struct protoent *getprotobynumber (int);
struct protoent *getprotoent (void);
struct servent *getservbyname (const char *, const char *);
struct servent *getservbyport (int, const char *);
struct servent *getservent (void);
void sethostent (int);
void setnetent (int);
void setprotoent (int);
void setservent (int);










#endif /* !_NETDB_ */

