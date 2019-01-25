/*
 *	a simple UNIX-Server (TCP)socket application that will provide service to its client
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
  	
  	// remove the socket file
  	unlink(SOCK_FILE);
  	
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
 	
 	// set the socket attribute
 	if((retval = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &retval, sizeof(retval))) < 0)
 	{
 		perror("setsockopt ");
 		
 		// close the connection
 		close(sock_fd);
 		
 		// remove the socket file
  		unlink(SOCK_FILE);
 		
 		return retval;
 	}
 	
 	// bind the socket with name
 	if((retval = bind(sock_fd,(struct sockaddr *) &addr,st_len)) < 0)
 	{
 		perror("bind ");
 		
 		//close the socket connection
 		close(sock_fd);
 		
 		// remove the socket file
  		unlink(SOCK_FILE);
 		
 		return retval;
 	}
 	
 	if((retval = listen(sock_fd,CON_QUEUE)) < 0)
 	{
 		perror("listen ");
 		
 		// close the socket connection
 		close(sock_fd);
 		
 		// remove the socket file
  		unlink(SOCK_FILE);
 		
 		return retval;
 	}
 	
 	/** Signal Handle **/
 	signal(SIGINT,abnorm_TERM);
 	signal(SIGTSTP,abnorm_TERM);

	printf("[SERVER] : is Running...\n");
 	
 	while(RUNNING)
 	{
 		// message
 		printf("[SERVER] : is Listening...\n");
 		
 		// accept the connection reuests from all client
		if((ses_id = accept(sock_fd,(struct sockaddr *) &addr,&st_len)) < 0)
		{
			perror("accept ");
		 		
			//close the socket connection
			close(ses_id);
			close(sock_fd);
			
			break;
		}

		// child process		
		if(fork() == 0)
		{
			// read the data from client
			if((retval = read(ses_id,buff,MAXBUFF)) < 0)
			{
				perror("read ");
			}
			else
			{
				// print the data on console
				printf("[SERVER] : Data from client - [%s]\n\n",buff);
				
				// write the responce to its client
				if((retval = write(ses_id,"Success", 10)) < 0)
				{
					perror("write ");
				}
			}
			
		
			// close all the connection
			close(ses_id);
			close(sock_fd);
			exit(0);
		}
		else
		{
			close(ses_id);
			continue;
		}
		
		
 	}
 	
 	// close the socket connection
 	close(sock_fd);	
 	
 	// remove the socket file
  	unlink(SOCK_FILE);	
 	
 	return 0;
 }
