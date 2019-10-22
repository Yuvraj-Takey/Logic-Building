/*********************************************************************************************************************

	Write a program to demonstrate the use of final keyword with
		a) class
		b) method
		c) data member(primitive value and reference variable and show that you
		can not refer this reference variable to other objects but can change
		the data field of a final reference variable)

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 final class One
 {
 	int iValue;
 	
 	// default constructor
 	public One()
 	{
 		iValue = 0;
 	}
 	
 	public void setValue(int iNo)
 	{
 		iValue = iNo;		
 	}
 	
 	public void getValue()
 	{
 		System.out.println("The value is : " + iValue);
 	}
 	
 }
 
 class Two // extends One				// not possible - cannot inherit from final class One
 {
 	final public int iValue;
 	 
 	// default constructor
 	public Two()
 	{
 		iValue = 10;
 	}
 	
 	public void setValue(int iNo)
 	{
 		//iValue = iNo;				// not possible - cannot assign a value to final variable iValue
 	}
 	
 	final public void getValue()
 	{
 		System.out.println("The value is : " + iValue);
 	}
 }
 
 // main class
 public class FinalKey extends Two
 {
 	int iValue = 20;
 	
 	// override method
 	/*public void getValue()
 	{
 		//
 		// not possible - getValue() in FinalKey cannot override of getValue() in class Two (as it is final)
 		//
	 	
 		System.out.println("The value is : " + iValue);
 	}*/
 	
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		
 		// get the object
 		FinalKey fk = new FinalKey();
 		final One one = new One();
 		Two two = new Two();
 		
 		// can not refer final reference variable to other objects
 		//one = new One();				
 		
 		// change the data field of a final reference variable
 		one.iValue = 20;
 		one.getValue();
 		

 	}
 }
 
 
 
 
