/*********************************************************************************************************************

	a program to read two numbers from the console, find their sum and
	display the numbers and the sum on the console.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;

 class SumOP
 {
 	private int iNum1, iNum2, iSum;
 	
 	// defualt constructor
 	SumOP()
 	{
 		// set to default
 		iNum1 = iNum2 = iSum = 0;
 	}
 	
 	public void getNum()
 	{
 		// get the scanner object to read value from console
 		Scanner s = new Scanner(System.in);
 		
 		// get from user
 		System.out.println("Kindly enter the two numbers for addition");
 		iNum1 = s.nextInt();
 		iNum2 = s.nextInt();
 	}
 	
 	public void calSum()
 	{
 		// check for 0 value
 		if((iNum1 != 0) && (iNum2 != 0))
 		{
 			// calculate the sum of two numbers
 			iSum = iNum1 + iNum2;
 		}
 	}
 	
 	public void getSum()
 	{
 		// message
 		System.out.println("The addition of " + iNum1 + " and " + iNum2 + " is " + iSum);
 	}
 } 
 
 // main class
 public class Number_C
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object
 		SumOP so = new SumOP();
 		
 		// invoke the object method
 		so.getNum();
 		so.calSum();
 		so.getSum();
 	}
 }
 
 
 
 
