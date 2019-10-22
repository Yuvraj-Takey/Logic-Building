/*******************************************************************************************************

	Create the UDP Client socket connection

	@Author	- Yuvraj Takey
	@Title	- DSSD-JAVA

********************************************************************************************************/

import java.lang.*;
import java.io.*;
import java.net.*;
import java.util.Scanner;

class UDPSend
{
	public static void main(String arg[])
	{
		System.out.println("JAVA CODE");
		try 
		{		
			// get the socket connection
			DatagramSocket ds = new DatagramSocket();
			
			String data = "HELLO";
			
			//get the byte array
			byte b[] = data.getBytes();
			
			InetAddress ia = InetAddress.getByName("localhost");
			
			// get the UDP packet
			DatagramPacket dp = new DatagramPacket(b,b.length,ia,5005);
			
			// receive the packet
			ds.send(dp);
			
			// message
			System.out.println("[SENDR_] : message send");
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
