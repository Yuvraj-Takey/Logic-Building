/*
 *	a program to capture the packets on the user selected interface and save the captured
 *	packet data to a file (saved file name can be capture.pcap).
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
 #define INT_NAME	50
 #define CAP_PORTION	65536
 #define TIME_OUT	1000
 #define INFINITE	0
 
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
 void hndProc(u_char *h_file, const struct pcap_pkthdr *header, const u_char *data)
 {
 	// store the data into file
 	pcap_dump(h_file,header,data);
 }

 /************************	MAIN	*********************************************************************/
 
 int main()
 {
 	pcap_if_t *iterate = NULL;
 	int retval = 0;
 	pcap_dumper_t *h_file = NULL;
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
 	
 	// get the file access
 	h_file = pcap_dump_open(h_inter,"capture.pcap");
 	
 	/** signal **/

	signal(SIGINT,ab_Term);
	signal(SIGTSTP,ab_Term);
 	
 	// Now, set the listener for each packet on arises
 	retval = pcap_loop(h_inter, INFINITE, hndProc,(u_char*)h_file);
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
 
 
 
 
 
 
 
  
