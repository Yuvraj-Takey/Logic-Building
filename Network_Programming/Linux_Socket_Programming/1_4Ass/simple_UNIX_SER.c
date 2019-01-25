/*
 *	a simple UNIX-Server (UDP)socket application that will provide service to its client
 *
 *	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- Linux_Socket_Programming
 */
 
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <sys/un.h>
 #include <signal.h>
 
 #define TRUE		1
 #define FALSE		0
 #define RUNNING	1
 #define CON_QUEUE	10
 #define MAXBUFF	200
 #define SOCK_FILE	"unix_sock"
 
 static int sock_fd = 0;
 
/*
 *	Signal handler
 *
 */
  
 void abnorm_TERM(int signum)
 {
 	printf("[SIGNL] : Abnormal Termination\n");
  
  	// close the socket connection
  	close(sock_fd);
  	
  	// remove the socket file
  	unlink(SOCK_FILE);
  	
  	exit(0);
 }
 
 int main()
 {
 	int retval = TRUE, ses_id = 0, st_len = 0;
 	char buff[MAXBUFF] = {"\0"};
 	struct sockaddr_un addr;
 	struct sockaddr_un st_client;
 	
 	if((sock_fd = socket(AF_UNIX,SOCK_DGRAM,0)) < 0)
 	{
 		perror("[SORRY] : socket ");
 		return sock_fd;
 	}
 		
 	// fill the structure with address
 	addr.sun_family = AF_UNIX;
 	memcpy(addr.sun_path,SOCK_FILE,strlen(SOCK_FILE)+1);
 	
 	// get the structure size
 	st_len = sizeof(addr);
 	
 	// bind the socket with name
 	if((retval = bind(sock_fd,(struct sockaddr *) &addr,st_len)) < 0)
 	{
 		perror("[SORRY] : bind ");
 		
 		//close the socket connection
 		close(sock_fd);
 		
 		// remove the socket file
  		unlink(SOCK_FILE);
 		
 		return retval;
 	}
 	
 	/** Signal Handle **/
 	signal(SIGINT,abnorm_TERM);
 	signal(SIGTSTP,abnorm_TERM);

	printf("[SERVR] : is Running...\n");
 	
 	// running continuously
 	while(RUNNING)
 	{
 		// message
 		printf("[SERVR] : is Listening...\n");
 		
 		st_len = sizeof(st_client);
 		
 		// message
 		printf("length of structure is : %d\n",st_len);
 		
		// get the data from client
		if((retval = recvfrom(sock_fd,buff,MAXBUFF,MSG_CMSG_CLOEXEC,(struct sockaddr *) &st_client, &st_len)) < 0)
		{
			perror("recvfrom ");
			break;
		}
		
		// message
		printf("Length is structure is : %d\n",st_len);
		
		// child process 
		if(1)
		{
			printf("[INFO_] : message from client - [%s]\n",buff);
			
			// perform operation
			memset(buff,'\0',MAXBUFF);
			memcpy(buff,"SUCCESS",10);
			
			// send response to client
			if((retval = sendto(sock_fd,buff,sizeof(buff),0,(struct sockaddr *) &st_client, st_len)) < 0)
			{
				perror("[SORRY] : sendto ");
				break;
			}
			
		}
		else
		{
			continue;
		}
		
		//code
 	}
 	
 	// close the socket connection
 	close(sock_fd);	
 	
 	// remove the socket file
  	unlink(SOCK_FILE);	
 	
 	return 0;
 }
