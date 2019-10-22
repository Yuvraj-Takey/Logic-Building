/*
 *	a program in Java to print Fibonacci series up to given number. Write both iterative 
 *	and recursive version.
 *
 *	@DSSD	- Yuvraj Takey
 *
 */
 
 import java.lang.*;
 import java.util.Scanner;
 
 class Series
 {
 	int iNumber;
 	
 	// default constructor
 	Series()
 	{
 		iNumber = 0;
 	}
 	
 	// Parameterised constructor
 	Series(int ival)
 	{
 		iNumber = ival;
 	}
 	
 	// Iterative Method
 	void getFiboITE()
 	{
 		int iVal1 = 0, iVal2 = 1, iSum = 0;
 		
 		System.out.print("Iterative Version : ");
 		
 		// iterator till given number
 		while(iSum < iNumber)
 		{
 			// print the message to console
 			System.out.print(iSum + " ");
 		
 			// calculate the iSum
 			iSum = iVal1 + iVal2;
 			
 			// copy the value of iVal1 to iVal2
 			iVal2 = iVal1;
 			
 			// copy the value of iSum to iVal1
 			iVal1 = iSum;
 		}
 		
 		System.out.println();
 	}
 	
 	// Recursive Method
 	void getRecursive(int iVal1, int iVal2, int iSum)
 	{
 		// iterator till given number
 		if(iSum >= iNumber)
 		{
 			System.out.println();
 			return;
 		}
 		
 		// print the message to console
 		System.out.print(iSum + " ");
 		
 		// calculate the iSum
 		iSum = iVal1 + iVal2;
 			
 		// copy the value of iVal1 to iVal2
 		iVal2 = iVal1;
 			
 		// copy the value of iSum to iVal1
 		iVal1 = iSum;
 		
 		// recursive call
 		getRecursive(iVal1,iVal2,iSum);
 	}
 	
 	// Recursion method with default argument
 	void getFiboREC(int... arg)
 	{
 		// get length of argument
 		if(arg.length <= 0)
 		{
 			// message
 			System.out.print("Recursive Version : ");
 			
 			// call recursive
 			getRecursive(0,1,0);
 		}
 	}
 }
 
 
 class Fibonacci
 {
 	public static void main(String arg[])
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		int iNumber = 0;
 		
 		System.out.println("Welcome To Fibonacci Series");
 		System.out.println("Kindly enter the number for series");
 		iNumber = s.nextInt();
 		
 		// get the object of class
 		Series fs = new Series(iNumber);
 		
 		// call to method
 		fs.getFiboITE();
 		
 		// call to method
 		fs.getFiboREC();
 	}
 }
