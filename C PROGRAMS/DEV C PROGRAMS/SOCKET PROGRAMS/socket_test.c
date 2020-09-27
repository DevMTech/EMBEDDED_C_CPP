/*struct sockaddr_in
{	sa_family_t 	sin_family;
	in_port_t 		sin_port;
	struct in_addr 	sin_addr;
	unsigned chat 	__pad[..];
}

struct in_addr
{
	in_addr s_addr;
}

sockaddr_in.sin_addr.s_addr=htons(); 	*/

sin_family 
sin_port
sin_addr
__pad[]

sock = socket(AF_INET/*domain = IPv4*/, SOCK_STREAM /*conn. type = TCP/IP*/, 0 /*protocol*/);

// domain 		= 	AF_UNIX/AF_INET/AF_INET6 (address family)
// conn. type 	=	SOCK_DGRAM/SOCK_STREAM
// protocol		=	0 , system selects protocol based on domain and conn. type
// sock = return value of socket() = integer socket descriptor or -1 in case of failure to create socket


