/*
 *	a Program to send an ARP request.
 *
 *	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- PCAP_Programming
 */
 
 #include "pack_header.h"
 
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
 
 void get_ARP_Pack(char * pack)
 {
 	char src_MAC[ETHER_ADDR_LEN] = {0x18,0x03,0x73,0xe5,0xe6,0x0e};	// 18:03:73:e5:e6:0e
 	char dst_MAC[ETHER_ADDR_LEN] = {0xff,0xff,0xff,0xff,0xff,0xff};
 	char type[2] = {0x08,0x06};
 	char htype[2] = {0x00, 0x01};
 	char ptype[2] = {0x08,0x00};
 	char hlen[1] = {0x06};
 	char plen[1] = {0x04};
 	char oper[2] = {0x00,0x01};
 	char snd_MAC[ETHER_ADDR_LEN] = {0x18,0x03,0x73,0xe5,0xe6,0x0e};	// 18:03:73:e5:e6:0e
 	char snd_IP[ETHER_IP_LEN] = {0xc0,0xa8,0x00,0x9f};
 	char trg_MAC[ETHER_ADDR_LEN] = {0x18,0x03,0x73,0xe5,0xe7,0x56}; //18:03:73:e5:e7:56	
 	char trg_IP[ETHER_IP_LEN] = {0xc0,0xa8,0x00,0x9e}; 
 	
 	// clear the buffer
 	memset(pack,'\0',ARP_PACK);
 	
 	// fill the ethernet header into packet
 	memcpy(pack,dst_MAC,ETHER_ADDR_LEN);
 	memcpy(pack + 6,src_MAC,ETHER_ADDR_LEN);
 	memcpy(pack + 12, type,2);
 	
 	// fill ARP data into packet
 	memcpy(pack + 14, htype,2);
 	memcpy(pack + 16, ptype,2);
 	memcpy(pack + 18, hlen,1);
 	memcpy(pack + 19, plen,1);
 	memcpy(pack + 20, oper,2);
 	memcpy(pack + 22, snd_MAC,ETHER_ADDR_LEN);
 	memcpy(pack + 28, snd_IP,ETHER_IP_LEN);
 	memcpy(pack + 32, trg_MAC,ETHER_ADDR_LEN);
 	memcpy(pack + 38, trg_IP,ETHER_IP_LEN);

 	
 }

 /************************	MAIN	*********************************************************************/
 
 int main()
 {
 	pcap_if_t *iterate = NULL;
 	int retval = 0;
 	char errbuf[PCAP_ERRBUF_SIZE] = {"\0"};
 	char interface_name[INT_NAME] = {"\0"};
 	char c_data[ARP_PACK] = {"\0"};
 	ether_header ethr;
 	arphdr_t arp;
 	
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
 
 	// call to function that will fill the ARP request packet
 	get_ARP_Pack(c_data);
 	
 	/** signal **/

	signal(SIGINT,ab_Term);
	signal(SIGTSTP,ab_Term);
 	
 	printf("start sending request packets :\n");
 	
 	while(RUNNING)
 	{
 		if((retval = pcap_sendpacket(h_inter,c_data,sizeof(c_data))) < 0)
 		{
 			perror("pcap_sendpacket ");
 			break;
 		}
 		
 		printf("[ARP] : Request \n");
 		//sleep of 1 second
 		sleep(1);
 	}
 	
 	
 	// free the linked list which having the interface list
 	pcap_freealldevs(listdev);
 	
 	// close the interface handler
 	pcap_close(h_inter);
 	
 	return 0;
 }
 
 
 
 
 
 
 
  
