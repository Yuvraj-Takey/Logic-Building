/**************************************************************************************************

	Create the TCP Client socket connection

	@Author	- Yuvraj Takey
	@Title	- DSSD-JAVA

****************************************************************************************************/

import java.lang.*;
import java.io.*;
import java.util.Scanner;
import java.net.Socket;
import java.io.InputStream;
import java.io.ObjectInputStream;

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

public class TCPClint 
{
	public static void main(String args[]) throws Exception
	{
		System.out.println("JAVA CODE");
		
		// get the reference of Complex class
		Complex c;
		
		try
		{
		
			// get the socket for making connection request with server's Socket Address
			Socket s = new Socket("127.0.0.1",5000);
			
			// get the stream
			InputStream is = s.getInputStream();
			
			// get data stream
			ObjectInputStream ois = new ObjectInputStream(is);
			
			// get the class object form server
			c = (Complex)ois.readObject();
			
			System.out.println("[CLNT] : data from server - real [" + c.real +"] img [" + c.img +"]");
			
			// close the connection
			s.close();
		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}




