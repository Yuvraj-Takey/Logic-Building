#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define TRUE	1
#define FALSE	0
#define RUNNING	1
#define PORTNO	3333
#define IPADDR	0xE1000013	//	225.0.0.19
#define IPGROP	IPADDR		//	225.0.0.19
#define MAXBUFF	200
