/*
 *	a simple UDP-Server Socket application that uses multi-casting operation
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
 	printf("[SERVR] : abnormal termination\n");
 
 	// close the socket
 	close(sock_fd);
 }

int main()
{
	int retval = TRUE, st_len = 0, buf_len = 0;
	struct sockaddr_in addr;
	char buff[MAXBUFF] = {"\0"};
	
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
	addr.sin_addr.s_addr=htonl(IPADDR);
	
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
	
	// get the message from user
	printf("[SERVR] : Kindly enter the message\n");
	scanf("%[^'\n']",buff);
	
	/** SIGNAL Handle **/
	signal(SIGINT,ab_TERM);
	signal(SIGTSTP,ab_TERM);
	
	printf("[SERVR] : Running..\n");
	
	buf_len = strlen(buff);
	
	printf("[SERVR] : Message - [%s]\n",buff);
	
	// running the server
	while(RUNNING)
	{
		if((retval = sendto(sock_fd,buff,buf_len,0,(struct sockaddr *) &addr, st_len)) < 0)
		{
			perror("[SORRY] : sendto ");
			break;
		}
		
		// sleep for few seconds
		sleep(1);
	}
	
	// close the socket file
	close(sock_fd);
	
	return 0;
}
