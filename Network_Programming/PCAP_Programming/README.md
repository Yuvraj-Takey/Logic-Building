# PCAP(Packet Capturing Library) Programming

	Nowadays, computer networks are usually large and diverse systems that communicate using a wide variety of protocols.
This complexity created the need for more sophisticated tools to monitor and troubleshoot network traffic.
Today, one of the critical tools in any network administrator toolbox is the sniffer

	Sniffers, also known as packet analyzers are programs that have the ability to intercept the traffic that passes over a network

	Packet capture is the action of collecting data as it travels over a network. Sniffers are the best example of packet 
capture systems but many other types of applications need to grab packets off a network card.
Those include network statistical tools, intrusion detection

	Libpcap is an open source library that provides a high level interface to network packet capture systems.
It was created in 1994 by McCanne, Leres and Jacobson - researchers at the Lawrence Berkeley National Laboratory from the
University of California at Berkeley as part of a research project to investigate and improve TCP and Internet gateway performance
Libpcap authors' main objective was ta create a platform-independent API to eliminate the need for system-dependent packet capture
modules in each application, as virtually every Os vendor implements its own capture mechanisms.

	The libpcap API is designed to be used from C and C++. However there are many wrappers that allow its use from languages like Perl,
Python, Java, C# or Ruby. Libpcap runs on most UNIX-like operating systems (Linux, Solaris, BSD, HP...). There is also a Windows version
named Winpcap


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
	- gcc -o output source.c -lpcap

2. Execute the programs with:
	- sudo ./output <args...>

