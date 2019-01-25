/*
 *	a program to capture the packets on a selected interface. If it’s IP packet then, classify
 *	the packet on the basis of TCP, UDP or ICMP.
 *
 *	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- PCAP_Programming
 */
 
 #include "pack_header.h"
 
 /********************************		GLOBALs		*********************************************************/
 
 static pcap_t *h_inter = NULL;
 static pcap_if_t *listdev = NULL;
 
 /*
  *	Handling signal
  *
  */
 
 void ab_Term(int signum)
 {
 	printf("Abnormally terminating\n");
 	
 	// free the linked list which having the interface list
 	pcap_freealldevs(listdev);
 	
 	// close the interface handler
 	pcap_close(h_inter);
 	
 	exit(0);
 }

 
 /*
  *	callback function
  *
  */
 void hndProc(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes)
 {
 	
 	int ret = 0;
 	
 	// get the ethernet header
 	ether_header *st_ethr = (ether_header*) bytes; 
 	
 	// separate out the packets using "ethernet header type"
 	switch((USHORT)ntohs(st_ethr -> type))
 	{
 		case ETHERNET_IP:
 		{
 			// get the previous header length
 			int h_len = sizeof(ether_header);
 			
 			// get the ipv4 header (add the previous header length to get the exact match)
 			IP4_HEADER * st_ipv4 = (IP4_HEADER *) (bytes + h_len);
 	
 			// message
 			printf("[PACKET] : IP \t\t");
 			
 			// filter the protocol type
 			switch(ntohs(st_ipv4 -> Protocol))
 			{
 				case ICMP:
 				{
 					printf("[PROTO_] : ICMP\n");
 					break;
 				}
 				case TCP:
 				{
 					printf("[PROTO_] : TCP\n");
 					break;
 				}
 				case UDP:
 				{
 					printf("[PROTO_] : UDP\n");
 					break;
 				}
 			}
 			
 			break;
 		}	
 	}
 }

 /************************	MAIN	*********************************************************************/
 
 int main()
 {
 	pcap_if_t *iterate = NULL;
 	int retval = 0;
 	char errbuf[PCAP_ERRBUF_SIZE] = {"\0"};
 	char interface_name[INT_NAME] = {"\0"};
 	
 	
 	// get all the list of interfaces available on wire (the result is linked list)
 	// the first page of wireshark
 	retval = pcap_findalldevs(&listdev,errbuf);
 	if((retval < 0) || (listdev == NULL))
 	{
 		perror("pcap_findalldevs ");
 		return retval;
 	}
 	
 	// message
 	printf("All available interfaces are : \n");
 	
 	// now, iterate whole linked list till end
 	for(iterate = listdev; iterate; iterate = iterate -> next)
 	{
 		printf("-->\t%s\n",iterate -> name);
 	}
 	
 	// Accept the input
 	printf("enter the name of interface that want to open\n");
 	scanf("%s",interface_name);
 	
 	// again, iterate whole linked list till we dont matchup with the user input
 	for(iterate = listdev; iterate; iterate = iterate -> next)
 	{
 		// check for the user input interface name
 		if(memcmp(iterate -> name, interface_name, strlen(interface_name)) == 0)
 		{
 			break;
 		}
 	}
 	
 	// check for end_of_linked_list
 	if(iterate == NULL)
 	{
 		printf("[SORRY] : Your given interface is not found\n");
 		
 		// free the linked list which having the interface list
 		pcap_freealldevs(listdev);
 		
 		return -1;
 	
 	}
 	
 	// Now, get/open the interface handle (user choice)
 	h_inter = pcap_open_live(iterate -> name,CAP_PORTION,1,TIME_OUT,errbuf);
 	if(h_inter == NULL)
 	{
 		perror("pacp_open_live ");
 		
 		// free the linked list which having the interface list
 		pcap_freealldevs(listdev);
 		
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
 		
 		// free the linked list which having the interface list
 		pcap_freealldevs(listdev);
 		
 		// close the interface handler
 		pcap_close(h_inter);
 		
 		return retval;
 	}
 	
 	
 	// free the linked list which having the interface list
 	pcap_freealldevs(listdev);
 	
 	// close the interface handler
 	pcap_close(h_inter);
 	
 	return 0;
 }
 
 
 
 
 
 
 
  
