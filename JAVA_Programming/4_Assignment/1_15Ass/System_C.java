/*********************************************************************************************************************

	a program to print all System properties using system class.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 import java.lang.System;
 import java.util.Properties;
 import java.util.*;
 
 class S_Property
 {
 	// default constructor
 	public S_Property()
 	{
 		// code
 	}
 	
 	public void getDetails()
 	{
 		String sKey;
 		
 		// get the object of Properties class
 		Properties pr = new Properties();
 		
 		// get the properties handle
 		pr = System.getProperties();
 		
 		// get the names into Enumeration
 		Enumeration<?> e = pr.propertyNames();
		
		// iterate the enumeration till end
		while(e.hasMoreElements())
		{
			// get the key from enumeration
			sKey =(String) e.nextElement();
			
			// Result with values
			System.out.printf("%-30s \t ---> %s\n",sKey,pr.getProperty( sKey ));
		}
		

 	}
 }
 
 // main class
 public class System_C
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object
 		S_Property sp = new S_Property();
 		sp.getDetails();
 	}
 }
 
 
 
 
