/*********************************************************************************************************************

	Demonstrate the use of ‘super’ keyword.
	a) To refer to a member of super class.
	b) To call super class constructor from sub class constructor.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class One
 {
 	int iValue;
 	
 	// default constructor
 	public One()
 	{
 		iValue = 0;
 		
 		System.out.println("[ONE_] : Inside default constructor");
 	}
 	
 	// param constructor
 	public One(int iNum)
 	{
 		iValue = iNum;
 		
 		System.out.println("[ONE_] : Inside parameterised constructor");
 	}
 }
 
 class Two extends One
 {
 	int jValue;
 	
 	// default constructor
 	public Two()
 	{
 		// call super class constructor
 		super();
 		
 		jValue = 0;
 		
 		System.out.println("[TWO_] : Inside default constructor");
 	}
 	
 	// param constructor
 	public Two(int iNum)
 	{
 		// call super class constructor
 		super();
 		
 		jValue = iNum;
 		
 		System.out.println("[TWO_] : Inside parameterised constructor");
 	}
 	
 	public void getIVal()
 	{
 		// refer to a member of super class.
 		super.iValue = 50;
 		
 		System.out.println("[TWO_] : I-Value is -> " + iValue);
 	}
 }
 
 // main class
 public class SuperKey
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object
 		Two two = new Two(20);
 		two.getIVal();
 	}
 }
 
 
 
 
