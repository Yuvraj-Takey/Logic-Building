/*
 *	a Java program to calculate factorial of an integer number, both iterative and recursive solution.
 *
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 
 class Cal_Fact
 {
 	// default constructor
 	Cal_Fact()
 	{
 		// code
 	}
 
 	// call to method
 	public int getFactITE(int iNumber)
 	{
 		if(iNumber <= 0)
 		{
 			System.out.println("[SORRY] : Number is invalid");
 			return 0;
 		}
 		
 		int index = 0, iFact = 0;
 		
 		// iterator till the number
 		for(index = 1, iFact = 1; index <= iNumber; index++)
 		{
 			// calculate the factorial
 			iFact = iFact * index;
 		}
 		
 		return iFact;
 	}
 	
 	// call to method
 	public int getFactREC(int iNumber)
 	{
 		if(iNumber <= 0)
 		{
 			System.out.println("[SORRY] : Number is invalid");
 			return 0;
 		}
 		
 		// Recursion termination condition
 		if(iNumber <= 1)
 		{
 			return 1;
 		}
 		
 		// recursion fact
 		return (iNumber = iNumber * getFactREC(iNumber-1));
 	}
 }
 
 
 class Fact
 {
 	public static void main(String args[])
 	{
 		System.out.println("HELLO_FACTORIAL");
 		
 		int iNumber = 0;
 		
 		// get Scanner object
 		Scanner s = new Scanner(System.in);
 
 		System.out.println("Kindly enter the number for factorial");
 		iNumber = s.nextInt();
 		
 		// get the object
 		Cal_Fact cf = new Cal_Fact();
 		
 		System.out.println("Factorial of given number is : ");
 		
 		// call to method
 		System.out.println("Iterative Approach : " + cf.getFactITE(iNumber));
 		
 		// call to method
 		System.out.println("Recursion Approach : " + cf.getFactREC(iNumber));
 	}
 }
 
 
