/*********************************************************************************************************************

	write a program to demonstrate the use of following operators.
		a)right shift with sign bit operator >>
		b)left shift operator <<
		c)right shift with zero fill operator >>>

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 
 // main class
 public class OperatorEx
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		int iValue = 20;
 		
 		// Output
 		System.out.println("[INFO_] : right shift			:(iValue >> 2)  " + (iValue >> 2));
 		System.out.println("[INFO_] : left  shift			:(iValue << 2)  " + (iValue << 2));
 		System.out.println("[INFO_] : right shift with zero fill	:(iValue >>> 1) " + (iValue >>> 1));
 		System.out.println("[INFO_] : right shift with zero fill	:(iValue >>> 2) " + (iValue >>> 2));
 		
 	}
 }
 
 
 
 
