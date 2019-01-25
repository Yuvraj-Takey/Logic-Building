/*
 *	a simple UNIX-Client (UDP)socket application that will request server for service
 *
 *	Reference : https://stackoverflow.com/questions/3324619/unix-domain-socket-using-datagram-communication-between-one-server-process-and
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
 #define SOCK_CFILE	"unix_sock_ePoint"
 
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
  	
  	exit(0);
 }
 
 int main()
 {
 	int retval = TRUE, ses_id = 0, st_len = 0;
 	char buff[MAXBUFF] = {"\0"};
 	struct sockaddr_un addr;
 	struct sockaddr_un cEnd_point;
 	
 	// create listening socket	
 	if((sock_fd = socket(AF_UNIX,SOCK_DGRAM,0)) < 0)
 	{
 		perror("[INFO_] : socket ");
 		return sock_fd;
 	}
 	
 	// fill the structure with address (client's end point)
 	cEnd_point.sun_family = AF_UNIX;
 	memcpy(cEnd_point.sun_path,SOCK_CFILE,strlen(SOCK_CFILE)+1);
 	
 	// fill the structure with address
 	addr.sun_family = AF_UNIX;
 	memcpy(addr.sun_path,SOCK_FILE,strlen(SOCK_FILE)+1);
 	
 	// get the structure size
 	st_len = sizeof(addr);
 	
 	// bind the client's end point
 	if((retval = bind(sock_fd,(struct sockaddr *)&cEnd_point,st_len)) < 0)
 	{
 		perror("[SORRY] : bind ");
 		
 		// close socket connection
 		close(sock_fd);
 		
 		return retval;
 	}
 	
 	// connect client to server_filename
 	if((retval = connect(sock_fd,(struct sockaddr *)&addr,st_len)) < 0)
 	{
 		perror("[SORRY] : connect ");
 		
 		// close socket connection
 		close(sock_fd);
 		
 		return retval;
 	}
 
 	/** Signal Handle **/
 	signal(SIGINT,abnorm_TERM);
 	signal(SIGTSTP,abnorm_TERM);

	printf("[CLINT] : is Running...\n");
 	
 	// accept data from user
 	printf("Kindly enter the data\n");
 	scanf("%[^'\n']",buff);
 	
 	// sent the data to server
	if((retval = sendto(sock_fd,buff,strlen(buff),0,(struct sockaddr *) &addr, st_len)) < 0)
	{
		perror("[INFO_] : sendto ");
		
		// close the connection
		close(sock_fd);
		return retval;
	}
 	
 	// flush the buffer
 	memset(buff,0,MAXBUFF);
 	
 	// message
 	printf("[INFO_] : getting responce from server\n");
 	
	// get the data from server
	if((retval = recvfrom(sock_fd,buff,MAXBUFF,0,(struct sockaddr *) &addr,&st_len)) < 0)
	{
		perror("[INFO_] : recvfrom ");
	}
	else
	{
		printf("[INFO_] : message from server - [%s]\n",buff);		
	}

 	// close the socket connection
 	close(sock_fd);	
 	
 	// unlink the socket file
 	unlink(SOCK_CFILE);
 	
 	return 0;
 }
