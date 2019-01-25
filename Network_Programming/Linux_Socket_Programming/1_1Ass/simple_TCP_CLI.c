/*
 *	A simple tcp Client-Socket application that request for service to server
 *
 *	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- Linux_Socket_Programming
 */
 
 #include <stdio.h>
 #include <stdio_ext.h>
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <string.h>
 #include <fcntl.h>
 #include <unistd.h>

 #define RUNNING	1
 #define MAXBUF		100
 #define IP_ADDR	"192.168.0.159"
 #define PORT_NO	5000
 #define TRUE		1
 #define FALSE		0
 
 int main()
 {
 	int sock_fd = 0, retval = TRUE, st_len = 0;
 	char buff[MAXBUF] = {"\0"};
 	struct sockaddr_in addr;
 	
 	
 	// generate socket connection
 	sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
 	if(sock_fd < 0)
 	{
 		perror("sock_fd ");
 		return sock_fd;
 	}
 	
 	// set the socket attribute
 	if((retval = setsockopt(sock_fd,SOL_SOCKET, SO_REUSEADDR, &retval,sizeof(retval))) < 0 )
 	{
 		perror("setsockopt ");
 		return retval;
 	}
 	
 	// fill the struct sockaddr_in 
 	addr.sin_family = AF_INET;
 	addr.sin_port = PORT_NO;
 	addr.sin_addr.s_addr = inet_addr(IP_ADDR);
 	
 	// get the size of structure
 	st_len  =sizeof(addr);
 	 	
 	// send connection request to server
 	retval = connect(sock_fd,(struct sockaddr *)&addr,st_len);
 	if(retval < 0)
 	{
 		perror("connect ");
 		return retval;
 	}
 	
 	printf("[Client is Running on IP - [%s] PORT - [%d]\n",IP_ADDR,PORT_NO);
 	
 	// flush the buffer
 	memset(buff,0,MAXBUF);
 		
 	//flush stdin
 	__fpurge(stdin);
 			
 	// get the data from client
 	printf("Kindly enter the data\n");
 	scanf("%[^'\n']s",buff);
 		
 	// send the data to server
 	retval = write(sock_fd,buff,strlen(buff));
 	if(retval < 0)
 	{
 		perror("write ");
 	}
 	else
 	{
 		// flush the buffer
 		memset(buff,0,MAXBUF);
 			
 		// get the responce from server
 		retval = read(sock_fd,&buff,MAXBUF);
		if(retval < 0)
		{
			perror("read ");
		}
		else
		{
			printf("[RES] : %s\n",buff);
		}
 	}
 	
 	// close the connection
 	close(sock_fd);
 	
 	return 0;
 }
