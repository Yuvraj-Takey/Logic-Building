/*
 *	a Java program to get IP address.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.net.InetAddress;
 import java.net.UnknownHostException;
 
 class Address
 {
 	// default constructor
 	public Address()
 	{
 		// code
 	}
 	
 	public void getIPDetails()
 	{
 		try
 		{
 			Scanner s = new Scanner(System.in);
 			String sHost;
 		
 			// get input from user
 			System.out.println("Kindly enter the name of host");
 			sHost = s.nextLine();
 			
 			// get the object of InetAddress class
 			InetAddress ia = InetAddress.getByName(sHost);
 			
 			// result
 			System.out.println("\nHost Name \t: " + ia.getHostName());
 			System.out.println("Host IP   \t: " + ia.getHostAddress());
 			System.out.println("Canonical ID\t: " + ia.getCanonicalHostName());
 		}
 		catch(UnknownHostException e)
 		{
 			e.printStackTrace();
 		}
 	}
 }
 
 class Network
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO_NETWORK_DETAILS");
 		
 		// get the object
 		Address ad = new Address();
 		ad.getIPDetails();
 	}
 }
