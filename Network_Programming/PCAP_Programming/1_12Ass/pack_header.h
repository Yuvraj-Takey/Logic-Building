
 #include <pcap/pcap.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <string.h>
 #include <unistd.h>
 #include <arpa/inet.h>


 #define INT_NAME	50
 #define CAP_PORTION	65536
 #define TIME_OUT	1000
 #define INFINITE	0
 #define RUNNING	1
 #define ETHER_ADDR_LEN	6
 #define ETHER_TYPE_LEN	2
 #define ETHER_IP_LEN	4
 #define ETHERNET_ARP	0x806
 #define ETHERNET_IP	0x800
 #define ARP_REQUEST	1   /* ARP Request             */ 
 #define ARP_REPLY 	2   /* ARP Reply               */ 
 #define ARP_PACK	42

 #define ETHER_HEADER_LEN	(2 * ETHER_ADDR_LEN) + (ETHER_TYPE_LEN)
 
 typedef unsigned char	UCHAR;
 typedef unsigned short	USHORT;


/************************************************	HEADERS		**************************************/

 typedef struct _ether_header
 {
	UCHAR	src[ETHER_ADDR_LEN] ;
	UCHAR	dst[ETHER_ADDR_LEN] ;
	USHORT	type ;
 } ether_header ;


/* ARP Header, (assuming Ethernet+IPv4)            */ 

typedef struct arphdr { 
    u_int16_t htype;    /* Hardware Type           */ 
    u_int16_t ptype;    /* Protocol Type           */ 
    u_char hlen;        /* Hardware Address Length */ 
    u_char plen;        /* Protocol Address Length */ 
    u_int16_t oper;     /* Operation Code          */ 
    u_char sha[6];      /* Sender hardware address */ 
    u_char spa[4];      /* Sender IP address       */ 
    u_char tha[6];      /* Target hardware address */ 
    u_char tpa[4];      /* Target IP address       */ 
}arphdr_t; 


