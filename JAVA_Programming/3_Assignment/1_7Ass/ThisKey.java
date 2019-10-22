/*********************************************************************************************************************

	Demonstrate the use of ‘this’ keyword
		a) To refer to current object.
		b) Inside a constructor to call another constructor.
		And also show that this can not be used in static context area.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class ThisClass
 {
 	int iValue;
 	static int jValue;
 	
 	// default constructor
 	public ThisClass()
 	{
 		this.iValue = this.jValue = 0;
 		
 		System.out.println("[THIS] : inside default constructor");
 	}
 	
 	public ThisClass(int iValue)
 	{
 		// calling default constructor
 		this();
 		
 		this.iValue = iValue;
 		
 		System.out.println("[THIS] : inside parameterised constructor");
 	}
 	
 	public static void setValue(int iNo)
 	{
 		//this.jValue = iNo;			// "this" keyward can not be used in static context area
 	}
 	
 }
 
 // main class
 public class ThisKey
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		
 		// get the object
 		ThisClass tc = new ThisClass(10);
 	}
 }
 
 
 
 
