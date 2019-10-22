/*********************************************************************************************************************

	Define an interface and show that data members of interface are by default
	public, static and final and also show that method members of interface are by
	default abstract and public.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 interface InterExample
 {
 	// int iStore ;				// not passible - as it is Final
 	
 	// private int iStore = 10;		// not ppossible - as all data member are public
 	
 	int iStore = 10;
 	
 	void storeMethod();
 	/*{
 						// not possible - as abstract methods cannot have body
 	}*/
 	
 	
 	//private void storeMethod(int ino);	// not possible - as all methods are public
 	 	
 }
 
 
 // main class
 public class InterfaceX implements InterExample
 {
 	// interface method
 	public void storeMethod()
 	{
 		// as every method from interface should define by implemented class
 	}
 
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 	}
 }
 
 
 
 
