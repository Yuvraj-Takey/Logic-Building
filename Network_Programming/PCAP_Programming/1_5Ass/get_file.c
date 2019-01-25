/*
 *	a program that reads the packets from the previously saved file (e.g. capture.pcap) and
 *	displays each packet data in hexadecimal format till EOF.
 *
 *
 *	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- PCAP_Programming
 */
 
 #include <pcap/pcap.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <string.h>
 #include <arpa/inet.h>

 #define INT_NAME	50
 #define CAP_PORTION	65536
 #define TIME_OUT	1000
 #define INFINITE	0
 #define LINE_LEN 16
 
 #define ETHER_ADDR_LEN	6
 #define ETHER_TYPE_LEN	2
 #define ETHER_CRC_LEN	4

 #define ETHER_HEADER_LEN	(2 * ETHER_ADDR_LEN) + (ETHER_TYPE_LEN)
 #define ETHERNET_ARP	806
 #define ETHERNET_IP	8

 typedef unsigned short USHORT;
 typedef unsigned char UCHAR;

 
 typedef struct _ether_header
 {
 	UCHAR	src[ETHER_ADDR_LEN] ; 
	UCHAR	dst[ETHER_ADDR_LEN] ;
	USHORT	type ;
 } ether_header ;
 
 
 
 
 static pcap_t *h_inter = NULL;

 /*
  *	Handling signal
  *
  */
 
 void ab_Term(int signum)
 {
 	printf("Abnormally terminating\n");
 	
 	// close the interface handler
 	pcap_close(h_inter);
 	
 	exit(0);
 }

 
 /*
  *	callback function
  *
  */
 void hndProc(u_char *h_file, const struct pcap_pkthdr *header, const u_char *data)
 {
 	// get the ethernet header
 	ether_header *st_ethr = (ether_header*) data;
 	
 	printf("%#x \t", ntohs(st_ethr -> type));
 
 	// iterate till data	
	for(int index = 1; index < header -> caplen+1; index++)
	{
		printf("%.2x ",data[index - 1]);
		
		if((index % LINE_LEN) == 0)
		{
			printf("\n");
		}
	}
		
	
	printf("\n\n");		
 }

 /************************	MAIN	*********************************************************************/
 
 int main()
 {
 	int retval = 0;
 	char errbuf[PCAP_ERRBUF_SIZE] = {"\0"};
 
 	// open the already saved file
 	h_inter = pcap_open_offline("capture.pcap",errbuf);
 	if(h_inter == NULL)
 	{
 		perror("unable to open the file ");
 		return -1;
 	}	
 	
 	/** signal **/

	signal(SIGINT,ab_Term);
	signal(SIGTSTP,ab_Term);
 	
 	// Now, set the listener for each packet on arises
 	retval = pcap_loop(h_inter, INFINITE, hndProc,NULL);
 	if(retval < 0)
 	{
 		perror("pcap_loop ");
 		
 		// close the interface handler
 		pcap_close(h_inter);
 		
 		return retval;
 	}
 	
 	// close the interface handler
 	pcap_close(h_inter);
 	
 	return 0;
 }
 
 
 
