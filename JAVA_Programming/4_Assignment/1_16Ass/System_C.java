/*********************************************************************************************************************

	Define a method setMyProperty (String, String) to set your own system property
	and use the same system property in another method.

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
 	
 	public void setMyProperty(String key, String value)
 	{
 		// use the system method for set the property
 		System.setProperty(key,value);
 	}
 	
 	public void getProperty(String sKey)
 	{	
		// Result with values
		System.out.printf("%-10s \t ---> %s\n\n",sKey,System.getProperty( sKey ));
	}
 }
 
 // main class
 public class System_C
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		String str[] = new String[3];
 		System.out.println("JAVA CODE");
 		Scanner s = new Scanner(System.in);
 		
 		// get the object
 		S_Property sp = new S_Property();
 		
 		// get the property from user
 		System.out.println("Kindly enter the key and value\nprefer: key - (user.name) (java.vendor)");
 		str[0] = s.nextLine();
 		str[1] = s.nextLine();
 		
 		// set the property with user choice
 		sp.setMyProperty(str[0],str[1]);
 		
 		// get the property with user choice
 		System.out.println("Kindly enter the key to get property");
 		str[2] = s.nextLine();
 		
 		// invoke the method
 		sp.getProperty(str[2]);

 	}
 }
 
 
 
 
