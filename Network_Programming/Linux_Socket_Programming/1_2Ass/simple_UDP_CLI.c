/*
 *	a simple UDP-Client application
 *
*	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- Linux_Socket_Programming
 */
 
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <errno.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>

 
 #define MAXBUFF	100
 #define PORT_NO	5001
 #define IP_ADDR	"192.168.0.159"
 #define TRUE		1
 #define FALSE		0
 
 int main()
 {
 	int sock_fd = 0, retval = TRUE, st_len = 0;
 	struct sockaddr_in addr;
 	char buff[MAXBUFF] = {"\0"};
 	
 	// establish the socket connection
 	sock_fd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
 	if(sock_fd < 0)
 	{
 		perror("socket ");
 		return sock_fd;
 	}
 	
 	// set ocket attribute
 	if((retval = setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&retval,sizeof(retval))) < 0)
 	{
 		perror("setsockopt ");
 		
 		// close the socket connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// fill the sockaddr structure
 	addr.sin_family = AF_INET;
 	addr.sin_port = PORT_NO;
 	addr.sin_addr.s_addr = inet_addr(IP_ADDR);
 	
 	// get the length of structure
 	st_len = sizeof(addr);
 	
 	// accept the data from user
 	printf("Kindly enter the data\n");
 	scanf("%[^'\n']",buff);
 	
 	//send the data to server
 	retval = sendto(sock_fd,buff,strlen(buff),0,(struct sockaddr *) &addr,st_len);
 	if(retval < 0)
 	{
 		perror("sendto ");
 		
 		// close the connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// flushes the buffer
 	memset(buff,0,MAXBUFF);
 	
 	//get the responce from server
 	retval = recvfrom(sock_fd,buff,MAXBUFF,0,(struct sockaddr *)&addr,&st_len);
 	if(retval < 0)
 	{
 		perror("recvfrom ");
 		
 		// close the connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// message from server
 	printf("[RES] : %s\n",buff);
 	
 	// close the socket connection
 	close(sock_fd);
 	
 	return 0;
 }
