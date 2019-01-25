
 #include <pcap/pcap.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <string.h>
 #include <arpa/inet.h>
 
 #define INT_NAME		50
 #define CAP_PORTION		65536
 #define TIME_OUT		1000
 #define INFINITE		0

 #define ETHER_ADDR_LEN		6
 #define ETHER_TYPE_LEN		2
 #define ETHER_CRC_LEN		4

 #define ETHER_HEADER_LEN	(2 * ETHER_ADDR_LEN) + (ETHER_TYPE_LEN)
 #define ETHERNET_IP		0x800

 #define IP_INIT_INFO		12
 #define IP4_ADDR_LEN		4

 #define ICMP			0x0100
 #define TCP			0x0600
 #define UDP			0x1100
 #define ANYP			0x0000

 typedef unsigned short USHORT;
 typedef unsigned char UCHAR;


 
 


/*********************************	STRUCT HEADERS		***************************************************/
 
 typedef struct _ether_header
 {
 	UCHAR	src[ETHER_ADDR_LEN] ; 
	UCHAR	dst[ETHER_ADDR_LEN] ;
	USHORT	type ;
 } ether_header ;
 

 typedef struct _ipv4_header
 {
	UCHAR	ip_hl:4,ip_v:4 ;

	UCHAR	ip_tos ;
	USHORT	tot_len ;
	USHORT	id ;
	USHORT	Flags:4,Offset:12 ;

	UCHAR	ttl ;
	UCHAR	Protocol ;
	USHORT	Chksum ;
	struct in_addr	ip_src ;
	struct in_addr	ip_dst ;

 } IP4_HEADER;

