/*
 *	a Java program to reverse a number using for, while and recursion.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;

 class NumRev
 {
 	int iNumber;
 	
 	// default constructor
 	NumRev()
 	{
 		iNumber = 0;
 	}
 	
 	// parameterised constructor
 	NumRev(int ival)
 	{
 		iNumber = ival;
 	}
 	
 	void getNum()
 	{
 		// get the Scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get user input
 		System.out.println("Kindly enter the number");
 		iNumber = s.nextInt();
 	}
 	
 	
 	// method using for loop
 	public int revFOR()
 	{
 		int index = 0, iTemp = iNumber, iDigit = 0, iNewNum = 0;
 		
 		// iterate loop
 		for(index = 0; iTemp != 0; index++)
 		{
 			// get the digit
 			iDigit = iTemp % 10;
 			
 			// recollect the number
 			iNewNum = iNewNum * 10 + iDigit;
 			
 			// reduce the number
 			iTemp = iTemp / 10;
 		}
 		
 		return iNewNum;
 	}
 	
 	// method using while loop
 	public int revWHI()
 	{ 		
 		int iTemp = iNumber, iDigit = 0, iNewNum = 0;
 		
 		// iterate loop
 		while(iTemp != 0)
 		{
 			// get the digit
 			iDigit = iTemp % 10;
 			
 			// recollect the number
 			iNewNum = iNewNum * 10 + iDigit;
 			
 			// reduce the number
 			iTemp = iTemp / 10;
 		}
 		
 		return iNewNum;
 	}
 	
 	private int nRecursive(int iNum, int iRev)
 	{
 		// termination condition
 		if(iNum == 0)
 		{
 			return iRev;
 		}
 		
 		// recollect the number
 		iRev = iRev * 10 + (iNum % 10);
 		
 		// call to recursive method
 		iRev = nRecursive(iNum/10, iRev);
 		
 		return iRev;
 	}
 	
 	public int revREC()
 	{
 		int iDigit = 0, iNewNum = 0;
 		
 		// call to the recursive method
 		iNewNum = nRecursive(iNumber,0);
 		
 		return iNewNum;
  	}
 }
 
 class Reverse
 {
 	public static void main(String arg[])
 	{
 		System.out.println("REVERSE_NUMBER");
 		
 		// get the object
 		NumRev nr = new NumRev();
 		nr.getNum();
 		
 		// call to class method
 		System.out.println( "Result using For \t: " + nr.revFOR());
 		System.out.println( "Result using While \t: " + nr.revWHI());
 		System.out.println( "Result using Recur \t: " +nr.revREC());
 		
 		
 	}
 }
 
