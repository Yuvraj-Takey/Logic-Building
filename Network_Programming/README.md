# Logic-Building
Contains some basic codes on C/C++ language




# Implement the following programs using pcap library
1. Write a program which enumerates all the network interfaces available in the system.
2. Write a program which print details (i.e. description etc.) of each of the enumerated interfaces.
3. Write a Program to add a packet capture call for capturing the packets. Print a counter value
inside the packet handler callback function when pcap calls the packet handler function.
4. Write a program to capture the packets on the user selected interface and save the captured
packet data to a file (saved file name can be capture.pcap).
5. Write a program that reads the packets from the previously saved file (e.g. capture.pcap) and
displays each packet data in hexadecimal format till EOF.
6. Write a program to capture the packets on a user selected interface and classify packets on the
basis of ARP or IP packets.
7. Write a program to capture the packets on a selected interface. If it’s IP packet then, classify
the packet on the basis of TCP, UDP or ICMP.
8. Write a program to capture the packets on a user selected interface and print the source and
destination MAC/hardware address and Type field from the Ethernet header. MAC address
should be printed as e.g. e4:11:5b:30:e0:96 and type field as e.g. 0x0806
9. Write a program to capture the packets and print the source and destination IP Address from
the IP header in a dotted notation (i.e. 10.21.55.56).
10. Write a program to capture the packets and if the packet is of UDP type then print the source
and destination port number from the UDP header in decimal form.
11. A filtering expression selects which packets will be passed on to the callback function for process-
ing. Write a program that adds filters to program. Use pcap_compile(. . . ) to compile a packet
filter and pcap_setfilter(. . . ) to associate a filter you have create with the capture you will be
doing.
12. Write a Program to send an ARP request.

## Notes

1. Compile the programs with:
gcc -o output source.c -lpcap

2. Execute the programs with:
sudo ./output <args...>

