/* 
 */



#ifndef _NETINET_IN_H_
#define _NETINET_IN_H_

#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/cdefs.h>



typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;



struct in_addr
{
	in_addr_t s_addr;
};


struct sockaddr_in
{
	sa_family_t sin_family;
	in_port_t sin_port;
	struct in_addr sin_addr;
};




#define IPPROTO_IP			1
#define IPPROTO_ICMP		2
#define IPPROTO_RAW			3
#define IPPROTO_TCP			4
#define IPPROTO_UDP			5



#define INADDR_ANY			1
#define INADDR_BROADCAST	2


#define INET_ADDRSTRLEN		16








#endif /* !_NETINET_IN_ */

