/*
 *	A simple tcp Server-Socket application that serves the servises to its client
 *
*	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- Linux_Socket_Programming
 */
 
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/types.h>          /* See NOTES */
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <string.h>

 
 #define MAXCLIENT	10
 #define RUNNING	1
 #define MAXBUF		250
 #define IP_ADDR	"192.168.0.159"
 #define PORT_NO	5000
 #define TRUE		1
 #define FALSE		0
 
 int main()
 {
 
 	int sock_fd = 0, retval = TRUE, st_len = 0, ses_id = 0;
 	struct sockaddr_in addr;
 	char buff[MAXBUF] = {"\0"};
 	
 	// establish the socket connection
 	sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
 	if(sock_fd < 0)
 	{
 		perror("socket ");
 		return sock_fd;
 	}
 	
 	// set the socket attribute
 	if((retval = setsockopt(sock_fd,SOL_SOCKET, SO_REUSEADDR, &retval,sizeof(retval))) < 0 )
 	{
 		perror("setsockopt ");
 		return retval;
 	}
 	
 	
 	// fill the sockaddr_in structure
 	addr.sin_family = AF_INET;
 	addr.sin_port = PORT_NO;
 	addr.sin_addr.s_addr = inet_addr(IP_ADDR);
 	st_len = sizeof(addr);
 	
 	// call to bind function
 	retval = bind(sock_fd,(struct sockaddr *)&addr,st_len);
 	if(retval < 0)
 	{
 		perror("bind ");
 		
 		// close the socket handler
 		close(sock_fd);
 		return retval;
 	}
 	
 	// make listener active
 	retval = listen(sock_fd,MAXCLIENT);
 	if(retval < 0)
 	{
 		perror("listen ");
 		
 		// close the socket handler
 		close(sock_fd);
 		return retval;
 	}
 	
 	// message
 	printf("Server is Running on IP - [%s] PORT - [%d] ..",IP_ADDR,PORT_NO);
 	
 	while(RUNNING)
 	{
 		printf("\nServer is Listening ..\n");
 		
 		// flush the buffer
 		memset(buff,0,MAXBUF);
 		
 		// lock untill client request not gets
 		if((ses_id = accept(sock_fd,(struct sockaddr *)&addr,&st_len)) < 0)
 		{
 			perror("accept : ");
 			continue;
 		}
 		
 		// creating child
 		if(fork() == 0)
 		{ 			
 			//read the data from client
 			retval = read(ses_id,buff,MAXBUF);
 			if(retval < 0)
 			{
 				perror("read ");
 			}
 			else
 			{
 				// write the data on console
 				printf("[D_IP] : [%s]\n",inet_ntoa(addr.sin_addr));
 				printf("[DATA] : [%s]\n",buff);
 				
 				// give the responce to client
 				retval = write(ses_id,"Success",10);
 				if(retval < 0)
	 			{
	 				perror("write ");
	 			}
 			}
 			
 			// close the sesion connection for child
 			close(ses_id);
 			exit(0);
 		}
 		else	// parent
 		{
 			// close the sesion connection for parent
 			close(ses_id);
 			continue;
 		}
 	}
 	
 	// close the socket connection
 	close(sock_fd);
 	
 	return 0;
 }
