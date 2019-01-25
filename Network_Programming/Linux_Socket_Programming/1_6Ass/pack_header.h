#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define TRUE		1
#define FALSE		0
#define RUNNING		1
#define PORTNO		3333
#define IPADDR		0xC0A800FF		// check in ifconfig
#define BROAD_RECV	0x00000000		
#define MAXBUFF		200
