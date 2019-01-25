
/*
 *	a program which print details (i.e. description etc.) of each of the enumerated interfaces.
 *
 *	@Author	- Yuvraj Takey
 *		  yuvraj.takey@gmail.com
 *	@Title	- PCAP_Programming
 */
 
 #include <pcap/pcap.h>
 #include <errno.h>
 
 /************************	MAIN	*********************************************************************/
 
 int main()
 {
 	pcap_if_t *listdev = NULL, *iterate = NULL;
 	int retval = 0;
 	char errbuf[PCAP_ERRBUF_SIZE] = {"\0"}; 	
 	
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
 		printf("-->\t%10s \t : %s\n",iterate -> name,iterate -> description);
 	}
 
 	// free all the linked list
 	pcap_freealldevs(listdev);
 		
 	return 0;
 }
 
 
 
 
 
