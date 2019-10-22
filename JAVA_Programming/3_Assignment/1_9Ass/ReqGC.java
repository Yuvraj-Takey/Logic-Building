/*********************************************************************************************************************

	a program to make a request to invoke garbage collector.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 
 class InvokeFinal
 {
 	// default constructor
 	public InvokeFinal()
 	{
 		System.out.println("[INFO_] : inside default constructor");
 	}
 	
 	// finalize method
 	public void finalize()
 	{
 		System.out.println("[INFO_] : inside resourse deallocator");
 	}
 }
 
 // main class
 public class ReqGC
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		{
 			// get the object
 			InvokeFinal ifinal1 = new InvokeFinal();
 			InvokeFinal ifinal2 = new InvokeFinal();
 			InvokeFinal ifinal3 = new InvokeFinal();
 			
 			// change reference
 			ifinal1 = ifinal2 = ifinal3 = null;
 		}
 		
 		// make request to invoke garbage collector
 		System.gc();
 	}
 }
 
 
 
 
