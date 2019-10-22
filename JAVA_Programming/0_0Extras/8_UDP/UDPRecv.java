/*******************************************************************************************************

	Create the UDP Server socket connection

	@Author	- Yuvraj Takey
	@Title	- DSSD-JAVA

********************************************************************************************************/

import java.lang.*;
import java.io.*;
import java.net.*;
import java.util.Scanner;

class UDPRecv
{
	public static void main(String arg[])
	{
		System.out.println("JAVA CODE");

		try
		{		
			// get the socket connection
			DatagramSocket ds = new DatagramSocket(5005);
			
			//get the byte array
			byte b[] = new byte[500];
			
			// get the UDP packet
			DatagramPacket dp = new DatagramPacket(b,b.length);
			
			// receive the packet
			ds.receive(dp);
			
			// get the message into string
			String s = new String(b);
			
			// message
			System.out.println("[RECVR] : message - " + s);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
