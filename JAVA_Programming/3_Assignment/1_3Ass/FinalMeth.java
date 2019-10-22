/*********************************************************************************************************************

	Write a program to define constructors and finalize of a class and
	construct 3 objects and then show that it is not a guarantee that finalizer
	will be invoked for each object.

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
 public class FinalMeth
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
 	}
 }
 
 
 
 
