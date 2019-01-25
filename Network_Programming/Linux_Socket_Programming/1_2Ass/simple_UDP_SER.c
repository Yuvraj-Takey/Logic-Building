/*
 *	a simple UDP-Server application that provides services to its client
 *
*	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- Linux_Socket_Programming
 */
 
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <string.h>
 #include <unistd.h>
 #include <signal.h>
 #include <stdlib.h>
 
 #define PORT_NO	5001
 #define IP_ADDR	"192.168.0.159"
 #define MAXBUFF	250
 #define RUNNING	1
 #define TRUE		1
 #define FALSE		0
 
 static int sock_fd = 0;
 
 /*
  *	Signal handler
  *
  */
  
  void abnorm_TERM(int signum)
  {
  	printf("[SIGNAL] : Abnormal Termination\n");
  	
  	// close the socket connection
 	close(sock_fd);
  	
  	exit(0);
  }
 
 
 int main()
 {
 	int retval = TRUE, st_len = 0;
 	struct sockaddr_in addr, st_cli;
 	char buff[MAXBUFF] = {"\0"};
 	
 	// generate the socket connection
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
 	
 	// fill the structure
 	addr.sin_family = AF_INET;
 	addr.sin_port = PORT_NO;
 	addr.sin_addr.s_addr = inet_addr(IP_ADDR);
 	
 	// get the length of the structure
 	st_len = sizeof(addr);
 	
 	//bind the network address
 	retval = bind(sock_fd,(struct sockaddr *)&addr,st_len);
 	if(retval < 0)
 	{
 		perror("bind ");
 		
 		// close the connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// get the size of structure
 	st_len = sizeof(st_cli);
 	
 	// message
 	printf("[SERVER] : Running on IP - [%s] PORT - [%d]..\n",IP_ADDR,PORT_NO);
 	
 	/** Signal Handle**/
 	
 	signal(SIGINT, abnorm_TERM);
 	signal(SIGTSTP, abnorm_TERM);
 	
 	while(RUNNING)
 	{
 		// message
 		printf("\n[SERVER] : Listening ..\n");
 		
	 	//get the data from client
	 	retval = recvfrom(sock_fd,buff,MAXBUFF,0,(struct sockaddr *)&st_cli,&st_len);
	 	if(retval < 0)
	 	{
	 		perror("recvfrom ");
	 		
	 		// close the connection
	 		close(sock_fd);
	 		
	 		break;
	 	}
	 	
	 	// operation over client data
	 	printf("[CLIENT] : %s\n",buff);
	 	memset(buff,0,MAXBUFF);
	 	memcpy(buff,"SUCCESS",10);
	 	
	 	// get the size of structure
	 	st_len = sizeof(st_cli);
	 	
	 	//send the data to client
	 	retval = sendto(sock_fd,buff,strlen(buff),0,(struct sockaddr *) &st_cli,st_len);
	 	if(retval < 0)
	 	{
	 		perror("sendto ");
	 		
	 		// close the connection
	 		close(sock_fd);
	 		
	 		break;
	 	}
	} 
		
 	// close the socket connection
 	close(sock_fd);
 	return 0;
 }
