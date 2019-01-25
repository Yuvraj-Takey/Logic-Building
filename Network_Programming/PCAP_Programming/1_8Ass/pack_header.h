
 #include <pcap/pcap.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <string.h>
 #include <arpa/inet.h>
 #include <netinet/ether.h>
 #include <net/ethernet.h>
 
 #define INT_NAME		50
 #define CAP_PORTION		65536
 #define TIME_OUT		1000
 #define INFINITE		0
 #define MAXBUFF		100

 typedef unsigned short USHORT;
 typedef unsigned char UCHAR;

/*********************************	STRUCT HEADERS		***************************************************/
 
 typedef struct _ether_header
 {
 	UCHAR	src[ETHER_ADDR_LEN] ; 
	UCHAR	dst[ETHER_ADDR_LEN] ;
	USHORT	type ;
 } ether_header ;
 

