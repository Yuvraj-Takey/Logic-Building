/**************************************************************************************************

	Create the TCP Server socket connection

	@Author	- Yuvraj Takey
	@Title	- DSSD-JAVA

****************************************************************************************************/


import java.lang.*;
import java.io.*;
import java.util.Scanner;
import java.net.Socket;
import java.net.ServerSocket;
import java.io.OutputStream;
import java.io.ObjectOutputStream;

class Complex implements Serializable
{
	int real;
	int img;
	
	// constructor default
	Complex()
	{
		real = img = 0;
	}
	
	// constructor parameterised
	Complex(int img, int real)
	{
		this.img = img;
		this.real = real;
	}
}

public class TCPServer 
{
	public static void main(String args[]) throws Exception
	{
		System.out.println("JAVA CODE");
		
		try 
		{
			// create the server socket connection with fixed port number
			ServerSocket ss = new ServerSocket(5000);
			
			// get the object of Complex class, that  will send to client
			Complex c = new Complex(10,20);
			
			// run the server
			while(true)
			{
				// accept the connection request from client(if any)
				Socket s = ss.accept();
				
				// get the stream
				OutputStream os = s.getOutputStream();
				
				// get the data stream
				ObjectOutputStream oos = new ObjectOutputStream(os);
				
				// write the object into stream
				oos.writeObject(c);
				
				System.out.println("[SERV] : data sent to client");
				
				// close the client connection
				s.close();
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
