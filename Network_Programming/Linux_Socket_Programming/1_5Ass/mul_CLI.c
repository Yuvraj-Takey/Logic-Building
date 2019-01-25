/*
 *	a simple UDP-Client Socket application that uses multi-casting operation
 *
 *	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- Linux_Socket_Programming
 */
 

#include "pack_header.h"

 static int sock_fd = 0;

/*
 *		Handle Signal
 */
 void ab_TERM(int signum)
 {
 	printf("[CLINT] : abnormal termination\n");
 
 	// close the socket
 	close(sock_fd);
 }

int main()
{
	int retval = TRUE, st_len = 0;
	struct sockaddr_in addr;
	char buff[MAXBUFF] = {"\0"};
	struct ip_mreq m_group;
	
	// establish the socket connection
	if((sock_fd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP)) < 0)
	{
		perror("[SORRY] : socket ");
		return retval;
	}
	
	
	// set the attribute for socket
	if((retval = setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&retval, sizeof(retval))) < 0)
	{
		perror("[SORRY] : setsockopt ");
		return retval;
	}
	
	// fill the sockaddr structure
	addr.sin_family = AF_INET;
	addr.sin_port = PORTNO;
	addr.sin_addr.s_addr = htonl(IPADDR);
	
	// get the size of structure
	st_len = sizeof(addr);
	
	// bind this socket name with address
	if((retval = bind(sock_fd,(struct sockaddr *) &addr,st_len)) < 0)
	{
		perror("[SORRY] : bind ");
		
		// close the socket file
		close(sock_fd);
		
		return retval;
	}
	
	// fill the structure group
	m_group.imr_multiaddr.s_addr=htonl(IPGROP);
	m_group.imr_interface.s_addr = htonl(INADDR_ANY);	// #define INADDR_ANY	0x00000000
	
	// set socket attribute with group info
	if((retval = setsockopt(sock_fd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&m_group, sizeof(m_group))) < 0)
	{
		perror("[SORRY] : setsockopt ");
		
		// close socket file
		close(sock_fd);
		
		return retval;
	}
	
	/** SIGNAL Handle **/
	signal(SIGINT,ab_TERM);
	signal(SIGTSTP,ab_TERM);
	
	printf("[CLINT] : Running..\n");
	
	// running the server
	while(RUNNING)
	{
		if((retval = recvfrom(sock_fd,buff,MAXBUFF,0,(struct sockaddr *) &addr,&st_len)) < 0)
		{
			perror("[SORRY] : recvfrom ");
			break;
		}
		
		printf("[CLINT] : Message from Server [%s] \n",buff);
		
		//flush the buffer
		memset(buff,'\0',MAXBUFF);
	
		// sleep for few second
		sleep(1);
	}

	// close the socket file
	close(sock_fd);

	return 0;	
}
