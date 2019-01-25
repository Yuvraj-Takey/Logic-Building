/*
 *	a simple UNIX-Client (TCP)socket application that will request server for service
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
 	printf("[SIGNAL] : Abnormal Termination\n");
  
  	// close the socket connection
  	close(sock_fd);
  	
  	exit(0);
 }
 
 int main()
 {
 	int retval = TRUE, ses_id = 0, st_len = 0;
 	char buff[MAXBUFF] = {"\n"};
 	struct sockaddr_un addr;
 	
 	if((sock_fd = socket(AF_UNIX,SOCK_STREAM,0)) < 0)
 	{
 		perror("socket ");
 		return sock_fd;
 	}
 		
 	// fill the structure with address
 	addr.sun_family = AF_UNIX;
 	memcpy(addr.sun_path,SOCK_FILE,10);
 	
 	// get the structure size
 	st_len = sizeof(addr);
 	
 	
 	/** Signal Handle **/
 	signal(SIGINT,abnorm_TERM);
 	signal(SIGTSTP,abnorm_TERM);

 	
 	// send the connection request to server
 	if((retval = connect(sock_fd,(struct sockaddr *) &addr,st_len)) < 0)
 	{
 		perror("connect ");
 		
 		// close the connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// accept the data from user
 	printf("Kindly enter the data \n");
 	scanf("%[^'\n']",buff);
 	
 	// send the data to server
 	if((retval = write(sock_fd,buff,strlen(buff))) < 0)
 	{
 		perror("write ");
 		
 		// close the connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// clear the buffer
 	memset(buff,'\0',MAXBUFF);
 	
 	// send the data to server
 	if((retval = read(sock_fd,buff,MAXBUFF)) < 0)
 	{
 		perror("read ");
 		
 		// close the connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// message
 	printf("[CLIENT] : replay from server - [%s] \n",buff);
 	
 	// close the connection
 	close(sock_fd);
 	return 0;
 }
